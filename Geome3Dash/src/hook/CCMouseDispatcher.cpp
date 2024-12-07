#include "pch.h"
#include "delegate/CustomMouse.h"

#include <Geode/modify/CCMouseDispatcher.hpp>

namespace g3d
{
    class $modify(CCMouseDispatcher)
    {
        bool dispatchScrollMSG(float x, float y)
        {
            CustomMouseManager::updateDelegates(x, y);
            return CCMouseDispatcher::dispatchScrollMSG(x, y);
        }
    };
}