#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "UIButtonConfig.hpp"
#include "GManager.hpp"

class GameManager : public GManager {
public:
    static constexpr auto CLASS_NAME = "GameManager";
    GEODE_CUSTOM_CONSTRUCTOR_GD(GameManager, GManager)

    /**
     * @note[short] Windows: 0x177af0
     * @note[short] Android
     */
    virtual  ~GameManager();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    static GameManager* get();

    /**
     * @note[short] MacOS (ARM): 0x2f60ec
     * @note[short] MacOS (Intel): 0x363400
     * @note[short] Windows: 0x178480
     * @note[short] Android
     */
    static GameManager* sharedState();

    /**
     * @note[short] MacOS (ARM): 0x308ae4
     * @note[short] MacOS (Intel): 0x3785d0
     * @note[short] Windows: 0x186c40
     * @note[short] iOS: 0x31d65c
     * @note[short] Android
     */
    virtual void update(float p0);

    /**
     * @note[short] MacOS (ARM): 0x2f6158
     * @note[short] MacOS (Intel): 0x363460
     * @note[short] Windows: 0x1784d0
     * @note[short] iOS: 0x311e44
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (ARM): 0x307eec
     * @note[short] MacOS (Intel): 0x3779c0
     * @note[short] Windows: 0x186050
     * @note[short] iOS: 0x31ce28
     * @note[short] Android
     */
    virtual void encodeDataTo(DS_Dictionary* p0);

    /**
     * @note[short] MacOS (ARM): 0x306384
     * @note[short] MacOS (Intel): 0x375ba0
     * @note[short] Windows: 0x183b40
     * @note[short] iOS: 0x31b6a4
     * @note[short] Android
     */
    virtual void dataLoaded(DS_Dictionary* p0);

