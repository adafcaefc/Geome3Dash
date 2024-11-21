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
#include "UploadMessageDelegate.hpp"
#include "UploadPopupDelegate.hpp"
#include "FLAlertLayerProtocol.hpp"

class GJWriteMessagePopup : public FLAlertLayer, public TextInputDelegate, public UploadMessageDelegate, public UploadPopupDelegate, public FLAlertLayerProtocol {
public:
    static constexpr auto CLASS_NAME = "GJWriteMessagePopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(GJWriteMessagePopup, FLAlertLayer)
    
private:
    [[deprecated("GJWriteMessagePopup::create not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x294a70
     * @note[short] Android
     */
    static GJWriteMessagePopup* create(int p0, int p1);
public:
    
private:
    [[deprecated("GJWriteMessagePopup::registerWithTouchDispatcher not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x23ebbc
     * @note[short] MacOS (Intel): 0x296b90
     * @note[short] iOS: 0x2dccd0
     * @note[short] Android
     */
    virtual void registerWithTouchDispatcher();
public:

    /**
     * @note[short] MacOS (ARM): 0x23eba8
     * @note[short] MacOS (Intel): 0x296b60
     * @note[short] Windows: 0x2930d0
     * @note[short] iOS: 0x2dccbc
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x23ec10
     * @note[short] MacOS (Intel): 0x296c10
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x2dcd24
     * @note[short] Android: Out of line
     */
    virtual void textInputOpened(CCTextInputNode* p0);
    
private:
    [[deprecated("GJWriteMessagePopup::textInputClosed not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x23ebf4
     * @note[short] MacOS (Intel): 0x296bd0
     * @note[short] iOS: 0x2dcd08
     * @note[short] Android
     */
    virtual void textInputClosed(CCTextInputNode* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x23ec18
     * @note[short] MacOS (Intel): 0x296c30
     * @note[short] Windows: 0x2930e0
     * @note[short] iOS: 0x2dcd2c
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x23f2bc
     * @note[short] MacOS (Intel): 0x297300
     * @note[short] Windows: 0x2936c0
     * @note[short] iOS: 0x2dd168
     * @note[short] Android
     */
    virtual void uploadMessageFinished(int p0);

    /**
     * @note[short] MacOS (ARM): 0x23f394
     * @note[short] MacOS (Intel): 0x2973c0
     * @note[short] Windows: 0x293740
     * @note[short] iOS: 0x2dd1f8
     * @note[short] Android
     */
    virtual void uploadMessageFailed(int p0);

    /**
     * @note[short] MacOS (ARM): 0x23f4d4
     * @note[short] MacOS (Intel): 0x2974f0
     * @note[short] Windows: 0x2937f0
     * @note[short] iOS: 0x2dd27c
     * @note[short] Android
     */
    virtual void onClosePopup(UploadActionPopup* p0);

    /**
     * @note[short] MacOS (ARM): 0x23f658
     * @note[short] MacOS (Intel): 0x297640
     * @note[short] Windows: 0x293890
     * @note[short] iOS: 0x2dd2f8
     * @note[short] Android
     */
    virtual void FLAlert_Clicked(FLAlertLayer* p0, bool p1);
    
private:
    [[deprecated("GJWriteMessagePopup::textInputShouldOffset not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x23f778
     * @note[short] MacOS (Intel): 0x297720
     * @note[short] iOS: 0x2dd38c
     * @note[short] Android
     */
    virtual void textInputShouldOffset(CCTextInputNode* p0, float p1);
public:
    
private:
    [[deprecated("GJWriteMessagePopup::textInputReturn not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x23f848
     * @note[short] MacOS (Intel): 0x2977e0
     * @note[short] iOS: 0x2dd3f8
     * @note[short] Android
     */
    virtual void textInputReturn(CCTextInputNode* p0);
public:
    
private:
    [[deprecated("GJWriteMessagePopup::closeMessagePopup not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn closeMessagePopup(bool p0);
public:
    
private:
    [[deprecated("GJWriteMessagePopup::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x23d718
     * @note[short] MacOS (Intel): 0x295560
     * @note[short] Android
     */
    bool init(int p0, int p1);
public:
    
private:
    [[deprecated("GJWriteMessagePopup::onClearBody not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x23e900
     * @note[short] MacOS (Intel): 0x2968a0
     * @note[short] Android
     */
    void onClearBody(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJWriteMessagePopup::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJWriteMessagePopup::onSend not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x23e4e0
     * @note[short] MacOS (Intel): 0x296450
     * @note[short] Android
     */
    void onSend(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJWriteMessagePopup::updateBody not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateBody(gd::string p0);
public:
    
private:
    [[deprecated("GJWriteMessagePopup::updateCharCountLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateCharCountLabel(int p0);
public:
    
private:
    [[deprecated("GJWriteMessagePopup::updateSubject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateSubject(gd::string p0);
public:
    
private:
    [[deprecated("GJWriteMessagePopup::updateText not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateText(gd::string p0, int p1);
public:
};
