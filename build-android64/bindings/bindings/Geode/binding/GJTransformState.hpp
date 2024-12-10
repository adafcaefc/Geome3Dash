#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJTransformState {
public:
    static constexpr auto CLASS_NAME = "GJTransformState";
    float m_scaleX;
    float m_scaleY;
    float m_angleX;
    float m_angleY;
    float m_skewX;
    float m_skewY;
    float m_unk1;
    float m_unk2;
    float m_unk3;
    float m_unk4;
    cocos2d::CCPoint m_unk5;
    cocos2d::CCPoint m_unk6;
    cocos2d::CCPoint m_unk7;
    float m_unk8;
    float m_unk9;
};
