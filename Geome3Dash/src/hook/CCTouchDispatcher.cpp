#include "pch.h"
#include "delegate/CustomTouch.h"

namespace g3d
{
    class $modify(CCTouchDispatcher)
    {
        void touches(CCSet * touches, CCEvent * event, unsigned int type)
        {
            CustomTouchManager::updateDelegates(touches, event, type);
            CCTouchDispatcher::touches(touches, event, type);
        }
    };
}