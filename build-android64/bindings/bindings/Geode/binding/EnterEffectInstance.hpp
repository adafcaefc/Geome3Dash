#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class EnterEffectInstance {
public:
    static constexpr auto CLASS_NAME = "EnterEffectInstance";

    /**
     * @note[short] Android
     */
     EnterEffectInstance(EnterEffectObject* p0, int p1, int p2, int p3, int p4, int p5, int p6);

    /**
     * @note[short] Android
     */
    TodoReturn animateValue(int p0, float p1, float p2, float p3, int p4, float p5, int p6);

    /**
     * @note[short] Android
     */
    TodoReturn getValue(int p0);

    /**
     * @note[short] Android
     */
    TodoReturn loadTransitions(EnterEffectObject* p0, float p1);

    /**
     * @note[short] Android
     */
    TodoReturn loadValuesFromObject(EnterEffectObject* p0);

    /**
     * @note[short] Android
     */
    void setValue(int p0, float p1);

    /**
     * @note[short] MacOS (ARM): 0x4f1338
     * @note[short] MacOS (Intel): 0x5bb680
     * @note[short] Android
     */
    void updateTransitions(float p0, GJBaseGameLayer* p1);
    gd::map<int,EnterEffectAnimValue> m_enterEffectAnimMap;
private:
    GameObject* m_gameObject;
public:
private:
    gd::vector<int> m_unkVecInt;
public:
};
