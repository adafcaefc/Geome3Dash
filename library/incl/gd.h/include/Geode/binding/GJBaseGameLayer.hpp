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
#include "PlayerButtonCommand.hpp"
#include "TriggerEffectDelegate.hpp"

class GJBaseGameLayer : public cocos2d::CCLayer, public TriggerEffectDelegate {
public:
    static constexpr auto CLASS_NAME = "GJBaseGameLayer";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJBaseGameLayer, cocos2d::CCLayer)

    /**
     * @note[short] Windows: 0x200540
     * @note[short] Android
     */
     ~GJBaseGameLayer();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    static GJBaseGameLayer* get();

    /**
     * @note[short] MacOS (ARM): 0x119128
     * @note[short] MacOS (Intel): 0x141f90
     * @note[short] Windows: 0x232100
     * @note[short] iOS: 0x200aec
     * @note[short] Android
     */
    virtual void update(float p0);

    /**
     * @note[short] MacOS (ARM): 0xe0fb8
     * @note[short] MacOS (Intel): 0xfe730
     * @note[short] Windows: 0x201cc0
     * @note[short] iOS: 0x1db7ec
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (ARM): 0x126ac4
     * @note[short] MacOS (Intel): 0x152a70
     * @note[short] Windows: 0x240950
     * @note[short] iOS: 0x20a398
     * @note[short] Android
     */
    virtual void visit();
    
