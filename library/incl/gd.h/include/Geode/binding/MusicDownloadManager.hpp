#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "PlatformDownloadDelegate.hpp"

class MusicDownloadManager : public cocos2d::CCNode, public PlatformDownloadDelegate {
public:
    static constexpr auto CLASS_NAME = "MusicDownloadManager";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(MusicDownloadManager, cocos2d::CCNode)
    
private:
    [[deprecated("MusicDownloadManager::responseToDict not implemented")]]
    /**
     * @note[short] Android
     */
    static cocos2d::CCDictionary* responseToDict(gd::string p0, char const* p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x4c6c2c
     * @note[short] MacOS (Intel): 0x572a00
     * @note[short] Windows: 0x3277b0
     * @note[short] Android
     */
    static MusicDownloadManager* sharedState();
    
private:
    [[deprecated("MusicDownloadManager::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4c7abc
     * @note[short] MacOS (Intel): 0x573980
     * @note[short] iOS: 0x157718
     * @note[short] Android
     */
    virtual bool init();
public:

    /**
     * @note[short] MacOS (ARM): 0x4cba2c
     * @note[short] MacOS (Intel): 0x577e40
     * @note[short] Windows: 0x3299f0
     * @note[short] Android
     */
    void addDLToActive(char const* tag, cocos2d::CCObject* obj);
    
private:
    [[deprecated("MusicDownloadManager::addDLToActive not implemented")]]
    /**
     * @note[short] Android
     */
    void addDLToActive(char const* tag);
public:

    /**
     * @note[short] Windows: 0x327f30
     * @note[short] Android
     */
    TodoReturn addMusicDownloadDelegate(MusicDownloadDelegate* p0);
    
private:
    [[deprecated("MusicDownloadManager::addSongObjectFromString not implemented")]]
    /**
     * @note[short] Android
     */
    void addSongObjectFromString(gd::string p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x4cae00
     * @note[short] MacOS (Intel): 0x577170
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void clearSong(int songID);

    /**
     * @note[short] Windows: 0x329160
     * @note[short] Android
     */
    void clearUnusedSongs();

    /**
     * @note[short] Windows: 0x328c50
     * @note[short] Android
     */
    void createArtistsInfo(gd::string p0);

    /**
     * @note[short] MacOS (ARM): 0x4c998c
     * @note[short] MacOS (Intel): 0x575b00
     * @note[short] Windows: 0x3288a0
     * @note[short] Android
     */
    void createSongsInfo(gd::string p0, gd::string p1);

    /**
     * @note[short] MacOS (ARM): 0x4cc790
     * @note[short] MacOS (Intel): 0x578e00
     * @note[short] Windows: 0x32a450
     * @note[short] Android
     */
    void dataLoaded(DS_Dictionary* p0);
    
private:
    [[deprecated("MusicDownloadManager::deleteSFX not implemented")]]
    /**
     * @note[short] Android
     */
    void deleteSFX(int p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::deleteSong not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4cada0
     * @note[short] MacOS (Intel): 0x577120
     * @note[short] Android
     */
    void deleteSong(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x4cb4c4
     * @note[short] MacOS (Intel): 0x5778d0
     * @note[short] Windows: 0x32ad40
     * @note[short] Android
     */
    void downloadCustomSong(int p0);
    
private:
    [[deprecated("MusicDownloadManager::downloadMusicLibrary not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4cd97c
     * @note[short] MacOS (Intel): 0x57a200
     * @note[short] Android
     */
    void downloadMusicLibrary();
public:
    
private:
    [[deprecated("MusicDownloadManager::downloadSFX not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4d01c0
     * @note[short] MacOS (Intel): 0x57d0e0
     * @note[short] Android
     */
    void downloadSFX(int p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::downloadSFXFailed not implemented")]]
    /**
     * @note[short] Android
     */
    void downloadSFXFailed(int p0, GJSongError p1);
public:
    
private:
    [[deprecated("MusicDownloadManager::downloadSFXFinished not implemented")]]
    /**
     * @note[short] Android
     */
    void downloadSFXFinished(int p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::downloadSFXLibrary not implemented")]]
    /**
     * @note[short] Android
     */
    void downloadSFXLibrary();
public:

    /**
     * @note[short] MacOS (ARM): 0x4cb0d0
     * @note[short] MacOS (Intel): 0x577410
     * @note[short] Windows: 0x329460
     * @note[short] Android
     */
    void downloadSong(int p0);
    
private:
    [[deprecated("MusicDownloadManager::downloadSongFailed not implemented")]]
    /**
     * @note[short] Android
     */
    void downloadSongFailed(int p0, GJSongError p1);
public:
    
private:
    [[deprecated("MusicDownloadManager::downloadSongFinished not implemented")]]
    /**
     * @note[short] Android
     */
    void downloadSongFinished(int p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::encodeDataTo not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4cc738
     * @note[short] Android
     */
    void encodeDataTo(DS_Dictionary* p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::filterMusicByArtistID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn filterMusicByArtistID(int p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("MusicDownloadManager::filterMusicByTag not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn filterMusicByTag(int p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("MusicDownloadManager::firstSetup not implemented")]]
    /**
     * @note[short] Android
     */
    void firstSetup();
public:

    /**
     * @note[short] MacOS (ARM): 0x4ccfdc
     * @note[short] MacOS (Intel): 0x5796c0
     * @note[short] Windows: 0x32e2e0
     * @note[short] Android
     */
    TodoReturn generateCustomContentURL(gd::string p0);
    
private:
    [[deprecated("MusicDownloadManager::generateResourceAssetList not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn generateResourceAssetList();
public:
    
private:
    [[deprecated("MusicDownloadManager::getAllMusicArtists not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getAllMusicArtists(OptionsObjectDelegate* p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::getAllMusicObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getAllMusicObjects(GJSongType p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::getAllMusicTags not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getAllMusicTags(OptionsObjectDelegate* p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::getAllSFXObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getAllSFXObjects(bool p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::getAllSongs not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getAllSongs();
public:

    /**
     * @note[short] MacOS (ARM): 0x4ccd84
     * @note[short] MacOS (Intel): 0x579470
     * @note[short] Windows: 0x32a940
     * @note[short] Android
     */
    void getCustomContentURL();

    /**
     * @note[short] Windows: 0x39d70
     * @note[short] Android
     */
    cocos2d::CCObject* getDLObject(char const* p0);

    /**
     * @note[short] MacOS (ARM): 0x4ca930
     * @note[short] MacOS (Intel): 0x576c20
     * @note[short] Windows: 0x3290a0
     * @note[short] Android
     */
    cocos2d::CCArray* getDownloadedSongs();
    
private:
    [[deprecated("MusicDownloadManager::getDownloadProgress not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getDownloadProgress(int p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::getMusicArtistForID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getMusicArtistForID(int p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::getMusicObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getMusicObject(int p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::getSFXDownloadKey not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4cbcd8
     * @note[short] MacOS (Intel): 0x5780c0
     * @note[short] Android
     */
    TodoReturn getSFXDownloadKey(int p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::getSFXDownloadProgress not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getSFXDownloadProgress(int p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::getSFXFolderObjectForID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getSFXFolderObjectForID(int p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::getSFXFolderPathForID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getSFXFolderPathForID(int p0, bool p1);
public:
    
private:
    [[deprecated("MusicDownloadManager::getSFXObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getSFXObject(int p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::getSongDownloadKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getSongDownloadKey(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x4c82e0
     * @note[short] MacOS (Intel): 0x574190
     * @note[short] Windows: 0x328180
     * @note[short] Android
     */
    void getSongInfo(int p0, bool p1);
    
private:
    [[deprecated("MusicDownloadManager::getSongInfoKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getSongInfoKey(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x4c8188
     * @note[short] MacOS (Intel): 0x574030
     * @note[short] Windows: 0x329b70
     * @note[short] Android
     */
    SongInfoObject* getSongInfoObject(int p0);
    
private:
    [[deprecated("MusicDownloadManager::getSongPriority not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getSongPriority();
public:
    
private:
    [[deprecated("MusicDownloadManager::handleIt not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4c7150
     * @note[short] MacOS (Intel): 0x572fd0
     * @note[short] Android
     */
    void handleIt(bool p0, gd::string p1, gd::string p2, GJHttpType p3);
public:
    
private:
    [[deprecated("MusicDownloadManager::handleItDelayed not implemented")]]
    /**
     * @note[short] Android
     */
    void handleItDelayed(bool p0, gd::string p1, gd::string p2, GJHttpType p3);
public:
    
private:
    [[deprecated("MusicDownloadManager::handleItND not implemented")]]
    /**
     * @note[short] Android
     */
    void handleItND(cocos2d::CCNode* p0, void* p1);
public:
    
private:
    [[deprecated("MusicDownloadManager::incrementPriorityForSong not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x574000
     * @note[short] Android
     */
    TodoReturn incrementPriorityForSong(int p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::isDLActive not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4c7f00
     * @note[short] MacOS (Intel): 0x573dd0
     * @note[short] Android
     */
    bool isDLActive(char const* tag);
public:
    
private:
    [[deprecated("MusicDownloadManager::isMusicLibraryLoaded not implemented")]]
    /**
     * @note[short] Android
     */
    bool isMusicLibraryLoaded();
public:
    
private:
    [[deprecated("MusicDownloadManager::isResourceSFX not implemented")]]
    /**
     * @note[short] Android
     */
    bool isResourceSFX(int p0);
public:

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    bool isResourceSong(int id);
    
private:
    [[deprecated("MusicDownloadManager::isRunningActionForSongID not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x573cb0
     * @note[short] Android
     */
    bool isRunningActionForSongID(int p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::isSFXDownloaded not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4cbfe4
     * @note[short] MacOS (Intel): 0x5784f0
     * @note[short] Android
     */
    bool isSFXDownloaded(int p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::isSFXLibraryLoaded not implemented")]]
    /**
     * @note[short] Android
     */
    bool isSFXLibraryLoaded();
public:

    /**
     * @note[short] MacOS (ARM): 0x4ca9c8
     * @note[short] MacOS (Intel): 0x576cc0
     * @note[short] Windows: 0x329c80
     * @note[short] Android
     */
    bool isSongDownloaded(int p0);
    
private:
    [[deprecated("MusicDownloadManager::limitDownloadedSongs not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4cac6c
     * @note[short] MacOS (Intel): 0x576fe0
     * @note[short] Android
     */
    void limitDownloadedSongs();
public:
    
private:
    [[deprecated("MusicDownloadManager::loadSongInfoFailed not implemented")]]
    /**
     * @note[short] Android
     */
    void loadSongInfoFailed(int p0, GJSongError p1);
public:

    /**
     * @note[short] Windows: 0x32ec70
     * @note[short] Android
     */
    void loadSongInfoFinished(SongInfoObject* p0);
    
private:
    [[deprecated("MusicDownloadManager::musicActionFailed not implemented")]]
    /**
     * @note[short] Android
     */
    void musicActionFailed(GJMusicAction p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::musicActionFinished not implemented")]]
    /**
     * @note[short] Android
     */
    void musicActionFinished(GJMusicAction p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::nameForTagID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn nameForTagID(int p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::onDownloadMusicLibraryCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onDownloadMusicLibraryCompleted(cocos2d::extension::CCHttpClient* p0, cocos2d::extension::CCHttpResponse* p1);
public:
    
private:
    [[deprecated("MusicDownloadManager::onDownloadSFXCompleted not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4d04ac
     * @note[short] MacOS (Intel): 0x57d3b0
     * @note[short] Android
     */
    void onDownloadSFXCompleted(cocos2d::extension::CCHttpClient* p0, cocos2d::extension::CCHttpResponse* p1);
public:
    
private:
    [[deprecated("MusicDownloadManager::onDownloadSFXLibraryCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onDownloadSFXLibraryCompleted(cocos2d::extension::CCHttpClient* p0, cocos2d::extension::CCHttpResponse* p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x4cb7b4
     * @note[short] MacOS (Intel): 0x577ba0
     * @note[short] Windows: 0x329750
     * @note[short] Android
     */
    void onDownloadSongCompleted(cocos2d::extension::CCHttpClient* p0, cocos2d::extension::CCHttpResponse* p1);
    
private:
    [[deprecated("MusicDownloadManager::onGetCustomContentURLCompleted not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4c7868
     * @note[short] MacOS (Intel): 0x5736a0
     * @note[short] Android
     */
    void onGetCustomContentURLCompleted(gd::string p0, gd::string p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x4c75d8
     * @note[short] MacOS (Intel): 0x573400
     * @note[short] Windows: 0x328460
     * @note[short] Android
     */
    void onGetSongInfoCompleted(gd::string p0, gd::string p1);
    
private:
    [[deprecated("MusicDownloadManager::onProcessHttpRequestCompleted not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4c6e34
     * @note[short] MacOS (Intel): 0x572ca0
     * @note[short] Android
     */
    void onProcessHttpRequestCompleted(cocos2d::extension::CCHttpClient* p0, cocos2d::extension::CCHttpResponse* p1);
public:
    
private:
    [[deprecated("MusicDownloadManager::onTryUpdateMusicLibraryCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onTryUpdateMusicLibraryCompleted(cocos2d::extension::CCHttpClient* p0, cocos2d::extension::CCHttpResponse* p1);
public:
    
private:
    [[deprecated("MusicDownloadManager::onTryUpdateSFXLibraryCompleted not implemented")]]
    /**
     * @note[short] Android
     */
    void onTryUpdateSFXLibraryCompleted(cocos2d::extension::CCHttpClient* p0, cocos2d::extension::CCHttpResponse* p1);
public:
    
private:
    [[deprecated("MusicDownloadManager::parseMusicLibrary not implemented")]]
    /**
     * @note[short] Android
     */
    void parseMusicLibrary();
public:
    
private:
    [[deprecated("MusicDownloadManager::parseSFXLibrary not implemented")]]
    /**
     * @note[short] Android
     */
    void parseSFXLibrary();
public:

    /**
     * @note[short] MacOS (ARM): 0x4cc334
     * @note[short] MacOS (Intel): 0x578940
     * @note[short] Windows: 0x32a230
     * @note[short] Android
     */
    gd::string pathForSFX(int p0);

    /**
     * @note[short] MacOS (ARM): 0x4cc418
     * @note[short] MacOS (Intel): 0x578a00
     * @note[short] Windows: 0x32a0e0
     * @note[short] Android
     */
    gd::string pathForSFXFolder(int p0);

    /**
     * @note[short] MacOS (ARM): 0x4caf14
     * @note[short] MacOS (Intel): 0x577270
     * @note[short] Windows: 0x329f00
     * @note[short] Android
     */
    gd::string pathForSong(int p0);

    /**
     * @note[short] MacOS (ARM): 0x4cbe10
     * @note[short] MacOS (Intel): 0x578290
     * @note[short] Windows: 0x329db0
     * @note[short] Android
     */
    gd::string pathForSongFolder(int p0);
    
private:
    [[deprecated("MusicDownloadManager::ProcessHttpGetRequest not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4c7030
     * @note[short] MacOS (Intel): 0x572e60
     * @note[short] Android
     */
    void ProcessHttpGetRequest(gd::string p0, gd::string p1, cocos2d::extension::SEL_HttpResponse p2, int p3, int p4);
public:
    
private:
    [[deprecated("MusicDownloadManager::ProcessHttpRequest not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4c6cf0
     * @note[short] MacOS (Intel): 0x572b10
     * @note[short] Android
     */
    void ProcessHttpRequest(gd::string p0, gd::string p1, gd::string p2, GJHttpType p3);
public:
    
private:
    [[deprecated("MusicDownloadManager::removeDLFromActive not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x47ecac
     * @note[short] MacOS (Intel): 0x522d00
     * @note[short] Android
     */
    void removeDLFromActive(char const* p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::removeMusicDownloadDelegate not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn removeMusicDownloadDelegate(MusicDownloadDelegate* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x4cc5ec
     * @note[short] MacOS (Intel): 0x578c60
     * @note[short] Windows: 0x32a2f0
     * @note[short] Android
     */
    void showTOS(FLAlertLayerProtocol* p0);

    /**
     * @note[short] MacOS (ARM): 0x4c80f8
     * @note[short] MacOS (Intel): 0x573fa0
     * @note[short] Windows: 0x328120
     * @note[short] Android
     */
    void songStateChanged();
    
private:
    [[deprecated("MusicDownloadManager::stopDownload not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4c7ea4
     * @note[short] MacOS (Intel): 0x573d80
     * @note[short] Android
     */
    TodoReturn stopDownload(int p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::storeMusicObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn storeMusicObject(SongInfoObject* p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::storeSFXInfoObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn storeSFXInfoObject(SFXInfoObject* p0);
public:
    
private:
    [[deprecated("MusicDownloadManager::tryLoadLibraries not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn tryLoadLibraries();
public:
    
private:
    [[deprecated("MusicDownloadManager::tryUpdateMusicLibrary not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4cd618
     * @note[short] MacOS (Intel): 0x579ed0
     * @note[short] Android
     */
    TodoReturn tryUpdateMusicLibrary();
public:
    
private:
    [[deprecated("MusicDownloadManager::tryUpdateSFXLibrary not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4d07c4
     * @note[short] MacOS (Intel): 0x57d6d0
     * @note[short] Android
     */
    TodoReturn tryUpdateSFXLibrary();
public:
    cocos2d::CCDictionary* m_activeDownloads;
    cocos2d::CCArray* m_musicDownloadDelegates;
    cocos2d::CCDictionary* m_songObjects;
    cocos2d::CCDictionary* m_MDLM003;
    int m_songPriority;
    gd::string m_customContentURL;
    cocos2d::CCDictionary* m_sfxObjects;
    cocos2d::CCArray* m_sfxArtists;
    int m_sfxLibraryVersion;
    int m_sfxObjectCount;
    bool m_requestedSfxLibraryDownloaded;
    cocos2d::CCDictionary* m_musicObjects;
    cocos2d::CCDictionary* m_musicArtists;
    gd::map<int, gd::string> m_musicTags;
    int m_musicLibraryVersion;
    int m_musicObjectCount;
    bool m_requestedMusicLibraryDownloaded;
    bool m_triedToLoadLibraries;
    bool m_unkBool;
    gd::unordered_set<int> m_resourceSfxUnorderedSet;
    gd::unordered_set<int> m_resourceSongUnorderedSet;
};
