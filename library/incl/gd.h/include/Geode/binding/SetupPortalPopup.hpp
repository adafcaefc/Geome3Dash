#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "FLAlertLayer.hpp"
#include "TextInputDelegate.hpp"

class SetupPortalPopup : public FLAlertLayer, public TextInputDelegate {
public:
    static constexpr auto CLASS_NAME = "SetupPortalPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupPortalPopup, FLAlertLayer)
    
private:
    [[deprecated("SetupPortalPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupPortalPopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupPortalPopup::keyBackClicked not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4b07e8
     * @note[short] MacOS (Intel): 0x559fd0
     * @note[short] Android
     */
    virtual void keyBackClicked();
public:
    
private:
    [[deprecated("SetupPortalPopup::determineStartValues not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn determineStartValues();
public:
    
private:
    [[deprecated("SetupPortalPopup::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4af7d4
     * @note[short] MacOS (Intel): 0x558e40
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupPortalPopup::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupPortalPopup::onEditCameraSettings not implemented")]]
    /**
     * @note[short] Android
     */
    void onEditCameraSettings(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupPortalPopup::onUnboundMode not implemented")]]
    /**
     * @note[short] Android
     */
    void onUnboundMode(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupPortalPopup::sliderChanged not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn sliderChanged(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("SetupPortalPopup::updateCameraEasing not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateCameraEasing();
public:
    
private:
    [[deprecated("SetupPortalPopup::updateCameraEasingLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateCameraEasingLabel();
public:
    
private:
    [[deprecated("SetupPortalPopup::updateCameraPadding not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateCameraPadding();
public:
    
private:
    [[deprecated("SetupPortalPopup::updateCameraPaddingLabel not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4b0614
     * @note[short] MacOS (Intel): 0x559dd0
     * @note[short] Android
     */
    TodoReturn updateCameraPaddingLabel();
public:
    
private:
    [[deprecated("SetupPortalPopup::updateItemVisibility not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateItemVisibility();
public:
};
