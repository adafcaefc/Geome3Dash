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

    /**
     * @note[short] Android
     */
    cocos2d::CCObject* animLoaded(char const* anim);

    /**
     * @note[short] Android
     */
    cocos2d::CCObject* getDefinition(char const* definitionKey);

    /**
     * @note[short] Android
     */
    cocos2d::CCObject* getGlobalAnimCopy(char const* anim);

    /**
     * @note[short] Windows: 0x6e800
     * @note[short] Android
     */
    void loadCopiedAnimations();

    /**
     * @note[short] MacOS (ARM): 0x6945cc
     * @note[short] Android
     */
    void loadCopiedSets();

    /**
     * @note[short] Android
     */
    void purgeObjectManager();

    /**
     * @note[short] Android
     */
    cocos2d::CCDictionary* replaceAllOccurencesOfString(cocos2d::CCString* p0, cocos2d::CCString* p1, cocos2d::CCDictionary* p2);

    /**
     * @note[short] Android
     */
    void setLoaded(char const* objectName);

    /**
     * @note[short] Windows: 0x6e4c0
     * @note[short] Android
     */
    void setup();
    cocos2d::CCDictionary* m_objectDefinitions;
    cocos2d::CCDictionary* m_maybeLoadedAnimations;
};
