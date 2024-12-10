#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJAccountSettingsDelegate {
public:
    static constexpr auto CLASS_NAME = "GJAccountSettingsDelegate";

    /**
     * @note[short] Android
     */
    virtual void updateSettingsFinished();

    /**
     * @note[short] Android
     */
    virtual void updateSettingsFailed();
};
