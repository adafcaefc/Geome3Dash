#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "EnhancedGameObject.hpp"

class EffectGameObject : public EnhancedGameObject {
public:
    static constexpr auto CLASS_NAME = "EffectGameObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(EffectGameObject, EnhancedGameObject)
    
private:
    [[deprecated("EffectGameObject::create not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16a0d4
     * @note[short] Android
     */
    static EffectGameObject* create(char const* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x16a470
     * @note[short] MacOS (Intel): 0x1a8550
     * @note[short] Windows: 0x48d790
     * @note[short] iOS: 0x37e130
     * @note[short] Android
     */
    virtual void setOpacity(unsigned char p0);

    /**
     * @note[short] MacOS (ARM): 0x16b8dc
     * @note[short] MacOS (Intel): 0x1aa2d0
     * @note[short] Windows: 0x48ffb0
     * @note[short] iOS: 0x37f594
     * @note[short] Android
     */
    virtual void firstSetup();

    /**
     * @note[short] MacOS (ARM): 0x14e098
     * @note[short] MacOS (Intel): 0x186600
     * @note[short] Windows: 0x48ffd0
     * @note[short] iOS: 0x370000
     * @note[short] Android
     */
    virtual void customSetup();

    /**
     * @note[short] MacOS (ARM): 0x16a4f4
     * @note[short] MacOS (Intel): 0x1a85d0
     * @note[short] Windows: 0x48d7d0
     * @note[short] iOS: 0x37e1b4
     * @note[short] Android
     */
    virtual void triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2);

    /**
     * @note[short] MacOS (ARM): 0x14f5b0
     * @note[short] MacOS (Intel): 0x187840
     * @note[short] Windows: 0x490230
     * @note[short] iOS: 0x371028
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);

    /**
     * @note[short] MacOS (ARM): 0x1463d0
     * @note[short] MacOS (Intel): 0x17c180
     * @note[short] Windows: 0x4932b0
     * @note[short] iOS: 0x36b454
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
    
private:
    [[deprecated("EffectGameObject::setRScaleX not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16a178
     * @note[short] MacOS (Intel): 0x1a81e0
     * @note[short] iOS: 0x37df18
     * @note[short] Android
     */
    virtual void setRScaleX(float p0);
public:
    
private:
    [[deprecated("EffectGameObject::setRScaleY not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16a188
     * @note[short] MacOS (Intel): 0x1a8200
     * @note[short] iOS: 0x37df28
     * @note[short] Android
     */
    virtual void setRScaleY(float p0);
public:
    
private:
    [[deprecated("EffectGameObject::triggerActivated not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16b854
     * @note[short] MacOS (Intel): 0x1aa260
     * @note[short] iOS: 0x37f520
     * @note[short] Android
     */
    virtual void triggerActivated(float p0);
public:
    
private:
    [[deprecated("EffectGameObject::restoreObject not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16b604
     * @note[short] MacOS (Intel): 0x1aa020
     * @note[short] iOS: 0x37f2ec
     * @note[short] Android
     */
    virtual void restoreObject();
public:
    
private:
    [[deprecated("EffectGameObject::spawnXPosition not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16b814
     * @note[short] MacOS (Intel): 0x1aa220
     * @note[short] iOS: 0x37f4e8
     * @note[short] Android
     */
    virtual float spawnXPosition();
public:
    
private:
    [[deprecated("EffectGameObject::canReverse not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16ba58
     * @note[short] MacOS (Intel): 0x1aa3b0
     * @note[short] iOS: 0x37f680
     * @note[short] Android
     */
    virtual bool canReverse();
public:
    
private:
    [[deprecated("EffectGameObject::isSpecialSpawnObject not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16bae4
     * @note[short] MacOS (Intel): 0x1aa420
     * @note[short] iOS: 0x37f70c
     * @note[short] Android
     */
    virtual bool isSpecialSpawnObject();
public:
    
private:
    [[deprecated("EffectGameObject::canBeOrdered not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16baec
     * @note[short] MacOS (Intel): 0x1aa430
     * @note[short] iOS: 0x37f714
     * @note[short] Android
     */
    virtual bool canBeOrdered();
public:
    
private:
    [[deprecated("EffectGameObject::getObjectLabel not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x199b10
     * @note[short] MacOS (Intel): 0x1e1d20
     * @note[short] iOS: 0x3922c0
     * @note[short] Android
     */
    virtual cocos2d::CCLabelBMFont* getObjectLabel();
public:
    
private:
    [[deprecated("EffectGameObject::setObjectLabel not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x199b18
     * @note[short] MacOS (Intel): 0x1e1d30
     * @note[short] iOS: 0x3922c8
     * @note[short] Android
     */
    virtual void setObjectLabel(cocos2d::CCLabelBMFont* p0);
public:
    
private:
    [[deprecated("EffectGameObject::stateSensitiveOff not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16b578
     * @note[short] MacOS (Intel): 0x1a9f90
     * @note[short] iOS: 0x37f260
     * @note[short] Android
     */
    virtual TodoReturn stateSensitiveOff(GJBaseGameLayer* p0);
public:
    
private:
    [[deprecated("EffectGameObject::getTargetColorIndex not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getTargetColorIndex();
public:

    /**
     * @note[short] Windows: 0x48d1a0
     * @note[short] Android
     */
    bool init(char const* p0);

    /**
     * @note[short] Windows: 0x48d2b0
     * @note[short] Android
     */
    TodoReturn playTriggerEffect();
    
private:
    [[deprecated("EffectGameObject::resetSpawnTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetSpawnTrigger();
public:
    
private:
    [[deprecated("EffectGameObject::setTargetID not implemented")]]
    /**
     * @note[short] Android
     */
    void setTargetID(int p0);
public:
    
private:
    [[deprecated("EffectGameObject::setTargetID2 not implemented")]]
    /**
     * @note[short] Android
     */
    void setTargetID2(int p0);
public:
    
private:
    [[deprecated("EffectGameObject::triggerEffectFinished not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn triggerEffectFinished();
public:
    
private:
    [[deprecated("EffectGameObject::updateInteractiveHover not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateInteractiveHover(float p0);
public:
    
private:
    [[deprecated("EffectGameObject::updateSpecialColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateSpecialColor();
public:

    /**
     * @note[short] Windows: 0x493010
     * @note[short] Android
     */
    TodoReturn updateSpeedModType();
    bool m_unknownBool;
    cocos2d::ccColor3B m_triggerTargetColor;
    float m_duration;
    float m_opacity;
    GEODE_PAD(4);
    int m_targetGroupID;
    int m_centerGroupID;
    bool m_isTouchTriggered;
    bool m_isSpawnTriggered;
    bool m_hasCenterEffect;
    float m_shakeStrength;
    float m_shakeInterval;
    bool m_tintGround;
    bool m_usesPlayerColor1;
    bool m_usesPlayerColor2;
    bool m_usesBlending;
    float m_moveOffsetX;
    float m_moveOffsetY;
    EasingType m_easingType;
    float m_easingRate;
    bool m_lockToPlayerX;
    bool m_lockToPlayerY;
    bool m_lockToCameraX;
    bool m_lockToCameraY;
    bool m_useMoveTarget;
    MoveTargetType m_moveTargetMode;
    float m_moveModX;
    float m_moveModY;
    bool m_property393;
    bool m_isDirectionFollowSnap360;
    int m_targetModCenterID;
    float m_directionModeDistance;
    bool m_isDynamicMode;
    bool m_isSilent;
    GEODE_PAD(6);
    float m_rotationDegrees;
    int m_times360;
    bool m_lockObjectRotation;
    int m_rotationTargetID;
    float m_rotationOffset;
    EasingType m_dynamicModeEasing;
    float m_followXMod;
    float m_followYMod;
    float m_followYSpeed;
    float m_followYDelay;
    int m_followYOffset;
    float m_followYMaxSpeed;
    float m_fadeInDuration;
    float m_holdDuration;
    float m_fadeOutDuration;
    int m_pulseMode;
    int m_pulseTargetType;
    cocos2d::ccHSVValue m_hsvValue;
    int m_copyColorID;
    bool m_copyOpacity;
    bool m_pulseMainOnly;
    bool m_pulseDetailOnly;
    bool m_pulseExclusive;
    bool m_property210;
    bool m_activateGroup;
    bool m_touchHoldMode;
    TouchToggleMode m_touchToggleMode;
    int m_touchPlayerMode;
    bool m_isDualMode;
    int m_animationID;
    GEODE_PAD(8);
    bool m_isMultiTriggered;
    GEODE_PAD(2);
    bool m_triggerOnExit;
    int m_itemID2;
    int m_property534;
    GEODE_PAD(1);
    bool m_isDynamicBlock;
    int m_itemID;
    bool m_targetPlayer1;
    bool m_targetPlayer2;
    bool m_followCPP;
    bool m_subtractCount;
    bool m_collectibleIsPickupItem;
    bool m_collectibleIsToggleTrigger;
    int m_collectibleParticleID;
    int m_collectiblePoints;
    bool m_hasNoAnimation;
    GEODE_PAD(35);
    float m_gravityValue;
    bool m_isSinglePTouch;
    GEODE_PAD(3);
    float m_zoomValue;
    bool m_cameraIsFreeMode;
    bool m_cameraEditCameraSettings;
    float m_cameraEasingValue;
    float m_cameraPaddingValue;
    bool m_cameraDisableGridSnap;
    bool m_property118;
    float m_timeWarpTimeMod;
    bool m_shouldPreview;
    int m_ordValue;
    int m_channelValue;
    bool m_isReverse;
    GEODE_PAD(11);
    int m_secretCoinID;
    GEODE_PAD(36);
    bool m_ignoreGroupParent;
    bool m_ignoreLinkedObjects;
    GEODE_PAD(1);
};
