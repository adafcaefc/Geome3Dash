#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJGroundLayer : public cocos2d::CCLayer {
public:
    static constexpr auto CLASS_NAME = "GJGroundLayer";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJGroundLayer, cocos2d::CCLayer)

    /**
     * @note[short] MacOS (Intel): 0x5d2760
     * @note[short] Windows: 0x276870
     * @note[short] Android
     */
    static GJGroundLayer* create(int p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0x50745c
     * @note[short] MacOS (Intel): 0x5d38a0
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x30c08
     * @note[short] Android: Out of line
     */
    virtual void draw();

    /**
     * @note[short] MacOS (ARM): 0x507250
     * @note[short] MacOS (Intel): 0x5d36c0
     * @note[short] Windows: 0x2774c0
     * @note[short] iOS: 0x30aa0
     * @note[short] Android
     */
    virtual void showGround();

    /**
     * @note[short] MacOS (ARM): 0x50725c
     * @note[short] MacOS (Intel): 0x5d36d0
     * @note[short] Windows: 0x2774d0
     * @note[short] iOS: 0x30aac
     * @note[short] Android
     */
    virtual TodoReturn fadeInGround(float p0);

    /**
     * @note[short] MacOS (ARM): 0x507430
     * @note[short] MacOS (Intel): 0x5d3870
     * @note[short] Windows: 0x2776c0
     * @note[short] iOS: 0x30c00
     * @note[short] Android
     */
    virtual TodoReturn fadeOutGround(float p0);

    /**
     * @note[short] MacOS (ARM): 0x506958
     * @note[short] MacOS (Intel): 0x5d2d50
     * @note[short] Windows: 0x277120
     * @note[short] Android
     */
    void createLine(int p0);
    
private:
    [[deprecated("GJGroundLayer::deactivateGround not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn deactivateGround();
public:
    
private:
    [[deprecated("GJGroundLayer::fadeInFinished not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn fadeInFinished();
public:
    
private:
    [[deprecated("GJGroundLayer::getGroundY not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getGroundY();
public:
    
private:
    [[deprecated("GJGroundLayer::hideShadows not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn hideShadows();
public:

    /**
     * @note[short] MacOS (ARM): 0x506450
     * @note[short] MacOS (Intel): 0x5d2870
     * @note[short] Windows: 0x2768f0
     * @note[short] Android
     */
    bool init(int p0, int p1);

    /**
     * @note[short] Windows: 0x276e60
     * @note[short] Android
     */
    void loadGroundSprites(int p0, bool p1);
    
private:
    [[deprecated("GJGroundLayer::positionGround not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x5d38b0
     * @note[short] Android
     */
    void positionGround(float p0);
public:

    /**
     * @note[short] MacOS (Intel): 0x5d3350
     * @note[short] Windows: 0x277310
     * @note[short] Android
     */
    TodoReturn scaleGround(float p0);
    
private:
    [[deprecated("GJGroundLayer::toggleVisible01 not implemented")]]
    /**
     * @note[short] Android
     */
    void toggleVisible01(bool p0);
public:
    
private:
    [[deprecated("GJGroundLayer::toggleVisible02 not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x506e20
     * @note[short] Android
     */
    void toggleVisible02(bool p0);
public:
    
private:
    [[deprecated("GJGroundLayer::updateGround01Color not implemented")]]
    /**
     * @note[short] Android
     */
    void updateGround01Color(cocos2d::ccColor3B p0);
public:
    
private:
    [[deprecated("GJGroundLayer::updateGround02Color not implemented")]]
    /**
     * @note[short] Android
     */
    void updateGround02Color(cocos2d::ccColor3B p0);
public:
    
private:
    [[deprecated("GJGroundLayer::updateGroundPos not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateGroundPos(cocos2d::CCPoint p0);
public:
    
private:
    [[deprecated("GJGroundLayer::updateGroundWidth not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateGroundWidth(bool p0);
public:
    
private:
    [[deprecated("GJGroundLayer::updateLineBlend not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x507214
     * @note[short] MacOS (Intel): 0x5d3670
     * @note[short] Android
     */
    void updateLineBlend(bool p0);
public:

    /**
     * @note[short] MacOS (Intel): 0x5d35e0
     * @note[short] Windows: 0x277550
     * @note[short] Android
     */
    TodoReturn updateShadows();

    /**
     * @note[short] MacOS (Intel): 0x5d37b0
     * @note[short] Windows: 0x2775f0
     * @note[short] Android
     */
    TodoReturn updateShadowXPos(float p0, float p1);
};
