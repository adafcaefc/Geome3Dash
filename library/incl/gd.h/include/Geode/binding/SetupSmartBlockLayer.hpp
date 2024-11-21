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
#include "TextInputDelegate.hpp"
#include "SelectArtDelegate.hpp"

class SetupSmartBlockLayer : public FLAlertLayer, public TextInputDelegate, public SelectArtDelegate {
public:
    static constexpr auto CLASS_NAME = "SetupSmartBlockLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupSmartBlockLayer, FLAlertLayer)
    
private:
    [[deprecated("SetupSmartBlockLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupSmartBlockLayer* create(SmartGameObject* p0, cocos2d::CCArray* p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x4383cc
     * @note[short] MacOS (Intel): 0x4d46d0
     * @note[short] Windows: 0x4406d0
     * @note[short] iOS: 0x74300
     * @note[short] Android
     */
    virtual void keyBackClicked();
    
private:
    [[deprecated("SetupSmartBlockLayer::show not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x438368
     * @note[short] MacOS (Intel): 0x4d4640
     * @note[short] iOS: 0x7429c
     * @note[short] Android
     */
    virtual void show();
public:

    /**
     * @note[short] MacOS (ARM): 0x4383b4
     * @note[short] MacOS (Intel): 0x4d46a0
     * @note[short] Windows: 0x440690
     * @note[short] iOS: 0x742e8
     * @note[short] Android
     */
    virtual void selectArtClosed(SelectArtLayer* p0);
    
private:
    [[deprecated("SetupSmartBlockLayer::determineStartValues not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn determineStartValues();
public:
    
private:
    [[deprecated("SetupSmartBlockLayer::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x436e18
     * @note[short] MacOS (Intel): 0x4d2e00
     * @note[short] Android
     */
    bool init(SmartGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupSmartBlockLayer::onAllowFlipping not implemented")]]
    /**
     * @note[short] Android
     */
    void onAllowFlipping(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupSmartBlockLayer::onAllowRotation not implemented")]]
    /**
     * @note[short] Android
     */
    void onAllowRotation(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupSmartBlockLayer::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupSmartBlockLayer::onCreate not implemented")]]
    /**
     * @note[short] Android
     */
    void onCreate(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupSmartBlockLayer::onCreateAll not implemented")]]
    /**
     * @note[short] Android
     */
    void onCreateAll(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupSmartBlockLayer::onCreateTemplate not implemented")]]
    /**
     * @note[short] Android
     */
    void onCreateTemplate(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupSmartBlockLayer::onDontDelete not implemented")]]
    /**
     * @note[short] Android
     */
    void onDontDelete(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupSmartBlockLayer::onIgnoreCorners not implemented")]]
    /**
     * @note[short] Android
     */
    void onIgnoreCorners(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupSmartBlockLayer::onNearbyReference not implemented")]]
    /**
     * @note[short] Android
     */
    void onNearbyReference(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupSmartBlockLayer::onPasteTemplate not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x437d78
     * @note[short] MacOS (Intel): 0x4d3f90
     * @note[short] Android
     */
    void onPasteTemplate(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupSmartBlockLayer::onReferenceOnly not implemented")]]
    /**
     * @note[short] Android
     */
    void onReferenceOnly(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupSmartBlockLayer::onSelectPremade not implemented")]]
    /**
     * @note[short] Android
     */
    void onSelectPremade(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupSmartBlockLayer::onSelectTemplate not implemented")]]
    /**
     * @note[short] Android
     */
    void onSelectTemplate(cocos2d::CCObject* sender);
public:
};
