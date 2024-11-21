#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "FLAlertLayer.hpp"

class SelectSettingLayer : public FLAlertLayer {
public:
    static constexpr auto CLASS_NAME = "SelectSettingLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SelectSettingLayer, FLAlertLayer)

    /**
     * @note[short] MacOS (Intel): 0x25c9f0
     * @note[short] Windows: 0x30e580
     * @note[short] Android
     */
    static SelectSettingLayer* create(SelectSettingType p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0x20b08c
     * @note[short] MacOS (Intel): 0x25efd0
     * @note[short] Windows: 0x30ede0
     * @note[short] Android
     */
    static gd::string frameForItem(SelectSettingType p0, int p1);

    /**
     * @note[short] MacOS (Intel): 0x25c690
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static gd::string frameForValue(SelectSettingType type, int value);

    /**
     * @note[short] MacOS (Intel): 0x25f2b0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static int idxToValue(SelectSettingType type, int idx);

    /**
     * @note[short] MacOS (Intel): 0x25efa0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static int valueToIdx(SelectSettingType type, int value);

    /**
     * @note[short] MacOS (ARM): 0x20b430
     * @note[short] MacOS (Intel): 0x25f2e0
     * @note[short] Windows: 0x30f380
     * @note[short] iOS: 0x180cbc
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (Intel): 0x25ccd0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    gd::string getSelectedFrame();

    /**
     * @note[short] MacOS (Intel): 0x25cca0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    int getSelectedValue();

    /**
     * @note[short] MacOS (ARM): 0x20aaac
     * @note[short] MacOS (Intel): 0x4870a0
     * @note[short] Windows: 0x30e690
     * @note[short] Android
     */
    bool init(SelectSettingType p0, int p1);
    
private:
    [[deprecated("SelectSettingLayer::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x20b2cc
     * @note[short] MacOS (Intel): 0x25f1b0
     * @note[short] Windows: 0x30f280
     * @note[short] Android
     */
    void onSelect(cocos2d::CCObject* sender);
    cocos2d::CCArray* m_settingSprites;
    int m_settingID;
    SelectSettingType m_type;
    SelectSettingDelegate* m_delegate;
};
