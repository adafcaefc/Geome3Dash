#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class SongInfoObject : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "SongInfoObject";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(SongInfoObject, cocos2d::CCNode)
    
private:
    [[deprecated("SongInfoObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SongInfoObject* create(cocos2d::CCDictionary* p0);
public:

    /**
     * @note[short] Windows: 0x3300c0
     * @note[short] Android
     */
    static SongInfoObject* create(int songID, gd::string songName, gd::string artistName, int artistID, float filesize, gd::string youtubeVideo, gd::string youtubeChannel, gd::string url, int nongType, gd::string extraArtistIDs, bool isNew, int newType, int priority);

    /**
     * @note[short] MacOS (ARM): 0x4d21ac
     * @note[short] MacOS (Intel): 0x57f2e0
     * @note[short] Windows: 0x32ef70
     * @note[short] Android
     */
    static SongInfoObject* create(int p0);

    /**
     * @note[short] MacOS (ARM): 0x4d2d3c
     * @note[short] MacOS (Intel): 0x5800d0
     * @note[short] Windows: 0x3309a0
     * @note[short] iOS: 0x15f0b0
     * @note[short] Android
     */
    virtual void encodeWithCoder(DS_Dictionary* p0);
    
private:
    [[deprecated("SongInfoObject::canEncode not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4d2ed0
     * @note[short] MacOS (Intel): 0x580290
     * @note[short] iOS: 0x15f244
     * @note[short] Android
     */
    virtual bool canEncode();
public:
    
private:
    [[deprecated("SongInfoObject::addTags not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn addTags(gd::string p0);
public:
    
private:
    [[deprecated("SongInfoObject::containsTag not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn containsTag(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x4d2740
     * @note[short] Windows: 0x330690
     * @note[short] Android
     */
    TodoReturn createWithCoder(DS_Dictionary* p0);
    
private:
    [[deprecated("SongInfoObject::getArtistNames not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getArtistNames(int p0);
public:
    
private:
    [[deprecated("SongInfoObject::getTagsString not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getTagsString(bool p0);
public:
    
private:
    [[deprecated("SongInfoObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(int songID, gd::string songName, gd::string artistName, int artistID, float filesize, gd::string youtubeVideo, gd::string youtubeChannel, gd::string url, int nongType, gd::string extraArtistIDs, bool isNew, int newType, int priority);
public:
    
private:
    [[deprecated("SongInfoObject::updateArtists not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateArtists(gd::string p0);
public:
    int m_songID;
    gd::string m_songName;
    gd::string m_artistName;
    gd::string m_youtubeVideo;
    gd::string m_youtubeChannel;
    gd::string m_songUrl;
    int m_artistID;
    float m_fileSize;
    int m_nongType;
    gd::string m_extraArtists;
    bool m_isUnknownSong;
    int m_priority;
    int m_unkInt;
    int m_BPM;
    bool m_isNew;
    int m_newType;
    gd::string m_extraArtistNames;
    gd::unordered_set<int> m_artistIDs;
    gd::set<int> m_tags;
    gd::string m_longTagsString;
    gd::string m_shortTagsString;
};
