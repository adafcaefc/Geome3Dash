#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "FLAlertLayer.hpp"
#include "TextInputDelegate.hpp"
#include "GJAccountLoginDelegate.hpp"
#include "FLAlertLayerProtocol.hpp"

class AccountLoginLayer : public FLAlertLayer, public TextInputDelegate, public GJAccountLoginDelegate, public FLAlertLayerProtocol {
public:
    static constexpr auto CLASS_NAME = "AccountLoginLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(AccountLoginLayer, FLAlertLayer)

    /**
     * @note[short] Windows: 0x7b730
     * @note[short] Android
     */
    static AccountLoginLayer* create(gd::string p0);
    
private:
    [[deprecated("AccountLoginLayer::registerWithTouchDispatcher not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x3f4ff4
     * @note[short] MacOS (Intel): 0x487a60
     * @note[short] iOS: 0x88580
     * @note[short] Android
     */
    virtual void registerWithTouchDispatcher();
public:

    /**
     * @note[short] MacOS (ARM): 0x3f4ea4
     * @note[short] MacOS (Intel): 0x487920
     * @note[short] Windows: 0x7cfa0
     * @note[short] iOS: 0x88494
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x3f4c90
     * @note[short] MacOS (Intel): 0x487760
     * @note[short] Windows: 0x7cb50
     * @note[short] iOS: 0x8839c
     * @note[short] Android
     */
    virtual void FLAlert_Clicked(FLAlertLayer* p0, bool p1);

    /**
     * @note[short] MacOS (ARM): 0x3f51c4
     * @note[short] MacOS (Intel): 0x487c10
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x886e8
     * @note[short] Android: Out of line
     */
    virtual void textInputOpened(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x3f502c
     * @note[short] MacOS (Intel): 0x487aa0
     * @note[short] Windows: 0x7d070
     * @note[short] iOS: 0x885b8
     * @note[short] Android
     */
    virtual void textInputClosed(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x3f51cc
     * @note[short] MacOS (Intel): 0x487c30
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x886f0
     * @note[short] Android: Out of line
     */
    virtual void textChanged(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x3f45bc
     * @note[short] MacOS (Intel): 0x4870a0
     * @note[short] Windows: 0x7c740
     * @note[short] iOS: 0x87ee8
     * @note[short] Android
     */
    virtual void loginAccountFinished(int p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0x3f493c
     * @note[short] MacOS (Intel): 0x487430
     * @note[short] Windows: 0x7c990
     * @note[short] iOS: 0x880f8
     * @note[short] Android
     */
    virtual void loginAccountFailed(AccountError p0);
    
private:
    [[deprecated("AccountLoginLayer::createTextBackground not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createTextBackground(cocos2d::CCPoint p0, char const* p1, cocos2d::CCSize p2);
public:
    
private:
    [[deprecated("AccountLoginLayer::createTextInput not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createTextInput(cocos2d::CCPoint p0, cocos2d::CCSize p1, char const* p2, int p3);
public:
    
private:
    [[deprecated("AccountLoginLayer::createTextLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createTextLabel(cocos2d::CCPoint p0, char const* p1, cocos2d::CCSize p2);
public:
    
private:
    [[deprecated("AccountLoginLayer::disableNodes not implemented")]]
    /**
     * @note[short] Android
     */
    void disableNodes();
public:
    
private:
    [[deprecated("AccountLoginLayer::hideLoadingUI not implemented")]]
    /**
     * @note[short] Android
     */
    void hideLoadingUI();
public:

    /**
     * @note[short] MacOS (ARM): 0x3f32c0
     * @note[short] MacOS (Intel): 0x485ce0
     * @note[short] Windows: 0x7b8d0
     * @note[short] Android
     */
    bool init(gd::string p0);
    
private:
    [[deprecated("AccountLoginLayer::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (Intel): 0x487080
     * @note[short] Windows: 0x7c490
     * @note[short] Android
     */
    void onForgotPassword(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (Intel): 0x487060
     * @note[short] Windows: 0x7c470
     * @note[short] Android
     */
    void onForgotUser(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x7cbc0
     * @note[short] Android
     */
    void onSubmit(cocos2d::CCObject* sender);
    
private:
    [[deprecated("AccountLoginLayer::resetLabel not implemented")]]
    /**
     * @note[short] Android
     */
    void resetLabel(int p0);
public:
    
private:
    [[deprecated("AccountLoginLayer::resetLabels not implemented")]]
    /**
     * @note[short] Android
     */
    void resetLabels();
public:
    
private:
    [[deprecated("AccountLoginLayer::showLoadingUI not implemented")]]
    /**
     * @note[short] Android
     */
    void showLoadingUI();
public:
    
private:
    [[deprecated("AccountLoginLayer::toggleUI not implemented")]]
    /**
     * @note[short] Android
     */
    void toggleUI(bool p0);
public:
    
private:
    [[deprecated("AccountLoginLayer::updateLabel not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x3f49d0
     * @note[short] MacOS (Intel): 0x4874c0
     * @note[short] Android
     */
    void updateLabel(AccountError p0);
public:
    CCTextInputNode* m_usernameInput;
    CCTextInputNode* m_passwordInput;
    cocos2d::CCLabelBMFont* m_usernameLabel;
    cocos2d::CCLabelBMFont* m_passwordLabel;
    LoadingCircle* m_loadingCircle;
    gd::string m_username;
    gd::string m_password;
};
