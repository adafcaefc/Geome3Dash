#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class AchievementNotifier : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "AchievementNotifier";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(AchievementNotifier, cocos2d::CCNode)

    /**
     * @note[short] MacOS (ARM): 0x6beb0c
     * @note[short] MacOS (Intel): 0x7ad380
     * @note[short] Windows: 0x3ab20
     * @note[short] Android
     */
    static AchievementNotifier* sharedState();
    
private:
    [[deprecated("AchievementNotifier::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x6beb88
     * @note[short] MacOS (Intel): 0x7ad410
     * @note[short] iOS: 0x21727c
     * @note[short] Android
     */
    virtual bool init();
public:
    
private:
    [[deprecated("AchievementNotifier::achievementDisplayFinished not implemented")]]
    /**
     * @note[short] Android
     */
    void achievementDisplayFinished();
public:

    /**
     * @note[short] MacOS (ARM): 0x6bebb4
     * @note[short] MacOS (Intel): 0x7ad440
     * @note[short] Windows: 0x3ac00
     * @note[short] Android
     */
    void notifyAchievement(char const* title, char const* desc, char const* icon, bool quest);

    /**
     * @note[short] Windows: 0x3ace0
     * @note[short] Android
     */
    void showNextAchievement();

    /**
     * @note[short] MacOS (ARM): 0x6bed64
     * @note[short] MacOS (Intel): 0x7ad5f0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void willSwitchToScene(cocos2d::CCScene* scene);
    cocos2d::CCScene* m_nextScene;
    cocos2d::CCArray* m_achievementBarArray;
    AchievementBar* m_activeAchievementBar;
};
