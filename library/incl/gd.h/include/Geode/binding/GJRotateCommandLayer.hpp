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

class GJRotateCommandLayer : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "GJRotateCommandLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(GJRotateCommandLayer, SetupTriggerPopup)
    
private:
    [[deprecated("GJRotateCommandLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static GJRotateCommandLayer* create(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("GJRotateCommandLayer::determineStartValues not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x6cc8
     * @note[short] MacOS (Intel): 0x45d0
     * @note[short] Android
     */
    virtual void determineStartValues();
public:
    
private:
    [[deprecated("GJRotateCommandLayer::onClose not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x7988
     * @note[short] MacOS (Intel): 0x5520
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJRotateCommandLayer::textChanged not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x7534
     * @note[short] MacOS (Intel): 0x4f80
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);
public:
    
private:
    [[deprecated("GJRotateCommandLayer::valuePopupClosed not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x7148
     * @note[short] MacOS (Intel): 0x4af0
     * @note[short] Android
     */
    virtual void valuePopupClosed(ConfigureValuePopup* p0, float p1);
public:
    
private:
    [[deprecated("GJRotateCommandLayer::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x461c
     * @note[short] MacOS (Intel): 0x1d60
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("GJRotateCommandLayer::onEasing not implemented")]]
    /**
     * @note[short] Android
     */
    void onEasing(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJRotateCommandLayer::onEasingRate not implemented")]]
    /**
     * @note[short] Android
     */
    void onEasingRate(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJRotateCommandLayer::onFollowRotation not implemented")]]
    /**
     * @note[short] Android
     */
    void onFollowRotation(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJRotateCommandLayer::onLockRotation not implemented")]]
    /**
     * @note[short] Android
     */
    void onLockRotation(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJRotateCommandLayer::onUpdateGroupID not implemented")]]
    /**
     * @note[short] Android
     */
    void onUpdateGroupID(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJRotateCommandLayer::onUpdateGroupID2 not implemented")]]
    /**
     * @note[short] Android
     */
    void onUpdateGroupID2(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJRotateCommandLayer::sliderChanged not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn sliderChanged(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("GJRotateCommandLayer::sliderDegreesChanged not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn sliderDegreesChanged(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("GJRotateCommandLayer::sliderTimesChanged not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn sliderTimesChanged(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("GJRotateCommandLayer::toggleEasingRateVisibility not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleEasingRateVisibility();
public:
    
private:
    [[deprecated("GJRotateCommandLayer::updateCommandDegrees not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateCommandDegrees();
public:
    
private:
    [[deprecated("GJRotateCommandLayer::updateCommandTimes not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateCommandTimes();
public:
    
private:
    [[deprecated("GJRotateCommandLayer::updateDegreesLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateDegreesLabel();
public:
    
private:
    [[deprecated("GJRotateCommandLayer::updateDuration not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateDuration();
public:
    
private:
    [[deprecated("GJRotateCommandLayer::updateDurLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateDurLabel(bool p0);
public:
    
private:
    [[deprecated("GJRotateCommandLayer::updateEasingLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateEasingLabel();
public:
    
private:
    [[deprecated("GJRotateCommandLayer::updateEasingRateLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateEasingRateLabel();
public:
    
private:
    [[deprecated("GJRotateCommandLayer::updateMoveCommandEasing not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateMoveCommandEasing();
public:
    
private:
    [[deprecated("GJRotateCommandLayer::updateMoveCommandEasingRate not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateMoveCommandEasingRate();
public:
    
private:
    [[deprecated("GJRotateCommandLayer::updateTargetGroupID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTargetGroupID();
public:
    
private:
    [[deprecated("GJRotateCommandLayer::updateTargetGroupID2 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTargetGroupID2();
public:
    
private:
    [[deprecated("GJRotateCommandLayer::updateTextInputLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTextInputLabel();
public:
    
private:
    [[deprecated("GJRotateCommandLayer::updateTextInputLabel2 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTextInputLabel2();
public:
    
private:
    [[deprecated("GJRotateCommandLayer::updateTimesLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTimesLabel();
public:
};
