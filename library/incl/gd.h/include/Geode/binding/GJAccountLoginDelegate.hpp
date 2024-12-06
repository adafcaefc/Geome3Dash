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
    
private:
    [[deprecated("GJAccountLoginDelegate::loginAccountFinished not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void loginAccountFinished(int p0, int p1);
public:
    
private:
    [[deprecated("GJAccountLoginDelegate::loginAccountFailed not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void loginAccountFailed(AccountError p0);
public:
};
