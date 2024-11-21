#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "GJOptionsLayer.hpp"

class GameOptionsLayer : public GJOptionsLayer {
public:
    static constexpr auto CLASS_NAME = "GameOptionsLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(GameOptionsLayer, GJOptionsLayer)

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
     GameOptionsLayer();

    /**
     * @note[short] MacOS (ARM): 0x244f94
     * @note[short] MacOS (Intel): 0x29d740
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static GameOptionsLayer* create(GJBaseGameLayer* baseGameLayer);

    /**
     * @note[short] MacOS (ARM): 0x24519c
     * @note[short] MacOS (Intel): 0x29da00
     * @note[short] Windows: 0x2978e0
     * @note[short] iOS: 0x2e1350
     * @note[short] Android
     */
    virtual void setupOptions();

    /**
     * @note[short] MacOS (ARM): 0x245e98
     * @note[short] MacOS (Intel): 0x29e7e0
     * @note[short] Windows: 0x298ed0
     * @note[short] iOS: 0x2e1e6c
     * @note[short] Android
     */
    virtual void didToggle(int p0);

    /**
     * @note[short] MacOS (Intel): 0x29d9b0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    bool init(GJBaseGameLayer* baseGameLayer);
    
private:
    [[deprecated("GameOptionsLayer::onPracticeMusicSync not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2458f4
     * @note[short] Android
     */
    void onPracticeMusicSync(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] Windows: 0x298d60
     * @note[short] Android
     */
    void onUIOptions(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x245888
     * @note[short] Windows: 0x298d80
     * @note[short] Android
     */
    void onUIPOptions(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x245968
     * @note[short] MacOS (Intel): 0x29e230
     * @note[short] Windows: 0x298380
     * @note[short] Android
     */
    void showPracticeMusicSyncUnlockInfo();
    GJBaseGameLayer* m_baseGameLayer;
    int m_practiceDialogIndex;
};
