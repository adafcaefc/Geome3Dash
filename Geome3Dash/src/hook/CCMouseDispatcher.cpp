#include "pch.h"
#include "delegate/CustomMouse.h"

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