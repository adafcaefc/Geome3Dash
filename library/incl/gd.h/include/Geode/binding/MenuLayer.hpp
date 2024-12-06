#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "FLAlertLayerProtocol.hpp"
#include "GooglePlayDelegate.hpp"

class MenuLayer : public cocos2d::CCLayer, public FLAlertLayerProtocol, public GooglePlayDelegate {
public:
    static constexpr auto CLASS_NAME = "MenuLayer";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(MenuLayer, cocos2d::CCLayer)

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    static MenuLayer* get();

    /**
     * @note[short] MacOS (ARM): 0x30d470
     * @note[short] MacOS (Intel): 0x37ccf0
     * @note[short] Windows: 0x31ea40
     * @note[short] Android
     */
    static cocos2d::CCScene* scene(bool isVideoOptionsOpen);

    /**
     * @note[short] MacOS (ARM): 0x30d620
     * @note[short] MacOS (Intel): 0x37ceb0
     * @note[short] Windows: 0x31ebd0
     * @note[short] iOS: 0x265660
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (ARM): 0x30f4b0
     * @note[short] MacOS (Intel): 0x37edc0
     * @note[short] Windows: 0x3210c0
     * @note[short] iOS: 0x267184
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x30f738
     * @note[short] MacOS (Intel): 0x37f0a0
     * @note[short] Windows: 0x3214a0
     * @note[short] iOS: 0x26740c
     * @note[short] Android
     */
    virtual void keyDown(cocos2d::enumKeyCodes p0);

    /**
     * @note[short] MacOS (ARM): 0x30f264
     * @note[short] MacOS (Intel): 0x37eb30
     * @note[short] Windows: 0x320ac0
     * @note[short] iOS: 0x266fe8
     * @note[short] Android
     */
    virtual void googlePlaySignedIn();

    /**
     * @note[short] MacOS (ARM): 0x30f4bc
     * @note[short] MacOS (Intel): 0x37edf0
     * @note[short] Windows: 0x321290
     * @note[short] iOS: 0x267244
     * @note[short] Android
     */
    virtual void FLAlert_Clicked(FLAlertLayer* p0, bool p1);

    /**
     * @note[short] MacOS (ARM): 0x30f72c
     * @note[short] MacOS (Intel): 0x37f070
     * @note[short] Windows: 0x321510
     * @note[short] Android
     */
    void endGame();

    /**
     * @note[short] Windows: 0x320430
     * @note[short] Android
     */
    void firstNetworkTest();

