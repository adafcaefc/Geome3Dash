#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "FLAlertLayer.hpp"
#include "TextInputDelegate.hpp"

class SetupObjectOptionsPopup : public FLAlertLayer, public TextInputDelegate {
public:
    static constexpr auto CLASS_NAME = "SetupObjectOptionsPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupObjectOptionsPopup, FLAlertLayer)

    /**
     * @note[short] Android
     */
    static SetupObjectOptionsPopup* create(GameObject* p0, cocos2d::CCArray* p1, SetGroupIDLayer* p2);

    /**
     * @note[short] MacOS (ARM): 0x29dd48
     * @note[short] MacOS (Intel): 0x306b70
     * @note[short] iOS: 0x45288
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x29dd6c
     * @note[short] MacOS (Intel): 0x306bb0
     * @note[short] iOS: 0x452ac
     * @note[short] Android
     */
    virtual void show();

    /**
     * @note[short] MacOS (ARM): 0x29da98
     * @note[short] MacOS (Intel): 0x306760
     * @note[short] Windows: 0x3e7cd0
     * @note[short] iOS: 0x450a4
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x29ddb8
     * @note[short] MacOS (Intel): 0x306c10
     * @note[short] iOS: 0x452f8
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x29b3ac
     * @note[short] MacOS (Intel): 0x3039a0
     * @note[short] Android
     */
    bool init(GameObject* p0, cocos2d::CCArray* p1, SetGroupIDLayer* p2);

    /**
     * @note[short] Android
     */
    void onAlwaysHide(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onApplyScaleStick(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onCenterEffect(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onDisableGlow(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onDisableObject(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onDontBoost(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onDontBoostX(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onDontEnter(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onDontFade(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onExtendedCollision(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onExtraSticky(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onGripSlope(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onHideEffects(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onHighDetail(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onIceBlock(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onNoAudioScale(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onNonStickX(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onNonStickY(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onNoParticle(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onPassable(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onReverse(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onSinglePlayerTouch(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onToggleAreaParent(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onToggleGroupParent(cocos2d::CCObject* sender);
};
