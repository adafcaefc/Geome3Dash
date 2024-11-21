#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "TextInputDelegate.hpp"
#include "FLAlertLayerProtocol.hpp"

class SecretLayer : public cocos2d::CCLayer, public TextInputDelegate, public FLAlertLayerProtocol {
public:
    static constexpr auto CLASS_NAME = "SecretLayer";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(SecretLayer, cocos2d::CCLayer)
    
private:
    [[deprecated("SecretLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SecretLayer* create();
public:
    
private:
    [[deprecated("SecretLayer::scene not implemented")]]
    /**
     * @note[short] Android
     */
    static cocos2d::CCScene* scene();
public:

    /**
     * @note[short] MacOS (ARM): 0x515624
     * @note[short] MacOS (Intel): 0x5e31b0
     * @note[short] Windows: 0x3c5700
     * @note[short] iOS: 0x3b58ac
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (ARM): 0x518d94
     * @note[short] MacOS (Intel): 0x5e6fe0
     * @note[short] Windows: 0x3cabb0
     * @note[short] iOS: 0x3b85a4
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x51818c
     * @note[short] MacOS (Intel): 0x5e60c0
     * @note[short] Windows: 0x3c84b0
     * @note[short] iOS: 0x3b7ab0
     * @note[short] Android
     */
    virtual void textInputOpened(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x51826c
     * @note[short] MacOS (Intel): 0x5e6190
     * @note[short] Windows: 0x3c8600
     * @note[short] iOS: 0x3b7b9c
     * @note[short] Android
     */
    virtual void textInputClosed(CCTextInputNode* p0);
    
private:
    [[deprecated("SecretLayer::textChanged not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x51837c
     * @note[short] MacOS (Intel): 0x5e6260
     * @note[short] iOS: 0x3b7c1c
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x518184
     * @note[short] MacOS (Intel): 0x5e60a0
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x3b7aa8
     * @note[short] Android: Out of line
     */
    virtual void FLAlert_Clicked(FLAlertLayer* p0, bool p1);
    
private:
    [[deprecated("SecretLayer::getBasicMessage not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x5e5aa0
     * @note[short] Android
     */
    TodoReturn getBasicMessage();
public:
    
private:
    [[deprecated("SecretLayer::getMessage not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getMessage();
public:
    
private:
    [[deprecated("SecretLayer::getThreadMessage not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x518564
     * @note[short] MacOS (Intel): 0x5e6420
     * @note[short] Android
     */
    TodoReturn getThreadMessage();
public:
    
private:
    [[deprecated("SecretLayer::nodeWithTag not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn nodeWithTag(int p0);
public:

    /**
     * @note[short] Windows: 0x3cab10
     * @note[short] Android
     */
    void onBack(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x516584
     * @note[short] MacOS (Intel): 0x5e4170
     * @note[short] Windows: 0x3c6a40
     * @note[short] Android
     */
    void onSubmit(cocos2d::CCObject* sender);
    
private:
    [[deprecated("SecretLayer::playCoinEffect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn playCoinEffect();
public:
    
private:
    [[deprecated("SecretLayer::selectAThread not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn selectAThread();
public:
    
private:
    [[deprecated("SecretLayer::updateMessageLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateMessageLabel(gd::string p0);
public:
    
private:
    [[deprecated("SecretLayer::updateSearchLabel not implemented")]]
    /**
     * @note[short] Android
     */
    void updateSearchLabel(char const* p0);
public:
};
