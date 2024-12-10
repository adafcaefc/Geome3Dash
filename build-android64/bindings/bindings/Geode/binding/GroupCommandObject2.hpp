#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "KeyframeObject.hpp"

class GroupCommandObject2 {
public:
    static constexpr auto CLASS_NAME = "GroupCommandObject2";

    /**
     * @note[short] Android
     */
    TodoReturn reset();

    /**
     * @note[short] Android
     */
    TodoReturn resetDelta(bool p0);

    /**
     * @note[short] Android
     */
    TodoReturn runFollowCommand(double p0, double p1, double p2);

    /**
     * @note[short] Android
     */
    TodoReturn runMoveCommand(cocos2d::CCPoint p0, double p1, int p2, double p3, bool p4, bool p5, bool p6, bool p7, double p8, double p9);

    /**
     * @note[short] Android
     */
    TodoReturn runPlayerFollowCommand(double p0, double p1, int p2, double p3, double p4);

    /**
     * @note[short] Android
     */
    TodoReturn runRotateCommand(double p0, double p1, int p2, double p3, bool p4, int p5);

    /**
     * @note[short] Android
     */
    TodoReturn runTransformCommand(double p0, int p1, double p2);

    /**
     * @note[short] Android
     */
    TodoReturn step(float p0);

    /**
     * @note[short] Android
     */
    TodoReturn stepTransformCommand(float p0, bool p1, bool p2);

    /**
     * @note[short] Android
     */
    TodoReturn updateAction(int p0, float p1);

    /**
     * @note[short] Android
     */
    TodoReturn updateEffectAction(float p0, int p1);
private:
    gd::vector<KeyframeObject> m_unkVecKeyframeObject;
public:
private:
    GameObject* m_gameObject;
public:
private:
    gd::vector<int> m_unkVecInt;
public:
};