private:
    [[deprecated("GJBaseGameLayer::postUpdate not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual void postUpdate(float p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::checkForEnd not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual TodoReturn checkForEnd();
public:
    
private:
    [[deprecated("GJBaseGameLayer::testTime not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual TodoReturn testTime();
public:
    
private:
    [[deprecated("GJBaseGameLayer::updateVerifyDamage not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual void updateVerifyDamage();
public:
    
private:
    [[deprecated("GJBaseGameLayer::updateAttemptTime not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual void updateAttemptTime(float p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::updateVisibility not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual void updateVisibility(float p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::playerTookDamage not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual void playerTookDamage(PlayerObject* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x118f10
     * @note[short] MacOS (Intel): 0x141d40
     * @note[short] Windows: 0x231ce0
     * @note[short] iOS: 0x200918
     * @note[short] Android
     */
    virtual TodoReturn opacityForObject(GameObject* p0);
    
private:
    [[deprecated("GJBaseGameLayer::addToSpeedObjects not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual TodoReturn addToSpeedObjects(EffectGameObject* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0xf9cf8
     * @note[short] MacOS (Intel): 0x11b120
     * @note[short] Windows: 0x213c90
     * @note[short] iOS: 0x1ecfb0
     * @note[short] Android
     */
    virtual void objectsCollided(int p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0x1076d8
     * @note[short] MacOS (Intel): 0x12c570
     * @note[short] Windows: 0x21e5c0
     * @note[short] iOS: 0x1f3a00
     * @note[short] Android
     */
    virtual void updateColor(cocos2d::ccColor3B& color, float fadeTime, int colorID, bool blending, float opacity, cocos2d::ccHSVValue& copyHSV, int colorIDToCopy, bool copyOpacity, EffectGameObject* callerObject, int unk1, int unk2);

    /**
     * @note[short] MacOS (ARM): 0x107844
     * @note[short] MacOS (Intel): 0x12c710
     * @note[short] Windows: 0x21e7a0
     * @note[short] iOS: 0x1f3b6c
     * @note[short] Android
     */
    virtual void toggleGroupTriggered(int p0, bool p1, gd::vector<int> const& p2, int p3, int p4);

    /**
     * @note[short] MacOS (ARM): 0xfad48
     * @note[short] MacOS (Intel): 0x11c510
     * @note[short] Windows: 0x2156a0
     * @note[short] iOS: 0x1edbbc
     * @note[short] Android
     */
    virtual void spawnGroup(int p0, bool p1, double p2, gd::vector<int> const& p3, int p4, int p5);

    /**
     * @note[short] MacOS (ARM): 0xfb108
     * @note[short] MacOS (Intel): 0x11c8b0
     * @note[short] Windows: 0x215b50
     * @note[short] iOS: 0x1ede3c
     * @note[short] Android
     */
    virtual void spawnObject(GameObject* p0, double p1, gd::vector<int> const& p2);
    
private:
    [[deprecated("GJBaseGameLayer::activateEndTrigger not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual TodoReturn activateEndTrigger(int p0, bool p1, bool p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::activatePlatformerEndTrigger not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual void activatePlatformerEndTrigger(EndTriggerGameObject* p0, gd::vector<int> const& p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0xd590
     * @note[short] Android: Out of line
     */
    virtual void toggleGlitter(bool p0);
    
private:
    [[deprecated("GJBaseGameLayer::destroyPlayer not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual void destroyPlayer(PlayerObject* p0, GameObject* p1);
public:

    /**
     * @note[short] MacOS (ARM): 0xf0e34
     * @note[short] MacOS (Intel): 0x111270
     * @note[short] Windows: 0x20b4d0
     * @note[short] iOS: 0x1e5dcc
     * @note[short] Android
     */
    virtual void updateDebugDraw();

    /**
     * @note[short] MacOS (ARM): 0x1096bc
     * @note[short] MacOS (Intel): 0x12e930
     * @note[short] Windows: 0x221220
     * @note[short] iOS: 0x1f5108
     * @note[short] Android
     */
    virtual void addToSection(GameObject* p0);

    /**
     * @note[short] MacOS (ARM): 0x107d50
     * @note[short] MacOS (Intel): 0x12cca0
     * @note[short] Windows: 0x21ec20
     * @note[short] iOS: 0x1f3fb0
     * @note[short] Android
     */
    virtual void addToGroup(GameObject* p0, int p1, bool p2);

    /**
     * @note[short] MacOS (ARM): 0x107fa0
     * @note[short] MacOS (Intel): 0x12ced0
     * @note[short] Windows: 0x21eda0
     * @note[short] iOS: 0x1f4158
     * @note[short] Android
     */
    virtual void removeFromGroup(GameObject* p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0x10ae68
     * @note[short] MacOS (Intel): 0x130780
     * @note[short] Windows: 0x222c70
     * @note[short] iOS: 0x1f60bc
     * @note[short] Android
     */
    virtual void updateObjectSection(GameObject* p0);
    
private:
    [[deprecated("GJBaseGameLayer::updateDisabledObjectsLastPos not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual TodoReturn updateDisabledObjectsLastPos(cocos2d::CCArray* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::toggleGroundVisibility not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x116b60
     * @note[short] MacOS (Intel): 0x13efe0
     * @note[short] iOS: 0x1fef2c
     * @note[short] Android
     */
    virtual TodoReturn toggleGroundVisibility(bool p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::toggleMGVisibility not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x116b64
     * @note[short] MacOS (Intel): 0x13eff0
     * @note[short] iOS: 0x1fef30
     * @note[short] Android
     */
    virtual void toggleMGVisibility(bool p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::toggleHideAttempts not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x116b68
     * @note[short] MacOS (Intel): 0x13f000
     * @note[short] iOS: 0x1fef34
     * @note[short] Android
     */
    virtual void toggleHideAttempts(bool p0);
public:

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    virtual float timeForPos(cocos2d::CCPoint p0, int p1, int p2, bool p3, int p4);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    virtual cocos2d::CCPoint posForTime(float p0);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    virtual void resetSPTriggered();

    /**
     * @note[short] MacOS (ARM): 0x116cb0
     * @note[short] MacOS (Intel): 0x13f1a0
     * @note[short] Windows: 0x230720
     * @note[short] iOS: 0x1ff018
     * @note[short] Android
     */
    virtual void updateScreenRotation(float p0, bool p1, bool p2, float p3, int p4, float p5, int p6, int p7);

    /**
     * @note[short] MacOS (ARM): 0xf8e6c
     * @note[short] MacOS (Intel): 0x11a1f0
     * @note[short] Windows: 0x212c80
     * @note[short] iOS: 0x1ec3d4
     * @note[short] Android
     */
    virtual TodoReturn reverseDirection(EffectGameObject* p0);

    /**
     * @note[short] MacOS (ARM): 0xf8eb0
     * @note[short] MacOS (Intel): 0x11a230
     * @note[short] Windows: 0x212ce0
     * @note[short] iOS: 0x1ec418
     * @note[short] Android
     */
    virtual void rotateGameplay(RotateGameplayGameObject* p0);
    
private:
    [[deprecated("GJBaseGameLayer::didRotateGameplay not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual TodoReturn didRotateGameplay();
public:

    /**
     * @note[short] MacOS (ARM): 0x11730c
     * @note[short] MacOS (Intel): 0x13f940
     * @note[short] Windows: 0x230a00
     * @note[short] iOS: 0x1ff468
     * @note[short] Android
     */
    virtual void updateTimeWarp(float p0);

    /**
     * @note[short] MacOS (ARM): 0x117300
     * @note[short] MacOS (Intel): 0x13f920
     * @note[short] Windows: 0x2309f0
     * @note[short] iOS: 0x1ff45c
     * @note[short] Android
     */
    virtual void updateTimeWarp(GameObject* p0, float p1);

    /**
     * @note[short] MacOS (ARM): 0x11734c
     * @note[short] MacOS (Intel): 0x13f990
     * @note[short] Windows: 0x230a50
     * @note[short] iOS: 0x1ff4a4
     * @note[short] Android
     */
    virtual TodoReturn applyTimeWarp(float p0);
    
private:
    [[deprecated("GJBaseGameLayer::playGravityEffect not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual void playGravityEffect(bool p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::manualUpdateObjectColors not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual TodoReturn manualUpdateObjectColors(GameObject* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x122170
     * @note[short] MacOS (Intel): 0x14cf30
     * @note[short] Windows: 0x23a7f0
     * @note[short] iOS: 0x206ed8
     * @note[short] Android
     */
    virtual TodoReturn createCustomParticle(gd::string const& p0, cocos2d::ParticleStruct const& p1, int p2, bool p3);

    /**
     * @note[short] MacOS (ARM): 0x122520
     * @note[short] MacOS (Intel): 0x14d2c0
     * @note[short] Windows: 0x23aaf0
     * @note[short] iOS: 0x207108
     * @note[short] Android
     */
    virtual TodoReturn claimCustomParticle(gd::string const& p0, cocos2d::ParticleStruct const& p1, int p2, int p3, int p4, bool p5);

    /**
     * @note[short] MacOS (ARM): 0x122760
     * @note[short] MacOS (Intel): 0x14d4c0
     * @note[short] Windows: 0x23acf0
     * @note[short] iOS: 0x207348
     * @note[short] Android
     */
    virtual TodoReturn unclaimCustomParticle(gd::string const& p0, cocos2d::CCParticleSystemQuad* p1);

    /**
     * @note[short] MacOS (ARM): 0x123474
     * @note[short] MacOS (Intel): 0x14e3e0
     * @note[short] Windows: 0x23c8a0
     * @note[short] iOS: 0x207e14
     * @note[short] Android
     */
    virtual TodoReturn activatedAudioTrigger(SFXTriggerGameObject* p0);

    /**
     * @note[short] MacOS (ARM): 0x126808
     * @note[short] MacOS (Intel): 0x152790
     * @note[short] Windows: 0x240530
     * @note[short] iOS: 0x20a194
     * @note[short] Android
     */
    virtual void checkpointActivated(CheckpointGameObject* p0);
    
private:
    [[deprecated("GJBaseGameLayer::flipArt not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x126804
     * @note[short] MacOS (Intel): 0x152780
     * @note[short] iOS: 0x20a190
     * @note[short] Android
     */
    virtual TodoReturn flipArt(bool p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x113f9c
     * @note[short] MacOS (Intel): 0x13b940
     * @note[short] Windows: 0x22e420
     * @note[short] iOS: 0x1fd18c
     * @note[short] Android
     */
    virtual void addKeyframe(KeyframeGameObject* p0);
    
private:
    [[deprecated("GJBaseGameLayer::updateTimeLabel not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual void updateTimeLabel(int p0, int p1, bool p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::checkSnapshot not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual TodoReturn checkSnapshot();
public:
    
private:
    [[deprecated("GJBaseGameLayer::toggleProgressbar not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual void toggleProgressbar();
public:
    
private:
    [[deprecated("GJBaseGameLayer::toggleInfoLabel not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual TodoReturn toggleInfoLabel();
public:
    
private:
    [[deprecated("GJBaseGameLayer::removeAllCheckpoints not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual void removeAllCheckpoints();
public:
    
private:
    [[deprecated("GJBaseGameLayer::toggleMusicInPractice not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual TodoReturn toggleMusicInPractice();
public:
    
private:
    [[deprecated("GJBaseGameLayer::activateCustomRing not implemented")]]
    /**
     * @note[short] Android
     */
    void activateCustomRing(RingObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::activatedAudioTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn activatedAudioTrigger(SFXTriggerGameObject* p0, float p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::activateEventTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn activateEventTrigger(EventLinkTrigger* p0, gd::vector<int> const& p1);
public:

    /**
     * @note[short] Windows: 0x22eed0
     * @note[short] Android
     */
    TodoReturn activateItemCompareTrigger(ItemTriggerGameObject* p0, gd::vector<int> const& p1);

    /**
     * @note[short] MacOS (ARM): 0x114c0c
     * @note[short] MacOS (Intel): 0x13c800
     * @note[short] Windows: 0x22eaf0
     * @note[short] Android
     */
    void activateItemEditTrigger(ItemTriggerGameObject* p0);
    
private:
    [[deprecated("GJBaseGameLayer::activateObjectControlTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    void activateObjectControlTrigger(ObjectControlGameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::activatePersistentItemTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn activatePersistentItemTrigger(ItemTriggerGameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::activatePlayerControlTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    void activatePlayerControlTrigger(PlayerControlGameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::activateResetTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn activateResetTrigger(EffectGameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::activateSFXEditTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    void activateSFXEditTrigger(SFXTriggerGameObject* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x11f100
     * @note[short] MacOS (Intel): 0x149850
     * @note[short] Windows: 0x23b6c0
     * @note[short] Android
     */
    void activateSFXTrigger(SFXTriggerGameObject* p0);

    /**
     * @note[short] MacOS (ARM): 0x11eec4
     * @note[short] MacOS (Intel): 0x1495f0
     * @note[short] Windows: 0x23b8c0
     * @note[short] Android
     */
    void activateSongEditTrigger(SongTriggerGameObject* p0);
    
private:
    [[deprecated("GJBaseGameLayer::activateSongTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    void activateSongTrigger(SongTriggerGameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::activateTimerTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn activateTimerTrigger(TimerTriggerGameObject* p0, gd::vector<int> const& p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::addAreaEffect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn addAreaEffect(EnterEffectObject* p0, gd::vector<EnterEffectInstance>* p1, GJAreaActionType p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::addCustomEnterEffect not implemented")]]
    /**
     * @note[short] Android
     */
    void addCustomEnterEffect(EnterEffectObject* p0, bool p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::addGuideArt not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x125938
     * @note[short] MacOS (Intel): 0x151740
     * @note[short] Android
     */
    TodoReturn addGuideArt(GameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::addObjectCounter not implemented")]]
    /**
     * @note[short] Android
     */
    void addObjectCounter(LabelGameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::addPickupTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn addPickupTrigger(CountTriggerGameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::addPoints not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn addPoints(int p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::addProximityVolumeEffect not implemented")]]
    /**
     * @note[short] Android
     */
    void addProximityVolumeEffect(int p0, int p1, SFXTriggerGameObject* p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::addRemapTargets not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x105880
     * @note[short] Android
     */
    TodoReturn addRemapTargets(gd::set<int>& p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::addToGroupParents not implemented")]]
    /**
     * @note[short] Android
     */
    void addToGroupParents(GameObject* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x107cdc
     * @note[short] MacOS (Intel): 0x12cc30
     * @note[short] Windows: 0x21eb90
     * @note[short] Android
     */
    void addToGroups(GameObject* p0, bool p1);
    
private:
    [[deprecated("GJBaseGameLayer::addToObjectsToShow not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn addToObjectsToShow(GameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::addUIObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn addUIObject(GameObject* p0);
public:

    /**
     * @note[short] Windows: 0x20deb0
     * @note[short] Android
     */
    void animateInDualGroundNew(GameObject* p0, float p1, bool p2, float p3);
    
private:
    [[deprecated("GJBaseGameLayer::animateInGroundNew not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x1144f0
     * @note[short] Android
     */
    TodoReturn animateInGroundNew(bool p0, float p1, bool p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::animateOutGroundNew not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x1147e0
     * @note[short] Android
     */
    void animateOutGroundNew(bool p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::animatePortalY not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn animatePortalY(float p0, float p1, float p2, float p3);
public:
    
private:
    [[deprecated("GJBaseGameLayer::applyLevelSettings not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x147ac0
     * @note[short] Android
     */
    TodoReturn applyLevelSettings(GameObject* p0);
public:

    /**
     * @note[short] Windows: 0x215ce0
     * @note[short] Android
     */
    void applyRemap(EffectGameObject* p0, gd::vector<int> const& p1, gd::unordered_map<int, int>& p2);
    
private:
    [[deprecated("GJBaseGameLayer::applySFXEditTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    void applySFXEditTrigger(int p0, int p1, SFXTriggerGameObject* p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::applyShake not implemented")]]
    /**
     * @note[short] Android
     */
    void applyShake(cocos2d::CCPoint& p0);
public:

    /**
     * @note[short] Windows: 0x21f990
     * @note[short] Android
     */
    void assignNewStickyGroups(cocos2d::CCArray* p0);
    
private:
    [[deprecated("GJBaseGameLayer::asyncBGLoaded not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn asyncBGLoaded(int p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::asyncGLoaded not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn asyncGLoaded(int p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::asyncMGLoaded not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn asyncMGLoaded(int p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::atlasValue not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn atlasValue(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0xf6b04
     * @note[short] MacOS (Intel): 0x117ce0
     * @note[short] Windows: 0x2124f0
     * @note[short] Android
     */
    void bumpPlayer(PlayerObject* p0, EffectGameObject* p1);
    
private:
    [[deprecated("GJBaseGameLayer::buttonIDToButton not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn buttonIDToButton(int p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::calculateColorGroups not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn calculateColorGroups();
public:
    
private:
    [[deprecated("GJBaseGameLayer::cameraMoveX not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn cameraMoveX(float p0, float p1, float p2, bool p3);
public:
    
private:
    [[deprecated("GJBaseGameLayer::cameraMoveY not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn cameraMoveY(float p0, float p1, float p2, bool p3);
public:

    /**
     * @note[short] MacOS (ARM): 0xf6710
     * @note[short] MacOS (Intel): 0x117880
     * @note[short] Windows: 0x2123e0
     * @note[short] Android
     */
    bool canBeActivatedByPlayer(PlayerObject* p0, EffectGameObject* p1);
    
private:
    [[deprecated("GJBaseGameLayer::canProcessSFX not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn canProcessSFX(SFXTriggerState& p0, gd::unordered_map<int, int>& p1, gd::unordered_map<int, float>& p2, gd::vector<SFXTriggerState>& p3);
public:
    
private:
    [[deprecated("GJBaseGameLayer::canTouchObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn canTouchObject(GameObject* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0xf0a1c
     * @note[short] MacOS (Intel): 0x110df0
     * @note[short] Windows: 0x2340b0
     * @note[short] Android
     */
    TodoReturn checkCameraLimitAfterTeleport(PlayerObject* p0, float p1);
    
private:
    [[deprecated("GJBaseGameLayer::checkCollision not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn checkCollision(int p0, int p1);
public:

    /**
     * @note[short] Windows: 0x2139e0
     * @note[short] Android
     */
    void checkCollisionBlocks(EffectGameObject* p0, gd::vector<EffectGameObject*>* p1, int p2);

    /**
     * @note[short] MacOS (ARM): 0xf45f0
     * @note[short] MacOS (Intel): 0x114fe0
     * @note[short] Windows: 0x20e330
     * @note[short] Android
     */
    int checkCollisions(PlayerObject* p0, float p1, bool p2);

    /**
     * @note[short] MacOS (Intel): 0x143830
     * @note[short] Windows: 0x233de0
     * @note[short] Android
     */
    void checkRepellPlayer();

    /**
     * @note[short] MacOS (Intel): 0x11c1f0
     * @note[short] Windows: 0x215410
     * @note[short] Android
     */
    void checkSpawnObjects();
    
private:
    [[deprecated("GJBaseGameLayer::claimMoveAction not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn claimMoveAction(int p0, bool p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::claimParticle not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn claimParticle(gd::string p0, int p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::claimRotationAction not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn claimRotationAction(int p0, int p1, float& p2, float& p3, bool p4, bool p5);
public:
    
private:
    [[deprecated("GJBaseGameLayer::clearActivatedAudioTriggers not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x148ac0
     * @note[short] Android
     */
    TodoReturn clearActivatedAudioTriggers();
public:
    
private:
    [[deprecated("GJBaseGameLayer::clearPickedUpItems not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x292260
     * @note[short] Android
     */
    TodoReturn clearPickedUpItems();
public:
    
private:
    [[deprecated("GJBaseGameLayer::collectedObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn collectedObject(EffectGameObject* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0xf5554
     * @note[short] MacOS (Intel): 0x116130
     * @note[short] Windows: 0x20f480
     * @note[short] Android
     */
    void collisionCheckObjects(PlayerObject* p0, gd::vector<GameObject*>* p1, int p2, float p3);
    
private:
    [[deprecated("GJBaseGameLayer::controlAdvancedFollowCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn controlAdvancedFollowCommand(AdvancedFollowTriggerObject* p0, int p1, GJActionCommand p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::controlAreaEffect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn controlAreaEffect(EnterEffectObject* p0, gd::vector<EnterEffectInstance>* p1, GJActionCommand p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::controlAreaEffectWithID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn controlAreaEffectWithID(int p0, int p1, GJActionCommand p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::controlDynamicCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn controlDynamicCommand(EffectGameObject* p0, int p1, gd::vector<DynamicObjectAction>& p2, GJActionCommand p3);
public:
    
private:
    [[deprecated("GJBaseGameLayer::controlDynamicMoveCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn controlDynamicMoveCommand(EffectGameObject* p0, int p1, GJActionCommand p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::controlDynamicRotateCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn controlDynamicRotateCommand(EffectGameObject* p0, int p1, GJActionCommand p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::controlEventLink not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn controlEventLink(int p0, int p1, GJActionCommand p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::controlGradientTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn controlGradientTrigger(GradientTriggerObject* p0, GJActionCommand p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::controlTriggersInGroup not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn controlTriggersInGroup(int p0, GJActionCommand p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::controlTriggersWithControlID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn controlTriggersWithControlID(int p0, GJActionCommand p1);
public:

    /**
     * @note[short] Windows: 0x2295d0
     * @note[short] Android
     */
    TodoReturn convertToClosestDirection(float p0, float p1);

    /**
     * @note[short] MacOS (ARM): 0xe4ed4
     * @note[short] MacOS (Intel): 0x1030e0
     * @note[short] Windows: 0x2064e0
     * @note[short] Android
     */
    void createBackground(int p0);

    /**
     * @note[short] MacOS (ARM): 0xe5410
     * @note[short] MacOS (Intel): 0x103660
     * @note[short] Windows: 0x206920
     * @note[short] Android
     */
    void createGroundLayer(int p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0xe55f4
     * @note[short] MacOS (Intel): 0x103870
     * @note[short] Windows: 0x2067a0
     * @note[short] Android
     */
    void createMiddleground(int p0);
    
private:
    [[deprecated("GJBaseGameLayer::createNewKeyframeAnim not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createNewKeyframeAnim();
public:
    
private:
    [[deprecated("GJBaseGameLayer::createParticle not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createParticle(int p0, char const* p1, int p2, cocos2d::tCCPositionType p3);
public:

    /**
     * @note[short] MacOS (ARM): 0xe4b94
     * @note[short] MacOS (Intel): 0x102d80
     * @note[short] Windows: 0x205fd0
     * @note[short] Android
     */
    void createPlayer();

    /**
     * @note[short] MacOS (Intel): 0x11a410
     * @note[short] Windows: 0x212e90
     * @note[short] Android
     */
    TodoReturn createPlayerCollisionBlock();

    /**
     * @note[short] MacOS (ARM): 0xee828
     * @note[short] MacOS (Intel): 0x10f2e0
     * @note[short] Windows: 0x209960
     * @note[short] Android
     */
    void createTextLayers();
    
private:
    [[deprecated("GJBaseGameLayer::damagingObjectsInRect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn damagingObjectsInRect(cocos2d::CCRect p0, bool p1);
public:

    /**
     * @note[short] MacOS (ARM): 0xf71e8
     * @note[short] MacOS (Intel): 0x118390
     * @note[short] Windows: 0x210bb0
     * @note[short] Android
     */
    void destroyObject(GameObject* p0);
    
private:
    [[deprecated("GJBaseGameLayer::enterDualMode not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xf84b0
     * @note[short] MacOS (Intel): 0x119720
     * @note[short] Android
     */
    void enterDualMode(GameObject* p0, bool p1);
public:

    /**
     * @note[short] Windows: 0x2390e0
     * @note[short] Android
     */
    void exitStaticCamera(bool exitX, bool exitY, float time, int easingType, float easingRate, bool smoothVelocity, float smoothVelocityMod, bool exitInstant);
    
private:
    [[deprecated("GJBaseGameLayer::flipFinished not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn flipFinished();
public:

    /**
     * @note[short] MacOS (ARM): 0xf3874
     * @note[short] MacOS (Intel): 0x114040
     * @note[short] Windows: 0x20d640
     * @note[short] Android
     */
    void flipGravity(PlayerObject* p0, bool p1, bool p2);
    
private:
    [[deprecated("GJBaseGameLayer::flipObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn flipObjects();
public:
    
private:
    [[deprecated("GJBaseGameLayer::gameEventToString not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn gameEventToString(GJGameEvent p0);
public:

    /**
     * @note[short] MacOS (ARM): 0xf0ae8
     * @note[short] MacOS (Intel): 0x110ea0
     * @note[short] Windows: 0x22c8a0
     * @note[short] Android
     */
    void gameEventTriggered(GJGameEvent p0, int p1, int p2);
    
private:
    [[deprecated("GJBaseGameLayer::generateEnterEasingBuffer not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn generateEnterEasingBuffer(int p0, float p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::generateEnterEasingBuffers not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn generateEnterEasingBuffers(EnterEffectObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::generatePickupAnimRandVal not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn generatePickupAnimRandVal(GameObject* p0, float& p1, float& p2);
public:

    /**
     * @note[short] MacOS (Intel): 0x106400
     * @note[short] Windows: 0x218c00
     * @note[short] Android
     */
    TodoReturn generateSpawnRemap();
    
private:
    [[deprecated("GJBaseGameLayer::generateTargetGroups not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x109d00
     * @note[short] Android
     */
    TodoReturn generateTargetGroups();
public:
    
private:
    [[deprecated("GJBaseGameLayer::generateVisibilityGroups not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn generateVisibilityGroups();
public:
    
private:
    [[deprecated("GJBaseGameLayer::getActiveOrderSpawnObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getActiveOrderSpawnObjects();
public:

    /**
     * @note[short] Windows: 0x222d90
     * @note[short] Android
     */
    float getAreaObjectValue(EnterEffectInstance* p0, GameObject* p1, cocos2d::CCPoint& p2, bool& p3);
    
private:
    [[deprecated("GJBaseGameLayer::getBumpMod not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getBumpMod(PlayerObject* p0, int p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getCameraEdgeValue not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x13f630
     * @note[short] Android
     */
    TodoReturn getCameraEdgeValue(int p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getCapacityString not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getCapacityString();
public:
    
private:
    [[deprecated("GJBaseGameLayer::getCenterGroupObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getCenterGroupObject(int p0, int p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getCustomEnterEffects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getCustomEnterEffects(int p0, bool p1);
public:

    /**
     * @note[short] Windows: 0x222f80
     * @note[short] Android
     */
    float getEasedAreaValue(GameObject* p0, EnterEffectInstance* p1, float p2, bool p3, int p4);
    
private:
    [[deprecated("GJBaseGameLayer::getEnterEasingKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getEnterEasingKey(int p0, float p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getEnterEasingValue not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getEnterEasingValue(float p0, int p1, float p2, int p3);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getFollowSpeedVal not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getFollowSpeedVal(GameObject* p0, int p1, int p2, float p3, float p4);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getGroundHeight not implemented")]]
    /**
     * @note[short] Android
     */
    float getGroundHeight(PlayerObject* p0, int p1);
public:

    /**
     * @note[short] Windows: 0x20c890
     * @note[short] Android
     */
    TodoReturn getGroundHeightForMode(int p0);

    /**
     * @note[short] Windows: 0x21eed0
     * @note[short] Android
     */
    TodoReturn getGroup(int p0);
    
private:
    [[deprecated("GJBaseGameLayer::getGroupParent not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getGroupParent(int p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getGroupParentsString not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getGroupParentsString(GameObject* p0);
public:

    /**
     * @note[short] Windows: 0x22ea60
     * @note[short] Android
     */
    TodoReturn getItemValue(int p0, int p1);

    /**
     * @note[short] Windows: 0x20e2b0
     * @note[short] Android
     */
    float getMaxPortalY();

    /**
     * @note[short] Windows: 0x23c430
     * @note[short] Android
     */
    TodoReturn getMinDistance(cocos2d::CCPoint p0, cocos2d::CCArray* p1, float p2, int p3);

    /**
     * @note[short] Windows: 0x20e1d0
     * @note[short] Android
     */
    float getMinPortalY();

    /**
     * @note[short] MacOS (ARM): 0x119084
     * @note[short] MacOS (Intel): 0x141ee0
     * @note[short] Windows: 0x232060
     * @note[short] Android
     */
    float getModifiedDelta(float p0);
    
private:
    [[deprecated("GJBaseGameLayer::getMoveTargetDelta not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getMoveTargetDelta(EffectGameObject* p0, bool p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getOptimizedGroup not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getOptimizedGroup(int p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getOtherPlayer not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x1128b0
     * @note[short] Android
     */
    PlayerObject* getOtherPlayer(PlayerObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getParticleKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getParticleKey(int p0, char const* p1, int p2, cocos2d::tCCPositionType p3);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getParticleKey2 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getParticleKey2(gd::string p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getPlayerButtonID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getPlayerButtonID(int p0, bool p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getPlayTimerFullSeconds not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getPlayTimerFullSeconds();
public:
    
private:
    [[deprecated("GJBaseGameLayer::getPlayTimerMilli not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getPlayTimerMilli();
public:
    
private:
    [[deprecated("GJBaseGameLayer::getPortalTarget not implemented")]]
    /**
     * @note[short] Android
     */
    TeleportPortalObject* getPortalTarget(TeleportPortalObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getPortalTargetPos not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCPoint getPortalTargetPos(TeleportPortalObject* p0, GameObject* p1, PlayerObject* p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getRecordString not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getRecordString();
public:
    
private:
    [[deprecated("GJBaseGameLayer::getRotateCommandTargets not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getRotateCommandTargets(EnhancedTriggerObject* p0, GameObject*& p1, GameObject*& p2, GameObject*& p3);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getSavedPosition not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getSavedPosition(int p0, float p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getScaledGroundHeight not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getScaledGroundHeight(float p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getSingleGroupObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getSingleGroupObject(int p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getSpecialKey not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getSpecialKey(int p0, bool p1, bool p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getStaticGroup not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getStaticGroup(int p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getStickyGroup not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getStickyGroup(int p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getTargetFlyCameraY not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getTargetFlyCameraY(GameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getTargetGroup not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getTargetGroup(int p0, int p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::getTargetGroupOrigin not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getTargetGroupOrigin(int p0, int p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::gravBumpPlayer not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xf6d28
     * @note[short] MacOS (Intel): 0x117ef0
     * @note[short] Android
     */
    TodoReturn gravBumpPlayer(PlayerObject* p0, EffectGameObject* p1);
public:

    /**
     * @note[short] Windows: 0x21f7b0
     * @note[short] Android
     */
    void groupStickyObjects(cocos2d::CCArray* p0);

    /**
     * @note[short] MacOS (ARM): 0x1136ec
     * @note[short] MacOS (Intel): 0x13afc0
     * @note[short] Windows: 0x22e190
     * @note[short] Android
     */
    void handleButton(bool down, int button, bool isPlayer1);
    
private:
    [[deprecated("GJBaseGameLayer::hasItem not implemented")]]
    /**
     * @note[short] Android
     */
    bool hasItem(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0xf72cc
     * @note[short] MacOS (Intel): 0x118460
     * @note[short] Windows: 0x211220
     * @note[short] Android
     */
    bool hasUniqueCoin(EffectGameObject* p0);

    /**
     * @note[short] Windows: 0x2078e0
     * @note[short] Android
     */
    void increaseBatchNodeCapacity();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    bool isFlipping();
    
private:
    [[deprecated("GJBaseGameLayer::isPlayer2Button not implemented")]]
    /**
     * @note[short] Android
     */
    bool isPlayer2Button(int p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::lightningFlash not implemented")]]
    /**
     * @note[short] Android
     */
    void lightningFlash(cocos2d::CCPoint to, cocos2d::ccColor3B color);
public:

    /**
     * @note[short] MacOS (ARM): 0xf089c
     * @note[short] MacOS (Intel): 0x110c50
     * @note[short] Windows: 0x240770
     * @note[short] Android
     */
    void lightningFlash(cocos2d::CCPoint from, cocos2d::CCPoint to, cocos2d::ccColor3B color, float lineWidth, float duration, int displacement, bool flash, float opacity);
    
private:
    [[deprecated("GJBaseGameLayer::loadGroupParentsFromString not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn loadGroupParentsFromString(GameObject* p0, gd::string p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x11d8c0
     * @note[short] MacOS (Intel): 0x147920
     * @note[short] Windows: 0x234770
     * @note[short] Android
     */
    void loadLevelSettings();

    /**
     * @note[short] MacOS (Intel): 0x13e9f0
     * @note[short] Windows: 0x230000
     * @note[short] Android
     */
    void loadStartPosObject();

    /**
     * @note[short] Windows: 0x2301a0
     * @note[short] Android
     */
    void loadUpToPosition(float p0, int p1, int p2);
    
private:
    [[deprecated("GJBaseGameLayer::maxZOrderForShaderZ not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn maxZOrderForShaderZ(int p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::minZOrderForShaderZ not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn minZOrderForShaderZ(int p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::modifyGroupPhysics not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn modifyGroupPhysics(AdvancedFollowEditObject* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::modifyObjectPhysics not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn modifyObjectPhysics(AdvancedFollowEditObject* p0, GameObjectPhysics& p1);
public:

    /**
     * @note[short] Windows: 0x2257d0
     * @note[short] Android
     */
    void moveAreaObject(GameObject* p0, float p1, float p2);
    
private:
    [[deprecated("GJBaseGameLayer::moveCameraToPos not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn moveCameraToPos(cocos2d::CCPoint p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::moveObject not implemented")]]
    /**
     * @note[short] Android
     */
    void moveObject(GameObject* p0, double p1, double p2, bool p3);
public:

    /**
     * @note[short] Windows: 0x228a70
     * @note[short] Android
     */
    void moveObjects(cocos2d::CCArray* p0, double p1, double p2, bool p3);
    
private:
    [[deprecated("GJBaseGameLayer::moveObjectsSilent not implemented")]]
    /**
     * @note[short] Android
     */
    void moveObjectsSilent(int p0, double p1, double p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::moveObjectToStaticGroup not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn moveObjectToStaticGroup(GameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::objectIntersectsCircle not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn objectIntersectsCircle(GameObject* p0, GameObject* p1);
public:

    /**
     * @note[short] MacOS (Intel): 0x1144d0
     * @note[short] Windows: 0x22ce10
     * @note[short] Android
     */
    GJGameEvent objectTypeToGameEvent(int p0);
    
private:
    [[deprecated("GJBaseGameLayer::optimizeMoveGroups not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn optimizeMoveGroups();
public:
    
private:
    [[deprecated("GJBaseGameLayer::orderSpawnObjects not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x151690
     * @note[short] Android
     */
    TodoReturn orderSpawnObjects();
public:
    
private:
    [[deprecated("GJBaseGameLayer::parentForZLayer not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x10f720
     * @note[short] Android
     */
    TodoReturn parentForZLayer(int p0, bool p1, int p2, int p3);
public:

    /**
     * @note[short] MacOS (Intel): 0x141de0
     * @note[short] Windows: 0x231d60
     * @note[short] Android
     */
    void pauseAudio();
    
private:
    [[deprecated("GJBaseGameLayer::performMathOperation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn performMathOperation(double p0, double p1, int p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::performMathRounding not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn performMathRounding(double p0, int p1);
public:

    /**
     * @note[short] MacOS (ARM): 0xf7400
     * @note[short] MacOS (Intel): 0x118560
     * @note[short] Windows: 0x210cd0
     * @note[short] Android
     */
    void pickupItem(EffectGameObject* p0);
    
private:
    [[deprecated("GJBaseGameLayer::playAnimationCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn playAnimationCommand(int p0, int p1);
public:

    /**
     * @note[short] Windows: 0x20c930
     * @note[short] Android
     */
    bool playerCircleCollision(PlayerObject* p0, GameObject* p1);
    
private:
    [[deprecated("GJBaseGameLayer::playerIntersectsCircle not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn playerIntersectsCircle(PlayerObject* p0, GameObject* p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::playerTouchedObject not implemented")]]
    /**
     * @note[short] Android
     */
    void playerTouchedObject(PlayerObject* p0, GameObject* p1);
public:

    /**
     * @note[short] MacOS (ARM): 0xf6eb0
     * @note[short] MacOS (Intel): 0x118040
     * @note[short] Windows: 0x212960
     * @note[short] Android
     */
    void playerTouchedRing(PlayerObject* p0, RingObject* p1);

    /**
     * @note[short] MacOS (ARM): 0xf6f88
     * @note[short] MacOS (Intel): 0x1180f0
     * @note[short] Windows: 0x212a70
     * @note[short] Android
     */
    void playerTouchedTrigger(PlayerObject* p0, EffectGameObject* p1);
    
private:
    [[deprecated("GJBaseGameLayer::playerWasTouchingObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn playerWasTouchingObject(PlayerObject* p0, GameObject* p1);
public:

    /**
     * @note[short] MacOS (ARM): 0xf3a44
     * @note[short] MacOS (Intel): 0x114200
     * @note[short] Windows: 0x20da30
     * @note[short] Android
     */
    void playerWillSwitchMode(PlayerObject* p0, GameObject* p1);

    /**
     * @note[short] Windows: 0x2119a0
     * @note[short] Android
     */
    void playExitDualEffect(PlayerObject* p0);
    
private:
    [[deprecated("GJBaseGameLayer::playFlashEffect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn playFlashEffect(float p0, int p1, float p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::playKeyframeAnimation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn playKeyframeAnimation(KeyframeAnimTriggerObject* p0, gd::vector<int> const& p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::playSpeedParticle not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x121058
     * @note[short] MacOS (Intel): 0x14c000
     * @note[short] Android
     */
    TodoReturn playSpeedParticle(float p0);
public:

    /**
     * @note[short] Windows: 0x21e1a0
     * @note[short] Android
     */
    TodoReturn positionForShaderTarget(int p0);
    
private:
    [[deprecated("GJBaseGameLayer::positionUIObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn positionUIObjects();
public:
    
private:
    [[deprecated("GJBaseGameLayer::prepareSavePositionObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn prepareSavePositionObjects();
public:
    
private:
    [[deprecated("GJBaseGameLayer::prepareTransformParent not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn prepareTransformParent(bool p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::preResumeGame not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x141dd0
     * @note[short] Android
     */
    void preResumeGame();
public:
    
private:
    [[deprecated("GJBaseGameLayer::preUpdateVisibility not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn preUpdateVisibility(float p0);
public:

    /**
     * @note[short] MacOS (Intel): 0x14f3a0
     * @note[short] Windows: 0x23d3e0
     * @note[short] Android
     */
    void processActivatedAudioTriggers(float p0);

    /**
     * @note[short] Windows: 0x22a020
     * @note[short] Android
     */
    void processAdvancedFollowAction(AdvancedFollowInstance& p0, bool p1, float p2);

    /**
     * @note[short] Windows: 0x229e00
     * @note[short] Android
     */
    void processAdvancedFollowActions(float p0);

    /**
     * @note[short] Windows: 0x223ce0
     * @note[short] Android
     */
    void processAreaActions(float p0, bool p1);

    /**
     * @note[short] MacOS (ARM): 0x10afe8
     * @note[short] MacOS (Intel): 0x1308e0
     * @note[short] Windows: 0x223100
     * @note[short] Android
     */
    void processAreaEffects(gd::vector<EnterEffectInstance>* p0, GJAreaActionType p1, float p2, bool p3);
    
private:
    [[deprecated("GJBaseGameLayer::processAreaFadeGroupAction not implemented")]]
    /**
     * @note[short] Android
     */
    void processAreaFadeGroupAction(cocos2d::CCArray* p0, EnterEffectInstance* p1, cocos2d::CCPoint p2, bool p3);
public:

    /**
     * @note[short] MacOS (ARM): 0x10c484
     * @note[short] MacOS (Intel): 0x132070
     * @note[short] Windows: 0x2251f0
     * @note[short] Android
     */
    void processAreaMoveGroupAction(cocos2d::CCArray* p0, EnterEffectInstance* p1, cocos2d::CCPoint p2, int p3, int p4, int p5, int p6, int p7, bool p8, bool p9);

    /**
     * @note[short] Windows: 0x224ab0
     * @note[short] Android
     */
    void processAreaRotateGroupAction(cocos2d::CCArray* p0, EnterEffectInstance* p1, cocos2d::CCPoint p2, int p3, int p4, int p5, int p6, int p7, bool p8, bool p9);

    /**
     * @note[short] Windows: 0x2258c0
     * @note[short] Android
     */
    void processAreaTintGroupAction(cocos2d::CCArray* p0, EnterEffectInstance* p1, cocos2d::CCPoint p2, bool p3);

    /**
     * @note[short] Windows: 0x223f40
     * @note[short] Android
     */
    void processAreaTransformGroupAction(cocos2d::CCArray* p0, EnterEffectInstance* p1, cocos2d::CCPoint p2, int p3, int p4, int p5, int p6, int p7, bool p8, bool p9);
    
private:
    [[deprecated("GJBaseGameLayer::processAreaVisualActions not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x10d908
     * @note[short] MacOS (Intel): 0x1339e0
     * @note[short] Android
     */
    void processAreaVisualActions(float p0);
public:

    /**
     * @note[short] MacOS (ARM): 0xf2584
     * @note[short] MacOS (Intel): 0x112ba0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    GameObject* processCameraObject(GameObject* object, PlayerObject* player);

    /**
     * @note[short] MacOS (ARM): 0x11a2d0
     * @note[short] MacOS (Intel): 0x1435a0
     * @note[short] Windows: 0x234170
     * @note[short] Android
     */
    void processCommands(float p0);

    /**
     * @note[short] Windows: 0x228fa0
     * @note[short] Android
     */
    void processDynamicObjectActions(int p0, float p1);

    /**
     * @note[short] Windows: 0x22b2a0
     * @note[short] Android
     */
    void processFollowActions();
    
private:
    [[deprecated("GJBaseGameLayer::processItems not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn processItems();
public:

    /**
     * @note[short] MacOS (ARM): 0x10ffa0
     * @note[short] MacOS (Intel): 0x136810
     * @note[short] Windows: 0x2282d0
     * @note[short] Android
     */
    void processMoveActions();

    /**
     * @note[short] MacOS (ARM): 0x10e5b8
     * @note[short] MacOS (Intel): 0x1347b0
     * @note[short] Windows: 0x2262f0
     * @note[short] Android
     */
    void processMoveActionsStep(float p0, bool p1);

    /**
     * @note[short] MacOS (ARM): 0x107a5c
     * @note[short] MacOS (Intel): 0x12c930
     * @note[short] Windows: 0x21e9a0
     * @note[short] Android
     */
    void processOptionsTrigger(GameOptionsTrigger* p0);

    /**
     * @note[short] Windows: 0x228bf0
     * @note[short] Android
     */
    void processPlayerFollowActions(float p0);

    /**
     * @note[short] MacOS (Intel): 0x1491f0
     * @note[short] Windows: 0x235550
     * @note[short] Android
     */
    void processQueuedAudioTriggers();

    /**
     * @note[short] MacOS (ARM): 0x113650
     * @note[short] MacOS (Intel): 0x13af40
     * @note[short] Windows: 0x22c7f0
     * @note[short] Android
     */
    void processQueuedButtons();

    /**
     * @note[short] Windows: 0x226510
     * @note[short] Android
     */
    void processRotationActions();

    /**
     * @note[short] MacOS (Intel): 0x525060
     * @note[short] Windows: 0x23b480
     * @note[short] Android
     */
    TodoReturn processSFXObjects();
    
private:
    [[deprecated("GJBaseGameLayer::processSFXState not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn processSFXState(SFXTriggerState* p0, SFXTriggerState* p1, int p2, float p3);
public:
    
private:
    [[deprecated("GJBaseGameLayer::processSongState not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn processSongState(int p0, float p1, float p2, int p3, float p4, float p5, gd::vector<SongTriggerState>* p6, SongTriggerGameObject* p7);
public:
    
private:
    [[deprecated("GJBaseGameLayer::processStateObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn processStateObjects();
public:

    /**
     * @note[short] Windows: 0x2273a0
     * @note[short] Android
     */
    void processTransformActions(bool p0);

    /**
     * @note[short] MacOS (ARM): 0x1134ec
     * @note[short] MacOS (Intel): 0x13ad90
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void queueButton(int button, bool push, bool isPlayer2);
    
private:
    [[deprecated("GJBaseGameLayer::reAddToStickyGroup not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x12df20
     * @note[short] Android
     */
    TodoReturn reAddToStickyGroup(GameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::recordAction not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn recordAction(int p0, bool p1, bool p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::rectIntersectsCircle not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn rectIntersectsCircle(cocos2d::CCRect p0, cocos2d::CCPoint p1, float p2);
public:

    /**
     * @note[short] MacOS (Intel): 0x13dda0
     * @note[short] Windows: 0x22fe50
     * @note[short] Android
     */
    void refreshCounterLabels();
    
private:
    [[deprecated("GJBaseGameLayer::refreshKeyframeAnims not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xecb14
     * @note[short] Android
     */
    void refreshKeyframeAnims();
public:
    
private:
    [[deprecated("GJBaseGameLayer::regenerateEnterEasingBuffers not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x106590
     * @note[short] Android
     */
    TodoReturn regenerateEnterEasingBuffers();
public:
    
private:
    [[deprecated("GJBaseGameLayer::registerSpawnRemap not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn registerSpawnRemap(gd::vector<ChanceObject>& p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::registerStateObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn registerStateObject(EffectGameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::removeBackground not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn removeBackground();
public:
    
private:
    [[deprecated("GJBaseGameLayer::removeCustomEnterEffects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn removeCustomEnterEffects(int p0, bool p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::removeFromGroupParents not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x12d4c0
     * @note[short] Android
     */
    void removeFromGroupParents(GameObject* p0);
public:

    /**
     * @note[short] MacOS (Intel): 0x12ce70
     * @note[short] Windows: 0x21ed10
     * @note[short] Android
     */
    void removeFromGroups(GameObject* p0);
    
private:
    [[deprecated("GJBaseGameLayer::removeFromStickyGroup not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x12de90
     * @note[short] Android
     */
    TodoReturn removeFromStickyGroup(GameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::removeGroundLayer not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x1039d0
     * @note[short] Android
     */
    TodoReturn removeGroundLayer();
public:
    
private:
    [[deprecated("GJBaseGameLayer::removeGroupParent not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn removeGroupParent(int p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::removeKeyframe not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x13bae0
     * @note[short] Android
     */
    TodoReturn removeKeyframe(KeyframeGameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::removeMiddleground not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn removeMiddleground();
public:

    /**
     * @note[short] MacOS (ARM): 0x109388
     * @note[short] MacOS (Intel): 0x12e500
     * @note[short] Windows: 0x221a80
     * @note[short] Android
     */
    void removeObjectFromSection(GameObject* p0);
    
private:
    [[deprecated("GJBaseGameLayer::removePlayer2 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn removePlayer2();
public:
    
private:
    [[deprecated("GJBaseGameLayer::removeTemporaryParticles not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x11e718
     * @note[short] MacOS (Intel): 0x148cb0
     * @note[short] Android
     */
    TodoReturn removeTemporaryParticles();
public:
    
private:
    [[deprecated("GJBaseGameLayer::reorderObjectSection not implemented")]]
    /**
     * @note[short] Android
     */
    void reorderObjectSection(GameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::reparentObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn reparentObject(cocos2d::CCNode* p0, cocos2d::CCNode* p1);
public:

    /**
     * @note[short] MacOS (ARM): 0xed248
     * @note[short] MacOS (Intel): 0x10d800
     * @note[short] Windows: 0x209060
     * @note[short] Android
     */
    void resetActiveEnterEffects();

    /**
     * @note[short] Windows: 0x222950
     * @note[short] Android
     */
    int resetAreaObjectValues(GameObject* p0, bool p1);

    /**
     * @note[short] MacOS (ARM): 0x119004
     * @note[short] Windows: 0x231fc0
     * @note[short] Android
     */
    void resetAudio();

    /**
     * @note[short] MacOS (ARM): 0x11e7d4
     * @note[short] MacOS (Intel): 0x148d80
     * @note[short] Windows: 0x239570
     * @note[short] Android
     */
    void resetCamera();

    /**
     * @note[short] Windows: 0x21bbf0
     * @note[short] Android
     */
    void resetGradientLayers();
    
private:
    [[deprecated("GJBaseGameLayer::resetGroupCounters not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x13e800
     * @note[short] Android
     */
    TodoReturn resetGroupCounters(bool p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x11dcf0
     * @note[short] MacOS (Intel): 0x147d80
     * @note[short] Windows: 0x234ab0
     * @note[short] Android
     */
    void resetLevelVariables();
    
private:
    [[deprecated("GJBaseGameLayer::resetMoveOptimizedValue not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetMoveOptimizedValue();
public:

    /**
     * @note[short] MacOS (ARM): 0xf2608
     * @note[short] MacOS (Intel): 0x112c30
     * @note[short] Windows: 0x20cbf0
     * @note[short] Android
     */
    void resetPlayer();
    
private:
    [[deprecated("GJBaseGameLayer::resetSongTriggerValues not implemented")]]
    /**
     * @note[short] Android
     */
    void resetSongTriggerValues();
public:

    /**
     * @note[short] MacOS (ARM): 0x11ea94
     * @note[short] MacOS (Intel): 0x149100
     * @note[short] Windows: 0x23f890
     * @note[short] Android
     */
    TodoReturn resetSpawnChannelIndex();

    /**
     * @note[short] Windows: 0x239850
     * @note[short] Android
     */
    void resetStaticCamera(bool p0, bool p1);
    
private:
    [[deprecated("GJBaseGameLayer::resetStoppedAreaObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetStoppedAreaObjects();
public:
    
private:
    [[deprecated("GJBaseGameLayer::restoreAllUIObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn restoreAllUIObjects();
public:
    
private:
    [[deprecated("GJBaseGameLayer::restoreDefaultGameplayOffsetX not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn restoreDefaultGameplayOffsetX();
public:
    
private:
    [[deprecated("GJBaseGameLayer::restoreDefaultGameplayOffsetY not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn restoreDefaultGameplayOffsetY();
public:
    
private:
    [[deprecated("GJBaseGameLayer::restoreRemap not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn restoreRemap(EffectGameObject* p0, gd::unordered_map<int, int>& p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::resumeAudio not implemented")]]
    /**
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Android
     */
    void resumeAudio();
public:
    
private:
    [[deprecated("GJBaseGameLayer::rotateAreaObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn rotateAreaObjects(GameObject* p0, cocos2d::CCArray* p1, float p2, bool p3);
public:
    
private:
    [[deprecated("GJBaseGameLayer::rotateObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn rotateObject(GameObject* p0, float p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::rotateObjects not implemented")]]
    /**
     * @note[short] Android
     */
    void rotateObjects(cocos2d::CCArray* p0, float p1, cocos2d::CCPoint p2, cocos2d::CCPoint p3, bool p4, bool p5);
public:
    
private:
    [[deprecated("GJBaseGameLayer::setGroupParent not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x12d370
     * @note[short] Android
     */
    void setGroupParent(GameObject* p0, int p1);
public:

    /**
     * @note[short] MacOS (ARM): 0xf2870
     * @note[short] MacOS (Intel): 0x112ed0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void setStartPosObject(StartPosObject* startPos);

    /**
     * @note[short] MacOS (ARM): 0xe24c4
     * @note[short] MacOS (Intel): 0x1003c0
     * @note[short] Windows: 0x203760
     * @note[short] Android
     */
    void setupLayers();

    /**
     * @note[short] MacOS (ARM): 0xf28b8
     * @note[short] MacOS (Intel): 0x112f20
     * @note[short] Windows: 0x20cd60
     * @note[short] Android
     */
    void setupLevelStart(LevelSettingsObject* p0);

    /**
     * @note[short] MacOS (ARM): 0x11cd28
     * @note[short] Windows: 0x234360
     * @note[short] Android
     */
    void setupReplay(gd::string p0);

    /**
     * @note[short] Windows: 0x2356c0
     * @note[short] Android
     */
    void shakeCamera(float duration, float strength, float interval);

    /**
     * @note[short] MacOS (Intel): 0x102b90
     * @note[short] Windows: 0x205d10
     * @note[short] Android
     */
    bool shouldExitHackedLevel();
    
private:
    [[deprecated("GJBaseGameLayer::sortAllGroupsX not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn sortAllGroupsX();
public:
    
private:
    [[deprecated("GJBaseGameLayer::sortGroups not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn sortGroups();
public:

    /**
     * @note[short] MacOS (ARM): 0x10a4a8
     * @note[short] MacOS (Intel): 0x12faf0
     * @note[short] Windows: 0x221cc0
     * @note[short] Android
     */
    void sortSectionVector();
    
private:
    [[deprecated("GJBaseGameLayer::sortStickyGroups not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn sortStickyGroups();
public:
    
private:
    [[deprecated("GJBaseGameLayer::spawnGroupTriggered not implemented")]]
    /**
     * @note[short] Android
     */
    void spawnGroupTriggered(int groupID, float p1, bool p2, gd::vector<int> const& p3, int p4, int p5);
public:
    
private:
    [[deprecated("GJBaseGameLayer::spawnObjectsInOrder not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn spawnObjectsInOrder(cocos2d::CCArray* p0, double p1, gd::vector<int> const& p2, int p3, int p4);
public:

    /**
     * @note[short] MacOS (ARM): 0x120f7c
     * @note[short] MacOS (Intel): 0x14bf50
     * @note[short] Windows: 0x239d50
     * @note[short] Android
     */
    cocos2d::CCParticleSystemQuad* spawnParticle(char const* plist, int zOrder, cocos2d::tCCPositionType positionType, cocos2d::CCPoint position);
    
private:
    [[deprecated("GJBaseGameLayer::spawnParticleTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn spawnParticleTrigger(int p0, cocos2d::CCPoint p1, float p2, float p3);
public:
    
private:
    [[deprecated("GJBaseGameLayer::spawnParticleTrigger not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x118670
     * @note[short] Android
     */
    TodoReturn spawnParticleTrigger(SpawnParticleGameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::spawnPlayer2 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn spawnPlayer2();
public:

    /**
     * @note[short] Windows: 0x21e250
     * @note[short] Android
     */
    TodoReturn speedForShaderTarget(int p0);

    /**
     * @note[short] Windows: 0x20bda0
     * @note[short] Android
     */
    cocos2d::CCArray* staticObjectsInRect(cocos2d::CCRect p0, bool p1);
    
private:
    [[deprecated("GJBaseGameLayer::stopAllGroundActions not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn stopAllGroundActions();
public:
    
private:
    [[deprecated("GJBaseGameLayer::stopCameraShake not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x14a310
     * @note[short] Android
     */
    TodoReturn stopCameraShake();
public:
    
private:
    [[deprecated("GJBaseGameLayer::stopCustomEnterEffect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn stopCustomEnterEffect(EnterEffectObject* p0, bool p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::stopCustomEnterEffect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn stopCustomEnterEffect(EnterEffectObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::stopSFXTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn stopSFXTrigger(SFXTriggerGameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::swapBackground not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn swapBackground(int p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::swapGround not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn swapGround(int p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::swapMiddleground not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn swapMiddleground(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0xf3300
     * @note[short] MacOS (Intel): 0x113ad0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void switchToFlyMode(PlayerObject* player, GameObject* object, bool unused, int type);
    
private:
    [[deprecated("GJBaseGameLayer::switchToRobotMode not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x113cd0
     * @note[short] Android
     */
    void switchToRobotMode(PlayerObject* p0, GameObject* p1, bool p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::switchToRollMode not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x113c20
     * @note[short] Android
     */
    void switchToRollMode(PlayerObject* p0, GameObject* p1, bool p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::switchToSpiderMode not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xf35b0
     * @note[short] MacOS (Intel): 0x113d80
     * @note[short] Android
     */
    void switchToSpiderMode(PlayerObject* p0, GameObject* p1, bool p2);
public:

    /**
     * @note[short] MacOS (ARM): 0x11dbd8
     * @note[short] MacOS (Intel): 0x147c70
     * @note[short] Windows: 0x234a10
     * @note[short] Android
     */
    void syncBGTextures();

    /**
     * @note[short] MacOS (ARM): 0xf00d8
     * @note[short] MacOS (Intel): 0x110400
     * @note[short] Windows: 0x20aa80
     * @note[short] Android
     */
    void teleportPlayer(TeleportPortalObject* p0, PlayerObject* p1);
    
private:
    [[deprecated("GJBaseGameLayer::testInstantCountTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn testInstantCountTrigger(int p0, int p1, int p2, bool p3, int p4, gd::vector<int> const& p5, int p6, int p7);
public:

    /**
     * @note[short] MacOS (ARM): 0xe2354
     * @note[short] Windows: 0x242550
     * @note[short] Android
     */
    void toggleAudioVisualizer(bool p0);

    /**
     * @note[short] MacOS (ARM): 0xf2fe8
     * @note[short] MacOS (Intel): 0x113770
     * @note[short] Windows: 0x2113f0
     * @note[short] Android
     */
    void toggleDualMode(GameObject* p0, bool p1, PlayerObject* p2, bool p3);

    /**
     * @note[short] MacOS (ARM): 0xf6954
     * @note[short] MacOS (Intel): 0x117af0
     * @note[short] Windows: 0x240240
     * @note[short] Android
     */
    void toggleFlipped(bool p0, bool p1);
    
private:
    [[deprecated("GJBaseGameLayer::toggleGroup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1078c4
     * @note[short] Android
     */
    void toggleGroup(int p0, bool p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x107cb0
     * @note[short] MacOS (Intel): 0x12cbe0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void toggleLockPlayer(bool disable, bool p2);
    
private:
    [[deprecated("GJBaseGameLayer::togglePlayerStreakBlend not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x107c3c
     * @note[short] MacOS (Intel): 0x12cb50
     * @note[short] Android
     */
    void togglePlayerStreakBlend(bool p0);
public:

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void togglePlayerVisibility(bool visible, bool player1);

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void togglePlayerVisibility(bool visible);
    
private:
    [[deprecated("GJBaseGameLayer::transformAreaObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn transformAreaObjects(GameObject* p0, cocos2d::CCArray* p1, float p2, float p3, bool p4);
public:
    
private:
    [[deprecated("GJBaseGameLayer::triggerAdvancedFollowCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn triggerAdvancedFollowCommand(AdvancedFollowTriggerObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::triggerAdvancedFollowEditCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn triggerAdvancedFollowEditCommand(AdvancedFollowEditObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::triggerAreaEffect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn triggerAreaEffect(EnterEffectObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::triggerAreaEffectAnimation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn triggerAreaEffectAnimation(EnterEffectObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::triggerDynamicMoveCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn triggerDynamicMoveCommand(EffectGameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::triggerDynamicRotateCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn triggerDynamicRotateCommand(EnhancedTriggerObject* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x104294
     * @note[short] MacOS (Intel): 0x128bc0
     * @note[short] Windows: 0x21a3a0
     * @note[short] Android
     */
    TodoReturn triggerGradientCommand(GradientTriggerObject* p0);
    
private:
    [[deprecated("GJBaseGameLayer::triggerGravityChange not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn triggerGravityChange(EffectGameObject* p0, int p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::triggerMoveCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn triggerMoveCommand(EffectGameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::triggerRotateCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn triggerRotateCommand(EnhancedTriggerObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::triggerShaderCommand not implemented")]]
    /**
     * @note[short] Android
     */
    bool triggerShaderCommand(ShaderGameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::triggerTransformCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn triggerTransformCommand(TransformTriggerGameObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::tryGetGroupParent not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn tryGetGroupParent(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0xf8cc4
     * @note[short] MacOS (Intel): 0x11a040
     * @note[short] Windows: 0x21f170
     * @note[short] Android
     */
    GameObject* tryGetMainObject(int p0);

    /**
     * @note[short] Windows: 0x21f1e0
     * @note[short] Android
     */
    TodoReturn tryGetObject(int p0);
    
private:
    [[deprecated("GJBaseGameLayer::tryResumeAudio not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x141e80
     * @note[short] Android
     */
    TodoReturn tryResumeAudio();
public:
    
private:
    [[deprecated("GJBaseGameLayer::unclaimParticle not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn unclaimParticle(char const* p0, cocos2d::CCParticleSystemQuad* p1);
public:

    /**
     * @note[short] MacOS (Intel): 0x12dcc0
     * @note[short] Windows: 0x21f8d0
     * @note[short] Android
     */
    void ungroupStickyObjects(cocos2d::CCArray* p0);
    
private:
    [[deprecated("GJBaseGameLayer::unlinkAllEvents not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn unlinkAllEvents();
public:
    
private:
    [[deprecated("GJBaseGameLayer::updateActiveEnterEffect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateActiveEnterEffect(EnterEffectObject* p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::updateAllObjectSection not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateAllObjectSection();
public:
    
private:
    [[deprecated("GJBaseGameLayer::updateAreaObjectLastValues not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateAreaObjectLastValues(GameObject* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x11a1b0
     * @note[short] MacOS (Intel): 0x143430
     * @note[short] Windows: 0x2422f0
     * @note[short] Android
     */
    void updateAudioVisualizer();
    
private:
    [[deprecated("GJBaseGameLayer::updateBGArtSpeed not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x11e5e0
     * @note[short] Android
     */
    void updateBGArtSpeed(float p0, float p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x11a738
     * @note[short] MacOS (Intel): 0x143a60
     * @note[short] Windows: 0x235760
     * @note[short] Android
     */
    void updateCamera(float p0);
    
private:
    [[deprecated("GJBaseGameLayer::updateCameraBGArt not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x14a5c0
     * @note[short] Android
     */
    TodoReturn updateCameraBGArt(cocos2d::CCPoint p0, float p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::updateCameraEdge not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateCameraEdge(int p0, int p1);
public:

    /**
     * @note[short] MacOS (Intel): 0x114180
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void updateCameraMode(EffectGameObject* obj, bool updateDual);

    /**
     * @note[short] MacOS (Intel): 0x13f3e0
     * @note[short] Windows: 0x230810
     * @note[short] Android
     */
    void updateCameraOffsetX(float p0, float p1, int p2, float p3, int p4, int p5);

    /**
     * @note[short] MacOS (Intel): 0x13f4e0
     * @note[short] Windows: 0x2308b0
     * @note[short] Android
     */
    void updateCameraOffsetY(float p0, float p1, int p2, float p3, int p4, int p5);
    
private:
    [[deprecated("GJBaseGameLayer::updateCollisionBlocks not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x11a8b0
     * @note[short] Android
     */
    void updateCollisionBlocks();
public:

    /**
     * @note[short] MacOS (ARM): 0x114398
     * @note[short] MacOS (Intel): 0x13bd80
     * @note[short] Windows: 0x22e760
     * @note[short] Android
     */
    void updateCounters(int p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0xf365c
     * @note[short] MacOS (Intel): 0x113e30
     * @note[short] Windows: 0x20dcc0
     * @note[short] Android
     */
    void updateDualGround(PlayerObject* p0, int p1, bool p2, float p3);
    
private:
    [[deprecated("GJBaseGameLayer::updateEnterEffects not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xedfd4
     * @note[short] MacOS (Intel): 0x10e8e0
     * @note[short] Android
     */
    void updateEnterEffects(float p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::updateExtendedCollision not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateExtendedCollision(GameObject* p0, bool p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::updateExtraGameLayers not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x12c410
     * @note[short] Android
     */
    TodoReturn updateExtraGameLayers();
public:
    
private:
    [[deprecated("GJBaseGameLayer::updateGameplayOffsetX not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateGameplayOffsetX(int p0, bool p1);
public:
    
private:
    [[deprecated("GJBaseGameLayer::updateGameplayOffsetY not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateGameplayOffsetY(int p0, bool p1);
public:

    /**
     * @note[short] MacOS (Intel): 0x129310
     * @note[short] Windows: 0x21a830
     * @note[short] Android
     */
    TodoReturn updateGradientLayers();
    
private:
    [[deprecated("GJBaseGameLayer::updateGroundShadows not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateGroundShadows();
public:

    /**
     * @note[short] Windows: 0x240130
     * @note[short] Android
     */
    TodoReturn updateGuideArt();
    
private:
    [[deprecated("GJBaseGameLayer::updateInternalCamOffsetX not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateInternalCamOffsetX(float p0, float p1, float p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::updateInternalCamOffsetY not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateInternalCamOffsetY(float p0, float p1, float p2);
public:
    
private:
    [[deprecated("GJBaseGameLayer::updateKeyframeOrder not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x11403c
     * @note[short] MacOS (Intel): 0x13b9d0
     * @note[short] Android
     */
    void updateKeyframeOrder(int p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::updateLayerCapacity not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateLayerCapacity(gd::string p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::updateLegacyLayerCapacity not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateLegacyLayerCapacity(int p0, int p1, int p2, int p3);
public:

    /**
     * @note[short] MacOS (ARM): 0xe5144
     * @note[short] MacOS (Intel): 0x103350
     * @note[short] Windows: 0x207150
     * @note[short] Android
     */
    void updateLevelColors();

    /**
     * @note[short] MacOS (Intel): 0x147b20
     * @note[short] Windows: 0x234930
     * @note[short] Android
     */
    void updateMaxGameplayY();
    
private:
    [[deprecated("GJBaseGameLayer::updateMGArtSpeed not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateMGArtSpeed(float p0, float p1);
public:

    /**
     * @note[short] Windows: 0x230950
     * @note[short] Android
     */
    void updateMGOffsetY(float p0, float p1, int p2, float p3, int p4, int p5);

    /**
     * @note[short] Windows: 0x6da50
     * @note[short] Android
     */
    TodoReturn updateOBB2(cocos2d::CCRect p0);
    
private:
    [[deprecated("GJBaseGameLayer::updateParticles not implemented")]]
    /**
     * @note[short] Android
     */
    void updateParticles(float p0);
public:
    
private:
    [[deprecated("GJBaseGameLayer::updatePlatformerTime not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updatePlatformerTime();
public:
    
private:
    [[deprecated("GJBaseGameLayer::updatePlayerCollisionBlocks not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updatePlayerCollisionBlocks();
public:

    /**
     * @note[short] MacOS (ARM): 0x11c754
     * @note[short] MacOS (Intel): 0x1465c0
     * @note[short] Windows: 0x23bd90
     * @note[short] Android
     */
    void updateProximityVolumeEffects();
    
private:
    [[deprecated("GJBaseGameLayer::updateQueuedLabels not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateQueuedLabels();
public:
    
private:
    [[deprecated("GJBaseGameLayer::updateReplay not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateReplay();
public:
    
private:
    [[deprecated("GJBaseGameLayer::updateSavePositionObjects not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x11b8b0
     * @note[short] Android
     */
    TodoReturn updateSavePositionObjects();
public:

    /**
     * @note[short] MacOS (ARM): 0x1060a8
     * @note[short] MacOS (Intel): 0x12b040
     * @note[short] Windows: 0x21cf00
     * @note[short] Android
     */
    void updateShaderLayer(float p0);

    /**
     * @note[short] MacOS (Intel): 0x106390
     * @note[short] Windows: 0x208c00
     * @note[short] Android
     */
    void updateSpecialGroupData();

    /**
     * @note[short] Windows: 0x2338f0
     * @note[short] Android
     */
    TodoReturn updateSpecialLabels();

    /**
     * @note[short] MacOS (ARM): 0xf40c8
     * @note[short] MacOS (Intel): 0x114990
     * @note[short] Windows: 0x238ca0
     * @note[short] Android
     */
    void updateStaticCameraPos(cocos2d::CCPoint pos, bool staticX, bool staticY, bool followOrSmoothEase, float time, int easingType, float easingRate);

    /**
     * @note[short] Windows: 0x2388b0
     * @note[short] Android
     */
    TodoReturn updateStaticCameraPosToGroup(int p0, bool p1, bool p2, bool p3, float p4, float p5, int p6, float p7, bool p8, float p9);
    
private:
    [[deprecated("GJBaseGameLayer::updateTimeMod not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTimeMod(float p0, bool p1, bool p2);
public:

    /**
     * @note[short] Windows: 0x22fae0
     * @note[short] Android
     */
    TodoReturn updateTimerLabels();

    /**
     * @note[short] MacOS (Intel): 0x13f010
     * @note[short] Windows: 0x230590
     * @note[short] Android
     */
    void updateZoom(float p0, float p1, int p2, float p3, int p4, int p5);
    
private:
    [[deprecated("GJBaseGameLayer::visitWithColorFlash not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn visitWithColorFlash();
public:

    /**
     * @note[short] Windows: 0x23c060
     * @note[short] Android
     */
    TodoReturn volumeForProximityEffect(SFXTriggerInstance& p0);
    GEODE_PAD(8);
    GJGameState m_gameState;
    GJGameLevel* m_level;
    PlaybackMode m_playbackMode;
    bool m_decimalPercentage;
    bool m_extraLDM;
    bool m_0173;
    bool m_enable22Changes;
    bool m_allowStaticRotate;
    bool m_fixNegativeScale;
    bool m_startingFromBeginning;
    gd::vector<gd::vector<int>*> m_field_8B0;
    gd::vector<int> m_unkVectorTypeIsWrong;
    cocos2d::CCNode* m_field_8E0;
    cocos2d::CCNode* m_field_8E8;
    cocos2d::CCNode* m_field_8F0;
    cocos2d::CCNode* m_field_8F8;
    cocos2d::CCNode* m_field_900;
    cocos2d::CCNode* m_field_908;
    OBB2D* m_obb2;
    gd::vector<gd::unordered_map<int,int>> m_spawnRemapTriggers;
    gd::unordered_map<int, cocos2d::CCPoint> m_umapIntCCPoint;
    GJEffectManager* m_effectManager;
    cocos2d::CCSpriteBatchNode* m_unk950;
    cocos2d::CCSpriteBatchNode* m_unk958;
    cocos2d::CCSpriteBatchNode* m_unk960;
    cocos2d::CCSpriteBatchNode* m_unk968;
    cocos2d::CCSpriteBatchNode* m_unk970;
    cocos2d::CCSpriteBatchNode* m_unk978;
    cocos2d::CCSpriteBatchNode* m_unk980;
    cocos2d::CCSpriteBatchNode* m_unk988;
    CCNodeContainer* m_unk990;
    cocos2d::CCSpriteBatchNode* m_unk998;
    cocos2d::CCSpriteBatchNode* m_unk9a0;
    cocos2d::CCSpriteBatchNode* m_unk9a8;
    cocos2d::CCSpriteBatchNode* m_unk9b0;
    cocos2d::CCSpriteBatchNode* m_unk9b8;
    cocos2d::CCSpriteBatchNode* m_unk9c0;
    cocos2d::CCSpriteBatchNode* m_unk9c8;
    cocos2d::CCSpriteBatchNode* m_unk9d0;
    cocos2d::CCSpriteBatchNode* m_unk9d8;
    cocos2d::CCSpriteBatchNode* m_unk9e0;
    cocos2d::CCSpriteBatchNode* m_unk9e8;
    cocos2d::CCSpriteBatchNode* m_unk9f0;
    cocos2d::CCSpriteBatchNode* m_unk9f8;
    CCNodeContainer* m_unka00;
    cocos2d::CCSpriteBatchNode* m_unka08;
    cocos2d::CCSpriteBatchNode* m_unka10;
    cocos2d::CCSpriteBatchNode* m_unka18;
    cocos2d::CCSpriteBatchNode* m_unka20;
    cocos2d::CCSpriteBatchNode* m_unka28;
    cocos2d::CCSpriteBatchNode* m_unka30;
    cocos2d::CCSpriteBatchNode* m_unka38;
    cocos2d::CCSpriteBatchNode* m_unka40;
    cocos2d::CCSpriteBatchNode* m_unka48;
    cocos2d::CCSpriteBatchNode* m_unka50;
    cocos2d::CCSpriteBatchNode* m_unka58;
    cocos2d::CCSpriteBatchNode* m_unka60;
    cocos2d::CCSpriteBatchNode* m_unka68;
    CCNodeContainer* m_unka70;
    cocos2d::CCSpriteBatchNode* m_unka78;
    cocos2d::CCSpriteBatchNode* m_unka80;
    cocos2d::CCSpriteBatchNode* m_unka88;
    cocos2d::CCSpriteBatchNode* m_unka90;
    cocos2d::CCSpriteBatchNode* m_unka98;
    cocos2d::CCSpriteBatchNode* m_unkaa0;
    cocos2d::CCSpriteBatchNode* m_unkaa8;
    cocos2d::CCSpriteBatchNode* m_unkab0;
    cocos2d::CCSpriteBatchNode* m_unkab8;
    cocos2d::CCSpriteBatchNode* m_unkac0;
    cocos2d::CCSpriteBatchNode* m_unkac8;
    cocos2d::CCSpriteBatchNode* m_unkad0;
    cocos2d::CCSpriteBatchNode* m_unkad8;
    CCNodeContainer* m_unkae0;
    cocos2d::CCSpriteBatchNode* m_unkae8;
    cocos2d::CCSpriteBatchNode* m_unkaf0;
    cocos2d::CCSpriteBatchNode* m_unkaf8;
    cocos2d::CCSpriteBatchNode* m_unkb00;
    cocos2d::CCSpriteBatchNode* m_unkb08;
    cocos2d::CCSpriteBatchNode* m_unkb10;
    cocos2d::CCSpriteBatchNode* m_unkb18;
    cocos2d::CCSpriteBatchNode* m_unkb20;
    cocos2d::CCSpriteBatchNode* m_unkb28;
    cocos2d::CCSpriteBatchNode* m_unkb30;
    cocos2d::CCSpriteBatchNode* m_unkb38;
    cocos2d::CCSpriteBatchNode* m_unkb40;
    cocos2d::CCSpriteBatchNode* m_unkb48;
    cocos2d::CCSpriteBatchNode* m_unkb50;
    void* m_unkb5c;
    cocos2d::CCSpriteBatchNode* m_unkb60;
    cocos2d::CCSpriteBatchNode* m_unkb68;
    cocos2d::CCSpriteBatchNode* m_unkb70;
    cocos2d::CCSpriteBatchNode* m_unkb78;
    CCNodeContainer* m_unkb80;
    cocos2d::CCSpriteBatchNode* m_unkb88;
    cocos2d::CCSpriteBatchNode* m_unkb90;
    cocos2d::CCSpriteBatchNode* m_unkb98;
    cocos2d::CCSpriteBatchNode* m_unkba0;
    cocos2d::CCSpriteBatchNode* m_unkba8;
    cocos2d::CCSpriteBatchNode* m_unkbb0;
    cocos2d::CCSpriteBatchNode* m_unkbb8;
    cocos2d::CCSpriteBatchNode* m_unkbc0;
    cocos2d::CCSpriteBatchNode* m_unkbc8;
    cocos2d::CCSpriteBatchNode* m_unkbd0;
    cocos2d::CCSpriteBatchNode* m_unkbd8;
    cocos2d::CCSpriteBatchNode* m_unkbe0;
    cocos2d::CCSpriteBatchNode* m_unkbe8;
    CCNodeContainer* m_unkbf0;
    cocos2d::CCSpriteBatchNode* m_unkbf8;
    cocos2d::CCSpriteBatchNode* m_unkc00;
    cocos2d::CCSpriteBatchNode* m_unkc08;
    cocos2d::CCSpriteBatchNode* m_unkc10;
    cocos2d::CCSpriteBatchNode* m_unkc18;
    cocos2d::CCSpriteBatchNode* m_unkc20;
    cocos2d::CCSpriteBatchNode* m_unkc28;
    cocos2d::CCSpriteBatchNode* m_unkc30;
    cocos2d::CCSpriteBatchNode* m_unkc38;
    cocos2d::CCSpriteBatchNode* m_unkc40;
    cocos2d::CCSpriteBatchNode* m_unkc48;
    cocos2d::CCSpriteBatchNode* m_unkc50;
    cocos2d::CCSpriteBatchNode* m_unkc58;
    CCNodeContainer* m_unkc60;
    cocos2d::CCSpriteBatchNode* m_unkc68;
    cocos2d::CCSpriteBatchNode* m_unkc70;
    cocos2d::CCSpriteBatchNode* m_unkc78;
    cocos2d::CCSpriteBatchNode* m_unkc80;
    cocos2d::CCSpriteBatchNode* m_unkc88;
    cocos2d::CCSpriteBatchNode* m_unkc90;
    cocos2d::CCSpriteBatchNode* m_unkc98;
    cocos2d::CCSpriteBatchNode* m_unkca0;
    cocos2d::CCSpriteBatchNode* m_unkca8;
    cocos2d::CCSpriteBatchNode* m_unkcb0;
    cocos2d::CCSpriteBatchNode* m_unkcb8;
    cocos2d::CCSpriteBatchNode* m_unkcc0;
    cocos2d::CCSpriteBatchNode* m_unkcc8;
    CCNodeContainer* m_unkcd0;
    cocos2d::CCSpriteBatchNode* m_unkcd8;
    cocos2d::CCSpriteBatchNode* m_unkce0;
    cocos2d::CCSpriteBatchNode* m_unkce8;
    cocos2d::CCSpriteBatchNode* m_unkcf0;
    cocos2d::CCSpriteBatchNode* m_unkcf8;
    cocos2d::CCSpriteBatchNode* m_unkd00;
    cocos2d::CCSpriteBatchNode* m_unkd08;
    cocos2d::CCSpriteBatchNode* m_unkd10;
    cocos2d::CCSpriteBatchNode* m_unkd18;
    cocos2d::CCSpriteBatchNode* m_unkd20;
    cocos2d::CCSpriteBatchNode* m_unkd28;
    cocos2d::CCSpriteBatchNode* m_unkd30;
    cocos2d::CCSpriteBatchNode* m_unkd38;
    CCNodeContainer* m_unkd40;
    cocos2d::CCSpriteBatchNode* m_unkd48;
    cocos2d::CCSpriteBatchNode* m_unkd50;
    cocos2d::CCSpriteBatchNode* m_unkd58;
    cocos2d::CCSpriteBatchNode* m_unkd60;
    cocos2d::CCSpriteBatchNode* m_unkd68;
    cocos2d::CCSpriteBatchNode* m_unkd70;
    cocos2d::CCSpriteBatchNode* m_unkd78;
    cocos2d::CCSpriteBatchNode* m_unkd80;
    cocos2d::CCSpriteBatchNode* m_unkd88;
    cocos2d::CCSpriteBatchNode* m_unkd90;
    PlayerObject* m_player1;
    PlayerObject* m_player2;
    LevelSettingsObject* m_levelSettings;
    cocos2d::CCArray* m_objects;
    cocos2d::CCArray* m_unknownCB0;
    cocos2d::CCArray* m_unknownCB8;
    cocos2d::CCDictionary* m_unknownCC0;
    cocos2d::CCNode* m_unknownCC8;
    gd::vector<GameObject*> m_unkdd8;
    gd::vector<GameObject*> m_unkdf0;
    gd::vector<GameObject*> m_unke08;
    gd::vector<GameObject*> m_unke20;
    gd::vector<GameObject*> m_unke38;
    gd::unordered_map<int, gd::vector<GameObject*>> m_unke50;
    gd::vector<GameObject*> m_unke90;
    int m_unkea8;
    int m_unkeac;
    gd::vector<GameObject*> m_unkeb0;
    int m_unkec8;
    int m_unkecc;
    int m_unked0;
    int m_unked4;
    int m_unked8;
    int m_unkedc;
    int m_unkee0;
    int m_unkee4;
    int m_unkee8;
    int m_unkeec;
    int m_unkef0;
    int m_unkef4;
    cocos2d::CCDictionary* m_groupDict;
    cocos2d::CCDictionary* m_staticGroupDict;
    cocos2d::CCDictionary* m_optimizedGroupDict;
    gd::vector<cocos2d::CCArray*> m_groups;
    gd::vector<cocos2d::CCArray*> m_staticGroups;
    gd::vector<cocos2d::CCArray*> m_optimizedGroups;
    cocos2d::CCDictionary* m_unknownE38;
    cocos2d::CCDictionary* m_unknownE40;
    cocos2d::CCDictionary* m_unknownE48;
    cocos2d::CCArray* m_unknownE50;
    gd::unordered_map<int, std::pair<int, int>> m_unknownE58;
    cocos2d::CCDictionary* m_linkedGroupDict;
    int m_lastUsedLinkedID;
    cocos2d::CCNode* m_unknownE90;
    cocos2d::CCNode* m_unknownE98;
    cocos2d::CCNode* m_unknownEA0;
    cocos2d::CCLayer* m_objectLayer;
    cocos2d::CCLayer* m_unkff8;
    cocos2d::CCLayer* m_unk1000;
    cocos2d::CCSprite* m_unk1008;
    void* m_unk1010;
    GJGroundLayer* m_groundLayer;
    GJGroundLayer* m_groundLayer2;
    GJMGLayer* m_middleground;
    cocos2d::CCArray* m_batchNodes;
    cocos2d::CCDictionary* m_unk1038;
    gd::unordered_map<int, gd::vector<LabelGameObject*>> m_umapIntVectorLabelGameObjectPtr;
    gd::unordered_map<int, gd::vector<LabelGameObject*>> m_umapIntVectorLabelGameObjectPtr2;
    gd::map<std::pair<int, int>, int> m_mapTupleIntIntIntTupleIntIntInt;
    bool m_increasedLayerCapacity;
    std::array<float, 2000> m_massiveFloatArray;
    gd::map<std::pair<int, int>, int> m_mapPairIntIntPairFloatFloat;
    gd::vector<float> field_3058;
    gd::unordered_map<int, int> m_umapIntInt3;
    int m_easingRelated;
    bool field_30AC;
    int m_clicks;
    int m_attempts;
    bool m_bUnk30b8;
    int m_leftSectionIndex;
    int m_rightSectionIndex;
    int m_bottomSectionIndex;
    int m_topSectionIndex;
    bool m_superHighGraphics;
    bool m_blending;
    bool m_isPlatformer;
    GameObject* m_player1CollisionBlock;
    GameObject* m_player2CollisionBlock;
    int m_particleCount;
    int m_customParticleCount;
    int m_particleSystemLimit;
    cocos2d::CCDictionary* m_particlesDict;
    cocos2d::CCDictionary* m_customParticles;
    cocos2d::CCArray* m_unclaimedParticles;
    gd::unordered_map<int, gd::string> m_particleCountToParticleString;
    cocos2d::CCDictionary* m_claimedParticles;
    cocos2d::CCArray* m_temporaryParticles;
    gd::unordered_set<int> m_customParticlesUIDs;
    cocos2d::CCDictionary* m_gradientLayers;
    int m_activeGradients;
    ShaderLayer* m_shaderLayer;
    bool m_bUnk31a0;
    bool m_bUnk31a1;
    StartPosObject* m_startPosObject;
    bool m_unk3188;
    int m_unk318c;
    int m_unk3190;
    gd::vector<GameObject*> m_unk3198;
    int m_unk31b0;
    int m_unk31b4;
    gd::vector<GameObject*> m_unk31b8;
    gd::vector<GameObject*> m_unk31d0;
    bool m_isPracticeMode;
    bool m_practiceMusicSync;
    float m_loadingProgress;
    cocos2d::CCNode* m_unk2a84;
    int m_unk2a88;
    float m_unk2a8c;
    int m_unk2a90;
    int m_unk2a94;
    int m_unk2a98;
    cocos2d::CCDictionary* m_collectedItems;
    float m_levelLength;
    int m_unk2aa4;
    EndPortalObject* m_endPortal;
    bool m_isTestMode;
    bool m_unk3089;
    bool m_unk308a;
    int m_unk322c;
    int m_unk3230;
    bool m_unk3234;
    cocos2d::CCParticleSystemQuad* m_unk3238;
    bool m_unk3240;
    bool m_unk3241;
    bool m_unk3242;
    double m_extraDelta;
    bool m_started;
    bool m_unk3251;
    float m_unk3254;
    float m_unk3258;
    float m_unk325c;
    float m_unk3260;
    AudioEffectsLayer* m_audioEffectsLayer;
    OBB2D* m_unk3270;
    gd::vector<GameObject*> m_unk3278;
    int m_activeObjects;
    int m_unk3294;
    cocos2d::ccColor3B m_unk3298;
    int m_resumeTimer;
    bool m_unk32a0;
    int m_unk32a4;
    gd::string m_unk32a8;
    cocos2d::CCObject* m_unk32c8;
    int m_unk32d0;
    double m_unk32d8;
    int m_coinsCollected;
    int m_unk32e4;
    int m_replayRandSeed;
    int m_unk32ec;
    int m_unk32f0;
    gd::vector<PlayerButtonCommand> m_queuedButtons;
    gd::vector<PlayerButtonCommand> m_queuedButtons2;
    gd::vector<PlayerButtonCommand> m_queuedButtons3;
    gd::vector<PlayerButtonCommand> m_queuedButtons4;
    gd::vector<PlayerButtonCommand> m_queuedButtons5;
    int m_someQueuedButtonSize;
    bool m_unk3374;
    bool m_unk3375;
    cocos2d::CCArray* m_unk3378;
    float m_unk3380;
    gd::vector<int> m_unk3388;
    gd::vector<int> m_unk33a0;
    bool m_unk33b8;
    cocos2d::CCArray* m_unk33c0;
    cocos2d::CCArray* m_unk33c8;
    gd::unordered_map<int, int> m_unk33d0;
    gd::unordered_map<int, int> m_unk3410;
    bool m_unk3450;
    cocos2d::CCDictionary* m_unk3458;
    int m_unk3460;
    UILayer* m_uiLayer;
    cocos2d::CCArray* m_unk3470;
    cocos2d::CCDictionary* m_unk3478;
    cocos2d::CCNode* m_unk3480;
    double m_timePlayed;
    bool m_levelEndAnimationStarted;
    int m_unknown3494;
    gd::string m_pointsString;
    gd::vector<gd::vector<gd::vector<GameObject*>*>*> m_sections;
    gd::vector<gd::vector<gd::vector<GameObject*>*>*> m_nonEffectObjects;
    gd::vector<gd::vector<GameObject*>*> m_collisionBlockSections;
    gd::vector<GameObject*> m_calcNonEffectObjects;
    int m_calcNonEffectObjectsSize;
    gd::vector<GameObject*> m_calcCollisionBlockObjects;
    int m_calcCollisionBlockObjectsSize;
    gd::vector<GameObject*> m_calcCollisionBlockObjects2;
    int m_calcCollisionBlockObjects2Size;
    gd::vector<gd::vector<int>*> m_sectionSizes;
    gd::vector<gd::vector<int>*> m_nonEffectObjectsSizes;
    gd::vector<gd::vector<int>*> m_collisionBlockSectionSizes;
    gd::vector<gd::vector<bool>*> m_nonEffectObjectsFlags;
    float m_unknown35c0;
    float m_unknown35c4;
    float m_unknown35c8;
    float m_unknown35cc;
    gd::unordered_map<int, int> m_stickyGroups;
    FMODLevelVisualizer* m_audioVisualizerBG;
    FMODLevelVisualizer* m_audioVisualizerSFX;
    bool m_showAudioVisualizer;
    int m_areaMovedCount;
    int m_areaScaledCount;
    int m_areaRotatedCount;
    int m_areaColorCount;
    int m_areaMovedCountTotal;
    int m_areaScaledCountTotal;
    int m_areaRotatedCountTotal;
    int m_areaColorCountTotal;
    int m_movedCount;
    int m_scaledCount;
    int m_rotatedCount;
    int m_followedCount;
    int m_areaMovedCountDisplay;
    int m_areaScaledCountDisplay;
    int m_areaRotatedCountDisplay;
    int m_areaColorCountDisplay;
    int m_areaMovedCountTotalDisplay;
    int m_areaScaledCountTotalDisplay;
    int m_areaRotatedCountTotalDisplay;
    int m_areaColorCountTotalDisplay;
    int m_movedCountDisplay;
    int m_scaledCountDisplay;
    int m_rotatedCountDisplay;
    int m_followedCountDisplay;
    int m_unknown3684;
    GJGameLoadingLayer* m_loadingLayer;
    cocos2d::CCDrawNode* m_debugDrawNode;
    void* m_unk3678;
    bool m_isDebugDrawEnabled;
    bool m_unk3501;
    GameObject* m_anticheatSpike;
};
