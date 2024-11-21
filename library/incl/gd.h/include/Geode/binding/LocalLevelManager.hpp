#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "GManager.hpp"

class LocalLevelManager : public GManager {
public:
    static constexpr auto CLASS_NAME = "LocalLevelManager";
    GEODE_CUSTOM_CONSTRUCTOR_GD(LocalLevelManager, GManager)
	inline static LocalLevelManager* get() {
        return LocalLevelManager::sharedState();
    }

    /**
     * @note[short] MacOS (ARM): 0x511bc0
     * @note[short] MacOS (Intel): 0x5df020
     * @note[short] Windows: 0x31b070
     * @note[short] Android
     */
    static LocalLevelManager* sharedState();

    /**
     * @note[short] MacOS (ARM): 0x511d40
     * @note[short] MacOS (Intel): 0x5df1c0
     * @note[short] Windows: 0x31b110
     * @note[short] iOS: 0x1c93c8
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (ARM): 0x512f54
     * @note[short] MacOS (Intel): 0x5e0610
     * @note[short] Windows: 0x31bae0
     * @note[short] iOS: 0x1c9fd8
     * @note[short] Android
     */
    virtual void encodeDataTo(DS_Dictionary* p0);

    /**
     * @note[short] MacOS (ARM): 0x512fac
     * @note[short] MacOS (Intel): 0x5e0670
     * @note[short] Windows: 0x31bb40
     * @note[short] iOS: 0x1ca030
     * @note[short] Android
     */
    virtual void dataLoaded(DS_Dictionary* p0);

    /**
     * @note[short] MacOS (ARM): 0x512ed8
     * @note[short] MacOS (Intel): 0x5e0580
     * @note[short] Windows: 0x31ba50
     * @note[short] iOS: 0x1c9fa0
     * @note[short] Android
     */
    virtual void firstLoad();

    /**
     * @note[short] Windows: 0x31b4e0
     * @note[short] Android
     */
    cocos2d::CCDictionary* getAllLevelsInDict();
    
private:
    [[deprecated("LocalLevelManager::getAllLevelsWithName not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getAllLevelsWithName(gd::string p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x512cdc
     * @note[short] MacOS (Intel): 0x5e0390
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    cocos2d::CCArray* getCreatedLevels(int folder);

    /**
     * @note[short] MacOS (ARM): 0x512e48
     * @note[short] MacOS (Intel): 0x5e04f0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    cocos2d::CCArray* getCreatedLists(int folder);
    
private:
    [[deprecated("LocalLevelManager::getLevelsInNameGroups not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCDictionary* getLevelsInNameGroups();
public:

    /**
     * @note[short] Windows: 0x31b3d0
     * @note[short] Android
     */
    gd::string getMainLevelString(int p0);
    
private:
    [[deprecated("LocalLevelManager::markLevelsAsUnmodified not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn markLevelsAsUnmodified();
public:
    
private:
    [[deprecated("LocalLevelManager::moveLevelToTop not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn moveLevelToTop(GJGameLevel* p0);
public:
    
private:
    [[deprecated("LocalLevelManager::reorderLevels not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn reorderLevels();
public:
    
private:
    [[deprecated("LocalLevelManager::reorderLists not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn reorderLists();
public:
    
private:
    [[deprecated("LocalLevelManager::tryLoadMainLevelString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x511d80
     * @note[short] MacOS (Intel): 0x5df200
     * @note[short] Android
     */
    TodoReturn tryLoadMainLevelString(int p0);
public:

    /**
     * @note[short] Windows: 0x31b9d0
     * @note[short] Android
     */
    TodoReturn updateLevelOrder();

    /**
     * @note[short] MacOS (ARM): 0x512700
     * @note[short] MacOS (Intel): 0x5dfd20
     * @note[short] Windows: 0x31b640
     * @note[short] Android
     */
    TodoReturn updateLevelRevision();
    
private:
    [[deprecated("LocalLevelManager::updateListOrder not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateListOrder();
public:
    cocos2d::CCArray* m_localLevels;
    cocos2d::CCArray* m_localLists;
    gd::unordered_map<int, gd::string> m_mainLevels;
};
