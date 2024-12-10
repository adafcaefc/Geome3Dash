#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "GJGameState.hpp"
#include "GJShaderState.hpp"
#include "FMODAudioState.hpp"
#include "EffectManagerState.hpp"

class CheckpointObject : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "CheckpointObject";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(CheckpointObject, cocos2d::CCNode)

    /**
     * @note[short] MacOS (Intel): 0xcaa60
     * @note[short] Windows: 0x38e330
     * @note[short] Android
     */
     CheckpointObject();

    /**
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static CheckpointObject* create();

    /**
     * @note[short] MacOS (ARM): 0xae344
     * @note[short] MacOS (Intel): 0xbfa20
     * @note[short] Windows: 0x77db0
     * @note[short] iOS: 0x126110
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] Android
     */
    TodoReturn getObject();

    /**
     * @note[short] Android
     */
    void setObject(GameObject* p0);
    GJGameState m_gameState;
    GJShaderState m_shaderState;
    FMODAudioState m_audioState;
    GameObject* m_physicalCheckpointObject;
    PlayerCheckpoint* m_player1Checkpoint;
    PlayerCheckpoint* m_player2Checkpoint;
    void* m_maybeAPointer1;
    int m_unkInt1;
    short m_unkShort1;
private:
    void* m_maybeAPointer2;
public:
private:
    gd::vector<DynamicSaveObject> m_vectorDynamicSaveObjects;
public:
private:
    gd::vector<ActiveSaveObject1> m_vectorActiveSaveObjects1;
public:
private:
    gd::vector<ActiveSaveObject2> m_vectorActiveSaveObjects2;
public:
private:
    EffectManagerState m_effectManagerState;
public:
private:
    cocos2d::CCArray* m_gradientTriggerObjectArray;
public:
private:
    bool m_unkBool1;
public:
private:
    gd::unordered_map<int,SequenceTriggerState> m_sequenceTriggerStateUnorderedMap;
public:
private:
    void* m_maybeAPointer3;
public:
};
