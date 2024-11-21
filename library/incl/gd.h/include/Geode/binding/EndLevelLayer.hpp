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

class EndLevelLayer : public GJDropDownLayer {
public:
    static constexpr auto CLASS_NAME = "EndLevelLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(EndLevelLayer, GJDropDownLayer)
    
private:
    [[deprecated("EndLevelLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static EndLevelLayer* create(PlayLayer* playLayer);
public:

    /**
     * @note[short] MacOS (ARM): 0x418b0c
     * @note[short] MacOS (Intel): 0x4afe70
     * @note[short] Windows: 0x133aa0
     * @note[short] iOS: 0x2f81f4
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x4192a4
     * @note[short] MacOS (Intel): 0x4b0620
     * @note[short] Windows: 0x135140
     * @note[short] iOS: 0x2f893c
     * @note[short] Android
     */
    virtual void keyDown(cocos2d::enumKeyCodes p0);

    /**
     * @note[short] MacOS (ARM): 0x415c30
     * @note[short] MacOS (Intel): 0x4acc80
     * @note[short] Windows: 0x131260
     * @note[short] iOS: 0x2f5654
     * @note[short] Android
     */
    virtual void customSetup();

    /**
     * @note[short] MacOS (ARM): 0x417d7c
     * @note[short] MacOS (Intel): 0x4af060
     * @note[short] Windows: 0x133070
     * @note[short] iOS: 0x2f74d8
     * @note[short] Android
     */
    virtual void showLayer(bool p0);

    /**
     * @note[short] MacOS (ARM): 0x418a60
     * @note[short] MacOS (Intel): 0x4afd90
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x2f8174
     * @note[short] Android: Out of line
     */
    virtual void enterAnimFinished();

    /**
     * @note[short] MacOS (ARM): 0x419320
     * @note[short] MacOS (Intel): 0x4b06b0
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x2f8980
     * @note[short] Android: Out of line
     */
    virtual void keyUp(cocos2d::enumKeyCodes p0);

    /**
     * @note[short] Windows: 0x134230
     * @note[short] Android
     */
    TodoReturn coinEnterFinished(cocos2d::CCPoint p0);

    /**
     * @note[short] Windows: 0x1341f0
     * @note[short] Android
     */
    TodoReturn coinEnterFinishedO(cocos2d::CCObject* p0);
    
private:
    [[deprecated("EndLevelLayer::currencyEnterFinished not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn currencyEnterFinished();
public:
    
private:
    [[deprecated("EndLevelLayer::diamondEnterFinished not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn diamondEnterFinished();
public:

    /**
     * @note[short] MacOS (ARM): 0x4174b8
     * @note[short] MacOS (Intel): 0x4ae840
     * @note[short] Windows: 0x132d30
     * @note[short] Android
     */
    TodoReturn getCoinString();

    /**
     * @note[short] MacOS (ARM): 0x6c7abc
     * @note[short] MacOS (Intel): 0x4aea80
     * @note[short] Windows: 0x135190
     * @note[short] Android
     */
    const char* getEndText();

    /**
     * @note[short] Windows: 0x1336e0
     * @note[short] Android
     */
    void goEdit();
    
private:
    [[deprecated("EndLevelLayer::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(PlayLayer* playLayer);
public:

    /**
     * @note[short] Windows: 0x1335e0
     * @note[short] Android
     */
    void onEdit(cocos2d::CCObject* sender);
    
private:
    [[deprecated("EndLevelLayer::onEveryplay not implemented")]]
    /**
     * @note[short] Android
     */
    void onEveryplay(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x417c94
     * @note[short] MacOS (Intel): 0x4aef70
     * @note[short] Windows: 0x1337b0
     * @note[short] Android
     */
    void onHideLayer(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x132c30
     * @note[short] Android
     */
    void onLevelLeaderboard(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x133460
     * @note[short] Android
     */
    void onMenu(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x133250
     * @note[short] Android
     */
    void onReplay(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x133890
     * @note[short] Android
     */
    void onRestartCheckpoint(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (Intel): 0x4af550
     * @note[short] Windows: 0x133fb0
     * @note[short] Android
     */
    void playCoinEffect(float p0);

    /**
     * @note[short] Windows: 0x134560
     * @note[short] Android
     */
    void playCurrencyEffect(float p0);

    /**
     * @note[short] Windows: 0x1349f0
     * @note[short] Android
     */
    void playDiamondEffect(float p0);

    /**
     * @note[short] Windows: 0x134e80
     * @note[short] Android
     */
    void playEndEffect();

    /**
     * @note[short] Windows: 0x133ab0
     * @note[short] Android
     */
    void playStarEffect(float p0);

    /**
     * @note[short] Windows: 0x133e50
     * @note[short] Android
     */
    TodoReturn starEnterFinished();
    
private:
    [[deprecated("EndLevelLayer::tryShowBanner not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn tryShowBanner(float p0);
public:
    PlayLayer* m_playLayer;
    bool m_notLocal;
    bool m_coinsVerified;
    bool m_unknown3;
    bool m_exiting;
    bool m_animateCoins;
    bool m_endEffectPlayed;
    cocos2d::CCMenu* m_sideMenu;
    cocos2d::CCArray* m_coinsToAnimate;
    cocos2d::CCPoint m_starsPosition;
    cocos2d::CCPoint m_orbsPosition;
    cocos2d::CCPoint m_diamondsPosition;
    int m_orbs;
    int m_stars;
    int m_moons;
    int m_diamonds;
    bool m_secretKey;
    bool m_hidden;
};
