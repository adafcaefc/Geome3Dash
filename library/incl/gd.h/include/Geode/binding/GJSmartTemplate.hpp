#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJSmartTemplate : public cocos2d::CCObject {
public:
    static constexpr auto CLASS_NAME = "GJSmartTemplate";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJSmartTemplate, cocos2d::CCObject)

    /**
     * @note[short] Windows: 0x2a92e0
     * @note[short] Android
     */
    static GJSmartTemplate* create();

    /**
     * @note[short] MacOS (ARM): 0x3912e8
     * @note[short] MacOS (Intel): 0x415960
     * @note[short] Windows: 0x2ae150
     * @note[short] iOS: 0xc430
     * @note[short] Android
     */
    virtual void encodeWithCoder(DS_Dictionary* p0);
    
private:
    [[deprecated("GJSmartTemplate::canEncode not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x390f40
     * @note[short] MacOS (Intel): 0x415580
     * @note[short] iOS: 0xc1c4
     * @note[short] Android
     */
    virtual bool canEncode();
public:
    
private:
    [[deprecated("GJSmartTemplate::applyTransformationsForType not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn applyTransformationsForType(SmartBlockType p0, cocos2d::CCSprite* p1);
public:
    
private:
    [[deprecated("GJSmartTemplate::createWithCoder not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x390f48
     * @note[short] MacOS (Intel): 0x415590
     * @note[short] Android
     */
    TodoReturn createWithCoder(DS_Dictionary* p0);
public:

    /**
     * @note[short] Windows: 0x2ade80
     * @note[short] Android
     */
    void dataLoaded(DS_Dictionary* p0);
    
private:
    [[deprecated("GJSmartTemplate::flipBlockType not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn flipBlockType(SmartBlockType p0, bool p1, bool p2);
public:
    
private:
    [[deprecated("GJSmartTemplate::flipBlockTypeX not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn flipBlockTypeX(SmartBlockType p0);
public:
    
private:
    [[deprecated("GJSmartTemplate::flipBlockTypeY not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn flipBlockTypeY(SmartBlockType p0);
public:
    
private:
    [[deprecated("GJSmartTemplate::flipKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn flipKey(gd::string p0, bool p1, bool p2);
public:
    
private:
    [[deprecated("GJSmartTemplate::generateRemapDict not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn generateRemapDict();
public:
    
private:
    [[deprecated("GJSmartTemplate::getNoCornerKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getNoCornerKey(gd::string p0);
public:
    
private:
    [[deprecated("GJSmartTemplate::getPrefab not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getPrefab(cocos2d::CCPoint p0, SmartGameObject* p1, SmartGameObject* p2, SmartGameObject* p3, SmartGameObject* p4, SmartGameObject* p5, SmartGameObject* p6, SmartGameObject* p7, SmartGameObject* p8, SmartGameObject* p9);
public:
    
private:
    [[deprecated("GJSmartTemplate::getPrefab not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getPrefab(gd::string p0, bool p1, bool p2);
public:
    
private:
    [[deprecated("GJSmartTemplate::getPrefabs not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getPrefabs(gd::string p0);
public:
    
private:
    [[deprecated("GJSmartTemplate::getPrefabWithID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getPrefabWithID(gd::string p0, int p1);
public:
    
private:
    [[deprecated("GJSmartTemplate::getRandomPrefab not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getRandomPrefab(gd::string p0);
public:
    
private:
    [[deprecated("GJSmartTemplate::getSimplifiedKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getSimplifiedKey(gd::string p0);
public:
    
private:
    [[deprecated("GJSmartTemplate::getSimplifiedType not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getSimplifiedType(SmartBlockType p0, bool& p1);
public:
    
private:
    [[deprecated("GJSmartTemplate::getTemplateState not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getTemplateState(gd::vector<SmartPrefabResult>& p0);
public:
    
private:
    [[deprecated("GJSmartTemplate::getTotalChanceForPrefab not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getTotalChanceForPrefab(gd::string p0);
public:
    
private:
    [[deprecated("GJSmartTemplate::getVerySimplifiedKey not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x411170
     * @note[short] Android
     */
    TodoReturn getVerySimplifiedKey(gd::string p0);
public:
    
private:
    [[deprecated("GJSmartTemplate::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init();
public:
    
private:
    [[deprecated("GJSmartTemplate::isUnrequired not implemented")]]
    /**
     * @note[short] Android
     */
    bool isUnrequired(gd::string p0);
public:
    
private:
    [[deprecated("GJSmartTemplate::keyFromNeighbors not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn keyFromNeighbors(cocos2d::CCPoint p0, SmartGameObject* p1, SmartGameObject* p2, SmartGameObject* p3, SmartGameObject* p4, SmartGameObject* p5, SmartGameObject* p6, SmartGameObject* p7, SmartGameObject* p8, SmartGameObject* p9);
public:
    
private:
    [[deprecated("GJSmartTemplate::keyFromNeighbors not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn keyFromNeighbors(SmartBlockType p0, SmartBlockType p1, SmartBlockType p2, SmartBlockType p3, SmartBlockType p4, SmartBlockType p5, SmartBlockType p6, SmartBlockType p7, SmartBlockType p8);
public:
    
private:
    [[deprecated("GJSmartTemplate::keyFromNeighborsOld not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn keyFromNeighborsOld(bool p0, bool p1, bool p2, bool p3, bool p4, bool p5, bool p6, bool p7);
public:
    
private:
    [[deprecated("GJSmartTemplate::logTemplateStatus not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x390450
     * @note[short] MacOS (Intel): 0x4148f0
     * @note[short] Android
     */
    TodoReturn logTemplateStatus(bool p0);
public:
    
private:
    [[deprecated("GJSmartTemplate::offsetForDir not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn offsetForDir(GJSmartDirection p0, int p1);
public:
    
private:
    [[deprecated("GJSmartTemplate::offsetForObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn offsetForObject(SmartGameObject* p0);
public:
    
private:
    [[deprecated("GJSmartTemplate::offsetForType not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn offsetForType(SmartBlockType p0);
public:
    
private:
    [[deprecated("GJSmartTemplate::removePrefab not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn removePrefab(gd::string p0, int p1);
public:
    
private:
    [[deprecated("GJSmartTemplate::resetScannedPrefabs not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetScannedPrefabs();
public:
    
private:
    [[deprecated("GJSmartTemplate::rotateBlockType not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn rotateBlockType(SmartBlockType p0, int p1);
public:
    
private:
    [[deprecated("GJSmartTemplate::rotateBlockType90 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn rotateBlockType90(SmartBlockType p0);
public:
    
private:
    [[deprecated("GJSmartTemplate::rotateKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn rotateKey(gd::string p0, int p1);
public:
    
private:
    [[deprecated("GJSmartTemplate::savePrefab not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn savePrefab(gd::string p0, gd::string p1);
public:
    
private:
    [[deprecated("GJSmartTemplate::saveRemap not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn saveRemap(gd::string p0);
public:
    
private:
    [[deprecated("GJSmartTemplate::saveRemapToDict not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x410e20
     * @note[short] Android
     */
    TodoReturn saveRemapToDict(gd::string p0, gd::string p1, cocos2d::CCDictionary* p2);
public:
    
private:
    [[deprecated("GJSmartTemplate::scanForPrefab not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn scanForPrefab(gd::string p0);
public:
    
private:
    [[deprecated("GJSmartTemplate::shouldDiscardObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn shouldDiscardObject(SmartBlockType p0, GJSmartDirection p1);
public:
    
private:
    [[deprecated("GJSmartTemplate::smartObjectToType not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn smartObjectToType(SmartGameObject* p0, cocos2d::CCPoint p1);
public:
    
private:
    [[deprecated("GJSmartTemplate::smartTypeToObjectKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn smartTypeToObjectKey(SmartBlockType p0);
public:
};
