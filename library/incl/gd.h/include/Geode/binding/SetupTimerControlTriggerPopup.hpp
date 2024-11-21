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

class SetupTimerControlTriggerPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupTimerControlTriggerPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupTimerControlTriggerPopup, SetupTriggerPopup)
    
private:
    [[deprecated("SetupTimerControlTriggerPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupTimerControlTriggerPopup* create(TimerTriggerGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupTimerControlTriggerPopup::onCustomToggleTriggerValue not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x31e0b4
     * @note[short] MacOS (Intel): 0x38f290
     * @note[short] iOS: 0x327c0
     * @note[short] Android
     */
    virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupTimerControlTriggerPopup::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x31dcd8
     * @note[short] MacOS (Intel): 0x38ee40
     * @note[short] Android
     */
    bool init(TimerTriggerGameObject* p0, cocos2d::CCArray* p1);
public:
};
