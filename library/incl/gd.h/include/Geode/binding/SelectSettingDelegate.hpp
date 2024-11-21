#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class SelectSettingDelegate {
public:
    static constexpr auto CLASS_NAME = "SelectSettingDelegate";
    
private:
    [[deprecated("SelectSettingDelegate::selectSettingClosed not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void selectSettingClosed(SelectSettingLayer* p0);
public:
};
