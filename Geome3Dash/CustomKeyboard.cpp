#include "pch.h"
#include "CustomKeyboard.h"

namespace g3d
{
    CustomKeyboardDelegate::CustomKeyboardDelegate() {
        uidCounter++;
        uid = uidCounter;
        CustomKeyboardManager::addDelegate(this);
    }
    CustomKeyboardDelegate::~CustomKeyboardDelegate() {
        CustomKeyboardManager::removeDelegate(this);
    }

    int CustomKeyboardDelegate::uidCounter = 0;

    void CustomKeyboardManager::addDelegate(CustomKeyboardDelegate* obj) {
        delegates.push_back(obj);
    }

    void CustomKeyboardManager::removeDelegate(CustomKeyboardDelegate* obj) {
        delegates.erase(std::remove_if(delegates.begin(), delegates.end(),
            [obj](CustomKeyboardDelegate* delegate) {
                return delegate->uid == obj->uid;
            }), delegates.end());
    }

    void CustomKeyboardManager::updateDelegates(enumKeyCodes key, bool pressed, bool holding) {
        for (auto delegate : delegates) {
            delegate->onKey(key, pressed, holding);
        }
    }

    std::vector<CustomKeyboardDelegate*> CustomKeyboardManager::delegates = {};
}
