#include "pch.h"
#include "delegate/CustomMouse.h"

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