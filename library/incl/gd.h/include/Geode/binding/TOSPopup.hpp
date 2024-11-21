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

class TOSPopup : public FLAlertLayer {
public:
    static constexpr auto CLASS_NAME = "TOSPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(TOSPopup, FLAlertLayer)
    
private:
    [[deprecated("TOSPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static TOSPopup* create();
public:

    /**
     * @note[short] MacOS (ARM): 0x243ea8
     * @note[short] MacOS (Intel): 0x29c720
     * @note[short] Windows: 0x296930
     * @note[short] iOS: 0x2e0414
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (ARM): 0x2444f4
     * @note[short] MacOS (Intel): 0x29cda0
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x2e0a24
     * @note[short] Android: Out of line
     */
    virtual void keyBackClicked();
    
private:
    [[deprecated("TOSPopup::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("TOSPopup::onPrivacy not implemented")]]
    /**
     * @note[short] Android
     */
    void onPrivacy(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("TOSPopup::onTOS not implemented")]]
    /**
     * @note[short] Android
     */
    void onTOS(cocos2d::CCObject* sender);
public:
};
