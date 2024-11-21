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

class SetupZoomTriggerPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupZoomTriggerPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupZoomTriggerPopup, SetupTriggerPopup)
    
private:
    [[deprecated("SetupZoomTriggerPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupZoomTriggerPopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupZoomTriggerPopup::determineStartValues not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2a3de4
     * @note[short] MacOS (Intel): 0x30d1e0
     * @note[short] iOS: 0x1ba6e0
     * @note[short] Android
     */
    virtual void determineStartValues();
public:
    
private:
    [[deprecated("SetupZoomTriggerPopup::onClose not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2a3de8
     * @note[short] MacOS (Intel): 0x30d1f0
     * @note[short] iOS: 0x1ba6e4
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupZoomTriggerPopup::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2a3a44
     * @note[short] MacOS (Intel): 0x30cdc0
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
};
