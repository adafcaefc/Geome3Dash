#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "FLAlertLayer.hpp"

class SelectPremadeLayer : public FLAlertLayer {
public:
    static constexpr auto CLASS_NAME = "SelectPremadeLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SelectPremadeLayer, FLAlertLayer)

    /**
     * @note[short] Android
     */
    static SelectPremadeLayer* create();

    /**
     * @note[short] MacOS (ARM): 0x28ef80
     * @note[short] MacOS (Intel): 0x2f5fc0
     * @note[short] iOS: 0x66fa4
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (ARM): 0x28f4c8
     * @note[short] MacOS (Intel): 0x2f64c0
     * @note[short] iOS: 0x6745c
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onSelectPremade(cocos2d::CCObject* sender);
};
