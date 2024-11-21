#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class PulseEffectAction {
public:
    static constexpr auto CLASS_NAME = "PulseEffectAction";
    
private:
    [[deprecated("PulseEffectAction::isFinished not implemented")]]
    /**
     * @note[short] Android
     */
    bool isFinished();
public:
    
private:
    [[deprecated("PulseEffectAction::step not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn step(float p0);
public:
    
private:
    [[deprecated("PulseEffectAction::valueForDelta not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn valueForDelta(float p0, float p1, float p2, float p3);
public:
    GEODE_PAD(72);
};
