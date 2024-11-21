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

class PlayerControlGameObject : public EffectGameObject {
public:
    static constexpr auto CLASS_NAME = "PlayerControlGameObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(PlayerControlGameObject, EffectGameObject)
    
private:
    [[deprecated("PlayerControlGameObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static PlayerControlGameObject* create();
public:
    
private:
    [[deprecated("PlayerControlGameObject::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x194730
     * @note[short] MacOS (Intel): 0x1db900
     * @note[short] iOS: 0x390144
     * @note[short] Android
     */
    virtual bool init();
public:
    
private:
    [[deprecated("PlayerControlGameObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x195378
     * @note[short] MacOS (Intel): 0x1dc830
     * @note[short] iOS: 0x3904f0
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:
    
private:
    [[deprecated("PlayerControlGameObject::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x194780
     * @note[short] MacOS (Intel): 0x1db950
     * @note[short] iOS: 0x390194
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
public:
};
