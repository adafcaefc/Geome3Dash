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

class LevelAreaLayer : public cocos2d::CCLayer, public DialogDelegate {
public:
    static constexpr auto CLASS_NAME = "LevelAreaLayer";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(LevelAreaLayer, cocos2d::CCLayer)

    /**
     * @note[short] Android
     */
    static LevelAreaLayer* create();

    /**
     * @note[short] Android
     */
    static cocos2d::CCScene* scene();

    /**
     * @note[short] MacOS (ARM): 0x2111e8
     * @note[short] MacOS (Intel): 0x2658d0
     * @note[short] Windows: 0x2bc1d0
     * @note[short] iOS: 0x34353c
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (ARM): 0x2133f4
     * @note[short] MacOS (Intel): 0x267ab0
     * @note[short] Windows: 0x2be1c0
     * @note[short] iOS: 0x344fe4
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x213170
     * @note[short] MacOS (Intel): 0x267810
     * @note[short] Windows: 0x2bd3b0
     * @note[short] iOS: 0x344e04
     * @note[short] Android
     */
    virtual void dialogClosed(DialogLayer* p0);

    /**
     * @note[short] MacOS (ARM): 0x2133a4
     * @note[short] MacOS (Intel): 0x267a60
     * @note[short] Windows: 0x2be170
     * @note[short] iOS: 0x344f94
     * @note[short] Android
     */
    virtual void onExit();

    /**
     * @note[short] Android
     */
    cocos2d::CCAction* addGodRay(float p0, float p1, float p2, float p3, float p4, cocos2d::CCPoint p5);

    /**
     * @note[short] MacOS (ARM): 0x2124b0
     * @note[short] MacOS (Intel): 0x266be0
     * @note[short] Android
     */
    TodoReturn addTorch(cocos2d::CCNode* p0, cocos2d::CCPoint p1, int p2, float p3, int p4, bool p5, int p6, cocos2d::CCArray* p7);

    /**
     * @note[short] Android
     */
    cocos2d::CCAction* fadeInsideTower();

    /**
     * @note[short] Android
     */
    void onBack(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onClickDoor(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x21322c
     * @note[short] Android
     */
    bool onEnterTower();

    /**
     * @note[short] MacOS (ARM): 0x212f20
     * @note[short] MacOS (Intel): 0x2675e0
     * @note[short] Android
     */
    cocos2d::CCAction* showDialog();
};
