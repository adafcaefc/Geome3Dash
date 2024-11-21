#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class AudioEffectsLayer : public cocos2d::CCLayerColor {
public:
    static constexpr auto CLASS_NAME = "AudioEffectsLayer";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(AudioEffectsLayer, cocos2d::CCLayerColor)
    
private:
    [[deprecated("AudioEffectsLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static AudioEffectsLayer* create(gd::string p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x407cdc
     * @note[short] MacOS (Intel): 0x49cba0
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x3bcf70
     * @note[short] Android: Out of line
     */
    virtual void draw();
    
private:
    [[deprecated("AudioEffectsLayer::updateTweenAction not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x407ba0
     * @note[short] MacOS (Intel): 0x49ca70
     * @note[short] iOS: 0x3bce70
     * @note[short] Android
     */
    virtual void updateTweenAction(float p0, char const* p1);
public:

    /**
     * @note[short] MacOS (Intel): 0x49c860
     * @note[short] Windows: 0x84d80
     * @note[short] Android
     */
    void audioStep(float p0);
    
private:
    [[deprecated("AudioEffectsLayer::getBGSquare not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getBGSquare();
public:
    
private:
    [[deprecated("AudioEffectsLayer::goingDown not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn goingDown();
public:
    
private:
    [[deprecated("AudioEffectsLayer::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(gd::string p0);
public:
    
private:
    [[deprecated("AudioEffectsLayer::resetAudioVars not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x407928
     * @note[short] MacOS (Intel): 0x49c800
     * @note[short] Android
     */
    void resetAudioVars();
public:
    
private:
    [[deprecated("AudioEffectsLayer::triggerEffect not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x49c930
     * @note[short] Android
     */
    TodoReturn triggerEffect(float p0);
public:
    cocos2d::CCSpriteBatchNode* m_batchNode;
    cocos2d::CCArray* m_unk1bc;
    cocos2d::CCArray* m_unk1c0;
    float m_unk1c4;
    float m_unk1c8;
    bool m_goingDown;
    float m_notAudioScale;
    bool m_unk1d4;
};
