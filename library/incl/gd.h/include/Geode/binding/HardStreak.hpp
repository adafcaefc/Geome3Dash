#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class HardStreak : public cocos2d::CCDrawNode {
public:
    static constexpr auto CLASS_NAME = "HardStreak";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(HardStreak, cocos2d::CCDrawNode)

    /**
     * @note[short] Windows: 0x2b1680
     * @note[short] Android
     */
    static HardStreak* create();
    
private:
    [[deprecated("HardStreak::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8f704
     * @note[short] MacOS (Intel): 0x9ca80
     * @note[short] iOS: 0x614d8
     * @note[short] Android
     */
    virtual bool init();
public:

    /**
     * @note[short] MacOS (ARM): 0x8ffec
     * @note[short] MacOS (Intel): 0x9d500
     * @note[short] Windows: 0x2b2130
     * @note[short] Android
     */
    void addPoint(cocos2d::CCPoint p0);
    
private:
    [[deprecated("HardStreak::clearAboveXPos not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn clearAboveXPos(float p0);
public:
    
private:
    [[deprecated("HardStreak::clearBehindXPos not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn clearBehindXPos(float p0);
public:

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    HardStreak* createDuplicate();
    
private:
    [[deprecated("HardStreak::firstSetup not implemented")]]
    /**
     * @note[short] Android
     */
    void firstSetup();
public:
    
private:
    [[deprecated("HardStreak::normalizeAngle not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn normalizeAngle(double p0);
public:
    
private:
    [[deprecated("HardStreak::quadCornerOffset not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn quadCornerOffset(cocos2d::CCPoint p0, cocos2d::CCPoint p1, float p2);
public:

    /**
     * @note[short] MacOS (ARM): 0x8ffc8
     * @note[short] MacOS (Intel): 0x9d4e0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void reset();
    
private:
    [[deprecated("HardStreak::resumeStroke not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8ff80
     * @note[short] MacOS (Intel): 0x9d480
     * @note[short] Android
     */
    void resumeStroke();
public:
    
private:
    [[deprecated("HardStreak::scheduleAutoUpdate not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn scheduleAutoUpdate();
public:

    /**
     * @note[short] Windows: 0x2b17f0
     * @note[short] Android
     */
    void stopStroke();

    /**
     * @note[short] MacOS (ARM): 0x8f870
     * @note[short] MacOS (Intel): 0x9cc30
     * @note[short] Windows: 0x2b1830
     * @note[short] Android
     */
    void updateStroke(float p0);
    cocos2d::CCArray* m_pointArray;
    cocos2d::CCPoint m_currentPoint;
    float m_waveSize;
    float m_pulseSize;
    bool m_isSolid;
    bool m_isFlipped;
    bool m_drawStreak;
};
