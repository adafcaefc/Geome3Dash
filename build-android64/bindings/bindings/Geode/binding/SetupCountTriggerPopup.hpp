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

    /**
     * @note[short] Android
     */
    static SetupCountTriggerPopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] MacOS (ARM): 0x24f140
     * @note[short] MacOS (Intel): 0x2a8e10
     * @note[short] iOS: 0xf7c00
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x24f618
     * @note[short] MacOS (Intel): 0x2a93a0
     * @note[short] iOS: 0xf7fd0
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x24f3f4
     * @note[short] MacOS (Intel): 0x2a9140
     * @note[short] Windows: 0x404650
     * @note[short] iOS: 0xf7e90
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x24de94
     * @note[short] MacOS (Intel): 0x2a7950
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] Android
     */
    void onEnableGroup(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onItemIDArrow(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onMultiActivate(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onTargetCountArrow(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onTargetIDArrow(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    TodoReturn updateCountTextInputLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateItemID();

    /**
     * @note[short] Android
     */
    TodoReturn updateItemIDInputLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateTargetCount();

    /**
     * @note[short] Android
     */
    TodoReturn updateTargetID();

    /**
     * @note[short] Android
     */
    TodoReturn updateTargetIDInputLabel();
};
