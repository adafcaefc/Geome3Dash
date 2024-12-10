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

class SetupItemCompareTriggerPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupItemCompareTriggerPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupItemCompareTriggerPopup, SetupTriggerPopup)

    /**
     * @note[short] Android
     */
    static SetupItemCompareTriggerPopup* create(ItemTriggerGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] MacOS (ARM): 0x4c0da8
     * @note[short] MacOS (Intel): 0x56bbc0
     * @note[short] iOS: 0x40708c
     * @note[short] Android
     */
    virtual void valueDidChange(int p0, float p1);

    /**
     * @note[short] MacOS (ARM): 0x4c0c50
     * @note[short] MacOS (Intel): 0x56ba60
     * @note[short] iOS: 0x406f44
     * @note[short] Android
     */
    virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x4beef4
     * @note[short] MacOS (Intel): 0x569ae0
     * @note[short] Android
     */
    bool init(ItemTriggerGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] Android
     */
    void onOpButton(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    TodoReturn updateFormulaLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateOpButton(CCMenuItemSpriteExtra* p0, int p1, int p2);
};
