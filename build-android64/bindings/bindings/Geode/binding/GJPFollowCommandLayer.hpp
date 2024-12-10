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

class GJPFollowCommandLayer : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "GJPFollowCommandLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(GJPFollowCommandLayer, SetupTriggerPopup)

    /**
     * @note[short] Android
     */
    static GJPFollowCommandLayer* create(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] MacOS (ARM): 0x2e7324
     * @note[short] MacOS (Intel): 0x353270
     * @note[short] iOS: 0x16384c
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x2e7e78
     * @note[short] MacOS (Intel): 0x354000
     * @note[short] iOS: 0x16412c
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x2e78a0
     * @note[short] MacOS (Intel): 0x353890
     * @note[short] Windows: 0x284d20
     * @note[short] iOS: 0x163d48
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x2e54c8
     * @note[short] MacOS (Intel): 0x351320
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
    TodoReturn updateMaxSpeed();

    /**
     * @note[short] Android
     */
    TodoReturn updateMaxSpeedLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateOffsetLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updatePlayerOffset();

    /**
     * @note[short] Android
     */
    TodoReturn updateTargetGroupID();

    /**
     * @note[short] Android
     */
    TodoReturn updateTextInputLabel();

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
