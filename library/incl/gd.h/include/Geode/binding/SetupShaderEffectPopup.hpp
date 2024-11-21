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

class SetupShaderEffectPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupShaderEffectPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupShaderEffectPopup, SetupTriggerPopup)
    
private:
    [[deprecated("SetupShaderEffectPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupShaderEffectPopup* create(EffectGameObject* p0, cocos2d::CCArray* p1, int p2);
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::toggleGroup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x261df0
     * @note[short] MacOS (Intel): 0x2bd2d0
     * @note[short] iOS: 0x18d670
     * @note[short] Android
     */
    virtual void toggleGroup(int p0, bool p1);
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::onClose not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x261e30
     * @note[short] MacOS (Intel): 0x2bd310
     * @note[short] iOS: 0x18d6b0
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::updateDefaultTriggerValues not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2614cc
     * @note[short] MacOS (Intel): 0x2bca50
     * @note[short] iOS: 0x18d054
     * @note[short] Android
     */
    virtual void updateDefaultTriggerValues();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::valueDidChange not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x261ab4
     * @note[short] MacOS (Intel): 0x2bcf90
     * @note[short] iOS: 0x18d3d8
     * @note[short] Android
     */
    virtual void valueDidChange(int p0, float p1);
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(EffectGameObject* p0, cocos2d::CCArray* p1, int p2);
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::onResetColors not implemented")]]
    /**
     * @note[short] Android
     */
    void onResetColors(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::onZLayer not implemented")]]
    /**
     * @note[short] Android
     */
    void onZLayer(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::setupBulge not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x25de18
     * @note[short] MacOS (Intel): 0x2b8e60
     * @note[short] Android
     */
    TodoReturn setupBulge();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::setupChromatic not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x25ad9c
     * @note[short] MacOS (Intel): 0x2b57d0
     * @note[short] Android
     */
    TodoReturn setupChromatic();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::setupChromaticGlitch not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x25b2f8
     * @note[short] MacOS (Intel): 0x2b5d70
     * @note[short] Android
     */
    TodoReturn setupChromaticGlitch();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::setupColorChange not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2601c0
     * @note[short] MacOS (Intel): 0x2bb610
     * @note[short] Android
     */
    TodoReturn setupColorChange();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::setupGlitch not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x25a738
     * @note[short] MacOS (Intel): 0x2b5110
     * @note[short] Android
     */
    TodoReturn setupGlitch();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::setupGrayscale not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x25f120
     * @note[short] MacOS (Intel): 0x2ba490
     * @note[short] Android
     */
    TodoReturn setupGrayscale();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::setupHueShift not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x25feb8
     * @note[short] MacOS (Intel): 0x2bb2f0
     * @note[short] Android
     */
    TodoReturn setupHueShift();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::setupInvertColor not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x25f89c
     * @note[short] MacOS (Intel): 0x2bac60
     * @note[short] Android
     */
    TodoReturn setupInvertColor();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::setupLensCircle not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x25c124
     * @note[short] MacOS (Intel): 0x2b6cf0
     * @note[short] Android
     */
    TodoReturn setupLensCircle();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::setupMotionBlur not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x25d314
     * @note[short] MacOS (Intel): 0x2b81c0
     * @note[short] Android
     */
    TodoReturn setupMotionBlur();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::setupPinch not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x25e654
     * @note[short] MacOS (Intel): 0x2b97e0
     * @note[short] Android
     */
    TodoReturn setupPinch();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::setupPixelate not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x25baa4
     * @note[short] MacOS (Intel): 0x2b65f0
     * @note[short] Android
     */
    TodoReturn setupPixelate();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::setupRadialBlur not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x25c9b0
     * @note[short] MacOS (Intel): 0x2b76e0
     * @note[short] Android
     */
    TodoReturn setupRadialBlur();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::setupSepia not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x25f5b0
     * @note[short] MacOS (Intel): 0x2ba990
     * @note[short] Android
     */
    TodoReturn setupSepia();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::setupShaderTrigger not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x260cac
     * @note[short] MacOS (Intel): 0x2bc190
     * @note[short] Android
     */
    TodoReturn setupShaderTrigger();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::setupShockLine not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x259658
     * @note[short] MacOS (Intel): 0x2b3d30
     * @note[short] Android
     */
    TodoReturn setupShockLine();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::setupShockWave not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2584b4
     * @note[short] MacOS (Intel): 0x2b2840
     * @note[short] Android
     */
    TodoReturn setupShockWave();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::setupSplitScreen not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x260808
     * @note[short] MacOS (Intel): 0x2bbcd0
     * @note[short] Android
     */
    TodoReturn setupSplitScreen();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::updateZLayerButtons not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateZLayerButtons();
public:
    
private:
    [[deprecated("SetupShaderEffectPopup::zLayerToString not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn zLayerToString(int p0);
public:
};
