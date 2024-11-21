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

class StartPosObject : public EffectGameObject {
public:
    static constexpr auto CLASS_NAME = "StartPosObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(StartPosObject, EffectGameObject)
    
private:
    [[deprecated("StartPosObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static StartPosObject* create();
public:
    
private:
    [[deprecated("StartPosObject::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16d800
     * @note[short] MacOS (Intel): 0x1ac6e0
     * @note[short] iOS: 0x380370
     * @note[short] Android
     */
    virtual bool init();
public:
    
private:
    [[deprecated("StartPosObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16d93c
     * @note[short] MacOS (Intel): 0x1ac830
     * @note[short] iOS: 0x38046c
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:
    
private:
    [[deprecated("StartPosObject::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16d940
     * @note[short] MacOS (Intel): 0x1ac840
     * @note[short] iOS: 0x380470
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
public:
    
private:
    [[deprecated("StartPosObject::loadSettingsFromString not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn loadSettingsFromString(gd::string p0);
public:
    
private:
    [[deprecated("StartPosObject::setSettings not implemented")]]
    /**
     * @note[short] Android
     */
    void setSettings(LevelSettingsObject* p0);
public:
    LevelSettingsObject* m_startSettings;
};
