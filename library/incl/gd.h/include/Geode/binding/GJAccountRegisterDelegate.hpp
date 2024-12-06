#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJAccountRegisterDelegate {
public:
    static constexpr auto CLASS_NAME = "GJAccountRegisterDelegate";
    
private:
    [[deprecated("GJAccountRegisterDelegate::registerAccountFinished not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void registerAccountFinished();
public:
    
private:
    [[deprecated("GJAccountRegisterDelegate::registerAccountFailed not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void registerAccountFailed(AccountError p0);
public:
};
