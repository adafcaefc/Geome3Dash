#include "pch.h"

namespace g3d
{
    class $modify(MenuLayer) {
        bool init() {
            if (!MenuLayer::init()) { return false; }
            //AllocConsole();
            //freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
            return true;
        }
    };
}