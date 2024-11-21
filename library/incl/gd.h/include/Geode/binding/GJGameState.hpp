#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "EventTriggerInstance.hpp"
#include "SongChannelState.hpp"
#include "DynamicObjectAction.hpp"
#include "AdvancedFollowInstance.hpp"
#include "EnterEffectInstance.hpp"
#include "GameObjectPhysics.hpp"
#include "GJValueTween.hpp"
#include "SFXTriggerInstance.hpp"
#include "SFXTriggerState.hpp"
#include "SongTriggerState.hpp"
#include "EnterEffectAnimValue.hpp"

class GJGameState {
public:
    static constexpr auto CLASS_NAME = "GJGameState";
    
private:
    [[deprecated("GJGameState::controlTweenAction not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn controlTweenAction(int p0, int p1, GJActionCommand p2);
public:
    
private:
    [[deprecated("GJGameState::getGameObjectPhysics not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getGameObjectPhysics(GameObject* p0);
public:

    /**
     * @note[short] Windows: 0x200290
     * @note[short] Android
     */
    TodoReturn processStateTriggers();

    /**
     * @note[short] MacOS (ARM): 0x4d160
     * @note[short] Windows: 0x2444e0
     * @note[short] Android
     */
    void stopTweenAction(int p0);

    /**
     * @note[short] Windows: 0x200140
     * @note[short] Android
     */
    TodoReturn tweenValue(float p0, float p1, int p2, float p3, int p4, float p5, int p6, int p7);
    
private:
    [[deprecated("GJGameState::updateTweenAction not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTweenAction(float p0, int p1);
public:
    
private:
    [[deprecated("GJGameState::updateTweenActions not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTweenActions(float p0);
public:
    float m_cameraZoom;
    float m_targetCameraZoom;
    cocos2d::CCPoint m_cameraOffset;
    cocos2d::CCPoint m_unkPoint1;
    cocos2d::CCPoint m_unkPoint2;
    cocos2d::CCPoint m_unkPoint3;
    cocos2d::CCPoint m_unkPoint4;
    cocos2d::CCPoint m_unkPoint5;
    cocos2d::CCPoint m_unkPoint6;
    cocos2d::CCPoint m_unkPoint7;
    cocos2d::CCPoint m_unkPoint8;
    cocos2d::CCPoint m_unkPoint9;
    cocos2d::CCPoint m_unkPoint10;
    cocos2d::CCPoint m_unkPoint11;
    cocos2d::CCPoint m_unkPoint12;
    cocos2d::CCPoint m_unkPoint13;
    cocos2d::CCPoint m_unkPoint14;
    cocos2d::CCPoint m_unkPoint15;
    cocos2d::CCPoint m_unkPoint16;
    cocos2d::CCPoint m_unkPoint17;
    cocos2d::CCPoint m_unkPoint18;
    cocos2d::CCPoint m_unkPoint19;
    cocos2d::CCPoint m_unkPoint20;
    cocos2d::CCPoint m_unkPoint21;
    cocos2d::CCPoint m_unkPoint22;
    cocos2d::CCPoint m_unkPoint23;
    cocos2d::CCPoint m_unkPoint24;
    cocos2d::CCPoint m_unkPoint25;
    cocos2d::CCPoint m_unkPoint26;
    cocos2d::CCPoint m_unkPoint27;
    cocos2d::CCPoint m_unkPoint28;
    cocos2d::CCPoint m_unkPoint29;
    bool m_unkBool1;
    int m_unkInt1;
    bool m_unkBool2;
    int m_unkInt2;
    bool m_unkBool3;
    cocos2d::CCPoint m_unkPoint30;
    float m_middleGroundOffsetY;
    int m_unkInt3;
    int m_unkInt4;
    bool m_unkBool4;
    bool m_unkBool5;
    float m_unkFloat2;
    float m_unkFloat3;
    int m_unkInt5;
    int m_unkInt6;
    int m_unkInt7;
    int m_unkInt8;
    int m_unkInt9;
    int m_unkInt10;
    int m_unkInt11;
    float m_unkFloat4;
    unsigned int m_unkUint1;
    float m_portalY;
    bool m_unkBool6;
    bool m_gravityRelated;
    int m_unkInt12;
    int m_unkInt13;
    int m_unkInt14;
    int m_unkInt15;
    bool m_unkBool7;
    bool m_unkBool8;
    bool m_unkBool9;
    float m_unkFloat5;
    float m_unkFloat6;
    float m_unkFloat7;
    float m_unkFloat8;
    float m_cameraAngle;
    float m_targetCameraAngle;
    bool m_unk184;
    float m_timeWarp;
    float m_timeWarpRelated;
    int m_currentChannel;
    int m_unkInt17;
    gd::unordered_map<int, int> m_spawnChannelRelated0;
    gd::unordered_map<int, bool> m_spawnChannelRelated1;
    double m_totalTime;
    double m_levelTime;
    double m_unkDouble3;
    unsigned int m_unkUint2;
    unsigned int m_unkUint3;
    int m_currentProgress;
    unsigned int m_unkUint4;
    unsigned int m_unkUint5;
    unsigned int m_unkUint6;
    unsigned int m_unkUint7;
    GameObject* m_unkGameObjPtr1;
    GameObject* m_unkGameObjPtr2;
    cocos2d::CCPoint m_cameraPosition;
    bool m_unkBool10;
    float m_levelFlipping;
    bool m_unkBool11;
    bool m_unkBool12;
    bool m_isDualMode;
    float m_unkFloat9;
    gd::unordered_map<int, GJValueTween> m_tweenActions;
    int m_cameraEdgeValue0;
    int m_cameraEdgeValue1;
    int m_cameraEdgeValue2;
    int m_cameraEdgeValue3;
    gd::unordered_map<int, GameObjectPhysics> m_gameObjectPhysics;
    gd::vector<float> m_unkVecFloat1;
    unsigned int m_unkUint10;
    unsigned int m_unkUint11;
    unsigned int m_unkUint12;
    cocos2d::CCPoint m_unkPoint31;
    float m_unkFloat10;
    unsigned int m_timeModRelated;
    bool m_timeModRelated2;
    gd::map<std::pair<int, int>, int> m_unkMapPairIntIntInt;
    unsigned int m_unkUint13;
    cocos2d::CCPoint m_unkPoint32;
    cocos2d::CCPoint m_unkPoint33;
    bool m_unkBool20;
    bool m_unkBool21;
    bool m_unkBool22;
    unsigned int m_unkUint14;
    bool m_unkBool26;
    bool m_cameraShakeEnabled;
    float m_cameraShakeFactor;
    unsigned int m_unkUint15;
    unsigned int m_unkUint16;
    uint64_t m_unkUint64_1;
    cocos2d::CCPoint m_unkPoint34;
    unsigned int dualRelated;
    gd::unordered_map<int, EnhancedGameObject*> m_stateObjects;
    gd::map<std::pair<GJGameEvent, int>, gd::vector<EventTriggerInstance>> m_unkMapPairGJGameEventIntVectorEventTriggerInstance;
    gd::map<std::pair<GJGameEvent, int>, int> m_unkMapPairGJGameEventIntInt;
    gd::unordered_map<int, std::vector<EnterEffectInstance>> m_unorderedMapEnterEffectInstanceVectors1;
    gd::unordered_map<int, std::vector<EnterEffectInstance>> m_unorderedMapEnterEffectInstanceVectors2;
    gd::vector<int> m_unkVecInt1;
    gd::vector<int> m_unkVecInt2;
    gd::vector<EnterEffectInstance> m_enterEffectInstances1;
    gd::vector<EnterEffectInstance> m_enterEffectInstances2;
    gd::vector<EnterEffectInstance> m_enterEffectInstances3;
    gd::vector<EnterEffectInstance> m_enterEffectInstances4;
    gd::vector<EnterEffectInstance> m_enterEffectInstances5;
    gd::unordered_set<int> m_unkUnorderedSet1;
    bool m_unkBool27;
    gd::vector<AdvancedFollowInstance> m_advanceFollowInstances;
    gd::vector<DynamicObjectAction> m_dynamicObjActions1;
    gd::vector<DynamicObjectAction> m_dynamicObjActions2;
    bool m_unkBool28;
    bool m_unkBool29;
    unsigned int m_unkUint17;
    gd::unordered_map<int, std::vector<int>> m_unkUMap8;
    gd::map<std::pair<int,int>, SFXTriggerInstance> m_proximityVolumeRelated;
    gd::unordered_map<int, SongChannelState> m_songChannelStates;
    gd::unordered_map<int, std::vector<SongTriggerState>> m_songTriggerStateVectors;
    gd::vector<SFXTriggerState> m_sfxTriggerStates;
    bool m_unkBool30;
    unsigned int m_unkUint18;
    int m_ground;
    unsigned int m_unkUint19;
    bool m_unkBool31;
    unsigned int m_unkUint20;
    bool m_unkBool32;
    unsigned int m_pauseCounter;
    unsigned int m_pauseBufferTimer;
};
