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

class RotateGameplayGameObject : public EffectGameObject {
public:
    static constexpr auto CLASS_NAME = "RotateGameplayGameObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(RotateGameplayGameObject, EffectGameObject)
    
private:
    [[deprecated("RotateGameplayGameObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static RotateGameplayGameObject* create();
public:
    
private:
    [[deprecated("RotateGameplayGameObject::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x198058
     * @note[short] MacOS (Intel): 0x1dfcf0
     * @note[short] iOS: 0x3918bc
     * @note[short] Android
     */
    virtual bool init();
public:
    
private:
    [[deprecated("RotateGameplayGameObject::updateStartValues not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x199834
     * @note[short] MacOS (Intel): 0x1e1a10
     * @note[short] iOS: 0x392124
     * @note[short] Android
     */
    virtual void updateStartValues();
public:
    
private:
    [[deprecated("RotateGameplayGameObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x199544
     * @note[short] MacOS (Intel): 0x1e1690
     * @note[short] iOS: 0x391e68
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:
    
private:
    [[deprecated("RotateGameplayGameObject::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1980a8
     * @note[short] MacOS (Intel): 0x1dfd40
     * @note[short] iOS: 0x39190c
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
public:
    
private:
    [[deprecated("RotateGameplayGameObject::updateGameplayRotation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateGameplayRotation();
public:
};
