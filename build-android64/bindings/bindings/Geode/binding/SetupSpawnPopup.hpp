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

class SetupSpawnPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupSpawnPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupSpawnPopup, SetupTriggerPopup)

    /**
     * @note[short] Android
     */
    static SetupSpawnPopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] MacOS (ARM): 0x2286cc
     * @note[short] MacOS (Intel): 0x27ece0
     * @note[short] iOS: 0xfbd4c
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x2271a4
     * @note[short] MacOS (Intel): 0x27d4f0
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] Android
     */
    void onAddRemap(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onDeleteRemap(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onSelectRemap(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    TodoReturn queueUpdateButtons();

    /**
     * @note[short] Android
     */
    TodoReturn updateRemapButtons(float p0);
};
