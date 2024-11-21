#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "SetupTriggerPopup.hpp"

class SetupTimerEventTriggerPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupTimerEventTriggerPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupTimerEventTriggerPopup, SetupTriggerPopup)
    
private:
    [[deprecated("SetupTimerEventTriggerPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupTimerEventTriggerPopup* create(TimerTriggerGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupTimerEventTriggerPopup::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x31d690
     * @note[short] MacOS (Intel): 0x38e680
     * @note[short] Android
     */
    bool init(TimerTriggerGameObject* p0, cocos2d::CCArray* p1);
public:
};
