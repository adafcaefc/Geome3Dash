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

class ColorSelectLiveOverlay : public FLAlertLayer {
public:
    static constexpr auto CLASS_NAME = "ColorSelectLiveOverlay";
    GEODE_CUSTOM_CONSTRUCTOR_GD(ColorSelectLiveOverlay, FLAlertLayer)

    /**
     * @note[short] MacOS (Intel): 0x551c50
     * @note[short] Windows: 0x8bc50
     * @note[short] Android
     */
    static ColorSelectLiveOverlay* create(ColorAction* p0, ColorAction* p1, EffectGameObject* p2);

    /**
     * @note[short] MacOS (ARM): 0x4aa894
     * @note[short] MacOS (Intel): 0x553950
     * @note[short] Windows: 0x8d1b0
     * @note[short] iOS: 0xf9668
     * @note[short] Android
     */
    virtual void keyBackClicked();
    
private:
    [[deprecated("ColorSelectLiveOverlay::show not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4aa94c
     * @note[short] MacOS (Intel): 0x553a00
     * @note[short] iOS: 0xf967c
     * @note[short] Android
     */
    virtual void show();
public:
    
private:
    [[deprecated("ColorSelectLiveOverlay::closeColorSelect not implemented")]]
    /**
     * @note[short] Android
     */
    void closeColorSelect(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("ColorSelectLiveOverlay::colorValueChanged not implemented")]]
    /**
     * @note[short] Android
     */
    void colorValueChanged(cocos2d::ccColor3B p0);
public:
    
private:
    [[deprecated("ColorSelectLiveOverlay::createToggleButton not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createToggleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCMenu* p3, cocos2d::CCPoint p4);
public:
    
private:
    [[deprecated("ColorSelectLiveOverlay::createWithActions not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createWithActions(ColorAction* p0, ColorAction* p1);
public:
    
private:
    [[deprecated("ColorSelectLiveOverlay::createWithObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createWithObject(EffectGameObject* p0);
public:
    
private:
    [[deprecated("ColorSelectLiveOverlay::determineStartValues not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn determineStartValues();
public:
    
private:
    [[deprecated("ColorSelectLiveOverlay::getColorValue not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getColorValue();
public:

    /**
     * @note[short] MacOS (ARM): 0x4a9080
     * @note[short] MacOS (Intel): 0x551e20
     * @note[short] Windows: 0x8bda0
     * @note[short] Android
     */
    bool init(ColorAction* p0, ColorAction* p1, EffectGameObject* p2);
    
private:
    [[deprecated("ColorSelectLiveOverlay::onSelectTab not implemented")]]
    /**
     * @note[short] Android
     */
    void onSelectTab(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("ColorSelectLiveOverlay::selectColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn selectColor(cocos2d::ccColor3B p0);
public:
    
private:
    [[deprecated("ColorSelectLiveOverlay::sliderChanged not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn sliderChanged(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("ColorSelectLiveOverlay::textChanged not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn textChanged(CCTextInputNode* p0);
public:
    
private:
    [[deprecated("ColorSelectLiveOverlay::textInputClosed not implemented")]]
    /**
     * @note[short] Android
     */
    void textInputClosed(CCTextInputNode* p0);
public:
    
private:
    [[deprecated("ColorSelectLiveOverlay::toggleControls not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleControls(bool p0);
public:
    
private:
    [[deprecated("ColorSelectLiveOverlay::updateColorLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateColorLabel();
public:
    
private:
    [[deprecated("ColorSelectLiveOverlay::updateColorValue not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateColorValue();
public:
    
private:
    [[deprecated("ColorSelectLiveOverlay::updateOpacity not implemented")]]
    /**
     * @note[short] Android
     */
    void updateOpacity();
public:
    EffectGameObject* m_effectGameObject;
    cocos2d::CCArray* m_barSprites;
    cocos2d::CCArray* m_12buttons;
    ColorAction* m_baseColorAction;
    ColorAction* m_detailColorAction;
};
