#include "pch.h"

#include <Geode/modify/LoadingLayer.hpp>

#include "manager/ModelManager.h"
#include "manager/LevelDataManager.h"

#include "game/planet/G3DPlanetLayer.h"

#include "helper/CommonHelper.h"
#include "helper/OpenGLStateHelper.h"

#include "impl/engine/PlanetModel.h"
#include "impl/engine/CloudModel.h"

#include <queue>

namespace g3d
{
    // I should really decouple the loading functionality from this class hook
    // maybe I will do it later but for now the loading layer hook is only used
    // for this loading mechanism so it's fine for the time being
    // if I ever implement any other functionality to this class I might have to
    // decouple this and make a loading manager class

    class $modify(HookedLoadingLayer, LoadingLayer)
    {
        struct ShaderData
        {
            std::string name, vertex, fragment;
            sus3d::ShaderProgram** program;
        };

        struct Fields
        {
            int preloadingStage = 0;
            std::queue<std::filesystem::path> queuedModels;
            std::queue<ShaderData> queuedShaders;
            std::string defaultText1, defaultText2;
            int queuedModelsAmount = 0;
            int queuedShadersAmount = 0;
        };

        std::string getLabelText()
        {
            auto label = static_cast<CCLabelBMFont*>(this->getChildByID("geode-small-label"));
            if (label) { return label->getString(); }
            return std::string();
        }

        std::string getLabelText2()
        {
            auto label = static_cast<CCLabelBMFont*>(this->getChildByID("geode-small-label-2"));
            if (label) { return label->getString(); }
            return std::string();
        }

        void setLabelText(const char* text)
        {
            auto label = static_cast<CCLabelBMFont*>(this->getChildByID("geode-small-label"));
            if (label) { label->setString(text); }
        }

        void setLabelText2(const char* text)
        {
            auto label = static_cast<CCLabelBMFont*>(this->getChildByID("geode-small-label-2"));
            if (label) { label->setString(text); }
        }

        void initShaders(ModelManager* bms)
        {
            const auto shaderPath = bms->getBP() / "planet" / "shader";

            m_fields->queuedShaders.push({
                "Shader Program",
                sus3d::shaders::vertexShaderSource,
                sus3d::shaders::fragmentShaderSource,
                &bms->blockShaderProgram });

            m_fields->queuedShaders.push({
                "Water Shader Program",
                sus3d::shaders::vertexShaderSource,
                utils::read_from_file(shaderPath / "water2.fsh"),
                &bms->waterShaderProgram });

            m_fields->queuedShaders.push({
                "Cloud Shader Program",
                utils::read_from_file(shaderPath / "cloud.vsh"),
                utils::read_from_file(shaderPath / "cloud.fsh"),
                &bms->cloudShaderProgram });

            m_fields->queuedShaders.push({
                "Buffer Shader Program",
                sus3d::shaders::idBufferingVertexShader,
                sus3d::shaders::idBufferingFragmentShader,
                &bms->idBufferShaderProgram });
        }

        void initModels(ModelManager* bms)
        {
            for (const auto& entry : std::filesystem::recursive_directory_iterator(bms->getBP()))
            {
                if (entry.is_regular_file() && entry.path().extension() == ".obj")
                {
                    m_fields->queuedModels.push(entry.path());
                }
            }
            for (const auto& entry : std::filesystem::recursive_directory_iterator(bms->getABP()))
            {
                if (entry.is_regular_file() && entry.path().extension() == ".obj")
                {
                    m_fields->queuedModels.push(entry.path());
                }
            }
        }

        void initCleanup(ModelManager* bms)
        {
            if (bms->blockShaderProgram) { delete bms->blockShaderProgram; }
            if (bms->waterShaderProgram) { delete bms->waterShaderProgram; }
            if (bms->cloudShaderProgram) { delete bms->cloudShaderProgram; }
            if (bms->idBufferShaderProgram) { delete bms->idBufferShaderProgram; }
            sus3d::Texture::cleanup();
            bms->blockModels.clear();
            bms->allModels.clear();
            for (auto& fn : bms->clearModelCallbacks) { fn(); }
        }

        void g3dPreloadingStage0(ModelManager* bms)
        {
            this->initCleanup(bms);
            this->initShaders(bms);
            this->initModels(bms);
            m_fields->queuedModelsAmount = static_cast<int>(m_fields->queuedModels.size());
            m_fields->queuedShadersAmount = static_cast<int>(m_fields->queuedShaders.size());
            m_fields->preloadingStage = 1;
        }

