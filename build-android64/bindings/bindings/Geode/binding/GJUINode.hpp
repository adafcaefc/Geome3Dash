#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJUINode : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "GJUINode";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJUINode, cocos2d::CCNode)

    /**
     * @note[short] MacOS (Intel): 0x4b5100
     * @note[short] Android
     */
    static GJUINode* create(UIButtonConfig& p0);

    /**
     * @note[short] MacOS (ARM): 0x4200f4
     * @note[short] MacOS (Intel): 0x4b8390
     * @note[short] iOS: 0x4ed2c
     * @note[short] Android
     */
    virtual void draw();

    /**
     * @note[short] Android
     */
    TodoReturn activeRangeTouchTest(cocos2d::CCPoint p0);

    /**
     * @note[short] Android
     */
    TodoReturn activeTouchTest(cocos2d::CCPoint p0);

    /**
     * @note[short] Android
     */
    TodoReturn getButtonScale();

    /**
     * @note[short] Android
     */
    TodoReturn getOpacity();

    /**
     * @note[short] Android
     */
    TodoReturn highlightButton(int p0);

    /**
     * @note[short] Android
     */
    bool init(UIButtonConfig& p0);

    /**
     * @note[short] Android
     */
    void loadFromConfig(UIButtonConfig& p0);

    /**
     * @note[short] Android
     */
    TodoReturn resetState();

    /**
     * @note[short] Android
     */
    TodoReturn saveToConfig(UIButtonConfig& p0);

    /**
     * @note[short] Android
     */
    void setOpacity(unsigned char p0);

    /**
     * @note[short] Android
     */
    TodoReturn toggleHighlight(int p0, bool p1);

    /**
     * @note[short] Android
     */
    void toggleModeB(bool p0);

    /**
     * @note[short] Android
     */
    TodoReturn touchEnded();

    /**
     * @note[short] Android
     */
    TodoReturn touchTest(cocos2d::CCPoint p0);

    /**
     * @note[short] MacOS (ARM): 0x41fdb8
     * @note[short] MacOS (Intel): 0x4b8000
     * @note[short] Android
     */
    TodoReturn updateButtonFrames();

    /**
     * @note[short] Android
     */
    TodoReturn updateButtonPositions();

    /**
     * @note[short] Android
     */
    TodoReturn updateButtonScale(float p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateDeadzone(int p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateDragRadius(float p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateHeight(float p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateRangePos(cocos2d::CCPoint p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateSize(float p0, float p1);

    /**
     * @note[short] Android
     */
    TodoReturn updateWidth(float p0);
};
