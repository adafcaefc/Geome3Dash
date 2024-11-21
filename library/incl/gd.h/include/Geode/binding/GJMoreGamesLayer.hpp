#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "GJDropDownLayer.hpp"

class GJMoreGamesLayer : public GJDropDownLayer {
public:
    static constexpr auto CLASS_NAME = "GJMoreGamesLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(GJMoreGamesLayer, GJDropDownLayer)

    /**
     * @note[short] MacOS (ARM): 0x69376c
     * @note[short] MacOS (Intel): 0x77eca0
     * @note[short] Windows: 0x278610
     * @note[short] Android
     */
    static GJMoreGamesLayer* create();
    
private:
    [[deprecated("GJMoreGamesLayer::customSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x693ed4
     * @note[short] MacOS (Intel): 0x77f500
     * @note[short] iOS: 0x6911c
     * @note[short] Android
     */
    virtual void customSetup();
public:
    
private:
    [[deprecated("GJMoreGamesLayer::getMoreGamesList not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getMoreGamesList();
public:
};
