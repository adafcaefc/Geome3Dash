#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class ListUploadDelegate {
public:
    static constexpr auto CLASS_NAME = "ListUploadDelegate";
    
private:
    [[deprecated("ListUploadDelegate::listUploadFinished not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void listUploadFinished(GJLevelList* p0);
public:
    
private:
    [[deprecated("ListUploadDelegate::listUploadFailed not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void listUploadFailed(GJLevelList* p0, int p1);
public:
};
