#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class SpawnTriggerAction {
public:
    static constexpr auto CLASS_NAME = "SpawnTriggerAction";
    
private:
    [[deprecated("SpawnTriggerAction::isFinished not implemented")]]
    /**
     * @note[short] Android
     */
    bool isFinished();
public:
    
private:
    [[deprecated("SpawnTriggerAction::step not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn step(float p0);
public:
    GEODE_PAD(40);
    GameObject* m_gameObject;
    gd::vector<int> m_unkVecInt;
};
