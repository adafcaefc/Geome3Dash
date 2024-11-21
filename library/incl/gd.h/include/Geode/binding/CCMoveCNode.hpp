#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class CCMoveCNode : public cocos2d::CCObject {
public:
    static constexpr auto CLASS_NAME = "CCMoveCNode";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(CCMoveCNode, cocos2d::CCObject)
    
private:
    [[deprecated("CCMoveCNode::create not implemented")]]
    /**
     * @note[short] Android
     */
    static CCMoveCNode* create();
public:
    
private:
    [[deprecated("CCMoveCNode::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init();
public:
    
private:
    [[deprecated("CCMoveCNode::reset not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn reset();
public:
};
