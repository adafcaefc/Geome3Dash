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
#include "FLAlertLayerProtocol.hpp"

class GJScoreCell : public TableViewCell, public FLAlertLayerProtocol {
public:
    static constexpr auto CLASS_NAME = "GJScoreCell";
    GEODE_CUSTOM_CONSTRUCTOR_GD(GJScoreCell, TableViewCell)

    /**
     * @note[short] MacOS (ARM): 0x1f2910
     * @note[short] MacOS (Intel): 0x243750
     * @note[short] Windows: 0xb3f00
     * @note[short] iOS: 0x113ce4
     * @note[short] Android
     */
    virtual bool init();
    
private:
    [[deprecated("GJScoreCell::draw not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f2bc0
     * @note[short] MacOS (Intel): 0x243a20
     * @note[short] iOS: 0x113e88
     * @note[short] Android
     */
    virtual void draw();
public:

    /**
     * @note[short] MacOS (ARM): 0x1f2af8
     * @note[short] MacOS (Intel): 0x243960
     * @note[short] Windows: 0xb8ee0
     * @note[short] iOS: 0x113e30
     * @note[short] Android
     */
    virtual void FLAlert_Clicked(FLAlertLayer* p0, bool p1);

    /**
     * @note[short] MacOS (ARM): 0x1e7b58
     * @note[short] MacOS (Intel): 0x237bc0
     * @note[short] Windows: 0xb7c80
     * @note[short] Android
     */
    void loadFromScore(GJUserScore* p0);
    
private:
    [[deprecated("GJScoreCell::onBan not implemented")]]
    /**
     * @note[short] Android
     */
    void onBan(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJScoreCell::onCheck not implemented")]]
    /**
     * @note[short] Android
     */
    void onCheck(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJScoreCell::onMoreLevels not implemented")]]
    /**
     * @note[short] Android
     */
    void onMoreLevels(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x1f291c
     * @note[short] MacOS (Intel): 0x243770
     * @note[short] Windows: 0xb8d60
     * @note[short] Android
     */
    void onViewProfile(cocos2d::CCObject* sender);
    
private:
    [[deprecated("GJScoreCell::updateBGColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateBGColor(int p0);
public:
    GJUserScore* m_score;
};
