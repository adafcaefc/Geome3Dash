#include "pch.h"

#include "Hooks.h"

#include "game/playing/G3DPlayLayer.h"
#include "game/test/G3DModelPreviewLayer.h"
#include "game/planet/G3DPlanetLayer.h"
#include "game/editor/G3DEditorPopup.h"

namespace g3d
{
    class $modify(PlayLayer)
    {
        struct Fields
        {
            G3DPlayLayer* playLayer3D = nullptr;
        };

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

    class $modify(LevelSettingsLayerG3D, LevelSettingsLayer)
    {
        void onEditorPopup(CCObject * sender)
        {
            G3DEditorPopup::scene();
        }
        bool init(LevelSettingsObject * p0, LevelEditorLayer * p1)
        {
            if (!LevelSettingsLayer::init(p0, p1)) { return false; }

            auto winSize = CCDirector::sharedDirector()->getWinSize() / 2;
            auto layer = dynamic_cast<CCLayer*>(this->getChildren()->objectAtIndex(0));
            if (!layer) { return true; }
            auto menu = dynamic_cast<CCNode*>(layer->getChildren()->objectAtIndex(1));
            if (!menu) { return true; }

            auto btnx = ButtonSprite::create("G3D", 0, false, "goldFont.fnt", "GJ_button_01.png", 0, 1);
            btnx->setScale(0.80f);
            btnx->setUserObject(this);
            auto btn = CCMenuItemSpriteExtra::create(btnx, this, menu_selector(LevelSettingsLayerG3D::onEditorPopup));
            btn->setPosition(menu->convertToNodeSpace({ winSize.width - 180.0f, winSize.height - 130.0f }));
            menu->addChild(btn);

            return true;
        }
    };

    class $modify(MenuLayer) {
        bool init() {
            if (!MenuLayer::init()) return false;
            AllocConsole();
            freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
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