#include "pch.h"

#include "Hooks.h"

#include "game/playing/G3DPlayLayer.h"
#include "game/test/G3DModelPreviewLayer.h"
#include "game/planet/G3DPlanetLayer.h"
#include "game/editor/G3DEditorPopup.h"
#include "game/component/G3DBaseNode.h" 

#include "PlanetStateManager.h"

namespace g3d
{
    class $modify(PlayLayer)
    {
        struct Fields
        {
            G3DPlayLayer* playLayer3D = nullptr;
        };

        void destroyPlayer(PlayerObject* p0, GameObject* p1) {
            if (G3DPlanetLayer::insideThePlanetLayerFlag) {
                auto percent = this->getCurrentPercentInt();
                if (this->m_isPracticeMode) {
                    PlanetStateManager::getInstance()->setPracticeProgressByLevelID(this->m_level->m_levelID, percent);
                }
                else {
                    PlanetStateManager::getInstance()->setNormalProgressByLevelID(this->m_level->m_levelID, percent);
                }
            }
            PlayLayer::destroyPlayer(p0, p1);
        }
        void levelComplete() {
            if (G3DPlanetLayer::insideThePlanetLayerFlag) {
                if (this->m_isPracticeMode) {
                    PlanetStateManager::getInstance()->setPracticeProgressByLevelID(this->m_level->m_levelID, 100);
                }
                else {
                    PlanetStateManager::getInstance()->setNormalProgressByLevelID(this->m_level->m_levelID, 100);
                }
            }
            PlayLayer::levelComplete();
        }

        void resetLevel()
        {
            if (!m_fields->playLayer3D)
            {
                m_fields->playLayer3D = G3DPlayLayer::create();
                m_fields->playLayer3D->setZOrder(9);
                this->addChild(m_fields->playLayer3D);
            }
            PlayLayer::resetLevel();
        }
    };

    class $modify(GameManager) {
        void returnToLastScene(GJGameLevel * p0) {
            if (G3DPlanetLayer::insideThePlanetLayerFlag) {
                CCDirector::sharedDirector()->popSceneWithTransition(0.3, kPopTransitionFade);
            }
            else {
                GameManager::returnToLastScene(p0);
            }
        }
    };


    class $modify(CreatorLayer) 
    {
        void onAdventureMap(CCObject*) 
        {
            auto scene = CCScene::create();
            auto testLayer = G3DPlanetLayer::create();

            scene->addChild(testLayer);
            CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.3f, scene));
        }
    };

    class $modify(CCKeyboardDispatcher)
    {
        bool dispatchKeyboardMSG(enumKeyCodes key, bool isKeyDown, bool isKeyRepeat)
        {
            CustomKeyboardManager::updateDelegates(key, isKeyDown, isKeyRepeat);
            return CCKeyboardDispatcher::dispatchKeyboardMSG(key, isKeyDown, isKeyRepeat);
        }
    };

    class $modify(CCMouseDispatcher)
    {
        bool dispatchScrollMSG(float x, float y)
        {
            CustomMouseManager::updateDelegates(x, y);
            return CCMouseDispatcher::dispatchScrollMSG(x, y);
        }
    };

    class $modify(CCEGLView)
    {
        void onGLFWMouseMoveCallBack(GLFWwindow * window, double x, double y)
        {
            CustomTouchManager::onGLFWMouseMoveCallBack(window, x, y);
            CCEGLView::onGLFWMouseMoveCallBack(window, x, y);
        }

        void onGLFWMouseCallBack(GLFWwindow * window, int button, int action, int mods)
        {
            CustomTouchManager::onGLFWMouseCallBack(window, button, action, mods);
            CCEGLView::onGLFWMouseCallBack(window, button, action, mods);
        }
    };

    class $modify(CCTouchDispatcher)
    {
        void touches(CCSet* touches, CCEvent* event, unsigned int type)
        {
            CustomTouchManager::updateDelegates(touches, event, type);
            CCTouchDispatcher::touches(touches, event, type);
        }
    };

    class $modify(LevelEditorLayerG3D, LevelEditorLayer)
    {
        void onEditorPopup(CCObject * sender)
        {
            G3DEditorPopup::scene();
        }

        bool init(GJGameLevel * p0, bool p1)
        {
            if (!LevelEditorLayer::init(p0, p1)) { return false; }
            auto settingsButton = this->getChildByIDRecursive("settings-button");
            auto settingsMenu = this->getChildByIDRecursive("settings-menu");

            auto sprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");

            auto menu = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(LevelEditorLayerG3D::onEditorPopup));

            auto settingsButtonSprite = settingsButton->getChildByType<CCSprite>(0);
            sprite->setContentSize(settingsButtonSprite->getContentSize());
            sprite->setScale(settingsButtonSprite->getScale() * 0.8);
            sprite->setPosition(settingsButtonSprite->getPosition());
            menu->setContentSize(settingsButton->getContentSize());
            menu->setScale(settingsButton->getScale());
            menu->setPosition(settingsButton->getPosition() + CCPoint(-44.5, -2.75));
            auto label = CCLabelBMFont::create("CAM", "bigFont.fnt", sprite->getContentWidth());
            sprite->addChild(label);
            label->setPosition(CCPoint(23.5, 24.5));
            label->setScale(0.5);

            settingsMenu->addChild(menu);

            return true;
        }
    };

    class $modify(MenuLayer) {
        bool init() {
            if (!MenuLayer::init()) { return false; }
            AllocConsole();
            freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
            return true;
        }
    };

    class $modify(MyCreatorLayer, CreatorLayer) {
        struct Fields
        {
            PlanetModel* planetModel;
            PlanetModel* planetModelWater;
            CCNode* mapButton;
        };

        void updateObjectHitbox(const float delta) {
            m_fields->planetModelWater->setScale(glm::vec3(0.251 * m_fields->mapButton->getScale()));
            m_fields->planetModel->setScale(glm::vec3(0.25 * m_fields->mapButton->getScale()));

            float sensitivityX = 0.4662;
            float sensitivityY = 0.3665;
            float sensitivityZ = 0.916;

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

            this->schedule(schedule_selector(MyCreatorLayer::updateObjectHitbox));

            return true;
        }
    };

    void setupLibraries()
    {
        // setup delayloaded dlls
        const auto path = geode::Mod::get()->getResourcesDir() / "binaries" / "win";
        const auto pugi = path / "pugixml.dll";
        const auto assimp = path / "assimp-vc143-mt.dll";
        LoadLibraryA(pugi.string().c_str());
        LoadLibraryA(assimp.string().c_str());
    }

    void setupHooks()
    {
        auto mod = geode::Mod::get();
        for (auto& hook : mod->getHooks()) { if (!hook->isEnabled()) { auto result = hook->enable(); } }
    }
}