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

class AchievementCell : public TableViewCell {
public:
    static constexpr auto CLASS_NAME = "AchievementCell";
    GEODE_CUSTOM_CONSTRUCTOR_GD(AchievementCell, TableViewCell)
    
private:
    [[deprecated("AchievementCell::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1ec614
     * @note[short] MacOS (Intel): 0x23c930
     * @note[short] iOS: 0x10ebb4
     * @note[short] Android
     */
    virtual bool init();
public:
    
private:
    [[deprecated("AchievementCell::draw not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1ec61c
     * @note[short] MacOS (Intel): 0x23c940
     * @note[short] iOS: 0x10ebbc
     * @note[short] Android
     */
    virtual void draw();
public:

    /**
     * @note[short] MacOS (Intel): 0x230eb0
     * @note[short] Windows: 0xac150
     * @note[short] Android
     */
    void loadFromDict(cocos2d::CCDictionary* p0);
    
private:
    [[deprecated("AchievementCell::updateBGColor not implemented")]]
    /**
     * @note[short] Android
     */
    void updateBGColor(int p0);
public:
};
