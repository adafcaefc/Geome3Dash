#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "CCCircleWave.hpp"

class CCCircleAlert : public CCCircleWave {
public:
    static constexpr auto CLASS_NAME = "CCCircleAlert";
    GEODE_CUSTOM_CONSTRUCTOR_GD(CCCircleAlert, CCCircleWave)
    
private:
    [[deprecated("CCCircleAlert::create not implemented")]]
    /**
     * @note[short] Android
     */
    static CCCircleAlert* create(float p0, float p1, float p2);
public:
    
private:
    [[deprecated("CCCircleAlert::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(float p0, float p1, float p2);
public:
};
