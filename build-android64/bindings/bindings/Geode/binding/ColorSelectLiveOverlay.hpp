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

    /**
     * @note[short] MacOS (ARM): 0x4aa94c
     * @note[short] MacOS (Intel): 0x553a00
     * @note[short] iOS: 0xf967c
     * @note[short] Android
     */
    virtual void show();

    /**
     * @note[short] Android
     */
    void closeColorSelect(cocos2d::CCObject* p0);

    /**
     * @note[short] Android
     */
    void colorValueChanged(cocos2d::ccColor3B p0);

    /**
     * @note[short] Android
     */
    TodoReturn createToggleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCMenu* p3, cocos2d::CCPoint p4);

    /**
     * @note[short] Android
     */
    TodoReturn createWithActions(ColorAction* p0, ColorAction* p1);

    /**
     * @note[short] Android
     */
    TodoReturn createWithObject(EffectGameObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn determineStartValues();

    /**
     * @note[short] Android
     */
    TodoReturn getColorValue();

    /**
     * @note[short] MacOS (ARM): 0x4a9080
     * @note[short] MacOS (Intel): 0x551e20
     * @note[short] Windows: 0x8bda0
     * @note[short] Android
     */
    bool init(ColorAction* p0, ColorAction* p1, EffectGameObject* p2);

    /**
     * @note[short] Android
     */
    void onSelectTab(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    TodoReturn selectColor(cocos2d::ccColor3B p0);

    /**
     * @note[short] Android
     */
    TodoReturn sliderChanged(cocos2d::CCObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn textChanged(CCTextInputNode* p0);

    /**
     * @note[short] Android
     */
    void textInputClosed(CCTextInputNode* p0);

    /**
     * @note[short] Android
     */
    TodoReturn toggleControls(bool p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateColorLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateColorValue();

    /**
     * @note[short] Android
     */
    void updateOpacity();
    EffectGameObject* m_effectGameObject;
    cocos2d::CCArray* m_barSprites;
    cocos2d::CCArray* m_12buttons;
    ColorAction* m_baseColorAction;
    ColorAction* m_detailColorAction;
};
