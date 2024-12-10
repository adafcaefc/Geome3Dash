#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class UIButtonConfig {
public:
    static constexpr auto CLASS_NAME = "UIButtonConfig";

    /**
     * @note[short] Windows: 0x1779e0
     * @note[short] Android
     */
    TodoReturn reset();

    /**
     * @note[short] Android
     */
    TodoReturn resetOneBtn();
    GEODE_PAD(40);
};
