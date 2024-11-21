#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GravityEffectSprite : public cocos2d::CCSprite {
public:
    static constexpr auto CLASS_NAME = "GravityEffectSprite";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GravityEffectSprite, cocos2d::CCSprite)
    
private:
    [[deprecated("GravityEffectSprite::create not implemented")]]
    /**
     * @note[short] Android
     */
    static GravityEffectSprite* create();
public:
    
private:
    [[deprecated("GravityEffectSprite::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xae348
     * @note[short] MacOS (Intel): 0xbfa30
     * @note[short] iOS: 0x126114
     * @note[short] Android
     */
    virtual bool init();
public:
    
private:
    [[deprecated("GravityEffectSprite::draw not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xae56c
     * @note[short] MacOS (Intel): 0xbfc90
     * @note[short] iOS: 0x126338
     * @note[short] Android
     */
    virtual void draw();
public:
    
private:
    [[deprecated("GravityEffectSprite::updateSpritesColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateSpritesColor(cocos2d::ccColor3B p0);
public:
};
