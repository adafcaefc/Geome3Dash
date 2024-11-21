#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class ColorAction : public cocos2d::CCObject {
public:
    static constexpr auto CLASS_NAME = "ColorAction";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(ColorAction, cocos2d::CCObject)

    /**
     * @note[short] MacOS (Intel): 0x2c5030
     * @note[short] Windows: 0x251b40
     * @note[short] Android
     */
    static ColorAction* create();
    
private:
    [[deprecated("ColorAction::create not implemented")]]
    /**
     * @note[short] Android
     */
    static ColorAction* create(cocos2d::ccColor3B p0, bool p1, int p2);
public:
    
private:
    [[deprecated("ColorAction::create not implemented")]]
    /**
     * @note[short] Android
     */
    static ColorAction* create(cocos2d::ccColor3B p0, cocos2d::ccColor3B p1, float p2, double p3, bool p4, int p5, float p6, float p7);
public:
    
private:
    [[deprecated("ColorAction::create not implemented")]]
    /**
     * @note[short] Android
     */
    static ColorAction* create(cocos2d::ccColor3B p0, cocos2d::ccColor3B p1, float p2, double p3, bool p4);
public:
    
private:
    [[deprecated("ColorAction::getCopy not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getCopy();
public:
    
private:
    [[deprecated("ColorAction::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(cocos2d::ccColor3B p0, cocos2d::ccColor3B p1, float p2, double p3, bool p4, int p5, float p6, float p7);
public:
    
private:
    [[deprecated("ColorAction::isInUse not implemented")]]
    /**
     * @note[short] Android
     */
    bool isInUse();
public:

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void loadFromState(CAState& state);
    
private:
    [[deprecated("ColorAction::resetAction not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetAction();
public:

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void saveToState(CAState& state);

    /**
     * @note[short] Windows: 0x252800
     * @note[short] Android
     */
    void setupFromMap(gd::map<gd::string, gd::string>& p0);

    /**
     * @note[short] MacOS (Intel): 0x2c7390
     * @note[short] Windows: 0x252720
     * @note[short] Android
     */
    void setupFromString(gd::string p0);

    /**
     * @note[short] Windows: 0x251c30
     * @note[short] Android
     */
    void step(float p0);
    
private:
    [[deprecated("ColorAction::updateCustomColor not implemented")]]
    /**
     * @note[short] Android
     */
    void updateCustomColor(cocos2d::ccColor3B p0, cocos2d::ccColor3B p1);
public:
    bool m_stepFinished;
    bool m_property19;
    cocos2d::ccColor3B m_color;
    float m_currentOpacity;
    float m_deltaTime;
    cocos2d::ccColor3B m_fromColor;
    cocos2d::ccColor3B m_toColor;
    float m_duration;
    bool m_blending;
    int m_playerColor;
    int m_colorID;
    float m_fromOpacity;
    float m_toOpacity;
    cocos2d::ccHSVValue m_copyHSV;
    int m_copyID;
    bool m_unknown;
    bool m_unknown2;
    bool m_copyOpacity;
    ColorActionSprite* m_colorSprite;
};
