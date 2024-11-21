#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class ObjectToolbox : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "ObjectToolbox";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(ObjectToolbox, cocos2d::CCNode)

    /**
     * @note[short] MacOS (ARM): 0x57b4a8
     * @note[short] MacOS (Intel): 0x654080
     * @note[short] Windows: 0x332f90
     * @note[short] Android
     */
    static ObjectToolbox* sharedState();

    /**
     * @note[short] MacOS (ARM): 0x57b5d0
     * @note[short] MacOS (Intel): 0x6541c0
     * @note[short] Windows: 0x333050
     * @note[short] iOS: 0x276cbc
     * @note[short] Android
     */
    virtual bool init();
    
private:
    [[deprecated("ObjectToolbox::allKeys not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn allKeys();
public:

    /**
     * @note[short] MacOS (ARM): 0x6282d0
     * @note[short] MacOS (Intel): 0x704100
     * @note[short] Windows: 0x35ae80
     * @note[short] Android
     */
    float gridNodeSizeForKey(int key);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    const char* intKeyToFrame(int key);
    
private:
    [[deprecated("ObjectToolbox::perspectiveBlockFrame not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn perspectiveBlockFrame(int p0);
public:
    gd::map<int, gd::string> m_allKeys;
};
