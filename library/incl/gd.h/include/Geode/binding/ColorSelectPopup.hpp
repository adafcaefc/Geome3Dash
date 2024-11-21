#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "SetupTriggerPopup.hpp"
#include "GJSpecialColorSelectDelegate.hpp"

class ColorSelectPopup : public SetupTriggerPopup, public cocos2d::extension::ColorPickerDelegate, public GJSpecialColorSelectDelegate {
public:
    static constexpr auto CLASS_NAME = "ColorSelectPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(ColorSelectPopup, SetupTriggerPopup)

    /**
     * @note[short] Windows: 0x926d0
     * @note[short] Android
     */
    static gd::string colorToHex(cocos2d::ccColor3B p0);

    /**
     * @note[short] MacOS (Intel): 0x70e810
     * @note[short] Windows: 0x8da30
     * @note[short] Android
     */
    static ColorSelectPopup* create(EffectGameObject* effect, cocos2d::CCArray* array, ColorAction* action);

    /**
     * @note[short] MacOS (ARM): 0x62d8a8
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static ColorSelectPopup* create(cocos2d::ccColor3B color);

    /**
     * @note[short] MacOS (Intel): 0x70eaf0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static ColorSelectPopup* create(ColorAction* action);

    /**
     * @note[short] MacOS (ARM): 0x62d6a0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static ColorSelectPopup* create(EffectGameObject* effect, cocos2d::CCArray* array);

    /**
     * @note[short] Windows: 0x91a60
     * @note[short] Android
     */
    static cocos2d::ccColor3B hexToColor(gd::string p0);
    
private:
    [[deprecated("ColorSelectPopup::show not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x6332dc
     * @note[short] MacOS (Intel): 0x714aa0
     * @note[short] iOS: 0x418298
     * @note[short] Android
     */
    virtual void show();
public:

    /**
     * @note[short] MacOS (ARM): 0x631010
     * @note[short] MacOS (Intel): 0x712800
     * @note[short] Windows: 0x90390
     * @note[short] iOS: 0x417284
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x6333a8
     * @note[short] MacOS (Intel): 0x714b90
     * @note[short] Windows: 0x92cd0
     * @note[short] iOS: 0x418364
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x6316b0
     * @note[short] MacOS (Intel): 0x712ff0
     * @note[short] Windows: 0x91750
     * @note[short] iOS: 0x417894
     * @note[short] Android
     */
    virtual void colorValueChanged(cocos2d::ccColor3B p0);

    /**
     * @note[short] MacOS (ARM): 0x633898
     * @note[short] MacOS (Intel): 0x715130
     * @note[short] Windows: 0x93690
     * @note[short] iOS: 0x418764
     * @note[short] Android
     */
    virtual void colorSelectClosed(GJSpecialColorSelect* p0, int p1);
    
private:
    [[deprecated("ColorSelectPopup::keyBackClicked not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x6316a4
     * @note[short] MacOS (Intel): 0x712fc0
     * @note[short] iOS: 0x417888
     * @note[short] Android
     */
    virtual void keyBackClicked();
public:

    /**
     * @note[short] MacOS (Intel): 0x711290
     * @note[short] Windows: 0x914a0
     * @note[short] Android
     */
    void closeColorSelect(cocos2d::CCObject* p0);
    
private:
    [[deprecated("ColorSelectPopup::getColorValue not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::ccColor3B const& getColorValue();
public:

    /**
     * @note[short] MacOS (ARM): 0x62d8e4
     * @note[short] MacOS (Intel): 0x70eb40
     * @note[short] Windows: 0x8dc20
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1, ColorAction* p2);

    /**
     * @note[short] Windows: 0x90d60
     * @note[short] Android
     */
    void onCopy(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x90b00
     * @note[short] Android
     */
    void onCopyOpacity(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x630280
     * @note[short] Windows: 0x90e60
     * @note[short] Android
     */
    void onDefault(cocos2d::CCObject* sender);
    
private:
    [[deprecated("ColorSelectPopup::onHSVLegacyMode not implemented")]]
    /**
     * @note[short] Android
     */
    void onHSVLegacyMode(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] Windows: 0x90de0
     * @note[short] Android
     */
    void onPaste(cocos2d::CCObject* sender);
    
private:
    [[deprecated("ColorSelectPopup::onPlayerColor1 not implemented")]]
    /**
     * @note[short] Android
     */
    void onPlayerColor1(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("ColorSelectPopup::onPlayerColor2 not implemented")]]
    /**
     * @note[short] Android
     */
    void onPlayerColor2(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("ColorSelectPopup::onSelectSpecialColor not implemented")]]
    /**
     * @note[short] Android
     */
    void onSelectSpecialColor(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("ColorSelectPopup::onTintGround not implemented")]]
    /**
     * @note[short] Android
     */
    void onTintGround(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] Windows: 0x93500
     * @note[short] Android
     */
    void onToggleHSVMode(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x909b0
     * @note[short] Android
     */
    void onToggleTintMode(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x93420
     * @note[short] Android
     */
    void onUpdateCopyColor(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x92c50
     * @note[short] Android
     */
    void onUpdateCustomColor(cocos2d::CCObject* sender);
    
private:
    [[deprecated("ColorSelectPopup::selectColor not implemented")]]
    /**
     * @note[short] Android
     */
    void selectColor(cocos2d::ccColor3B p0);
public:
    
private:
    [[deprecated("ColorSelectPopup::sliderChanged not implemented")]]
    /**
     * @note[short] Android
     */
    void sliderChanged(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("ColorSelectPopup::updateColorLabels not implemented")]]
    /**
     * @note[short] Android
     */
    void updateColorLabels();
public:
    
private:
    [[deprecated("ColorSelectPopup::updateColorValue not implemented")]]
    /**
     * @note[short] Android
     */
    void updateColorValue();
public:

    /**
     * @note[short] Windows: 0x93830
     * @note[short] Android
     */
    void updateCopyColor();
    
private:
    [[deprecated("ColorSelectPopup::updateCopyColorTextInputLabel not implemented")]]
    /**
     * @note[short] Android
     */
    void updateCopyColorTextInputLabel();
public:

    /**
     * @note[short] Windows: 0x93270
     * @note[short] Android
     */
    void updateCustomColorIdx();
    
private:
    [[deprecated("ColorSelectPopup::updateDuration not implemented")]]
    /**
     * @note[short] Android
     */
    void updateDuration();
public:
    
private:
    [[deprecated("ColorSelectPopup::updateDurLabel not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x630004
     * @note[short] MacOS (Intel): 0x7116c0
     * @note[short] Android
     */
    void updateDurLabel();
public:

    /**
     * @note[short] Windows: 0x93540
     * @note[short] Android
     */
    void updateHSVMode();
    
private:
    [[deprecated("ColorSelectPopup::updateHSVValue not implemented")]]
    /**
     * @note[short] Android
     */
    void updateHSVValue();
public:

    /**
     * @note[short] Windows: 0x912b0
     * @note[short] Android
     */
    void updateOpacity();

    /**
     * @note[short] Windows: 0x91430
     * @note[short] Android
     */
    void updateOpacityLabel();
    
private:
    [[deprecated("ColorSelectPopup::updateTextInputLabel not implemented")]]
    /**
     * @note[short] Android
     */
    void updateTextInputLabel();
public:
    cocos2d::extension::CCControlColourPicker* m_colorPicker;
    bool m_unk3c0;
    cocos2d::CCLabelBMFont* m_opacityLabel;
    Slider* m_fadeTimeSlider;
    Slider* m_opacitySlider;
    CCMenuItemToggler* m_playerColor1Toggle;
    CCMenuItemToggler* m_playerColor2Toggle;
    cocos2d::ccColor3B m_originalColor;
    cocos2d::CCSprite* m_currentColorSprite;
    cocos2d::CCSprite* m_originalColorSprite;
    cocos2d::ccColor3B m_currentColor;
    ColorSelectDelegate* m_delegate;
    float m_fadeTime;
    int m_playerColor;
    int m_blending;
    float m_opacity;
    ColorAction* m_colorAction;
    CCTextInputNode* m_colorInput;
    bool m_backgroundTrigger;
    bool m_tintGround;
    bool m_legacyHSV;
    bool m_colorTrigger;
    bool m_noChannel;
    bool m_newColorTrigger;
    int m_colorID;
    bool m_initalizing;
    int m_copyColorID;
    bool m_copyOpacity;
    ConfigureHSVWidget* m_hsvWidget;
    cocos2d::ccHSVValue m_hsv;
    cocos2d::CCArray* m_colorObjects;
    cocos2d::CCArray* m_copyObjects;
    CCTextInputNode* m_copyColorInput;
    CCTextInputNode* m_fadeTimeInput;
    void* m_unk488;
    void* m_unk490;
    bool m_showCopyObjects;
    CCTextInputNode* m_rInput;
    CCTextInputNode* m_gInput;
    CCTextInputNode* m_bInput;
    CCTextInputNode* m_hexInput;
};
