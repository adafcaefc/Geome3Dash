#include "pch.h"
#include "delegate/CustomTouch.h"

namespace g3d
{
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
}