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
    
private:
    [[deprecated("ColorAction2::resetAction not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetAction();
public:
    
private:
    [[deprecated("ColorAction2::step not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn step(float p0);
public:
    
private:
    [[deprecated("ColorAction2::updateCustomColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateCustomColor(cocos2d::ccColor3B p0, cocos2d::ccColor3B p1);
public:
};
