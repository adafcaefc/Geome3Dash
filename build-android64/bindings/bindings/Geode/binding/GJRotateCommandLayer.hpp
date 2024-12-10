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

    /**
     * @note[short] Android
     */
    static GJRotateCommandLayer* create(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] MacOS (ARM): 0x6cc8
     * @note[short] MacOS (Intel): 0x45d0
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x7988
     * @note[short] MacOS (Intel): 0x5520
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x7534
     * @note[short] MacOS (Intel): 0x4f80
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x7148
     * @note[short] MacOS (Intel): 0x4af0
     * @note[short] Android
     */
    virtual void valuePopupClosed(ConfigureValuePopup* p0, float p1);

    /**
     * @note[short] MacOS (ARM): 0x461c
     * @note[short] MacOS (Intel): 0x1d60
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] Android
     */
    void onEasing(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onEasingRate(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onFollowRotation(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onLockRotation(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onUpdateGroupID(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onUpdateGroupID2(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    TodoReturn sliderChanged(cocos2d::CCObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn sliderDegreesChanged(cocos2d::CCObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn sliderTimesChanged(cocos2d::CCObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn toggleEasingRateVisibility();

    /**
     * @note[short] Android
     */
    TodoReturn updateCommandDegrees();

    /**
     * @note[short] Android
     */
    TodoReturn updateCommandTimes();

    /**
     * @note[short] Android
     */
    TodoReturn updateDegreesLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateDuration();

    /**
     * @note[short] Android
     */
    TodoReturn updateDurLabel(bool p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateEasingLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateEasingRateLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateMoveCommandEasing();

    /**
     * @note[short] Android
     */
    TodoReturn updateMoveCommandEasingRate();

    /**
     * @note[short] Android
     */
    TodoReturn updateTargetGroupID();

    /**
     * @note[short] Android
     */
    TodoReturn updateTargetGroupID2();

    /**
     * @note[short] Android
     */
    TodoReturn updateTextInputLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateTextInputLabel2();

    /**
     * @note[short] Android
     */
    TodoReturn updateTimesLabel();
};
