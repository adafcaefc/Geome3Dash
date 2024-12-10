#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJAccountBackupDelegate {
public:
    static constexpr auto CLASS_NAME = "GJAccountBackupDelegate";

    /**
     * @note[short] Android
     */
    virtual void backupAccountFinished();

    /**
     * @note[short] Android
     */
    virtual void backupAccountFailed(BackupAccountError p0, int p1);
};
