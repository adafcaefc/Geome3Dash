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
#include "FLAlertLayerProtocol.hpp"

class NewgroundsInfoLayer : public FLAlertLayer, public FLAlertLayerProtocol {
public:
    static constexpr auto CLASS_NAME = "NewgroundsInfoLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(NewgroundsInfoLayer, FLAlertLayer)
    
private:
    [[deprecated("NewgroundsInfoLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static NewgroundsInfoLayer* create();
public:
    
private:
    [[deprecated("NewgroundsInfoLayer::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1baac0
     * @note[short] MacOS (Intel): 0x205a50
     * @note[short] iOS: 0x1491ec
     * @note[short] Android
     */
    virtual bool init();
public:
    
private:
    [[deprecated("NewgroundsInfoLayer::keyBackClicked not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1bb5c4
     * @note[short] MacOS (Intel): 0x206530
     * @note[short] iOS: 0x149c54
     * @note[short] Android
     */
    virtual void keyBackClicked();
public:

    /**
     * @note[short] MacOS (ARM): 0x1bb56c
     * @note[short] MacOS (Intel): 0x2064d0
     * @note[short] Windows: 0xc5690
     * @note[short] iOS: 0x149bfc
     * @note[short] Android
     */
    virtual void FLAlert_Clicked(FLAlertLayer* p0, bool p1);
    
private:
    [[deprecated("NewgroundsInfoLayer::onArtists not implemented")]]
    /**
     * @note[short] Android
     */
    void onArtists(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("NewgroundsInfoLayer::onChanges not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1bb3ac
     * @note[short] MacOS (Intel): 0x206360
     * @note[short] Android
     */
    void onChanges(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("NewgroundsInfoLayer::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("NewgroundsInfoLayer::onGuidelines not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x206320
     * @note[short] Android
     */
    void onGuidelines(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("NewgroundsInfoLayer::onInfo not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1bb488
     * @note[short] MacOS (Intel): 0x206420
     * @note[short] Android
     */
    void onInfo(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("NewgroundsInfoLayer::onNewgrounds not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x206300
     * @note[short] Android
     */
    void onNewgrounds(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("NewgroundsInfoLayer::onSupporter not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x206340
     * @note[short] Android
     */
    void onSupporter(cocos2d::CCObject* sender);
public:
};
