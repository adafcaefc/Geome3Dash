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
#include "DialogDelegate.hpp"

class SecretLayer2 : public cocos2d::CCLayer, public TextInputDelegate, public FLAlertLayerProtocol, public DialogDelegate {
public:
    static constexpr auto CLASS_NAME = "SecretLayer2";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(SecretLayer2, cocos2d::CCLayer)
    
private:
    [[deprecated("SecretLayer2::create not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x489fc0
     * @note[short] Android
     */
    static SecretLayer2* create();
public:

    /**
     * @note[short] MacOS (Intel): 0x489f80
     * @note[short] Windows: 0x3cadf0
     * @note[short] Android
     */
    static cocos2d::CCScene* scene();

    /**
     * @note[short] MacOS (ARM): 0x3f73b4
     * @note[short] MacOS (Intel): 0x48a0f0
     * @note[short] Windows: 0x3caf70
     * @note[short] iOS: 0x309960
     * @note[short] Android
     */
    virtual bool init();
    
private:
    [[deprecated("SecretLayer2::onExit not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x3fce88
     * @note[short] MacOS (Intel): 0x4900c0
     * @note[short] iOS: 0x30dc8c
     * @note[short] Android
     */
    virtual void onExit();
public:

    /**
     * @note[short] MacOS (ARM): 0x3fcd9c
     * @note[short] MacOS (Intel): 0x48ffd0
     * @note[short] Windows: 0x3d2590
     * @note[short] iOS: 0x30dc80
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x3fbe64
     * @note[short] MacOS (Intel): 0x48f060
     * @note[short] Windows: 0x3cfa10
     * @note[short] iOS: 0x30d318
     * @note[short] Android
     */
    virtual void textInputOpened(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x3fbf44
     * @note[short] MacOS (Intel): 0x48f130
     * @note[short] Windows: 0x3cfb60
     * @note[short] iOS: 0x30d404
     * @note[short] Android
     */
    virtual void textInputClosed(CCTextInputNode* p0);
    
private:
    [[deprecated("SecretLayer2::textChanged not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x3fc054
     * @note[short] MacOS (Intel): 0x48f200
     * @note[short] iOS: 0x30d484
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x3fbe5c
     * @note[short] MacOS (Intel): 0x48f040
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x30d310
     * @note[short] Android: Out of line
     */
    virtual void FLAlert_Clicked(FLAlertLayer* p0, bool p1);

    /**
     * @note[short] MacOS (ARM): 0x3fa9c0
     * @note[short] MacOS (Intel): 0x48dbb0
     * @note[short] Windows: 0x3cd250
     * @note[short] iOS: 0x30c6f4
     * @note[short] Android
     */
    virtual void dialogClosed(DialogLayer* p0);

    /**
     * @note[short] MacOS (ARM): 0x3fc23c
     * @note[short] MacOS (Intel): 0x48f3c0
     * @note[short] Windows: 0x3d0880
     * @note[short] Android
     */
    gd::string getBasicMessage();

    /**
     * @note[short] Windows: 0x3d13e0
     * @note[short] Android
     */
    gd::string getErrorMessage();

    /**
     * @note[short] Windows: 0x3cffb0
     * @note[short] Android
     */
    gd::string getMessage();

    /**
     * @note[short] MacOS (ARM): 0x3fc958
     * @note[short] MacOS (Intel): 0x48faa0
     * @note[short] Windows: 0x3d0190
     * @note[short] Android
     */
    gd::string getThreadMessage();
    
private:
    [[deprecated("SecretLayer2::nodeWithTag not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn nodeWithTag(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x3f8594
     * @note[short] MacOS (Intel): 0x48b320
     * @note[short] Windows: 0x3d24e0
     * @note[short] Android
     */
    void onBack(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x3f9a70
     * @note[short] MacOS (Intel): 0x48ca80
     * @note[short] Windows: 0x3cd5a0
     * @note[short] Android
     */
    void onDoor(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x3f9cd4
     * @note[short] MacOS (Intel): 0x48ccc0
     * @note[short] Windows: 0x3cd2f0
     * @note[short] Android
     */
    void onSecretLevel(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x3f8608
     * @note[short] MacOS (Intel): 0x48b390
     * @note[short] Windows: 0x3cdf00
     * @note[short] Android
     */
    void onSubmit(cocos2d::CCObject* sender);
    
private:
    [[deprecated("SecretLayer2::playCoinEffect not implemented")]]
    /**
     * @note[short] Android
     */
    void playCoinEffect();
public:
    
private:
    [[deprecated("SecretLayer2::selectAThread not implemented")]]
    /**
     * @note[short] Android
     */
    void selectAThread();
public:

    /**
     * @note[short] MacOS (ARM): 0x3f9e98
     * @note[short] MacOS (Intel): 0x48ce80
     * @note[short] Windows: 0x3cc5a0
     * @note[short] Android
     */
    void showCompletedLevel();

    /**
     * @note[short] Windows: 0x3cc430
     * @note[short] Android
     */
    void showSecretLevel();

    /**
     * @note[short] Windows: 0x3cff20
     * @note[short] Android
     */
    void updateMessageLabel(gd::string text);

    /**
     * @note[short] MacOS (ARM): 0x3f831c
     * @note[short] MacOS (Intel): 0x48b090
     * @note[short] Windows: 0x3cfc30
     * @note[short] Android
     */
    void updateSearchLabel(char const* p0);
};
