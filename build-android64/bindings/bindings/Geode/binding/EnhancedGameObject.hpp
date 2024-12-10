#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "GameObject.hpp"

class EnhancedGameObject : public GameObject {
public:
    static constexpr auto CLASS_NAME = "EnhancedGameObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(EnhancedGameObject, GameObject)

    /**
     * @note[short] Android
     */
    static EnhancedGameObject* create(char const* p0);

    /**
     * @note[short] MacOS (ARM): 0x4ec86c
     * @note[short] MacOS (Intel): 0x5b42e0
     * @note[short] Windows: 0x1a1ff0
     * @note[short] iOS: 0x262680
     * @note[short] Android
     */
    virtual void customSetup();

    /**
     * @note[short] MacOS (ARM): 0x4ec1fc
     * @note[short] MacOS (Intel): 0x5b3b10
     * @note[short] Windows: 0x1a19b0
     * @note[short] iOS: 0x2620bc
     * @note[short] Android
     */
    virtual void resetObject();

    /**
     * @note[short] MacOS (ARM): 0x4ed9e8
     * @note[short] MacOS (Intel): 0x5b7190
     * @note[short] iOS: 0x26389c
     * @note[short] Android
     */
    virtual void deactivateObject(bool p0);

    /**
     * @note[short] MacOS (ARM): 0x4ec4b0
     * @note[short] MacOS (Intel): 0x5b3df0
     * @note[short] iOS: 0x26234c
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);

    /**
     * @note[short] MacOS (ARM): 0x4eda50
     * @note[short] MacOS (Intel): 0x5b71f0
     * @note[short] iOS: 0x263904
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);

    /**
     * @note[short] MacOS (ARM): 0x4ec328
     * @note[short] MacOS (Intel): 0x5b3c80
     * @note[short] iOS: 0x2621e8
     * @note[short] Android
     */
    virtual void triggerActivated(float p0);

    /**
     * @note[short] MacOS (ARM): 0x4ec278
     * @note[short] MacOS (Intel): 0x5b3bb0
     * @note[short] iOS: 0x262138
     * @note[short] Android
     */
    virtual void restoreObject();

    /**
     * @note[short] MacOS (ARM): 0x4ec428
     * @note[short] MacOS (Intel): 0x5b3d50
     * @note[short] iOS: 0x2622c8
     * @note[short] Android
     */
    virtual void animationTriggered();

    /**
     * @note[short] MacOS (ARM): 0x4ec334
     * @note[short] MacOS (Intel): 0x5b3c90
     * @note[short] Windows: 0x1a1b10
     * @note[short] iOS: 0x2621f4
     * @note[short] Android
     */
    virtual void activatedByPlayer(PlayerObject* p0);

    /**
     * @note[short] MacOS (ARM): 0x4ec394
     * @note[short] MacOS (Intel): 0x5b3ce0
     * @note[short] iOS: 0x26224c
     * @note[short] Android
     */
    virtual bool hasBeenActivatedByPlayer(PlayerObject* p0);

    /**
     * @note[short] MacOS (ARM): 0x4ec408
     * @note[short] MacOS (Intel): 0x5b3d30
     * @note[short] iOS: 0x2622a8
     * @note[short] Android
     */
    virtual bool hasBeenActivated();

    /**
     * @note[short] MacOS (ARM): 0x4ec438
     * @note[short] MacOS (Intel): 0x5b3d70
     * @note[short] iOS: 0x2622d8
     * @note[short] Android
     */
    virtual void saveActiveColors();

    /**
     * @note[short] MacOS (ARM): 0x4ec104
     * @note[short] MacOS (Intel): 0x5b3810
     * @note[short] iOS: 0x261f88
     * @note[short] Android
     */
    virtual bool canAllowMultiActivate();

    /**
     * @note[short] MacOS (ARM): 0x199ae8
     * @note[short] MacOS (Intel): 0x1e1cd0
     * @note[short] iOS: 0x26466c
     * @note[short] Android
     */
    virtual bool getHasSyncedAnimation();

    /**
     * @note[short] MacOS (ARM): 0x199af0
     * @note[short] MacOS (Intel): 0x1e1ce0
     * @note[short] iOS: 0x264674
     * @note[short] Android
     */
    virtual bool getHasRotateAction();

    /**
     * @note[short] MacOS (ARM): 0x4ec304
     * @note[short] MacOS (Intel): 0x5b3c60
     * @note[short] iOS: 0x2621c4
     * @note[short] Android
     */
    virtual bool canMultiActivate(bool p0);

    /**
     * @note[short] MacOS (ARM): 0x4ec2b0
     * @note[short] MacOS (Intel): 0x5b3bf0
     * @note[short] iOS: 0x262170
     * @note[short] Android
     */
    virtual TodoReturn powerOnObject(int p0);

    /**
     * @note[short] MacOS (ARM): 0x4ec2c4
     * @note[short] MacOS (Intel): 0x5b3c10
     * @note[short] iOS: 0x262184
     * @note[short] Android
     */
    virtual TodoReturn powerOffObject();

    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual TodoReturn stateSensitiveOff(GJBaseGameLayer* p0);

    /**
     * @note[short] MacOS (ARM): 0x1f7c7c
     * @note[short] MacOS (Intel): 0x2499e0
     * @note[short] Windows: 0x1a4e30
     * @note[short] iOS: 0x347598
     * @note[short] Android
     */
    virtual void updateSyncedAnimation(float p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0x1f903c
     * @note[short] MacOS (Intel): 0x24b920
     * @note[short] iOS: 0x348938
     * @note[short] Android
     */
    virtual TodoReturn updateAnimateOnTrigger(bool p0);

    /**
     * @note[short] Android
     */
    TodoReturn createRotateAction(float p0, int p1);

    /**
     * @note[short] Windows: 0x1a1800
     * @note[short] Android
     */
    bool init(char const* p0);

    /**
     * @note[short] Android
     */
    TodoReturn previewAnimateOnTrigger();

    /**
     * @note[short] Android
     */
    TodoReturn refreshRotateAction();

    /**
     * @note[short] Android
     */
    TodoReturn resetSyncedAnimation();

    /**
     * @note[short] Android
     */
    TodoReturn resumeAudio();

    /**
     * @note[short] Android
     */
    TodoReturn resumeAudioDelayed();

    /**
     * @note[short] Android
     */
    TodoReturn setupAnimationVariables();

    /**
     * @note[short] Android
     */
    TodoReturn triggerAnimation();

    /**
     * @note[short] Android
     */
    TodoReturn updateRotateAction(float p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateState(int p0);

    /**
     * @note[short] MacOS (ARM): 0x4e3b94
     * @note[short] MacOS (Intel): 0x5a9770
     * @note[short] Windows: 0x1a3970
     * @note[short] Android
     */
    void updateUserCoin();

    /**
     * @note[short] Android
     */
    TodoReturn waitForAnimationTrigger();
    GEODE_PAD(34);
    bool m_hasCustomAnimation;
    bool m_hasCustomRotation;
    bool m_disableRotation;
    GEODE_PAD(3);
    float m_rotationSpeed;
    GEODE_PAD(12);
    bool m_animationRandomizedStart;
    float m_animationSpeed;
    bool m_animationShouldUseSpeed;
    bool m_animateOnTrigger;
    bool m_disableDelayedLoop;
    bool m_disableAnimShine;
    int m_singleFrame;
    bool m_animationOffset;
    GEODE_PAD(15);
    bool m_animateOnlyWhenActive;
    bool m_isNoMultiActivate;
    bool m_isMultiActivate;
    GEODE_PAD(8);
};
