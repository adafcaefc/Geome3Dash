#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class CustomSongDelegate {
public:
    static constexpr auto CLASS_NAME = "CustomSongDelegate";

    /**
     * @note[short] Android
     */
    virtual void songIDChanged(int p0);

    /**
     * @note[short] Android
     */
    virtual int getActiveSongID();

    /**
     * @note[short] Android
     */
    virtual gd::string getSongFileName();

    /**
     * @note[short] Android
     */
    virtual LevelSettingsObject* getLevelSettings();
};