    /**
     * @note[short] MacOS (ARM): 0x30eaa8
     * @note[short] MacOS (Intel): 0x37e370
     * @note[short] Windows: 0x320960
     * @note[short] Android
     */
    void onAchievements(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x30ea2c
     * @note[short] MacOS (Intel): 0x37e2e0
     * @note[short] Windows: 0x320e70
     * @note[short] Android
     */
    void onCreator(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x30f028
     * @note[short] MacOS (Intel): 0x37e8b0
     * @note[short] Windows: 0x3201e0
     * @note[short] Android
     */
    void onDaily(cocos2d::CCObject* sender);
    
private:
    [[deprecated("MenuLayer::onDiscord not implemented")]]
    /**
     * @note[short] Android
     */
    void onDiscord(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void onEveryplay(cocos2d::CCObject* sender);
    
private:
    [[deprecated("MenuLayer::onFacebook not implemented")]]
    /**
     * @note[short] Android
     */
    void onFacebook(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("MenuLayer::onFreeLevels not implemented")]]
    /**
     * @note[short] Android
     */
    void onFreeLevels(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("MenuLayer::onFullVersion not implemented")]]
    /**
     * @note[short] Android
     */
    void onFullVersion(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("MenuLayer::onGameCenter not implemented")]]
    /**
     * @note[short] Android
     */
    void onGameCenter(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x30e9b0
     * @note[short] MacOS (Intel): 0x37e250
     * @note[short] Windows: 0x320f00
     * @note[short] Android
     */
    void onGarage(cocos2d::CCObject* sender);
    
private:
    [[deprecated("MenuLayer::onGooglePlayGames not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x30f23c
     * @note[short] Android
     */
    void onGooglePlayGames(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x30ed3c
     * @note[short] MacOS (Intel): 0x37e5c0
     * @note[short] Windows: 0x320880
     * @note[short] Android
     */
    void onMoreGames(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x30ee98
     * @note[short] MacOS (Intel): 0x37e710
     * @note[short] Windows: 0x320720
     * @note[short] Android
     */
    void onMyProfile(cocos2d::CCObject* sender);
    
private:
    [[deprecated("MenuLayer::onNewgrounds not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x30eb8c
     * @note[short] MacOS (Intel): 0x37e430
     * @note[short] Android
     */
    void onNewgrounds(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x30eaf4
     * @note[short] MacOS (Intel): 0x37e3b0
     * @note[short] Windows: 0x320bb0
     * @note[short] Android
     */
    void onOptions(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x30d5b8
     * @note[short] Windows: 0x320bc0
     * @note[short] Android
     */
    void onOptionsInstant();

    /**
     * @note[short] MacOS (ARM): 0x30e930
     * @note[short] MacOS (Intel): 0x37e1c0
     * @note[short] Windows: 0x320b10
     * @note[short] Android
     */
    void onPlay(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x30edc0
     * @note[short] MacOS (Intel): 0x37e640
     * @note[short] Windows: 0x3210d0
     * @note[short] Android
     */
    void onQuit(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x3207c0
     * @note[short] Android
     */
    void onRobTop(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x30eb40
     * @note[short] MacOS (Intel): 0x37e3f0
     * @note[short] Windows: 0x320d50
     * @note[short] Android
     */
    void onStats(cocos2d::CCObject* sender);
    
private:
    [[deprecated("MenuLayer::onTrailer not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x30f470
     * @note[short] MacOS (Intel): 0x37ed80
     * @note[short] Android
     */
    void onTrailer(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("MenuLayer::onTwitch not implemented")]]
    /**
     * @note[short] Android
     */
    void onTwitch(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("MenuLayer::onTwitter not implemented")]]
    /**
     * @note[short] Android
     */
    void onTwitter(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("MenuLayer::onYouTube not implemented")]]
    /**
     * @note[short] Android
     */
    void onYouTube(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x30f360
     * @note[short] Windows: 0x320bd0
     * @note[short] Android
     */
    void openOptions(bool videoOptions);
    
private:
    [[deprecated("MenuLayer::showGCQuestion not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x30f144
     * @note[short] MacOS (Intel): 0x37e9f0
     * @note[short] Android
     */
    void showGCQuestion();
public:

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void showMeltdownPromo();

    /**
     * @note[short] MacOS (ARM): 0x30f044
     * @note[short] Windows: 0x320600
     * @note[short] Android
     */
    void showTOS();
    
private:
    [[deprecated("MenuLayer::syncPlatformAchievements not implemented")]]
    /**
     * @note[short] Android
     */
    void syncPlatformAchievements(float p0);
public:
    
private:
    [[deprecated("MenuLayer::tryShowAd not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x30f0a4
     * @note[short] Android
     */
    void tryShowAd(float p0);
public:

    /**
     * @note[short] Windows: 0x320330
     * @note[short] Android
     */
    void updateUserProfileButton();

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void videoOptionsClosed();

    /**
     * @note[short] MacOS (Intel): 0x37ecd0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void videoOptionsOpened();

    /**
     * @note[short] MacOS (ARM): 0x30d274
     * @note[short] Windows: 0x3211f0
     * @note[short] Android
     */
    void willClose();
    bool m_showingTOS;
    cocos2d::CCSprite* m_gpSprite;
    cocos2d::CCSprite* m_viewProfileSprite;
    cocos2d::CCLabelBMFont* m_profileLabel;
    CCMenuItemSpriteExtra* m_profileButton;
    void* m_unknown;
    MenuGameLayer* m_menuGameLayer;
};
