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

class ParentalOptionsLayer : public FLAlertLayer {
public:
    static constexpr auto CLASS_NAME = "ParentalOptionsLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(ParentalOptionsLayer, FLAlertLayer)
    
private:
    [[deprecated("ParentalOptionsLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static ParentalOptionsLayer* create();
public:
    
private:
    [[deprecated("ParentalOptionsLayer::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x6a1270
     * @note[short] MacOS (Intel): 0x78d870
     * @note[short] iOS: 0xf5a0c
     * @note[short] Android
     */
    virtual bool init();
public:
    
private:
    [[deprecated("ParentalOptionsLayer::keyBackClicked not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x6a2a4c
     * @note[short] MacOS (Intel): 0x78f100
     * @note[short] iOS: 0xf69d8
     * @note[short] Android
     */
    virtual void keyBackClicked();
public:
    
private:
    [[deprecated("ParentalOptionsLayer::addToggle not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn addToggle(char const* p0, char const* p1, char const* p2);
public:
    
private:
    [[deprecated("ParentalOptionsLayer::countForPage not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn countForPage(int p0);
public:
    
private:
    [[deprecated("ParentalOptionsLayer::goToPage not implemented")]]
    /**
     * @note[short] Android
     */
    void goToPage(int p0);
public:
    
private:
    [[deprecated("ParentalOptionsLayer::incrementCountForPage not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn incrementCountForPage(int p0);
public:
    
private:
    [[deprecated("ParentalOptionsLayer::infoKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn infoKey(int p0);
public:
    
private:
    [[deprecated("ParentalOptionsLayer::layerForPage not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn layerForPage(int p0);
public:
    
private:
    [[deprecated("ParentalOptionsLayer::layerKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn layerKey(int p0);
public:
    
private:
    [[deprecated("ParentalOptionsLayer::nextPosition not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn nextPosition(int p0);
public:
    
private:
    [[deprecated("ParentalOptionsLayer::objectKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn objectKey(int p0);
public:
    
private:
    [[deprecated("ParentalOptionsLayer::objectsForPage not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn objectsForPage(int p0);
public:
    
private:
    [[deprecated("ParentalOptionsLayer::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("ParentalOptionsLayer::onInfo not implemented")]]
    /**
     * @note[short] Android
     */
    void onInfo(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("ParentalOptionsLayer::onNextPage not implemented")]]
    /**
     * @note[short] Android
     */
    void onNextPage(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("ParentalOptionsLayer::onPrevPage not implemented")]]
    /**
     * @note[short] Android
     */
    void onPrevPage(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("ParentalOptionsLayer::onToggle not implemented")]]
    /**
     * @note[short] Android
     */
    void onToggle(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("ParentalOptionsLayer::pageKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn pageKey(int p0);
public:
};
