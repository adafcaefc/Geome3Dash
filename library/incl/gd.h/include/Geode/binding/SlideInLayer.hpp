#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class SlideInLayer : public cocos2d::CCLayerColor {
public:
    static constexpr auto CLASS_NAME = "SlideInLayer";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(SlideInLayer, cocos2d::CCLayerColor)
    
private:
    [[deprecated("SlideInLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SlideInLayer* create();
public:
    
private:
    [[deprecated("SlideInLayer::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2265e8
     * @note[short] MacOS (Intel): 0x27c670
     * @note[short] Android
     */
    virtual bool init();
public:
    
private:
    [[deprecated("SlideInLayer::draw not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x226cac
     * @note[short] MacOS (Intel): 0x27cda0
     * @note[short] Android
     */
    virtual void draw();
public:
    
private:
    [[deprecated("SlideInLayer::ccTouchBegan not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x226ce8
     * @note[short] MacOS (Intel): 0x27cdd0
     * @note[short] Android
     */
    virtual bool ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);
public:
    
private:
    [[deprecated("SlideInLayer::ccTouchMoved not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x226d08
     * @note[short] MacOS (Intel): 0x27ce30
     * @note[short] Android
     */
    virtual void ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);
public:
    
private:
    [[deprecated("SlideInLayer::ccTouchEnded not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x226cf8
     * @note[short] MacOS (Intel): 0x27cdf0
     * @note[short] Android
     */
    virtual void ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);
public:
    
private:
    [[deprecated("SlideInLayer::ccTouchCancelled not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x226d00
     * @note[short] MacOS (Intel): 0x27ce10
     * @note[short] Android
     */
    virtual void ccTouchCancelled(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);
public:
    
private:
    [[deprecated("SlideInLayer::registerWithTouchDispatcher not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2269cc
     * @note[short] MacOS (Intel): 0x27caa0
     * @note[short] Android
     */
    virtual void registerWithTouchDispatcher();
public:
    
private:
    [[deprecated("SlideInLayer::keyBackClicked not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x226a04
     * @note[short] MacOS (Intel): 0x27cae0
     * @note[short] Android
     */
    virtual void keyBackClicked();
public:
    
private:
    [[deprecated("SlideInLayer::customSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x226968
     * @note[short] MacOS (Intel): 0x27ca20
     * @note[short] Android
     */
    virtual void customSetup();
public:
    
private:
    [[deprecated("SlideInLayer::enterLayer not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x226994
     * @note[short] MacOS (Intel): 0x27ca70
     * @note[short] Android
     */
    virtual TodoReturn enterLayer();
public:
    
private:
    [[deprecated("SlideInLayer::exitLayer not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x226a28
     * @note[short] MacOS (Intel): 0x27cb20
     * @note[short] Android
     */
    virtual TodoReturn exitLayer(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("SlideInLayer::showLayer not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x226a8c
     * @note[short] MacOS (Intel): 0x27cb70
     * @note[short] Android
     */
    virtual void showLayer(bool p0);
public:
    
private:
    [[deprecated("SlideInLayer::hideLayer not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x226b7c
     * @note[short] MacOS (Intel): 0x27cc60
     * @note[short] Android
     */
    virtual TodoReturn hideLayer(bool p0);
public:
    
private:
    [[deprecated("SlideInLayer::layerVisible not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x226c4c
     * @note[short] MacOS (Intel): 0x27cd40
     * @note[short] Android
     */
    virtual TodoReturn layerVisible();
public:
    
private:
    [[deprecated("SlideInLayer::layerHidden not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x226c5c
     * @note[short] MacOS (Intel): 0x27cd60
     * @note[short] Android
     */
    virtual void layerHidden();
public:
    
private:
    [[deprecated("SlideInLayer::enterAnimFinished not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x226c48
     * @note[short] MacOS (Intel): 0x27cd30
     * @note[short] Android
     */
    virtual void enterAnimFinished();
public:
    
private:
    [[deprecated("SlideInLayer::disableUI not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x22696c
     * @note[short] MacOS (Intel): 0x27ca30
     * @note[short] Android
     */
    virtual void disableUI();
public:
    
private:
    [[deprecated("SlideInLayer::enableUI not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x226980
     * @note[short] MacOS (Intel): 0x27ca50
     * @note[short] Android
     */
    virtual void enableUI();
public:
};
