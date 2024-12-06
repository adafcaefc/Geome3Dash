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
#include "LikeItemDelegate.hpp"
#include "FLAlertLayerProtocol.hpp"

class CommentCell : public TableViewCell, public LikeItemDelegate, public FLAlertLayerProtocol {
public:
    static constexpr auto CLASS_NAME = "CommentCell";
    GEODE_CUSTOM_CONSTRUCTOR_GD(CommentCell, TableViewCell)

    /**
     * @note[short] MacOS (ARM): 0x1f202c
     * @note[short] MacOS (Intel): 0x242d60
     * @note[short] Windows: 0xb5460
     * @note[short] iOS: 0x11371c
     * @note[short] Android
     */
    virtual bool init();
    
private:
    [[deprecated("CommentCell::draw not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f22f4
     * @note[short] MacOS (Intel): 0x243070
     * @note[short] iOS: 0x1139b8
     * @note[short] Android
     */
    virtual void draw();
public:

    /**
     * @note[short] MacOS (ARM): 0x1f23a0
     * @note[short] MacOS (Intel): 0x243140
     * @note[short] Windows: 0xb7750
     * @note[short] iOS: 0x113a64
     * @note[short] Android
     */
    virtual void likedItem(LikeItemType p0, int p1, bool p2);

    /**
     * @note[short] MacOS (ARM): 0x1f271c
     * @note[short] MacOS (Intel): 0x2434e0
     * @note[short] Windows: 0xb79c0
     * @note[short] iOS: 0x113bdc
     * @note[short] Android
     */
    virtual void FLAlert_Clicked(FLAlertLayer* p0, bool p1);
    
private:
    [[deprecated("CommentCell::incrementDislikes not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn incrementDislikes();
public:
    
private:
    [[deprecated("CommentCell::incrementLikes not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn incrementLikes();
public:

    /**
     * @note[short] MacOS (ARM): 0x1e5f14
     * @note[short] MacOS (Intel): 0x235d50
     * @note[short] Windows: 0xb5480
     * @note[short] Android
     */
    void loadFromComment(GJComment* p0);

    /**
     * @note[short] MacOS (ARM): 0x1f220c
     * @note[short] MacOS (Intel): 0x242f80
     * @note[short] Windows: 0xb7850
     * @note[short] Android
     */
    void onConfirmDelete(cocos2d::CCObject* sender);
    
private:
    [[deprecated("CommentCell::onDelete not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f26a0
     * @note[short] MacOS (Intel): 0x243450
     * @note[short] Android
     */
    void onDelete();
public:

    /**
     * @note[short] MacOS (ARM): 0x1f2078
     * @note[short] MacOS (Intel): 0x242dc0
     * @note[short] Windows: 0xb7b20
     * @note[short] Android
     */
    void onGoToLevel(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x1f212c
     * @note[short] MacOS (Intel): 0x242e90
     * @note[short] Windows: 0xb75f0
     * @note[short] Android
     */
    void onLike(cocos2d::CCObject* sender);
    
private:
    [[deprecated("CommentCell::onUndelete not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn onUndelete();
public:

    /**
     * @note[short] MacOS (Intel): 0x242e70
     * @note[short] Windows: 0xb7b00
     * @note[short] Android
     */
    void onUnhide(cocos2d::CCObject* sender);
    
private:
    [[deprecated("CommentCell::onViewProfile not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1f2044
     * @note[short] MacOS (Intel): 0x242d90
     * @note[short] Android
     */
    void onViewProfile(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CommentCell::updateBGColor not implemented")]]
    /**
     * @note[short] Android
     */
    void updateBGColor(int p0);
public:
    
private:
    [[deprecated("CommentCell::updateLabelValues not implemented")]]
    /**
     * @note[short] Android
     */
    void updateLabelValues();
public:
    cocos2d::CCSprite* m_iconSprite;
    cocos2d::CCLabelBMFont* m_likeLabel;
    GJComment* m_comment;
    bool m_accountComment;
};
