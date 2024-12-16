#include "pch.h"
#include <Geode/modify/CCMouseDispatcher.hpp>
#include "delegate/CustomMouse.h"

#include <Geode/modify/CCMouseDispatcher.hpp>

namespace g3d
{
    class $modify(CCMouseDispatcher)
    {
        bool dispatchScrollMSG(float x, float y)
        {
            CustomMouseManager::scrollWheel(x, y);
            return CCMouseDispatcher::dispatchScrollMSG(x, y);
        }
    };
}