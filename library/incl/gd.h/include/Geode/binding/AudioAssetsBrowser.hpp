#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "FLAlertLayer.hpp"
#include "TableViewCellDelegate.hpp"
#include "MusicDownloadDelegate.hpp"

class AudioAssetsBrowser : public FLAlertLayer, public TableViewCellDelegate, public MusicDownloadDelegate {
public:
    static constexpr auto CLASS_NAME = "AudioAssetsBrowser";
    GEODE_CUSTOM_CONSTRUCTOR_GD(AudioAssetsBrowser, FLAlertLayer)
    
private:
    [[deprecated("AudioAssetsBrowser::create not implemented")]]
    /**
     * @note[short] Android
     */
    static AudioAssetsBrowser* create(gd::vector<int>& songIds, gd::vector<int>& sfxIds);
public:
    
private:
    [[deprecated("AudioAssetsBrowser::registerWithTouchDispatcher not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x6b1dd4
     * @note[short] MacOS (Intel): 0x79fa30
     * @note[short] iOS: 0x1d30fc
     * @note[short] Android
     */
    virtual void registerWithTouchDispatcher();
public:
    
private:
    [[deprecated("AudioAssetsBrowser::keyBackClicked not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x6b1d58
     * @note[short] MacOS (Intel): 0x79f9c0
     * @note[short] iOS: 0x1d3080
     * @note[short] Android
     */
    virtual void keyBackClicked();
public:
    
private:
    [[deprecated("AudioAssetsBrowser::musicActionFinished not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x6b1d04
     * @note[short] MacOS (Intel): 0x79f8e0
     * @note[short] iOS: 0x1d3034
     * @note[short] Android
     */
    virtual void musicActionFinished(GJMusicAction p0);
public:
    
private:
    [[deprecated("AudioAssetsBrowser::musicActionFailed not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x6b1d10
     * @note[short] MacOS (Intel): 0x79f910
     * @note[short] iOS: 0x1d3040
     * @note[short] Android
     */
    virtual void musicActionFailed(GJMusicAction p0);
public:
    
private:
    [[deprecated("AudioAssetsBrowser::cellPerformedAction not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x6b1d24
     * @note[short] MacOS (Intel): 0x79f950
     * @note[short] iOS: 0x1d3050
     * @note[short] Android
     */
    virtual bool cellPerformedAction(TableViewCell* p0, int p1, CellAction p2, cocos2d::CCNode* p3);
public:
    
private:
    [[deprecated("AudioAssetsBrowser::getSelectedCellIdx not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x6b1d34
     * @note[short] MacOS (Intel): 0x79f970
     * @note[short] iOS: 0x1d3060
     * @note[short] Android
     */
    virtual int getSelectedCellIdx();
public:
    
private:
    [[deprecated("AudioAssetsBrowser::getCellDelegateType not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x6b1d44
     * @note[short] MacOS (Intel): 0x79f990
     * @note[short] iOS: 0x1d3070
     * @note[short] Android
     */
    virtual int getCellDelegateType();
public:
    
private:
    [[deprecated("AudioAssetsBrowser::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(gd::vector<int>& songIds, gd::vector<int>& sfxIds);
public:
    
private:
    [[deprecated("AudioAssetsBrowser::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("AudioAssetsBrowser::onInfo not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x6b1494
     * @note[short] MacOS (Intel): 0x79ef60
     * @note[short] Android
     */
    void onInfo(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("AudioAssetsBrowser::onPage not implemented")]]
    /**
     * @note[short] Android
     */
    void onPage(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("AudioAssetsBrowser::setupList not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn setupList();
public:
    
private:
    [[deprecated("AudioAssetsBrowser::trySetupAudioBrowser not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn trySetupAudioBrowser();
public:
    
private:
    [[deprecated("AudioAssetsBrowser::updatePageLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updatePageLabel();
public:
    cocos2d::CCArray* m_songInfoObjects;
    GJCommentListLayer* m_songList;
    cocos2d::CCLabelBMFont* m_pageIndicatorLabel;
    gd::vector<int> m_songsIds;
    gd::vector<int> m_sfxIds;
    LoadingCircleSprite* m_loadingCircle;
};
