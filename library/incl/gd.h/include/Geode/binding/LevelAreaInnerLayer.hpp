#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "DialogDelegate.hpp"

class LevelAreaInnerLayer : public cocos2d::CCLayer, public DialogDelegate {
public:
    static constexpr auto CLASS_NAME = "LevelAreaInnerLayer";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(LevelAreaInnerLayer, cocos2d::CCLayer)
    
private:
    [[deprecated("LevelAreaInnerLayer::create not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x267c20
     * @note[short] Android
     */
    static LevelAreaInnerLayer* create(bool p0);
public:

    /**
     * @note[short] MacOS (Intel): 0x267950
     * @note[short] Windows: 0x2be1d0
     * @note[short] Android
     */
    static cocos2d::CCScene* scene(bool p0);

    /**
     * @note[short] MacOS (ARM): 0x21538c
     * @note[short] MacOS (Intel): 0x269bf0
     * @note[short] Windows: 0x2c0550
     * @note[short] iOS: 0x3467b8
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x215164
     * @note[short] MacOS (Intel): 0x2699c0
     * @note[short] Windows: 0x2bf9a0
     * @note[short] iOS: 0x346614
     * @note[short] Android
     */
    virtual void dialogClosed(DialogLayer* p0);

    /**
     * @note[short] MacOS (ARM): 0x21533c
     * @note[short] MacOS (Intel): 0x269ba0
     * @note[short] Windows: 0x2c0500
     * @note[short] iOS: 0x346768
     * @note[short] Android
     */
    virtual void onExit();

    /**
     * @note[short] MacOS (ARM): 0x2135d4
     * @note[short] MacOS (Intel): 0x267d00
     * @note[short] Windows: 0x2be2e0
     * @note[short] Android
     */
    bool init(bool p0);

    /**
     * @note[short] MacOS (ARM): 0x2143a0
     * @note[short] MacOS (Intel): 0x268b80
     * @note[short] Windows: 0x2c04a0
     * @note[short] Android
     */
    void onBack(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x2143f8
     * @note[short] MacOS (Intel): 0x268bd0
     * @note[short] Windows: 0x2bffd0
     * @note[short] Android
     */
    void onDoor(cocos2d::CCObject* sender);
    
private:
    [[deprecated("LevelAreaInnerLayer::onInfo not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2146cc
     * @note[short] MacOS (Intel): 0x268e70
     * @note[short] Android
     */
    void onInfo(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("LevelAreaInnerLayer::onNextFloor not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x21453c
     * @note[short] MacOS (Intel): 0x268d00
     * @note[short] Android
     */
    void onNextFloor(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("LevelAreaInnerLayer::onOnlineVault not implemented")]]
    /**
     * @note[short] Android
     */
    void onOnlineVault(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("LevelAreaInnerLayer::playStep1 not implemented")]]
    /**
     * @note[short] Android
     */
    bool playStep1();
public:
    
private:
    [[deprecated("LevelAreaInnerLayer::showFloor1CompleteDialog not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x214c58
     * @note[short] MacOS (Intel): 0x269470
     * @note[short] Android
     */
    cocos2d::CCAction* showFloor1CompleteDialog();
public:
    
private:
    [[deprecated("LevelAreaInnerLayer::tryResumeTowerMusic not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn tryResumeTowerMusic();
public:
    
private:
    [[deprecated("LevelAreaInnerLayer::tryShowAd not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn tryShowAd();
public:
};
