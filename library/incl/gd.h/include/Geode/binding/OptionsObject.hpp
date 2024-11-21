#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class OptionsObject : public cocos2d::CCObject {
public:
    static constexpr auto CLASS_NAME = "OptionsObject";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(OptionsObject, cocos2d::CCObject)
    
private:
    [[deprecated("OptionsObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static OptionsObject* create(int p0, bool p1, gd::string p2, OptionsObjectDelegate* p3);
public:
    
private:
    [[deprecated("OptionsObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(int p0, bool p1, gd::string p2, OptionsObjectDelegate* p3);
public:
    
private:
    [[deprecated("OptionsObject::toggleState not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleState();
public:
};
