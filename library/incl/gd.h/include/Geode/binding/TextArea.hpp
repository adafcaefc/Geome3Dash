#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class TextArea : public cocos2d::CCSprite {
public:
    static constexpr auto CLASS_NAME = "TextArea";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(TextArea, cocos2d::CCSprite)

    /**
     * @note[short] MacOS (ARM): 0x2a4014
     * @note[short] MacOS (Intel): 0x30d440
     * @note[short] Windows: 0x76e50
     * @note[short] Android
     */
    static TextArea* create(gd::string str, char const* font, float scale, float width, cocos2d::CCPoint anchor, float lineHeight, bool disableColor);

    /**
     * @note[short] MacOS (ARM): 0x2a4c5c
     * @note[short] MacOS (Intel): 0x30e100
     * @note[short] Windows: 0x776b0
     * @note[short] iOS: 0xf9ff4
     * @note[short] Android
     */
    virtual void update(float p0);

    /**
     * @note[short] MacOS (ARM): 0x2a4c58
     * @note[short] MacOS (Intel): 0x30e0f0
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0xf9ff0
     * @note[short] Android: Out of line
     */
    virtual void draw();

    /**
     * @note[short] MacOS (ARM): 0x2a4ab4
     * @note[short] MacOS (Intel): 0x30df50
     * @note[short] Windows: 0x775c0
     * @note[short] iOS: 0xf9e54
     * @note[short] Android
     */
    virtual void setOpacity(unsigned char p0);

    /**
     * @note[short] MacOS (ARM): 0x2a4b20
     * @note[short] MacOS (Intel): 0x30dfc0
     * @note[short] Windows: 0x77600
     * @note[short] Android
     */
    void colorAllCharactersTo(cocos2d::ccColor3B p0);
    
private:
    [[deprecated("TextArea::colorAllLabels not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2a4be4
     * @note[short] MacOS (Intel): 0x30e070
     * @note[short] Android
     */
    void colorAllLabels(cocos2d::ccColor3B p0);
public:
    
private:
    [[deprecated("TextArea::fadeIn not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2a47e4
     * @note[short] Android
     */
    void fadeIn(float p0, bool p1);
public:
    
private:
    [[deprecated("TextArea::fadeInCharacters not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2a4db0
     * @note[short] Android
     */
    void fadeInCharacters(float p0, float p1, bool p2, TextFadeInStyle p3);
public:
    
private:
    [[deprecated("TextArea::fadeOut not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2a49b4
     * @note[short] Android
     */
    void fadeOut(float p0);
public:
    
private:
    [[deprecated("TextArea::fadeOutAndRemove not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2a4944
     * @note[short] MacOS (Intel): 0x30ddf0
     * @note[short] Android
     */
    void fadeOutAndRemove();
public:

    /**
     * @note[short] MacOS (ARM): 0x2a4920
     * @note[short] MacOS (Intel): 0x30ddc0
     * @note[short] Windows: 0x775a0
     * @note[short] Android
     */
    void finishFade();
    
private:
    [[deprecated("TextArea::hideAll not implemented")]]
    /**
     * @note[short] Android
     */
    void hideAll();
public:
    
private:
    [[deprecated("TextArea::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2a41bc
     * @note[short] MacOS (Intel): 0x30d5f0
     * @note[short] Android
     */
    bool init(gd::string str, char const* font, float scale, float width, cocos2d::CCPoint anchor, float lineHeight, bool disableColor);
public:
    
private:
    [[deprecated("TextArea::setIgnoreColorCode not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x30da00
     * @note[short] Android
     */
    void setIgnoreColorCode(bool p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x2a42b4
     * @note[short] MacOS (Intel): 0x30d6f0
     * @note[short] Windows: 0x77090
     * @note[short] Android
     */
    void setString(gd::string p0);
    
private:
    [[deprecated("TextArea::showAll not implemented")]]
    /**
     * @note[short] Android
     */
    void showAll();
public:

    /**
     * @note[short] MacOS (Intel): 0x30daf0
     * @note[short] Windows: 0x774e0
     * @note[short] Android
     */
    void stopAllCharacterActions();
    bool m_disableColor;
    MultilineBitmapFont* m_label;
    float m_width;
    int m_unknown;
    gd::string m_fontFile;
    float m_height;
    bool m_unkBool;
    cocos2d::CCPoint m_anchorPoint;
    bool m_allShown;
    float m_scale;
    int m_rectHeight;
    int m_rectWidth;
    float m_maxWidth;
    cocos2d::CCPoint m_unkPoint;
    TextAreaDelegate* m_delegate;
    cocos2d::CCDictionary* m_shakeCharacters;
    float m_shakeElapsed;
};
