#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class OptionsObjectDelegate {
public:
    static constexpr auto CLASS_NAME = "OptionsObjectDelegate";
    
private:
    [[deprecated("OptionsObjectDelegate::stateChanged not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void stateChanged(OptionsObject* p0);
public:
};
