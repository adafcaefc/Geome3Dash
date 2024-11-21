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

class SetupRotateCommandPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupRotateCommandPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupRotateCommandPopup, SetupTriggerPopup)
    
private:
    [[deprecated("SetupRotateCommandPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupRotateCommandPopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupRotateCommandPopup::updateInputNode not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8cf4
     * @note[short] MacOS (Intel): 0x6dd0
     * @note[short] iOS: 0x3fec80
     * @note[short] Android
     */
    virtual TodoReturn updateInputNode(int p0, float p1);
public:
    
private:
    [[deprecated("SetupRotateCommandPopup::valueDidChange not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8cf8
     * @note[short] MacOS (Intel): 0x6de0
     * @note[short] iOS: 0x3fec84
     * @note[short] Android
     */
    virtual void valueDidChange(int p0, float p1);
public:
    
private:
    [[deprecated("SetupRotateCommandPopup::triggerValueFromSliderValue not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8ccc
     * @note[short] MacOS (Intel): 0x6d80
     * @note[short] iOS: 0x3fec58
     * @note[short] Android
     */
    virtual TodoReturn triggerValueFromSliderValue(int p0, float p1);
public:
    
private:
    [[deprecated("SetupRotateCommandPopup::triggerSliderValueFromValue not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8cf0
     * @note[short] MacOS (Intel): 0x6dc0
     * @note[short] iOS: 0x3fec7c
     * @note[short] Android
     */
    virtual TodoReturn triggerSliderValueFromValue(int p0, float p1);
public:
    
private:
    [[deprecated("SetupRotateCommandPopup::onCustomToggleTriggerValue not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8f90
     * @note[short] MacOS (Intel): 0x7120
     * @note[short] iOS: 0x3fed98
     * @note[short] Android
     */
    virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x7bec
     * @note[short] MacOS (Intel): 0x5890
     * @note[short] Windows: 0x2a06d0
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);
    
private:
    [[deprecated("SetupRotateCommandPopup::onInfiniteDuration not implemented")]]
    /**
     * @note[short] Android
     */
    void onInfiniteDuration(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] Windows: 0x2a1b30
     * @note[short] Android
     */
    void updateControlVisibility();
};
