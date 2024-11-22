#include "pch.h"
#include "../pch.h"
#include "ShaderScene.h"
#include "ShaderProgram.h"
#include "Model.h"
#include "OpenGLStateHelper.h"
#include <psapi.h>

namespace g3d
{
    void printMemoryUsage() {
        PROCESS_MEMORY_COUNTERS memInfo;
        BOOL result = GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));

        if (result) {
            geode::log::info("Working Set Size:      {}KB", memInfo.WorkingSetSize / 1024);
            geode::log::info("Peak Working Set Size: {}KB", memInfo.PeakWorkingSetSize / 1024);
            geode::log::info("Pagefile Usage:        {}KB", memInfo.PagefileUsage / 1024);
        }
        else {
            geode::log::error("Failed to get memory usage information", memInfo.PagefileUsage / 1024);
        }
    }

    void ShaderScene::draw() {
        OpenGLStateHelper::saveState();

        glDisable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);

        glm::mat4 view = camera->getViewMat();

        glm::mat4 projection = camera->getProjectionMat();

        for (auto model : models) {
            model->render(view, light->getPosition(), light->getColor(), camera->getPosition(), projection);
        }

        glDisable(GL_DEPTH_TEST);

        OpenGLStateHelper::pushState();
    }

    ShaderScene::~ShaderScene() {
        for (auto model : models) {
            delete model;
        }
    }

    Model* ShaderScene::loadAndAddModel(const std::filesystem::path& path, ShaderProgram* shaderProgram) {
        geode::log::info("loading model start");
        printMemoryUsage();
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(path.string(),
            aiProcess_Triangulate |
            aiProcess_FlipUVs |
            aiProcess_JoinIdenticalVertices |
            aiProcess_SortByPType);

        auto model = Model::create(scene, shaderProgram);
        geode::log::info("loading model end");
        printMemoryUsage();
        importer.FreeScene();
        geode::log::info("loading model clear");
        printMemoryUsage();
        models.push_back(model);
        return model;
    }

    Model* ShaderScene::loadWithoutAddModel(const std::filesystem::path& path, ShaderProgram* shaderProgram) {
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(path.string(),
            aiProcess_Triangulate |
            aiProcess_FlipUVs |
            aiProcess_JoinIdenticalVertices |
            aiProcess_SortByPType);

        auto model = Model::create(scene, shaderProgram);
        importer.FreeScene();
        return model;
    }

    auto ShaderScene::create() {
        auto node = new ShaderScene;
        if (node->init()) {
            node->autorelease();
        }
        else {
            CC_SAFE_DELETE(node);
        }
        return node;
    }
}