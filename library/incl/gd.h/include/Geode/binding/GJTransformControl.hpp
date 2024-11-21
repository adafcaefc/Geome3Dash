#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJTransformControl : public cocos2d::CCLayer {
public:
    static constexpr auto CLASS_NAME = "GJTransformControl";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJTransformControl, cocos2d::CCLayer)
    
private:
    [[deprecated("GJTransformControl::create not implemented")]]
    /**
     * @note[short] Android
     */
    static GJTransformControl* create();
public:

    /**
     * @note[short] MacOS (ARM): 0x4a5fc
     * @note[short] MacOS (Intel): 0x534a0
     * @note[short] Windows: 0x1290a0
     * @note[short] iOS: 0x3f3868
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (ARM): 0x4aa70
     * @note[short] MacOS (Intel): 0x53940
     * @note[short] Windows: 0x12a730
     * @note[short] iOS: 0x3f3c00
     * @note[short] Android
     */
    virtual bool ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);

    /**
     * @note[short] MacOS (ARM): 0x4ae6c
     * @note[short] MacOS (Intel): 0x53dc0
     * @note[short] Windows: 0x12a900
     * @note[short] iOS: 0x3f3da8
     * @note[short] Android
     */
    virtual void ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);

    /**
     * @note[short] MacOS (ARM): 0x4b374
     * @note[short] MacOS (Intel): 0x54360
     * @note[short] Windows: 0x12ae60
     * @note[short] iOS: 0x3f42a4
     * @note[short] Android
     */
    virtual void ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);

    /**
     * @note[short] MacOS (ARM): 0x4b54c
     * @note[short] MacOS (Intel): 0x54570
     * @note[short] Windows: 0x71210
     * @note[short] iOS: 0x3f447c
     * @note[short] Android
     */
    virtual void ccTouchCancelled(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);
    
private:
    [[deprecated("GJTransformControl::applyRotation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn applyRotation(float p0);
public:
    
private:
    [[deprecated("GJTransformControl::calculateRotationOffset not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn calculateRotationOffset();
public:
    
private:
    [[deprecated("GJTransformControl::finishTouch not implemented")]]
    /**
     * @note[short] Android
     */
    void finishTouch();
public:
    
private:
    [[deprecated("GJTransformControl::loadFromState not implemented")]]
    /**
     * @note[short] Android
     */
    void loadFromState(GJTransformState& p0);
public:
    
private:
    [[deprecated("GJTransformControl::loadValues not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn loadValues(GameObject* p0, cocos2d::CCArray* p1, gd::unordered_map<int, GameObjectEditorState>& p2);
public:
    
private:
    [[deprecated("GJTransformControl::logCurrentZeroPos not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn logCurrentZeroPos();
public:
    
private:
    [[deprecated("GJTransformControl::onToggleLockScale not implemented")]]
    /**
     * @note[short] Android
     */
    void onToggleLockScale(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] Windows: 0x1295f0
     * @note[short] Android
     */
    void refreshControl();
    
private:
    [[deprecated("GJTransformControl::saveToState not implemented")]]
    /**
     * @note[short] Android
     */
    void saveToState(GJTransformState& p0);
public:

    /**
     * @note[short] Windows: 0x129810
     * @note[short] Android
     */
    void scaleButtons(float p0);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    cocos2d::CCSprite* spriteByTag(int tag);
    
private:
    [[deprecated("GJTransformControl::updateAnchorSprite not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateAnchorSprite(cocos2d::CCPoint p0);
public:

    /**
     * @note[short] Windows: 0x1298d0
     * @note[short] Android
     */
    void updateButtons(bool p0, bool p1);
    
private:
    [[deprecated("GJTransformControl::updateMinMaxPositions not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateMinMaxPositions();
public:
    cocos2d::CCNode* m_mainNodeParent;
    cocos2d::CCNode* m_mainNode;
    cocos2d::CCArray* m_unk1;
    int m_touchID;
    short m_transformButtonType;
    GJTransformControlDelegate* m_delegate;
    cocos2d::CCPoint m_cursorDifference;
    cocos2d::CCPoint m_touchStart;
    cocos2d::CCPoint m_unk3;
    cocos2d::CCPoint m_unk4;
    cocos2d::CCPoint m_unk5;
    cocos2d::CCPoint m_unk6;
    cocos2d::CCPoint m_unk7;
    cocos2d::CCArray* m_warpSprites;
    cocos2d::CCPoint m_rotatePosition;
    CCMenuItemSpriteExtra* m_warpLockButton;
    float m_scaleX;
    float m_scaleY;
    bool m_warpLocked;
    float m_unk10;
    float m_unk11;
    float m_unk12;
    float m_buttonScale;
};
