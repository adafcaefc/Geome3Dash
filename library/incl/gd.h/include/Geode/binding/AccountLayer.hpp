#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "GJDropDownLayer.hpp"
#include "GJAccountDelegate.hpp"
#include "GJAccountBackupDelegate.hpp"
#include "GJAccountSyncDelegate.hpp"
#include "FLAlertLayerProtocol.hpp"

class AccountLayer : public GJDropDownLayer, public GJAccountDelegate, public GJAccountBackupDelegate, public GJAccountSyncDelegate, public FLAlertLayerProtocol {
public:
    static constexpr auto CLASS_NAME = "AccountLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(AccountLayer, GJDropDownLayer)

    /**
     * @note[short] Windows: 0x7d560
     * @note[short] Android
     */
    static AccountLayer* create();

    /**
     * @note[short] MacOS (ARM): 0xb530c
     * @note[short] MacOS (Intel): 0xcc490
     * @note[short] Windows: 0x7d6c0
     * @note[short] iOS: 0x168d38
     * @note[short] Android
     */
    virtual void customSetup();

    /**
     * @note[short] MacOS (ARM): 0xb72fc
     * @note[short] MacOS (Intel): 0xce520
     * @note[short] Windows: 0x7f450
     * @note[short] iOS: 0x16a450
     * @note[short] Android
     */
    virtual void layerHidden();

    /**
     * @note[short] MacOS (ARM): 0xb6888
     * @note[short] MacOS (Intel): 0xcda30
     * @note[short] Windows: 0x7eb30
     * @note[short] iOS: 0x169d60
     * @note[short] Android
     */
    virtual void backupAccountFinished();

    /**
     * @note[short] MacOS (ARM): 0xb6a48
     * @note[short] MacOS (Intel): 0xcdbf0
     * @note[short] Windows: 0x7ece0
     * @note[short] iOS: 0x169e94
     * @note[short] Android
     */
    virtual void backupAccountFailed(BackupAccountError p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0xb6dd8
     * @note[short] MacOS (Intel): 0xcdfd0
     * @note[short] Windows: 0x7eff0
     * @note[short] iOS: 0x16a100
     * @note[short] Android
     */
    virtual void syncAccountFinished();

    /**
     * @note[short] MacOS (ARM): 0xb6f40
     * @note[short] MacOS (Intel): 0xce150
     * @note[short] Windows: 0x7f1b0
     * @note[short] iOS: 0x16a234
     * @note[short] Android
     */
    virtual void syncAccountFailed(BackupAccountError p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0xb6874
     * @note[short] MacOS (Intel): 0xcda00
     * @note[short] Windows: 0x7e750
     * @note[short] iOS: 0x169d4c
     * @note[short] Android
     */
    virtual void accountStatusChanged();

    /**
     * @note[short] MacOS (ARM): 0xb71cc
     * @note[short] MacOS (Intel): 0xce400
     * @note[short] Windows: 0x7f340
     * @note[short] iOS: 0x16a3b4
     * @note[short] Android
     */
    virtual void FLAlert_Clicked(FLAlertLayer* p0, bool p1);
    
private:
    [[deprecated("AccountLayer::createToggleButton not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createToggleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCMenu* p3, cocos2d::CCPoint p4);
public:

    /**
     * @note[short] MacOS (ARM): 0xb6708
     * @note[short] MacOS (Intel): 0xcd8a0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void doBackup();

    /**
     * @note[short] MacOS (ARM): 0xb67e4
     * @note[short] MacOS (Intel): 0xcd970
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void doSync();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void exitLayer();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void hideLoadingUI();
    
private:
    [[deprecated("AccountLayer::onBackup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xb5a14
     * @note[short] MacOS (Intel): 0xccbf0
     * @note[short] Android
     */
    void onBackup(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("AccountLayer::onHelp not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xb5f34
     * @note[short] MacOS (Intel): 0xcd130
     * @note[short] Android
     */
    void onHelp(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("AccountLayer::onLogin not implemented")]]
    /**
     * @note[short] Android
     */
    void onLogin(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("AccountLayer::onMore not implemented")]]
    /**
     * @note[short] Android
     */
    void onMore(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] Windows: 0x7de50
     * @note[short] Android
     */
    void onRegister(cocos2d::CCObject* sender);
    
private:
    [[deprecated("AccountLayer::onSync not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xb5d2c
     * @note[short] MacOS (Intel): 0xccf40
     * @note[short] Android
     */
    void onSync(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void showLoadingUI();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void toggleUI(bool enable);

    /**
     * @note[short] MacOS (ARM): 0xb601c
     * @note[short] MacOS (Intel): 0xcd210
     * @note[short] Windows: 0x7e760
     * @note[short] Android
     */
    void updatePage(bool p0);
    cocos2d::CCLabelBMFont* m_linkedAccountTitle;
    TextArea* m_textArea;
    CCMenuItemSpriteExtra* m_loginButton;
    CCMenuItemSpriteExtra* m_registerButton;
    CCMenuItemSpriteExtra* m_backupButton;
    CCMenuItemSpriteExtra* m_syncButton;
    CCMenuItemSpriteExtra* m_helpButton;
    CCMenuItemSpriteExtra* m_moreButton;
    LoadingCircle* m_loadingCircle;
    int m_accountHelpRelated;
    bool m_isLoggedIn;
};
