#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class PointNode : public cocos2d::CCObject {
public:
    static constexpr auto CLASS_NAME = "PointNode";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(PointNode, cocos2d::CCObject)
    
private:
    [[deprecated("PointNode::create not implemented")]]
    /**
     * @note[short] Android
     */
    static PointNode* create(cocos2d::CCPoint p0);
public:
    
private:
    [[deprecated("PointNode::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Android
     */
    bool init(cocos2d::CCPoint p0);
public:
    cocos2d::CCPoint m_point;
};
