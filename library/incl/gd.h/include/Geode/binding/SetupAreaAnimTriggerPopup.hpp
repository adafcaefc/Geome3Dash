#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "SetupAreaTintTriggerPopup.hpp"

class SetupAreaAnimTriggerPopup : public SetupAreaTintTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupAreaAnimTriggerPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupAreaAnimTriggerPopup, SetupAreaTintTriggerPopup)
    
private:
    [[deprecated("SetupAreaAnimTriggerPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupAreaAnimTriggerPopup* create(EnterEffectObject* p0, cocos2d::CCArray* p1, int p2);
public:
    
private:
    [[deprecated("SetupAreaAnimTriggerPopup::updateDefaultTriggerValues not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x42e564
     * @note[short] MacOS (Intel): 0x4c8dd0
     * @note[short] iOS: 0x3e8ec
     * @note[short] Android
     */
    virtual void updateDefaultTriggerValues();
public:
    
private:
    [[deprecated("SetupAreaAnimTriggerPopup::valueDidChange not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x42e720
     * @note[short] MacOS (Intel): 0x4c8f70
     * @note[short] iOS: 0x3ea50
     * @note[short] Android
     */
    virtual void valueDidChange(int p0, float p1);
public:
    
private:
    [[deprecated("SetupAreaAnimTriggerPopup::createValueControlAdvancedAnim not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createValueControlAdvancedAnim(int p0, gd::string p1, cocos2d::CCPoint p2, float p3, bool p4, InputValueType p5, int p6, bool p7, float min, float max, int p10, int p11, GJInputStyle p12);
public:
    
private:
    [[deprecated("SetupAreaAnimTriggerPopup::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x42cb08
     * @note[short] MacOS (Intel): 0x4c6f90
     * @note[short] Android
     */
    bool init(EnterEffectObject* p0, cocos2d::CCArray* p1, int p2);
public:
    
private:
    [[deprecated("SetupAreaAnimTriggerPopup::onDeactivateAnimValue not implemented")]]
    /**
     * @note[short] Android
     */
    void onDeactivateAnimValue(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupAreaAnimTriggerPopup::updateTargetIDLabel not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x4c8f00
     * @note[short] Android
     */
    TodoReturn updateTargetIDLabel();
public:
};
