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
#include "NumberInputDelegate.hpp"

class ShareLevelSettingsLayer : public FLAlertLayer, public NumberInputDelegate {
public:
    static constexpr auto CLASS_NAME = "ShareLevelSettingsLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(ShareLevelSettingsLayer, FLAlertLayer)

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     ShareLevelSettingsLayer();

    /**
     * @note[short] MacOS (ARM): 0x21ac5c
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static ShareLevelSettingsLayer* create(GJGameLevel* level);

    /**
     * @note[short] MacOS (ARM): 0x21c6d0
     * @note[short] MacOS (Intel): 0x271520
     * @note[short] Windows: 0x4799c0
     * @note[short] iOS: 0x276b68
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x21b9b8
     * @note[short] MacOS (Intel): 0x270760
     * @note[short] Windows: 0x478c00
     * @note[short] Android
     */
    bool init(GJGameLevel* p0);

    /**
     * @note[short] Windows: 0x479940
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x21c440
     * @note[short] MacOS (Intel): 0x271250
     * @note[short] Windows: 0x479620
     * @note[short] Android
     */
    void onUnlisted(cocos2d::CCObject* sender);
    
private:
    [[deprecated("ShareLevelSettingsLayer::onUnlistedFriendsOnly not implemented")]]
    /**
     * @note[short] Android
     */
    void onUnlistedFriendsOnly(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("ShareLevelSettingsLayer::updateSettingsState not implemented")]]
    /**
     * @note[short] Android
     */
    void updateSettingsState();
public:
    cocos2d::CCLabelBMFont* m_passwordLabel;
    GJGameLevel* m_level;
    CCMenuItemToggler* m_friendsOnlyToggler;
    cocos2d::CCLabelBMFont* m_friendsOnlyLabel;
};
