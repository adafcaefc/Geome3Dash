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

class SetupAnimationPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupAnimationPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupAnimationPopup, SetupTriggerPopup)

    /**
     * @note[short] Android
     */
    static SetupAnimationPopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] MacOS (ARM): 0x34bdd0
     * @note[short] MacOS (Intel): 0x3c29f0
     * @note[short] iOS: 0x3bc428
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x34c158
     * @note[short] MacOS (Intel): 0x3c2e10
     * @note[short] iOS: 0x3bc6dc
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x34bfb0
     * @note[short] MacOS (Intel): 0x3c2c20
     * @note[short] Windows: 0x3f2060
     * @note[short] iOS: 0x3bc600
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x34af78
     * @note[short] MacOS (Intel): 0x3c1a90
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] Android
     */
    void onAnimationIDArrow(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onTargetIDArrow(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    TodoReturn updateAnimationID();

    /**
     * @note[short] Android
     */
    TodoReturn updateAnimationTextInputLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateTargetID();

    /**
     * @note[short] Android
     */
    TodoReturn updateTextInputLabel();
};
