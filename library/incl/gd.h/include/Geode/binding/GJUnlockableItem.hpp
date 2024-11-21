#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJUnlockableItem : public cocos2d::CCObject {
public:
    static constexpr auto CLASS_NAME = "GJUnlockableItem";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJUnlockableItem, cocos2d::CCObject)
    
private:
    [[deprecated("GJUnlockableItem::create not implemented")]]
    /**
     * @note[short] Android
     */
    static GJUnlockableItem* create();
public:
    
private:
    [[deprecated("GJUnlockableItem::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init();
public:
};
