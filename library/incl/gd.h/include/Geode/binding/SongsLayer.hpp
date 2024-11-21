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

class SongsLayer : public GJDropDownLayer {
public:
    static constexpr auto CLASS_NAME = "SongsLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SongsLayer, GJDropDownLayer)
    
private:
    [[deprecated("SongsLayer::create not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x45b7a8
     * @note[short] MacOS (Intel): 0x4fba10
     * @note[short] Android
     */
    static SongsLayer* create();
public:

    /**
     * @note[short] MacOS (ARM): 0x45b920
     * @note[short] MacOS (Intel): 0x4fbc40
     * @note[short] Windows: 0x47c050
     * @note[short] iOS: 0x346974
     * @note[short] Android
     */
    virtual void customSetup();
};
