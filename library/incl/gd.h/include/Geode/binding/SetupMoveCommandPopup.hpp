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

class SetupMoveCommandPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupMoveCommandPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupMoveCommandPopup, SetupTriggerPopup)
    
private:
    [[deprecated("SetupMoveCommandPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupMoveCommandPopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupMoveCommandPopup::updateInputValue not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x5211d4
     * @note[short] MacOS (Intel): 0x5f1410
     * @note[short] iOS: 0x273cb8
     * @note[short] Android
     */
    virtual void updateInputValue(int p0, float& p1);
public:
    
private:
    [[deprecated("SetupMoveCommandPopup::updateInputNode not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x5211a8
     * @note[short] MacOS (Intel): 0x5f13d0
     * @note[short] iOS: 0x273c8c
     * @note[short] Android
     */
    virtual TodoReturn updateInputNode(int p0, float p1);
public:
    
private:
    [[deprecated("SetupMoveCommandPopup::valueDidChange not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x521208
     * @note[short] MacOS (Intel): 0x5f1450
     * @note[short] iOS: 0x273cec
     * @note[short] Android
     */
    virtual void valueDidChange(int p0, float p1);
public:
    
private:
    [[deprecated("SetupMoveCommandPopup::triggerValueFromSliderValue not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x5210f4
     * @note[short] MacOS (Intel): 0x5f12f0
     * @note[short] iOS: 0x273bd8
     * @note[short] Android
     */
    virtual TodoReturn triggerValueFromSliderValue(int p0, float p1);
public:
    
private:
    [[deprecated("SetupMoveCommandPopup::triggerSliderValueFromValue not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x521138
     * @note[short] MacOS (Intel): 0x5f1340
     * @note[short] iOS: 0x273c1c
     * @note[short] Android
     */
    virtual TodoReturn triggerSliderValueFromValue(int p0, float p1);
public:
    
private:
    [[deprecated("SetupMoveCommandPopup::onCustomToggleTriggerValue not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x5213d8
     * @note[short] MacOS (Intel): 0x5f1650
     * @note[short] iOS: 0x273eac
     * @note[short] Android
     */
    virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x51fd2c
     * @note[short] MacOS (Intel): 0x5efb70
     * @note[short] Windows: 0x279010
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);
    
private:
    [[deprecated("SetupMoveCommandPopup::updateControlVisibility not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateControlVisibility();
public:
};
