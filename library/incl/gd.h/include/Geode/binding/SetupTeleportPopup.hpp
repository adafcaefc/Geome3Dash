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

class SetupTeleportPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupTeleportPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupTeleportPopup, SetupTriggerPopup)
    
private:
    [[deprecated("SetupTeleportPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupTeleportPopup* create(TeleportPortalObject* p0, cocos2d::CCArray* p1, int p2, bool p3);
public:
    
private:
    [[deprecated("SetupTeleportPopup::determineStartValues not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2db89c
     * @note[short] MacOS (Intel): 0x346b20
     * @note[short] iOS: 0x1008c
     * @note[short] Android
     */
    virtual void determineStartValues();
public:
    
private:
    [[deprecated("SetupTeleportPopup::updateDefaultTriggerValues not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2db8a0
     * @note[short] MacOS (Intel): 0x346b30
     * @note[short] iOS: 0x10090
     * @note[short] Android
     */
    virtual void updateDefaultTriggerValues();
public:
    
private:
    [[deprecated("SetupTeleportPopup::valueDidChange not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2db9ac
     * @note[short] MacOS (Intel): 0x346c30
     * @note[short] iOS: 0x10144
     * @note[short] Android
     */
    virtual void valueDidChange(int p0, float p1);
public:
    
private:
    [[deprecated("SetupTeleportPopup::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2da580
     * @note[short] MacOS (Intel): 0x3454c0
     * @note[short] Android
     */
    bool init(TeleportPortalObject* p0, cocos2d::CCArray* p1, int p2, bool p3);
public:
    
private:
    [[deprecated("SetupTeleportPopup::onTeleportGravity not implemented")]]
    /**
     * @note[short] Android
     */
    void onTeleportGravity(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupTeleportPopup::updateTeleportGravityState not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTeleportGravityState(int p0);
public:
};
