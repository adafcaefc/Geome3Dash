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

class ParticleGameObject : public EnhancedGameObject {
public:
    static constexpr auto CLASS_NAME = "ParticleGameObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(ParticleGameObject, EnhancedGameObject)

    /**
     * @note[short] Android
     */
    static ParticleGameObject* create();

    /**
     * @note[short] MacOS (ARM): 0x1633a0
     * @note[short] MacOS (Intel): 0x1a08c0
     * @note[short] iOS: 0x379a74
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (ARM): 0x164424
     * @note[short] MacOS (Intel): 0x1a1960
     * @note[short] iOS: 0x37a8d4
     * @note[short] Android
     */
    virtual void setScaleX(float p0);

    /**
     * @note[short] MacOS (ARM): 0x164494
     * @note[short] MacOS (Intel): 0x1a19d0
     * @note[short] iOS: 0x37a920
     * @note[short] Android
     */
    virtual void setScaleY(float p0);

    /**
     * @note[short] MacOS (ARM): 0x164504
     * @note[short] MacOS (Intel): 0x1a1a40
     * @note[short] iOS: 0x37a96c
     * @note[short] Android
     */
    virtual void setScale(float p0);

    /**
     * @note[short] MacOS (ARM): 0x164340
     * @note[short] MacOS (Intel): 0x1a18a0
     * @note[short] iOS: 0x37a7f0
     * @note[short] Android
     */
    virtual void setRotation(float p0);

    /**
     * @note[short] MacOS (ARM): 0x16438c
     * @note[short] MacOS (Intel): 0x1a18e0
     * @note[short] iOS: 0x37a83c
     * @note[short] Android
     */
    virtual void setRotationX(float p0);

    /**
     * @note[short] MacOS (ARM): 0x1643d8
     * @note[short] MacOS (Intel): 0x1a1920
     * @note[short] iOS: 0x37a888
     * @note[short] Android
     */
    virtual void setRotationY(float p0);

    /**
     * @note[short] MacOS (ARM): 0x164668
     * @note[short] MacOS (Intel): 0x1a1ba0
     * @note[short] iOS: 0x37aaac
     * @note[short] Android
     */
    virtual void setChildColor(cocos2d::ccColor3B const& p0);

    /**
     * @note[short] MacOS (ARM): 0x1635f0
     * @note[short] MacOS (Intel): 0x1a0b90
     * @note[short] iOS: 0x379c5c
     * @note[short] Android
     */
    virtual void customSetup();

    /**
     * @note[short] MacOS (ARM): 0x16369c
     * @note[short] MacOS (Intel): 0x1a0c60
     * @note[short] iOS: 0x379d08
     * @note[short] Android
     */
    virtual void addMainSpriteToParent(bool p0);

    /**
     * @note[short] MacOS (ARM): 0x164834
     * @note[short] MacOS (Intel): 0x1a1d90
     * @note[short] iOS: 0x37ac6c
     * @note[short] Android
     */
    virtual void resetObject();

    /**
     * @note[short] MacOS (ARM): 0x1647f0
     * @note[short] MacOS (Intel): 0x1a1d50
     * @note[short] iOS: 0x37ac34
     * @note[short] Android
     */
    virtual void deactivateObject(bool p0);

    /**
     * @note[short] MacOS (ARM): 0x1633d8
     * @note[short] MacOS (Intel): 0x1a08f0
     * @note[short] iOS: 0x379aac
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);

    /**
     * @note[short] MacOS (ARM): 0x164a28
     * @note[short] MacOS (Intel): 0x1a1f90
     * @note[short] iOS: 0x37ae4c
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);

    /**
     * @note[short] MacOS (ARM): 0x16377c
     * @note[short] MacOS (Intel): 0x1a0d40
     * @note[short] iOS: 0x379de8
     * @note[short] Android
     */
    virtual void claimParticle();

