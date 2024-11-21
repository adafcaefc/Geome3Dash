#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJSpecialColorSelectDelegate {
public:
    static constexpr auto CLASS_NAME = "GJSpecialColorSelectDelegate";
    
private:
    [[deprecated("GJSpecialColorSelectDelegate::colorSelectClosed not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void colorSelectClosed(GJSpecialColorSelect* p0, int p1);
public:
};
