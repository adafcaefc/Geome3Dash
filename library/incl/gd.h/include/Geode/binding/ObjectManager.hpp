#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class ObjectManager : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "ObjectManager";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(ObjectManager, cocos2d::CCNode)

    /**
     * @note[short] Windows: 0x6e3d0
     * @note[short] Android
     */
    static ObjectManager* instance();

    /**
     * @note[short] MacOS (ARM): 0x69410c
     * @note[short] MacOS (Intel): 0x77f750
     * @note[short] Windows: 0x6e460
     * @note[short] iOS: 0x24c270
     * @note[short] Android
     */
    virtual bool init();
    
private:
    [[deprecated("ObjectManager::animLoaded not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCObject* animLoaded(char const* anim);
public:
    
private:
    [[deprecated("ObjectManager::getDefinition not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCObject* getDefinition(char const* definitionKey);
public:
    
private:
    [[deprecated("ObjectManager::getGlobalAnimCopy not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCObject* getGlobalAnimCopy(char const* anim);
public:

    /**
     * @note[short] Windows: 0x6e800
     * @note[short] Android
     */
    void loadCopiedAnimations();
    
private:
    [[deprecated("ObjectManager::loadCopiedSets not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x6945cc
     * @note[short] Android
     */
    void loadCopiedSets();
public:
    
private:
    [[deprecated("ObjectManager::purgeObjectManager not implemented")]]
    /**
     * @note[short] Android
     */
    void purgeObjectManager();
public:
    
private:
    [[deprecated("ObjectManager::replaceAllOccurencesOfString not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCDictionary* replaceAllOccurencesOfString(cocos2d::CCString* p0, cocos2d::CCString* p1, cocos2d::CCDictionary* p2);
public:
    
private:
    [[deprecated("ObjectManager::setLoaded not implemented")]]
    /**
     * @note[short] Android
     */
    void setLoaded(char const* objectName);
public:

    /**
     * @note[short] Windows: 0x6e4c0
     * @note[short] Android
     */
    void setup();
    cocos2d::CCDictionary* m_objectDefinitions;
    cocos2d::CCDictionary* m_maybeLoadedAnimations;
};
