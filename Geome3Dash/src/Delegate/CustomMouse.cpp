#include "pch.h"
#include "../pch.h"
#include "CustomMouse.h"

namespace g3d
{
    CustomMouseDelegate::CustomMouseDelegate() {
        uidCounter++;
        uid = uidCounter;
        CustomMouseManager::addDelegate(this);
    }
    CustomMouseDelegate::~CustomMouseDelegate() {
        CustomMouseManager::removeDelegate(this);
    }

    int CustomMouseDelegate::uidCounter = 0;

    void CustomMouseManager::addDelegate(CustomMouseDelegate* obj) {
        delegates.push_back(obj);
    }

    void CustomMouseManager::removeDelegate(CustomMouseDelegate* obj) {
        delegates.erase(std::remove_if(delegates.begin(), delegates.end(),
            [obj](CustomMouseDelegate* delegate) {
                return delegate->uid == obj->uid;
            }), delegates.end());
    }

    void CustomMouseManager::updateDelegates(float x, float y) {
        for (auto delegate : delegates) {
            delegate->scrollWheel(x, y);
        }
    }

    std::vector<CustomMouseDelegate*> CustomMouseManager::delegates = {};
}
