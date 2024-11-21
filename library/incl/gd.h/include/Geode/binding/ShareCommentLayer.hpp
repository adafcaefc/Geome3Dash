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
#include "UploadActionDelegate.hpp"
#include "UploadPopupDelegate.hpp"

class ShareCommentLayer : public FLAlertLayer, public TextInputDelegate, public UploadActionDelegate, public UploadPopupDelegate {
public:
    static constexpr auto CLASS_NAME = "ShareCommentLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(ShareCommentLayer, FLAlertLayer)

    /**
     * @note[short] Windows: 0x474930
     * @note[short] Android
     */
    static ShareCommentLayer* create(gd::string title, int charLimit, CommentType type, int ID, gd::string desc);
    
private:
    [[deprecated("ShareCommentLayer::registerWithTouchDispatcher not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4fd970
     * @note[short] MacOS (Intel): 0x5c9120
     * @note[short] iOS: 0x1d673c
     * @note[short] Android
     */
    virtual void registerWithTouchDispatcher();
public:

    /**
     * @note[short] MacOS (ARM): 0x4fd8c8
     * @note[short] MacOS (Intel): 0x5c9070
     * @note[short] Windows: 0x476170
     * @note[short] iOS: 0x1d6694
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x4fdb34
     * @note[short] MacOS (Intel): 0x5c92d0
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x1d6848
     * @note[short] Android: Out of line
     */
    virtual void textInputOpened(CCTextInputNode* textInput);

    /**
     * @note[short] MacOS (ARM): 0x4fd9a8
     * @note[short] MacOS (Intel): 0x5c9160
     * @note[short] Windows: 0x4761c0
     * @note[short] iOS: 0x1d6774
     * @note[short] Android
     */
    virtual void textInputClosed(CCTextInputNode* textInput);

    /**
     * @note[short] MacOS (ARM): 0x4fdb3c
     * @note[short] MacOS (Intel): 0x5c92f0
     * @note[short] Windows: 0x476300
     * @note[short] iOS: 0x1d6850
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* textInput);

    /**
     * @note[short] MacOS (ARM): 0x4fddcc
     * @note[short] MacOS (Intel): 0x5c9560
     * @note[short] Windows: 0x476550
     * @note[short] iOS: 0x1d6a10
     * @note[short] Android
     */
    virtual void uploadActionFinished(int ID, int unk);

    /**
     * @note[short] MacOS (ARM): 0x4fdf04
     * @note[short] MacOS (Intel): 0x5c9660
     * @note[short] Windows: 0x4765e0
     * @note[short] iOS: 0x1d6aa0
     * @note[short] Android
     */
    virtual void uploadActionFailed(int ID, int unk);

    /**
     * @note[short] MacOS (ARM): 0x4fe064
     * @note[short] MacOS (Intel): 0x5c9780
     * @note[short] Windows: 0x476690
     * @note[short] iOS: 0x1d6b24
     * @note[short] Android
     */
    virtual void onClosePopup(UploadActionPopup* p0);

    /**
     * @note[short] MacOS (ARM): 0x4fc27c
     * @note[short] MacOS (Intel): 0x5c7820
     * @note[short] Windows: 0x474b40
     * @note[short] Android
     */
    bool init(gd::string title, int charLimit, CommentType type, int ID, gd::string desc);

    /**
     * @note[short] MacOS (ARM): 0x4fd404
     * @note[short] MacOS (Intel): 0x5c8b70
     * @note[short] Windows: 0x475c20
     * @note[short] Android
     */
    void onClear(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x476130
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x4fd26c
     * @note[short] MacOS (Intel): 0x5c89e0
     * @note[short] Windows: 0x475c90
     * @note[short] Android
     */
    void onPercent(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (Intel): 0x5c8c60
     * @note[short] Windows: 0x475d90
     * @note[short] Android
     */
    void onShare(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x4fdcb8
     * @note[short] MacOS (Intel): 0x5c9450
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void updateCharCountLabel();
    
private:
    [[deprecated("ShareCommentLayer::updateDescText not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4fd8a0
     * @note[short] MacOS (Intel): 0x5c9040
     * @note[short] iOS: Out of line
     * @note[short] Android
     */
    void updateDescText(gd::string desc);
public:

    /**
     * @note[short] MacOS (ARM): 0x4fd33c
     * @note[short] MacOS (Intel): 0x5c8ab0
     * @note[short] Windows: 0x475cb0
     * @note[short] Android
     */
    void updatePercentLabel();
    int m_charLimit;
    int m_itemID;
    CommentType m_commentType;
    CCTextInputNode* m_commentInput;
    gd::string m_descText;
    gd::string m_placeholderText;
    cocos2d::CCLabelBMFont* m_charCountLabel;
    cocos2d::CCLabelBMFont* m_percentLabel;
    UploadActionPopup* m_uploadPopup;
    bool m_uploadSuccess;
    bool m_percentEnabled;
    int m_percent;
    ShareCommentDelegate* m_delegate;
};
