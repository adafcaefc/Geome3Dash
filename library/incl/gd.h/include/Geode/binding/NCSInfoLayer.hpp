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
    
private:
    [[deprecated("NCSInfoLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static NCSInfoLayer* create(CustomSongLayer* p0);
public:
    
private:
    [[deprecated("NCSInfoLayer::keyBackClicked not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1bbda8
     * @note[short] MacOS (Intel): 0x206d40
     * @note[short] iOS: 0x14a3ac
     * @note[short] Android
     */
    virtual void keyBackClicked();
public:
    
private:
    [[deprecated("NCSInfoLayer::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1bb640
     * @note[short] MacOS (Intel): 0x2065a0
     * @note[short] Android
     */
    bool init(CustomSongLayer* p0);
public:
    
private:
    [[deprecated("NCSInfoLayer::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("NCSInfoLayer::onLibrary not implemented")]]
    /**
     * @note[short] Android
     */
    void onLibrary(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("NCSInfoLayer::onNCS not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x206cb0
     * @note[short] Android
     */
    void onNCS(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("NCSInfoLayer::onNCSIO not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x206cd0
     * @note[short] Android
     */
    void onNCSIO(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("NCSInfoLayer::onNCSUsage not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x206cf0
     * @note[short] Android
     */
    void onNCSUsage(cocos2d::CCObject* sender);
public:
};
