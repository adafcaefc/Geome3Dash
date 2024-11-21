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

class ItemTriggerGameObject : public EffectGameObject {
public:
    static constexpr auto CLASS_NAME = "ItemTriggerGameObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(ItemTriggerGameObject, EffectGameObject)
    
private:
    [[deprecated("ItemTriggerGameObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static ItemTriggerGameObject* create(char const* p0);
public:
    
private:
    [[deprecated("ItemTriggerGameObject::customSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x18db5c
     * @note[short] MacOS (Intel): 0x1d3670
     * @note[short] iOS: 0x38d9e0
     * @note[short] Android
     */
    virtual void customSetup();
public:

    /**
     * @note[short] MacOS (ARM): 0x18db94
     * @note[short] MacOS (Intel): 0x1d36b0
     * @note[short] Windows: 0x4a71a0
     * @note[short] iOS: 0x38da18
     * @note[short] Android
     */
    virtual void triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2);
    
private:
    [[deprecated("ItemTriggerGameObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1916e0
     * @note[short] MacOS (Intel): 0x1d83a0
     * @note[short] iOS: 0x38e954
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x18dce4
     * @note[short] MacOS (Intel): 0x1d3800
     * @note[short] Windows: 0x4a7300
     * @note[short] iOS: 0x38db00
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
    
private:
    [[deprecated("ItemTriggerGameObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(char const* p0);
public:
};
