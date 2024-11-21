#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJActionManager : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "GJActionManager";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJActionManager, cocos2d::CCNode)
    
private:
    [[deprecated("GJActionManager::create not implemented")]]
    /**
     * @note[short] Android
     */
    static GJActionManager* create();
public:
    
private:
    [[deprecated("GJActionManager::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x521a8c
     * @note[short] MacOS (Intel): 0x5f1e50
     * @note[short] iOS: 0x2fe634
     * @note[short] Android
     */
    virtual bool init();
public:
    
private:
    [[deprecated("GJActionManager::getInternalAction not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getInternalAction(int p0);
public:
    
private:
    [[deprecated("GJActionManager::runInternalAction not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x5f1e80
     * @note[short] Android
     */
    TodoReturn runInternalAction(cocos2d::CCAction* p0, cocos2d::CCNode* p1);
public:
    
private:
    [[deprecated("GJActionManager::stopAllInternalActions not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn stopAllInternalActions();
public:
    
private:
    [[deprecated("GJActionManager::stopInternalAction not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x5f1ed0
     * @note[short] Android
     */
    TodoReturn stopInternalAction(int p0);
public:
    
private:
    [[deprecated("GJActionManager::updateInternalActions not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateInternalActions(float p0, bool p1);
public:
};
