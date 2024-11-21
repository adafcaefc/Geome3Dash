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

class SongCell : public TableViewCell {
public:
    static constexpr auto CLASS_NAME = "SongCell";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SongCell, TableViewCell)
    
private:
    [[deprecated("SongCell::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f13c8
     * @note[short] MacOS (Intel): 0x241b80
     * @note[short] iOS: 0x112de8
     * @note[short] Android
     */
    virtual bool init();
public:
    
private:
    [[deprecated("SongCell::draw not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f13f8
     * @note[short] MacOS (Intel): 0x241bc0
     * @note[short] iOS: 0x112e18
     * @note[short] Android
     */
    virtual void draw();
public:

    /**
     * @note[short] MacOS (Intel): 0x235330
     * @note[short] Windows: 0xb3990
     * @note[short] Android
     */
    void loadFromObject(SongObject* p0);
    
private:
    [[deprecated("SongCell::onClick not implemented")]]
    /**
     * @note[short] Android
     */
    void onClick(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SongCell::updateBGColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateBGColor(int p0);
public:
};
