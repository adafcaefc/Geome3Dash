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
#include "UploadActionDelegate.hpp"
#include "UploadPopupDelegate.hpp"
#include "FLAlertLayerProtocol.hpp"
#include "DownloadMessageDelegate.hpp"

class GJMessagePopup : public FLAlertLayer, public UploadActionDelegate, public UploadPopupDelegate, public FLAlertLayerProtocol, public DownloadMessageDelegate {
public:
    static constexpr auto CLASS_NAME = "GJMessagePopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(GJMessagePopup, FLAlertLayer)
    
private:
    [[deprecated("GJMessagePopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static GJMessagePopup* create(GJUserMessage* p0);
public:
    
private:
    [[deprecated("GJMessagePopup::keyBackClicked not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x23ce50
     * @note[short] MacOS (Intel): 0x294c90
     * @note[short] iOS: 0x2db374
     * @note[short] Android
     */
    virtual void keyBackClicked();
public:

    /**
     * @note[short] MacOS (ARM): 0x23cecc
     * @note[short] MacOS (Intel): 0x294d00
     * @note[short] Windows: 0x2914b0
     * @note[short] iOS: 0x2db3f0
     * @note[short] Android
     */
    virtual void downloadMessageFinished(GJUserMessage* p0);

    /**
     * @note[short] MacOS (ARM): 0x23cfa4
     * @note[short] MacOS (Intel): 0x294dc0
     * @note[short] Windows: 0x291500
     * @note[short] iOS: 0x2db464
     * @note[short] Android
     */
    virtual void downloadMessageFailed(int p0);

    /**
     * @note[short] MacOS (ARM): 0x23d05c
     * @note[short] MacOS (Intel): 0x294e60
     * @note[short] Windows: 0x291540
     * @note[short] iOS: 0x2db51c
     * @note[short] Android
     */
    virtual void uploadActionFinished(int p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0x23d250
     * @note[short] MacOS (Intel): 0x295030
     * @note[short] Windows: 0x2916d0
     * @note[short] iOS: 0x2db640
     * @note[short] Android
     */
    virtual void uploadActionFailed(int p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0x23d3c0
     * @note[short] MacOS (Intel): 0x295180
     * @note[short] Windows: 0x2917a0
     * @note[short] iOS: 0x2db6dc
     * @note[short] Android
     */
    virtual void onClosePopup(UploadActionPopup* p0);

    /**
     * @note[short] MacOS (ARM): 0x23d4e4
     * @note[short] MacOS (Intel): 0x295280
     * @note[short] Windows: 0x291820
     * @note[short] iOS: 0x2db774
     * @note[short] Android
     */
    virtual void FLAlert_Clicked(FLAlertLayer* p0, bool p1);
    
private:
    [[deprecated("GJMessagePopup::blockUser not implemented")]]
    /**
     * @note[short] Android
     */
    void blockUser();
public:
    
private:
    [[deprecated("GJMessagePopup::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(GJUserMessage* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x23c0a8
     * @note[short] MacOS (Intel): 0x293e60
     * @note[short] Windows: 0x290760
     * @note[short] Android
     */
    void loadFromGJMessage(GJUserMessage* p0);
    
private:
    [[deprecated("GJMessagePopup::onBlock not implemented")]]
    /**
     * @note[short] Android
     */
    void onBlock(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJMessagePopup::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJMessagePopup::onRemove not implemented")]]
    /**
     * @note[short] Android
     */
    void onRemove(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJMessagePopup::onReply not implemented")]]
    /**
     * @note[short] Android
     */
    void onReply(cocos2d::CCObject* sender);
public:
};
