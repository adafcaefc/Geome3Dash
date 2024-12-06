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
    
private:
    [[deprecated("CustomSongDelegate::songIDChanged not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void songIDChanged(int p0);
public:
    
private:
    [[deprecated("CustomSongDelegate::getActiveSongID not implemented")]]
    /**
     * @note[short] Android
     */
    virtual int getActiveSongID();
public:
    
private:
    [[deprecated("CustomSongDelegate::getSongFileName not implemented")]]
    /**
     * @note[short] Android
     */
    virtual gd::string getSongFileName();
public:
    
private:
    [[deprecated("CustomSongDelegate::getLevelSettings not implemented")]]
    /**
     * @note[short] Android
     */
    virtual LevelSettingsObject* getLevelSettings();
public:
};
