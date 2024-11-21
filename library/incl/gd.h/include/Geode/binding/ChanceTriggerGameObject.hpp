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

class ChanceTriggerGameObject : public EffectGameObject {
public:
    static constexpr auto CLASS_NAME = "ChanceTriggerGameObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(ChanceTriggerGameObject, EffectGameObject)
    
private:
    [[deprecated("ChanceTriggerGameObject::editChanceObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn editChanceObject(int p0, int p1);
public:
    
private:
    [[deprecated("ChanceTriggerGameObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(char const* p0);
public:
    
private:
    [[deprecated("ChanceTriggerGameObject::remapChanceObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn remapChanceObjects(gd::unordered_map<int, int> const* p0);
public:
    
private:
    [[deprecated("ChanceTriggerGameObject::revertChanceRemap not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn revertChanceRemap();
public:
};
