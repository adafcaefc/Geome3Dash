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

class KeyframeGameObject : public EffectGameObject {
public:
    static constexpr auto CLASS_NAME = "KeyframeGameObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(KeyframeGameObject, EffectGameObject)
    
private:
    [[deprecated("KeyframeGameObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static KeyframeGameObject* create();
public:
    
private:
    [[deprecated("KeyframeGameObject::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1750f4
     * @note[short] MacOS (Intel): 0x1b5420
     * @note[short] iOS: 0x383c34
     * @note[short] Android
     */
    virtual bool init();
public:

    /**
     * @note[short] MacOS (ARM): 0x1753e0
     * @note[short] MacOS (Intel): 0x1b5700
     * @note[short] Windows: 0x49cba0
     * @note[short] iOS: 0x383ef8
     * @note[short] Android
     */
    virtual void setOpacity(unsigned char p0);
    
private:
    [[deprecated("KeyframeGameObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x17552c
     * @note[short] MacOS (Intel): 0x1b5860
     * @note[short] iOS: 0x383fa4
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:
    
private:
    [[deprecated("KeyframeGameObject::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1759d4
     * @note[short] MacOS (Intel): 0x1b5dd0
     * @note[short] iOS: 0x3843ac
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
public:
    
private:
    [[deprecated("KeyframeGameObject::updateShadowObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateShadowObjects(GJBaseGameLayer* p0, EditorUI* p1);
public:
};
