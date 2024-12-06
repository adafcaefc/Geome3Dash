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
#include "CCCircleWaveDelegate.hpp"
#include "CurrencyRewardDelegate.hpp"
#include "DialogDelegate.hpp"

class PlayLayer : public GJBaseGameLayer, public CCCircleWaveDelegate, public CurrencyRewardDelegate, public DialogDelegate {
public:
    static constexpr auto CLASS_NAME = "PlayLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(PlayLayer, GJBaseGameLayer)

    /**
     * @note[short] MacOS (Intel): 0xab980
     * @note[short] Windows: 0x38e920
     * @note[short] Android
     */
    virtual  ~PlayLayer();
    
private:
    [[deprecated("PlayLayer::create not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x9ccd0
     * @note[short] MacOS (Intel): 0xabda0
     * @note[short] Android
     */
    static PlayLayer* create(GJGameLevel* level, bool useReplay, bool dontCreateObjects);
public:

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    static PlayLayer* get();

    /**
     * @note[short] MacOS (ARM): 0x9cc10
     * @note[short] MacOS (Intel): 0xabcf0
     * @note[short] Windows: 0x38ebc0
     * @note[short] Android
     */
    static cocos2d::CCScene* scene(GJGameLevel* level, bool useReplay, bool dontCreateObjects);

    /**
     * @note[short] MacOS (ARM): 0xae0cc
     * @note[short] MacOS (Intel): 0xbf710
     * @note[short] Windows: 0x3a4190
     * @note[short] iOS: 0x125f5c
     * @note[short] Android
     */
    virtual void onEnterTransitionDidFinish();

    /**
     * @note[short] MacOS (ARM): 0xae110
     * @note[short] MacOS (Intel): 0xbf740
     * @note[short] Windows: 0x3a41c0
     * @note[short] iOS: 0x125f90
     * @note[short] Android
     */
    virtual void onExit();

    /**
     * @note[short] MacOS (ARM): 0xaaab0
     * @note[short] MacOS (Intel): 0xbb760
     * @note[short] Windows: 0x39da60
     * @note[short] iOS: 0x123060
     * @note[short] Android
     */
    virtual void postUpdate(float p0);

    /**
     * @note[short] MacOS (ARM): 0xaad98
     * @note[short] MacOS (Intel): 0xbba90
     * @note[short] Windows: 0x39de30
     * @note[short] iOS: 0x123338
     * @note[short] Android
     */
    virtual TodoReturn checkForEnd();
    
private:
    [[deprecated("PlayLayer::testTime not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual TodoReturn testTime();
public:

    /**
     * @note[short] MacOS (ARM): 0xaae94
     * @note[short] MacOS (Intel): 0xbbb80
     * @note[short] Windows: 0x39e000
     * @note[short] iOS: 0x123420
     * @note[short] Android
     */
    virtual void updateVerifyDamage();

    /**
     * @note[short] MacOS (ARM): 0xaaf9c
     * @note[short] MacOS (Intel): 0xbbc70
     * @note[short] Windows: 0x39e0f0
     * @note[short] iOS: 0x123510
     * @note[short] Android
     */
    virtual void updateAttemptTime(float p0);

    /**
     * @note[short] MacOS (ARM): 0xa75f0
     * @note[short] MacOS (Intel): 0xb7ab0
     * @note[short] Windows: 0x3984e0
     * @note[short] iOS: 0x120198
     * @note[short] Android
     */
    virtual void updateVisibility(float p0);

    /**
     * @note[short] MacOS (ARM): 0xa9384
     * @note[short] MacOS (Intel): 0xb9de0
     * @note[short] Windows: 0x399410
     * @note[short] iOS: 0x121be8
     * @note[short] Android
     */
    virtual TodoReturn opacityForObject(GameObject* p0);

    /**
     * @note[short] MacOS (ARM): 0xa9448
     * @note[short] MacOS (Intel): 0xb9ec0
     * @note[short] Windows: 0x39b0c0
     * @note[short] iOS: 0x121c58
     * @note[short] Android
     */
    virtual void updateColor(cocos2d::ccColor3B& color, float fadeTime, int colorID, bool blending, float opacity, cocos2d::ccHSVValue& copyHSV, int colorIDToCopy, bool copyOpacity, EffectGameObject* callerObject, int unk1, int unk2);
    
private:
    [[deprecated("PlayLayer::activateEndTrigger not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xa6648
     * @note[short] MacOS (Intel): 0xb69f0
     * @note[short] iOS: 0x11f5dc
     * @note[short] Android
     */
    virtual TodoReturn activateEndTrigger(int p0, bool p1, bool p2);
public:

    /**
     * @note[short] MacOS (ARM): 0xa6a7c
     * @note[short] MacOS (Intel): 0xb6ec0
     * @note[short] Windows: 0x395320
     * @note[short] iOS: 0x11f8f4
     * @note[short] Android
     */
    virtual void activatePlatformerEndTrigger(EndTriggerGameObject* p0, gd::vector<int> const& p1);

    /**
     * @note[short] MacOS (ARM): 0xa9eb4
     * @note[short] MacOS (Intel): 0xba9a0
     * @note[short] Windows: 0x39c9d0
     * @note[short] iOS: 0x1225ec
     * @note[short] Android
     */
    virtual void toggleGlitter(bool p0);

    /**
     * @note[short] MacOS (ARM): 0xa9f8c
     * @note[short] MacOS (Intel): 0xbaa60
     * @note[short] Windows: 0x39caf0
     * @note[short] iOS: 0x122650
     * @note[short] Android
     */
    virtual void destroyPlayer(PlayerObject* p0, GameObject* p1);

    /**
     * @note[short] MacOS (ARM): 0xa9dc8
     * @note[short] MacOS (Intel): 0xba8b0
     * @note[short] Windows: 0x39c820
     * @note[short] iOS: 0x122508
     * @note[short] Android
     */
    virtual TodoReturn toggleGroundVisibility(bool p0);

    /**
     * @note[short] MacOS (ARM): 0xa9df8
     * @note[short] MacOS (Intel): 0xba8e0
     * @note[short] Windows: 0x39c8a0
     * @note[short] iOS: 0x122538
     * @note[short] Android
     */
    virtual void toggleMGVisibility(bool p0);

    /**
     * @note[short] MacOS (ARM): 0xa9e08
     * @note[short] MacOS (Intel): 0xba900
     * @note[short] Windows: 0x39c8e0
     * @note[short] iOS: 0x122548
     * @note[short] Android
     */
    virtual void toggleHideAttempts(bool p0);

    /**
     * @note[short] MacOS (ARM): 0xa9cf8
     * @note[short] MacOS (Intel): 0xba790
     * @note[short] Windows: 0x39c6f0
     * @note[short] iOS: 0x122438
     * @note[short] Android
     */
    virtual float timeForPos(cocos2d::CCPoint p0, int p1, int p2, bool p3, int p4);

    /**
     * @note[short] MacOS (ARM): 0xa9d6c
     * @note[short] MacOS (Intel): 0xba810
     * @note[short] Windows: 0x39c780
     * @note[short] iOS: 0x1224ac
     * @note[short] Android
     */
    virtual cocos2d::CCPoint posForTime(float p0);

    /**
     * @note[short] MacOS (ARM): 0xa9d8c
     * @note[short] MacOS (Intel): 0xba860
     * @note[short] Windows: 0x39c7e0
     * @note[short] iOS: 0x1224cc
     * @note[short] Android
     */
    virtual void resetSPTriggered();
    
private:
    [[deprecated("PlayLayer::updateTimeWarp not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xa6560
     * @note[short] MacOS (Intel): 0xb68e0
     * @note[short] iOS: 0x11f5c4
     * @note[short] Android
     */
    virtual void updateTimeWarp(float p0);
public:

    /**
     * @note[short] MacOS (ARM): 0xa94b4
     * @note[short] MacOS (Intel): 0xb9f30
     * @note[short] Windows: 0x39b180
     * @note[short] iOS: 0x121cc4
     * @note[short] Android
     */
    virtual void playGravityEffect(bool p0);

    /**
     * @note[short] MacOS (ARM): 0xa938c
     * @note[short] MacOS (Intel): 0xb9df0
     * @note[short] Windows: 0x399420
     * @note[short] iOS: 0x121bf0
     * @note[short] Android
     */
    virtual TodoReturn manualUpdateObjectColors(GameObject* p0);

    /**
     * @note[short] MacOS (ARM): 0xab010
     * @note[short] MacOS (Intel): 0xbbce0
     * @note[short] Windows: 0x39e130
     * @note[short] iOS: 0x123580
     * @note[short] Android
     */
    virtual void checkpointActivated(CheckpointGameObject* p0);

    /**
     * @note[short] MacOS (ARM): 0xa9c94
     * @note[short] MacOS (Intel): 0xba710
     * @note[short] Windows: 0x39bb60
     * @note[short] iOS: 0x1223d4
     * @note[short] Android
     */
    virtual TodoReturn flipArt(bool p0);

    /**
     * @note[short] MacOS (ARM): 0xa98b8
     * @note[short] MacOS (Intel): 0xba360
     * @note[short] Windows: 0x39b690
     * @note[short] iOS: 0x122048
     * @note[short] Android
     */
    virtual void updateTimeLabel(int p0, int p1, bool p2);
    
private:
    [[deprecated("PlayLayer::checkSnapshot not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xad494
     * @note[short] MacOS (Intel): 0xbeaa0
     * @note[short] iOS: 0x125610
     * @note[short] Android
     */
    virtual TodoReturn checkSnapshot();
public:

    /**
     * @note[short] MacOS (ARM): 0xa9a90
     * @note[short] MacOS (Intel): 0xba530
     * @note[short] Windows: 0x39b890
     * @note[short] iOS: 0x1221f0
     * @note[short] Android
     */
    virtual void toggleProgressbar();

    /**
     * @note[short] MacOS (ARM): 0xa9cb4
     * @note[short] MacOS (Intel): 0xba750
     * @note[short] Windows: 0x39c670
     * @note[short] iOS: 0x1223f4
     * @note[short] Android
     */
    virtual TodoReturn toggleInfoLabel();

    /**
     * @note[short] MacOS (ARM): 0xad284
     * @note[short] MacOS (Intel): 0xbe890
     * @note[short] Windows: 0x3a1130
     * @note[short] iOS: 0x125104
     * @note[short] Android
     */
    virtual void removeAllCheckpoints();

    /**
     * @note[short] MacOS (ARM): 0xa9c08
     * @note[short] MacOS (Intel): 0xba6b0
     * @note[short] Windows: 0x39ba30
     * @note[short] iOS: 0x122368
     * @note[short] Android
     */
    virtual TodoReturn toggleMusicInPractice();

    /**
     * @note[short] MacOS (ARM): 0xaa984
     * @note[short] MacOS (Intel): 0xbb5b0
     * @note[short] Windows: 0x39d880
     * @note[short] iOS: 0x122f34
     * @note[short] Android
     */
    virtual void currencyWillExit(CurrencyRewardLayer* p0);

    /**
     * @note[short] MacOS (ARM): 0xaa9e4
     * @note[short] MacOS (Intel): 0xbb650
     * @note[short] Windows: 0x39da40
     * @note[short] iOS: 0x122f94
     * @note[short] Android
     */
    virtual void circleWaveWillBeRemoved(CCCircleWave* p0);

    /**
     * @note[short] MacOS (ARM): 0xaa9b0
     * @note[short] MacOS (Intel): 0xbb5f0
     * @note[short] Windows: 0x39d8a0
     * @note[short] iOS: 0x122f60
     * @note[short] Android
     */
    virtual void dialogClosed(DialogLayer* p0);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
    void addCircle(CCCircleWave* cw);

    /**
     * @note[short] MacOS (ARM): 0xa2668
     * @note[short] MacOS (Intel): 0xb2190
     * @note[short] Windows: 0x396eb0
     * @note[short] Android
     */
    void addObject(GameObject* p0);
    
private:
    [[deprecated("PlayLayer::addToGroupOld not implemented")]]
    /**
     * @note[short] Android
     */
    void addToGroupOld(GameObject* p0);
public:

    /**
     * @note[short] Windows: 0x399aa0
     * @note[short] Android
     */
    void applyCustomEnterEffect(GameObject* p0, bool p1);

    /**
     * @note[short] Windows: 0x39a790
     * @note[short] Android
     */
    void applyEnterEffect(GameObject* p0, int p1, bool p2);

    /**
     * @note[short] MacOS (ARM): 0xadc4c
     * @note[short] MacOS (Intel): 0xbf270
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    bool canPauseGame();
    
private:
    [[deprecated("PlayLayer::checkpointWithID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn checkpointWithID(int p0);
public:
    
private:
    [[deprecated("PlayLayer::colorObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn colorObject(int p0, cocos2d::ccColor3B p1);
public:
    
private:
    [[deprecated("PlayLayer::commitJumps not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn commitJumps();
public:
    
private:
    [[deprecated("PlayLayer::compareStateSnapshot not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn compareStateSnapshot();
public:

    /**
     * @note[short] MacOS (Intel): 0xbbd00
     * @note[short] Windows: 0x39e150
     * @note[short] Android
     */
    CheckpointObject* createCheckpoint();

    /**
     * @note[short] MacOS (ARM): 0xa6fc4
     * @note[short] MacOS (Intel): 0xb7490
     * @note[short] Windows: 0x396a10
     * @note[short] Android
     */
    void createObjectsFromSetupFinished();
    
private:
    [[deprecated("PlayLayer::delayedFullReset not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xad4a0
     * @note[short] MacOS (Intel): 0xbead0
     * @note[short] Android
     */
    void delayedFullReset();
public:

    /**
     * @note[short] MacOS (ARM): 0xaa970
     * @note[short] MacOS (Intel): 0xbb590
     * @note[short] Windows: 0x3a1de0
     * @note[short] Android
     */
    void delayedResetLevel();

    /**
     * @note[short] MacOS (ARM): 0xad514
     * @note[short] MacOS (Intel): 0xbeb30
     * @note[short] Windows: 0x3a1ce0
     * @note[short] Android
     */
    void fullReset();

    /**
     * @note[short] MacOS (ARM): 0xa9848
     * @note[short] MacOS (Intel): 0xba2f0
     * @note[short] Windows: 0x39ca70
     * @note[short] Android
     */
    float getCurrentPercent();

    /**
     * @note[short] MacOS (ARM): 0xa9f18
     * @note[short] MacOS (Intel): 0xba9f0
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android
     */
    int getCurrentPercentInt();
    
private:
    [[deprecated("PlayLayer::getEndPosition not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getEndPosition();
public:
    
private:
    [[deprecated("PlayLayer::getLastCheckpoint not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getLastCheckpoint();
public:
    
private:
    [[deprecated("PlayLayer::getRelativeMod not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getRelativeMod(cocos2d::CCPoint p0, float p1, float p2, float p3);
public:
    
private:
    [[deprecated("PlayLayer::getRelativeModNew not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getRelativeModNew(cocos2d::CCPoint p0, float p1, float p2, bool p3, bool p4);
public:

    /**
     * @note[short] Windows: 0x3cef0
     * @note[short] Android
     */
    double getTempMilliTime();
    
private:
    [[deprecated("PlayLayer::gravityEffectFinished not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn gravityEffectFinished();
public:
    
private:
    [[deprecated("PlayLayer::incrementJumps not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xadbcc
     * @note[short] MacOS (Intel): 0xbf200
     * @note[short] Android
     */
    void incrementJumps();
public:

    /**
     * @note[short] MacOS (ARM): 0x9cd6c
     * @note[short] MacOS (Intel): 0xabe20
     * @note[short] Windows: 0x38ec70
     * @note[short] Android
     */
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects);
    
private:
    [[deprecated("PlayLayer::isGameplayActive not implemented")]]
    /**
     * @note[short] Android
     */
    bool isGameplayActive();
public:

    /**
     * @note[short] MacOS (ARM): 0xa406c
     * @note[short] MacOS (Intel): 0xb4050
     * @note[short] Windows: 0x390c30
     * @note[short] Android
     */
    void levelComplete();
    
private:
    [[deprecated("PlayLayer::loadActiveSaveObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn loadActiveSaveObjects(gd::vector<SavedActiveObjectState>& p0, gd::vector<SavedSpecialObjectState>& p1);
public:

    /**
     * @note[short] MacOS (ARM): 0xa2300
     * @note[short] MacOS (Intel): 0xb1de0
     * @note[short] Windows: 0x39ad80
     * @note[short] Android
     */
    void loadDefaultColors();
    
private:
    [[deprecated("PlayLayer::loadDynamicSaveObjects not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xad05c
     * @note[short] MacOS (Intel): 0xbe690
     * @note[short] Android
     */
    TodoReturn loadDynamicSaveObjects(gd::vector<SavedObjectStateRef>& p0);
public:

    /**
     * @note[short] MacOS (ARM): 0xacb4c
     * @note[short] MacOS (Intel): 0xbe120
     * @note[short] Windows: 0x3a07b0
     * @note[short] Android
     */
    void loadFromCheckpoint(CheckpointObject* p0);
    
private:
    [[deprecated("PlayLayer::loadLastCheckpoint not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xacaf4
     * @note[short] Android
     */
    TodoReturn loadLastCheckpoint();
public:

    /**
     * @note[short] MacOS (ARM): 0xaacd4
     * @note[short] MacOS (Intel): 0xbb9d0
     * @note[short] Windows: 0x3a06e0
     * @note[short] Android
     */
    CheckpointObject * markCheckpoint();

    /**
     * @note[short] MacOS (ARM): 0xa3cac
     * @note[short] MacOS (Intel): 0xb3c60
     * @note[short] Windows: 0x3a3db0
     * @note[short] Android
     */
    void onQuit();

    /**
     * @note[short] MacOS (Intel): 0xae840
     * @note[short] Windows: 0x397d10
     * @note[short] Android
     */
    TodoReturn optimizeColorGroups();

    /**
     * @note[short] MacOS (Intel): 0xaea30
     * @note[short] Windows: 0x397fa0
     * @note[short] Android
     */
    TodoReturn optimizeOpacityGroups();

    /**
     * @note[short] MacOS (ARM): 0xadc74
     * @note[short] MacOS (Intel): 0xbf290
     * @note[short] Windows: 0x3a31f0
     * @note[short] Android
     */
    void pauseGame(bool p0);

    /**
     * @note[short] MacOS (ARM): 0xa664c
     * @note[short] MacOS (Intel): 0xb6a00
     * @note[short] Windows: 0x394aa0
     * @note[short] Android
     */
    void playEndAnimationToPos(cocos2d::CCPoint p0);

    /**
     * @note[short] MacOS (ARM): 0xa6b84
     * @note[short] MacOS (Intel): 0xb6fb0
     * @note[short] Windows: 0x395430
     * @note[short] Android
     */
    void playPlatformerEndAnimationToPos(cocos2d::CCPoint p0, bool p1);
    
private:
    [[deprecated("PlayLayer::playReplay not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn playReplay(gd::string p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x9dac0
     * @note[short] Windows: 0x395f80
     * @note[short] Android
     */
    void prepareCreateObjectsFromSetup(gd::string& p0);
    
private:
    [[deprecated("PlayLayer::prepareMusic not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0xb3ae0
     * @note[short] Android
     */
    void prepareMusic(bool p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x9de44
     * @note[short] Windows: 0x396230
     * @note[short] Android
     */
    void processCreateObjectsFromSetup();
    
private:
    [[deprecated("PlayLayer::processLoadedMoveActions not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn processLoadedMoveActions();
public:
    
private:
    [[deprecated("PlayLayer::queueCheckpoint not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn queueCheckpoint();
public:
    
private:
    [[deprecated("PlayLayer::removeAllObjects not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0xb3dd0
     * @note[short] Android
     */
    void removeAllObjects();
public:

    /**
     * @note[short] MacOS (ARM): 0xaca08
     * @note[short] MacOS (Intel): 0xbdfd0
     * @note[short] Windows: 0x3a0ff0
     * @note[short] Android
     */
    void removeCheckpoint(bool p0);
    
private:
    [[deprecated("PlayLayer::removeFromGroupOld not implemented")]]
    /**
     * @note[short] Android
     */
    void removeFromGroupOld(GameObject* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0xa3120
     * @note[short] MacOS (Intel): 0xb2f80
     * @note[short] Windows: 0x3a1f90
     * @note[short] Android
     */
    void resetLevel();

    /**
     * @note[short] MacOS (ARM): 0xad7d0
     * @note[short] MacOS (Intel): 0xbee20
     * @note[short] Windows: 0x3a1df0
     * @note[short] Android
     */
    void resetLevelFromStart();

    /**
     * @note[short] MacOS (ARM): 0xadf54
     * @note[short] MacOS (Intel): 0xbf580
     * @note[short] Windows: 0x3a37c0
     * @note[short] Android
     */
    void resume();

    /**
     * @note[short] MacOS (ARM): 0xaddbc
     * @note[short] MacOS (Intel): 0xbf3d0
     * @note[short] Windows: 0x3a34b0
     * @note[short] Android
     */
    void resumeAndRestart(bool p0);
    
private:
    [[deprecated("PlayLayer::saveActiveSaveObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn saveActiveSaveObjects(gd::vector<SavedActiveObjectState>& p0, gd::vector<SavedSpecialObjectState>& p1);
public:
    
private:
    [[deprecated("PlayLayer::saveDynamicSaveObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn saveDynamicSaveObjects(gd::vector<SavedObjectStateRef>& p0);
public:
    
private:
    [[deprecated("PlayLayer::scanActiveSaveObjects not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0xaf930
     * @note[short] Android
     */
    TodoReturn scanActiveSaveObjects();
public:

    /**
     * @note[short] MacOS (Intel): 0xaec20
     * @note[short] Windows: 0x3a1180
     * @note[short] Android
     */
    TodoReturn scanDynamicSaveObjects();
    
private:
    [[deprecated("PlayLayer::screenFlipObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn screenFlipObject(GameObject* p0);
public:
    
private:
    [[deprecated("PlayLayer::setDamageVerifiedIdx not implemented")]]
    /**
     * @note[short] Android
     */
    void setDamageVerifiedIdx(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x9e66c
     * @note[short] MacOS (Intel): 0xadac0
     * @note[short] Windows: 0x38f9c0
     * @note[short] Android
     */
    void setupHasCompleted();
    
private:
    [[deprecated("PlayLayer::shouldBlend not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn shouldBlend(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0xa4af4
     * @note[short] MacOS (Intel): 0xb4c70
     * @note[short] Windows: 0x391fd0
     * @note[short] Android
     */
    void showCompleteEffect();

    /**
     * @note[short] MacOS (ARM): 0xa4ecc
     * @note[short] MacOS (Intel): 0xb50f0
     * @note[short] Windows: 0x3919a0
     * @note[short] Android
     */
    void showCompleteText();
    
private:
    [[deprecated("PlayLayer::showEndLayer not implemented")]]
    /**
     * @note[short] Android
     */
    void showEndLayer();
public:

    /**
     * @note[short] MacOS (Intel): 0xbb420
     * @note[short] Windows: 0x39d8c0
     * @note[short] Android
     */
    void showHint();

    /**
     * @note[short] MacOS (ARM): 0xa5a94
     * @note[short] MacOS (Intel): 0xb5d40
     * @note[short] Windows: 0x3925f0
     * @note[short] Android
     */
    void showNewBest(bool p0, int p1, int p2, bool p3, bool p4, bool p5);
    
private:
    [[deprecated("PlayLayer::showRetryLayer not implemented")]]
    /**
     * @note[short] Android
     */
    void showRetryLayer();
public:
    
private:
    [[deprecated("PlayLayer::showTwoPlayerGuide not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xa1d74
     * @note[short] MacOS (Intel): 0xb1890
     * @note[short] Android
     */
    void showTwoPlayerGuide();
public:
    
private:
    [[deprecated("PlayLayer::spawnCircle not implemented")]]
    /**
     * @note[short] Android
     */
    void spawnCircle();
public:
    
private:
    [[deprecated("PlayLayer::spawnFirework not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xa5800
     * @note[short] MacOS (Intel): 0xb5a80
     * @note[short] Android
     */
    TodoReturn spawnFirework();
public:

    /**
     * @note[short] MacOS (ARM): 0xa3c50
     * @note[short] MacOS (Intel): 0xb3c00
     * @note[short] Windows: 0x390bd0
     * @note[short] Android
     */
    void startGame();
    
private:
    [[deprecated("PlayLayer::startGameDelayed not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0xb3fe0
     * @note[short] Android
     */
    void startGameDelayed();
public:

    /**
     * @note[short] MacOS (ARM): 0xa3f14
     * @note[short] MacOS (Intel): 0xb3ef0
     * @note[short] Windows: 0x3a3c60
     * @note[short] Android
     */
    void startMusic();
    
private:
    [[deprecated("PlayLayer::startRecording not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn startRecording();
public:
    
private:
    [[deprecated("PlayLayer::startRecordingDelayed not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn startRecordingDelayed();
public:
    
private:
    [[deprecated("PlayLayer::stopRecording not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn stopRecording();
public:

    /**
     * @note[short] MacOS (ARM): 0xac964
     * @note[short] MacOS (Intel): 0xbdf30
     * @note[short] Windows: 0x3a0610
     * @note[short] Android
     */
    void storeCheckpoint(CheckpointObject* p0);
    
private:
    [[deprecated("PlayLayer::takeStateSnapshot not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn takeStateSnapshot();
public:
    
private:
    [[deprecated("PlayLayer::toggleBGEffectVisibility not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleBGEffectVisibility(bool p0);
public:
    
private:
    [[deprecated("PlayLayer::toggleDebugDraw not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleDebugDraw(bool p0);
public:
    
private:
    [[deprecated("PlayLayer::toggleGhostEffect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleGhostEffect(int p0);
public:
    
private:
    [[deprecated("PlayLayer::toggleIgnoreDamage not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleIgnoreDamage(bool p0);
public:

    /**
     * @note[short] MacOS (ARM): 0xad654
     * @note[short] MacOS (Intel): 0xbeca0
     * @note[short] Windows: 0x3a2f20
     * @note[short] Android
     */
    void togglePracticeMode(bool practiceMode);
    
private:
    [[deprecated("PlayLayer::tryStartRecord not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn tryStartRecord();
public:

    /**
     * @note[short] MacOS (ARM): 0xad858
     * @note[short] MacOS (Intel): 0xbeeb0
     * @note[short] Windows: 0x3a2c70
     * @note[short] Android
     */
    void updateAttempts();
    
private:
    [[deprecated("PlayLayer::updateEffectPositions not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0xaa9fc
     * @note[short] MacOS (Intel): 0xbb690
     * @note[short] Android
     */
    void updateEffectPositions();
public:

    /**
     * @note[short] MacOS (ARM): 0xa0770
     * @note[short] MacOS (Intel): 0xafdc0
     * @note[short] Windows: 0x39bb90
     * @note[short] Android
     */
    void updateInfoLabel();
    
private:
    [[deprecated("PlayLayer::updateInvisibleBlock not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateInvisibleBlock(GameObject* p0, float p1, float p2, float p3, float p4, cocos2d::ccColor3B const& p5);
public:

    /**
     * @note[short] MacOS (ARM): 0xa2124
     * @note[short] MacOS (Intel): 0xb1c20
     * @note[short] Windows: 0x39b4f0
     * @note[short] Android
     */
    void updateProgressbar();
    
private:
    [[deprecated("PlayLayer::updateScreenRotation not implemented")]]
    /**
     * @note[short] Android
     */
    void updateScreenRotation(int p0, bool p1, bool p2, float p3, int p4, float p5, int p6, int p7);
public:

    /**
     * @note[short] MacOS (ARM): 0xa3d38
     * @note[short] MacOS (Intel): 0xb3d10
     * @note[short] Windows: 0x390b40
     * @note[short] Android
     */
    void updateTestModeLabel();

    /**
     * @note[short] Windows: 0x394a40
     * @note[short] Android
     */
    void updateTimeWarp(EffectGameObject* p0, float p1);
    GEODE_PAD(48);
    cocos2d::CCArray* m_coinArray;
    GEODE_PAD(110);
    bool m_isIgnoreDamageEnabled;
    cocos2d::CCLabelBMFont* m_statusLabel;
    int m_unk3778;
    GEODE_PAD(24);
    float m_unkSomeFloat;
    CheckpointObject* m_currentCheckpoint;
    cocos2d::CCArray* m_checkpointArray;
    cocos2d::CCArray* m_unk37a8;
    int m_unk37b0;
    int m_unk37b4;
    int m_unk37b8;
    cocos2d::CCArray* m_unk37c0;
    int m_unk37c8;
    int m_unk37cc;
    cocos2d::CCArray* m_circleWaveArray;
    cocos2d::CCArray* m_unk37d8;
    int m_unk37e0;
    int m_unk37e4;
    float m_unk37e8;
    cocos2d::CCLabelBMFont* m_attemptLabel;
    cocos2d::CCLabelBMFont* m_percentageLabel;
    bool m_0126;
    cocos2d::CCSprite* m_progressBar;
    cocos2d::CCSprite* m_progressFill;
    GEODE_PAD(110);
    int m_jumps;
    bool m_hasJumped;
    int m_uncommittedJumps;
    bool m_showLeaderboardPercentage;
    bool m_hasCompletedLevel;
    bool m_inResetDelay;
    int m_lastAttemptPercent;
    bool m_endLayerStars;
    GEODE_PAD(58);
    double m_attemptTime;
    double m_bestAttemptTime;
    GEODE_PAD(31);
    bool m_isPaused;
    bool m_disableGravityEffect;
    cocos2d::CCLabelBMFont* m_infoLabel;
    cocos2d::CCPoint m_pUnk38e8;
    cocos2d::CCPoint m_pUnk38f0;
    cocos2d::CCDictionary* m_colorKeyDict;
    gd::vector<int> m_keyColors;
    gd::vector<int> m_keyOpacities;
    gd::vector<int> m_keyPulses;
    int m_nextColorKey;
    bool m_tryPlaceCheckpoint;
    CheckpointGameObject* m_activatedCheckpoint;
    bool m_bUnk3958;
    cocos2d::CCPoint m_endPosition;
    EndTriggerGameObject* m_platformerEndTrigger;
};
