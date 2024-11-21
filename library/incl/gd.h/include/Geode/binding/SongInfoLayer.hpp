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

class SongInfoLayer : public FLAlertLayer {
public:
    static constexpr auto CLASS_NAME = "SongInfoLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SongInfoLayer, FLAlertLayer)
    
private:
    [[deprecated("SongInfoLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SongInfoLayer* create(gd::string p0, gd::string p1, gd::string p2, gd::string p3, gd::string p4, gd::string p5, int p6, gd::string p7, int p8);
public:
    
private:
    [[deprecated("SongInfoLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SongInfoLayer* create(int p0);
public:
    
private:
    [[deprecated("SongInfoLayer::keyBackClicked not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x51be3c
     * @note[short] MacOS (Intel): 0x5ea640
     * @note[short] iOS: 0x3a1940
     * @note[short] Android
     */
    virtual void keyBackClicked();
public:

    /**
     * @note[short] MacOS (ARM): 0x51aa04
     * @note[short] MacOS (Intel): 0x5e9240
     * @note[short] Windows: 0x47a450
     * @note[short] Android
     */
    bool init(gd::string p0, gd::string p1, gd::string p2, gd::string p3, gd::string p4, gd::string p5, int p6, gd::string p7, int p8);
    
private:
    [[deprecated("SongInfoLayer::onBPM not implemented")]]
    /**
     * @note[short] Android
     */
    void onBPM(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SongInfoLayer::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SongInfoLayer::onDownload not implemented")]]
    /**
     * @note[short] Android
     */
    void onDownload(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SongInfoLayer::onFB not implemented")]]
    /**
     * @note[short] Android
     */
    void onFB(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SongInfoLayer::onMenuMusic not implemented")]]
    /**
     * @note[short] Android
     */
    void onMenuMusic(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SongInfoLayer::onNG not implemented")]]
    /**
     * @note[short] Android
     */
    void onNG(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SongInfoLayer::onPracticeMusic not implemented")]]
    /**
     * @note[short] Android
     */
    void onPracticeMusic(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SongInfoLayer::onYT not implemented")]]
    /**
     * @note[short] Android
     */
    void onYT(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SongInfoLayer::showCustomMusicUnlockInfo not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x51bbd4
     * @note[short] MacOS (Intel): 0x5ea430
     * @note[short] Android
     */
    void showCustomMusicUnlockInfo();
public:
    gd::string m_downloadLink;
    gd::string m_newgroundsLink;
    gd::string m_youtubeLink;
    gd::string m_facebookLink;
    int m_songID;
    int m_musicCustomizerMessageIndex;
};
