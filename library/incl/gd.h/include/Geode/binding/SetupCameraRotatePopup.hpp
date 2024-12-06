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

class SetupCameraRotatePopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupCameraRotatePopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupCameraRotatePopup, SetupTriggerPopup)
    
private:
    [[deprecated("SetupCameraRotatePopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupCameraRotatePopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupCameraRotatePopup::determineStartValues not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x414080
     * @note[short] MacOS (Intel): 0x4aad80
     * @note[short] Android
     */
    virtual void determineStartValues();
public:
    
private:
    [[deprecated("SetupCameraRotatePopup::onClose not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x414790
     * @note[short] MacOS (Intel): 0x4ab540
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupCameraRotatePopup::textChanged not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x414568
     * @note[short] MacOS (Intel): 0x4ab2d0
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);
public:
    
private:
    [[deprecated("SetupCameraRotatePopup::valuePopupClosed not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4142ec
     * @note[short] MacOS (Intel): 0x4ab000
     * @note[short] Android
     */
    virtual void valuePopupClosed(ConfigureValuePopup* p0, float p1);
public:
    
private:
    [[deprecated("SetupCameraRotatePopup::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x412998
     * @note[short] MacOS (Intel): 0x4a9690
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupCameraRotatePopup::onEasing not implemented")]]
    /**
     * @note[short] Android
     */
    void onEasing(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupCameraRotatePopup::onEasingRate not implemented")]]
    /**
     * @note[short] Android
     */
    void onEasingRate(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupCameraRotatePopup::sliderChanged not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn sliderChanged(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("SetupCameraRotatePopup::sliderDegreesChanged not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn sliderDegreesChanged(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("SetupCameraRotatePopup::toggleEasingRateVisibility not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleEasingRateVisibility();
public:
    
private:
    [[deprecated("SetupCameraRotatePopup::updateCommandDegrees not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateCommandDegrees();
public:
    
private:
    [[deprecated("SetupCameraRotatePopup::updateDegreesLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateDegreesLabel();
public:
    
private:
    [[deprecated("SetupCameraRotatePopup::updateDuration not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateDuration();
public:
    
private:
    [[deprecated("SetupCameraRotatePopup::updateDurLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateDurLabel(bool p0);
public:
    
private:
    [[deprecated("SetupCameraRotatePopup::updateEasingLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateEasingLabel();
public:
    
private:
    [[deprecated("SetupCameraRotatePopup::updateEasingRateLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateEasingRateLabel();
public:
    
private:
    [[deprecated("SetupCameraRotatePopup::updateMoveCommandEasing not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateMoveCommandEasing();
public:
    
private:
    [[deprecated("SetupCameraRotatePopup::updateMoveCommandEasingRate not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateMoveCommandEasingRate();
public:
};
