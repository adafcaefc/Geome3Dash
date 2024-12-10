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

class SetupOpacityPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupOpacityPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupOpacityPopup, SetupTriggerPopup)

    /**
     * @note[short] Android
     */
    static SetupOpacityPopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] MacOS (ARM): 0x4e708
     * @note[short] MacOS (Intel): 0x58780
     * @note[short] iOS: 0x280e8
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x4ec00
     * @note[short] MacOS (Intel): 0x58d80
     * @note[short] iOS: 0x284f4
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x4e9c0
     * @note[short] MacOS (Intel): 0x58ae0
     * @note[short] iOS: 0x28374
     * @note[short] Android
     */
    virtual void textInputClosed(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x4e9dc
     * @note[short] MacOS (Intel): 0x58b20
     * @note[short] Windows: 0x413a50
     * @note[short] iOS: 0x28390
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x4d5e0
     * @note[short] MacOS (Intel): 0x57560
     * @note[short] Windows: 0x412860
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);

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
    TodoReturn updateDuration();

    /**
     * @note[short] Android
     */
    TodoReturn updateDurLabel(bool p0);

    /**
     * @note[short] Android
     */
    void updateOpacity();

    /**
     * @note[short] Android
     */
    void updateOpacityLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateTargetID();

    /**
     * @note[short] Android
     */
    TodoReturn updateTextInputLabel();
};
