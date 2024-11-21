#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "EffectGameObject.hpp"

class EnhancedTriggerObject : public EffectGameObject {
public:
    static constexpr auto CLASS_NAME = "EnhancedTriggerObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(EnhancedTriggerObject, EffectGameObject)
    
private:
    [[deprecated("EnhancedTriggerObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static EnhancedTriggerObject* create(char const* p0);
public:
    
private:
    [[deprecated("EnhancedTriggerObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16d4e8
     * @note[short] MacOS (Intel): 0x1ac3b0
     * @note[short] iOS: 0x38017c
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:
    
private:
    [[deprecated("EnhancedTriggerObject::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16cbf8
     * @note[short] MacOS (Intel): 0x1ab8c0
     * @note[short] iOS: 0x37fed8
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
public:
    
private:
    [[deprecated("EnhancedTriggerObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(char const* p0);
public:
};
