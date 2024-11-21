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

class SetupGradientPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupGradientPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupGradientPopup, SetupTriggerPopup)
    
private:
    [[deprecated("SetupGradientPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupGradientPopup* create(GradientTriggerObject* p0, cocos2d::CCArray* p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x50e9cc
     * @note[short] MacOS (Intel): 0x5db910
     * @note[short] Windows: 0x409e70
     * @note[short] iOS: 0x343010
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x50eafc
     * @note[short] MacOS (Intel): 0x5dba30
     * @note[short] Windows: 0x409f80
     * @note[short] iOS: 0x343120
     * @note[short] Android
     */
    virtual void onPlusButton(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x50eb58
     * @note[short] MacOS (Intel): 0x5dba80
     * @note[short] Windows: 0x40a000
     * @note[short] iOS: 0x34317c
     * @note[short] Android
     */
    virtual TodoReturn updateToggleItem(int p0, bool p1);

    /**
     * @note[short] MacOS (ARM): 0x50ed10
     * @note[short] MacOS (Intel): 0x5dbc40
     * @note[short] Windows: 0x40a410
     * @note[short] iOS: 0x343234
     * @note[short] Android
     */
    virtual void valueDidChange(int p0, float p1);
    
private:
    [[deprecated("SetupGradientPopup::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x50d368
     * @note[short] MacOS (Intel): 0x5da040
     * @note[short] Android
     */
    bool init(GradientTriggerObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupGradientPopup::onBlending not implemented")]]
    /**
     * @note[short] Android
     */
    void onBlending(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupGradientPopup::onZLayer not implemented")]]
    /**
     * @note[short] Android
     */
    void onZLayer(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupGradientPopup::sliderChanged not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn sliderChanged(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("SetupGradientPopup::updateBlending not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateBlending();
public:
    
private:
    [[deprecated("SetupGradientPopup::updateBlendingLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateBlendingLabel();
public:
    
private:
    [[deprecated("SetupGradientPopup::updateGradientLabels not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateGradientLabels(bool p0);
public:
    
private:
    [[deprecated("SetupGradientPopup::updateZLayerButtons not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateZLayerButtons();
public:
};
