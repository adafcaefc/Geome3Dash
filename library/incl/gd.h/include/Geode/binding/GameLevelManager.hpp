#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GameLevelManager : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "GameLevelManager";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GameLevelManager, cocos2d::CCNode)

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    static GameLevelManager* get();

    /**
     * @note[short] MacOS (ARM): 0x477c14
     * @note[short] MacOS (Intel): 0x51b260
     * @note[short] Windows: 0x168140
     * @note[short] Android
     */
    static cocos2d::CCDictionary* responseToDict(gd::string p0, bool p1);

    /**
     * @note[short] MacOS (ARM): 0x4641c4
     * @note[short] MacOS (Intel): 0x504a90
     * @note[short] Windows: 0x140b20
     * @note[short] Android
     */
    static GameLevelManager* sharedState();

    /**
     * @note[short] MacOS (ARM): 0x473374
     * @note[short] MacOS (Intel): 0x515dc0
     * @note[short] Windows: 0x142230
     * @note[short] iOS: 0x95d68
     * @note[short] Android
     */
    virtual bool init();
    
private:
    [[deprecated("GameLevelManager::acceptFriendRequest not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x497a7c
     * @note[short] MacOS (Intel): 0x53e840
     * @note[short] Android
     */
    void acceptFriendRequest(int p0, int p1);
public:
    
private:
    [[deprecated("GameLevelManager::accountIDForUserID not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x475c08
     * @note[short] MacOS (Intel): 0x518ae0
     * @note[short] Android
     */
    int accountIDForUserID(int userID);
public:

    /**
     * @note[short] MacOS (ARM): 0x47e834
     * @note[short] MacOS (Intel): 0x5228d0
     * @note[short] Windows: 0x147a20
     * @note[short] Android
     */
    void addDLToActive(char const* p0);
    
private:
    [[deprecated("GameLevelManager::areGauntletsLoaded not implemented")]]
    /**
     * @note[short] Android
     */
    bool areGauntletsLoaded();
public:
    
private:
    [[deprecated("GameLevelManager::banUser not implemented")]]
    /**
     * @note[short] Android
     */
    void banUser(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::blockUser not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x498a24
     * @note[short] MacOS (Intel): 0x53f840
     * @note[short] Android
     */
    void blockUser(int p0);
public:

    /**
     * @note[short] Windows: 0x1485e0
     * @note[short] Android
     */
    void cleanupDailyLevels();
    
private:
    [[deprecated("GameLevelManager::createAndGetAccountComments not implemented")]]
    /**
     * @note[short] Android
     */
    bool createAndGetAccountComments(gd::string p0, int p1);
public:
    
private:
    [[deprecated("GameLevelManager::createAndGetCommentsFull not implemented")]]
    /**
     * @note[short] Android
     */
    bool createAndGetCommentsFull(gd::string p0, int p1, bool p2);
public:
    
private:
    [[deprecated("GameLevelManager::createAndGetLevelComments not implemented")]]
    /**
     * @note[short] Android
     */
    bool createAndGetLevelComments(gd::string p0, int p1);
public:
    
private:
    [[deprecated("GameLevelManager::createAndGetLevelLists not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x51b840
     * @note[short] Android
     */
    cocos2d::CCArray* createAndGetLevelLists(gd::string p0);
public:
    
private:
    [[deprecated("GameLevelManager::createAndGetLevels not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCArray* createAndGetLevels(gd::string p0);
public:
    
private:
    [[deprecated("GameLevelManager::createAndGetMapPacks not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCArray* createAndGetMapPacks(gd::string p0);
public:
    
private:
    [[deprecated("GameLevelManager::createAndGetScores not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x51cf60
     * @note[short] Android
     */
    cocos2d::CCArray* createAndGetScores(gd::string p0, GJScoreType p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x473a40
     * @note[short] MacOS (Intel): 0x5165d0
     * @note[short] Windows: 0x142800
     * @note[short] Android
     */
    GJGameLevel* createNewLevel();

    /**
     * @note[short] MacOS (ARM): 0x474704
     * @note[short] Windows: 0x1432b0
     * @note[short] Android
     */
    GJLevelList* createNewLevelList();
    
private:
    [[deprecated("GameLevelManager::createPageInfo not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x47e660
     * @note[short] MacOS (Intel): 0x522710
     * @note[short] Android
     */
    TodoReturn createPageInfo(int p0, int p1, int p2);
public:
    
private:
    [[deprecated("GameLevelManager::createSmartTemplate not implemented")]]
    /**
     * @note[short] Android
     */
    GJSmartTemplate* createSmartTemplate();
public:

    /**
     * @note[short] MacOS (ARM): 0x481004
     * @note[short] MacOS (Intel): 0x525360
     * @note[short] Windows: 0x149310
     * @note[short] Android
     */
    void dataLoaded(DS_Dictionary* p0);
    
private:
    [[deprecated("GameLevelManager::deleteAccountComment not implemented")]]
    /**
     * @note[short] Android
     */
    void deleteAccountComment(int p0, int p1);
public:
    
private:
    [[deprecated("GameLevelManager::deleteComment not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x496170
     * @note[short] MacOS (Intel): 0x53ccf0
     * @note[short] Android
     */
    void deleteComment(int p0, CommentType p1, int p2);
public:

    /**
     * @note[short] MacOS (ARM): 0x49713c
     * @note[short] MacOS (Intel): 0x53de30
     * @note[short] Windows: 0x15e180
     * @note[short] Android
     */
    bool deleteFriendRequests(int p0, cocos2d::CCArray* p1, bool p2);

    /**
     * @note[short] MacOS (ARM): 0x4743e0
     * @note[short] MacOS (Intel): 0x517010
     * @note[short] Windows: 0x142fe0
     * @note[short] Android
     */
    void deleteLevel(GJGameLevel* p0);
    
private:
    [[deprecated("GameLevelManager::deleteLevelComment not implemented")]]
    /**
     * @note[short] Android
     */
    void deleteLevelComment(int p0, int p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x474ba4
     * @note[short] MacOS (Intel): 0x517880
     * @note[short] Windows: 0x143890
     * @note[short] Android
     */
    void deleteLevelList(GJLevelList* p0);
    
private:
    [[deprecated("GameLevelManager::deleteSentFriendRequest not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x53de10
     * @note[short] Android
     */
    bool deleteSentFriendRequest(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x48b430
     * @note[short] MacOS (Intel): 0x530ad0
     * @note[short] Windows: 0x152350
     * @note[short] Android
     */
    void deleteServerLevel(int p0);
    
private:
    [[deprecated("GameLevelManager::deleteServerLevelList not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x486e7c
     * @note[short] MacOS (Intel): 0x52bc60
     * @note[short] Android
     */
    void deleteServerLevelList(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::deleteSmartTemplate not implemented")]]
    /**
     * @note[short] Android
     */
    void deleteSmartTemplate(GJSmartTemplate* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x492290
     * @note[short] MacOS (Intel): 0x5389d0
     * @note[short] Windows: 0x158f20
     * @note[short] Android
     */
    void deleteUserMessages(GJUserMessage* message, cocos2d::CCArray* messages, bool isSender);

    /**
     * @note[short] MacOS (ARM): 0x4889b0
     * @note[short] MacOS (Intel): 0x52dae0
     * @note[short] Windows: 0x14fde0
     * @note[short] Android
     */
    void downloadLevel(int p0, bool p1);
    
private:
    [[deprecated("GameLevelManager::downloadUserMessage not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x491908
     * @note[short] MacOS (Intel): 0x537ff0
     * @note[short] Android
     */
    void downloadUserMessage(int p0, bool p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x480b48
     * @note[short] MacOS (Intel): 0x524e30
     * @note[short] Windows: 0x148e00
     * @note[short] Android
     */
    void encodeDataTo(DS_Dictionary* p0);
    
private:
    [[deprecated("GameLevelManager::firstSetup not implemented")]]
    /**
     * @note[short] Android
     */
    void firstSetup();
public:
    
private:
    [[deprecated("GameLevelManager::followUser not implemented")]]
    /**
     * @note[short] Android
     */
    void followUser(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::friendRequestFromAccountID not implemented")]]
    /**
     * @note[short] Android
     */
    GJFriendRequest* friendRequestFromAccountID(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::friendRequestWasRemoved not implemented")]]
    /**
     * @note[short] Android
     */
    void friendRequestWasRemoved(int p0, bool p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x4935b0
     * @note[short] MacOS (Intel): 0x539d80
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    char const* getAccountCommentKey(int p0, int p1);
    
private:
    [[deprecated("GameLevelManager::getAccountComments not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x493268
     * @note[short] MacOS (Intel): 0x539a30
     * @note[short] Android
     */
    void getAccountComments(int accountID, int page, int total);
public:
    
private:
    [[deprecated("GameLevelManager::getActiveDailyID not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x49c9d0
     * @note[short] MacOS (Intel): 0x5439d0
     * @note[short] Android
     */
    int getActiveDailyID(GJTimedLevelType p0);
public:
    
private:
    [[deprecated("GameLevelManager::getActiveSmartTemplate not implemented")]]
    /**
     * @note[short] Android
     */
    GJSmartTemplate* getActiveSmartTemplate();
public:
    
private:
    [[deprecated("GameLevelManager::getAllSmartTemplates not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCArray* getAllSmartTemplates();
public:
    
private:
    [[deprecated("GameLevelManager::getAllUsedSongIDs not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCDictionary* getAllUsedSongIDs();
public:
    
private:
    [[deprecated("GameLevelManager::getAllUsedSongIDs not implemented")]]
    /**
     * @note[short] Android
     */
    GJLevelList* getAllUsedSongIDs(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x4826c4
     * @note[short] MacOS (Intel): 0x526da0
     * @note[short] Windows: 0x14a4b0
     * @note[short] Android
     */
    gd::string getBasePostString();

    /**
     * @note[short] MacOS (ARM): 0x49da8c
     * @note[short] MacOS (Intel): 0x544a30
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    bool getBoolForKey(char const* key);

    /**
     * @note[short] MacOS (ARM): 0x492fb4
     * @note[short] MacOS (Intel): 0x5397d0
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    gd::string getCommentKey(int ID, int page, int mode, CommentKeyType keytype);
    
private:
    [[deprecated("GameLevelManager::getCompletedDailyLevels not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getCompletedDailyLevels();
public:
    
private:
    [[deprecated("GameLevelManager::getCompletedEventLevels not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getCompletedEventLevels(int p0, int p1);
public:
    
private:
    [[deprecated("GameLevelManager::getCompletedGauntletDemons not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getCompletedGauntletDemons();
public:
    
private:
    [[deprecated("GameLevelManager::getCompletedGauntletLevels not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getCompletedGauntletLevels();
public:

    /**
     * @note[short] MacOS (ARM): 0x47b4a4
     * @note[short] MacOS (Intel): 0x51ef80
     * @note[short] Windows: 0x145860
     * @note[short] Android
     */
    cocos2d::CCArray* getCompletedLevels(bool p0);
    
private:
    [[deprecated("GameLevelManager::getCompletedWeeklyLevels not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getCompletedWeeklyLevels();
public:
    
private:
    [[deprecated("GameLevelManager::getDailyID not implemented")]]
    /**
     * @note[short] Android
     */
    int getDailyID(GJTimedLevelType p0);
public:
    
private:
    [[deprecated("GameLevelManager::getDailyTimer not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x49ca04
     * @note[short] MacOS (Intel): 0x543a00
     * @note[short] Android
     */
    double getDailyTimer(GJTimedLevelType p0);
public:
    
private:
    [[deprecated("GameLevelManager::getDeleteCommentKey not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x494660
     * @note[short] MacOS (Intel): 0x53afa0
     * @note[short] Android
     */
    char const* getDeleteCommentKey(int p0, int p1, int p2);
public:
    
private:
    [[deprecated("GameLevelManager::getDeleteMessageKey not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x492778
     * @note[short] MacOS (Intel): 0x538ed0
     * @note[short] Android
     */
    char const* getDeleteMessageKey(int p0, bool p1);
public:
    
private:
    [[deprecated("GameLevelManager::getDemonLevelsString not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getDemonLevelsString();
public:
    
private:
    [[deprecated("GameLevelManager::getDescKey not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x494610
     * @note[short] MacOS (Intel): 0x53af60
     * @note[short] Android
     */
    char const* getDescKey(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::getDifficultyStr not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getDifficultyStr(bool p0, bool p1, bool p2, bool p3, bool p4, bool p5, bool p6, bool p7);
public:
    
private:
    [[deprecated("GameLevelManager::getDiffKey not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x49d290
     * @note[short] MacOS (Intel): 0x544280
     * @note[short] Android
     */
    char const* getDiffKey(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::getDiffVal not implemented")]]
    /**
     * @note[short] Android
     */
    bool getDiffVal(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x4803b8
     * @note[short] MacOS (Intel): 0x5245e0
     * @note[short] Windows: 0x148910
     * @note[short] Android
     */
    gd::string getFolderName(int p0, bool p1);
    
private:
    [[deprecated("GameLevelManager::getFriendRequestKey not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4945e4
     * @note[short] MacOS (Intel): 0x53af40
     * @note[short] Android
     */
    char const* getFriendRequestKey(bool p0, int p1);
public:
    
private:
    [[deprecated("GameLevelManager::getFriendRequests not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x49689c
     * @note[short] MacOS (Intel): 0x53d510
     * @note[short] Android
     */
    void getFriendRequests(bool p0, int p1, int p2);
public:
    
private:
    [[deprecated("GameLevelManager::getGauntletKey not implemented")]]
    /**
     * @note[short] Android
     */
    char const* getGauntletKey(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::getGauntletLevels not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4883b0
     * @note[short] MacOS (Intel): 0x52d450
     * @note[short] Android
     */
    void getGauntletLevels(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::getGauntlets not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x487fd0
     * @note[short] MacOS (Intel): 0x52d080
     * @note[short] Android
     */
    void getGauntlets();
public:
    
private:
    [[deprecated("GameLevelManager::getGauntletSearchKey not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x487f04
     * @note[short] MacOS (Intel): 0x52cfc0
     * @note[short] Android
     */
    TodoReturn getGauntletSearchKey(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::getGauntletsearchKey not implemented")]]
    /**
     * @note[short] Android
     */
    void getGauntletsearchKey(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x49be48
     * @note[short] MacOS (Intel): 0x542da0
     * @note[short] Windows: 0x164ad0
     * @note[short] Android
     */
    void getGJChallenges();

    /**
     * @note[short] MacOS (ARM): 0x49c2bc
     * @note[short] MacOS (Intel): 0x543260
     * @note[short] Windows: 0x165ec0
     * @note[short] Android
     */
    void getGJDailyLevelState(GJTimedLevelType p0);

    /**
     * @note[short] MacOS (ARM): 0x49b6b0
     * @note[short] MacOS (Intel): 0x542540
     * @note[short] Windows: 0x1635e0
     * @note[short] Android
     */
    void getGJRewards(int p0);
    
private:
    [[deprecated("GameLevelManager::getGJSecretReward not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x49b214
     * @note[short] MacOS (Intel): 0x542050
     * @note[short] Android
     */
    TodoReturn getGJSecretReward(gd::string p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x4901ac
     * @note[short] MacOS (Intel): 0x536710
     * @note[short] Windows: 0x157880
     * @note[short] Android
     */
    void getGJUserInfo(int p0);
    
private:
    [[deprecated("GameLevelManager::getHighestLevelOrder not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x51ece0
     * @note[short] Android
     */
    int getHighestLevelOrder();
public:

    /**
     * @note[short] MacOS (ARM): 0x49d874
     * @note[short] MacOS (Intel): 0x544830
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    int getIntForKey(char const* key);

    /**
     * @note[short] MacOS (ARM): 0x48e540
     * @note[short] MacOS (Intel): 0x5347a0
     * @note[short] Windows: 0x1554b0
     * @note[short] Android
     */
    void getLeaderboardScores(char const* p0);
    
private:
    [[deprecated("GameLevelManager::getLengthStr not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4841e8
     * @note[short] MacOS (Intel): 0x528ae0
     * @note[short] Android
     */
    gd::string getLengthStr(bool p0, bool p1, bool p2, bool p3, bool p4, bool p5);
public:
    
private:
    [[deprecated("GameLevelManager::getLenKey not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x49d4f4
     * @note[short] MacOS (Intel): 0x5444d0
     * @note[short] Android
     */
    const char * getLenKey(int len);
public:
    
private:
    [[deprecated("GameLevelManager::getLenVal not implemented")]]
    /**
     * @note[short] Android
     */
    bool getLenVal(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x492b0c
     * @note[short] MacOS (Intel): 0x5392d0
     * @note[short] Windows: 0x159870
     * @note[short] Android
     */
    void getLevelComments(int ID, int page, int total, int mode, CommentKeyType keytype);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    const char* getLevelDownloadKey(int levelID, bool isGauntlet);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    const char* getLevelKey(int levelID);

    /**
     * @note[short] MacOS (ARM): 0x48ed8c
     * @note[short] MacOS (Intel): 0x535090
     * @note[short] Windows: 0x155ff0
     * @note[short] Android
     */
    void getLevelLeaderboard(GJGameLevel* p0, LevelLeaderboardType p1, LevelLeaderboardMode p2);
    
private:
    [[deprecated("GameLevelManager::getLevelLeaderboardKey not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x48f940
     * @note[short] MacOS (Intel): 0x535e90
     * @note[short] Android
     */
    char const* getLevelLeaderboardKey(int p0, LevelLeaderboardType p1, LevelLeaderboardMode p2);
public:
    
private:
    [[deprecated("GameLevelManager::getLevelListKey not implemented")]]
    /**
     * @note[short] Android
     */
    char const* getLevelListKey(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x4873b8
     * @note[short] MacOS (Intel): 0x52c220
     * @note[short] Windows: 0x14e6e0
     * @note[short] Android
     */
    void getLevelLists(GJSearchObject* p0);

    /**
     * @note[short] MacOS (ARM): 0x485a64
     * @note[short] MacOS (Intel): 0x52a7d0
     * @note[short] Windows: 0x14cd40
     * @note[short] Android
     */
    void getLevelSaveData();
    
private:
    [[deprecated("GameLevelManager::getLikeAccountItemKey not implemented")]]
    /**
     * @note[short] Android
     */
    char const* getLikeAccountItemKey(LikeItemType p0, int p1, bool p2, int p3);
public:
    
private:
    [[deprecated("GameLevelManager::getLikeItemKey not implemented")]]
    /**
     * @note[short] Android
     */
    char const* getLikeItemKey(LikeItemType p0, int p1, bool p2, int p3);
public:
    
private:
    [[deprecated("GameLevelManager::getLocalLevel not implemented")]]
    /**
     * @note[short] Android
     */
    GJGameLevel* getLocalLevel(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::getLocalLevelByName not implemented")]]
    /**
     * @note[short] Android
     */
    GJGameLevel* getLocalLevelByName(gd::string p0);
public:
    
private:
    [[deprecated("GameLevelManager::getLocalLevelList not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getLocalLevelList(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::getLowestLevelOrder not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x51ed20
     * @note[short] Android
     */
    int getLowestLevelOrder();
public:

    /**
     * @note[short] MacOS (ARM): 0x473484
     * @note[short] MacOS (Intel): 0x515f50
     * @note[short] Windows: 0x1423e0
     * @note[short] Android
     */
    GJGameLevel* getMainLevel(int levelID, bool dontGetLevelString);
    
private:
    [[deprecated("GameLevelManager::getMapPackKey not implemented")]]
    /**
     * @note[short] Android
     */
    const char* getMapPackKey(int pack);
public:

    /**
     * @note[short] MacOS (ARM): 0x485d20
     * @note[short] MacOS (Intel): 0x52aa70
     * @note[short] Windows: 0x14d470
     * @note[short] Android
     */
    void getMapPacks(GJSearchObject* p0);
    
private:
    [[deprecated("GameLevelManager::getMessageKey not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x491c5c
     * @note[short] MacOS (Intel): 0x538350
     * @note[short] Android
     */
    char const* getMessageKey(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::getMessagesKey not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x490dc4
     * @note[short] MacOS (Intel): 0x5373f0
     * @note[short] Android
     */
    char const* getMessagesKey(bool p0, int p1);
public:
    
private:
    [[deprecated("GameLevelManager::getNews not implemented")]]
    /**
     * @note[short] Android
     */
    void getNews();
public:
    
private:
    [[deprecated("GameLevelManager::getNextFreeTemplateID not implemented")]]
    /**
     * @note[short] Android
     */
    int getNextFreeTemplateID();
public:
    
private:
    [[deprecated("GameLevelManager::getNextLevelName not implemented")]]
    /**
     * @note[short] Android
     */
    gd::string getNextLevelName(gd::string p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x484cec
     * @note[short] MacOS (Intel): 0x529700
     * @note[short] Windows: 0x14bb70
     * @note[short] Android
     */
    void getOnlineLevels(GJSearchObject* p0);
    
private:
    [[deprecated("GameLevelManager::getPageInfo not implemented")]]
    /**
     * @note[short] Android
     */
    char const* getPageInfo(char const* p0);
public:
    
private:
    [[deprecated("GameLevelManager::getPostCommentKey not implemented")]]
    /**
     * @note[short] Android
     */
    char const* getPostCommentKey(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::getRateStarsKey not implemented")]]
    /**
     * @note[short] Android
     */
    const char * getRateStarsKey(int key);
public:
    
private:
    [[deprecated("GameLevelManager::getReportKey not implemented")]]
    /**
     * @note[short] Android
     */
    char const* getReportKey(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x47d344
     * @note[short] MacOS (Intel): 0x521300
     * @note[short] Windows: 0x146ba0
     * @note[short] Android
     */
    GJGameLevel* getSavedDailyLevel(int p0);
    
private:
    [[deprecated("GameLevelManager::getSavedDailyLevelFromLevelID not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x47d650
     * @note[short] MacOS (Intel): 0x521600
     * @note[short] Android
     */
    GJGameLevel* getSavedDailyLevelFromLevelID(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::getSavedGauntlet not implemented")]]
    /**
     * @note[short] Android
     */
    GJMapPack* getSavedGauntlet(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x47d448
     * @note[short] MacOS (Intel): 0x521400
     * @note[short] Windows: 0x146c70
     * @note[short] Android
     */
    GJGameLevel* getSavedGauntletLevel(int p0);

    /**
     * @note[short] MacOS (ARM): 0x4780e4
     * @note[short] MacOS (Intel): 0x51b7f0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    GJGameLevel* getSavedLevel(GJGameLevel* level);

    /**
     * @note[short] MacOS (ARM): 0x47d54c
     * @note[short] MacOS (Intel): 0x521500
     * @note[short] Windows: 0x146ad0
     * @note[short] Android
     */
    GJGameLevel* getSavedLevel(int p0);
    
private:
    [[deprecated("GameLevelManager::getSavedLevelList not implemented")]]
    /**
     * @note[short] Android
     */
    GJLevelList* getSavedLevelList(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::getSavedLevelLists not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCArray* getSavedLevelLists(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x47af84
     * @note[short] MacOS (Intel): 0x51e9f0
     * @note[short] Windows: 0x145410
     * @note[short] Android
     */
    cocos2d::CCArray* getSavedLevels(bool p0, int p1);
    
private:
    [[deprecated("GameLevelManager::getSavedMapPack not implemented")]]
    /**
     * @note[short] Android
     */
    GJMapPack* getSavedMapPack(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::getSearchScene not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x47edb8
     * @note[short] MacOS (Intel): 0x522e00
     * @note[short] Android
     */
    cocos2d::CCScene* getSearchScene(char const* p0);
public:
    
private:
    [[deprecated("GameLevelManager::getSplitIntFromKey not implemented")]]
    /**
     * @note[short] Android
     */
    int getSplitIntFromKey(char const* p0, int p1);
public:
    
private:
    [[deprecated("GameLevelManager::getStarLevelsString not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getStarLevelsString();
public:

    /**
     * @note[short] MacOS (ARM): 0x494a28
     * @note[short] MacOS (Intel): 0x53b2f0
     * @note[short] Windows: 0x15b420
     * @note[short] Android
     */
    cocos2d::CCArray* getStoredLevelComments(char const* p0);

    /**
     * @note[short] MacOS (ARM): 0x47e2d8
     * @note[short] MacOS (Intel): 0x5223c0
     * @note[short] Windows: 0x147780
     * @note[short] Android
     */
    cocos2d::CCArray* getStoredOnlineLevels(char const* p0);
    
private:
    [[deprecated("GameLevelManager::getStoredUserList not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x53f790
     * @note[short] Android
     */
    cocos2d::CCArray* getStoredUserList(UserListType p0);
public:
    
private:
    [[deprecated("GameLevelManager::getStoredUserMessage not implemented")]]
    /**
     * @note[short] Android
     */
    GJUserMessage* getStoredUserMessage(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::getStoredUserMessageReply not implemented")]]
    /**
     * @note[short] Android
     */
    GJUserMessage* getStoredUserMessageReply(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x47ea48
     * @note[short] MacOS (Intel): 0x522ab0
     * @note[short] Windows: 0x147dd0
     * @note[short] Android
     */
    double getTimeLeft(char const* p0, float p1);
    
private:
    [[deprecated("GameLevelManager::getTopArtists not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x48fa04
     * @note[short] MacOS (Intel): 0x535f20
     * @note[short] Android
     */
    void getTopArtists(int page, int total);
public:

    /**
     * @note[short] MacOS (ARM): 0x48fdc4
     * @note[short] MacOS (Intel): 0x536300
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    const char* getTopArtistsKey(int page);
    
private:
    [[deprecated("GameLevelManager::getUploadMessageKey not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x491c84
     * @note[short] MacOS (Intel): 0x538370
     * @note[short] Android
     */
    char const* getUploadMessageKey(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::getUserInfoKey not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x490184
     * @note[short] MacOS (Intel): 0x5366f0
     * @note[short] Android
     */
    char const* getUserInfoKey(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x499414
     * @note[short] MacOS (Intel): 0x5402b0
     * @note[short] Windows: 0x15ffa0
     * @note[short] Android
     */
    void getUserList(UserListType p0);
    
private:
    [[deprecated("GameLevelManager::getUserMessages not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x490a64
     * @note[short] MacOS (Intel): 0x537080
     * @note[short] Android
     */
    void getUserMessages(bool p0, int p1, int p2);
public:

    /**
     * @note[short] MacOS (ARM): 0x48fdec
     * @note[short] MacOS (Intel): 0x536320
     * @note[short] Windows: 0x1571c0
     * @note[short] Android
     */
    void getUsers(GJSearchObject* p0);

    /**
     * @note[short] MacOS (ARM): 0x47dd44
     * @note[short] MacOS (Intel): 0x521e70
     * @note[short] Windows: 0x1473c0
     * @note[short] Android
     */
    void gotoLevelPage(GJGameLevel* p0);

    /**
     * @note[short] MacOS (ARM): 0x46479c
     * @note[short] MacOS (Intel): 0x505160
     * @note[short] Windows: 0x140e00
     * @note[short] Android
     */
    void handleIt(bool p0, gd::string p1, gd::string p2, GJHttpType p3);
    
private:
    [[deprecated("GameLevelManager::handleItDelayed not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4669d0
     * @note[short] MacOS (Intel): 0x507fb0
     * @note[short] Android
     */
    void handleItDelayed(bool p0, gd::string p1, gd::string p2, GJHttpType p3);
public:
    
private:
    [[deprecated("GameLevelManager::handleItND not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x466ce4
     * @note[short] MacOS (Intel): 0x5082a0
     * @note[short] Android
     */
    void handleItND(cocos2d::CCNode* p0, void* p1);
public:
    
private:
    [[deprecated("GameLevelManager::hasDailyStateBeenLoaded not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x49c950
     * @note[short] MacOS (Intel): 0x543960
     * @note[short] Android
     */
    bool hasDailyStateBeenLoaded(GJTimedLevelType p0);
public:
    
private:
    [[deprecated("GameLevelManager::hasDownloadedLevel not implemented")]]
    /**
     * @note[short] Android
     */
    bool hasDownloadedLevel(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::hasDownloadedList not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x48911c
     * @note[short] MacOS (Intel): 0x52e360
     * @note[short] Android
     */
    bool hasDownloadedList(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::hasLikedAccountItem not implemented")]]
    /**
     * @note[short] Android
     */
    bool hasLikedAccountItem(LikeItemType p0, int p1, bool p2, int p3);
public:

    /**
     * @note[short] Windows: 0x1623d0
     * @note[short] Android
     */
    bool hasLikedItem(LikeItemType p0, int p1, bool p2, int p3);

    /**
     * @note[short] MacOS (ARM): 0x49a5c4
     * @note[short] MacOS (Intel): 0x541500
     * @note[short] Windows: 0x162340
     * @note[short] Android
     */
    bool hasLikedItemFullCheck(LikeItemType p0, int p1, int p2);
    
private:
    [[deprecated("GameLevelManager::hasRatedDemon not implemented")]]
    /**
     * @note[short] Android
     */
    bool hasRatedDemon(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::hasRatedLevelStars not implemented")]]
    /**
     * @note[short] Android
     */
    bool hasRatedLevelStars(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::hasReportedLevel not implemented")]]
    /**
     * @note[short] Android
     */
    bool hasReportedLevel(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::invalidateMessages not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x538ef0
     * @note[short] Android
     */
    void invalidateMessages(bool p0, bool p1);
public:
    
private:
    [[deprecated("GameLevelManager::invalidateRequests not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x53e480
     * @note[short] Android
     */
    void invalidateRequests(bool p0, bool p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x4996f8
     * @note[short] MacOS (Intel): 0x540580
     * @note[short] Windows: 0x160840
     * @note[short] Android
     */
    void invalidateUserList(UserListType p0, bool p1);
    
private:
    [[deprecated("GameLevelManager::isDLActive not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x47e73c
     * @note[short] MacOS (Intel): 0x5227e0
     * @note[short] Android
     */
    bool isDLActive(char const* tag);
public:

    /**
     * @note[short] MacOS (ARM): 0x47fda8
     * @note[short] MacOS (Intel): 0x523fe0
     * @note[short] Windows: 0x148840
     * @note[short] Android
     */
    bool isFollowingUser(int p0);

    /**
     * @note[short] Windows: 0x147c90
     * @note[short] Android
     */
    bool isTimeValid(char const* p0, float p1);

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    bool isUpdateValid(int id);
    
private:
    [[deprecated("GameLevelManager::itemIDFromLikeKey not implemented")]]
    /**
     * @note[short] Android
     */
    int itemIDFromLikeKey(char const* p0);
public:
    
private:
    [[deprecated("GameLevelManager::keyHasTimer not implemented")]]
    /**
     * @note[short] Android
     */
    bool keyHasTimer(char const* p0);
public:
    
private:
    [[deprecated("GameLevelManager::levelIDFromCommentKey not implemented")]]
    /**
     * @note[short] Android
     */
    int levelIDFromCommentKey(char const* p0);
public:
    
private:
    [[deprecated("GameLevelManager::levelIDFromPostCommentKey not implemented")]]
    /**
     * @note[short] Android
     */
    int levelIDFromPostCommentKey(char const* p0);
public:
    
private:
    [[deprecated("GameLevelManager::likeFromLikeKey not implemented")]]
    /**
     * @note[short] Android
     */
    int likeFromLikeKey(char const* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x499d68
     * @note[short] MacOS (Intel): 0x540b40
     * @note[short] Windows: 0x161270
     * @note[short] Android
     */
    void likeItem(LikeItemType p0, int p1, bool p2, int p3);

    /**
     * @note[short] MacOS (ARM): 0x47f58c
     * @note[short] MacOS (Intel): 0x5236b0
     * @note[short] Windows: 0x148090
     * @note[short] Android
     */
    void limitSavedLevels();

    /**
     * @note[short] MacOS (ARM): 0x47e18c
     * @note[short] MacOS (Intel): 0x522290
     * @note[short] Windows: 0x147b90
     * @note[short] Android
     */
    void makeTimeStamp(char const* p0);
    
private:
    [[deprecated("GameLevelManager::markItemAsLiked not implemented")]]
    /**
     * @note[short] Android
     */
    void markItemAsLiked(LikeItemType p0, int p1, bool p2, int p3);
public:

    /**
     * @note[short] Windows: 0x151510
     * @note[short] Android
     */
    void markLevelAsDownloaded(int p0);
    
private:
    [[deprecated("GameLevelManager::markLevelAsRatedDemon not implemented")]]
    /**
     * @note[short] Android
     */
    void markLevelAsRatedDemon(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::markLevelAsRatedStars not implemented")]]
    /**
     * @note[short] Android
     */
    void markLevelAsRatedStars(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::markLevelAsReported not implemented")]]
    /**
     * @note[short] Android
     */
    void markLevelAsReported(int p0);
public:

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void markListAsDownloaded(int id);
    
private:
    [[deprecated("GameLevelManager::messageWasRemoved not implemented")]]
    /**
     * @note[short] Android
     */
    void messageWasRemoved(int p0, bool p1);
public:
    
private:
    [[deprecated("GameLevelManager::onAcceptFriendRequestCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onAcceptFriendRequestCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onBanUserCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onBanUserCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onBlockUserCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onBlockUserCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onDeleteCommentCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onDeleteCommentCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onDeleteFriendRequestCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onDeleteFriendRequestCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onDeleteServerLevelCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onDeleteServerLevelCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onDeleteServerLevelListCompleted not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x514f40
     * @note[short] Android
     */
    void onDeleteServerLevelListCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onDeleteUserMessagesCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onDeleteUserMessagesCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onDownloadLevelCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onDownloadLevelCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onDownloadUserMessageCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onDownloadUserMessageCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onGetAccountCommentsCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onGetAccountCommentsCompleted(gd::string response, gd::string tag);
public:

    /**
     * @note[short] Windows: 0x15d510
     * @note[short] Android
     */
    void onGetFriendRequestsCompleted(gd::string response, gd::string tag);
    
private:
    [[deprecated("GameLevelManager::onGetGauntletsCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onGetGauntletsCompleted(gd::string response, gd::string tag);
public:

    /**
     * @note[short] MacOS (ARM): 0x46f5b0
     * @note[short] MacOS (Intel): 0x510b00
     * @note[short] Windows: 0x164f20
     * @note[short] Android
     */
    void onGetGJChallengesCompleted(gd::string response, gd::string tag);

    /**
     * @note[short] MacOS (ARM): 0x470324
     * @note[short] MacOS (Intel): 0x512730
     * @note[short] Windows: 0x1663a0
     * @note[short] Android
     */
    void onGetGJDailyLevelStateCompleted(gd::string response, gd::string tag);
    
private:
    [[deprecated("GameLevelManager::onGetGJRewardsCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onGetGJRewardsCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onGetGJSecretRewardCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn onGetGJSecretRewardCompleted(gd::string p0, gd::string p1);
public:
    
private:
    [[deprecated("GameLevelManager::onGetGJUserInfoCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onGetGJUserInfoCompleted(gd::string response, gd::string tag);
public:

    /**
     * @note[short] MacOS (ARM): 0x468fa0
     * @note[short] MacOS (Intel): 0x50a9d0
     * @note[short] Windows: 0x155b80
     * @note[short] Android
     */
    void onGetLeaderboardScoresCompleted(gd::string response, gd::string tag);
    
private:
    [[deprecated("GameLevelManager::onGetLevelCommentsCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onGetLevelCommentsCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onGetLevelLeaderboardCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onGetLevelLeaderboardCompleted(gd::string response, gd::string tag);
public:

    /**
     * @note[short] MacOS (Intel): 0x5145d0
     * @note[short] Windows: 0x14e970
     * @note[short] Android
     */
    void onGetLevelListsCompleted(gd::string response, gd::string tag);
    
private:
    [[deprecated("GameLevelManager::onGetLevelSaveDataCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onGetLevelSaveDataCompleted(gd::string response, gd::string tag);
public:

    /**
     * @note[short] Windows: 0x14d680
     * @note[short] Android
     */
    void onGetMapPacksCompleted(gd::string response, gd::string tag);
    
private:
    [[deprecated("GameLevelManager::onGetNewsCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onGetNewsCompleted(gd::string response, gd::string tag);
public:

    /**
     * @note[short] MacOS (ARM): 0x46708c
     * @note[short] MacOS (Intel): 0x508660
     * @note[short] Windows: 0x14c3d0
     * @note[short] Android
     */
    void onGetOnlineLevelsCompleted(gd::string response, gd::string tag);
    
private:
    [[deprecated("GameLevelManager::onGetTopArtistsCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onGetTopArtistsCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onGetUserListCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onGetUserListCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onGetUserMessagesCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onGetUserMessagesCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onGetUsersCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onGetUsersCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onLikeItemCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onLikeItemCompleted(gd::string response, gd::string tag);
public:

    /**
     * @note[short] MacOS (ARM): 0x464438
     * @note[short] MacOS (Intel): 0x504de0
     * @note[short] Windows: 0x140d10
     * @note[short] Android
     */
    void onProcessHttpRequestCompleted(cocos2d::extension::CCHttpClient* p0, cocos2d::extension::CCHttpResponse* p1);
    
private:
    [[deprecated("GameLevelManager::onRateDemonCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onRateDemonCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onRateStarsCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onRateStarsCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onReadFriendRequestCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onReadFriendRequestCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onRemoveFriendCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onRemoveFriendCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onReportLevelCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onReportLevelCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onRequestUserAccessCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onRequestUserAccessCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onRestoreItemsCompleted not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x46acc0
     * @note[short] MacOS (Intel): 0x50cc20
     * @note[short] Android
     */
    void onRestoreItemsCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onSetLevelFeaturedCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onSetLevelFeaturedCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onSetLevelStarsCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onSetLevelStarsCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onSubmitUserInfoCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onSubmitUserInfoCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onSuggestLevelStarsCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onSuggestLevelStarsCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onUnblockUserCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onUnblockUserCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onUpdateDescriptionCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onUpdateDescriptionCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onUpdateLevelCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onUpdateLevelCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onUpdateUserScoreCompleted not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x50a6c0
     * @note[short] Android
     */
    void onUpdateUserScoreCompleted(gd::string response, gd::string tag);
public:

    /**
     * @note[short] MacOS (ARM): 0x469db8
     * @note[short] MacOS (Intel): 0x50b830
     * @note[short] Windows: 0x15bde0
     * @note[short] Android
     */
    void onUploadCommentCompleted(gd::string response, gd::string tag);
    
private:
    [[deprecated("GameLevelManager::onUploadFriendRequestCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onUploadFriendRequestCompleted(gd::string response, gd::string tag);
public:

    /**
     * @note[short] MacOS (Intel): 0x5083c0
     * @note[short] Windows: 0x14b1a0
     * @note[short] Android
     */
    void onUploadLevelCompleted(gd::string response, gd::string tag);
    
private:
    [[deprecated("GameLevelManager::onUploadLevelListCompleted not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x514d50
     * @note[short] Android
     */
    void onUploadLevelListCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::onUploadUserMessageCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onUploadUserMessageCompleted(gd::string response, gd::string tag);
public:
    
private:
    [[deprecated("GameLevelManager::pageFromCommentKey not implemented")]]
    /**
     * @note[short] Android
     */
    int pageFromCommentKey(char const* p0);
public:
    
private:
    [[deprecated("GameLevelManager::parseRestoreData not implemented")]]
    /**
     * @note[short] Android
     */
    void parseRestoreData(gd::string p0);
public:
    
private:
    [[deprecated("GameLevelManager::performNetworkTest not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4642b0
     * @note[short] MacOS (Intel): 0x504c40
     * @note[short] Android
     */
    void performNetworkTest();
public:

    /**
     * @note[short] MacOS (ARM): 0x464634
     * @note[short] MacOS (Intel): 0x504fa0
     * @note[short] Windows: 0x140b70
     * @note[short] Android
     */
    void ProcessHttpRequest(gd::string endpoint, gd::string params, gd::string tag, GJHttpType httpType);

    /**
     * @note[short] MacOS (ARM): 0x489224
     * @note[short] MacOS (Intel): 0x52e460
     * @note[short] Windows: 0x150350
     * @note[short] Android
     */
    void processOnDownloadLevelCompleted(gd::string response, gd::string tag, bool p2);

    /**
     * @note[short] MacOS (Intel): 0x523900
     * @note[short] Windows: 0x148330
     * @note[short] Android
     */
    void purgeUnusedLevels();
    
private:
    [[deprecated("GameLevelManager::rateDemon not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x48c020
     * @note[short] MacOS (Intel): 0x531730
     * @note[short] Android
     */
    void rateDemon(int p0, int p1, bool p2);
public:
    
private:
    [[deprecated("GameLevelManager::rateStars not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x48a7c8
     * @note[short] MacOS (Intel): 0x52fd00
     * @note[short] Android
     */
    void rateStars(int p0, int p1);
public:
    
private:
    [[deprecated("GameLevelManager::readFriendRequest not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x498000
     * @note[short] MacOS (Intel): 0x53edd0
     * @note[short] Android
     */
    void readFriendRequest(int p0);
public:

    /**
     * @note[short] Windows: 0x167f10
     * @note[short] Android
     */
    TodoReturn removeDelimiterChars(gd::string p0, bool p1);
    
private:
    [[deprecated("GameLevelManager::removeDLFromActive not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x47e944
     * @note[short] MacOS (Intel): 0x5229d0
     * @note[short] Android
     */
    void removeDLFromActive(char const* p0);
public:
    
private:
    [[deprecated("GameLevelManager::removeFriend not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x498490
     * @note[short] MacOS (Intel): 0x53f2b0
     * @note[short] Android
     */
    void removeFriend(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::removeLevelDownloadedKeysFromDict not implemented")]]
    /**
     * @note[short] Android
     */
    void removeLevelDownloadedKeysFromDict(cocos2d::CCDictionary* p0);
public:
    
private:
    [[deprecated("GameLevelManager::removeUserFromList not implemented")]]
    /**
     * @note[short] Android
     */
    void removeUserFromList(int p0, UserListType p1);
public:
    
private:
    [[deprecated("GameLevelManager::reportLevel not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x49cd30
     * @note[short] MacOS (Intel): 0x543d30
     * @note[short] Android
     */
    void reportLevel(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::requestUserAccess not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x49ab48
     * @note[short] MacOS (Intel): 0x5419f0
     * @note[short] Android
     */
    void requestUserAccess();
public:

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void resetAccountComments(int accountID);
    
private:
    [[deprecated("GameLevelManager::resetAllTimers not implemented")]]
    /**
     * @note[short] Android
     */
    void resetAllTimers();
public:
    
private:
    [[deprecated("GameLevelManager::resetCommentTimersForAccountID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetCommentTimersForAccountID(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x495b6c
     * @note[short] MacOS (Intel): 0x53c490
     * @note[short] Windows: 0x15c770
     * @note[short] Android
     */
    void resetCommentTimersForLevelID(int p0, CommentKeyType p1);
    
private:
    [[deprecated("GameLevelManager::resetDailyLevelState not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x49c920
     * @note[short] MacOS (Intel): 0x543920
     * @note[short] Android
     */
    void resetDailyLevelState(GJTimedLevelType p0);
public:
    
private:
    [[deprecated("GameLevelManager::resetGauntlets not implemented")]]
    /**
     * @note[short] Android
     */
    void resetGauntlets();
public:

    /**
     * @note[short] MacOS (Intel): 0x536fc0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void resetStoredUserInfo(int id);
    
private:
    [[deprecated("GameLevelManager::resetStoredUserList not implemented")]]
    /**
     * @note[short] Android
     */
    void resetStoredUserList(UserListType p0);
public:
    
private:
    [[deprecated("GameLevelManager::resetTimerForKey not implemented")]]
    /**
     * @note[short] Android
     */
    void resetTimerForKey(char const* p0);
public:
    
private:
    [[deprecated("GameLevelManager::restoreItems not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x49ca38
     * @note[short] MacOS (Intel): 0x543a30
     * @note[short] Android
     */
    void restoreItems();
public:

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void saveFetchedLevelLists(cocos2d::CCArray* lists);

    /**
     * @note[short] MacOS (ARM): 0x477ed0
     * @note[short] MacOS (Intel): 0x51b540
     * @note[short] Windows: 0x144960
     * @note[short] Android
     */
    void saveFetchedLevels(cocos2d::CCArray* p0);
    
private:
    [[deprecated("GameLevelManager::saveFetchedMapPacks not implemented")]]
    /**
     * @note[short] Android
     */
    void saveFetchedMapPacks(cocos2d::CCArray* p0);
public:
    
private:
    [[deprecated("GameLevelManager::saveGauntlet not implemented")]]
    /**
     * @note[short] Android
     */
    void saveGauntlet(GJMapPack* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x47d688
     * @note[short] MacOS (Intel): 0x521650
     * @note[short] Windows: 0x146d40
     * @note[short] Android
     */
    void saveLevel(GJGameLevel* p0);

    /**
     * @note[short] Windows: 0x14ee60
     * @note[short] Android
     */
    void saveLevelList(GJLevelList* p0);
    
private:
    [[deprecated("GameLevelManager::saveLocalScore not implemented")]]
    /**
     * @note[short] Android
     */
    void saveLocalScore(int p0, int p1, int p2);
public:
    
private:
    [[deprecated("GameLevelManager::saveMapPack not implemented")]]
    /**
     * @note[short] Android
     */
    void saveMapPack(GJMapPack* p0);
public:
    
private:
    [[deprecated("GameLevelManager::setActiveSmartTemplate not implemented")]]
    /**
     * @note[short] Android
     */
    void setActiveSmartTemplate(GJSmartTemplate* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x49d96c
     * @note[short] MacOS (Intel): 0x544920
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void setBoolForKey(bool value, char const* key);
    
private:
    [[deprecated("GameLevelManager::setDiffVal not implemented")]]
    /**
     * @note[short] Android
     */
    void setDiffVal(int p0, bool p1);
public:
    
private:
    [[deprecated("GameLevelManager::setFolderName not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x48055c
     * @note[short] MacOS (Intel): 0x524790
     * @note[short] Android
     */
    void setFolderName(int p0, gd::string p1, bool p2);
public:

    /**
     * @note[short] MacOS (ARM): 0x49d758
     * @note[short] MacOS (Intel): 0x544720
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void setIntForKey(int value, char const* key);
    
private:
    [[deprecated("GameLevelManager::setLenVal not implemented")]]
    /**
     * @note[short] Android
     */
    void setLenVal(int p0, bool p1);
public:
    
private:
    [[deprecated("GameLevelManager::setLevelFeatured not implemented")]]
    /**
     * @note[short] Android
     */
    void setLevelFeatured(int p0, int p1, bool p2);
public:
    
private:
    [[deprecated("GameLevelManager::setLevelStars not implemented")]]
    /**
     * @note[short] Android
     */
    void setLevelStars(int p0, int p1, bool p2);
public:
    
private:
    [[deprecated("GameLevelManager::specialFromLikeKey not implemented")]]
    /**
     * @note[short] Android
     */
    int specialFromLikeKey(char const* p0);
public:
    
private:
    [[deprecated("GameLevelManager::storeCommentsResult not implemented")]]
    /**
     * @note[short] Android
     */
    void storeCommentsResult(cocos2d::CCArray* p0, gd::string p1, char const* p2);
public:
    
private:
    [[deprecated("GameLevelManager::storeDailyLevelState not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x543800
     * @note[short] Android
     */
    void storeDailyLevelState(int p0, int p1, GJTimedLevelType p2);
public:
    
private:
    [[deprecated("GameLevelManager::storeFriendRequest not implemented")]]
    /**
     * @note[short] Android
     */
    void storeFriendRequest(GJFriendRequest* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x47dec0
     * @note[short] MacOS (Intel): 0x521fe0
     * @note[short] Windows: 0x147570
     * @note[short] Android
     */
    void storeSearchResult(cocos2d::CCArray* levels, gd::string pageInfo, char const* searchKey);
    
private:
    [[deprecated("GameLevelManager::storeUserInfo not implemented")]]
    /**
     * @note[short] Android
     */
    void storeUserInfo(GJUserScore* p0);
public:
    
private:
    [[deprecated("GameLevelManager::storeUserMessage not implemented")]]
    /**
     * @note[short] Android
     */
    void storeUserMessage(GJUserMessage* p0);
public:
    
private:
    [[deprecated("GameLevelManager::storeUserMessageReply not implemented")]]
    /**
     * @note[short] Android
     */
    void storeUserMessageReply(int p0, GJUserMessage* p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x4754d4
     * @note[short] MacOS (Intel): 0x5181b0
     * @note[short] Windows: 0x143ca0
     * @note[short] Android
     */
    void storeUserName(int userID, int accountID, gd::string userName);
    
private:
    [[deprecated("GameLevelManager::storeUserNames not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x474d1c
     * @note[short] MacOS (Intel): 0x5179d0
     * @note[short] Android
     */
    void storeUserNames(gd::string usernameString);
public:
    
private:
    [[deprecated("GameLevelManager::submitUserInfo not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x48ddc8
     * @note[short] MacOS (Intel): 0x533e90
     * @note[short] Android
     */
    void submitUserInfo();
public:
    
private:
    [[deprecated("GameLevelManager::suggestLevelStars not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x48b9ec
     * @note[short] MacOS (Intel): 0x531110
     * @note[short] Android
     */
    void suggestLevelStars(int p0, int p1, int p2);
public:

    /**
     * @note[short] MacOS (ARM): 0x475900
     * @note[short] MacOS (Intel): 0x5185d0
     * @note[short] Windows: 0x144000
     * @note[short] Android
     */
    gd::string tryGetUsername(int p0);
    
private:
    [[deprecated("GameLevelManager::typeFromCommentKey not implemented")]]
    /**
     * @note[short] Android
     */
    CommentType typeFromCommentKey(char const* p0);
public:
    
private:
    [[deprecated("GameLevelManager::typeFromLikeKey not implemented")]]
    /**
     * @note[short] Android
     */
    LikeItemType typeFromLikeKey(char const* p0);
public:
    
private:
    [[deprecated("GameLevelManager::unblockUser not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x498f7c
     * @note[short] MacOS (Intel): 0x53fdd0
     * @note[short] Android
     */
    void unblockUser(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::unfollowUser not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x5240e0
     * @note[short] Android
     */
    void unfollowUser(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::updateDescription not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x499750
     * @note[short] MacOS (Intel): 0x5405d0
     * @note[short] Android
     */
    void updateDescription(int p0, gd::string p1);
public:
    
private:
    [[deprecated("GameLevelManager::updateLevel not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x48a478
     * @note[short] MacOS (Intel): 0x52f9a0
     * @note[short] Android
     */
    void updateLevel(GJGameLevel* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x47b2b0
     * @note[short] Windows: 0x145680
     * @note[short] Android
     */
    void updateLevelOrders();

    /**
     * @note[short] MacOS (ARM): 0x475db4
     * @note[short] Windows: 0x144380
     * @note[short] Android
     */
    void updateLevelRewards(GJGameLevel* p0);

    /**
     * @note[short] MacOS (ARM): 0x487790
     * @note[short] MacOS (Intel): 0x52c630
     * @note[short] Windows: 0x14ef40
     * @note[short] Android
     */
    void updateSavedLevelList(GJLevelList* p0);
    
private:
    [[deprecated("GameLevelManager::updateUsernames not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x523ed0
     * @note[short] Android
     */
    void updateUsernames();
public:

    /**
     * @note[short] MacOS (ARM): 0x48c508
     * @note[short] MacOS (Intel): 0x531c80
     * @note[short] Windows: 0x153790
     * @note[short] Android
     */
    void updateUserScore();
    
private:
    [[deprecated("GameLevelManager::uploadAccountComment not implemented")]]
    /**
     * @note[short] Android
     */
    void uploadAccountComment(gd::string p0);
public:
    
private:
    [[deprecated("GameLevelManager::uploadComment not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x494bec
     * @note[short] MacOS (Intel): 0x53b480
     * @note[short] Android
     */
    void uploadComment(gd::string p0, CommentType p1, int p2, int p3);
public:
    
private:
    [[deprecated("GameLevelManager::uploadFriendRequest not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x496bfc
     * @note[short] MacOS (Intel): 0x53d870
     * @note[short] Android
     */
    void uploadFriendRequest(int p0, gd::string p1);
public:
    
private:
    [[deprecated("GameLevelManager::uploadLevel not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x482908
     * @note[short] MacOS (Intel): 0x526fe0
     * @note[short] Android
     */
    void uploadLevel(GJGameLevel* p0);
public:
    
private:
    [[deprecated("GameLevelManager::uploadLevelComment not implemented")]]
    /**
     * @note[short] Android
     */
    void uploadLevelComment(int p0, gd::string p1, int p2);
public:
    
private:
    [[deprecated("GameLevelManager::uploadLevelList not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x486180
     * @note[short] MacOS (Intel): 0x52aed0
     * @note[short] Android
     */
    void uploadLevelList(GJLevelList* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x491cac
     * @note[short] MacOS (Intel): 0x538390
     * @note[short] Windows: 0x1588b0
     * @note[short] Android
     */
    void uploadUserMessage(int p0, gd::string p1, gd::string p2);
    
private:
    [[deprecated("GameLevelManager::userIDForAccountID not implemented")]]
    /**
     * @note[short] Android
     */
    int userIDForAccountID(int p0);
public:
    
private:
    [[deprecated("GameLevelManager::userInfoForAccountID not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x518ac0
     * @note[short] Android
     */
    GJUserScore* userInfoForAccountID(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x475748
     * @note[short] MacOS (Intel): 0x518420
     * @note[short] Windows: 0x143e80
     * @note[short] Android
     */
    gd::string userNameForUserID(int p0);
    
private:
    [[deprecated("GameLevelManager::verifyContainerOnlyHasLevels not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn verifyContainerOnlyHasLevels(cocos2d::CCDictionary* p0);
public:
    
private:
    [[deprecated("GameLevelManager::verifyLevelState not implemented")]]
    /**
     * @note[short] Android
     */
    void verifyLevelState(GJGameLevel* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x4848d4
     * @note[short] MacOS (Intel): 0x529260
     * @note[short] Windows: 0x14b8b0
     * @note[short] Android
     */
    gd::string writeSpecialFilters(GJSearchObject* p0);
    gd::set<gd::string> m_queuedLists;
    cocos2d::CCDictionary* m_mainLevels;
    cocos2d::CCDictionary* m_searchFilters;
    cocos2d::CCDictionary* m_onlineLevels;
    cocos2d::CCDictionary* m_unkDict;
    cocos2d::CCDictionary* m_followedCreators;
    cocos2d::CCDictionary* m_favoriteLists;
    cocos2d::CCDictionary* m_downloadedLevels;
    cocos2d::CCDictionary* m_likedLevels;
    cocos2d::CCDictionary* m_ratedLevels;
    cocos2d::CCDictionary* m_ratedDemons;
    cocos2d::CCDictionary* m_reportedLevels;
    cocos2d::CCDictionary* m_onlineFolders;
    cocos2d::CCDictionary* m_localLevelsFolders;
    cocos2d::CCDictionary* m_dailyLevels;
    int m_dailyTimeLeft;
    int m_dailyID;
    int m_dailyIDUnk;
    int m_weeklyTimeLeft;
    int m_weeklyID;
    int m_weeklyIDUnk;
    int m_eventTimeLeft;
    int m_eventID;
    int m_eventIDUnk;
    cocos2d::CCDictionary* m_gauntletLevels;
    gd::map<gd::string, bool> m_availableFilters;
    cocos2d::CCDictionary* m_timerDict;
    cocos2d::CCDictionary* m_knownUsers;
    cocos2d::CCDictionary* m_accountIDtoUserIDDict;
    cocos2d::CCDictionary* m_userIDtoAccountIDDict;
    cocos2d::CCDictionary* m_storedLevels;
    cocos2d::CCDictionary* m_pageInfo;
    cocos2d::CCDictionary* m_unkDict20;
    cocos2d::CCDictionary* m_savedPacks;
    cocos2d::CCDictionary* m_savedGauntlets;
    cocos2d::CCDictionary* m_downloadObjects;
    cocos2d::CCDictionary* m_friendReqAndUserBlocks;
    cocos2d::CCDictionary* m_storedUserInfo;
    cocos2d::CCDictionary* m_friendRequests;
    cocos2d::CCDictionary* m_userMessages;
    cocos2d::CCDictionary* m_userReplies;
    gd::string m_searchSceneStr;
    gd::string m_searchType9Str;
    LeaderboardState m_leaderboardState;
    bool m_unkEditLevelLayerOnBack;
    LevelManagerDelegate* m_levelManagerDelegate;
    LevelDownloadDelegate* m_levelDownloadDelegate;
    LevelCommentDelegate* m_levelCommentDelegate;
    CommentUploadDelegate* m_commentUploadDelegate;
    LevelUploadDelegate* m_levelUploadDelegate;
    ListUploadDelegate* m_listUploadDelegate;
    LevelUpdateDelegate* m_levelUpdateDelegate;
    LeaderboardManagerDelegate* m_leaderboardManagerDelegate;
    LevelDeleteDelegate* m_levelDeleteDelegate;
    LevelListDeleteDelegate* m_levelListDeleteDelegate;
    UserInfoDelegate* m_userInfoDelegate;
    UploadActionDelegate* m_uploadActionDelegate;
    UserListDelegate* m_userListDelegate;
    FriendRequestDelegate* m_friendRequestDelegate;
    MessageListDelegate* m_messageListDelegate;
    DownloadMessageDelegate* m_downloadMessageDelegate;
    UploadMessageDelegate* m_uploadMessageDelegate;
    GJRewardDelegate* m_GJRewardDelegate;
    GJOnlineRewardDelegate* m_GJOnlineRewardDelegate;
    GJChallengeDelegate* m_GJChallengeDelegate;
    GJDailyLevelDelegate* m_GJDailyLevelDelegate;
    OnlineListDelegate* m_onlineListDelegate;
    int m_unkDownload;
    int m_mapPack;
    gd::string m_unkStr3;
    cocos2d::CCString* m_unkStr4;
    cocos2d::CCArray* m_smartTemplates;
    GJSmartTemplate* m_smartTemplate;
    bool m_testedNetwork;
};
