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
    
private:
    [[deprecated("GroupCommandObject2::reset not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn reset();
public:
    
private:
    [[deprecated("GroupCommandObject2::resetDelta not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetDelta(bool p0);
public:
    
private:
    [[deprecated("GroupCommandObject2::runFollowCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn runFollowCommand(double p0, double p1, double p2);
public:
    
private:
    [[deprecated("GroupCommandObject2::runMoveCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn runMoveCommand(cocos2d::CCPoint p0, double p1, int p2, double p3, bool p4, bool p5, bool p6, bool p7, double p8, double p9);
public:
    
private:
    [[deprecated("GroupCommandObject2::runPlayerFollowCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn runPlayerFollowCommand(double p0, double p1, int p2, double p3, double p4);
public:
    
private:
    [[deprecated("GroupCommandObject2::runRotateCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn runRotateCommand(double p0, double p1, int p2, double p3, bool p4, int p5);
public:
    
private:
    [[deprecated("GroupCommandObject2::runTransformCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn runTransformCommand(double p0, int p1, double p2);
public:
    
private:
    [[deprecated("GroupCommandObject2::step not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn step(float p0);
public:
    
private:
    [[deprecated("GroupCommandObject2::stepTransformCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn stepTransformCommand(float p0, bool p1, bool p2);
public:
    
private:
    [[deprecated("GroupCommandObject2::updateAction not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateAction(int p0, float p1);
public:
    
private:
    [[deprecated("GroupCommandObject2::updateEffectAction not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateEffectAction(float p0, int p1);
public:
    GEODE_PAD(440);
    gd::vector<KeyframeObject> m_unkVecKeyframeObject;
    GEODE_PAD(8);
    GameObject* m_gameObject;
    GEODE_PAD(8);
    gd::vector<int> m_unkVecInt;
    GEODE_PAD(8);
};
