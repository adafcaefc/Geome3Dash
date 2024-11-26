#include "pch.h"
#include "CustomTouch.h"

namespace g3d
{
    CustomTouchDelegate::CustomTouchDelegate() {
        uidCounter++;
        uid = uidCounter;
        CustomTouchManager::addDelegate(this);
    }
    CustomTouchDelegate::~CustomTouchDelegate() {
        CustomTouchManager::removeDelegate(this);
    }

    int CustomTouchDelegate::uidCounter = 0;

    void CustomTouchManager::addDelegate(CustomTouchDelegate* obj) {
        delegates.push_back(obj);
    }

    void CustomTouchManager::removeDelegate(CustomTouchDelegate* obj) {
        delegates.erase(std::remove_if(delegates.begin(), delegates.end(),
            [obj](CustomTouchDelegate* delegate) {
                return delegate->uid == obj->uid;
            }), delegates.end());
    }

    void CustomTouchManager::updateDelegates(CCSet* touches, CCEvent* event, unsigned int type) {
        for (auto delegate : delegates) {
            delegate->touch(touches, event, type);
        }
    }

    void CustomTouchManager::onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) {
        for (auto delegate : delegates) {
            delegate->onGLFWMouseCallBack(window, button, action, mods);
        }
    }
    void CustomTouchManager::onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) {
        for (auto delegate : delegates) {
            delegate->onGLFWMouseMoveCallBack(window, x, y);
        }
    }

    std::vector<CustomTouchDelegate*> CustomTouchManager::delegates = {};
}
