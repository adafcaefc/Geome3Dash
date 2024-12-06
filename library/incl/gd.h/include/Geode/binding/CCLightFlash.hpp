#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class CCLightFlash : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "CCLightFlash";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(CCLightFlash, cocos2d::CCNode)

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
     CCLightFlash();

    /**
     * @note[short] MacOS (ARM): 0x451614
     * @note[short] MacOS (Intel): 0x4f0560
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static CCLightFlash* create();

    /**
     * @note[short] MacOS (ARM): 0x451678
     * @note[short] MacOS (Intel): 0x4f05d0
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x3501c
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (Intel): 0x4f0e50
     * @note[short] Windows: 0x43c80
     * @note[short] Android
     */
    void cleanupFlash();
    
private:
    [[deprecated("CCLightFlash::fadeAndRemove not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x451c20
     * @note[short] Android
     */
    void fadeAndRemove();
public:

    /**
     * @note[short] MacOS (ARM): 0x451680
     * @note[short] MacOS (Intel): 0x4f05e0
     * @note[short] Windows: 0x433a0
     * @note[short] Android
     */
    void playEffect(cocos2d::CCPoint pos, cocos2d::ccColor3B col, float startWidth, float startWidthVariation, float endWidth, float endWidthVariation, float endHeight, float stripDuration, float stripDurationVariance, float stripInterval, float stripStartDelay, float stripStartDelayVariation, float stripRotation, float stripRotationVariation, float stripOpacity, float stripOpacityVariation, int stripCount, bool circleRotation, bool fadeIn, float delay);

    /**
     * @note[short] Windows: 0x43c20
     * @note[short] Android
     */
    void removeLights();

    /**
     * @note[short] MacOS (ARM): 0x451af4
     * @note[short] MacOS (Intel): 0x4f0b30
     * @note[short] Windows: 0x438e0
     * @note[short] Android
     */
    void showFlash();
    cocos2d::CCArray* m_lightStripArray;
    cocos2d::CCLayerColor* m_layerColor;
    bool m_dontFadeOut;
    cocos2d::CCNode* m_mainLayer;
    int m_layerColorZOrder;
};
