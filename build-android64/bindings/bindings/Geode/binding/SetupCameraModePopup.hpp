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

class SetupCameraModePopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupCameraModePopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupCameraModePopup, SetupTriggerPopup)

    /**
     * @note[short] Android
     */
    static SetupCameraModePopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] MacOS (ARM): 0x402fc0
     * @note[short] MacOS (Intel): 0x496b80
     * @note[short] iOS: 0x3a3b64
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x403274
     * @note[short] MacOS (Intel): 0x496e70
     * @note[short] iOS: 0x3a3dec
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x4022e4
     * @note[short] MacOS (Intel): 0x495d30
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] Android
     */
    void onEditCameraSettings(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onUnboundMode(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    TodoReturn sliderChanged(cocos2d::CCObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateCameraEasing();

    /**
     * @note[short] Android
     */
    TodoReturn updateCameraEasingLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateCameraPadding();

    /**
     * @note[short] MacOS (ARM): 0x402ed4
     * @note[short] MacOS (Intel): 0x496a80
     * @note[short] Android
     */
    TodoReturn updateCameraPaddingLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateItemVisibility();
};
