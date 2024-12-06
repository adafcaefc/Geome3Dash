#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "DialogDelegate.hpp"

class CreatorLayer : public cocos2d::CCLayer, public cocos2d::CCSceneTransitionDelegate, public DialogDelegate {
public:
    static constexpr auto CLASS_NAME = "CreatorLayer";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(CreatorLayer, cocos2d::CCLayer)

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     CreatorLayer();

    /**
     * @note[short] MacOS (ARM): 0x22ec24
     * @note[short] MacOS (Intel): 0x285610
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static CreatorLayer* create();

    /**
     * @note[short] MacOS (ARM): 0x22eb40
     * @note[short] MacOS (Intel): 0x2854f0
     * @note[short] Windows: 0x9b9a0
     * @note[short] Android
     */
    static cocos2d::CCScene* scene();

    /**
     * @note[short] MacOS (ARM): 0x22ece0
     * @note[short] MacOS (Intel): 0x2856f0
     * @note[short] Windows: 0x9bb10
     * @note[short] iOS: 0xb81ec
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (ARM): 0x230ea4
     * @note[short] MacOS (Intel): 0x287a70
     * @note[short] Windows: 0x9f2b0
     * @note[short] iOS: 0xb9d0c
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x230e34
     * @note[short] MacOS (Intel): 0x2879f0
     * @note[short] Windows: 0x9f1f0
     * @note[short] iOS: 0xb9ccc
     * @note[short] Android
     */
    virtual void sceneWillResume();

    /**
     * @note[short] MacOS (ARM): 0x230d34
     * @note[short] MacOS (Intel): 0x2878f0
     * @note[short] Windows: 0x9f0d0
     * @note[short] iOS: 0xb9c3c
     * @note[short] Android
     */
    virtual void dialogClosed(DialogLayer* p0);
    
private:
    [[deprecated("CreatorLayer::canPlayOnlineLevels not implemented")]]
    /**
     * @note[short] Android
     */
    bool canPlayOnlineLevels();
public:
    
private:
    [[deprecated("CreatorLayer::checkQuestsStatus not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x23039c
     * @note[short] MacOS (Intel): 0x286f00
     * @note[short] Android
     */
    void checkQuestsStatus();
public:

    /**
     * @note[short] MacOS (ARM): 0x22fdf4
     * @note[short] MacOS (Intel): 0x286950
     * @note[short] Windows: 0x9dbe0
     * @note[short] Android
     */
    void onAdventureMap(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x230c80
     * @note[short] MacOS (Intel): 0x287820
     * @note[short] Windows: 0x9f190
     * @note[short] Android
     */
    void onBack(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x22fe84
     * @note[short] MacOS (Intel): 0x2869c0
     * @note[short] Windows: 0x9ddb0
     * @note[short] Android
     */
    void onChallenge(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x22febc
     * @note[short] MacOS (Intel): 0x2869f0
     * @note[short] Windows: 0x9dd50
     * @note[short] Android
     */
    void onDailyLevel(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x22fefc
     * @note[short] MacOS (Intel): 0x286a30
     * @note[short] Windows: 0x9dd90
     * @note[short] Android
     */
    void onEventLevel(cocos2d::CCObject* sender);
    
private:
    [[deprecated("CreatorLayer::onFameLevels not implemented")]]
    /**
     * @note[short] Android
     */
    void onFameLevels(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x22ff64
     * @note[short] MacOS (Intel): 0x286aa0
     * @note[short] Windows: 0x9d2a0
     * @note[short] Android
     */
    void onFeaturedLevels(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x22ff1c
     * @note[short] MacOS (Intel): 0x286a50
     * @note[short] Windows: 0x9d590
     * @note[short] Android
     */
    void onGauntlets(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x22fa48
     * @note[short] MacOS (Intel): 0x2865a0
     * @note[short] Windows: 0x9d0f0
     * @note[short] Android
     */
    void onLeaderboards(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x23002c
     * @note[short] MacOS (Intel): 0x286b80
     * @note[short] Windows: 0x9d4d0
     * @note[short] Android
     */
    void onMapPacks(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x22fa84
     * @note[short] MacOS (Intel): 0x2865e0
     * @note[short] Windows: 0x9d610
     * @note[short] Android
     */
    void onMultiplayer(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x2300b4
     * @note[short] MacOS (Intel): 0x286c20
     * @note[short] Windows: 0x9cce0
     * @note[short] Android
     */
    void onMyLevels(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x230078
     * @note[short] MacOS (Intel): 0x286be0
     * @note[short] Windows: 0x9d450
     * @note[short] Android
     */
    void onOnlineLevels(cocos2d::CCObject* sender);
    
private:
    [[deprecated("CreatorLayer::onOnlyFullVersion not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x23017c
     * @note[short] MacOS (Intel): 0x286d00
     * @note[short] Android
     */
    void onOnlyFullVersion(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x22ffb0
     * @note[short] MacOS (Intel): 0x286b00
     * @note[short] Windows: 0x9d360
     * @note[short] Android
     */
    void onPaths(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x22f988
     * @note[short] MacOS (Intel): 0x2864d0
     * @note[short] Windows: 0x9cef0
     * @note[short] Android
     */
    void onSavedLevels(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x230498
     * @note[short] MacOS (Intel): 0x287000
     * @note[short] Windows: 0x9df20
     * @note[short] Android
     */
    void onSecretVault(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x22ffcc
     * @note[short] MacOS (Intel): 0x286b20
     * @note[short] Windows: 0x9d380
     * @note[short] Android
     */
    void onTopLists(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x2306ec
     * @note[short] MacOS (Intel): 0x287220
     * @note[short] Windows: 0x9e730
     * @note[short] Android
     */
    void onTreasureRoom(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x22fedc
     * @note[short] MacOS (Intel): 0x286a10
     * @note[short] Windows: 0x9dd70
     * @note[short] Android
     */
    void onWeeklyLevel(cocos2d::CCObject* sender);
    cocos2d::CCSprite* m_secretDoorSprite;
    cocos2d::CCSprite* m_questsSprite;
    int m_vaultDialogIndex;
    int m_versusDialogIndex;
};
