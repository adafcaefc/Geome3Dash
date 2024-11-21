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
#include "HSVWidgetDelegate.hpp"

class SetupEnterEffectPopup : public SetupTriggerPopup, public HSVWidgetDelegate {
public:
    static constexpr auto CLASS_NAME = "SetupEnterEffectPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupEnterEffectPopup, SetupTriggerPopup)
    
private:
    [[deprecated("SetupEnterEffectPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupEnterEffectPopup* create(EnterEffectObject* p0, cocos2d::CCArray* p1, int p2);
public:

    /**
     * @note[short] MacOS (ARM): 0x363d00
     * @note[short] MacOS (Intel): 0x3e1800
     * @note[short] Windows: 0x408580
     * @note[short] iOS: 0x3f92a4
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x3640e0
     * @note[short] MacOS (Intel): 0x3e1c10
     * @note[short] Windows: 0x408b60
     * @note[short] iOS: 0x3f94f8
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);
    
private:
    [[deprecated("SetupEnterEffectPopup::updateInputValue not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x36425c
     * @note[short] MacOS (Intel): 0x3e1db0
     * @note[short] iOS: 0x3f9650
     * @note[short] Android
     */
    virtual void updateInputValue(int p0, float& p1);
public:
    
private:
    [[deprecated("SetupEnterEffectPopup::updateInputNode not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x364228
     * @note[short] MacOS (Intel): 0x3e1d80
     * @note[short] iOS: 0x3f961c
     * @note[short] Android
     */
    virtual TodoReturn updateInputNode(int p0, float p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x363e70
     * @note[short] MacOS (Intel): 0x3e19c0
     * @note[short] Windows: 0x408750
     * @note[short] iOS: 0x3f9410
     * @note[short] Android
     */
    virtual void valueDidChange(int p0, float p1);
    
private:
    [[deprecated("SetupEnterEffectPopup::triggerValueFromSliderValue not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x3641a0
     * @note[short] MacOS (Intel): 0x3e1d10
     * @note[short] iOS: 0x3f9594
     * @note[short] Android
     */
    virtual TodoReturn triggerValueFromSliderValue(int p0, float p1);
public:
    
private:
    [[deprecated("SetupEnterEffectPopup::triggerSliderValueFromValue not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x3641f4
     * @note[short] MacOS (Intel): 0x3e1d50
     * @note[short] iOS: 0x3f95e8
     * @note[short] Android
     */
    virtual TodoReturn triggerSliderValueFromValue(int p0, float p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x363f34
     * @note[short] MacOS (Intel): 0x3e1a90
     * @note[short] Windows: 0x408a70
     * @note[short] iOS: 0x3f94cc
     * @note[short] Android
     */
    virtual void hsvPopupClosed(HSVWidgetPopup* p0, cocos2d::ccHSVValue p1);
    
private:
    [[deprecated("SetupEnterEffectPopup::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x361a0c
     * @note[short] MacOS (Intel): 0x3deda0
     * @note[short] Android
     */
    bool init(EnterEffectObject* p0, cocos2d::CCArray* p1, int p2);
public:
    
private:
    [[deprecated("SetupEnterEffectPopup::onEnterType not implemented")]]
    /**
     * @note[short] Android
     */
    void onEnterType(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupEnterEffectPopup::onHSV not implemented")]]
    /**
     * @note[short] Android
     */
    void onHSV(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupEnterEffectPopup::onNextFreeEnterChannel not implemented")]]
    /**
     * @note[short] Android
     */
    void onNextFreeEnterChannel(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupEnterEffectPopup::onNextFreeEnterEffectID not implemented")]]
    /**
     * @note[short] Android
     */
    void onNextFreeEnterEffectID(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupEnterEffectPopup::updateHSVButton not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateHSVButton();
public:
};
