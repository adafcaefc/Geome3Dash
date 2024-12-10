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

class SetupMGTrigger : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupMGTrigger";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupMGTrigger, SetupTriggerPopup)

    /**
     * @note[short] Android
     */
    static SetupMGTrigger* create(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] MacOS (ARM): 0x454a5c
     * @note[short] MacOS (Intel): 0x4f3d90
     * @note[short] iOS: 0x2f2ad8
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x4551e4
     * @note[short] MacOS (Intel): 0x4f45f0
     * @note[short] iOS: 0x2f3144
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x454fcc
     * @note[short] MacOS (Intel): 0x4f4390
     * @note[short] Windows: 0x410830
     * @note[short] iOS: 0x2f2f84
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x454ce8
     * @note[short] MacOS (Intel): 0x4f4050
     * @note[short] iOS: 0x2f2d1c
     * @note[short] Android
     */
    virtual void valuePopupClosed(ConfigureValuePopup* p0, float p1);

    /**
     * @note[short] MacOS (ARM): 0x453360
     * @note[short] MacOS (Intel): 0x4f2600
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
    TodoReturn updateMoveCommandPosY();

    /**
     * @note[short] Android
     */
    TodoReturn updateValueYLabel();
};