    /**
     * @note[short] MacOS (ARM): 0x163d44
     * @note[short] MacOS (Intel): 0x1a12e0
     * @note[short] iOS: 0x37a390
     * @note[short] Android
     */
    virtual void unclaimParticle();

    /**
     * @note[short] MacOS (ARM): 0x163dd0
     * @note[short] MacOS (Intel): 0x1a1360
     * @note[short] iOS: 0x37a410
     * @note[short] Android
     */
    virtual void particleWasActivated();

    /**
     * @note[short] MacOS (ARM): 0x164574
     * @note[short] MacOS (Intel): 0x1a1ab0
     * @note[short] iOS: 0x37a9b8
     * @note[short] Android
     */
    virtual void setObjectColor(cocos2d::ccColor3B const& p0);

    /**
     * @note[short] MacOS (ARM): 0x16366c
     * @note[short] MacOS (Intel): 0x1a0c20
     * @note[short] iOS: 0x379cd8
     * @note[short] Android
     */
    virtual void blendModeChanged();

    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual void updateParticleColor(cocos2d::ccColor3B const& p0);

    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual void updateParticleOpacity(unsigned char p0);

    /**
     * @note[short] MacOS (ARM): 0x16475c
     * @note[short] MacOS (Intel): 0x1a1c90
     * @note[short] iOS: 0x37aba0
     * @note[short] Android
     */
    virtual void updateMainParticleOpacity(unsigned char p0);

    /**
     * @note[short] MacOS (ARM): 0x1647a8
     * @note[short] MacOS (Intel): 0x1a1cf0
     * @note[short] iOS: 0x37abec
     * @note[short] Android
     */
    virtual void updateSecondaryParticleOpacity(unsigned char p0);

    /**
     * @note[short] MacOS (ARM): 0x16489c
     * @note[short] MacOS (Intel): 0x1a1df0
     * @note[short] iOS: 0x37acd4
     * @note[short] Android
     */
    virtual void updateSyncedAnimation(float p0, int p1);

    /**
     * @note[short] MacOS (ARM): 0x1649d8
     * @note[short] MacOS (Intel): 0x1a1f40
     * @note[short] iOS: 0x37adfc
     * @note[short] Android
     */
    virtual TodoReturn updateAnimateOnTrigger(bool p0);

    /**
     * @note[short] Android
     */
    TodoReturn applyParticleSettings(cocos2d::CCParticleSystemQuad* p0);

    /**
     * @note[short] Android
     */
    TodoReturn createAndAddCustomParticle();

    /**
     * @note[short] MacOS (ARM): 0x164140
     * @note[short] MacOS (Intel): 0x1a16c0
     * @note[short] Android
     */
    TodoReturn createParticlePreviewArt();

    /**
     * @note[short] MacOS (ARM): 0x163f24
     * @note[short] MacOS (Intel): 0x1a14a0
     * @note[short] Windows: 0x4880b0
     * @note[short] Android
     */
    void setParticleString(gd::string p0);

    /**
     * @note[short] MacOS (Intel): 0x1a1530
     * @note[short] Windows: 0x488140
     * @note[short] Android
     */
    void updateParticle();

    /**
     * @note[short] MacOS (Intel): 0x1a11d0
     * @note[short] Android
     */
    TodoReturn updateParticleAngle(float p0, cocos2d::CCParticleSystemQuad* p1);

    /**
     * @note[short] Android
     */
    TodoReturn updateParticlePreviewArtOpacity(float p0);

    /**
     * @note[short] Android
     */
    TodoReturn updateParticleScale(float p0);

    /**
     * @note[short] MacOS (Intel): 0x1a0d10
     * @note[short] Android
     */
    TodoReturn updateParticleStruct();
    gd::string m_particleData;
    bool m_updatedParticleData;
private:
    bool m_hasUniformObjectColor;
public:
private:
    bool m_shouldQuickStart;
public:
};
