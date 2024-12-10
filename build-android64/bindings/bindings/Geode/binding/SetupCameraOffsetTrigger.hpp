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

class SetupCameraOffsetTrigger : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupCameraOffsetTrigger";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupCameraOffsetTrigger, SetupTriggerPopup)

    /**
     * @note[short] Android
     */
    static SetupCameraOffsetTrigger* create(CameraTriggerGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] MacOS (ARM): 0x57505c
     * @note[short] MacOS (Intel): 0x64d090
     * @note[short] iOS: 0x193bc8
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x575a68
     * @note[short] MacOS (Intel): 0x64dbc0
     * @note[short] iOS: 0x194458
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x5757e8
     * @note[short] MacOS (Intel): 0x64d890
     * @note[short] Windows: 0x3ff6f0
     * @note[short] iOS: 0x194230
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x57542c
     * @note[short] MacOS (Intel): 0x64d460
     * @note[short] Windows: 0x3fedf0
     * @note[short] iOS: 0x193f00
     * @note[short] Android
     */
    virtual void valuePopupClosed(ConfigureValuePopup* p0, float p1);

    /**
     * @note[short] MacOS (ARM): 0x57347c
     * @note[short] MacOS (Intel): 0x64b350
     * @note[short] Android
     */
    bool init(CameraTriggerGameObject* p0, cocos2d::CCArray* p1);

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
    void onTargetMode(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    TodoReturn posFromSliderValue(float p0);

    /**
     * @note[short] Android
     */
    TodoReturn sliderChanged(cocos2d::CCObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn sliderValueFromPos(int p0);

    /**
     * @note[short] Android
     */
    TodoReturn sliderXChanged(cocos2d::CCObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn sliderYChanged(cocos2d::CCObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn toggleEasingRateVisibility();

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
    TodoReturn updateMoveCommandPosX();

    /**
     * @note[short] Android
     */
    TodoReturn updateMoveCommandPosY();

    /**
     * @note[short] Android
     */
    TodoReturn updateValueXLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateValueYLabel();
};
