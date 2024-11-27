#include "pch.h"

#include "Hooks.h"

#include "G3DPlayLayer.h"
#include "G3DModelPreviewLayer.h"
#include "G3DPlanetLayer.h"

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
            CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.3, scene));
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