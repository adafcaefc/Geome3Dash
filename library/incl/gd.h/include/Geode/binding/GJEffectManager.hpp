#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "DynamicMoveCalculation.hpp"
#include "PulseEffectAction.hpp"
#include "TouchToggleAction.hpp"
#include "CollisionTriggerAction.hpp"
#include "ToggleTriggerAction.hpp"
#include "SpawnTriggerAction.hpp"
#include "GroupCommandObject2.hpp"
#include "OpacityEffectAction.hpp"
#include "CountTriggerAction.hpp"
#include "TimerItem.hpp"
#include "TimerTriggerAction.hpp"

class GJEffectManager : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "GJEffectManager";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJEffectManager, cocos2d::CCNode)

    /**
     * @note[short] Windows: 0x2538f0
     * @note[short] Android
     */
    static GJEffectManager* create();
    
private:
    [[deprecated("GJEffectManager::rewardedVideoFinished not implemented")]]
    /**
     * @note[short] Android
     */
    virtual void rewardedVideoFinished();
public:
    
private:
    [[deprecated("GJEffectManager::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x26c924
     * @note[short] MacOS (Intel): 0x2c8f30
     * @note[short] iOS: 0x125e8
     * @note[short] Android
     */
    virtual bool init();
public:

    /**
     * @note[short] MacOS (Intel): 0x2ca350
     * @note[short] Windows: 0x254930
     * @note[short] Android
     */
    TodoReturn activeColorForIndex(int p0);
    
private:
    [[deprecated("GJEffectManager::activeOpacityForIndex not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x2ca4b0
     * @note[short] Android
     */
    TodoReturn activeOpacityForIndex(int p0);
public:
    
private:
    [[deprecated("GJEffectManager::addAllInheritedColorActions not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn addAllInheritedColorActions(cocos2d::CCArray* p0);
public:
    
private:
    [[deprecated("GJEffectManager::addCountToItem not implemented")]]
    /**
     * @note[short] Android
     */
    void addCountToItem(int p0, int p1);
public:
    
private:
    [[deprecated("GJEffectManager::addMoveCalculation not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn addMoveCalculation(CCMoveCNode* p0, cocos2d::CCPoint p1, GameObject* p2);
public:
    
private:
    [[deprecated("GJEffectManager::calculateBaseActiveColors not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn calculateBaseActiveColors();
public:
    
private:
    [[deprecated("GJEffectManager::calculateInheritedColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn calculateInheritedColor(int p0, ColorAction* p1);
public:
    
private:
    [[deprecated("GJEffectManager::calculateLightBGColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn calculateLightBGColor(cocos2d::ccColor3B p0);
public:
    
private:
    [[deprecated("GJEffectManager::checkCollision not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn checkCollision(int const& p0, int const& p1);
public:
    
private:
    [[deprecated("GJEffectManager::colorActionChanged not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x2cb670
     * @note[short] Android
     */
    void colorActionChanged(ColorAction* p0);
public:
    
private:
    [[deprecated("GJEffectManager::colorExists not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x2cb640
     * @note[short] Android
     */
    bool colorExists(int p0);
public:
    
private:
    [[deprecated("GJEffectManager::colorForEffect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn colorForEffect(cocos2d::ccColor3B p0, cocos2d::ccHSVValue p1);
public:
    
private:
    [[deprecated("GJEffectManager::colorForGroupID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn colorForGroupID(int p0, cocos2d::ccColor3B const& p1, bool p2);
public:
    
private:
    [[deprecated("GJEffectManager::colorForIndex not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn colorForIndex(int p0);
public:
    
private:
    [[deprecated("GJEffectManager::colorForPulseEffect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn colorForPulseEffect(cocos2d::ccColor3B const& p0, PulseEffectAction* p1);
public:
    
private:
    [[deprecated("GJEffectManager::controlActionsForControlID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn controlActionsForControlID(int p0, GJActionCommand p1);
public:
    
private:
    [[deprecated("GJEffectManager::controlActionsForTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn controlActionsForTrigger(EffectGameObject* p0, GJActionCommand p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x2777b8
     * @note[short] MacOS (Intel): 0x2d6930
     * @note[short] Windows: 0x25b060
     * @note[short] Android
     */
    int countForItem(int p0);
    
private:
    [[deprecated("GJEffectManager::createFollowCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createFollowCommand(float p0, float p1, float p2, int p3, int p4, int p5, int p6);
public:
    
private:
    [[deprecated("GJEffectManager::createKeyframeCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createKeyframeCommand(int p0, cocos2d::CCArray* p1, GameObject* p2, int p3, int p4, bool p5, float p6, float p7, float p8, float p9, float p10, float p11, gd::vector<int> const& p12);
public:
    
private:
    [[deprecated("GJEffectManager::createMoveCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createMoveCommand(cocos2d::CCPoint p0, int p1, float p2, int p3, float p4, bool p5, bool p6, bool p7, bool p8, float p9, float p10, int p11, int p12);
public:
    
private:
    [[deprecated("GJEffectManager::createPlayerFollowCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createPlayerFollowCommand(float p0, float p1, int p2, float p3, float p4, int p5, int p6, int p7);
public:
    
private:
    [[deprecated("GJEffectManager::createRotateCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createRotateCommand(float p0, float p1, int p2, int p3, int p4, float p5, bool p6, bool p7, bool p8, int p9, int p10);
public:
    
private:
    [[deprecated("GJEffectManager::createTransformCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createTransformCommand(double p0, double p1, double p2, double p3, bool p4, float p5, int p6, int p7, int p8, float p9, bool p10, bool p11, int p12, int p13);
public:
    
private:
    [[deprecated("GJEffectManager::getAllColorActions not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getAllColorActions();
public:
    
private:
    [[deprecated("GJEffectManager::getAllColorSprites not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getAllColorSprites();
public:

    /**
     * @note[short] MacOS (ARM): 0x26d3c4
     * @note[short] MacOS (Intel): 0x2ca1e0
     * @note[short] Windows: 0x254870
     * @note[short] Android
     */
    ColorAction* getColorAction(int p0);

    /**
     * @note[short] MacOS (Intel): 0x2ca3a0
     * @note[short] Windows: 0x254930
     * @note[short] Android
     */
    ColorActionSprite* getColorSprite(int p0);
    
private:
    [[deprecated("GJEffectManager::getLoadedMoveOffset not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getLoadedMoveOffset(gd::unordered_map<int, std::pair<double, double>>& p0);
public:
    
private:
    [[deprecated("GJEffectManager::getMixedColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getMixedColor(cocos2d::ccColor3B p0, cocos2d::ccColor3B p1, float p2);
public:
    
private:
    [[deprecated("GJEffectManager::getMoveCommandNode not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getMoveCommandNode(GroupCommandObject2* p0);
public:
    
private:
    [[deprecated("GJEffectManager::getMoveCommandObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getMoveCommandObject();
public:
    
private:
    [[deprecated("GJEffectManager::getOpacityActionForGroup not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getOpacityActionForGroup(int p0);
public:
    
private:
    [[deprecated("GJEffectManager::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x2d9360
     * @note[short] Android
     */
    TodoReturn getSaveString();
public:
    
private:
    [[deprecated("GJEffectManager::getTempGroupCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getTempGroupCommand();
public:
    
private:
    [[deprecated("GJEffectManager::handleObjectCollision not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn handleObjectCollision(bool p0, int p1, int p2);
public:
    
private:
    [[deprecated("GJEffectManager::hasActiveDualTouch not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn hasActiveDualTouch();
public:
    
private:
    [[deprecated("GJEffectManager::hasBeenTriggered not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x2d5fd0
     * @note[short] Android
     */
    TodoReturn hasBeenTriggered(int p0, int p1);
public:
    
private:
    [[deprecated("GJEffectManager::hasPulseEffectForGroupID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn hasPulseEffectForGroupID(int p0);
public:
    
private:
    [[deprecated("GJEffectManager::isGroupEnabled not implemented")]]
    /**
     * @note[short] Android
     */
    bool isGroupEnabled(int p0);
public:
    
private:
    [[deprecated("GJEffectManager::keyForGroupIDColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn keyForGroupIDColor(int p0, cocos2d::ccColor3B const& p1, bool p2);
public:

    /**
     * @note[short] Windows: 0x25cb40
     * @note[short] Android
     */
    void loadFromState(EffectManagerState& p0);
    
private:
    [[deprecated("GJEffectManager::objectsCollided not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x2cc680
     * @note[short] Android
     */
    void objectsCollided(int p0, int p1);
public:
    
private:
    [[deprecated("GJEffectManager::onRewardedVideo not implemented")]]
    /**
     * @note[short] Android
     */
    void onRewardedVideo(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJEffectManager::opacityForIndex not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn opacityForIndex(int p0);
public:
    
private:
    [[deprecated("GJEffectManager::opacityModForGroup not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn opacityModForGroup(int p0);
public:
    
private:
    [[deprecated("GJEffectManager::pauseTimer not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn pauseTimer(int p0);
public:

    /**
     * @note[short] Windows: 0x25ae00
     * @note[short] Android
     */
    TodoReturn playerButton(bool p0, bool p1);
    
private:
    [[deprecated("GJEffectManager::playerDied not implemented")]]
    /**
     * @note[short] Android
     */
    void playerDied();
public:

    /**
     * @note[short] MacOS (Intel): 0x2cc390
     * @note[short] Windows: 0x254f50
     * @note[short] Android
     */
    TodoReturn postCollisionCheck();

    /**
     * @note[short] MacOS (Intel): 0x2d4110
     * @note[short] Windows: 0x259470
     * @note[short] Android
     */
    TodoReturn postMoveActions();
    
private:
    [[deprecated("GJEffectManager::preCollisionCheck not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x2cc370
     * @note[short] Android
     */
    TodoReturn preCollisionCheck();
public:

    /**
     * @note[short] MacOS (Intel): 0x2d16c0
     * @note[short] Windows: 0x258060
     * @note[short] Android
     */
    TodoReturn prepareMoveActions(float p0, bool p1);

    /**
     * @note[short] MacOS (Intel): 0x2ca520
     * @note[short] Windows: 0x253fb0
     * @note[short] Android
     */
    TodoReturn processColors();
    
private:
    [[deprecated("GJEffectManager::processCopyColorPulseActions not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x2cabf0
     * @note[short] Android
     */
    TodoReturn processCopyColorPulseActions();
public:
    
private:
    [[deprecated("GJEffectManager::processInheritedColors not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x2ca840
     * @note[short] Android
     */
    TodoReturn processInheritedColors();
public:
    
private:
    [[deprecated("GJEffectManager::processMoveCalculations not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn processMoveCalculations();
public:
    
private:
    [[deprecated("GJEffectManager::processPulseActions not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn processPulseActions();
public:
    
private:
    [[deprecated("GJEffectManager::registerCollisionTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn registerCollisionTrigger(int p0, int p1, int p2, bool p3, bool p4, gd::vector<int> const& p5, int p6, int p7);
public:
    
private:
    [[deprecated("GJEffectManager::registerRotationCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn registerRotationCommand(GroupCommandObject2* p0, bool p1);
public:
    
private:
    [[deprecated("GJEffectManager::removeAllPulseActions not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn removeAllPulseActions();
public:
    
private:
    [[deprecated("GJEffectManager::removeColorAction not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn removeColorAction(int p0);
public:
    
private:
    [[deprecated("GJEffectManager::removePersistentFromAllItems not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x2d7520
     * @note[short] Android
     */
    TodoReturn removePersistentFromAllItems();
public:
    
private:
    [[deprecated("GJEffectManager::removePersistentFromAllTimers not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn removePersistentFromAllTimers();
public:
    
private:
    [[deprecated("GJEffectManager::removeTriggeredID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn removeTriggeredID(int p0, int p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x26cb18
     * @note[short] MacOS (Intel): 0x2c9190
     * @note[short] Windows: 0x253d10
     * @note[short] Android
     */
    void reset();

    /**
     * @note[short] MacOS (Intel): 0x2c93a0
     * @note[short] Windows: 0x254c90
     * @note[short] Android
     */
    TodoReturn resetEffects();
    
private:
    [[deprecated("GJEffectManager::resetMoveActions not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetMoveActions();
public:
    
private:
    [[deprecated("GJEffectManager::resetTempGroupCommands not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetTempGroupCommands(bool p0);
public:
    
private:
    [[deprecated("GJEffectManager::resetToggledGroups not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetToggledGroups();
public:
    
private:
    [[deprecated("GJEffectManager::resetTriggeredIDs not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resetTriggeredIDs();
public:
    
private:
    [[deprecated("GJEffectManager::resumeTimer not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn resumeTimer(int p0);
public:
    
private:
    [[deprecated("GJEffectManager::runCountTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn runCountTrigger(int p0, int p1, bool p2, int p3, bool p4, gd::vector<int> const& p5, int p6, int p7);
public:
    
private:
    [[deprecated("GJEffectManager::runDeathTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn runDeathTrigger(int p0, bool p1, gd::vector<int> const& p2, int p3, int p4);
public:
    
private:
    [[deprecated("GJEffectManager::runOpacityActionOnGroup not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn runOpacityActionOnGroup(int p0, float p1, float p2, int p3, int p4);
public:
    
private:
    [[deprecated("GJEffectManager::runPulseEffect not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn runPulseEffect(int p0, bool p1, float p2, float p3, float p4, PulseEffectType p5, cocos2d::ccColor3B p6, cocos2d::ccHSVValue p7, int p8, bool p9, bool p10, bool p11, bool p12, int p13, int p14);
public:
    
private:
    [[deprecated("GJEffectManager::runTimerTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn runTimerTrigger(int p0, double p1, bool p2, int p3, gd::vector<int> const& p4, int p5, int p6);
public:
    
private:
    [[deprecated("GJEffectManager::runTouchTriggerCommand not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn runTouchTriggerCommand(int p0, bool p1, TouchTriggerType p2, TouchTriggerControl p3, bool p4, gd::vector<int> const& p5, int p6, int p7);
public:
    
private:
    [[deprecated("GJEffectManager::saveCompletedMove not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn saveCompletedMove(int p0, double p1, double p2);
public:

    /**
     * @note[short] Windows: 0x25c520
     * @note[short] Android
     */
    void saveToState(EffectManagerState& p0);

    /**
     * @note[short] MacOS (ARM): 0x26e4cc
     * @note[short] MacOS (Intel): 0x2cb570
     * @note[short] Windows: 0x254a90
     * @note[short] Android
     */
    void setColorAction(ColorAction* p0, int p1);
    
private:
    [[deprecated("GJEffectManager::setFollowing not implemented")]]
    /**
     * @note[short] Android
     */
    void setFollowing(int p0, int p1, bool p2);
public:
    
private:
    [[deprecated("GJEffectManager::setupFromString not implemented")]]
    /**
     * @note[short] Android
     */
    void setupFromString(gd::string p0);
public:
    
private:
    [[deprecated("GJEffectManager::shouldBlend not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x2ca4e0
     * @note[short] Android
     */
    bool shouldBlend(int p0);
public:

    /**
     * @note[short] Windows: 0x25a920
     * @note[short] Android
     */
    TodoReturn spawnGroup(int p0, float p1, bool p2, gd::vector<int> const& p3, int p4, int p5);
    
private:
    [[deprecated("GJEffectManager::spawnObject not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn spawnObject(GameObject* p0, float p1, gd::vector<int> const& p2, int p3, int p4);
public:
    
private:
    [[deprecated("GJEffectManager::startTimer not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn startTimer(int p0, double p1, double p2, bool p3, bool p4, bool p5, float p6, bool p7, int p8, gd::vector<int> const& p9, int p10, int p11);
public:

    /**
     * @note[short] MacOS (Intel): 0x2d5e20
     * @note[short] Windows: 0x25ac60
     * @note[short] Android
     */
    TodoReturn storeTriggeredID(int p0, int p1);

    /**
     * @note[short] Windows: 0x25bfd0
     * @note[short] Android
     */
    TodoReturn timeForItem(int p0);
    
private:
    [[deprecated("GJEffectManager::timerExists not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn timerExists(int p0);
public:
    
private:
    [[deprecated("GJEffectManager::toggleGroup not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleGroup(int p0, bool p1);
public:
    
private:
    [[deprecated("GJEffectManager::toggleItemPersistent not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleItemPersistent(int p0, bool p1);
public:
    
private:
    [[deprecated("GJEffectManager::toggleTimerPersistent not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleTimerPersistent(int p0, bool p1);
public:
    
private:
    [[deprecated("GJEffectManager::transferPersistentItems not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn transferPersistentItems();
public:
    
private:
    [[deprecated("GJEffectManager::traverseInheritanceChain not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn traverseInheritanceChain(InheritanceNode* p0);
public:
    
private:
    [[deprecated("GJEffectManager::tryGetMoveCommandNode not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn tryGetMoveCommandNode(int p0);
public:
    
private:
    [[deprecated("GJEffectManager::updateActiveOpacityEffects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateActiveOpacityEffects();
public:
    
private:
    [[deprecated("GJEffectManager::updateColorAction not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateColorAction(ColorAction* p0);
public:
    
private:
    [[deprecated("GJEffectManager::updateColorEffects not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x26e6c0
     * @note[short] MacOS (Intel): 0x2cb7d0
     * @note[short] Android
     */
    void updateColorEffects(float p0);
public:
    
private:
    [[deprecated("GJEffectManager::updateColors not implemented")]]
    /**
     * @note[short] Android
     */
    void updateColors(cocos2d::ccColor3B p0, cocos2d::ccColor3B p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x27791c
     * @note[short] MacOS (Intel): 0x2d6b10
     * @note[short] Windows: 0x25b120
     * @note[short] Android
     */
    void updateCountForItem(int p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0x26e5bc
     * @note[short] MacOS (Intel): 0x2cb6a0
     * @note[short] Windows: 0x254b10
     * @note[short] Android
     */
    void updateEffects(float p0);
    
private:
    [[deprecated("GJEffectManager::updateOpacityAction not implemented")]]
    /**
     * @note[short] Android
     */
    void updateOpacityAction(OpacityEffectAction* p0);
public:
    
private:
    [[deprecated("GJEffectManager::updateOpacityEffects not implemented")]]
    /**
     * @note[short] Android
     */
    void updateOpacityEffects(float p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x26e850
     * @note[short] MacOS (Intel): 0x2cb9a0
     * @note[short] Windows: 0x259e30
     * @note[short] Android
     */
    void updatePulseEffects(float p0);

    /**
     * @note[short] Windows: 0x25aa10
     * @note[short] Android
     */
    TodoReturn updateSpawnTriggers(float p0);
    
private:
    [[deprecated("GJEffectManager::updateTimer not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateTimer(int p0, double p1);
public:

    /**
     * @note[short] MacOS (Intel): 0x2d82a0
     * @note[short] Windows: 0x25b9e0
     * @note[short] Android
     */
    TodoReturn updateTimers(float p0, float p1);
    
private:
    [[deprecated("GJEffectManager::wasFollowing not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn wasFollowing(int p0, int p1);
public:
    
private:
    [[deprecated("GJEffectManager::wouldCreateLoop not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn wouldCreateLoop(InheritanceNode* p0, int p1);
public:
    TriggerEffectDelegate* m_triggerEffectDelegate;
    cocos2d::CCDictionary* m_unkObject148;
    cocos2d::CCDictionary* m_unkDict150;
    gd::vector<PulseEffectAction> m_pulseEffectVector;
    gd::unordered_map<int, gd::vector<PulseEffectAction>> m_pulseEffectMap;
    gd::unordered_map<int, OpacityEffectAction> m_opacityEffectMap;
    gd::vector<TouchToggleAction> m_unkVector1e0;
    gd::unordered_map<int, gd::vector<CountTriggerAction>> m_countTriggerActions;
    gd::vector<CollisionTriggerAction> m_unkVector230;
    gd::vector<ToggleTriggerAction> m_unkVector248;
    cocos2d::CCDictionary* m_colorActionDict;
    cocos2d::CCDictionary* m_unkDict268;
    gd::vector<InheritanceNode*> m_unkVector270;
    gd::unordered_map<int, bool> m_unkMap288;
    gd::vector<ColorAction*> m_unkVector2c0;
    gd::vector<ColorActionSprite*> m_unkVector2d8;
    gd::vector<bool> m_unkVector2f0;
    gd::unordered_map<int, int> m_itemIDs;
    gd::unordered_map<int, int> m_unkMap350;
    gd::unordered_set<int> m_unkMap388;
    gd::unordered_map<int, TimerItem> m_unkMap3c0;
    gd::unordered_map<int, std::vector<TimerTriggerAction>> m_unkMap3f8;
    cocos2d::CCArray* m_unkArray430;
    gd::vector<bool> m_unkVector438;
    gd::unordered_set<int> m_unkMap460;
    gd::map<int, int> m_unkMap498;
    gd::unordered_set<int> m_unkMap4c8;
    gd::vector<SpawnTriggerAction> m_nukVector500;
    gd::vector<GroupCommandObject2*> m_unkVector518;
    gd::vector<GroupCommandObject2*> m_unkVector530;
    gd::vector<CCObject*> m_unkVector548;
    gd::vector<GroupCommandObject2> m_unkVector560;
    gd::unordered_map<int, std::pair<double, double>> m_unkMap578;
    gd::vector<GroupCommandObject2*> m_unkVector5b0;
    gd::unordered_map<int, gd::vector<GroupCommandObject2*>> m_unkMap5c8;
    gd::vector<GroupCommandObject2*> m_unkVector600;
    gd::unordered_map<int, CCMoveCNode*> m_unkMap618;
    gd::unordered_map<int, CCMoveCNode*> m_unkMap650;
    gd::unordered_map<int, CCMoveCNode*> m_unkMap688;
    gd::vector<CCMoveCNode*> m_unkVector6c0;
    gd::vector<CCMoveCNode*> m_unkVector6d8;
    gd::vector<CCMoveCNode*> m_unkVector6f0;
    gd::vector<DynamicMoveCalculation> m_unkVector708;
    gd::map<std::pair<int, int>, gd::vector<GroupCommandObject2*>> m_unkMap770;
    float m_unk780;
    float m_unk784;
    float m_unk788;
    float m_unk78C;
    float m_unk790;
    float m_unk794;
    bool m_unk798;
};
