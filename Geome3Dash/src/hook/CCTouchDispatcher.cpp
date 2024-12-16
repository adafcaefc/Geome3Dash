#include "pch.h"
#include <Geode/modify/CCTouchDispatcher.hpp>
#include "delegate/CustomTouch.h"

namespace g3d
{
    class $modify(CCTouchDispatcher)
    {
        void touches(CCSet * touches, CCEvent * event, unsigned int type)
        {
            CustomTouchManager::touch(touches, event, type);
            CCTouchDispatcher::touches(touches, event, type);
        }
    };
}