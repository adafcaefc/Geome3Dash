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

class ArtTriggerGameObject : public EffectGameObject {
public:
    static constexpr auto CLASS_NAME = "ArtTriggerGameObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(ArtTriggerGameObject, EffectGameObject)
    
private:
    [[deprecated("ArtTriggerGameObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static ArtTriggerGameObject* create(char const* p0);
public:
    
private:
    [[deprecated("ArtTriggerGameObject::triggerObject not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x194614
     * @note[short] MacOS (Intel): 0x1db7e0
     * @note[short] iOS: 0x390034
     * @note[short] Android
     */
    virtual void triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2);
public:
    
private:
    [[deprecated("ArtTriggerGameObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x19459c
     * @note[short] MacOS (Intel): 0x1db780
     * @note[short] iOS: 0x38ffcc
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:
    
private:
    [[deprecated("ArtTriggerGameObject::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x194120
     * @note[short] MacOS (Intel): 0x1db260
     * @note[short] iOS: 0x38fe3c
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
public:
    
private:
    [[deprecated("ArtTriggerGameObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(char const* p0);
public:
};
