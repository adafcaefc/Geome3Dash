#include "pch.h"
#include <Geode/modify/CreatorLayer.hpp>
#include "game/planet/G3DPlanetLayer.h"
#include "helper/OpenGLStateHelper.h"
#include "helper/Easing.h"
#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Shaders.h"
#include "manager/ModelManager.h"
#include "impl/engine/PlanetModel.h"

namespace g3d
{
    class G3DPlanetCreatorLayerBaseNode : public G3DBaseNode 
    {
    public:
        sus3d::ShaderProgram* shaderProgram;
        sus3d::ShaderProgram* shaderProgram2;
        PlanetModel* planetModel;
        PlanetModel* planetWaterModel;
        ~G3DPlanetCreatorLayerBaseNode() override = default;
        virtual void draw() override;
        static G3DPlanetCreatorLayerBaseNode* create();
    };

    void G3DPlanetCreatorLayerBaseNode::draw()
    {
        CCNode::draw();
        OpenGLStateHelper::saveState();
        glEnable(GL_BLEND);
        glEnable(GL_ALPHA_TEST);
        glEnable(GL_DEPTH_TEST);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glm::mat4 view = camera.getViewMat();
        glm::mat4 projection = camera.getProjectionMat();

        planetModel->render(
            shaderProgram,
            view,
            light.getPosition(),
            light.getColor(),
            camera.getPosition(),
            projection);

        planetWaterModel->render(
            shaderProgram2,
            view,
            light.getPosition(),
            light.getColor(),
            camera.getPosition(),
            projection);

        glDisable(GL_DEPTH_TEST);
        OpenGLStateHelper::pushState();
    }

    G3DPlanetCreatorLayerBaseNode* G3DPlanetCreatorLayerBaseNode::create() 
    {
        G3DPlanetCreatorLayerBaseNode* ret = new G3DPlanetCreatorLayerBaseNode();
        if (!ret || !ret->init()) 
        {
            delete ret;
            return nullptr;
        }
        return ret;
    }

    class $modify(MyCreatorLayer, CreatorLayer) 
    {
        struct Fields
        {
            PlanetModel* planetModel;
            PlanetModel* planetModelWater;
            CCNode* mapButton;
        };

        void updatePlanetRotation(const float delta) 
        {
            if (G3DPlanetLayer::insideThePlanetLayerFlag) { return; }

            // Store previous scales
            static glm::vec3 previousWaterScale = m_fields->planetModelWater->getScale();
            static glm::vec3 previousPlanetScale = m_fields->planetModel->getScale();

            // Set target scales
            const glm::vec3 waterTargetScale = glm::vec3(0.251f);
            const glm::vec3 planetTargetScale = glm::vec3(0.250f);

            // Calculate scale differences
            float waterScaleDiff = glm::length(previousWaterScale - waterTargetScale);
            float planetScaleDiff = glm::length(previousPlanetScale - planetTargetScale);

            // Threshold for triggering animation
            constexpr float threshold = 0.2f;

            // Static animation state
            static bool isAnimating = false;
            static double timeElapsed = 0.0;
            constexpr double duration = 1.5; // Animation duration

            // Trigger animation if the scale difference exceeds the threshold
            if (!isAnimating && (waterScaleDiff > threshold || planetScaleDiff > threshold)) {
                isAnimating = true;
                timeElapsed = 0.0; // Reset animation timer
            }

            // Perform animation if active
            if (isAnimating) {
                timeElapsed += delta;
                if (timeElapsed <= duration) {
                    double t = timeElapsed / duration;
                    m_fields->planetModelWater->setScale(
                        ease::ease<glm::vec3>(ease::InOutCubic::get(), t, duration, previousWaterScale, waterTargetScale)
                    );
                    m_fields->planetModel->setScale(
                        ease::ease<glm::vec3>(ease::InOutCubic::get(), t, duration, previousPlanetScale, planetTargetScale)
                    );
                }
                else {
                    // Animation complete, set to final target scales
                    m_fields->planetModelWater->setScale(waterTargetScale);
                    m_fields->planetModel->setScale(planetTargetScale);
                    isAnimating = false; // End animation
                }
            }

            // Update previous scales for the next frame
            previousWaterScale = m_fields->planetModelWater->getScale();
            previousPlanetScale = m_fields->planetModel->getScale();

            if (!isAnimating) 
            {
                m_fields->planetModelWater->setScale(glm::vec3(0.251f * m_fields->mapButton->getScale()));
                m_fields->planetModel->setScale(glm::vec3(0.250f * m_fields->mapButton->getScale()));
            }

            float sensitivityX = 0.4662f;
            float sensitivityY = 0.3665f;
            float sensitivityZ = 0.916f;

            glm::quat rotationX = glm::angleAxis(delta * sensitivityX, glm::vec3(1.0f, 0.0f, 0.0f));
            glm::quat rotationY = glm::angleAxis(delta * sensitivityY, glm::vec3(0.0f, 1.0f, 0.0f));
            glm::quat rotationZ = glm::angleAxis(delta * sensitivityZ, glm::vec3(0.0f, 0.0f, 1.0f));
            glm::quat currentRotation = glm::quat(glm::vec3(
                glm::radians(m_fields->planetModel->getRotationX()),
                glm::radians(m_fields->planetModel->getRotationY()),
                glm::radians(m_fields->planetModel->getRotationZ())
            ));

            glm::quat newRotation = rotationZ * rotationY * rotationX * currentRotation;
            glm::vec3 eulerAngles = glm::eulerAngles(newRotation);

            m_fields->planetModel->setRotationX(glm::degrees(eulerAngles.x));
            m_fields->planetModel->setRotationY(glm::degrees(eulerAngles.y));
            m_fields->planetModel->setRotationZ(glm::degrees(eulerAngles.z));
            m_fields->planetModelWater->setRotationX(glm::degrees(eulerAngles.x));
            m_fields->planetModelWater->setRotationY(glm::degrees(eulerAngles.y));
            m_fields->planetModelWater->setRotationZ(glm::degrees(eulerAngles.z));
        }

