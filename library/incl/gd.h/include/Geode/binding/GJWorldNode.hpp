#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJWorldNode : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "GJWorldNode";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJWorldNode, cocos2d::CCNode)
    
private:
    [[deprecated("GJWorldNode::create not implemented")]]
    /**
     * @note[short] Android
     */
    static GJWorldNode* create(int p0, WorldSelectLayer* p1);
public:
    
private:
    [[deprecated("GJWorldNode::addDotsToLevel not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x33d2d0
     * @note[short] MacOS (Intel): 0x3b1940
     * @note[short] Android
     */
    TodoReturn addDotsToLevel(int p0, bool p1);
public:
    
private:
    [[deprecated("GJWorldNode::dotPositionForLevel not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn dotPositionForLevel(int p0, int p1);
public:
    
private:
    [[deprecated("GJWorldNode::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x33c8b8
     * @note[short] MacOS (Intel): 0x3b0e80
     * @note[short] Android
     */
    bool init(int p0, WorldSelectLayer* p1);
public:
    
private:
    [[deprecated("GJWorldNode::onLevel not implemented")]]
    /**
     * @note[short] Android
     */
    void onLevel(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJWorldNode::playStep1 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn playStep1();
public:
    
private:
    [[deprecated("GJWorldNode::playStep2 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn playStep2();
public:
    
private:
    [[deprecated("GJWorldNode::playStep3 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn playStep3();
public:
    
private:
    [[deprecated("GJWorldNode::positionForLevelButton not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn positionForLevelButton(int p0);
public:
    
private:
    [[deprecated("GJWorldNode::unlockActiveItem not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn unlockActiveItem();
public:
};
