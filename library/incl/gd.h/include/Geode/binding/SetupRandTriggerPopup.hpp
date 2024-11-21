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

class SetupRandTriggerPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupRandTriggerPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupRandTriggerPopup, SetupTriggerPopup)
    
private:
    [[deprecated("SetupRandTriggerPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupRandTriggerPopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupRandTriggerPopup::determineStartValues not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x5028bc
     * @note[short] MacOS (Intel): 0x5ce3b0
     * @note[short] iOS: 0x1cb858
     * @note[short] Android
     */
    virtual void determineStartValues();
public:
    
private:
    [[deprecated("SetupRandTriggerPopup::onClose not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x502ddc
     * @note[short] MacOS (Intel): 0x5ce990
     * @note[short] iOS: 0x1cbc54
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x502b44
     * @note[short] MacOS (Intel): 0x5ce6a0
     * @note[short] Windows: 0x4288e0
     * @note[short] iOS: 0x1cbad0
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);
    
private:
    [[deprecated("SetupRandTriggerPopup::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x5016b0
     * @note[short] MacOS (Intel): 0x5cd0b0
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupRandTriggerPopup::onTargetID2Arrow not implemented")]]
    /**
     * @note[short] Android
     */
    void onTargetID2Arrow(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupRandTriggerPopup::onTargetIDArrow not implemented")]]
    /**
     * @note[short] Android
     */
    void onTargetIDArrow(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupRandTriggerPopup::sliderChanged not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn sliderChanged(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("SetupRandTriggerPopup::updateChance not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateChance();
public:
    
private:
    [[deprecated("SetupRandTriggerPopup::updateChanceLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateChanceLabel(bool p0);
public:
    
private:
    [[deprecated("SetupRandTriggerPopup::updateTargetID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTargetID();
public:
    
private:
    [[deprecated("SetupRandTriggerPopup::updateTargetID2 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTargetID2();
public:
    
private:
    [[deprecated("SetupRandTriggerPopup::updateTextInputLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTextInputLabel();
public:
    
private:
    [[deprecated("SetupRandTriggerPopup::updateTextInputLabel2 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTextInputLabel2();
public:
};
