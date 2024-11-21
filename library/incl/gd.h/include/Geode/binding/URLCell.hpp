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

class URLCell : public TableViewCell {
public:
    static constexpr auto CLASS_NAME = "URLCell";
    GEODE_CUSTOM_CONSTRUCTOR_GD(URLCell, TableViewCell)
    
private:
    [[deprecated("URLCell::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f5dc8
     * @note[short] MacOS (Intel): 0x2476e0
     * @note[short] iOS: 0x115ca4
     * @note[short] Android
     */
    virtual bool init();
public:
    
private:
    [[deprecated("URLCell::draw not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f5e38
     * @note[short] MacOS (Intel): 0x247750
     * @note[short] iOS: 0x115d00
     * @note[short] Android
     */
    virtual void draw();
public:

    /**
     * @note[short] MacOS (Intel): 0x235b20
     * @note[short] Windows: 0xbf530
     * @note[short] Android
     */
    void loadFromObject(CCURLObject* p0);
    
private:
    [[deprecated("URLCell::onURL not implemented")]]
    /**
     * @note[short] Android
     */
    void onURL(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("URLCell::updateBGColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateBGColor(int p0);
public:
};
