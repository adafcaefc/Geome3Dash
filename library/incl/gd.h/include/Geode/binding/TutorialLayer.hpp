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

class TutorialLayer : public FLAlertLayer {
public:
    static constexpr auto CLASS_NAME = "TutorialLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(TutorialLayer, FLAlertLayer)
    
private:
    [[deprecated("TutorialLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static TutorialLayer* create();
public:

    /**
     * @note[short] MacOS (ARM): 0x42e988
     * @note[short] MacOS (Intel): 0x4c9280
     * @note[short] Windows: 0x4b31c0
     * @note[short] iOS: 0x1bf188
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (ARM): 0x42f414
     * @note[short] MacOS (Intel): 0x4c9cc0
     * @note[short] Windows: 0x4b3de0
     * @note[short] iOS: 0x1bfa70
     * @note[short] Android
     */
    virtual void keyBackClicked();
    
private:
    [[deprecated("TutorialLayer::loadPage not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x42ef60
     * @note[short] MacOS (Intel): 0x4c9800
     * @note[short] Android
     */
    void loadPage(int p0);
public:
    
private:
    [[deprecated("TutorialLayer::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("TutorialLayer::onNext not implemented")]]
    /**
     * @note[short] Android
     */
    void onNext(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("TutorialLayer::removeTutorialTexture not implemented")]]
    /**
     * @note[short] Android
     */
    void removeTutorialTexture();
public:
};
