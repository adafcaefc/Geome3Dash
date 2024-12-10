#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class ColorAction2 {
public:
    static constexpr auto CLASS_NAME = "ColorAction2";

    /**
     * @note[short] Android
     */
     ColorAction2(cocos2d::ccColor3B p0, cocos2d::ccColor3B p1, float p2, double p3, bool p4, int p5, float p6, float p7);

    /**
     * @note[short] Android
     */
    TodoReturn resetAction();

    /**
     * @note[short] Android
     */
    TodoReturn step(float p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateCustomColor(cocos2d::ccColor3B p0, cocos2d::ccColor3B p1);
};
