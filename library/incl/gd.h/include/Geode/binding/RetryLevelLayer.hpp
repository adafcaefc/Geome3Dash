#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "GJDropDownLayer.hpp"
#include "RewardedVideoDelegate.hpp"

class RetryLevelLayer : public GJDropDownLayer, public RewardedVideoDelegate {
public:
    static constexpr auto CLASS_NAME = "RetryLevelLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(RetryLevelLayer, GJDropDownLayer)

    /**
     * @note[short] Windows: 0x3959c0
     * @note[short] Android
     */
    static RetryLevelLayer* create();

    /**
     * @note[short] MacOS (ARM): 0x4485ec
     * @note[short] MacOS (Intel): 0x4e64b0
     * @note[short] Windows: 0x3b4c40
     * @note[short] iOS: 0x1b5c44
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x448540
     * @note[short] MacOS (Intel): 0x4e63e0
     * @note[short] Windows: 0x3b4ad0
     * @note[short] iOS: 0x1b5bf8
     * @note[short] Android
     */
    virtual void keyDown(cocos2d::enumKeyCodes p0);

    /**
     * @note[short] MacOS (ARM): 0x4474c4
     * @note[short] MacOS (Intel): 0x4e5300
     * @note[short] Windows: 0x3b3d00
     * @note[short] iOS: 0x1b4fb4
     * @note[short] Android
     */
    virtual void customSetup();
    
private:
    [[deprecated("RetryLevelLayer::showLayer not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x44805c
     * @note[short] MacOS (Intel): 0x4e5ec0
     * @note[short] iOS: 0x1b5aa8
     * @note[short] Android
     */
    virtual void showLayer(bool p0);
public:
    
private:
    [[deprecated("RetryLevelLayer::enterAnimFinished not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x44816c
     * @note[short] MacOS (Intel): 0x4e5fc0
     * @note[short] iOS: 0x1b5bb0
     * @note[short] Android
     */
    virtual void enterAnimFinished();
public:

    /**
     * @note[short] MacOS (ARM): 0x448530
     * @note[short] MacOS (Intel): 0x4e63c0
     * @note[short] Windows: 0x3b4a00
     * @note[short] iOS: 0x1b5be8
     * @note[short] Android
     */
    virtual void rewardedVideoFinished();
    
private:
    [[deprecated("RetryLevelLayer::shouldOffsetRewardCurrency not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fcc
     * @note[short] MacOS (Intel): 0x7190
     * @note[short] iOS: 0x10258
     * @note[short] Android
     */
    virtual bool shouldOffsetRewardCurrency();
public:

    /**
     * @note[short] MacOS (ARM): 0x4485e4
     * @note[short] MacOS (Intel): 0x4e6490
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x1b5c3c
     * @note[short] Android: Out of line
     */
    virtual void keyUp(cocos2d::enumKeyCodes p0);
    
private:
    [[deprecated("RetryLevelLayer::getEndText not implemented")]]
    /**
     * @note[short] Android
     */
    const char* getEndText();
public:
    
private:
    [[deprecated("RetryLevelLayer::onEveryplay not implemented")]]
    /**
     * @note[short] Android
     */
    void onEveryplay(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] Windows: 0x3b4b20
     * @note[short] Android
     */
    void onMenu(cocos2d::CCObject* sender);
    
private:
    [[deprecated("RetryLevelLayer::onReplay not implemented")]]
    /**
     * @note[short] Android
     */
    void onReplay(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("RetryLevelLayer::onRewardedVideo not implemented")]]
    /**
     * @note[short] Android
     */
    void onRewardedVideo(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] Windows: 0x3b4460
     * @note[short] Android
     */
    TodoReturn setupLastProgress();
    cocos2d::CCMenu* m_mainMenu;
    bool m_unk1e8;
    bool m_unk1e9;
};
