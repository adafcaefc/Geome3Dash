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

class CollisionBlockPopup : public FLAlertLayer, public TextInputDelegate {
public:
    static constexpr auto CLASS_NAME = "CollisionBlockPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(CollisionBlockPopup, FLAlertLayer)
    
private:
    [[deprecated("CollisionBlockPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static CollisionBlockPopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x220028
     * @note[short] MacOS (Intel): 0x2753b0
     * @note[short] Windows: 0x8bb20
     * @note[short] iOS: 0x89a70
     * @note[short] Android
     */
    virtual void keyBackClicked();
    
private:
    [[deprecated("CollisionBlockPopup::show not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x21ffdc
     * @note[short] MacOS (Intel): 0x275350
     * @note[short] iOS: 0x89a24
     * @note[short] Android
     */
    virtual void show();
public:
    
private:
    [[deprecated("CollisionBlockPopup::textInputClosed not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x21fe7c
     * @note[short] MacOS (Intel): 0x275190
     * @note[short] iOS: 0x89988
     * @note[short] Android
     */
    virtual void textInputClosed(CCTextInputNode* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x21fe98
     * @note[short] MacOS (Intel): 0x2751d0
     * @note[short] Windows: 0x8b7a0
     * @note[short] iOS: 0x899a4
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);
    
private:
    [[deprecated("CollisionBlockPopup::textInputShouldOffset not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x220034
     * @note[short] MacOS (Intel): 0x2753e0
     * @note[short] iOS: 0x89a7c
     * @note[short] Android
     */
    virtual void textInputShouldOffset(CCTextInputNode* p0, float p1);
public:
    
private:
    [[deprecated("CollisionBlockPopup::textInputReturn not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x220104
     * @note[short] MacOS (Intel): 0x2754a0
     * @note[short] iOS: 0x89ae8
     * @note[short] Android
     */
    virtual void textInputReturn(CCTextInputNode* p0);
public:
    
private:
    [[deprecated("CollisionBlockPopup::createToggleButton not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createToggleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCMenu* p3, cocos2d::CCPoint p4);
public:
    
private:
    [[deprecated("CollisionBlockPopup::determineStartValues not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn determineStartValues();
public:
    
private:
    [[deprecated("CollisionBlockPopup::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x21ec48
     * @note[short] MacOS (Intel): 0x273e80
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("CollisionBlockPopup::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CollisionBlockPopup::onDynamicBlock not implemented")]]
    /**
     * @note[short] Android
     */
    void onDynamicBlock(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CollisionBlockPopup::onItemIDArrow not implemented")]]
    /**
     * @note[short] Android
     */
    void onItemIDArrow(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CollisionBlockPopup::onNextItemID not implemented")]]
    /**
     * @note[short] Android
     */
    void onNextItemID(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CollisionBlockPopup::updateEditorLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateEditorLabel();
public:
    
private:
    [[deprecated("CollisionBlockPopup::updateItemID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateItemID();
public:
    
private:
    [[deprecated("CollisionBlockPopup::updateTextInputLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTextInputLabel();
public:
};
