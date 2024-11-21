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

class ShaderGameObject : public EffectGameObject {
public:
    static constexpr auto CLASS_NAME = "ShaderGameObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(ShaderGameObject, EffectGameObject)
    
private:
    [[deprecated("ShaderGameObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static ShaderGameObject* create(char const* p0);
public:
    
private:
    [[deprecated("ShaderGameObject::customSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1537ec
     * @note[short] MacOS (Intel): 0x18c9a0
     * @note[short] iOS: 0x373f2c
     * @note[short] Android
     */
    virtual void customSetup();
public:
    
private:
    [[deprecated("ShaderGameObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1573c4
     * @note[short] MacOS (Intel): 0x191760
     * @note[short] iOS: 0x374f24
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:
    
private:
    [[deprecated("ShaderGameObject::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x153844
     * @note[short] MacOS (Intel): 0x18ca10
     * @note[short] iOS: 0x373f7c
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
public:
    
private:
    [[deprecated("ShaderGameObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(char const* p0);
public:
};
