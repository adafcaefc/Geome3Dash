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

class MultiTriggerPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "MultiTriggerPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(MultiTriggerPopup, SetupTriggerPopup)
    
private:
    [[deprecated("MultiTriggerPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static MultiTriggerPopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("MultiTriggerPopup::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4bb4cc
     * @note[short] MacOS (Intel): 0x565ad0
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
};
