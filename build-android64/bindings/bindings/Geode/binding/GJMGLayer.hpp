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

    /**
     * @note[short] MacOS (Intel): 0x5d3a40
     * @note[short] Android
     */
    static GJMGLayer* create(int p0);

    /**
     * @note[short] MacOS (ARM): 0x508038
     * @note[short] MacOS (Intel): 0x5d4520
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x31548
     * @note[short] Android: Out of line
     */
    virtual void draw();

    /**
     * @note[short] MacOS (ARM): 0x508008
     * @note[short] MacOS (Intel): 0x5d44f0
     * @note[short] iOS: 0x3153c
     * @note[short] Android
     */
    virtual void showGround();

    /**
     * @note[short] Android
     */
    TodoReturn deactivateGround();

    /**
     * @note[short] Android
     */
    TodoReturn defaultYOffsetForBG2(int p0);

    /**
     * @note[short] Android
     */
    bool init(int p0);

    /**
     * @note[short] Android
     */
    void loadGroundSprites(int p0, bool p1);

    /**
     * @note[short] Android
     */
    TodoReturn scaleGround(float p0);

    /**
     * @note[short] Android
     */
    TodoReturn toggleVisible01(bool p0);

    /**
     * @note[short] Android
     */
    TodoReturn toggleVisible02(bool p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateGroundColor(cocos2d::ccColor3B p0, bool p1);

    /**
     * @note[short] MacOS (Intel): 0x5d4300
     * @note[short] Android
     */
    TodoReturn updateGroundOpacity(unsigned char p0, bool p1);

    /**
     * @note[short] Android
     */
    TodoReturn updateGroundPos(cocos2d::CCPoint p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateGroundWidth(bool p0);

    /**
     * @note[short] Android
     */
    void updateMG01Blend(bool p0);

    /**
     * @note[short] Android
     */
    void updateMG02Blend(bool p0);
};
