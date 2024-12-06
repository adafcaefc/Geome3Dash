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

class SetupPulsePopup : public SetupTriggerPopup, public cocos2d::extension::ColorPickerDelegate, public GJSpecialColorSelectDelegate {
public:
    static constexpr auto CLASS_NAME = "SetupPulsePopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupPulsePopup, SetupTriggerPopup)
    
private:
    [[deprecated("SetupPulsePopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupPulsePopup* create(EffectGameObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupPulsePopup::show not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x32a368
     * @note[short] MacOS (Intel): 0x39ce50
     * @note[short] iOS: 0x3affd0
     * @note[short] Android
     */
    virtual void show();
public:
    
private:
    [[deprecated("SetupPulsePopup::determineStartValues not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x32924c
     * @note[short] MacOS (Intel): 0x39ba60
     * @note[short] iOS: 0x3af378
     * @note[short] Android
     */
    virtual void determineStartValues();
public:
    
private:
    [[deprecated("SetupPulsePopup::onClose not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x329c84
     * @note[short] MacOS (Intel): 0x39c670
     * @note[short] iOS: 0x3afbc8
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x32a3c4
     * @note[short] MacOS (Intel): 0x39ced0
     * @note[short] Windows: 0x424150
     * @note[short] iOS: 0x3b002c
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x329e10
     * @note[short] MacOS (Intel): 0x39c850
     * @note[short] Windows: 0x423e90
     * @note[short] iOS: 0x3afce8
     * @note[short] Android
     */
    virtual void colorValueChanged(cocos2d::ccColor3B p0);

    /**
     * @note[short] MacOS (ARM): 0x32a3bc
     * @note[short] MacOS (Intel): 0x39ceb0
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x3b0024
     * @note[short] Android: Out of line
     */
    virtual void textInputOpened(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x3296fc
     * @note[short] MacOS (Intel): 0x39bfa0
     * @note[short] Windows: 0x423720
     * @note[short] iOS: 0x3af7cc
     * @note[short] Android
     */
    virtual void colorSelectClosed(GJSpecialColorSelect* p0, int p1);
    
private:
    [[deprecated("SetupPulsePopup::getColorValue not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getColorValue();
public:

    /**
     * @note[short] MacOS (ARM): 0x3250b8
     * @note[short] MacOS (Intel): 0x397170
     * @note[short] Windows: 0x41f430
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1);
    
private:
    [[deprecated("SetupPulsePopup::onCopy not implemented")]]
    /**
     * @note[short] Android
     */
    void onCopy(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupPulsePopup::onExclusive not implemented")]]
    /**
     * @note[short] Android
     */
    void onExclusive(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupPulsePopup::onGroupMainOnly not implemented")]]
    /**
     * @note[short] Android
     */
    void onGroupMainOnly(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupPulsePopup::onGroupSecondaryOnly not implemented")]]
    /**
     * @note[short] Android
     */
    void onGroupSecondaryOnly(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupPulsePopup::onHSVLegacyMode not implemented")]]
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

    /**
     * @note[short] Windows: 0x422aa0
     * @note[short] Android
     */
    void onSelectPulseMode(cocos2d::CCObject* sender);
    
private:
    [[deprecated("SetupPulsePopup::onSelectSpecialColor not implemented")]]
    /**
     * @note[short] Android
     */
    void onSelectSpecialColor(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupPulsePopup::onSelectSpecialTargetID not implemented")]]
    /**
     * @note[short] Android
     */
    void onSelectSpecialTargetID(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupPulsePopup::onSelectTargetMode not implemented")]]
    /**
     * @note[short] Android
     */
    void onSelectTargetMode(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupPulsePopup::onUpdateCopyColor not implemented")]]
    /**
     * @note[short] Android
     */
    void onUpdateCopyColor(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupPulsePopup::onUpdateCustomColor not implemented")]]
    /**
     * @note[short] Android
     */
    void onUpdateCustomColor(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupPulsePopup::selectColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn selectColor(cocos2d::ccColor3B p0);
public:
    
private:
    [[deprecated("SetupPulsePopup::sliderChanged not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn sliderChanged(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("SetupPulsePopup::updateColorLabels not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateColorLabels();
public:
    
private:
    [[deprecated("SetupPulsePopup::updateColorValue not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateColorValue();
public:
    
private:
    [[deprecated("SetupPulsePopup::updateCopyColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateCopyColor();
public:
    
private:
    [[deprecated("SetupPulsePopup::updateCopyColorTextInputLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateCopyColorTextInputLabel();
public:
    
private:
    [[deprecated("SetupPulsePopup::updateFadeInLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateFadeInLabel(bool p0);
public:
    
private:
    [[deprecated("SetupPulsePopup::updateFadeInTime not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateFadeInTime();
public:
    
private:
    [[deprecated("SetupPulsePopup::updateFadeOutLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateFadeOutLabel(bool p0);
public:
    
private:
    [[deprecated("SetupPulsePopup::updateFadeOutTime not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateFadeOutTime();
public:
    
private:
    [[deprecated("SetupPulsePopup::updateGroupMainOnly not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateGroupMainOnly();
public:
    
private:
    [[deprecated("SetupPulsePopup::updateGroupSecondaryOnly not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateGroupSecondaryOnly();
public:
    
private:
    [[deprecated("SetupPulsePopup::updateHoldLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateHoldLabel(bool p0);
public:
    
private:
    [[deprecated("SetupPulsePopup::updateHoldTime not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateHoldTime();
public:
    
private:
    [[deprecated("SetupPulsePopup::updateHSVValue not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateHSVValue();
public:
    
private:
    [[deprecated("SetupPulsePopup::updatePulseMode not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updatePulseMode();
public:
    
private:
    [[deprecated("SetupPulsePopup::updatePulseTargetType not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updatePulseTargetType();
public:
    
private:
    [[deprecated("SetupPulsePopup::updateTargetID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTargetID();
public:
    
private:
    [[deprecated("SetupPulsePopup::updateTextInputLabel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTextInputLabel();
public:
};