        void g3dPreloadingStage1(ModelManager* bms)
        {
            if (m_fields->queuedShaders.empty())
            {
                m_fields->preloadingStage = 2;
            }
            else
            {
                auto shader = m_fields->queuedShaders.front();
                *shader.program = bms->loadShader(shader.vertex, shader.fragment);
                m_fields->queuedShaders.pop();
                this->setLabelText(fmt::format(
                    "Geome3Dash: loading shaders ({}/{})",
                    m_fields->queuedShadersAmount - m_fields->queuedShaders.size(),
                    m_fields->queuedShadersAmount).c_str());
                this->setLabelText2(shader.name.c_str());
            }
        }

        void g3dPreloadingStage2(ModelManager* bms)
        {
            if (m_fields->queuedModels.empty())
            {
                const auto modelPath = bms->getBP() / "planet" / "model";
                bms->getModelT<PlanetModel>(modelPath / "new_planet_textured.obj");
                bms->getModelT<PlanetModel>(modelPath / "planet_water.obj");
                bms->getModelT<CloudModel>(modelPath / "clouds.obj");
                m_fields->preloadingStage = 3;
            }
            else
            {
                auto modelPath = m_fields->queuedModels.front();
                if (auto blockModel = bms->loadAndParseMtl(modelPath))
                {
                    bms->allModels.emplace(modelPath, blockModel);
                }
                m_fields->queuedModels.pop();
                this->setLabelText(fmt::format(
                    "Geome3Dash: loading models ({}/{})",
                    m_fields->queuedModelsAmount - m_fields->queuedModels.size(),
                    m_fields->queuedModelsAmount).c_str());

                static const auto shorter = [](const std::string& a, const std::string& b) { return (a.size() < b.size()) ? a : b; };
                const std::string bpPath = modelPath.lexically_relative(bms->getBP()).string();
                const std::string abpPath = modelPath.lexically_relative(bms->getABP()).string();

                this->setLabelText2(shorter(bpPath, abpPath).c_str());
            }
        }

        void loadMusic(int id)
        {
            const auto downloaded = MusicDownloadManager::sharedState()->isSongDownloaded(id);
            if (!downloaded)
            {
                const auto name = fmt::format("{}.mp3", id);
                try {
                    const auto from = geode::Mod::get()->getResourcesDir() / "music" / "level" / name;
                    const auto to = utils::get_song_path() / name;
                    std::filesystem::copy(from, to);
                }
                catch (...)
                {

                }
            }
        }

        void g3dPreloadingStage3(ModelManager* bms)
        {
            this->loadMusic(1221653);
            m_fields->preloadingStage = 4;
        }

        void g3dPreloadingStage4(ModelManager* bms)
        {
            constexpr int MAX_OBJECT_ID = 10000;
            for (int i = 0; i < MAX_OBJECT_ID; i++)
            {
                const auto modelPath = bms->getBP() / "object" / std::to_string(i) / "model.obj";
                if (auto blockModel = bms->getModel(modelPath)) { bms->blockModels[i] = blockModel; }
            }
            m_fields->preloadingStage = -1;
        }

        void updateLoading(float)
        {
            if (m_fields->preloadingStage == 0)
            {
                m_fields->defaultText1 = this->getLabelText();
                m_fields->defaultText2 = this->getLabelText2();
            }

            OpenGLStateHelper::saveState();
            auto bms = ModelManager::get();
            switch (m_fields->preloadingStage)
            {
            case 0: 
                this->setLabelText("Geome3Dash: listing assets");
                this->setLabelText2("");
                this->g3dPreloadingStage0(bms); 
                break;
            case 1: 
                this->g3dPreloadingStage1(bms); 
                break;
            case 2:
                this->g3dPreloadingStage2(bms); 
                break;
            case 3:
                this->setLabelText("Geome3Dash: caching models");
                this->setLabelText2("");
                this->g3dPreloadingStage3(bms); 
                break;
            case 4:
                this->setLabelText("Geome3Dash: loading music");
                this->setLabelText2("");
                this->g3dPreloadingStage4(bms);
                break;
            case -1: 
                this->setLabelText(m_fields->defaultText1.c_str());
                this->setLabelText2(m_fields->defaultText2.c_str());
                this->loadAssets(); 
                break;
            default: break;
            }
            OpenGLStateHelper::pushState();
        }

        void loadAssets()
        {
            if (m_fields->preloadingStage == -1) 
            {
                this->unschedule(schedule_selector(HookedLoadingLayer::updateLoading));
                return LoadingLayer::loadAssets(); 
            }
            this->schedule(schedule_selector(HookedLoadingLayer::updateLoading));
        }
    };
}