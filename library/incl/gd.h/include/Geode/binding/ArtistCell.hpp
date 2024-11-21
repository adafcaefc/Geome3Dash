#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "TableViewCell.hpp"

class ArtistCell : public TableViewCell {
public:
    static constexpr auto CLASS_NAME = "ArtistCell";
    GEODE_CUSTOM_CONSTRUCTOR_GD(ArtistCell, TableViewCell)
    
private:
    [[deprecated("ArtistCell::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f1b40
     * @note[short] MacOS (Intel): 0x242700
     * @note[short] iOS: 0x113428
     * @note[short] Android
     */
    virtual bool init();
public:
    
private:
    [[deprecated("ArtistCell::draw not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f1d04
     * @note[short] MacOS (Intel): 0x2428c0
     * @note[short] iOS: 0x1135cc
     * @note[short] Android
     */
    virtual void draw();
public:

    /**
     * @note[short] MacOS (Intel): 0x235770
     * @note[short] Windows: 0xb4e90
     * @note[short] Android
     */
    void loadFromObject(SongInfoObject* p0);
    
private:
    [[deprecated("ArtistCell::onNewgrounds not implemented")]]
    /**
     * @note[short] Android
     */
    void onNewgrounds(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("ArtistCell::onYouTube not implemented")]]
    /**
     * @note[short] Android
     */
    void onYouTube(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("ArtistCell::updateBGColor not implemented")]]
    /**
     * @note[short] Android
     */
    void updateBGColor(int p0);
public:
    SongInfoObject* m_songInfo;
};
