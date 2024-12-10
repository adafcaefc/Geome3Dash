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

class SetupRandTriggerPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupRandTriggerPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupRandTriggerPopup, SetupTriggerPopup)

    /**
     * @note[short] Android
     */
    static SetupRandTriggerPopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] MacOS (ARM): 0x5028bc
     * @note[short] MacOS (Intel): 0x5ce3b0
     * @note[short] iOS: 0x1cb858
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x502ddc
     * @note[short] MacOS (Intel): 0x5ce990
     * @note[short] iOS: 0x1cbc54
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x502b44
     * @note[short] MacOS (Intel): 0x5ce6a0
     * @note[short] Windows: 0x4288e0
     * @note[short] iOS: 0x1cbad0
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x5016b0
     * @note[short] MacOS (Intel): 0x5cd0b0
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] Android
     */
    void onTargetID2Arrow(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onTargetIDArrow(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    TodoReturn sliderChanged(cocos2d::CCObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateChance();

    /**
     * @note[short] Android
     */
    TodoReturn updateChanceLabel(bool p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateTargetID();

    /**
     * @note[short] Android
     */
    TodoReturn updateTargetID2();

    /**
     * @note[short] Android
     */
    TodoReturn updateTextInputLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateTextInputLabel2();
};
