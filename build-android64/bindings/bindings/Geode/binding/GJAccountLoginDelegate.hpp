#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJAccountLoginDelegate {
public:
    static constexpr auto CLASS_NAME = "GJAccountLoginDelegate";

    /**
     * @note[short] Android
     */
    virtual void loginAccountFinished(int p0, int p1);

    /**
     * @note[short] Android
     */
    virtual void loginAccountFailed(AccountError p0);
};
