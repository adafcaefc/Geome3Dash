#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class LevelTools {
public:
    static constexpr auto CLASS_NAME = "LevelTools";

    /**
     * @note[short] Windows: 0x314320
     * @note[short] Android
     */
    static int artistForAudio(int p0);
    
private:
    [[deprecated("LevelTools::base64DecodeString not implemented")]]
    /**
     * @note[short] Android
     */
    static gd::string base64DecodeString(gd::string p0);
public:
    
private:
    [[deprecated("LevelTools::base64EncodeString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x44fd1c
     * @note[short] MacOS (Intel): 0x4ee880
     * @note[short] Android
     */
    static gd::string base64EncodeString(gd::string p0);
public:
    
private:
    [[deprecated("LevelTools::createStarPackDict not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x44fd8c
     * @note[short] MacOS (Intel): 0x4ee920
     * @note[short] Android
     */
    static cocos2d::CCDictionary* createStarPackDict();
public:

    /**
     * @note[short] MacOS (ARM): 0x44df44
     * @note[short] MacOS (Intel): 0x4ec970
     * @note[short] Windows: 0x316430
     * @note[short] Android
     */
    static gd::string fbURLForArtist(int p0);
    
private:
    [[deprecated("LevelTools::getAudioBPM not implemented")]]
    /**
     * @note[short] Android
     */
    static int getAudioBPM(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x44ca9c
     * @note[short] MacOS (Intel): 0x4eb120
     * @note[short] Windows: 0x313750
     * @note[short] Android
     */
    static gd::string getAudioFileName(int p0);

    /**
     * @note[short] MacOS (ARM): 0x44e26c
     * @note[short] MacOS (Intel): 0x4ecd10
     * @note[short] Windows: 0x316950
     * @note[short] Android
     */
    static gd::string getAudioString(int p0);

    /**
     * @note[short] MacOS (ARM): 0x44c364
     * @note[short] MacOS (Intel): 0x4eab80
     * @note[short] Windows: 0x312bd0
     * @note[short] Android
     */
    static gd::string getAudioTitle(int p0);
    
private:
    [[deprecated("LevelTools::getLastGameplayReversed not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn getLastGameplayReversed();
public:
    
private:
    [[deprecated("LevelTools::getLastGameplayRotated not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn getLastGameplayRotated();
public:
    
private:
    [[deprecated("LevelTools::getLastTimewarp not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn getLastTimewarp();
public:

    /**
     * @note[short] MacOS (ARM): 0x44a514
     * @note[short] MacOS (Intel): 0x4e8620
     * @note[short] Windows: 0x310320
     * @note[short] Android
     */
    static GJGameLevel* getLevel(int p0, bool p1);
    
private:
    [[deprecated("LevelTools::getLevelList not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x44a138
     * @note[short] MacOS (Intel): 0x4e82b0
     * @note[short] Android
     */
    static gd::unordered_set<int> getLevelList();
public:

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static SongInfoObject* getSongObject(int id);
    
private:
    [[deprecated("LevelTools::moveTriggerObjectsToArray not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn moveTriggerObjectsToArray(cocos2d::CCArray* p0, cocos2d::CCDictionary* p1, int p2);
public:

    /**
     * @note[short] MacOS (ARM): 0x44d12c
     * @note[short] Windows: 0x3143f0
     * @note[short] Android
     */
    static gd::string nameForArtist(int p0);

    /**
     * @note[short] MacOS (ARM): 0x44d960
     * @note[short] MacOS (Intel): 0x4ec2c0
     * @note[short] Windows: 0x315a10
     * @note[short] Android
     */
    static gd::string ngURLForArtist(int p0);
    
private:
    [[deprecated("LevelTools::offsetBPMForTrack not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn offsetBPMForTrack(int p0);
public:
    
private:
    [[deprecated("LevelTools::posForTime not implemented")]]
    /**
     * @note[short] Android
     */
    static cocos2d::CCPoint posForTime(float time, cocos2d::CCArray* p1, int p2, bool p3, int& p4);
public:

    /**
     * @note[short] Windows: 0x317ea0
     * @note[short] Android
     */
    static cocos2d::CCPoint posForTimeInternal(float time, cocos2d::CCArray* gameObjects, int speedmodValue, bool disabledSpeedmod, bool p4, bool p5, int& p6, int p7);
    
private:
    [[deprecated("LevelTools::sortChannelOrderObjects not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn sortChannelOrderObjects(cocos2d::CCArray* p0, cocos2d::CCDictionary* p1, bool p2);
public:
    
private:
    [[deprecated("LevelTools::sortSpeedObjects not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x66d20
     * @note[short] Android
     */
    static TodoReturn sortSpeedObjects(cocos2d::CCArray* p0, GJBaseGameLayer* p1);
public:
    
private:
    [[deprecated("LevelTools::timeForPos not implemented")]]
    /**
     * @note[short] Android
     */
    static float timeForPos(cocos2d::CCPoint p0, cocos2d::CCArray* p1, int p2, int p3, int p4, bool p5, bool p6, bool p7, bool p8, int p9);
public:
    
private:
    [[deprecated("LevelTools::toggleDebugLogging not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn toggleDebugLogging(bool p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x44d310
     * @note[short] MacOS (Intel): 0x4eb7f0
     * @note[short] Windows: 0x3146f0
     * @note[short] Android
     */
    static gd::string urlForAudio(int p0);
    
private:
    [[deprecated("LevelTools::valueForSpeedMod not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn valueForSpeedMod(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x44fb5c
     * @note[short] MacOS (Intel): 0x4ee730
     * @note[short] Windows: 0x318500
     * @note[short] Android
     */
    static bool verifyLevelIntegrity(gd::string p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0x44dc2c
     * @note[short] MacOS (Intel): 0x4ec5c0
     * @note[short] Windows: 0x315eb0
     * @note[short] Android
     */
    static gd::string ytURLForArtist(int p0);
};
