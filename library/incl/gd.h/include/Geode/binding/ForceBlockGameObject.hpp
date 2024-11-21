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

class ForceBlockGameObject : public EffectGameObject {
public:
    static constexpr auto CLASS_NAME = "ForceBlockGameObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(ForceBlockGameObject, EffectGameObject)
    
private:
    [[deprecated("ForceBlockGameObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static ForceBlockGameObject* create(char const* p0);
public:
    
private:
    [[deprecated("ForceBlockGameObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x193bfc
     * @note[short] MacOS (Intel): 0x1dacc0
     * @note[short] iOS: 0x38f9a8
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:
    
private:
    [[deprecated("ForceBlockGameObject::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x192f78
     * @note[short] MacOS (Intel): 0x1d9d40
     * @note[short] iOS: 0x38f600
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
public:
    
private:
    [[deprecated("ForceBlockGameObject::calculateForceToTarget not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn calculateForceToTarget(GameObject* p0);
public:
    
private:
    [[deprecated("ForceBlockGameObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(char const* p0);
public:
};
