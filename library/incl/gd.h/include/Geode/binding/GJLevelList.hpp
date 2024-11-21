#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJLevelList : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "GJLevelList";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJLevelList, cocos2d::CCNode)

    /**
     * @note[short] MacOS (ARM): 0x474a98
     * @note[short] MacOS (Intel): 0x517750
     * @note[short] Windows: 0x173760
     * @note[short] Android
     */
    static GJLevelList* create();

    /**
     * @note[short] MacOS (ARM): 0x478394
     * @note[short] MacOS (Intel): 0x51bac0
     * @note[short] Windows: 0x172e70
     * @note[short] Android
     */
    static GJLevelList* create(cocos2d::CCDictionary* p0);

    /**
     * @note[short] MacOS (ARM): 0x4a5298
     * @note[short] MacOS (Intel): 0x54d230
     * @note[short] Windows: 0x174ff0
     * @note[short] iOS: 0xb5668
     * @note[short] Android
     */
    virtual void encodeWithCoder(DS_Dictionary* p0);
    
private:
    [[deprecated("GJLevelList::canEncode not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4a54d0
     * @note[short] MacOS (Intel): 0x54d4a0
     * @note[short] iOS: 0xb58a0
     * @note[short] Android
     */
    virtual bool canEncode();
public:
    
private:
    [[deprecated("GJLevelList::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4a3784
     * @note[short] MacOS (Intel): 0x54b420
     * @note[short] iOS: 0xb42e0
     * @note[short] Android
     */
    virtual bool init();
public:

    /**
     * @note[short] Windows: 0x173ee0
     * @note[short] Android
     */
    void addLevelToList(GJGameLevel* level);
    
private:
    [[deprecated("GJLevelList::completedLevels not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4a4a48
     * @note[short] MacOS (Intel): 0x54ca00
     * @note[short] Android
     */
    TodoReturn completedLevels();
public:
    
private:
    [[deprecated("GJLevelList::createWithCoder not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4a4f38
     * @note[short] Android
     */
    TodoReturn createWithCoder(DS_Dictionary* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x4a4f68
     * @note[short] MacOS (Intel): 0x54cef0
     * @note[short] Windows: 0x174cd0
     * @note[short] Android
     */
    void dataLoaded(DS_Dictionary* p0);
    
private:
    [[deprecated("GJLevelList::duplicateListLevels not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn duplicateListLevels(GJLevelList* p0);
public:
    
private:
    [[deprecated("GJLevelList::frameForListDifficulty not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4a54d8
     * @note[short] MacOS (Intel): 0x54d4b0
     * @note[short] Android
     */
    TodoReturn frameForListDifficulty(int p0, DifficultyIconType p1);
public:

    /**
     * @note[short] Windows: 0x174160
     * @note[short] Android
     */
    cocos2d::CCArray* getListLevelsArray(cocos2d::CCArray* p0);

    /**
     * @note[short] MacOS (ARM): 0x4a39d0
     * @note[short] MacOS (Intel): 0x54b670
     * @note[short] Windows: 0x173b80
     * @note[short] Android
     */
    gd::string getUnpackedDescription();
    
private:
    [[deprecated("GJLevelList::handleStatsConflict not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4a37fc
     * @note[short] MacOS (Intel): 0x54b4a0
     * @note[short] Android
     */
    void handleStatsConflict(GJLevelList* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x4a3814
     * @note[short] MacOS (Intel): 0x54b4c0
     * @note[short] Windows: 0x173970
     * @note[short] Android
     */
    bool hasMatchingLevels(GJLevelList* p0);
    
private:
    [[deprecated("GJLevelList::orderForLevel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn orderForLevel(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x487a60
     * @note[short] MacOS (Intel): 0x52ca10
     * @note[short] Windows: 0x173c40
     * @note[short] Android
     */
    TodoReturn parseListLevels(gd::string p0);
    
private:
    [[deprecated("GJLevelList::removeLevelFromList not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn removeLevelFromList(int p0);
public:

    /**
     * @note[short] Windows: 0x174070
     * @note[short] Android
     */
    void reorderLevel(int levelID, int newPosition);
    
private:
    [[deprecated("GJLevelList::reorderLevelStep not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn reorderLevelStep(int p0, bool p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x4a4aac
     * @note[short] MacOS (Intel): 0x54ca50
     * @note[short] Windows: 0x174900
     * @note[short] Android
     */
    void showListInfo();
    
private:
    [[deprecated("GJLevelList::totalLevels not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4a4a38
     * @note[short] MacOS (Intel): 0x54c9e0
     * @note[short] Android
     */
    TodoReturn totalLevels();
public:
    
private:
    [[deprecated("GJLevelList::updateLevelsString not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateLevelsString();
public:
    gd::vector<int> m_levels;
    int m_listID;
    int m_listVersion;
    int m_downloads;
    int m_likes;
    int m_difficulty;
    int m_accountID;
    int m_folder;
    int m_listRevision;
    int m_listOrder;
    int m_original;
    int m_diamonds;
    int m_levelsToClaim;
    bool m_isEditable;
    bool m_unlisted;
    bool m_friendsOnly;
    bool m_uploaded;
    bool m_favorite;
    bool m_featured;
    bool m_k100;
    gd::string m_creatorName;
    gd::string m_listName;
    gd::string m_unkString;
    gd::string m_levelsString;
    gd::string m_listDesc;
    int m_uploadDate;
    int m_updateDate;
    cocos2d::CCDictionary* m_levelsDict;
    GJLevelType m_listType;
    int m_M_ID;
};
