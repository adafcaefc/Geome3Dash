#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include <fmod.hpp>

class FMODAudioState {
public:
    static constexpr auto CLASS_NAME = "FMODAudioState";
    float m_unkFloat1;
    float m_unkFloat2;
    gd::map<std::pair<int,int>,FMODSoundTween> m_unkMapPairIntIntFMODSoundTween1;
    gd::map<std::pair<int,int>,FMODSoundTween> m_unkMapPairIntIntFMODSoundTween2;
    gd::map<std::pair<int,int>,FMODSoundTween> m_unkMapPairIntIntFMODSoundTween3;
    gd::unordered_map<int,float> m_unkMapIntFloat1;
    gd::unordered_map<int,float> m_unkMapIntFloat2;
    gd::unordered_map<int,float> m_unkMapIntFloat3;
    gd::unordered_map<int,float> m_unkMapIntFloat4;
    gd::unordered_map<int,float> m_unkMapIntFloat5;
    gd::unordered_map<int,float> m_unkMapIntFloat6;
    gd::unordered_map<int,float> m_unkMapIntFloat7;
    gd::unordered_map<int,float> m_unkMapIntFloat8;
    gd::unordered_map<int,float> m_unkMapIntFloat9;
    gd::unordered_map<int,float> m_unkMapIntFloat10;
    gd::unordered_map<int,FMODQueuedMusic> m_unkMapIntFMODQueuedMusic1;
    gd::unordered_map<int,FMODQueuedMusic> m_unkMapIntFMODQueuedMusic2;
    gd::unordered_map<int,FMODSoundState> m_unkMapIntFMODSoundState;
    int64_t m_unkInt1;
};
