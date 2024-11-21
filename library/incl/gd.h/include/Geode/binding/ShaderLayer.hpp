#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "GJShaderState.hpp"

class ShaderLayer : public cocos2d::CCLayer {
public:
    static constexpr auto CLASS_NAME = "ShaderLayer";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(ShaderLayer, cocos2d::CCLayer)
    
private:
    [[deprecated("ShaderLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static ShaderLayer* create();
public:

    /**
     * @note[short] MacOS (ARM): 0x342afc
     * @note[short] MacOS (Intel): 0x3b7930
     * @note[short] Windows: 0x4697b0
     * @note[short] iOS: 0x26cd28
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (ARM): 0x3442d4
     * @note[short] MacOS (Intel): 0x3b91b0
     * @note[short] Windows: 0x4697b0
     * @note[short] iOS: 0x26e070
     * @note[short] Android
     */
    virtual void update(float p0);

    /**
     * @note[short] MacOS (ARM): 0x348f24
     * @note[short] MacOS (Intel): 0x3bee90
     * @note[short] Windows: 0x470580
     * @note[short] iOS: 0x272320
     * @note[short] Android
     */
    virtual void visit();
    
private:
    [[deprecated("ShaderLayer::objectPosToShaderPos not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn objectPosToShaderPos(cocos2d::CCPoint p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x348c6c
     * @note[short] MacOS (Intel): 0x3beb80
     * @note[short] Windows: 0x46fbd0
     * @note[short] Android
     */
    void performCalculations();
    
private:
    [[deprecated("ShaderLayer::preBulgeShader not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn preBulgeShader();
public:
    
private:
    [[deprecated("ShaderLayer::preChromaticGlitchShader not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn preChromaticGlitchShader();
public:
    
private:
    [[deprecated("ShaderLayer::preChromaticShader not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3bc6a0
     * @note[short] Android
     */
    TodoReturn preChromaticShader();
public:
    
private:
    [[deprecated("ShaderLayer::preColorChangeShader not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3be680
     * @note[short] Android
     */
    TodoReturn preColorChangeShader();
public:
    
private:
    [[deprecated("ShaderLayer::preCommonShader not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3b93c0
     * @note[short] Android
     */
    TodoReturn preCommonShader();
public:
    
private:
    [[deprecated("ShaderLayer::preGlitchShader not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3bc0f0
     * @note[short] Android
     */
    TodoReturn preGlitchShader();
public:
    
private:
    [[deprecated("ShaderLayer::preGrayscaleShader not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3be160
     * @note[short] Android
     */
    TodoReturn preGrayscaleShader();
public:
    
private:
    [[deprecated("ShaderLayer::preHueShiftShader not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn preHueShiftShader();
public:
    
private:
    [[deprecated("ShaderLayer::preInvertColorShader not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn preInvertColorShader();
public:
    
private:
    [[deprecated("ShaderLayer::preLensCircleShader not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3bd4a0
     * @note[short] Android
     */
    TodoReturn preLensCircleShader();
public:
    
private:
    [[deprecated("ShaderLayer::preMotionBlurShader not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn preMotionBlurShader();
public:
    
private:
    [[deprecated("ShaderLayer::prepareTargetContainer not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCPoint prepareTargetContainer();
public:
    
private:
    [[deprecated("ShaderLayer::prePinchShader not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn prePinchShader();
public:
    
private:
    [[deprecated("ShaderLayer::prePixelateShader not implemented")]]
    /**
     * @note[short] Android
     */
    void prePixelateShader();
public:
    
private:
    [[deprecated("ShaderLayer::preRadialBlurShader not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3bd770
     * @note[short] Android
     */
    TodoReturn preRadialBlurShader();
public:
    
private:
    [[deprecated("ShaderLayer::preSepiaShader not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn preSepiaShader();
public:
    
private:
    [[deprecated("ShaderLayer::preShockLineShader not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3bbbd0
     * @note[short] Android
     */
    TodoReturn preShockLineShader();
public:
    
private:
    [[deprecated("ShaderLayer::preShockWaveShader not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3bb510
     * @note[short] Android
     */
    TodoReturn preShockWaveShader();
public:
    
private:
    [[deprecated("ShaderLayer::preSplitScreenShader not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn preSplitScreenShader();
public:

    /**
     * @note[short] Windows: 0x4710f0
     * @note[short] Android
     */
    bool resetAllShaders();
    
private:
    [[deprecated("ShaderLayer::resetTargetContainer not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetTargetContainer();
public:
    
private:
    [[deprecated("ShaderLayer::setupBulgeShader not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x343da0
     * @note[short] MacOS (Intel): 0x3b8c80
     * @note[short] Android
     */
    TodoReturn setupBulgeShader();
public:
    
private:
    [[deprecated("ShaderLayer::setupChromaticGlitchUniforms not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x343b30
     * @note[short] MacOS (Intel): 0x3b8a10
     * @note[short] Android
     */
    TodoReturn setupChromaticGlitchUniforms();
public:
    
private:
    [[deprecated("ShaderLayer::setupChromaticUniforms not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x343acc
     * @note[short] MacOS (Intel): 0x3b89b0
     * @note[short] Android
     */
    TodoReturn setupChromaticUniforms();
public:
    
private:
    [[deprecated("ShaderLayer::setupColorChangeShader not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x3440ec
     * @note[short] MacOS (Intel): 0x3b8fc0
     * @note[short] Android
     */
    TodoReturn setupColorChangeShader();
public:
    
private:
    [[deprecated("ShaderLayer::setupCommonUniforms not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x3434e0
     * @note[short] MacOS (Intel): 0x3b83b0
     * @note[short] Android
     */
    TodoReturn setupCommonUniforms();
public:
    
private:
    [[deprecated("ShaderLayer::setupGlitchUniforms not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x3439fc
     * @note[short] MacOS (Intel): 0x3b88e0
     * @note[short] Android
     */
    TodoReturn setupGlitchUniforms();
public:
    
private:
    [[deprecated("ShaderLayer::setupGrayscaleShader not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x343f80
     * @note[short] MacOS (Intel): 0x3b8e60
     * @note[short] Android
     */
    TodoReturn setupGrayscaleShader();
public:
    
private:
    [[deprecated("ShaderLayer::setupHueShiftShader not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x344088
     * @note[short] MacOS (Intel): 0x3b8f60
     * @note[short] Android
     */
    TodoReturn setupHueShiftShader();
public:
    
private:
    [[deprecated("ShaderLayer::setupInvertColorShader not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x344048
     * @note[short] MacOS (Intel): 0x3b8f20
     * @note[short] Android
     */
    TodoReturn setupInvertColorShader();
public:
    
private:
    [[deprecated("ShaderLayer::setupLensCircleShader not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x343c48
     * @note[short] MacOS (Intel): 0x3b8b30
     * @note[short] Android
     */
    TodoReturn setupLensCircleShader();
public:
    
private:
    [[deprecated("ShaderLayer::setupMotionBlurShader not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x343ef8
     * @note[short] MacOS (Intel): 0x3b8de0
     * @note[short] Android
     */
    TodoReturn setupMotionBlurShader();
public:
    
private:
    [[deprecated("ShaderLayer::setupPinchShader not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x343e4c
     * @note[short] MacOS (Intel): 0x3b8d30
     * @note[short] Android
     */
    TodoReturn setupPinchShader();
public:
    
private:
    [[deprecated("ShaderLayer::setupRadialBlurShader not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x343d3c
     * @note[short] MacOS (Intel): 0x3b8c20
     * @note[short] Android
     */
    TodoReturn setupRadialBlurShader();
public:
    
private:
    [[deprecated("ShaderLayer::setupSepiaShader not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x344008
     * @note[short] MacOS (Intel): 0x3b8ee0
     * @note[short] Android
     */
    TodoReturn setupSepiaShader();
public:

    /**
     * @note[short] MacOS (Intel): 0x3b79f0
     * @note[short] Windows: 0x4698c0
     * @note[short] Android
     */
    void setupShader(bool p0);
    
private:
    [[deprecated("ShaderLayer::setupShockLineUniforms not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x343830
     * @note[short] MacOS (Intel): 0x3b8710
     * @note[short] Android
     */
    TodoReturn setupShockLineUniforms();
public:
    
private:
    [[deprecated("ShaderLayer::setupShockWaveUniforms not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x343664
     * @note[short] MacOS (Intel): 0x3b8540
     * @note[short] Android
     */
    TodoReturn setupShockWaveUniforms();
public:
    
private:
    [[deprecated("ShaderLayer::setupSplitScreenShader not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x344150
     * @note[short] MacOS (Intel): 0x3b9020
     * @note[short] Android
     */
    TodoReturn setupSplitScreenShader();
public:

    /**
     * @note[short] Windows: 0x46a4f0
     * @note[short] Android
     */
    void toggleAntiAlias(bool p0);
    
private:
    [[deprecated("ShaderLayer::triggerBulge not implemented")]]
    /**
     * @note[short] Android
     */
    bool triggerBulge(float p0, float p1, float p2, float p3, float p4, int p5, int p6, float p7, bool p8);
public:
    
private:
    [[deprecated("ShaderLayer::triggerChromaticGlitch not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn triggerChromaticGlitch(bool p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, int p8, float p9, bool p10, bool p11);
public:
    
private:
    [[deprecated("ShaderLayer::triggerChromaticX not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3bc640
     * @note[short] Android
     */
    TodoReturn triggerChromaticX(float p0, float p1, int p2, float p3, bool p4);
public:
    
private:
    [[deprecated("ShaderLayer::triggerChromaticY not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn triggerChromaticY(float p0, float p1, int p2, float p3, bool p4);
public:
    
private:
    [[deprecated("ShaderLayer::triggerColorChange not implemented")]]
    /**
     * @note[short] Android
     */
    bool triggerColorChange(float p0, float p1, float p2, float p3, float p4, float p5, float p6, int p7, float p8);
public:
    
private:
    [[deprecated("ShaderLayer::triggerGlitch not implemented")]]
    /**
     * @note[short] Android
     */
    bool triggerGlitch(float p0, float p1, float p2, float p3, float p4, float p5, float p6, bool p7);
public:
    
private:
    [[deprecated("ShaderLayer::triggerGrayscale not implemented")]]
    /**
     * @note[short] Android
     */
    bool triggerGrayscale(float p0, float p1, bool p2, int p3, int p4, float p5);
public:
    
private:
    [[deprecated("ShaderLayer::triggerHueShift not implemented")]]
    /**
     * @note[short] Android
     */
    bool triggerHueShift(float p0, float p1, int p2, float p3);
public:
    
private:
    [[deprecated("ShaderLayer::triggerInvertColor not implemented")]]
    /**
     * @note[short] Android
     */
    bool triggerInvertColor(float p0, float p1, float p2, float p3, float p4, bool p5, bool p6, bool p7, int p8, float p9);
public:
    
private:
    [[deprecated("ShaderLayer::triggerLensCircle not implemented")]]
    /**
     * @note[short] Android
     */
    bool triggerLensCircle(float p0, float p1, float p2, float p3, int p4, int p5, float p6, float p7, int p8, float p9, bool p10);
public:
    
private:
    [[deprecated("ShaderLayer::triggerMotionBlurX not implemented")]]
    /**
     * @note[short] Android
     */
    bool triggerMotionBlurX(float p0, float p1, float p2, float p3, int p4, float p5, bool p6, int p7, int p8, float p9, bool p10, bool p11);
public:
    
private:
    [[deprecated("ShaderLayer::triggerMotionBlurY not implemented")]]
    /**
     * @note[short] Android
     */
    bool triggerMotionBlurY(float p0, float p1, float p2, float p3, int p4, float p5, bool p6, int p7, int p8, float p9, bool p10, bool p11);
public:
    
private:
    [[deprecated("ShaderLayer::triggerPinchX not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3bdf10
     * @note[short] Android
     */
    bool triggerPinchX(float p0, float p1, float p2, float p3, float p4, bool p5, int p6, int p7, float p8, bool p9);
public:
    
private:
    [[deprecated("ShaderLayer::triggerPinchY not implemented")]]
    /**
     * @note[short] Android
     */
    bool triggerPinchY(float p0, float p1, float p2, float p3, float p4, bool p5, int p6, int p7, float p8, bool p9);
public:
    
private:
    [[deprecated("ShaderLayer::triggerPixelateX not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3bccf0
     * @note[short] Android
     */
    bool triggerPixelateX(float p0, float p1, bool p2, bool p3, int p4, float p5, bool p6);
public:
    
private:
    [[deprecated("ShaderLayer::triggerPixelateY not implemented")]]
    /**
     * @note[short] Android
     */
    bool triggerPixelateY(float p0, float p1, bool p2, bool p3, int p4, float p5, bool p6);
public:
    
private:
    [[deprecated("ShaderLayer::triggerRadialBlur not implemented")]]
    /**
     * @note[short] Android
     */
    bool triggerRadialBlur(float p0, float p1, float p2, float p3, int p4, float p5, float p6, bool p7, int p8, int p9, float p10, bool p11);
public:
    
private:
    [[deprecated("ShaderLayer::triggerSepia not implemented")]]
    /**
     * @note[short] Android
     */
    bool triggerSepia(float p0, float p1, int p2, float p3);
public:
    
private:
    [[deprecated("ShaderLayer::triggerShockLine not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3bb970
     * @note[short] Android
     */
    bool triggerShockLine(float p0, float p1, bool p2, bool p3, bool p4, bool p5, float p6, float p7, float p8, float p9, float p10, float p11, int p12, bool p13, bool p14, bool p15, float p16, bool p17, float p18, int p19, float p20);
public:
    
private:
    [[deprecated("ShaderLayer::triggerShockWave not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3bac70
     * @note[short] Android
     */
    bool triggerShockWave(float p0, float p1, float p2, float p3, float p4, float p5, float p6, bool p7, float p8, float p9, float p10, int p11, bool p12, bool p13, bool p14, float p15, float p16, bool p17, float p18, int p19, float p20);
public:
    
private:
    [[deprecated("ShaderLayer::triggerSplitScreenCols not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3be870
     * @note[short] Android
     */
    bool triggerSplitScreenCols(float p0, float p1, int p2, float p3);
public:
    
private:
    [[deprecated("ShaderLayer::triggerSplitScreenRows not implemented")]]
    /**
     * @note[short] Android
     */
    bool triggerSplitScreenRows(float p0, float p1, int p2, float p3);
public:
    
private:
    [[deprecated("ShaderLayer::tweenValue not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn tweenValue(float p0, float p1, int p2, float p3, int p4, float p5);
public:
    
private:
    [[deprecated("ShaderLayer::tweenValueAuto not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3baef0
     * @note[short] Android
     */
    TodoReturn tweenValueAuto(float p0, int p1, float p2, int p3, float p4);
public:
    
private:
    [[deprecated("ShaderLayer::updateEffectOffsets not implemented")]]
    /**
     * @note[short] Android
     */
    void updateEffectOffsets(cocos2d::CCPoint p0);
public:
    
private:
    [[deprecated("ShaderLayer::updateMotionBlurSpeedX not implemented")]]
    /**
     * @note[short] Android
     */
    void updateMotionBlurSpeedX(float p0, float p1);
public:
    
private:
    [[deprecated("ShaderLayer::updateMotionBlurSpeedY not implemented")]]
    /**
     * @note[short] Android
     */
    void updateMotionBlurSpeedY(float p0, float p1);
public:
    
private:
    [[deprecated("ShaderLayer::updateShockLineCenter not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3bbb90
     * @note[short] Android
     */
    TodoReturn updateShockLineCenter(cocos2d::CCPoint p0);
public:
    
private:
    [[deprecated("ShaderLayer::updateShockWaveCenter not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3bb4d0
     * @note[short] Android
     */
    TodoReturn updateShockWaveCenter(cocos2d::CCPoint p0);
public:
    
private:
    [[deprecated("ShaderLayer::updateZLayer not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x3b82d0
     * @note[short] Android
     */
    bool updateZLayer(int p0, int p1, bool p2);
public:
    GJShaderState m_state;
    bool m_unk3c0;
    cocos2d::CCGLProgram* m_shader;
    cocos2d::CCRenderTexture* m_renderTexture;
    cocos2d::CCSprite* m_sprite;
    bool m_antiAlias;
    bool m_configuredAntiAlias;
    void* m_unk3d4;
    GJBaseGameLayer* m_gameLayer;
    cocos2d::CCPoint m_savedCameraPosition;
    float m_savedCameraRotation;
    float m_shockWaveTimeMult;
    float m_scaleFactor;
    float m_aspectRatio;
    cocos2d::CCSize m_screenSize;
    cocos2d::CCSize m_textureContentSize;
    cocos2d::CCSize m_targetTextureSize;
    cocos2d::CCSize m_targetTextureSizeExtra;
    int m_textureScaleUniform;
    int m_textureScaleInvUniform;
    int m_screenAspectUniform;
    int m_screenAspectINVUniform;
    int m_shaderPositionUniform;
    int m_blurRefColorUniform;
    int m_blurUseRefUniform;
    int m_blurIntensityUniform;
    int m_blurOnlyEmptyUniform;
    int m_shockWaveTimeUniform;
    int m_shockWaveTime1Uniform;
    int m_shockWaveTime2Uniform;
    int m_shockWaveTime3Uniform;
    int m_shockWaveTime4Uniform;
    int m_shockWaveStrengthUniform;
    int m_shockWaveWavesUniform;
    int m_shockWaveCenterUniform;
    int m_shockWaveInvertUniform;
    int m_shockWaveMinSizeUniform;
    int m_shockWaveMaxSizeUniform;
    int m_shockWaveMaxDistValUniform;
    float m_shockWaveTime1;
    float m_shockWaveTime2;
    float m_shockWaveTime3;
    float m_shockWaveTime4;
    float m_shockWaveMaxDistVal;
    float m_shockWaveMinSize;
    float m_shockWaveMaxSize;
    bool m_shockWaveUnk46c;
    int m_shockLineTimeUniform;
    int m_shockLineTime1Uniform;
    int m_shockLineTime2Uniform;
    int m_shockLineTime3Uniform;
    int m_shockLineTime4Uniform;
    int m_shockLineAxisUniform;
    int m_shockLineDirectionUniform;
    int m_shockLineDualUniform;
    int m_shockLineWavesUniform;
    int m_shockLineStrengthUniform;
    int m_shockLineCenterUniform;
    int m_shockLineMaxDistValUniform;
    float m_shockLineTime1;
    float m_shockLineTime2;
    float m_shockLineTime3;
    float m_shockLineTime4;
    float m_shockLineMaxDistVal;
    int m_unk4b4;
    int m_unk4b8;
    int m_unk4bc;
    int m_glitchBotUniform;
    int m_glitchTopUniform;
    int m_glitchXOffsetUniform;
    int m_glitchColOffsetUniform;
    int m_glitchRndUniform;
    int m_chromaticXOffUniform;
    int m_chromaticYOffUniform;
    int m_cGRGBOffsetUniform;
    int m_cGYOffsetUniform;
    int m_cGTimeUniform;
    int m_cGStrengthUniform;
    int m_cGHeightUniform;
    int m_cGLineThickUniform;
    int m_cGLineStrengthUniform;
    int m_lensCircleOriginUniform;
    int m_lensCircleStartUniform;
    int m_lensCircleEndUniform;
    int m_lensCircleStrengthUniform;
    int m_lensCircleTintUniform;
    int m_lensCircleAdditiveUniform;
    int m_radialBlurCenterUniform;
    int m_radialBlurValueUniform;
    int m_blurFadeUniform;
    int m_motionBlurValueUniform;
    int m_motionBlurMultUniform;
    int m_motionBlurDualUniform;
    int m_bulgeValueUniform;
    int m_bulgeValue2Uniform;
    int m_bulgeOriginUniform;
    int m_bulgeRadiusUniform;
    int m_pinchValueUniform;
    int m_pinchCenterPosUniform;
    int m_pinchCalcUniform;
    int m_pinchRadiusUniform;
    int m_grayscaleValueUniform;
    int m_grayscaleTintUniform;
    int m_grayscaleUseLumUniform;
    int m_sepiaValueUniform;
    int m_invertColorValueUniform;
    int m_hueShiftCosAUniform;
    int m_hueShiftSinAUniform;
    int m_colorChangeCUniform;
    int m_colorChangeBUniform;
    int m_rowmodUniform;
    int m_colmodUniform;
    int m_rowmodCalcUniform;
    int m_colmodCalcUniform;
    int m_splitXStartUniform;
    int m_splitXRangeUniform;
    int m_splitXRangeMultUniform;
    int m_splitYStartUniform;
    int m_splitYRangeUniform;
    int m_splitYRangeMultUniform;
};
