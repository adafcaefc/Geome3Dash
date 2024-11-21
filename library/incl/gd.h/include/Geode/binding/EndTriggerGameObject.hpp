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

class EndTriggerGameObject : public EffectGameObject {
public:
    static constexpr auto CLASS_NAME = "EndTriggerGameObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(EndTriggerGameObject, EffectGameObject)
    
private:
    [[deprecated("EndTriggerGameObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static EndTriggerGameObject* create();
public:
    
private:
    [[deprecated("EndTriggerGameObject::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1864c4
     * @note[short] MacOS (Intel): 0x1ca130
     * @note[short] iOS: 0x38ad10
     * @note[short] Android
     */
    virtual bool init();
public:

    /**
     * @note[short] MacOS (ARM): 0x186514
     * @note[short] MacOS (Intel): 0x1ca180
     * @note[short] Windows: 0x4a4180
     * @note[short] iOS: 0x38ad60
     * @note[short] Android
     */
    virtual void triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2);
    
private:
    [[deprecated("EndTriggerGameObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1870ac
     * @note[short] MacOS (Intel): 0x1caf50
     * @note[short] iOS: 0x38b0ec
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:
    
private:
    [[deprecated("EndTriggerGameObject::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1865f0
     * @note[short] MacOS (Intel): 0x1ca260
     * @note[short] iOS: 0x38adec
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
public:
    bool m_noEffects;
    bool m_noSFX;
    bool m_instant;
};
