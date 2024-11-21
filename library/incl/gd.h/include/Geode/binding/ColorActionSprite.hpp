#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class ColorActionSprite : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "ColorActionSprite";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(ColorActionSprite, cocos2d::CCNode)
    
private:
    [[deprecated("ColorActionSprite::create not implemented")]]
    /**
     * @note[short] Android
     */
    static ColorActionSprite* create();
public:
    
private:
    [[deprecated("ColorActionSprite::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x268d18
     * @note[short] MacOS (Intel): 0x2c4e30
     * @note[short] iOS: 0x10d8c
     * @note[short] Android
     */
    virtual bool init();
public:
    float m_opacity;
    cocos2d::ccColor3B m_color;
    cocos2d::ccColor3B m_copyColor;
};
