#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "BoomScrollLayerDelegate.hpp"

class WorldSelectLayer : public cocos2d::CCLayer, public BoomScrollLayerDelegate {
public:
    static constexpr auto CLASS_NAME = "WorldSelectLayer";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(WorldSelectLayer, cocos2d::CCLayer)
    
private:
    [[deprecated("WorldSelectLayer::create not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3aed30
     * @note[short] Android
     */
    static WorldSelectLayer* create(int p0);
public:
    
private:
    [[deprecated("WorldSelectLayer::scene not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3aec20
     * @note[short] Android
     */
    static cocos2d::CCScene* scene(int p0);
public:
    
private:
    [[deprecated("WorldSelectLayer::onExit not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x33c594
     * @note[short] MacOS (Intel): 0x3b0b30
     * @note[short] Android
     */
    virtual void onExit();
public:
    
private:
    [[deprecated("WorldSelectLayer::keyBackClicked not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x33c4b4
     * @note[short] MacOS (Intel): 0x3b0a50
     * @note[short] Android
     */
    virtual void keyBackClicked();
public:
    
private:
    [[deprecated("WorldSelectLayer::scrollLayerWillScrollToPage not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x33c36c
     * @note[short] MacOS (Intel): 0x3b0960
     * @note[short] Android
     */
    virtual void scrollLayerWillScrollToPage(BoomScrollLayer* p0, int p1);
public:
    
private:
    [[deprecated("WorldSelectLayer::scrollLayerScrolledToPage not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x33c224
     * @note[short] MacOS (Intel): 0x3b0870
     * @note[short] Android
     */
    virtual void scrollLayerScrolledToPage(BoomScrollLayer* p0, int p1);
public:
    
private:
    [[deprecated("WorldSelectLayer::scrollLayerMoved not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x33c5e4
     * @note[short] MacOS (Intel): 0x3b0b80
     * @note[short] Android
     */
    virtual void scrollLayerMoved(cocos2d::CCPoint p0);
public:
    
private:
    [[deprecated("WorldSelectLayer::animateInActiveIsland not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn animateInActiveIsland();
public:
    
private:
    [[deprecated("WorldSelectLayer::colorForPage not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::ccColor3B colorForPage(int p0);
public:
    
private:
    [[deprecated("WorldSelectLayer::getColorValue not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getColorValue(int p0, int p1, float p2);
public:
    
private:
    [[deprecated("WorldSelectLayer::goToPage not implemented")]]
    /**
     * @note[short] Android
     */
    void goToPage(int p0, bool p1);
public:
    
private:
    [[deprecated("WorldSelectLayer::init not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3aee20
     * @note[short] Android
     */
    bool init(int p0);
public:
    
private:
    [[deprecated("WorldSelectLayer::onBack not implemented")]]
    /**
     * @note[short] Android
     */
    void onBack(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("WorldSelectLayer::onFreeLevels not implemented")]]
    /**
     * @note[short] Android
     */
    void onFreeLevels(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("WorldSelectLayer::onGarage not implemented")]]
    /**
     * @note[short] Android
     */
    void onGarage(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("WorldSelectLayer::onNext not implemented")]]
    /**
     * @note[short] Android
     */
    void onNext(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("WorldSelectLayer::onPrev not implemented")]]
    /**
     * @note[short] Android
     */
    void onPrev(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("WorldSelectLayer::setupWorlds not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x33b13c
     * @note[short] MacOS (Intel): 0x3af740
     * @note[short] Android
     */
    TodoReturn setupWorlds();
public:
    
private:
    [[deprecated("WorldSelectLayer::showCompleteDialog not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x33b724
     * @note[short] MacOS (Intel): 0x3afd60
     * @note[short] Android
     */
    void showCompleteDialog();
public:
    
private:
    [[deprecated("WorldSelectLayer::tryShowAd not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn tryShowAd();
public:
    
private:
    [[deprecated("WorldSelectLayer::unblockButtons not implemented")]]
    /**
     * @note[short] Android
     */
    void unblockButtons();
public:
    
private:
    [[deprecated("WorldSelectLayer::updateArrows not implemented")]]
    /**
     * @note[short] Android
     */
    void updateArrows();
public:
    cocos2d::CCSprite* m_background;
    BoomScrollLayer* m_scrollLayer;
    CCMenuItemSpriteExtra* m_arrowLeft;
    CCMenuItemSpriteExtra* m_arrowRight;
    bool m_cleanupSprites;
    bool m_unkBool1;
    GJWorldNode* m_worldNode;
    bool m_unkBool2;
};
