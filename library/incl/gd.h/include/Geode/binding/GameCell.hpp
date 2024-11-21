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

class GameCell : public TableViewCell {
public:
    static constexpr auto CLASS_NAME = "GameCell";
    GEODE_CUSTOM_CONSTRUCTOR_GD(GameCell, TableViewCell)
    
private:
    [[deprecated("GameCell::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x291d60
     * @note[short] MacOS (Intel): 0x2f9520
     * @note[short] iOS: 0x1d1424
     * @note[short] Android
     */
    virtual bool init();
public:

    /**
     * @note[short] MacOS (ARM): 0x291e34
     * @note[short] MacOS (Intel): 0x2f95e0
     * @note[short] Windows: 0x3cbf0
     * @note[short] iOS: 0x1d1468
     * @note[short] Android
     */
    virtual void draw();
    
private:
    [[deprecated("GameCell::loadFromString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x291900
     * @note[short] MacOS (Intel): 0x2f9000
     * @note[short] Android
     */
    void loadFromString(gd::string p0);
public:
    
private:
    [[deprecated("GameCell::onTouch not implemented")]]
    /**
     * @note[short] Android
     */
    void onTouch(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GameCell::updateBGColor not implemented")]]
    /**
     * @note[short] Android
     */
    void updateBGColor(int p0);
public:
};
