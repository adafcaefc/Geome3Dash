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

class SetupCollisionTriggerPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupCollisionTriggerPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupCollisionTriggerPopup, SetupTriggerPopup)

    /**
     * @note[short] Android
     */
    static SetupCollisionTriggerPopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] MacOS (ARM): 0x3139c4
     * @note[short] MacOS (Intel): 0x383820
     * @note[short] iOS: 0x230460
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x313f38
     * @note[short] MacOS (Intel): 0x383eb0
     * @note[short] iOS: 0x23086c
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x313ccc
     * @note[short] MacOS (Intel): 0x383bc0
     * @note[short] Windows: 0x401ac0
     * @note[short] iOS: 0x23072c
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x3125a4
     * @note[short] MacOS (Intel): 0x382240
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] Android
     */
    void onActivateOnExit(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onEnableGroup(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onItemID2Arrow(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onItemIDArrow(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onTargetIDArrow(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onTargetP1(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onTargetP2(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onTargetPP(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    TodoReturn updateItemID();

    /**
     * @note[short] Android
     */
    TodoReturn updateItemID2();

    /**
     * @note[short] Android
     */
    TodoReturn updateItemID2InputLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateItemIDInputLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateTargetID();

    /**
     * @note[short] Android
     */
    TodoReturn updateTargetIDInputLabel();
};
