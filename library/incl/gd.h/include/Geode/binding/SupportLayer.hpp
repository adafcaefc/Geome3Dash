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
#include "FLAlertLayerProtocol.hpp"
#include "UploadActionDelegate.hpp"
#include "UploadPopupDelegate.hpp"

class SupportLayer : public GJDropDownLayer, public FLAlertLayerProtocol, public UploadActionDelegate, public UploadPopupDelegate {
public:
    static constexpr auto CLASS_NAME = "SupportLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SupportLayer, GJDropDownLayer)
    
private:
    [[deprecated("SupportLayer::create not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x314fd0
     * @note[short] MacOS (Intel): 0x3851e0
     * @note[short] Android
     */
    static SupportLayer* create();
public:
    
private:
    [[deprecated("SupportLayer::customSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x31546c
     * @note[short] MacOS (Intel): 0x385810
     * @note[short] iOS: 0x194c28
     * @note[short] Android
     */
    virtual void customSetup();
public:

    /**
     * @note[short] MacOS (ARM): 0x317218
     * @note[short] MacOS (Intel): 0x3876b0
     * @note[short] Windows: 0x4b0fb0
     * @note[short] iOS: 0x1964b8
     * @note[short] Android
     */
    virtual void uploadActionFinished(int p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0x31736c
     * @note[short] MacOS (Intel): 0x387800
     * @note[short] Windows: 0x4b10f0
     * @note[short] iOS: 0x1965a0
     * @note[short] Android
     */
    virtual void uploadActionFailed(int p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0x3171c8
     * @note[short] MacOS (Intel): 0x387660
     * @note[short] Windows: 0x4b0f70
     * @note[short] iOS: 0x196468
     * @note[short] Android
     */
    virtual void onClosePopup(UploadActionPopup* p0);

    /**
     * @note[short] MacOS (ARM): 0x3176c4
     * @note[short] MacOS (Intel): 0x387b20
     * @note[short] Windows: 0x4b1d70
     * @note[short] iOS: 0x1967b4
     * @note[short] Android
     */
    virtual void FLAlert_Clicked(FLAlertLayer* p0, bool p1);
    
private:
    [[deprecated("SupportLayer::createToggleButton not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createToggleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCMenu* p3, cocos2d::CCPoint p4, cocos2d::CCArray* p5);
public:
    
private:
    [[deprecated("SupportLayer::exitLayer not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn exitLayer();
public:
    
private:
    [[deprecated("SupportLayer::onCocos2d not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x387630
     * @note[short] Android
     */
    void onCocos2d(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SupportLayer::onEmail not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x316600
     * @note[short] MacOS (Intel): 0x386af0
     * @note[short] Android
     */
    void onEmail(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SupportLayer::onGetReward not implemented")]]
    /**
     * @note[short] Android
     */
    void onGetReward(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SupportLayer::onLinks not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x315d64
     * @note[short] MacOS (Intel): 0x386110
     * @note[short] Android
     */
    void onLinks(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x316f08
     * @note[short] MacOS (Intel): 0x3873b0
     * @note[short] Windows: 0x4b1180
     * @note[short] Android
     */
    void onLowDetail(cocos2d::CCObject* sender);
    
private:
    [[deprecated("SupportLayer::onPrivacy not implemented")]]
    /**
     * @note[short] Android
     */
    void onPrivacy(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] Windows: 0x4b0d30
     * @note[short] Android
     */
    void onRequestAccess(cocos2d::CCObject* sender);
    
private:
    [[deprecated("SupportLayer::onRobTop not implemented")]]
    /**
     * @note[short] Android
     */
    void onRobTop(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SupportLayer::onSFX not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x316714
     * @note[short] MacOS (Intel): 0x386c10
     * @note[short] Android
     */
    void onSFX(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SupportLayer::onTOS not implemented")]]
    /**
     * @note[short] Android
     */
    void onTOS(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SupportLayer::sendSupportMail not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x317494
     * @note[short] MacOS (Intel): 0x387900
     * @note[short] Android
     */
    TodoReturn sendSupportMail();
public:
};
