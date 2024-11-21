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

class EnterEffectObject : public EffectGameObject {
public:
    static constexpr auto CLASS_NAME = "EnterEffectObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(EnterEffectObject, EffectGameObject)
    
private:
    [[deprecated("EnterEffectObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static EnterEffectObject* create(char const* p0);
public:
    
private:
    [[deprecated("EnterEffectObject::customSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x14e030
     * @note[short] MacOS (Intel): 0x186570
     * @note[short] iOS: 0x36ffc0
     * @note[short] Android
     */
    virtual void customSetup();
public:
    
private:
    [[deprecated("EnterEffectObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x14e368
     * @note[short] MacOS (Intel): 0x1868b0
     * @note[short] iOS: 0x370254
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:
    
private:
    [[deprecated("EnterEffectObject::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x140604
     * @note[short] MacOS (Intel): 0x174880
     * @note[short] iOS: 0x369c38
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
public:
    
private:
    [[deprecated("EnterEffectObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(char const* p0);
public:
    
private:
    [[deprecated("EnterEffectObject::resetEnterAnimValues not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetEnterAnimValues();
public:
};
