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

class RingObject : public EffectGameObject {
public:
    static constexpr auto CLASS_NAME = "RingObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(RingObject, EffectGameObject)

    /**
     * @note[short] Windows: 0x489570
     * @note[short] Android
     */
    static RingObject* create(char const* p0);
    
private:
    [[deprecated("RingObject::setScale not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x165ca8
     * @note[short] MacOS (Intel): 0x1a3520
     * @note[short] iOS: 0x37b5e4
     * @note[short] Android
     */
    virtual void setScale(float p0);
public:
    
private:
    [[deprecated("RingObject::setRotation not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x165d08
     * @note[short] MacOS (Intel): 0x1a3580
     * @note[short] iOS: 0x37b634
     * @note[short] Android
     */
    virtual void setRotation(float p0);
public:
    
private:
    [[deprecated("RingObject::resetObject not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x165c7c
     * @note[short] MacOS (Intel): 0x1a3500
     * @note[short] iOS: 0x37b5b8
     * @note[short] Android
     */
    virtual void resetObject();
public:
    
private:
    [[deprecated("RingObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x165d1c
     * @note[short] MacOS (Intel): 0x1a35b0
     * @note[short] iOS: 0x37b648
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:
    
private:
    [[deprecated("RingObject::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x165e28
     * @note[short] MacOS (Intel): 0x1a3700
     * @note[short] iOS: 0x37b748
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
public:
    
private:
    [[deprecated("RingObject::setRScale not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x165cd8
     * @note[short] MacOS (Intel): 0x1a3550
     * @note[short] iOS: 0x37b60c
     * @note[short] Android
     */
    virtual void setRScale(float p0);
public:
    
private:
    [[deprecated("RingObject::triggerActivated not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x165b30
     * @note[short] MacOS (Intel): 0x1a33a0
     * @note[short] iOS: 0x37b46c
     * @note[short] Android
     */
    virtual void triggerActivated(float p0);
public:
    
private:
    [[deprecated("RingObject::shouldDrawEditorHitbox not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x165d0c
     * @note[short] MacOS (Intel): 0x1a3590
     * @note[short] iOS: 0x37b638
     * @note[short] Android
     */
    virtual bool shouldDrawEditorHitbox();
public:
    
private:
    [[deprecated("RingObject::powerOnObject not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x165b3c
     * @note[short] MacOS (Intel): 0x1a33b0
     * @note[short] iOS: 0x37b478
     * @note[short] Android
     */
    virtual TodoReturn powerOnObject(int p0);
public:
    
private:
    [[deprecated("RingObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(char const* p0);
public:
    
private:
    [[deprecated("RingObject::spawnCircle not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn spawnCircle();
public:
    bool m_claimTouch;
    bool m_isSpawnOnly;
};
