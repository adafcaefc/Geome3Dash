#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class DownloadMessageDelegate {
public:
    static constexpr auto CLASS_NAME = "DownloadMessageDelegate";
    
private:
    [[deprecated("DownloadMessageDelegate::downloadMessageFinished not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void downloadMessageFinished(GJUserMessage* p0);
public:
    
private:
    [[deprecated("DownloadMessageDelegate::downloadMessageFailed not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void downloadMessageFailed(int p0);
public:
};
