#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class StatsObject : public cocos2d::CCObject {
public:
    static constexpr auto CLASS_NAME = "StatsObject";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(StatsObject, cocos2d::CCObject)
    
private:
    [[deprecated("StatsObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static StatsObject* create(char const* p0, int p1);
public:
    
private:
    [[deprecated("StatsObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(char const* p0, int p1);
public:
};
