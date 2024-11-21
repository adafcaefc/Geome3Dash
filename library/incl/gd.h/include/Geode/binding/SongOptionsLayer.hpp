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

class SongOptionsLayer : public FLAlertLayer {
public:
    static constexpr auto CLASS_NAME = "SongOptionsLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SongOptionsLayer, FLAlertLayer)
    
private:
    [[deprecated("SongOptionsLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SongOptionsLayer* create(CustomSongDelegate* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x1baab4
     * @note[short] MacOS (Intel): 0x205a20
     * @note[short] Windows: 0xc4920
     * @note[short] iOS: 0x1491e0
     * @note[short] Android
     */
    virtual void keyBackClicked();
    
private:
    [[deprecated("SongOptionsLayer::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1b9c60
     * @note[short] Android
     */
    bool init(CustomSongDelegate* p0);
public:
    
private:
    [[deprecated("SongOptionsLayer::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SongOptionsLayer::onFadeIn not implemented")]]
    /**
     * @note[short] Android
     */
    void onFadeIn(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SongOptionsLayer::onFadeOut not implemented")]]
    /**
     * @note[short] Android
     */
    void onFadeOut(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SongOptionsLayer::onInfo not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1ba820
     * @note[short] MacOS (Intel): 0x2057b0
     * @note[short] Android
     */
    void onInfo(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SongOptionsLayer::onPlayback not implemented")]]
    /**
     * @note[short] Android
     */
    void onPlayback(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SongOptionsLayer::onSongPersistent not implemented")]]
    /**
     * @note[short] Android
     */
    void onSongPersistent(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SongOptionsLayer::updatePlaybackBtn not implemented")]]
    /**
     * @note[short] Android
     */
    void updatePlaybackBtn();
public:
};
