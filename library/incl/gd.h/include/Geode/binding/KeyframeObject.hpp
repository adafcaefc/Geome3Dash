#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class KeyframeObject {
public:
    static constexpr auto CLASS_NAME = "KeyframeObject";
    
private:
    [[deprecated("KeyframeObject::setupSpline not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn setupSpline(gd::vector<KeyframeObject*>& p0);
public:
    GEODE_PAD(32);
    gd::vector<double> m_unkVecDouble1;
    gd::vector<double> m_unkVecDouble2;
    gd::vector<double> m_unkVecDouble3;
    gd::vector<double> m_unkVecDouble4;
    gd::vector<double> m_unkVecDouble5;
    GEODE_PAD(41);
    gd::vector<double> m_unkVecDouble6;
    gd::vector<double> m_unkVecDouble7;
    gd::vector<double> m_unkVecDouble8;
    gd::vector<double> m_unkVecDouble9;
    gd::vector<double> m_unkVecDouble10;
    GEODE_PAD(128);
};
