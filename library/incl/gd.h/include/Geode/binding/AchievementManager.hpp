#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class AchievementManager : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "AchievementManager";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(AchievementManager, cocos2d::CCNode)

    /**
     * @note[short] MacOS (ARM): 0x633e04
     * @note[short] MacOS (Intel): 0x715690
     * @note[short] Windows: 0x7da0
     * @note[short] Android
     */
    static AchievementManager* sharedState();

    /**
     * @note[short] MacOS (ARM): 0x633ef4
     * @note[short] MacOS (Intel): 0x7157a0
     * @note[short] Windows: 0x7e60
     * @note[short] iOS: 0xb9ecc
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (ARM): 0x682554
     * @note[short] MacOS (Intel): 0x76ef60
     * @note[short] Windows: 0x3a1c0
     * @note[short] Android
     */
    gd::string achievementForUnlock(int p0, UnlockType p1);

    /**
     * @note[short] Windows: 0x7ef0
     * @note[short] Android
     */
    void addAchievement(gd::string p0, gd::string p1, gd::string p2, gd::string p3, gd::string p4, int p5);

    /**
     * @note[short] MacOS (ARM): 0x633f7c
     * @note[short] MacOS (Intel): 0x715830
     * @note[short] Windows: 0x8410
     * @note[short] Android
     */
    void addManualAchievements();
    
private:
    [[deprecated("AchievementManager::areAchievementsEarned not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn areAchievementsEarned(cocos2d::CCArray* p0);
public:
    
private:
    [[deprecated("AchievementManager::checkAchFromUnlock not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn checkAchFromUnlock(char const* p0);
public:
    
private:
    [[deprecated("AchievementManager::dataLoaded not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x76ea20
     * @note[short] Android
     */
    void dataLoaded(DS_Dictionary* p0);
public:
    
private:
    [[deprecated("AchievementManager::encodeDataTo not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x76ea90
     * @note[short] Android
     */
    void encodeDataTo(DS_Dictionary* p0);
public:
    
private:
    [[deprecated("AchievementManager::firstSetup not implemented")]]
    /**
     * @note[short] Android
     */
    void firstSetup();
public:
    
private:
    [[deprecated("AchievementManager::getAchievementRewardDict not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getAchievementRewardDict();
public:

    /**
     * @note[short] MacOS (Intel): 0x76ed50
     * @note[short] Windows: 0x39d70
     * @note[short] Android
     */
    cocos2d::CCDictionary* getAchievementsWithID(char const* p0);
    
private:
    [[deprecated("AchievementManager::getAllAchievements not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCArray* getAllAchievements();
public:
    
private:
    [[deprecated("AchievementManager::getAllAchievementsSorted not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCArray* getAllAchievementsSorted(bool p0);
public:
    
private:
    [[deprecated("AchievementManager::isAchievementAvailable not implemented")]]
    /**
     * @note[short] Android
     */
    bool isAchievementAvailable(gd::string p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x682198
     * @note[short] MacOS (Intel): 0x76ec00
     * @note[short] Windows: 0x39a70
     * @note[short] Android
     */
    bool isAchievementEarned(char const* ach);

    /**
     * @note[short] MacOS (ARM): 0x68248c
     * @note[short] MacOS (Intel): 0x76eec0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    int limitForAchievement(gd::string id);
    
private:
    [[deprecated("AchievementManager::notifyAchievement not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn notifyAchievement(char const* p0, char const* p1, char const* p2);
public:
    
private:
    [[deprecated("AchievementManager::notifyAchievementWithID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn notifyAchievementWithID(char const* p0);
public:
    
private:
    [[deprecated("AchievementManager::percentageForCount not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn percentageForCount(int p0, int p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x6821b4
     * @note[short] MacOS (Intel): 0x76ec20
     * @note[short] Windows: 0x39a90
     * @note[short] Android
     */
    int percentForAchievement(char const* p0);
    
private:
    [[deprecated("AchievementManager::reportAchievementWithID not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x682d28
     * @note[short] MacOS (Intel): 0x76f830
     * @note[short] Android
     */
    void reportAchievementWithID(char const* p0, int p1, bool p2);
public:
    
private:
    [[deprecated("AchievementManager::reportPlatformAchievementWithID not implemented")]]
    /**
     * @note[short] Android
     */
    void reportPlatformAchievementWithID(char const* p0, int p1);
public:
    
private:
    [[deprecated("AchievementManager::resetAchievement not implemented")]]
    /**
     * @note[short] Android
     */
    void resetAchievement(char const* p0);
public:
    
private:
    [[deprecated("AchievementManager::resetAchievements not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetAchievements();
public:
    
private:
    [[deprecated("AchievementManager::setup not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn setup();
public:
    
private:
    [[deprecated("AchievementManager::storeAchievementUnlocks not implemented")]]
    /**
     * @note[short] Android
     */
    void storeAchievementUnlocks();
public:
    cocos2d::CCArray* m_allAchievements;
    cocos2d::CCDictionary* m_platformAchievements;
    cocos2d::CCDictionary* m_achievementUnlocks;
    void* m_unkPtrUnused;
    cocos2d::CCDictionary* m_reportedAchievements;
    bool m_dontNotify;
    cocos2d::CCArray* m_allAchievementsSorted;
    int m_order;
    cocos2d::CCDictionary* m_unAchieved;
};
