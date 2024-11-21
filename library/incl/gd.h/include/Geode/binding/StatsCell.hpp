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

class StatsCell : public TableViewCell {
public:
    static constexpr auto CLASS_NAME = "StatsCell";
    GEODE_CUSTOM_CONSTRUCTOR_GD(StatsCell, TableViewCell)
    
private:
    [[deprecated("StatsCell::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f05d8
     * @note[short] MacOS (Intel): 0x240e40
     * @note[short] iOS: 0x112528
     * @note[short] Android
     */
    virtual bool init();
public:

    /**
     * @note[short] MacOS (ARM): 0x1f1224
     * @note[short] MacOS (Intel): 0x241930
     * @note[short] Windows: 0xad710
     * @note[short] iOS: 0x112c98
     * @note[short] Android
     */
    virtual void draw();
    
private:
    [[deprecated("StatsCell::getTitleFromKey not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f05e0
     * @note[short] MacOS (Intel): 0x240e50
     * @note[short] Android
     */
    TodoReturn getTitleFromKey(char const* p0);
public:

    /**
     * @note[short] MacOS (Intel): 0x235030
     * @note[short] Windows: 0xb2630
     * @note[short] Android
     */
    void loadFromObject(StatsObject* p0);
    
private:
    [[deprecated("StatsCell::updateBGColor not implemented")]]
    /**
     * @note[short] Android
     */
    void updateBGColor(int p0);
public:
};
