#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class NCSInfoLayer {
public:
    static constexpr auto CLASS_NAME = "NCSInfoLayer";

    /**
     * @note[short] Android
     */
    static NCSInfoLayer* create(CustomSongLayer* p0);

    /**
     * @note[short] MacOS (ARM): 0x1bbda8
     * @note[short] MacOS (Intel): 0x206d40
     * @note[short] iOS: 0x14a3ac
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x1bb640
     * @note[short] MacOS (Intel): 0x2065a0
     * @note[short] Android
     */
    bool init(CustomSongLayer* p0);

    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onLibrary(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (Intel): 0x206cb0
     * @note[short] Android
     */
    void onNCS(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (Intel): 0x206cd0
     * @note[short] Android
     */
    void onNCSIO(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (Intel): 0x206cf0
     * @note[short] Android
     */
    void onNCSUsage(cocos2d::CCObject* sender);
};
