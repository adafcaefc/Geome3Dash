#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "EffectGameObject.hpp"

class CheckpointGameObject : public EffectGameObject {
public:
    static constexpr auto CLASS_NAME = "CheckpointGameObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(CheckpointGameObject, EffectGameObject)
    
private:
    [[deprecated("CheckpointGameObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static CheckpointGameObject* create();
public:

    /**
     * @note[short] MacOS (ARM): 0x180db0
     * @note[short] MacOS (Intel): 0x1c36c0
     * @note[short] Windows: 0x4a1240
     * @note[short] iOS: 0x388610
     * @note[short] Android
     */
    virtual bool init();
    
private:
    [[deprecated("CheckpointGameObject::setupCustomSprites not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1811f0
     * @note[short] MacOS (Intel): 0x1c3b10
     * @note[short] iOS: 0x3889e4
     * @note[short] Android
     */
    virtual void setupCustomSprites(gd::string p0);
public:
    
private:
    [[deprecated("CheckpointGameObject::resetObject not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x18256c
     * @note[short] MacOS (Intel): 0x1c5120
     * @note[short] iOS: 0x389524
     * @note[short] Android
     */
    virtual void resetObject();
public:

    /**
     * @note[short] MacOS (ARM): 0x180e0c
     * @note[short] MacOS (Intel): 0x1c3720
     * @note[short] Windows: 0x4a12c0
     * @note[short] iOS: 0x38866c
     * @note[short] Android
     */
    virtual void triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2);
    
private:
    [[deprecated("CheckpointGameObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x182434
     * @note[short] MacOS (Intel): 0x1c4fe0
     * @note[short] iOS: 0x38941c
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:
    
private:
    [[deprecated("CheckpointGameObject::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x181b0c
     * @note[short] MacOS (Intel): 0x1c44f0
     * @note[short] iOS: 0x389178
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x180e24
     * @note[short] MacOS (Intel): 0x1c3740
     * @note[short] Windows: 0x4a12e0
     * @note[short] iOS: 0x388684
     * @note[short] Android
     */
    virtual void triggerActivated(float p0);
    
private:
    [[deprecated("CheckpointGameObject::restoreObject not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1825c4
     * @note[short] MacOS (Intel): 0x1c5190
     * @note[short] iOS: 0x389574
     * @note[short] Android
     */
    virtual void restoreObject();
public:
    
private:
    [[deprecated("CheckpointGameObject::updateSyncedAnimation not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x181770
     * @note[short] MacOS (Intel): 0x1c40f0
     * @note[short] iOS: 0x388de8
     * @note[short] Android
     */
    virtual void updateSyncedAnimation(float p0, int p1);
public:
    
private:
    [[deprecated("CheckpointGameObject::resetCheckpoint not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetCheckpoint();
public:
    
private:
    [[deprecated("CheckpointGameObject::updateCheckpointSpriteVisibility not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateCheckpointSpriteVisibility();
public:
};