    /**
     * @note[short] MacOS (ARM): 0x3076a8
     * @note[short] MacOS (Intel): 0x377060
     * @note[short] Windows: 0x185750
     * @note[short] iOS: 0x31c908
     * @note[short] Android
     */
    virtual void firstLoad();
    
private:
    [[deprecated("GameManager::accountStatusChanged not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn accountStatusChanged();
public:

    /**
     * @note[short] MacOS (ARM): 0x2feb3c
     * @note[short] MacOS (Intel): 0x36d480
     * @note[short] Windows: 0x17ea70
     * @note[short] Android
     */
    int activeIconForType(IconType p0);
    
private:
    [[deprecated("GameManager::addCustomAnimationFrame not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn addCustomAnimationFrame(int p0, int p1, gd::string p2, gd::string p3);
public:
    
private:
    [[deprecated("GameManager::addDuplicateLastFrame not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn addDuplicateLastFrame(int p0);
public:
    
private:
    [[deprecated("GameManager::addGameAnimation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn addGameAnimation(int p0, int p1, float p2, gd::string p3, gd::string p4, int p5);
public:
    
private:
    [[deprecated("GameManager::addIconDelegate not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn addIconDelegate(cocos2d::CCObject* p0, int p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x302400
     * @note[short] MacOS (Intel): 0x370fd0
     * @note[short] Windows: 0x1807d0
     * @note[short] Android
     */
    void addNewCustomObject(gd::string str);
    
private:
    [[deprecated("GameManager::addToGJLog not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn addToGJLog(cocos2d::CCString* p0);
public:
    
private:
    [[deprecated("GameManager::applicationDidEnterBackground not implemented")]]
    /**
     * @note[short] Android
     */
    void applicationDidEnterBackground();
public:

    /**
     * @note[short] Windows: 0x186cd0
     * @note[short] Android
     */
    TodoReturn applicationWillEnterForeground();
    
private:
    [[deprecated("GameManager::calculateBaseKeyForIcons not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn calculateBaseKeyForIcons();
public:
    
private:
    [[deprecated("GameManager::canShowRewardedVideo not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn canShowRewardedVideo();
public:
    
private:
    [[deprecated("GameManager::checkSteamAchievementUnlock not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn checkSteamAchievementUnlock();
public:

    /**
     * @note[short] MacOS (Intel): 0x36b860
     * @note[short] Windows: 0x1811b0
     * @note[short] Android
     */
    TodoReturn checkUsedIcons();
    
private:
    [[deprecated("GameManager::claimItemsResponse not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn claimItemsResponse(gd::string p0);
public:
    
private:
    [[deprecated("GameManager::clearGJLog not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn clearGJLog();
public:

    /**
     * @note[short] MacOS (ARM): 0x2fdae8
     * @note[short] MacOS (Intel): 0x36c520
     * @note[short] Windows: 0x17e330
     * @note[short] Android
     */
    cocos2d::ccColor3B colorForIdx(int p0);
    
private:
    [[deprecated("GameManager::colorForPos not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn colorForPos(int p0);
public:
    
private:
    [[deprecated("GameManager::colorKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn colorKey(int p0, UnlockType p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x2f8464
     * @note[short] Windows: 0x17a1d0
     * @note[short] Android
     */
    bool completedAchievement(gd::string p0);

    /**
     * @note[short] MacOS (ARM): 0x2febfc
     * @note[short] MacOS (Intel): 0x36d6f0
     * @note[short] Windows: 0x17ebe0
     * @note[short] Android
     */
    int countForType(IconType p0);
    
private:
    [[deprecated("GameManager::defaultFrameForAnimation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn defaultFrameForAnimation(int p0);
public:
    
private:
    [[deprecated("GameManager::defaultYOffsetForBG2 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn defaultYOffsetForBG2(int p0);
public:
    
private:
    [[deprecated("GameManager::didExitPlayscene not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x308a38
     * @note[short] MacOS (Intel): 0x378540
     * @note[short] Android
     */
    TodoReturn didExitPlayscene();
public:
    
private:
    [[deprecated("GameManager::doQuickSave not implemented")]]
    /**
     * @note[short] Android
     */
    void doQuickSave();
public:

    /**
     * @note[short] MacOS (ARM): 0x304e14
     * @note[short] MacOS (Intel): 0x374330
     * @note[short] Windows: 0x183540
     * @note[short] Android
     */
    TodoReturn dpadConfigToString(UIButtonConfig& p0);
    
private:
    [[deprecated("GameManager::eventUnlockFeature not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn eventUnlockFeature(char const* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x2f6a1c
     * @note[short] MacOS (Intel): 0x363ca0
     * @note[short] Windows: 0x178a90
     * @note[short] Android
     */
    void fadeInMenuMusic();

    /**
     * @note[short] MacOS (ARM): 0x2f6b18
     * @note[short] MacOS (Intel): 0x363d80
     * @note[short] Windows: 0x178b80
     * @note[short] Android
     */
    void fadeInMusic(gd::string p0);
    
private:
    [[deprecated("GameManager::finishedLoadingBGAsync not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn finishedLoadingBGAsync(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("GameManager::finishedLoadingGAsync not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn finishedLoadingGAsync(int p0);
public:
    
private:
    [[deprecated("GameManager::finishedLoadingGAsync1 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn finishedLoadingGAsync1(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("GameManager::finishedLoadingGAsync2 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn finishedLoadingGAsync2(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("GameManager::finishedLoadingIconAsync not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn finishedLoadingIconAsync(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("GameManager::finishedLoadingMGAsync not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn finishedLoadingMGAsync(int p0);
public:
    
private:
    [[deprecated("GameManager::finishedLoadingMGAsync1 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn finishedLoadingMGAsync1(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("GameManager::finishedLoadingMGAsync2 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn finishedLoadingMGAsync2(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("GameManager::followTwitch not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn followTwitch();
public:
    
private:
    [[deprecated("GameManager::followTwitter not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn followTwitter();
public:
    
private:
    [[deprecated("GameManager::framesForAnimation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn framesForAnimation(int p0);
public:
    
private:
    [[deprecated("GameManager::frameTimeForAnimation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn frameTimeForAnimation(int p0);
public:
    
private:
    [[deprecated("GameManager::generateSecretNumber not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn generateSecretNumber();
public:

    /**
     * @note[short] MacOS (ARM): 0x3017dc
     * @note[short] MacOS (Intel): 0x370460
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    const char* getBGTexture(int id);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    LevelEditorLayer* getEditorLayer();
    
private:
    [[deprecated("GameManager::getFontFile not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x300d14
     * @note[short] MacOS (Intel): 0x36fa00
     * @note[short] Android
     */
    void getFontFile(int p0);
public:
    
private:
    [[deprecated("GameManager::getFontTexture not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getFontTexture(int p0);
public:

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    GJBaseGameLayer* getGameLayer();

    /**
     * @note[short] MacOS (ARM): 0x2f6894
     * @note[short] MacOS (Intel): 0x363b40
     * @note[short] Windows: 0x1800f0
     * @note[short] Android
     */
    bool getGameVariable(char const* p0);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    bool getGameVariableDefault(const char* key, bool defaultValue);
    
private:
    [[deprecated("GameManager::getGTexture not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x370500
     * @note[short] Android
     */
    TodoReturn getGTexture(int p0);
public:

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int getIconRequestID();

    /**
     * @note[short] MacOS (ARM): 0x3020bc
     * @note[short] MacOS (Intel): 0x370ca0
     * @note[short] Windows: 0x1806f0
     * @note[short] Android
     */
    int getIntGameVariable(char const* p0);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int getIntGameVariableDefault(const char* key, int defaultValue);

    /**
     * @note[short] MacOS (ARM): 0x2f63c0
     * @note[short] MacOS (Intel): 0x3636f0
     * @note[short] Windows: 0x178700
     * @note[short] Android
     */
    gd::string getMenuMusicFile();
    
private:
    [[deprecated("GameManager::getMGTexture not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getMGTexture(int p0);
public:
    
private:
    [[deprecated("GameManager::getNextUniqueObjectKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getNextUniqueObjectKey();
public:
    
private:
    [[deprecated("GameManager::getNextUsedKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getNextUsedKey(int p0, bool p1);
public:
    
private:
    [[deprecated("GameManager::getOrderedCustomObjectKeys not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x370e40
     * @note[short] Android
     */
    TodoReturn getOrderedCustomObjectKeys();
public:

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int getPlayerBall();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int getPlayerBird();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int getPlayerColor();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int getPlayerColor2();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int getPlayerDart();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int getPlayerDeathEffect();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int getPlayerFrame();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    bool getPlayerGlow();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int getPlayerGlowColor();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int getPlayerJetpack();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int getPlayerRobot();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int getPlayerShip();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int getPlayerShipFire();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int getPlayerSpider();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int getPlayerStreak();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int getPlayerSwing();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    PlayLayer* getPlayLayer();
    
private:
    [[deprecated("GameManager::getPracticeMusicFile not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2f6540
     * @note[short] MacOS (Intel): 0x363850
     * @note[short] Android
     */
    TodoReturn getPracticeMusicFile();
public:

    /**
     * @note[short] MacOS (ARM): 0x301df0
     * @note[short] MacOS (Intel): 0x370a10
     * @note[short] Windows: 0x180480
     * @note[short] Android
     */
    bool getUGV(char const* p0);
    
private:
    [[deprecated("GameManager::getUnlockForAchievement not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getUnlockForAchievement(gd::string p0, int& p1, UnlockType& p2);
public:
    
private:
    [[deprecated("GameManager::groundHasSecondaryColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn groundHasSecondaryColor(int p0);
public:
    
private:
    [[deprecated("GameManager::iconAndTypeForKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn iconAndTypeForKey(int p0, int& p1, int& p2);
public:

    /**
     * @note[short] Windows: 0x1792b0
     * @note[short] Android
     */
    gd::string iconKey(int p0, IconType p1);

    /**
     * @note[short] MacOS (ARM): 0x2f7498
     * @note[short] MacOS (Intel): 0x364990
     * @note[short] Windows: 0x1795c0
     * @note[short] Android
     */
    UnlockType iconTypeToUnlockType(IconType p0);

    /**
     * @note[short] MacOS (ARM): 0x2f78a8
     * @note[short] MacOS (Intel): 0x364f40
     * @note[short] Windows: 0x1798c0
     * @note[short] Android
     */
    bool isColorUnlocked(int p0, UnlockType p1);
    
private:
    [[deprecated("GameManager::isIconLoaded not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x36d8f0
     * @note[short] Android
     */
    bool isIconLoaded(int p0, int p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x2f7388
     * @note[short] MacOS (Intel): 0x3648d0
     * @note[short] Windows: 0x1794e0
     * @note[short] Android
     */
    bool isIconUnlocked(int p0, IconType p1);
    
private:
    [[deprecated("GameManager::itemPurchased not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn itemPurchased(char const* p0);
public:
    
private:
    [[deprecated("GameManager::joinDiscord not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn joinDiscord();
public:
    
private:
    [[deprecated("GameManager::joinReddit not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2fe974
     * @note[short] MacOS (Intel): 0x36d2c0
     * @note[short] Android
     */
    void joinReddit();
public:

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    int keyForIcon(int iconIdx, int iconEnum);
    
private:
    [[deprecated("GameManager::levelIsPremium not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn levelIsPremium(int p0, int p1);
public:
    
private:
    [[deprecated("GameManager::likeFacebook not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn likeFacebook();
public:

    /**
     * @note[short] MacOS (ARM): 0x300f5c
     * @note[short] MacOS (Intel): 0x36fc40
     * @note[short] Windows: 0x17f880
     * @note[short] Android
     */
    void loadBackground(int p0);
    
private:
    [[deprecated("GameManager::loadBackgroundAsync not implemented")]]
    /**
     * @note[short] Android
     */
    void loadBackgroundAsync(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x300de4
     * @note[short] MacOS (Intel): 0x36fac0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void loadDeathEffect(int id);
    
private:
    [[deprecated("GameManager::loadDpadFromString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x305914
     * @note[short] MacOS (Intel): 0x375010
     * @note[short] Android
     */
    TodoReturn loadDpadFromString(UIButtonConfig& p0, gd::string p1);
public:
    
private:
    [[deprecated("GameManager::loadDPadLayout not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn loadDPadLayout(int p0, bool p1);
public:
    
private:
    [[deprecated("GameManager::loadFont not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x36f960
     * @note[short] Android
     */
    TodoReturn loadFont(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x301484
     * @note[short] MacOS (Intel): 0x370120
     * @note[short] Windows: 0x17fc30
     * @note[short] Android
     */
    void loadGround(int p0);
    
private:
    [[deprecated("GameManager::loadGroundAsync not implemented")]]
    /**
     * @note[short] Android
     */
    void loadGroundAsync(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x2ffaf4
     * @note[short] MacOS (Intel): 0x36e7f0
     * @note[short] Windows: 0x17ecf0
     * @note[short] Android
     */
    cocos2d::CCTexture2D* loadIcon(int p0, int p1, int p2);
    
private:
    [[deprecated("GameManager::loadIconAsync not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn loadIconAsync(int p0, int p1, int p2, cocos2d::CCObject* p3);
public:

    /**
     * @note[short] MacOS (ARM): 0x301148
     * @note[short] MacOS (Intel): 0x36fe10
     * @note[short] Windows: 0x17f9e0
     * @note[short] Android
     */
    void loadMiddleground(int p0);
    
private:
    [[deprecated("GameManager::loadMiddlegroundAsync not implemented")]]
    /**
     * @note[short] Android
     */
    void loadMiddlegroundAsync(int p0);
public:
    
private:
    [[deprecated("GameManager::loadVideoSettings not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x375a90
     * @note[short] Android
     */
    void loadVideoSettings();
public:
    
private:
    [[deprecated("GameManager::lockColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn lockColor(int p0, UnlockType p1);
public:
    
private:
    [[deprecated("GameManager::lockIcon not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn lockIcon(int p0, IconType p1);
public:
    
private:
    [[deprecated("GameManager::logLoadedIconInfo not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn logLoadedIconInfo();
public:
    
private:
    [[deprecated("GameManager::openEditorGuide not implemented")]]
    /**
     * @note[short] Android
     */
    void openEditorGuide();
public:

    /**
     * @note[short] MacOS (ARM): 0x2f66b4
     * @note[short] MacOS (Intel): 0x3639a0
     * @note[short] Windows: 0x178810
     * @note[short] Android
     */
    void playMenuMusic();
    
private:
    [[deprecated("GameManager::playSFXTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn playSFXTrigger(SFXTriggerGameObject* p0);
public:
    
private:
    [[deprecated("GameManager::prepareDPadSettings not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x375340
     * @note[short] Android
     */
    TodoReturn prepareDPadSettings();
public:
    
private:
    [[deprecated("GameManager::printGJLog not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn printGJLog();
public:
    
private:
    [[deprecated("GameManager::queueReloadMenu not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x378db0
     * @note[short] Android
     */
    void queueReloadMenu();
public:
    
private:
    [[deprecated("GameManager::rateGame not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn rateGame();
public:

    /**
     * @note[short] MacOS (ARM): 0x3032cc
     * @note[short] MacOS (Intel): 0x372010
     * @note[short] Windows: 0x181ba0
     * @note[short] Android
     */
    void recountUserStats(gd::string p0);

    /**
     * @note[short] MacOS (ARM): 0x309444
     * @note[short] MacOS (Intel): 0x378ee0
     * @note[short] Windows: 0x187490
     * @note[short] Android
     */
    void reloadAll(bool switchingModes, bool toFullscreen, bool borderless, bool fix, bool unused);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void reloadAll(bool switchingModes, bool toFullscreen, bool unused);

    /**
     * @note[short] MacOS (ARM): 0x3094e8
     * @note[short] MacOS (Intel): 0x378f90
     * @note[short] Windows: 0x187540
     * @note[short] Android
     */
    void reloadAllStep2();
    
private:
    [[deprecated("GameManager::reloadAllStep3 not implemented")]]
    /**
     * @note[short] Android
     */
    void reloadAllStep3();
public:
    
private:
    [[deprecated("GameManager::reloadAllStep4 not implemented")]]
    /**
     * @note[short] Android
     */
    void reloadAllStep4();
public:

    /**
     * @note[short] MacOS (ARM): 0x3096c0
     * @note[short] MacOS (Intel): 0x379180
     * @note[short] Windows: 0x187850
     * @note[short] Android
     */
    void reloadAllStep5();
    
private:
    [[deprecated("GameManager::reloadMenu not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn reloadMenu();
public:
    
private:
    [[deprecated("GameManager::removeCustomObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn removeCustomObject(int p0);
public:
    
private:
    [[deprecated("GameManager::removeIconDelegate not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn removeIconDelegate(int p0);
public:
    
private:
    [[deprecated("GameManager::reorderKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn reorderKey(int p0, bool p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x2f9160
     * @note[short] MacOS (Intel): 0x366830
     * @note[short] Windows: 0x17afd0
     * @note[short] Android
     */
    void reportAchievementWithID(char const* p0, int p1, bool p2);

    /**
     * @note[short] MacOS (ARM): 0x2f87b4
     * @note[short] MacOS (Intel): 0x365da0
     * @note[short] Windows: 0x17a5f0
     * @note[short] Android
     */
    void reportPercentageForLevel(int levelID, int percentage, bool isPlatformer);
    
private:
    [[deprecated("GameManager::resetAchievement not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetAchievement(gd::string p0);
public:
    
private:
    [[deprecated("GameManager::resetAdTimer not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetAdTimer();
public:
    
private:
    [[deprecated("GameManager::resetAllIcons not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetAllIcons();
public:
    
private:
    [[deprecated("GameManager::resetCoinUnlocks not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetCoinUnlocks();
public:
    
private:
    [[deprecated("GameManager::resetDPadSettings not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetDPadSettings(bool p0);
public:

    /**
     * @note[short] MacOS (Intel): 0x3791c0
     * @note[short] Windows: 0x187890
     * @note[short] Android
     */
    cocos2d::CCSize resolutionForKey(int p0);
    
private:
    [[deprecated("GameManager::resumeAudio not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resumeAudio();
public:
    
private:
    [[deprecated("GameManager::resumeAudioDelayed not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resumeAudioDelayed();
public:

    /**
     * @note[short] MacOS (ARM): 0x308f8c
     * @note[short] MacOS (Intel): 0x3789d0
     * @note[short] Windows: 0x187030
     * @note[short] Android
     */
    void returnToLastScene(GJGameLevel* p0);
    
private:
    [[deprecated("GameManager::rewardedVideoAdFinished not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn rewardedVideoAdFinished(int p0);
public:
    
private:
    [[deprecated("GameManager::rewardedVideoHidden not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn rewardedVideoHidden();
public:
    
private:
    [[deprecated("GameManager::rewardedVideoHiddenDelayed not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn rewardedVideoHiddenDelayed();
public:

    /**
     * @note[short] MacOS (ARM): 0x309298
     * @note[short] MacOS (Intel): 0x378d40
     * @note[short] Windows: 0x1873e0
     * @note[short] Android
     */
    void safePopScene();
    
private:
    [[deprecated("GameManager::saveAdTimer not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn saveAdTimer();
public:
    
private:
    [[deprecated("GameManager::saveDPadLayout not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn saveDPadLayout(int p0, bool p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x3018c0
     * @note[short] MacOS (Intel): 0x370550
     * @note[short] Windows: 0x17fe90
     * @note[short] Android
     */
    void setGameVariable(char const* p0, bool p1);
    
private:
    [[deprecated("GameManager::setHasRatingPower not implemented")]]
    /**
     * @note[short] Android
     */
    void setHasRatingPower(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x301f7c
     * @note[short] MacOS (Intel): 0x370b70
     * @note[short] Windows: 0x1805f0
     * @note[short] Android
     */
    void setIntGameVariable(char const* p0, int p1);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void setPlayerBall(int id);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void setPlayerBird(int id);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void setPlayerColor(int id);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void setPlayerColor2(int id);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void setPlayerColor3(int id);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void setPlayerDart(int id);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void setPlayerDeathEffect(int id);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void setPlayerFrame(int id);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void setPlayerGlow(bool v);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void setPlayerJetpack(int id);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void setPlayerRobot(int id);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void setPlayerShip(int id);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void setPlayerShipStreak(int id);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void setPlayerSpider(int id);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void setPlayerStreak(int id);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void setPlayerSwing(int id);
    
private:
    [[deprecated("GameManager::setPlayerUserID not implemented")]]
    /**
     * @note[short] Android
     */
    void setPlayerUserID(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x301c3c
     * @note[short] MacOS (Intel): 0x370890
     * @note[short] Windows: 0x180320
     * @note[short] Android
     */
    void setUGV(char const* p0, bool p1);

    /**
     * @note[short] MacOS (ARM): 0x1fa990
     * @note[short] MacOS (Intel): 0x24d5f0
     * @note[short] Windows: 0x1a8870
     * @note[short] Android
     */
    void setupGameAnimations();

    /**
     * @note[short] MacOS (ARM): 0x2ff040
     * @note[short] MacOS (Intel): 0x36dcb0
     * @note[short] Windows: 0x17f470
     * @note[short] Android
     */
    gd::string sheetNameForIcon(int p0, int p1);
    
private:
    [[deprecated("GameManager::shortenAdTimer not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn shortenAdTimer(float p0);
public:
    
private:
    [[deprecated("GameManager::shouldShowInterstitial not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn shouldShowInterstitial(int p0, int p1, int p2);
public:
    
private:
    [[deprecated("GameManager::showInterstitial not implemented")]]
    /**
     * @note[short] Android
     */
    void showInterstitial();
public:
    
private:
    [[deprecated("GameManager::showInterstitialForced not implemented")]]
    /**
     * @note[short] Android
     */
    void showInterstitialForced();
public:
    
private:
    [[deprecated("GameManager::showMainMenuAd not implemented")]]
    /**
     * @note[short] Android
     */
    void showMainMenuAd();
public:
    
private:
    [[deprecated("GameManager::startUpdate not implemented")]]
    /**
     * @note[short] Android
     */
    void startUpdate();
public:

    /**
     * @note[short] MacOS (ARM): 0x3025a0
     * @note[short] MacOS (Intel): 0x371170
     * @note[short] Windows: 0x180950
     * @note[short] Android
     */
    gd::string stringForCustomObject(int customObjectID);
    
private:
    [[deprecated("GameManager::subYouTube not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn subYouTube();
public:
    
private:
    [[deprecated("GameManager::switchCustomObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn switchCustomObjects(int p0, int p1);
public:
    
private:
    [[deprecated("GameManager::switchScreenMode not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn switchScreenMode(bool p0, bool p1, bool p2, bool p3);
public:
    
private:
    [[deprecated("GameManager::syncPlatformAchievements not implemented")]]
    /**
     * @note[short] Android
     */
    void syncPlatformAchievements();
public:

    /**
     * @note[short] MacOS (ARM): 0x301b54
     * @note[short] MacOS (Intel): 0x3707d0
     * @note[short] Windows: 0x180270
     * @note[short] Android
     */
    void toggleGameVariable(char const* p0);
    
private:
    [[deprecated("GameManager::tryCacheAd not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn tryCacheAd();
public:
    
private:
    [[deprecated("GameManager::tryShowInterstitial not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn tryShowInterstitial(int p0, int p1, int p2);
public:
    
private:
    [[deprecated("GameManager::unloadBackground not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn unloadBackground();
public:

    /**
     * @note[short] MacOS (ARM): 0x30016c
     * @note[short] MacOS (Intel): 0x36ee80
     * @note[short] Windows: 0x17f050
     * @note[short] Android
     */
    void unloadIcon(int p0, int p1, int p2);
    
private:
    [[deprecated("GameManager::unloadIcons not implemented")]]
    /**
     * @note[short] Android
     */
    void unloadIcons(int p0);
public:
    
private:
    [[deprecated("GameManager::unlockColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn unlockColor(int p0, UnlockType p1);
public:
    
private:
    [[deprecated("GameManager::unlockedPremium not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn unlockedPremium();
public:
    
private:
    [[deprecated("GameManager::unlockIcon not implemented")]]
    /**
     * @note[short] Android
     */
    void unlockIcon(int p0, IconType p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x2f7528
     * @note[short] MacOS (Intel): 0x364ba0
     * @note[short] Windows: 0x1796e0
     * @note[short] Android
     */
    IconType unlockTypeToIconType(int p0);

    /**
     * @note[short] MacOS (Intel): 0x379480
     * @note[short] Windows: 0x187cc0
     * @note[short] Android
     */
    void updateCustomFPS();
    
private:
    [[deprecated("GameManager::updateMusic not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateMusic();
public:
    
private:
    [[deprecated("GameManager::verifyAchievementUnlocks not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2f93b0
     * @note[short] Android
     */
    void verifyAchievementUnlocks();
public:
    
private:
    [[deprecated("GameManager::verifyCoinUnlocks not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn verifyCoinUnlocks();
public:
    
private:
    [[deprecated("GameManager::verifyStarUnlocks not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn verifyStarUnlocks();
public:
    
private:
    [[deprecated("GameManager::verifySyncedCoins not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn verifySyncedCoins();
public:
    
private:
    [[deprecated("GameManager::videoAdHidden not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn videoAdHidden();
public:
    
private:
    [[deprecated("GameManager::videoAdShowed not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn videoAdShowed();
public:
    cocos2d::CCDictionary* m_unkAnimationDict;
    cocos2d::CCDictionary* m_unkAnimationDict2;
    cocos2d::CCDictionary* m_frameTimeForAnimation;
    cocos2d::CCDictionary* m_framesForAnimation;
    cocos2d::CCDictionary* m_defaultFrames;
    bool m_switchModes;
    bool m_toFullscreen;
    bool m_reloading;
    bool m_fix;
    bool m_unkBool1;
    bool m_unkBool2;
    bool m_vsyncEnabled;
    cocos2d::CCDictionary* m_valueKeeper;
    cocos2d::CCDictionary* m_unlockValueKeeper;
    cocos2d::CCDictionary* m_customObjectDict;
    double m_adTimer;
    double m_adCache;
    bool m_unkBool3;
    int m_unkSize4_1;
    double m_unkDouble2;
    int m_unkSize4_2;
    int m_unkSize4_3;
    bool m_loaded;
    bool m_googlePlaySignedIn;
    gd::string m_editorClipboard;
    int m_unkSize4_4;
    PlayLayer* m_playLayer;
    LevelEditorLayer* m_levelEditorLayer;
    GJBaseGameLayer* m_gameLayer;
    void* m_unkPtr;
    MenuLayer* m_menuLayer;
    bool m_inMenuLayer;
    void* m_unknownVariable;
    bool m_unknownBool3;
    bool m_unknownPlayLayerBool;
    bool m_unknownBool4;
    bool m_unknownBool5;
    gd::string m_playerUDID;
    gd::string m_playerName;
    bool m_commentsEnabled;
    geode::SeedValueRSV m_playerUserID;
    float m_bgVolume;
    float m_sfxVolume;
    float m_timeOffset;
    bool m_ratedGame;
    bool m_clickedFacebook;
    bool m_clickedTwitter;
    bool m_clickedYouTube;
    bool m_clickedTwitch;
    bool m_clickedDiscord_;
    bool m_clickedReddit;
    double m_socialsDuration;
    bool m_showedAd;
    bool m_unknownBool;
    bool m_editorEnabled;
    int m_sceneEnum;
    bool m_searchObjectBool;
    geode::SeedValueRSV m_playerFrame;
    geode::SeedValueRSV m_playerShip;
    geode::SeedValueRSV m_playerBall;
    geode::SeedValueRSV m_playerBird;
    geode::SeedValueRSV m_playerDart;
    geode::SeedValueRSV m_playerRobot;
    geode::SeedValueRSV m_playerSpider;
    geode::SeedValueRSV m_playerSwing;
    geode::SeedValueRSV m_playerColor;
    geode::SeedValueRSV m_playerColor2;
    geode::SeedValueRSV m_playerGlowColor;
    geode::SeedValueRSV m_playerStreak;
    geode::SeedValueRSV m_playerShipFire;
    geode::SeedValueRSV m_playerDeathEffect;
    geode::SeedValueRSV m_playerJetpack;
    geode::SeedValueRS m_chk;
    geode::SeedValueSR m_secretNumber;
    bool m_playerGlow;
    IconType m_playerIconType;
    bool m_everyPlaySetup;
    bool m_showSongMarkers;
    bool m_showBPMMarkers;
    bool m_recordGameplay;
    bool m_showProgressBar;
    bool m_performanceMode;
    bool m_unkBool4;
    bool m_clickedGarage;
    bool m_clickedEditor;
    bool m_clickedName;
    bool m_clickedPractice;
    bool m_showedEditorGuide;
    bool m_showedRateDiffDialog;
    bool m_showedRateStarDialog;
    bool m_showedLowDetailDialog;
    void* m_unkPtr2;
    void* m_unkPtr3;
    int m_unkSize4_5;
    int m_unkSize4_6;
    int m_unkSize4_7;
    int m_unkSize4_8;
    int m_loadedBgID;
    int m_loadedGroundID;
    int m_loadedMG;
    int m_loadedFont;
    int m_loadedDeathEffect;
    bool m_loadingBG;
    bool m_loadingG;
    bool m_loadingG1;
    bool m_finishedLoadingG1;
    bool m_shouldLoadG1;
    bool m_finishedLoadingMG1;
    bool m_finishedLoadingMG2;
    bool m_unkBool5;
    int m_unkSize4_9;
    int m_unkSize4_10;
    int m_unkSize4_11;
    int m_bootups;
    bool m_hasRatedGame;
    bool m_unkBool6;
    bool m_shouldLoadUnlockValueKeeper;
    bool m_unkBool7;
    bool m_unkBool8;
    geode::SeedValueRSV m_hasRP;
    bool m_canGetLevelSaveData;
    int m_resolution;
    int m_texQuality;
    bool m_somethingInMenuLayer;
    void* m_unkPtr4;
    bool m_ropeGarageEnter;
    int m_unkSize4_12;
    int m_unkSize4_13;
    bool m_unkBool10;
    int m_unkSize4_14;
    bool m_disableThumbstick;
    float m_customFPSTarget;
    bool m_unkBool11;
    int m_customMenuSongID;
    int m_customPracticeSongID;
    gd::map<int, int> m_loadIcon;
    gd::map<int, gd::map<int, int>> m_loadIcon2;
    gd::map<int, bool> m_isIconBeingLoaded;
    gd::vector<int> m_keyStartForIcon;
    gd::map<int, gd::vector<cocos2d::CCObject*>> m_iconDelegates;
    int m_iconRequestID;
    cocos2d::CCArray* m_unkArray;
    void* m_someAdPointer;
    int m_unkSize4_15;
    int m_unkSize4_16;
    int m_unkSize4_17;
    UIButtonConfig m_dpad1;
    UIButtonConfig m_dpad2;
    UIButtonConfig m_dpad3;
    UIButtonConfig m_dpad4;
    UIButtonConfig m_dpad5;
    gd::string m_dpadLayout1;
    gd::string m_dpadLayout2;
    gd::string m_dpadLayout3;
    gd::string m_dpadLayoutDual1;
    gd::string m_dpadLayoutDual2;
    gd::string m_dpadLayoutDual3;
    int m_unkSize4_18;
    int m_unkSize4_19;
    int m_unkSize4_20;
    bool m_shouldResetShader;
    float m_practicePosX;
    float m_practicePosY;
    float m_practiceOpacity;
};
