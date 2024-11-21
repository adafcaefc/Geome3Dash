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

class GJPromoPopup : public FLAlertLayer {
public:
    static constexpr auto CLASS_NAME = "GJPromoPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(GJPromoPopup, FLAlertLayer)
    
private:
    [[deprecated("GJPromoPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static GJPromoPopup* create(gd::string p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x249ff4
     * @note[short] MacOS (Intel): 0x2a3260
     * @note[short] Windows: 0x29d890
     * @note[short] iOS: 0x2e515c
     * @note[short] Android
     */
    virtual void onExit();
    
private:
    [[deprecated("GJPromoPopup::registerWithTouchDispatcher not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x24a104
     * @note[short] MacOS (Intel): 0x2a3370
     * @note[short] iOS: 0x2e519c
     * @note[short] Android
     */
    virtual void registerWithTouchDispatcher();
public:
    
private:
    [[deprecated("GJPromoPopup::keyBackClicked not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x24a034
     * @note[short] MacOS (Intel): 0x2a32a0
     * @note[short] iOS: 0x2e5190
     * @note[short] Android
     */
    virtual void keyBackClicked();
public:
    
private:
    [[deprecated("GJPromoPopup::show not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x24a13c
     * @note[short] MacOS (Intel): 0x2a33b0
     * @note[short] iOS: 0x2e51d4
     * @note[short] Android
     */
    virtual void show();
public:

    /**
     * @note[short] MacOS (Intel): 0x2a2f80
     * @note[short] Windows: 0x29d590
     * @note[short] Android
     */
    bool init(gd::string p0);
    
private:
    [[deprecated("GJPromoPopup::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:
};
