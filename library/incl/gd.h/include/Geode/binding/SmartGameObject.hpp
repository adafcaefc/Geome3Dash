#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "GameObject.hpp"

class SmartGameObject : public GameObject {
public:
    static constexpr auto CLASS_NAME = "SmartGameObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SmartGameObject, GameObject)
    
private:
    [[deprecated("SmartGameObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SmartGameObject* create(char const* p0);
public:
    
private:
    [[deprecated("SmartGameObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1631f0
     * @note[short] MacOS (Intel): 0x1a0680
     * @note[short] iOS: 0x379920
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:
    
private:
    [[deprecated("SmartGameObject::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x162cf4
     * @note[short] MacOS (Intel): 0x1a00c0
     * @note[short] iOS: 0x37978c
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
public:
    
private:
    [[deprecated("SmartGameObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(char const* p0);
public:
    
private:
    [[deprecated("SmartGameObject::updateSmartFrame not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateSmartFrame();
public:
    bool m_property157;
};