        bool init() 
        {
            if (!CreatorLayer::init()) { return false; }

            // -------------------- waboo --------------------

            //{
            //    m_fields->mapButton = this->getChildByIDRecursive("map-button");
            //    m_fields->mapButton->removeAllChildren();
            //    auto sprite = CCSprite::createWithSpriteFrameName("GJ_mapBtn_001.png");
            //    auto weeklyButton = this->getChildByIDRecursive("weekly-button");
            //    auto weeklyButtonSprite = weeklyButton->getChildByType<CCSprite>(0);
            //    sprite->setScale(weeklyButtonSprite->getScale());
            //    sprite->setPosition(weeklyButtonSprite->getPosition());
            //    m_fields->mapButton->addChild(sprite);
            //}
            //return true;

            // -----------------------------------------------

            auto bms = ModelManager::get();

            m_fields->mapButton = this->getChildByIDRecursive("map-button");
            auto weeklyButton = this->getChildByIDRecursive("weekly-button");

            m_fields->mapButton->removeAllChildren();
            auto sprite = CCSprite::create("sprite/G3D_emptyBtn_001.png"_spr);
            auto weeklyButtonSprite = weeklyButton->getChildByType<CCSprite>(0);
            sprite->setScale(weeklyButtonSprite->getScale());
            sprite->setPosition(weeklyButtonSprite->getPosition() + CCPoint(2, -2));
            m_fields->mapButton->addChild(sprite);

            // swap button positions
            auto cmenu = this->getChildByID("creator-buttons-menu");
            cmenu->swapChildIndices(m_fields->mapButton, weeklyButton);
            cmenu->updateLayout();

            auto layer3d = G3DPlanetCreatorLayerBaseNode::create();
            layer3d->light.setPosition(glm::vec3(0, 50, 1000));
            layer3d->setZOrder(10);

            const auto planetPath = bms->getBP() / "planet";
            const auto modelPath = planetPath / "model";

            m_fields->planetModel = bms->getModelT<PlanetModel>(modelPath / "new_planet_textured.obj");
            m_fields->planetModelWater = bms->getModelT<PlanetModel>(modelPath / "planet_water.obj");

            layer3d->planetModel = m_fields->planetModel;
            layer3d->planetWaterModel = m_fields->planetModelWater;
            layer3d->shaderProgram = dynamic_cast<CocosShaderProgram*>(bms->getBlockSP());
            layer3d->shaderProgram2 = dynamic_cast<CocosShaderProgram*>(bms->getWaterSP());

            this->addChild(layer3d);
            layer3d->camera.setPosition(glm::vec3(0, 0, 25));

            this->schedule(schedule_selector(MyCreatorLayer::updatePlanetRotation));

            return true;
        }

        void onAdventureMap(CCObject*)
        {
            auto scene = CCScene::create();
            auto testLayer = G3DPlanetLayer::create();
            scene->addChild(testLayer);
            CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.3f, scene));
        }
    };
}