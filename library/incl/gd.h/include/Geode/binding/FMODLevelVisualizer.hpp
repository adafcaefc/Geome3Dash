#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include <fmod.hpp>

class FMODLevelVisualizer : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "FMODLevelVisualizer";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(FMODLevelVisualizer, cocos2d::CCNode)

    /**
     * @note[short] MacOS (ARM): 0x244748
     * @note[short] MacOS (Intel): 0x29cfb0
     * @note[short] Windows: 0x297150
     * @note[short] Android
     */
    static FMODLevelVisualizer* create();
    
private:
    [[deprecated("FMODLevelVisualizer::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2447d0
     * @note[short] MacOS (Intel): 0x29d020
     * @note[short] iOS: 0x2e0c20
     * @note[short] Android
     */
    virtual bool init();
public:

    /**
     * @note[short] MacOS (ARM): 0x244c40
     * @note[short] MacOS (Intel): 0x29d460
     * @note[short] Windows: 0x297690
     * @note[short] Android
     */
    void updateVisualizer(float p0, float p1, float p2);
    float m_width;
};
