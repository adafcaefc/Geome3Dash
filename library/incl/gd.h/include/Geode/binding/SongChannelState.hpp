#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class SongChannelState {
public:
    static constexpr auto CLASS_NAME = "SongChannelState";
    SongTriggerGameObject* m_songTriggerGameObject1;
    GEODE_PAD(8);
    SongTriggerGameObject* m_songTriggerGameObject2;
    GEODE_PAD(8);
};
