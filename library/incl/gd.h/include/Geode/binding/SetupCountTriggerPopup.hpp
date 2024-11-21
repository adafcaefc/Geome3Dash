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

class SetupCountTriggerPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupCountTriggerPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupCountTriggerPopup, SetupTriggerPopup)
    
private:
    [[deprecated("SetupCountTriggerPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupCountTriggerPopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupCountTriggerPopup::determineStartValues not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x24f140
     * @note[short] MacOS (Intel): 0x2a8e10
     * @note[short] iOS: 0xf7c00
     * @note[short] Android
     */
    virtual void determineStartValues();
public:
    
private:
    [[deprecated("SetupCountTriggerPopup::onClose not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x24f618
     * @note[short] MacOS (Intel): 0x2a93a0
     * @note[short] iOS: 0xf7fd0
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x24f3f4
     * @note[short] MacOS (Intel): 0x2a9140
     * @note[short] Windows: 0x404650
     * @note[short] iOS: 0xf7e90
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);
    
private:
    [[deprecated("SetupCountTriggerPopup::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x24de94
     * @note[short] MacOS (Intel): 0x2a7950
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupCountTriggerPopup::onEnableGroup not implemented")]]
    /**
     * @note[short] Android
     */
    void onEnableGroup(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupCountTriggerPopup::onItemIDArrow not implemented")]]
    /**
     * @note[short] Android
     */
    void onItemIDArrow(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupCountTriggerPopup::onMultiActivate not implemented")]]
    /**
     * @note[short] Android
     */
    void onMultiActivate(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupCountTriggerPopup::onTargetCountArrow not implemented")]]
    /**
     * @note[short] Android
     */
    void onTargetCountArrow(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupCountTriggerPopup::onTargetIDArrow not implemented")]]
    /**
     * @note[short] Android
     */
    void onTargetIDArrow(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupCountTriggerPopup::updateCountTextInputLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateCountTextInputLabel();
public:
    
private:
    [[deprecated("SetupCountTriggerPopup::updateItemID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateItemID();
public:
    
private:
    [[deprecated("SetupCountTriggerPopup::updateItemIDInputLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateItemIDInputLabel();
public:
    
private:
    [[deprecated("SetupCountTriggerPopup::updateTargetCount not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTargetCount();
public:
    
private:
    [[deprecated("SetupCountTriggerPopup::updateTargetID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTargetID();
public:
    
private:
    [[deprecated("SetupCountTriggerPopup::updateTargetIDInputLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTargetIDInputLabel();
public:
};
