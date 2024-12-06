#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class SpritePartDelegate {
public:
    static constexpr auto CLASS_NAME = "SpritePartDelegate";
    
private:
    [[deprecated("SpritePartDelegate::displayFrameChanged not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void displayFrameChanged(cocos2d::CCObject* p0, gd::string p1);
public:
};
