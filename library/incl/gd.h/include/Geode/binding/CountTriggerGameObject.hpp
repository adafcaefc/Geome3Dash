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

class CountTriggerGameObject : public EffectGameObject {
public:
    static constexpr auto CLASS_NAME = "CountTriggerGameObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(CountTriggerGameObject, EffectGameObject)
    
private:
    [[deprecated("CountTriggerGameObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static CountTriggerGameObject* create(char const* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x182718
     * @note[short] MacOS (Intel): 0x1c52f0
     * @note[short] Windows: 0x4a26c0
     * @note[short] iOS: 0x389674
     * @note[short] Android
     */
    virtual void triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2);
    
private:
    [[deprecated("CountTriggerGameObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x182950
     * @note[short] MacOS (Intel): 0x1c5570
     * @note[short] iOS: 0x38981c
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:
    
private:
    [[deprecated("CountTriggerGameObject::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x182cdc
     * @note[short] MacOS (Intel): 0x1c59a0
     * @note[short] iOS: 0x389b1c
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
public:
    
private:
    [[deprecated("CountTriggerGameObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(char const* p0);
public:
    int m_pickupCount;
    int m_pickupTriggerMode;
    bool m_unkPickupBool1;
    bool m_isOverride;
    float m_pickupTriggerMultiplier;
};
