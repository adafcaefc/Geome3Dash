#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class AnimatedSpriteDelegate {
public:
    static constexpr auto CLASS_NAME = "AnimatedSpriteDelegate";
    
private:
    [[deprecated("AnimatedSpriteDelegate::animationFinished not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void animationFinished(char const* p0);
public:
};
