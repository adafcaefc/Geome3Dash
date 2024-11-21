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

class LevelListCell : public TableViewCell {
public:
    static constexpr auto CLASS_NAME = "LevelListCell";
    GEODE_CUSTOM_CONSTRUCTOR_GD(LevelListCell, TableViewCell)
    
private:
    [[deprecated("LevelListCell::create not implemented")]]
    /**
     * @note[short] Android
     */
    static LevelListCell* create(float p0, float p1);
public:
    
private:
    [[deprecated("LevelListCell::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f5bc0
     * @note[short] MacOS (Intel): 0x247460
     * @note[short] iOS: 0x115ae0
     * @note[short] Android
     */
    virtual bool init();
public:
    
private:
    [[deprecated("LevelListCell::draw not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f5cd8
     * @note[short] MacOS (Intel): 0x2475a0
     * @note[short] iOS: 0x115bf8
     * @note[short] Android
     */
    virtual void draw();
public:

    /**
     * @note[short] MacOS (ARM): 0x1e3af4
     * @note[short] MacOS (Intel): 0x233ae0
     * @note[short] Windows: 0xbdf90
     * @note[short] Android
     */
    void loadFromList(GJLevelList* p0);

    /**
     * @note[short] MacOS (ARM): 0x1f5bc8
     * @note[short] MacOS (Intel): 0x247470
     * @note[short] Windows: 0xbf3c0
     * @note[short] Android
     */
    void onClick(cocos2d::CCObject* sender);
    
private:
    [[deprecated("LevelListCell::onListInfo not implemented")]]
    /**
     * @note[short] Android
     */
    void onListInfo(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("LevelListCell::onViewProfile not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f5c90
     * @note[short] MacOS (Intel): 0x247550
     * @note[short] Android
     */
    void onViewProfile(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("LevelListCell::updateBGColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateBGColor(int p0);
public:
    GJLevelList* m_levelList;
    bool m_addingLevel;
};
