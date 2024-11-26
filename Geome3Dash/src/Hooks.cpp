#include "pch.h"
#include "../pch.h"

#include "Hooks.h"

#include "PlayLayer3D.h"

namespace g3d
{
    class $modify(PlayLayer)
    {
        struct Fields
        {
            PlayLayer3D* playLayer3D = nullptr;
        };

        void resetLevel()
        {
            if (!m_fields->playLayer3D)
            {
                m_fields->playLayer3D = PlayLayer3D::create();
                m_fields->playLayer3D->setZOrder(10);
                this->addChild(m_fields->playLayer3D);
            }
            PlayLayer::resetLevel();
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

    void HookAll()
    {
        auto mod = geode::Mod::get();
        for (auto& hook : mod->getHooks()) { hook->enable(); }
    }
}