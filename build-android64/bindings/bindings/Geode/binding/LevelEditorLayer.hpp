#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "GJBaseGameLayer.hpp"
#include "LevelSettingsDelegate.hpp"

class LevelEditorLayer : public GJBaseGameLayer, public LevelSettingsDelegate {
public:
    static constexpr auto CLASS_NAME = "LevelEditorLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(LevelEditorLayer, GJBaseGameLayer)

    /**
     * @note[short] Windows: 0x2c86d0
     * @note[short] Android
     */
     LevelEditorLayer();

    /**
     * @note[short] MacOS (ARM): 0xc3090
     * @note[short] MacOS (Intel): 0xdb210
     * @note[short] Windows: 0x2c9650
     * @note[short] Android
     */
    static LevelEditorLayer* create(GJGameLevel* p0, bool p1);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    static LevelEditorLayer* get();

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static cocos2d::CCScene* scene(GJGameLevel* level, bool p1);

    /**
     * @note[short] MacOS (Intel): 0xe9cb0
     * @note[short] Windows: 0x2cef40
     * @note[short] Android
     */
    static void updateObjectLabel(GameObject* p0);

    /**
     * @note[short] MacOS (ARM): 0xd9514
     * @note[short] MacOS (Intel): 0xf52c0
     * @note[short] iOS: 0x365218
     * @note[short] Android
     */
    virtual void draw();

    /**
     * @note[short] MacOS (ARM): 0xd6df4
     * @note[short] MacOS (Intel): 0xf21a0
     * @note[short] Windows: 0x2d88d0
     * @note[short] iOS: 0x363080
     * @note[short] Android
     */
    virtual void postUpdate(float p0);

    /**
     * @note[short] MacOS (ARM): 0xd04e0
     * @note[short] MacOS (Intel): 0xeab50
     * @note[short] Windows: 0x2d0700
     * @note[short] iOS: 0x35e108
     * @note[short] Android
     */
    virtual void updateVisibility(float p0);

    /**
     * @note[short] MacOS (ARM): 0xd6de0
     * @note[short] MacOS (Intel): 0xf2180
     * @note[short] Windows: 0x2d88c0
     * @note[short] iOS: 0x36306c
     * @note[short] Android
     */
    virtual void playerTookDamage(PlayerObject* p0);

    /**
     * @note[short] MacOS (ARM): 0xd4138
     * @note[short] MacOS (Intel): 0xeef10
     * @note[short] Windows: 0x2d5080
     * @note[short] iOS: 0x3611bc
     * @note[short] Android
     */
    virtual void updateColor(cocos2d::ccColor3B& color, float fadeTime, int colorID, bool blending, float opacity, cocos2d::ccHSVValue& copyHSV, int colorIDToCopy, bool copyOpacity, EffectGameObject* callerObject, int unk1, int unk2);

    /**
     * @note[short] MacOS (ARM): 0xd7ec0
     * @note[short] MacOS (Intel): 0xf32d0
     * @note[short] Windows: 0x2d9510
     * @note[short] iOS: 0x363e2c
     * @note[short] Android
     */
    virtual void updateDebugDraw();

    /**
     * @note[short] MacOS (ARM): 0xd49bc
     * @note[short] MacOS (Intel): 0xef890
     * @note[short] Windows: 0x2d6070
     * @note[short] iOS: 0x36159c
     * @note[short] Android
     */
    virtual void addToGroup(GameObject* p0, int p1, bool p2);

