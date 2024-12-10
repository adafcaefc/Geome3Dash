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

class SetupTouchTogglePopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupTouchTogglePopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupTouchTogglePopup, SetupTriggerPopup)

    /**
     * @note[short] Android
     */
    static SetupTouchTogglePopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] MacOS (ARM): 0x24cb44
     * @note[short] MacOS (Intel): 0x2a6270
     * @note[short] iOS: 0x24af20
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x24ce10
     * @note[short] MacOS (Intel): 0x2a65b0
     * @note[short] iOS: 0x24b160
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x24cd0c
     * @note[short] MacOS (Intel): 0x2a6490
     * @note[short] Windows: 0x44c760
     * @note[short] iOS: 0x24b0c4
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x24bc30
     * @note[short] MacOS (Intel): 0x2a51e0
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] Android
     */
    void onControlMode(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onDualTouchMode(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onHoldMode(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onTargetIDArrow(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onTouchMode(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    TodoReturn updateTargetID();

    /**
     * @note[short] Android
     */
    TodoReturn updateTextInputLabel();
};
