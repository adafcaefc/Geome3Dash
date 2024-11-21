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

class GJLevelScoreCell : public TableViewCell {
public:
    static constexpr auto CLASS_NAME = "GJLevelScoreCell";
    GEODE_CUSTOM_CONSTRUCTOR_GD(GJLevelScoreCell, TableViewCell)
    
private:
    [[deprecated("GJLevelScoreCell::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f2e24
     * @note[short] MacOS (Intel): 0x243de0
     * @note[short] iOS: 0x11405c
     * @note[short] Android
     */
    virtual bool init();
public:
    
private:
    [[deprecated("GJLevelScoreCell::draw not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f2e6c
     * @note[short] MacOS (Intel): 0x243e30
     * @note[short] iOS: 0x1140a4
     * @note[short] Android
     */
    virtual void draw();
public:

    /**
     * @note[short] MacOS (ARM): 0x1e8cec
     * @note[short] MacOS (Intel): 0x238d60
     * @note[short] Windows: 0xb93d0
     * @note[short] Android
     */
    void loadFromScore(GJUserScore* p0);
    
private:
    [[deprecated("GJLevelScoreCell::onViewProfile not implemented")]]
    /**
     * @note[short] Android
     */
    void onViewProfile(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJLevelScoreCell::updateBGColor not implemented")]]
    /**
     * @note[short] Android
     */
    void updateBGColor(int p0);
public:
};
