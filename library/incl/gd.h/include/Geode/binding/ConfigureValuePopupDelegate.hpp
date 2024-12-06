#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class ConfigureValuePopupDelegate {
public:
    static constexpr auto CLASS_NAME = "ConfigureValuePopupDelegate";
    
private:
    [[deprecated("ConfigureValuePopupDelegate::valuePopupClosed not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void valuePopupClosed(ConfigureValuePopup* p0, float p1);
public:
};
