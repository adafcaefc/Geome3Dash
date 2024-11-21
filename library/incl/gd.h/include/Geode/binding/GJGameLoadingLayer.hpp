#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJGameLoadingLayer : public cocos2d::CCLayer {
public:
    static constexpr auto CLASS_NAME = "GJGameLoadingLayer";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJGameLoadingLayer, cocos2d::CCLayer)
    
private:
    [[deprecated("GJGameLoadingLayer::create not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x1546e0
     * @note[short] Android
     */
    static GJGameLoadingLayer* create(GJGameLevel* level, bool editor);
public:

    /**
     * @note[short] Windows: 0x242890
     * @note[short] Android
     */
    static GJGameLoadingLayer* transitionToLoadingLayer(GJGameLevel* level, bool editor);
    
private:
    [[deprecated("GJGameLoadingLayer::onEnter not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1286f4
     * @note[short] MacOS (Intel): 0x154bb0
     * @note[short] iOS: 0x20b7f4
     * @note[short] Android
     */
    virtual void onEnter();
public:
    
private:
    [[deprecated("GJGameLoadingLayer::onEnterTransitionDidFinish not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1286f0
     * @note[short] MacOS (Intel): 0x154ba0
     * @note[short] iOS: 0x20b7f0
     * @note[short] Android
     */
    virtual void onEnterTransitionDidFinish();
public:
    
private:
    [[deprecated("GJGameLoadingLayer::gameLayerDidUnload not implemented")]]
    /**
     * @note[short] Android
     */
    void gameLayerDidUnload();
public:
    
private:
    [[deprecated("GJGameLoadingLayer::init not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x154a40
     * @note[short] Android
     */
    bool init(GJGameLevel* level, bool editor);
public:

    /**
     * @note[short] MacOS (ARM): 0x12868c
     * @note[short] MacOS (Intel): 0x154b40
     * @note[short] Windows: 0x242a80
     * @note[short] Android
     */
    void loadLevel();
    GJGameLevel* m_level;
    bool m_editor;
};
