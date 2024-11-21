#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJGradientLayer : public cocos2d::CCLayerGradient {
public:
    static constexpr auto CLASS_NAME = "GJGradientLayer";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJGradientLayer, cocos2d::CCLayerGradient)
    
private:
    [[deprecated("GJGradientLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static GJGradientLayer* create();
public:
    
private:
    [[deprecated("GJGradientLayer::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x128178
     * @note[short] MacOS (Intel): 0x154550
     * @note[short] iOS: 0x20b450
     * @note[short] Android
     */
    virtual bool init();
public:
};
