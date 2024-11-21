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

class TransformTriggerGameObject : public EffectGameObject {
public:
    static constexpr auto CLASS_NAME = "TransformTriggerGameObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(TransformTriggerGameObject, EffectGameObject)
    
private:
    [[deprecated("TransformTriggerGameObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static TransformTriggerGameObject* create(char const* p0);
public:
    
private:
    [[deprecated("TransformTriggerGameObject::triggerObject not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1847d4
     * @note[short] MacOS (Intel): 0x1c7c90
     * @note[short] iOS: 0x38a2c0
     * @note[short] Android
     */
    virtual void triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2);
public:
    
private:
    [[deprecated("TransformTriggerGameObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1847f8
     * @note[short] MacOS (Intel): 0x1c7cc0
     * @note[short] iOS: 0x38a2e4
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:
    
private:
    [[deprecated("TransformTriggerGameObject::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x184ac0
     * @note[short] MacOS (Intel): 0x1c80a0
     * @note[short] iOS: 0x38a574
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
public:
    
private:
    [[deprecated("TransformTriggerGameObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(char const* p0);
public:
};
