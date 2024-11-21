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

class KeybindingsLayer : public FLAlertLayer {
public:
    static constexpr auto CLASS_NAME = "KeybindingsLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(KeybindingsLayer, FLAlertLayer)

    /**
     * @note[short] Windows: 0x2b81d0
     * @note[short] Android
     */
    static KeybindingsLayer* create();

    /**
     * @note[short] MacOS (ARM): 0x5220ec
     * @note[short] MacOS (Intel): 0x5f25f0
     * @note[short] Windows: 0x2b82c0
     * @note[short] Android
     */
    virtual bool init();
    
private:
    [[deprecated("KeybindingsLayer::keyBackClicked not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x523ab4
     * @note[short] MacOS (Intel): 0x5f3fc0
     * @note[short] Android
     */
    virtual void keyBackClicked();
public:

    /**
     * @note[short] Windows: 0x2b8bd0
     * @note[short] Android
     */
    TodoReturn addKeyPair(char const* p0, char const* p1);

    /**
     * @note[short] Windows: 0x2b8f80
     * @note[short] Android
     */
    TodoReturn countForPage(int p0);

    /**
     * @note[short] Windows: 0x2b9220
     * @note[short] Android
     */
    void goToPage(int p0);
    
private:
    [[deprecated("KeybindingsLayer::incrementCountForPage not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn incrementCountForPage(int p0);
public:
    
private:
    [[deprecated("KeybindingsLayer::infoKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn infoKey(int p0);
public:

    /**
     * @note[short] Windows: 0x2b9050
     * @note[short] Android
     */
    TodoReturn layerForPage(int p0);
    
private:
    [[deprecated("KeybindingsLayer::layerKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn layerKey(int p0);
public:
    
private:
    [[deprecated("KeybindingsLayer::nextPosition not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn nextPosition(int p0);
public:
    
private:
    [[deprecated("KeybindingsLayer::objectKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn objectKey(int p0);
public:
    
private:
    [[deprecated("KeybindingsLayer::objectsForPage not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn objectsForPage(int p0);
public:

    /**
     * @note[short] Windows: 0x84620
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
    
private:
    [[deprecated("KeybindingsLayer::onInfo not implemented")]]
    /**
     * @note[short] Android
     */
    void onInfo(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] Windows: 0x2b9200
     * @note[short] Android
     */
    void onNextPage(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x2b9210
     * @note[short] Android
     */
    void onPrevPage(cocos2d::CCObject* sender);
    
private:
    [[deprecated("KeybindingsLayer::onToggle not implemented")]]
    /**
     * @note[short] Android
     */
    void onToggle(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("KeybindingsLayer::pageKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn pageKey(int p0);
public:
};