    /**
     * @note[short] MacOS (ARM): 0xd4a74
     * @note[short] MacOS (Intel): 0xef940
     * @note[short] Windows: 0x2d61c0
     * @note[short] iOS: 0x361620
     * @note[short] Android
     */
    virtual void removeFromGroup(GameObject* p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0xd59e4
     * @note[short] MacOS (Intel): 0xf0b10
     * @note[short] Windows: 0x2d6f90
     * @note[short] iOS: 0x36221c
     * @note[short] Android
     */
    virtual void updateObjectSection(GameObject* p0);

    /**
     * @note[short] MacOS (ARM): 0xd5aec
     * @note[short] MacOS (Intel): 0xf0c50
     * @note[short] Windows: 0x2d7240
     * @note[short] iOS: 0x362318
     * @note[short] Android
     */
    virtual TodoReturn updateDisabledObjectsLastPos(cocos2d::CCArray* p0);

    /**
     * @note[short] MacOS (ARM): 0xd43f0
     * @note[short] MacOS (Intel): 0xef260
     * @note[short] Windows: 0x2d5f10
     * @note[short] iOS: 0x3613c0
     * @note[short] Android
     */
    virtual float timeForPos(cocos2d::CCPoint p0, int p1, int p2, bool p3, int p4);

    /**
     * @note[short] MacOS (ARM): 0xd447c
     * @note[short] MacOS (Intel): 0xef2f0
     * @note[short] Windows: 0x2d5f80
     * @note[short] iOS: 0x361430
     * @note[short] Android
     */
    virtual cocos2d::CCPoint posForTime(float p0);

    /**
     * @note[short] MacOS (ARM): 0xd44bc
     * @note[short] MacOS (Intel): 0xef390
     * @note[short] iOS: 0x361450
     * @note[short] Android
     */
    virtual void resetSPTriggered();

    /**
     * @note[short] MacOS (ARM): 0xd57e8
     * @note[short] MacOS (Intel): 0xf0910
     * @note[short] Windows: 0x2d6f20
     * @note[short] iOS: 0x362078
     * @note[short] Android
     */
    virtual TodoReturn didRotateGameplay();

    /**
     * @note[short] MacOS (ARM): 0xd0ff4
     * @note[short] MacOS (Intel): 0xeb6d0
     * @note[short] Windows: 0x2d1700
     * @note[short] iOS: 0x35ea4c
     * @note[short] Android
     */
    virtual TodoReturn manualUpdateObjectColors(GameObject* p0);

    /**
     * @note[short] MacOS (ARM): 0xd7c6c
     * @note[short] MacOS (Intel): 0xf3080
     * @note[short] Windows: 0x2d9060
     * @note[short] iOS: 0x363bf0
     * @note[short] Android
     */
    virtual TodoReturn claimCustomParticle(gd::string const& p0, cocos2d::ParticleStruct const& p1, int p2, int p3, int p4, bool p5);

    /**
     * @note[short] MacOS (ARM): 0xd7d4c
     * @note[short] MacOS (Intel): 0xf3140
     * @note[short] Windows: 0x2d9120
     * @note[short] iOS: 0x363cbc
     * @note[short] Android
     */
    virtual TodoReturn unclaimCustomParticle(gd::string const& p0, cocos2d::CCParticleSystemQuad* p1);

    /**
     * @note[short] MacOS (ARM): 0xd6d1c
     * @note[short] MacOS (Intel): 0xf20a0
     * @note[short] Windows: 0x2d87c0
     * @note[short] iOS: 0x362fa8
     * @note[short] Android
     */
    virtual TodoReturn activatedAudioTrigger(SFXTriggerGameObject* p0);

    /**
     * @note[short] MacOS (ARM): 0xd6d34
     * @note[short] MacOS (Intel): 0xf20d0
     * @note[short] Windows: 0x2d87f0
     * @note[short] iOS: 0x362fc0
     * @note[short] Android
     */
    virtual void checkpointActivated(CheckpointGameObject* p0);

    /**
     * @note[short] MacOS (ARM): 0xd7d8c
     * @note[short] MacOS (Intel): 0xf3180
     * @note[short] Windows: 0x2d9160
     * @note[short] iOS: 0x363cfc
     * @note[short] Android
     */
    virtual void addKeyframe(KeyframeGameObject* p0);

    /**
     * @note[short] MacOS (ARM): 0xc699c
     * @note[short] MacOS (Intel): 0xdf4f0
     * @note[short] Windows: 0x2cb030
     * @note[short] iOS: 0x358cb4
     * @note[short] Android
     */
    virtual void levelSettingsUpdated();

    /**
     * @note[short] Android
     */
    TodoReturn activateTriggerEffect(EffectGameObject* p0, float p1, float p2, float p3, bool p4);

    /**
     * @note[short] Android
     */
    TodoReturn addDelayedSpawn(EffectGameObject* p0, float p1);

    /**
     * @note[short] Android
     */
    TodoReturn addExclusionList(cocos2d::CCArray* p0, cocos2d::CCDictionary* p1);

    /**
     * @note[short] Android
     */
    TodoReturn addObjectFromVector(gd::vector<gd::string>& p0, gd::vector<void*>& p1);

    /**
     * @note[short] Android
     */
    TodoReturn addObjectsAtPosition(cocos2d::CCPoint p0, cocos2d::CCArray* p1, cocos2d::CCArray* p2);

    /**
     * @note[short] Android
     */
    TodoReturn addObjectsInRect(cocos2d::CCRect p0, bool p1, cocos2d::CCArray* p2, cocos2d::CCArray* p3);

    /**
     * @note[short] Android
     */
    TodoReturn addObjectToGroup(GameObject* p0, int p1);

    /**
     * @note[short] Android
     */
    TodoReturn addPlayer2Point(cocos2d::CCPoint p0, bool p1);

    /**
     * @note[short] Android
     */
    TodoReturn addPlayerCollisionBlock();

    /**
     * @note[short] Android
     */
    TodoReturn addPlayerPoint(cocos2d::CCPoint p0);

    /**
     * @note[short] MacOS (ARM): 0xc7674
     * @note[short] Windows: 0x2cf4a0
     * @note[short] Android
     */
    void addSpecial(GameObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn addToRedoList(UndoObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn addTouchPoint(cocos2d::CCPoint p0);

    /**
     * @note[short] MacOS (Intel): 0xe0210
     * @note[short] Android
     */
    TodoReturn addToUndoList(UndoObject* p0, bool p1);

    /**
     * @note[short] Android
     */
    TodoReturn applyAttributeState(GameObject* p0, GameObject* p1);

    /**
     * @note[short] Android
     */
    TodoReturn applyGroupState(GameObject* p0, GameObject* p1);

    /**
     * @note[short] Android
     */
    TodoReturn breakApartTextObject(TextGameObject* p0);

    /**
     * @note[short] Android
     */
    bool canPasteState();

    /**
     * @note[short] Android
     */
    TodoReturn clearPlayerPoints();

    /**
     * @note[short] Android
     */
    TodoReturn clearTouchPoints();

    /**
     * @note[short] Android
     */
    TodoReturn copyObjectState(GameObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn copyParticleState(ParticleGameObject* p0);

    /**
     * @note[short] Windows: 0x2cbf90
     * @note[short] Android
     */
    GameObject* createObject(int p0, cocos2d::CCPoint p1, bool p2);

    /**
     * @note[short] Android
     */
    void createObjectsFromSetup(gd::string& p0);

    /**
     * @note[short] MacOS (ARM): 0xc6e60
     * @note[short] MacOS (Intel): 0xdf9e0
     * @note[short] Windows: 0x2cb920
     * @note[short] Android
     */
    cocos2d::CCArray* createObjectsFromString(gd::string const& p0, bool p1, bool p2);

    /**
     * @note[short] Android
     */
    TodoReturn dirtifyTriggers();

    /**
     * @note[short] Android
     */
    TodoReturn duplicateKeyframeAnimation(int p0);

    /**
     * @note[short] Android
     */
    TodoReturn fastUpdateDisabledGroups();

    /**
     * @note[short] Android
     */
    int findGameObject(int p0);

    /**
     * @note[short] Android
     */
    TodoReturn findStartPosObject();

    /**
     * @note[short] Android
     */
    TodoReturn forceShowSelectedObjects(bool p0);

    /**
     * @note[short] Android
     */
    TodoReturn fullUpdateDisabledGroups();

    /**
     * @note[short] Android
     */
    TodoReturn getAllObjects();

    /**
     * @note[short] Android
     */
    TodoReturn getDelayedSpawnNode();

    /**
     * @note[short] Android
     */
    TodoReturn getGridPos(cocos2d::CCPoint p0);

    /**
     * @note[short] MacOS (Intel): 0xed530
     * @note[short] Android
     */
    TodoReturn getLastObjectX();

    /**
     * @note[short] MacOS (Intel): 0xe3a60
     * @note[short] Windows: 0x2ce530
     * @note[short] Android
     */
    gd::string getLevelString();

    /**
     * @note[short] Android
     */
    TodoReturn getLockedLayers();

    /**
     * @note[short] Android
     */
    TodoReturn getNextColorChannel();

    /**
     * @note[short] Windows: 0x2d26d0
     * @note[short] Android
     */
    int getNextFreeAreaEffectID(cocos2d::CCArray* p0);

    /**
     * @note[short] Android
     */
    TodoReturn getNextFreeBlockID(cocos2d::CCArray* p0);

    /**
     * @note[short] Android
     */
    int getNextFreeEditorLayer(cocos2d::CCArray* p0);

    /**
     * @note[short] Android
     */
    TodoReturn getNextFreeEnterChannel(cocos2d::CCArray* p0);

    /**
     * @note[short] Windows: 0x2d27b0
     * @note[short] Android
     */
    int getNextFreeGradientID(cocos2d::CCArray* p0);

    /**
     * @note[short] MacOS (ARM): 0xd1514
     * @note[short] MacOS (Intel): 0xebbf0
     * @note[short] Windows: 0x2d2030
     * @note[short] Android
     */
    int getNextFreeGroupID(cocos2d::CCArray* p0);

    /**
     * @note[short] Windows: 0x2d22b0
     * @note[short] Android
     */
    int getNextFreeItemID(cocos2d::CCArray* p0);

    /**
     * @note[short] Android
     */
    TodoReturn getNextFreeOrderChannel(cocos2d::CCArray* p0);

    /**
     * @note[short] Android
     */
    TodoReturn getNextFreeSFXGroupID(cocos2d::CCArray* p0);

    /**
     * @note[short] Android
     */
    TodoReturn getNextFreeSFXID(cocos2d::CCArray* p0);

    /**
     * @note[short] Windows: 0x2cd0f0
     * @note[short] Android
     */
    TodoReturn getObjectRect(GameObject* p0, bool p1, bool p2);

    /**
     * @note[short] Android
     */
    TodoReturn getRelativeOffset(GameObject* p0);

    /**
     * @note[short] MacOS (Intel): 0xe9750
     * @note[short] Android
     */
    TodoReturn getSavedEditorPosition(int p0);

    /**
     * @note[short] MacOS (Intel): 0xe9790
     * @note[short] Android
     */
    TodoReturn getSavedEditorPositions();

    /**
     * @note[short] MacOS (Intel): 0xe9bb0
     * @note[short] Android
     */
    TodoReturn getSectionCount();

    /**
     * @note[short] Android
     */
    TodoReturn getSelectedEditorOrder();

    /**
     * @note[short] Android
     */
    TodoReturn getSelectedEffectPos();

    /**
     * @note[short] Android
     */
    TodoReturn getSelectedOrderChannel();

    /**
     * @note[short] Android
     */
    TodoReturn getSFXIDs();

    /**
     * @note[short] Android
     */
    TodoReturn getSongIDs(bool& p0);

    /**
     * @note[short] Android
     */
    TodoReturn getTriggerGroup(int p0);

    /**
     * @note[short] MacOS (ARM): 0xca1b0
     * @note[short] MacOS (Intel): 0xe3140
     * @note[short] Windows: 0x2cde30
     * @note[short] Android
     */
    void handleAction(bool p0, cocos2d::CCArray* p1);

    /**
     * @note[short] Android
     */
    bool hasAction(bool p0);

    /**
     * @note[short] MacOS (ARM): 0xc3124
     * @note[short] MacOS (Intel): 0xdb280
     * @note[short] Windows: 0x2c96e0
     * @note[short] Android
     */
    bool init(GJGameLevel* p0, bool p1);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    bool isLayerLocked(int layer);

    /**
     * @note[short] Windows: 0x2cc940
     * @note[short] Android
     */
    GameObject* objectAtPosition(cocos2d::CCPoint p0);

    /**
     * @note[short] MacOS (Intel): 0xea300
     * @note[short] Android
     */
    TodoReturn objectMoved(GameObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn objectsAtPosition(cocos2d::CCPoint p0);

    /**
     * @note[short] Android
     */
    cocos2d::CCArray* objectsInRect(cocos2d::CCRect p0, bool p1);

    /**
     * @note[short] Android
     */
    void onPausePlaytest();

    /**
     * @note[short] MacOS (ARM): 0xd5d40
     * @note[short] MacOS (Intel): 0xf0f00
     * @note[short] Windows: 0x2d7330
     * @note[short] Android
     */
    void onPlaytest();

    /**
     * @note[short] Windows: 0x2d7d60
     * @note[short] Android
     */
    void onResumePlaytest();

    /**
     * @note[short] MacOS (ARM): 0xd67f8
     * @note[short] MacOS (Intel): 0xf1ae0
     * @note[short] Windows: 0x2d7f50
     * @note[short] Android
     */
    void onStopPlaytest();

    /**
     * @note[short] Android
     */
    TodoReturn pasteAttributeState(GameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] Android
     */
    TodoReturn pasteColorState(GameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] Android
     */
    TodoReturn pasteGroupState(GameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] Android
     */
    TodoReturn pasteParticleState(ParticleGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] MacOS (ARM): 0xa7448
     * @note[short] MacOS (Intel): 0xb7920
     * @note[short] Android
     */
    void processLoadedMoveActions();

    /**
     * @note[short] Windows: 0x2d70c0
     * @note[short] Android
     */
    TodoReturn quickUpdateAllPositions();

    /**
     * @note[short] MacOS (Intel): 0xef9c0
     * @note[short] Android
     */
    TodoReturn recreateGroups();

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void redoLastAction();

    /**
     * @note[short] Android
     */
    TodoReturn refreshSpecial(GameObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn removeAllObjects();

    /**
     * @note[short] Windows: 0x2cdbb0
     * @note[short] Android
     */
    TodoReturn removeAllObjectsOfType(int p0);

    /**
     * @note[short] MacOS (ARM): 0xc98e4
     * @note[short] MacOS (Intel): 0xe27e0
     * @note[short] Android
     */
    TodoReturn removeObject(GameObject* p0, bool p1);

    /**
     * @note[short] MacOS (ARM): 0x62950c
     * @note[short] Android
     */
    TodoReturn removePlayerCollisionBlock();

    /**
     * @note[short] MacOS (ARM): 0xc99a4
     * @note[short] MacOS (Intel): 0xe28a0
     * @note[short] Windows: 0x2cfbb0
     * @note[short] Android
     */
    void removeSpecial(GameObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn resetDelayedSpawnNodes();

    /**
     * @note[short] Android
     */
    TodoReturn resetEffectTriggerOptim(GameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] Android
     */
    void resetMovingObjects();

    /**
     * @note[short] Android
     */
    void resetObjectVector();

    /**
     * @note[short] Android
     */
    TodoReturn resetPlayback();

    /**
     * @note[short] Android
     */
    TodoReturn resetToggledGroups();

    /**
     * @note[short] Android
     */
    TodoReturn resetToggledGroupsAndObjects();

    /**
     * @note[short] Android
     */
    TodoReturn resetUnusedColorChannels();

    /**
     * @note[short] Android
     */
    TodoReturn reverseKeyframeAnimationOrder(int p0);

    /**
     * @note[short] Android
     */
    TodoReturn reverseObjectChanged(EffectGameObject* p0);

    /**
     * @note[short] MacOS (Intel): 0xe1170
     * @note[short] Android
     */
    TodoReturn rotationForSlopeNearObject(GameObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn runColorEffect(EffectGameObject* p0, int p1, float p2, float p3, bool p4);

    /**
     * @note[short] MacOS (Intel): 0xe9730
     * @note[short] Android
     */
    TodoReturn saveEditorPosition(cocos2d::CCPoint& p0, int p1);

    /**
     * @note[short] Android
     */
    void setObjectCount(int p0);

    /**
     * @note[short] Android
     */
    TodoReturn shouldBlend(int p0);

    /**
     * @note[short] Android
     */
    TodoReturn sortBatchnodeChildren(float p0);

    /**
     * @note[short] Android
     */
    TodoReturn spawnGroupPreview(int p0, float p1, float p2, float p3, float p4, float p5, bool p6, bool p7);

    /**
     * @note[short] Android
     */
    TodoReturn stopPlayback();

    /**
     * @note[short] Android
     */
    TodoReturn stopTriggersInGroup(int p0, float p1);

    /**
     * @note[short] Android
     */
    TodoReturn timeObjectChanged();

    /**
     * @note[short] Android
     */
    TodoReturn toggleBackground(bool p0);

    /**
     * @note[short] Android
     */
    TodoReturn toggleGrid(bool p0);

    /**
     * @note[short] MacOS (Intel): 0xdf280
     * @note[short] Android
     */
    TodoReturn toggleGround(bool p0);

    /**
     * @note[short] Android
     */
    TodoReturn toggleGroupPreview(int p0, bool p1);

    /**
     * @note[short] Android
     */
    TodoReturn toggleLockActiveLayer();

    /**
     * @note[short] MacOS (Intel): 0xed150
     * @note[short] Android
     */
    TodoReturn transferDefaultColors(GJEffectManager* p0, GJEffectManager* p1);

    /**
     * @note[short] Android
     */
    TodoReturn triggerFollowCommand(EffectGameObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn triggerPlayerFollowCommand(EffectGameObject* p0);

    /**
     * @note[short] Android
     */
    TodoReturn triggerRotateCommand(EffectGameObject* p0);

    /**
     * @note[short] MacOS (Intel): 0xea170
     * @note[short] Windows: 0x2d0190
     * @note[short] Android
     */
    bool tryUpdateSpeedObject(EffectGameObject* p0, bool p1);

    /**
     * @note[short] Windows: 0x2cc340
     * @note[short] Android
     */
    bool typeExistsAtPosition(int p0, cocos2d::CCPoint p1, bool p2, bool p3, float p4);

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void undoLastAction();

    /**
     * @note[short] MacOS (Intel): 0xe9c60
     * @note[short] Android
     */
    TodoReturn unlockAllLayers();

    /**
     * @note[short] Android
     */
    TodoReturn updateAnimateOnTriggerObjects(bool p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateArt(float p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateBlendValues();

    /**
     * @note[short] MacOS (ARM): 0xc53b8
     * @note[short] MacOS (Intel): 0xddb40
     * @note[short] Windows: 0x2d0330
     * @note[short] Android
     */
    void updateEditor(float p0);

    /**
     * @note[short] MacOS (ARM): 0xc6370
     * @note[short] MacOS (Intel): 0xdeeb0
     * @note[short] Windows: 0x2d2e10
     * @note[short] Android
     */
    void updateEditorMode();

    /**
     * @note[short] MacOS (ARM): 0xc57c0
     * @note[short] MacOS (Intel): 0xddf40
     * @note[short] Android
     */
    void updateGameObjects();

    /**
     * @note[short] Android
     */
    TodoReturn updateGridLayer();

    /**
     * @note[short] Android
     */
    TodoReturn updateGridLayerParent();

    /**
     * @note[short] MacOS (Intel): 0xeb650
     * @note[short] Windows: 0x2d9490
     * @note[short] Android
     */
    TodoReturn updateKeyframeObjects();

    /**
     * @note[short] Android
     */
    TodoReturn updateKeyframeVisibility(bool p0);

    /**
     * @note[short] Windows: 0x2d66d0
     * @note[short] Android
     */
    void updateLevelFont(int p0);

    /**
     * @note[short] MacOS (ARM): 0xd102c
     * @note[short] MacOS (Intel): 0xeb700
     * @note[short] Windows: 0x2d1790
     * @note[short] Android
     */
    void updateObjectColors(cocos2d::CCArray* gameObjects);

    /**
     * @note[short] MacOS (ARM): 0xc4394
     * @note[short] MacOS (Intel): 0xdc880
     * @note[short] Windows: 0x2ca8f0
     * @note[short] Android
     */
    void updateOptions();

    /**
     * @note[short] Android
     */
    void updatePreviewAnim();

    /**
     * @note[short] MacOS (ARM): 0x1642bc
     * @note[short] MacOS (Intel): 0x1a1820
     * @note[short] Android
     */
    void updatePreviewParticle(ParticleGameObject* p0);

    /**
     * @note[short] MacOS (Intel): 0xecfe0
     * @note[short] Windows: 0x2d8ec0
     * @note[short] Android
     */
    void updatePreviewParticles();

    /**
     * @note[short] Android
     */
    TodoReturn updateToggledGroups();

    /**
     * @note[short] Android
     */
    TodoReturn validGroup(GameObject* p0, bool p1);
    bool m_drawTriggerBoxes;
    bool m_showGrid;
    bool m_hideGridOnPlay;
    bool m_drawEffectLines;
    bool m_showGround;
    bool m_showDurationLines;
    bool m_increaseMaxUndoRedo;
    bool m_hideBackground;
    bool m_gv0120;
    bool m_layerLockingEnabled;
    bool m_unkBool4;
    bool m_previewParticles;
    bool m_previewAnimations;
    bool m_previewShaders;
    bool m_hideParticleIcons;
    bool m_unkBool5;
    bool m_playTestSmoothFix;
    GEODE_PAD(15);
    cocos2d::CCArray* m_unkArr0;
    cocos2d::CCArray* m_unkArr1;
    cocos2d::CCArray* m_unkArr2;
    cocos2d::CCArray* m_unkArr3;
    cocos2d::CCArray* m_unkArr4;
    cocos2d::CCArray* m_unkArr8;
    cocos2d::CCArray* m_unkArr11;
    cocos2d::CCArray* m_unkArr12;
    cocos2d::CCArray* m_unkArr13;
    cocos2d::CCDictionary* m_unkDict3;
    cocos2d::CCArray* m_unkArr5;
    GEODE_PAD(16);
    cocos2d::CCDictionary* m_unkDict4;
    cocos2d::CCArray* m_unkArr7;
    bool m_unkBool3;
    bool m_unkBool2;
    geode::SeedValueRSV m_coinCount;
    GEODE_PAD(8);
    cocos2d::CCArray* m_unkArr6;
    GEODE_PAD(8);
    cocos2d::CCDictionary* m_unkDict1;
    cocos2d::CCDictionary* m_unkDict2;
    bool m_unkBool0;
    bool m_unkBool1;
    short m_currentLayer;
    GEODE_PAD(28);
    float m_trailTimer;
    GEODE_PAD(4);
    EditorUI* m_editorUI;
    cocos2d::CCArray* m_undoObjects;
    cocos2d::CCArray* m_redoObjects;
    geode::SeedValueRSV m_objectCount;
    DrawGridLayer* m_drawGridLayer;
    bool m_unkBool;
    bool m_previewMode;
    GEODE_PAD(244);
    gd::vector<bool> m_lockedLayers;
    GEODE_PAD(248);
};
