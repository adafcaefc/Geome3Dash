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

class StarInfoPopup : public FLAlertLayer {
public:
    static constexpr auto CLASS_NAME = "StarInfoPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(StarInfoPopup, FLAlertLayer)

    /**
     * @note[short] MacOS (ARM): 0x6bdd58
     * @note[short] MacOS (Intel): 0x7ac620
     * @note[short] Windows: 0x3b0cb0
     * @note[short] Android
     */
    static StarInfoPopup* create(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, bool p9);
    
private:
    [[deprecated("StarInfoPopup::createFromString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x6baa6c
     * @note[short] Android
     */
    static StarInfoPopup* createFromString(gd::string p0);
public:
    
private:
    [[deprecated("StarInfoPopup::createFromStringMoons not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x6bacd4
     * @note[short] Android
     */
    static StarInfoPopup* createFromStringMoons(gd::string p0);
public:
    
private:
    [[deprecated("StarInfoPopup::keyBackClicked not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x6be87c
     * @note[short] MacOS (Intel): 0x7ad0e0
     * @note[short] iOS: 0x1a1584
     * @note[short] Android
     */
    virtual void keyBackClicked();
public:

    /**
     * @note[short] MacOS (ARM): 0x6bdeb0
     * @note[short] MacOS (Intel): 0x7ac7b0
     * @note[short] Windows: 0x3b0df0
     * @note[short] Android
     */
    bool init(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, bool p9);
    
private:
    [[deprecated("StarInfoPopup::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:
};
