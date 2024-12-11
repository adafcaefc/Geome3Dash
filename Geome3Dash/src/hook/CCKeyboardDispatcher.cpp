#include "pch.h"
#include "delegate/CustomKeyboard.h"

#include <Geode/modify/CCKeyboardDispatcher.hpp>

namespace g3d
{
    class $modify(CCKeyboardDispatcher)
    {
        bool dispatchKeyboardMSG(enumKeyCodes key, bool isKeyDown, bool isKeyRepeat)
        {
            CustomKeyboardManager::onKey(key, isKeyDown, isKeyRepeat);
            return CCKeyboardDispatcher::dispatchKeyboardMSG(key, isKeyDown, isKeyRepeat);
        }
    };
}