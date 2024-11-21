#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJDailyLevelDelegate {
public:
    static constexpr auto CLASS_NAME = "GJDailyLevelDelegate";
    
private:
    [[deprecated("GJDailyLevelDelegate::dailyStatusFinished not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void dailyStatusFinished(GJTimedLevelType p0);
public:
    
private:
    [[deprecated("GJDailyLevelDelegate::dailyStatusFailed not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void dailyStatusFailed(GJTimedLevelType p0, GJErrorCode p1);
public:
};
