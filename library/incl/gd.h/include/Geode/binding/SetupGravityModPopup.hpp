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

class SetupGravityModPopup : public FLAlertLayer, public TextInputDelegate {
public:
    static constexpr auto CLASS_NAME = "SetupGravityModPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupGravityModPopup, FLAlertLayer)
    
private:
    [[deprecated("SetupGravityModPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupGravityModPopup* create(EffectGameObject* p0, cocos2d::CCArray* p1, bool p2);
public:
    
private:
    [[deprecated("SetupGravityModPopup::keyBackClicked not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x34fa14
     * @note[short] MacOS (Intel): 0x3c6a50
     * @note[short] Android
     */
    virtual void keyBackClicked();
public:
    
private:
    [[deprecated("SetupGravityModPopup::show not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x34f9c8
     * @note[short] MacOS (Intel): 0x3c69f0
     * @note[short] Android
     */
    virtual void show();
public:
    
private:
    [[deprecated("SetupGravityModPopup::textInputClosed not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x34f8cc
     * @note[short] MacOS (Intel): 0x3c68b0
     * @note[short] Android
     */
    virtual void textInputClosed(CCTextInputNode* p0);
public:
    
private:
    [[deprecated("SetupGravityModPopup::textChanged not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x34f8e8
     * @note[short] MacOS (Intel): 0x3c68f0
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);
public:
    
private:
    [[deprecated("SetupGravityModPopup::determineStartValues not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn determineStartValues();
public:
    
private:
    [[deprecated("SetupGravityModPopup::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x34e7e0
     * @note[short] MacOS (Intel): 0x3c56a0
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1, bool p2);
public:
    
private:
    [[deprecated("SetupGravityModPopup::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupGravityModPopup::onItemIDArrow not implemented")]]
    /**
     * @note[short] Android
     */
    void onItemIDArrow(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupGravityModPopup::sliderChanged not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn sliderChanged(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("SetupGravityModPopup::updateItemID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateItemID();
public:
    
private:
    [[deprecated("SetupGravityModPopup::updateTextInputLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTextInputLabel();
public:
    
private:
    [[deprecated("SetupGravityModPopup::updateValue not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateValue();
public:
    
private:
    [[deprecated("SetupGravityModPopup::updateValueLabel not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x34f5c0
     * @note[short] MacOS (Intel): 0x3c6540
     * @note[short] Android
     */
    TodoReturn updateValueLabel();
public:
};
