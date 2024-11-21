#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class ShareCommentDelegate {
public:
    static constexpr auto CLASS_NAME = "ShareCommentDelegate";
    
private:
    [[deprecated("ShareCommentDelegate::shareCommentClosed not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void shareCommentClosed(gd::string p0, ShareCommentLayer* p1);
public:
};
