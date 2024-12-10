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

class GJFollowCommandLayer : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "GJFollowCommandLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(GJFollowCommandLayer, SetupTriggerPopup)

    /**
     * @note[short] Android
     */
    static GJFollowCommandLayer* create(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] MacOS (ARM): 0x267ae4
     * @note[short] MacOS (Intel): 0x2c39d0
     * @note[short] iOS: 0x13a72c
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x268494
     * @note[short] MacOS (Intel): 0x2c45a0
     * @note[short] iOS: 0x13aed4
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x268044
     * @note[short] MacOS (Intel): 0x2c3fe0
     * @note[short] Windows: 0x26a850
     * @note[short] iOS: 0x13ac1c
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x2661e4
     * @note[short] MacOS (Intel): 0x2c1fb0
     * @note[short] Windows: 0x268e30
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);

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
    TodoReturn sliderXModChanged(cocos2d::CCObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn sliderYModChanged(cocos2d::CCObject* p0);

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
    TodoReturn updateXMod();

    /**
     * @note[short] Android
     */
    TodoReturn updateXModLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateYMod();

    /**
     * @note[short] Android
     */
    TodoReturn updateYModLabel();
};
