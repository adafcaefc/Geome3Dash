#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class SecretNumberLayer : public cocos2d::CCLayer {
public:
    static constexpr auto CLASS_NAME = "SecretNumberLayer";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(SecretNumberLayer, cocos2d::CCLayer)
    
private:
    [[deprecated("SecretNumberLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SecretNumberLayer* create();
public:
    
private:
    [[deprecated("SecretNumberLayer::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x3fcf14
     * @note[short] MacOS (Intel): 0x4901a0
     * @note[short] iOS: 0x30dd14
     * @note[short] Android
     */
    virtual bool init();
public:
    
private:
    [[deprecated("SecretNumberLayer::playNumberEffect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn playNumberEffect(int p0);
public:
};
