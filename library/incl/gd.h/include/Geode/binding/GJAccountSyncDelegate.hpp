#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJAccountSyncDelegate {
public:
    static constexpr auto CLASS_NAME = "GJAccountSyncDelegate";
    
private:
    [[deprecated("GJAccountSyncDelegate::syncAccountFinished not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void syncAccountFinished();
public:
    
private:
    [[deprecated("GJAccountSyncDelegate::syncAccountFailed not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void syncAccountFailed(BackupAccountError p0, int p1);
public:
};
