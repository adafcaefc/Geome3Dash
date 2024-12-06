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

class SetupOpacityPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupOpacityPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupOpacityPopup, SetupTriggerPopup)
    
private:
    [[deprecated("SetupOpacityPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupOpacityPopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupOpacityPopup::determineStartValues not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4e708
     * @note[short] MacOS (Intel): 0x58780
     * @note[short] iOS: 0x280e8
     * @note[short] Android
     */
    virtual void determineStartValues();
public:
    
private:
    [[deprecated("SetupOpacityPopup::onClose not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4ec00
     * @note[short] MacOS (Intel): 0x58d80
     * @note[short] iOS: 0x284f4
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupOpacityPopup::textInputClosed not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4e9c0
     * @note[short] MacOS (Intel): 0x58ae0
     * @note[short] iOS: 0x28374
     * @note[short] Android
     */
    virtual void textInputClosed(CCTextInputNode* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x4e9dc
     * @note[short] MacOS (Intel): 0x58b20
     * @note[short] Windows: 0x413a50
     * @note[short] iOS: 0x28390
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x4d5e0
     * @note[short] MacOS (Intel): 0x57560
     * @note[short] Windows: 0x412860
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);
    
private:
    [[deprecated("SetupOpacityPopup::onTargetIDArrow not implemented")]]
    /**
     * @note[short] Android
     */
    void onTargetIDArrow(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupOpacityPopup::sliderChanged not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn sliderChanged(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("SetupOpacityPopup::updateDuration not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateDuration();
public:
    
private:
    [[deprecated("SetupOpacityPopup::updateDurLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateDurLabel(bool p0);
public:
    
private:
    [[deprecated("SetupOpacityPopup::updateOpacity not implemented")]]
    /**
     * @note[short] Android
     */
    void updateOpacity();
public:
    
private:
    [[deprecated("SetupOpacityPopup::updateOpacityLabel not implemented")]]
    /**
     * @note[short] Android
     */
    void updateOpacityLabel();
public:
    
private:
    [[deprecated("SetupOpacityPopup::updateTargetID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTargetID();
public:
    
private:
    [[deprecated("SetupOpacityPopup::updateTextInputLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTextInputLabel();
public:
};
