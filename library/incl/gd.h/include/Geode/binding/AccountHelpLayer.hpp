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
#include "FLAlertLayerProtocol.hpp"

class AccountHelpLayer : public GJDropDownLayer, public GJAccountDelegate, public FLAlertLayerProtocol {
public:
    static constexpr auto CLASS_NAME = "AccountHelpLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(AccountHelpLayer, GJDropDownLayer)
    
private:
    [[deprecated("AccountHelpLayer::create not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xb7368
     * @note[short] MacOS (Intel): 0xce580
     * @note[short] Android
     */
    static AccountHelpLayer* create();
public:

    /**
     * @note[short] MacOS (ARM): 0xb77d4
     * @note[short] MacOS (Intel): 0xceb60
     * @note[short] Windows: 0x7f5c0
     * @note[short] iOS: 0x16a644
     * @note[short] Android
     */
    virtual void customSetup();
    
private:
    [[deprecated("AccountHelpLayer::layerHidden not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xb844c
     * @note[short] MacOS (Intel): 0xcf810
     * @note[short] iOS: 0x16b0cc
     * @note[short] Android
     */
    virtual void layerHidden();
public:

    /**
     * @note[short] MacOS (ARM): 0xb8300
     * @note[short] MacOS (Intel): 0xcf6d0
     * @note[short] Windows: 0x7fcc0
     * @note[short] iOS: 0x16b018
     * @note[short] Android
     */
    virtual void accountStatusChanged();

    /**
     * @note[short] MacOS (ARM): 0xb830c
     * @note[short] MacOS (Intel): 0xcf700
     * @note[short] Windows: 0x7ffa0
     * @note[short] iOS: 0x16b024
     * @note[short] Android
     */
    virtual void FLAlert_Clicked(FLAlertLayer* p0, bool p1);
    
private:
    [[deprecated("AccountHelpLayer::doUnlink not implemented")]]
    /**
     * @note[short] Android
     */
    void doUnlink();
public:
    
private:
    [[deprecated("AccountHelpLayer::exitLayer not implemented")]]
    /**
     * @note[short] Android
     */
    void exitLayer();
public:

    /**
     * @note[short] MacOS (ARM): 0xb7bf0
     * @note[short] MacOS (Intel): 0xcefa0
     * @note[short] Windows: 0x7fa10
     * @note[short] Android
     */
    void onAccountManagement(cocos2d::CCObject* sender);
    
private:
    [[deprecated("AccountHelpLayer::onReLogin not implemented")]]
    /**
     * @note[short] Android
     */
    void onReLogin(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0xb7cc4
     * @note[short] MacOS (Intel): 0xcf070
     * @note[short] Windows: 0x7fb20
     * @note[short] Android
     */
    void onUnlink(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0xb7e88
     * @note[short] MacOS (Intel): 0xcf230
     * @note[short] Windows: 0x7fcd0
     * @note[short] Android
     */
    void updatePage();
    
private:
    [[deprecated("AccountHelpLayer::verifyUnlink not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xb81d4
     * @note[short] MacOS (Intel): 0xcf580
     * @note[short] Android
     */
    void verifyUnlink();
public:
    cocos2d::CCLabelBMFont* m_loginStatusLabel;
    TextArea* m_textArea;
    CCMenuItemSpriteExtra* m_refreshLoginButton;
    CCMenuItemSpriteExtra* m_unlinkAccountButton;
    bool m_unk290;
};
