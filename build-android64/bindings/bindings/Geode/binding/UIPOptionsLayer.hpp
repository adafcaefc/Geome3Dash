#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class UIPOptionsLayer {
public:
    static constexpr auto CLASS_NAME = "UIPOptionsLayer";

    /**
     * @note[short] Android
     */
    static UIPOptionsLayer* create();

    /**
     * @note[short] MacOS (ARM): 0x24aa70
     * @note[short] MacOS (Intel): 0x2a3c00
     * @note[short] Windows: 0x29e170
     * @note[short] iOS: 0x2e58fc
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (ARM): 0x24b160
     * @note[short] MacOS (Intel): 0x2a4350
     * @note[short] iOS: 0x2e5fd0
     * @note[short] Android
     */
    virtual bool ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);

    /**
     * @note[short] MacOS (ARM): 0x24b27c
     * @note[short] MacOS (Intel): 0x2a4470
     * @note[short] iOS: 0x2e6098
     * @note[short] Android
     */
    virtual void ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);

    /**
     * @note[short] MacOS (ARM): 0x24b3d8
     * @note[short] MacOS (Intel): 0x2a45e0
     * @note[short] iOS: 0x2e614c
     * @note[short] Android
     */
    virtual void ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);

    /**
     * @note[short] MacOS (ARM): 0x24b410
     * @note[short] MacOS (Intel): 0x2a4620
     * @note[short] iOS: 0x2e6184
     * @note[short] Android
     */
    virtual void ccTouchCancelled(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);

    /**
     * @note[short] MacOS (ARM): 0x24b42c
     * @note[short] MacOS (Intel): 0x2a4660
     * @note[short] iOS: 0x2e61a0
     * @note[short] Android
     */
    virtual void registerWithTouchDispatcher();

    /**
     * @note[short] MacOS (ARM): 0x24afa8
     * @note[short] MacOS (Intel): 0x2a4170
     * @note[short] iOS: 0x2e5e18
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x24b018
     * @note[short] MacOS (Intel): 0x2a41f0
     * @note[short] iOS: 0x2e5e88
     * @note[short] Android
     */
    virtual TodoReturn valueDidChange(int p0, float p1);

    /**
     * @note[short] MacOS (ARM): 0x24b0cc
     * @note[short] MacOS (Intel): 0x2a42c0
     * @note[short] iOS: 0x2e5f3c
     * @note[short] Android
     */
    virtual TodoReturn getValue(int p0);

    /**
     * @note[short] Android
     */
    TodoReturn getTouchRect();

    /**
     * @note[short] Android
     */
    void onReset(cocos2d::CCObject* sender);
};
