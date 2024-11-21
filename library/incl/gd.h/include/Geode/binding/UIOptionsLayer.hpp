#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "SetupTriggerPopup.hpp"

class UIOptionsLayer : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "UIOptionsLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(UIOptionsLayer, SetupTriggerPopup)

    /**
     * @note[short] MacOS (Intel): 0x29e540
     * @note[short] Windows: 0x2995e0
     * @note[short] Android
     */
    static UIOptionsLayer* create(bool p0);

    /**
     * @note[short] MacOS (ARM): 0x248680
     * @note[short] MacOS (Intel): 0x2a17c0
     * @note[short] Windows: 0x29c640
     * @note[short] iOS: 0x2e4038
     * @note[short] Android
     */
    virtual bool ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);

    /**
     * @note[short] MacOS (ARM): 0x248840
     * @note[short] MacOS (Intel): 0x2a1990
     * @note[short] Windows: 0x29c790
     * @note[short] iOS: 0x2e41cc
     * @note[short] Android
     */
    virtual void ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);

    /**
     * @note[short] MacOS (ARM): 0x248a2c
     * @note[short] MacOS (Intel): 0x2a1b30
     * @note[short] Windows: 0x29c8c0
     * @note[short] iOS: 0x2e4314
     * @note[short] Android
     */
    virtual void ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);
    
private:
    [[deprecated("UIOptionsLayer::ccTouchCancelled not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x248b64
     * @note[short] MacOS (Intel): 0x2a1c70
     * @note[short] iOS: 0x2e43ac
     * @note[short] Android
     */
    virtual void ccTouchCancelled(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);
public:
    
private:
    [[deprecated("UIOptionsLayer::registerWithTouchDispatcher not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x248b80
     * @note[short] MacOS (Intel): 0x2a1cb0
     * @note[short] iOS: 0x2e43c8
     * @note[short] Android
     */
    virtual void registerWithTouchDispatcher();
public:
    
private:
    [[deprecated("UIOptionsLayer::onClose not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x248060
     * @note[short] MacOS (Intel): 0x2a1040
     * @note[short] iOS: 0x2e3ba4
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("UIOptionsLayer::valueDidChange not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2481b0
     * @note[short] MacOS (Intel): 0x2a11d0
     * @note[short] iOS: 0x2e3cf4
     * @note[short] Android
     */
    virtual void valueDidChange(int p0, float p1);
public:
    
private:
    [[deprecated("UIOptionsLayer::getValue not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x248414
     * @note[short] MacOS (Intel): 0x2a14e0
     * @note[short] iOS: 0x2e3ecc
     * @note[short] Android
     */
    virtual float getValue(int p0);
public:
    
private:
    [[deprecated("UIOptionsLayer::getNode not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getNode(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x24645c
     * @note[short] MacOS (Intel): 0x29ef50
     * @note[short] Windows: 0x299720
     * @note[short] Android
     */
    bool init(bool p0);
    
private:
    [[deprecated("UIOptionsLayer::onReset not implemented")]]
    /**
     * @note[short] Android
     */
    void onReset(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("UIOptionsLayer::onSaveLoad not implemented")]]
    /**
     * @note[short] Android
     */
    void onSaveLoad(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("UIOptionsLayer::toggleUIGroup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x247d74
     * @note[short] MacOS (Intel): 0x2a0ce0
     * @note[short] Android
     */
    TodoReturn toggleUIGroup(int p0);
public:
};
