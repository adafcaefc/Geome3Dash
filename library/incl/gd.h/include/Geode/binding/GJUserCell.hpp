#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "TableViewCell.hpp"
#include "FLAlertLayerProtocol.hpp"
#include "UploadPopupDelegate.hpp"
#include "UploadActionDelegate.hpp"

class GJUserCell : public TableViewCell, public FLAlertLayerProtocol, public UploadPopupDelegate, public UploadActionDelegate {
public:
    static constexpr auto CLASS_NAME = "GJUserCell";
    GEODE_CUSTOM_CONSTRUCTOR_GD(GJUserCell, TableViewCell)

    /**
     * @note[short] MacOS (ARM): 0x1f31f8
     * @note[short] MacOS (Intel): 0x2443a0
     * @note[short] Windows: 0xb9f50
     * @note[short] iOS: 0x114208
     * @note[short] Android
     */
    virtual bool init();
    
private:
    [[deprecated("GJUserCell::draw not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f399c
     * @note[short] MacOS (Intel): 0x244b10
     * @note[short] iOS: 0x11469c
     * @note[short] Android
     */
    virtual void draw();
public:

    /**
     * @note[short] MacOS (ARM): 0x1f3a48
     * @note[short] MacOS (Intel): 0x244be0
     * @note[short] Windows: 0xbae70
     * @note[short] iOS: 0x114748
     * @note[short] Android
     */
    virtual void FLAlert_Clicked(FLAlertLayer* p0, bool p1);

    /**
     * @note[short] MacOS (ARM): 0x1f3c94
     * @note[short] MacOS (Intel): 0x244e90
     * @note[short] Windows: 0xbb230
     * @note[short] iOS: 0x114950
     * @note[short] Android
     */
    virtual void uploadActionFinished(int p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0x1f3ea8
     * @note[short] MacOS (Intel): 0x2450a0
     * @note[short] Windows: 0xbb3e0
     * @note[short] iOS: 0x114a74
     * @note[short] Android
     */
    virtual void uploadActionFailed(int p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0x1f4010
     * @note[short] MacOS (Intel): 0x245210
     * @note[short] Windows: 0xbb4b0
     * @note[short] iOS: 0x114b0c
     * @note[short] Android
     */
    virtual void onClosePopup(UploadActionPopup* p0);

    /**
     * @note[short] MacOS (Intel): 0x239a60
     * @note[short] Windows: 0xb9f70
     * @note[short] Android
     */
    void loadFromScore(GJUserScore* p0);
    
private:
    [[deprecated("GJUserCell::onCancelFriendRequest not implemented")]]
    /**
     * @note[short] Android
     */
    void onCancelFriendRequest(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJUserCell::onRemoveFriend not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f3644
     * @note[short] MacOS (Intel): 0x2447c0
     * @note[short] Android
     */
    void onRemoveFriend(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJUserCell::onSendMessage not implemented")]]
    /**
     * @note[short] Android
     */
    void onSendMessage(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJUserCell::onUnblockUser not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f3244
     * @note[short] MacOS (Intel): 0x2443f0
     * @note[short] Android
     */
    void onUnblockUser(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJUserCell::onViewFriendRequest not implemented")]]
    /**
     * @note[short] Android
     */
    void onViewFriendRequest(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJUserCell::onViewProfile not implemented")]]
    /**
     * @note[short] Android
     */
    void onViewProfile(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJUserCell::updateBGColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateBGColor(int p0);
public:
};
