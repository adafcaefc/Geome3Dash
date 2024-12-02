#include "pch.h"
#include "game/planet/G3DPlanetLayer.h"
#include "helper/OpenGLStateHelper.h"
#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Shaders.h"

namespace g3d
{
    class $modify(MyCreatorLayer, CreatorLayer) {
        struct Fields
        {
            PlanetModel* planetModel;
            PlanetModel* planetModelWater;
            CCNode* mapButton;
        };

        void updatePlanetRotation(const float delta) {
            m_fields->planetModelWater->setScale(glm::vec3(0.251 * m_fields->mapButton->getScale()));
            m_fields->planetModel->setScale(glm::vec3(0.25 * m_fields->mapButton->getScale()));

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
        bool init() {
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

            m_fields->mapButton = this->getChildByIDRecursive("map-button");
            auto weeklyButton = this->getChildByIDRecursive("weekly-button");
            const auto mapButtonPos = m_fields->mapButton->getPosition();
            m_fields->mapButton->setPosition(weeklyButton->getPosition());
            weeklyButton->setPosition(mapButtonPos);

            m_fields->mapButton->removeAllChildren();

            auto sprite = CCSprite::create("sprite/G3D_emptyBtn_001.png"_spr);
            auto weeklyButtonSprite = weeklyButton->getChildByType<CCSprite>(0);
            sprite->setScale(weeklyButtonSprite->getScale());
            sprite->setPosition(weeklyButtonSprite->getPosition() + CCPoint(2, -2));
            m_fields->mapButton->addChild(sprite);

            //auto label = CCLabelBMFont::create("Planet", "bigFont.fnt");
            //label->setScale(weeklyButtonSprite->getScale() / 2.f);
            //label->setPosition(weeklyButtonSprite->getPosition() + CCPoint(2, -2));
            //label->setPositionY(label->getPositionY() - 20.f);
            //label->setZOrder(20);
            //m_fields->mapButton->addChild(label);

            OpenGLStateHelper::saveState();
            auto vertexShader = sus3d::Shader::createWithString(sus3d::shaders::vertexShaderSource, sus3d::ShaderType::kVertexShader);
            auto fragmentShader = sus3d::Shader::createWithString(sus3d::shaders::fragmentShaderSource, sus3d::ShaderType::kFragmentShader);
            auto shaderProgram = CocosShaderProgram::create(vertexShader, fragmentShader);
            delete vertexShader;
            delete fragmentShader;

            const auto planetPath = geode::Mod::get()->getResourcesDir() / "model3d" / "planet";
            const auto shaderPath = planetPath / "shader";
            const auto modelPath = planetPath / "model";

            auto vertexShader2 = sus3d::Shader::createWithString(sus3d::shaders::vertexShaderSource, sus3d::ShaderType::kVertexShader);
            auto fragmentShader2 = sus3d::Shader::createWithFile(shaderPath / "water2.fsh", sus3d::ShaderType::kFragmentShader);
            auto shaderProgram2 = CocosShaderProgram::create(vertexShader2, fragmentShader2);
            delete vertexShader2;
            delete fragmentShader2;

            OpenGLStateHelper::pushState();

            auto layer3d = G3DBaseNode::create();
            layer3d->light.setPosition(glm::vec3(0, 50, 1000));
            layer3d->setZOrder(10);

            m_fields->planetModel = layer3d->loadAndAddModel<PlanetModel>(modelPath / "new_planet_textured.obj", shaderProgram);
            m_fields->planetModelWater = layer3d->loadAndAddModel<PlanetModel>(modelPath / "planet_water.obj", shaderProgram2);

            m_fields->mapButton->addChild(layer3d);
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