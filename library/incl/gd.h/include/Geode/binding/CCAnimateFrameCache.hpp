#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class CCAnimateFrameCache : public cocos2d::CCObject {
public:
    static constexpr auto CLASS_NAME = "CCAnimateFrameCache";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(CCAnimateFrameCache, cocos2d::CCObject)

    /**
     * @note[short] Windows: 0x41450
     * @note[short] Android
     */
    static CCAnimateFrameCache* sharedSpriteFrameCache();
    
private:
    [[deprecated("CCAnimateFrameCache::addCustomSpriteFramesWithFile not implemented")]]
    /**
     * @note[short] Android
     */
    void addCustomSpriteFramesWithFile(char const* p0);
public:
    
private:
    [[deprecated("CCAnimateFrameCache::addDict not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn addDict(cocos2d::CCDictionary* p0, char const* p1);
public:
    
private:
    [[deprecated("CCAnimateFrameCache::addDict not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn addDict(DS_Dictionary* p0, char const* p1);
public:

    /**
     * @note[short] Windows: 0x414e0
     * @note[short] Android
     */
    void addSpriteFramesWithFile(char const* p0);
    
private:
    [[deprecated("CCAnimateFrameCache::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init();
public:
    
private:
    [[deprecated("CCAnimateFrameCache::purgeSharedSpriteFrameCache not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn purgeSharedSpriteFrameCache();
public:
    
private:
    [[deprecated("CCAnimateFrameCache::removeSpriteFrames not implemented")]]
    /**
     * @note[short] Android
     */
    void removeSpriteFrames();
public:
    
private:
    [[deprecated("CCAnimateFrameCache::spriteFrameByName not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn spriteFrameByName(char const* p0);
public:
};
