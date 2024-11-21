#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class CCURLObject : public cocos2d::CCObject {
public:
    static constexpr auto CLASS_NAME = "CCURLObject";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(CCURLObject, cocos2d::CCObject)
    
private:
    [[deprecated("CCURLObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static CCURLObject* create(gd::string p0, gd::string p1);
public:
    
private:
    [[deprecated("CCURLObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(gd::string p0, gd::string p1);
public:
};
