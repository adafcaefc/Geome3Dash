#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "MusicDownloadDelegate.hpp"
#include "FLAlertLayerProtocol.hpp"

class CustomSFXWidget : public cocos2d::CCNode, public MusicDownloadDelegate, public FLAlertLayerProtocol {
public:
    static constexpr auto CLASS_NAME = "CustomSFXWidget";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(CustomSFXWidget, cocos2d::CCNode)

    /**
     * @note[short] Android
     */
    static CustomSFXWidget* create(SFXInfoObject* p0, CustomSFXDelegate* p1, bool p2, bool p3, bool p4, bool p5, bool p6);

    /**
     * @note[short] MacOS (ARM): 0x500fac
     * @note[short] MacOS (Intel): 0x5cc910
     * @note[short] Windows: 0xc18e0
     * @note[short] iOS: 0x2f13bc
     * @note[short] Android
     */
    virtual void downloadSFXFinished(int p0);

    /**
     * @note[short] MacOS (ARM): 0x50104c
     * @note[short] MacOS (Intel): 0x5cc9b0
     * @note[short] Windows: 0xc1960
     * @note[short] iOS: 0x2f1414
     * @note[short] Android
     */
    virtual void downloadSFXFailed(int p0, GJSongError p1);

    /**
     * @note[short] MacOS (ARM): 0x500f84
     * @note[short] MacOS (Intel): 0x5cc8a0
     * @note[short] Windows: 0xc1230
     * @note[short] iOS: 0x2f13a8
     * @note[short] Android
     */
    virtual void songStateChanged();

    /**
     * @note[short] MacOS (ARM): 0x50125c
     * @note[short] MacOS (Intel): 0x5ccb90
     * @note[short] Windows: 0xc1a60
     * @note[short] iOS: 0x2f1554
     * @note[short] Android
     */
    virtual void FLAlert_Clicked(FLAlertLayer* p0, bool p1);

    /**
     * @note[short] MacOS (ARM): 0x500ad8
     * @note[short] MacOS (Intel): 0x5cc3f0
     * @note[short] Android
     */
    TodoReturn deleteSFX();

    /**
     * @note[short] Android
     */
    void downloadFailed();

    /**
     * @note[short] Android
     */
    TodoReturn hideLoadingArt();

    /**
     * @note[short] MacOS (ARM): 0x4fef30
     * @note[short] MacOS (Intel): 0x5ca7d0
     * @note[short] Android
     */
    bool init(SFXInfoObject* p0, CustomSFXDelegate* p1, bool p2, bool p3, bool p4, bool p5, bool p6);

    /**
     * @note[short] Android
     */
    void onCancelDownload(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x4fff6c
     * @note[short] MacOS (Intel): 0x5cb890
     * @note[short] Android
     */
    void onDelete(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onDownload(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onPlayback(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onSelect(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void showLoadingArt();

    /**
     * @note[short] Android
     */
    TodoReturn startDownload();

    /**
     * @note[short] Android
     */
    TodoReturn startMonitorDownload();

    /**
     * @note[short] Android
     */
    TodoReturn updateDownloadProgress(float p0);

    /**
     * @note[short] MacOS (ARM): 0x50115c
     * @note[short] MacOS (Intel): 0x5ccaa0
     * @note[short] Android
     */
    TodoReturn updateError(GJSongError p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateLengthMod(float p0);

    /**
     * @note[short] Android
     */
    TodoReturn updatePlaybackBtn();

    /**
     * @note[short] Android
     */
    TodoReturn updateProgressBar(int p0);

    /**
     * @note[short] MacOS (ARM): 0x5003a4
     * @note[short] MacOS (Intel): 0x5cbcc0
     * @note[short] Android
     */
    void updateSFXInfo();

    /**
     * @note[short] Android
     */
    TodoReturn updateSFXObject(SFXInfoObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn verifySFXID(int p0);
};
