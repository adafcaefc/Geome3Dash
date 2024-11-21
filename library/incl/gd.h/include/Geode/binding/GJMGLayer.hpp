#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJMGLayer : public cocos2d::CCLayer {
public:
    static constexpr auto CLASS_NAME = "GJMGLayer";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJMGLayer, cocos2d::CCLayer)
    
private:
    [[deprecated("GJMGLayer::create not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x5d3a40
     * @note[short] Android
     */
    static GJMGLayer* create(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x508038
     * @note[short] MacOS (Intel): 0x5d4520
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x31548
     * @note[short] Android: Out of line
     */
    virtual void draw();
    
private:
    [[deprecated("GJMGLayer::showGround not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x508008
     * @note[short] MacOS (Intel): 0x5d44f0
     * @note[short] iOS: 0x3153c
     * @note[short] Android
     */
    virtual void showGround();
public:
    
private:
    [[deprecated("GJMGLayer::deactivateGround not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn deactivateGround();
public:
    
private:
    [[deprecated("GJMGLayer::defaultYOffsetForBG2 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn defaultYOffsetForBG2(int p0);
public:
    
private:
    [[deprecated("GJMGLayer::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(int p0);
public:
    
private:
    [[deprecated("GJMGLayer::loadGroundSprites not implemented")]]
    /**
     * @note[short] Android
     */
    void loadGroundSprites(int p0, bool p1);
public:
    
private:
    [[deprecated("GJMGLayer::scaleGround not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn scaleGround(float p0);
public:
    
private:
    [[deprecated("GJMGLayer::toggleVisible01 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleVisible01(bool p0);
public:
    
private:
    [[deprecated("GJMGLayer::toggleVisible02 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleVisible02(bool p0);
public:
    
private:
    [[deprecated("GJMGLayer::updateGroundColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateGroundColor(cocos2d::ccColor3B p0, bool p1);
public:
    
private:
    [[deprecated("GJMGLayer::updateGroundOpacity not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x5d4300
     * @note[short] Android
     */
    TodoReturn updateGroundOpacity(unsigned char p0, bool p1);
public:
    
private:
    [[deprecated("GJMGLayer::updateGroundPos not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateGroundPos(cocos2d::CCPoint p0);
public:
    
private:
    [[deprecated("GJMGLayer::updateGroundWidth not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateGroundWidth(bool p0);
public:
    
private:
    [[deprecated("GJMGLayer::updateMG01Blend not implemented")]]
    /**
     * @note[short] Android
     */
    void updateMG01Blend(bool p0);
public:
    
private:
    [[deprecated("GJMGLayer::updateMG02Blend not implemented")]]
    /**
     * @note[short] Android
     */
    void updateMG02Blend(bool p0);
public:
};
