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

class LikeItemLayer : public FLAlertLayer {
public:
    static constexpr auto CLASS_NAME = "LikeItemLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(LikeItemLayer, FLAlertLayer)

    /**
     * @note[short] MacOS (Intel): 0x5e1410
     * @note[short] Windows: 0x318ea0
     * @note[short] Android
     */
    static LikeItemLayer* create(LikeItemType p0, int p1, int p2);
    
private:
    [[deprecated("LikeItemLayer::keyBackClicked not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x514184
     * @note[short] MacOS (Intel): 0x5e1b00
     * @note[short] iOS: 0x24c0fc
     * @note[short] Android
     */
    virtual void keyBackClicked();
public:

    /**
     * @note[short] MacOS (ARM): 0x513c28
     * @note[short] MacOS (Intel): 0x5e1580
     * @note[short] Windows: 0x318fa0
     * @note[short] Android
     */
    bool init(LikeItemType p0, int p1, int p2);
    
private:
    [[deprecated("LikeItemLayer::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x514090
     * @note[short] MacOS (Intel): 0x5e1a00
     * @note[short] Windows: 0x319380
     * @note[short] Android
     */
    void onDislike(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x319370
     * @note[short] Android
     */
    void onLike(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x319390
     * @note[short] Android
     */
    void triggerLike(bool isLiked);
    LikeItemType m_itemType;
    int m_itemID;
    int m_commentSourceID;
    LikeItemDelegate* m_likeDelegate;
};
