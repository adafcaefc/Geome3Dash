#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class ScrollingLayer : public cocos2d::CCLayerColor {
public:
    static constexpr auto CLASS_NAME = "ScrollingLayer";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(ScrollingLayer, cocos2d::CCLayerColor)
    
private:
    [[deprecated("ScrollingLayer::create not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x629898
     * @note[short] MacOS (Intel): 0x340380
     * @note[short] Android
     */
    static ScrollingLayer* create(cocos2d::CCSize p0, cocos2d::CCPoint p1, float p2);
public:
    
private:
    [[deprecated("ScrollingLayer::draw not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x629b24
     * @note[short] MacOS (Intel): 0x70a580
     * @note[short] iOS: 0x1ba978
     * @note[short] Android
     */
    virtual void draw();
public:
    
private:
    [[deprecated("ScrollingLayer::visit not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x629bc8
     * @note[short] MacOS (Intel): 0x70a650
     * @note[short] iOS: 0x1baa1c
     * @note[short] Android
     */
    virtual void visit();
public:

    /**
     * @note[short] MacOS (ARM): 0x629cdc
     * @note[short] MacOS (Intel): 0x70a7a0
     * @note[short] Windows: 0x70ff0
     * @note[short] iOS: 0x1baaa4
     * @note[short] Android
     */
    virtual bool ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);

    /**
     * @note[short] MacOS (ARM): 0x629e38
     * @note[short] MacOS (Intel): 0x70a940
     * @note[short] Windows: 0x710e0
     * @note[short] iOS: 0x1bab64
     * @note[short] Android
     */
    virtual void ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);

    /**
     * @note[short] MacOS (ARM): 0x629f34
     * @note[short] MacOS (Intel): 0x70aa60
     * @note[short] Windows: 0x711f0
     * @note[short] iOS: 0x1bac60
     * @note[short] Android
     */
    virtual void ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);
    
private:
    [[deprecated("ScrollingLayer::ccTouchCancelled not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x629f6c
     * @note[short] MacOS (Intel): 0x70aaa0
     * @note[short] iOS: 0x1bac98
     * @note[short] Android
     */
    virtual void ccTouchCancelled(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);
public:
    
private:
    [[deprecated("ScrollingLayer::getViewRect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getViewRect();
public:
    
private:
    [[deprecated("ScrollingLayer::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(cocos2d::CCSize p0, cocos2d::CCPoint p1, float p2);
public:
    
private:
    [[deprecated("ScrollingLayer::setStartOffset not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x629ca4
     * @note[short] MacOS (Intel): 0x70a760
     * @note[short] Android
     */
    void setStartOffset(cocos2d::CCPoint p0);
public:
};
