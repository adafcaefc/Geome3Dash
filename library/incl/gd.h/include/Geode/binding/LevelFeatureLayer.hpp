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

class LevelFeatureLayer : public FLAlertLayer {
public:
    static constexpr auto CLASS_NAME = "LevelFeatureLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(LevelFeatureLayer, FLAlertLayer)
    
private:
    [[deprecated("LevelFeatureLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static LevelFeatureLayer* create(int p0);
public:
    
private:
    [[deprecated("LevelFeatureLayer::keyBackClicked not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4530b8
     * @note[short] MacOS (Intel): 0x4f2260
     * @note[short] Android
     */
    virtual void keyBackClicked();
public:
    
private:
    [[deprecated("LevelFeatureLayer::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x45260c
     * @note[short] MacOS (Intel): 0x4f1770
     * @note[short] Android
     */
    bool init(int p0);
public:
    
private:
    [[deprecated("LevelFeatureLayer::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("LevelFeatureLayer::onDown not implemented")]]
    /**
     * @note[short] Android
     */
    void onDown(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("LevelFeatureLayer::onDown2 not implemented")]]
    /**
     * @note[short] Android
     */
    void onDown2(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("LevelFeatureLayer::onRemoveValues not implemented")]]
    /**
     * @note[short] Android
     */
    void onRemoveValues(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("LevelFeatureLayer::onSetEpicOnly not implemented")]]
    /**
     * @note[short] Android
     */
    void onSetEpicOnly(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("LevelFeatureLayer::onSetFeatured not implemented")]]
    /**
     * @note[short] Android
     */
    void onSetFeatured(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("LevelFeatureLayer::onToggleEpic not implemented")]]
    /**
     * @note[short] Android
     */
    void onToggleEpic(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("LevelFeatureLayer::onUp not implemented")]]
    /**
     * @note[short] Android
     */
    void onUp(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("LevelFeatureLayer::onUp2 not implemented")]]
    /**
     * @note[short] Android
     */
    void onUp2(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("LevelFeatureLayer::updateStars not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateStars();
public:
};
