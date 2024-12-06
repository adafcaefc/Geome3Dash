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

class GJMessageCell : public TableViewCell, public FLAlertLayerProtocol, public UploadPopupDelegate, public UploadActionDelegate {
public:
    static constexpr auto CLASS_NAME = "GJMessageCell";
    GEODE_CUSTOM_CONSTRUCTOR_GD(GJMessageCell, TableViewCell)

    /**
     * @note[short] MacOS (ARM): 0x1f4e7c
     * @note[short] MacOS (Intel): 0x2464b0
     * @note[short] Windows: 0xbb620
     * @note[short] iOS: 0x11530c
     * @note[short] Android
     */
    virtual bool init();
    
private:
    [[deprecated("GJMessageCell::draw not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f5164
     * @note[short] MacOS (Intel): 0x2467c0
     * @note[short] iOS: 0x115538
     * @note[short] Android
     */
    virtual void draw();
public:

    /**
     * @note[short] MacOS (ARM): 0x1f5210
     * @note[short] MacOS (Intel): 0x246890
     * @note[short] Windows: 0xbd440
     * @note[short] iOS: 0x1155e4
     * @note[short] Android
     */
    virtual void FLAlert_Clicked(FLAlertLayer* p0, bool p1);

    /**
     * @note[short] MacOS (ARM): 0x1f5374
     * @note[short] MacOS (Intel): 0x246a20
     * @note[short] Windows: 0xbd5e0
     * @note[short] iOS: 0x1156cc
     * @note[short] Android
     */
    virtual void uploadActionFinished(int p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0x1f5568
     * @note[short] MacOS (Intel): 0x246c10
     * @note[short] Windows: 0xbd760
     * @note[short] iOS: 0x1157d0
     * @note[short] Android
     */
    virtual void uploadActionFailed(int p0, int p1);
    
private:
    [[deprecated("GJMessageCell::onClosePopup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f56d0
     * @note[short] MacOS (Intel): 0x246d80
     * @note[short] iOS: 0x115868
     * @note[short] Android
     */
    virtual void onClosePopup(UploadActionPopup* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x1ea9f8
     * @note[short] MacOS (Intel): 0x23aa30
     * @note[short] Windows: 0xbc7e0
     * @note[short] Android
     */
    void loadFromMessage(GJUserMessage* p0);
    
private:
    [[deprecated("GJMessageCell::markAsRead not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn markAsRead();
public:
    
private:
    [[deprecated("GJMessageCell::onDeleteMessage not implemented")]]
    /**
     * @note[short] Android
     */
    void onDeleteMessage(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJMessageCell::onToggle not implemented")]]
    /**
     * @note[short] Android
     */
    void onToggle(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJMessageCell::onViewMessage not implemented")]]
    /**
     * @note[short] Android
     */
    void onViewMessage(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJMessageCell::onViewProfile not implemented")]]
    /**
     * @note[short] Android
     */
    void onViewProfile(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJMessageCell::updateBGColor not implemented")]]
    /**
     * @note[short] Android
     */
    void updateBGColor(int p0);
public:
    
private:
    [[deprecated("GJMessageCell::updateToggle not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateToggle();
public:
    GJUserMessage* m_message;
    void* m_unk;
    CCMenuItemToggler* m_toggler;
};
