#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class InheritanceNode : public cocos2d::CCObject {
public:
    static constexpr auto CLASS_NAME = "InheritanceNode";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(InheritanceNode, cocos2d::CCObject)
    
private:
    [[deprecated("InheritanceNode::create not implemented")]]
    /**
     * @note[short] Android
     */
    static InheritanceNode* create(int p0, InheritanceNode* p1);
public:
    
private:
    [[deprecated("InheritanceNode::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(int p0, InheritanceNode* p1);
public:
};
