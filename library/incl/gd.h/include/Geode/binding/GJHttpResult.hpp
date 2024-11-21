#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJHttpResult : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "GJHttpResult";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJHttpResult, cocos2d::CCNode)
    
private:
    [[deprecated("GJHttpResult::create not implemented")]]
    /**
     * @note[short] Android
     */
    static GJHttpResult* create(bool p0, gd::string p1, gd::string p2, GJHttpType p3);
public:
    
private:
    [[deprecated("GJHttpResult::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(bool p0, gd::string p1, gd::string p2, GJHttpType p3);
public:
};
