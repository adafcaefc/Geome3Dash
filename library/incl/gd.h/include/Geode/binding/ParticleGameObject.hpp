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
    
private:
    [[deprecated("ParticleGameObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static ParticleGameObject* create();
public:
    
private:
    [[deprecated("ParticleGameObject::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1633a0
     * @note[short] MacOS (Intel): 0x1a08c0
     * @note[short] iOS: 0x379a74
     * @note[short] Android
     */
    virtual bool init();
public:
    
private:
    [[deprecated("ParticleGameObject::setScaleX not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x164424
     * @note[short] MacOS (Intel): 0x1a1960
     * @note[short] iOS: 0x37a8d4
     * @note[short] Android
     */
    virtual void setScaleX(float p0);
public:
    
private:
    [[deprecated("ParticleGameObject::setScaleY not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x164494
     * @note[short] MacOS (Intel): 0x1a19d0
     * @note[short] iOS: 0x37a920
     * @note[short] Android
     */
    virtual void setScaleY(float p0);
public:
    
private:
    [[deprecated("ParticleGameObject::setScale not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x164504
     * @note[short] MacOS (Intel): 0x1a1a40
     * @note[short] iOS: 0x37a96c
     * @note[short] Android
     */
    virtual void setScale(float p0);
public:
    
private:
    [[deprecated("ParticleGameObject::setRotation not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x164340
     * @note[short] MacOS (Intel): 0x1a18a0
     * @note[short] iOS: 0x37a7f0
     * @note[short] Android
     */
    virtual void setRotation(float p0);
public:
    
private:
    [[deprecated("ParticleGameObject::setRotationX not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16438c
     * @note[short] MacOS (Intel): 0x1a18e0
     * @note[short] iOS: 0x37a83c
     * @note[short] Android
     */
    virtual void setRotationX(float p0);
public:
    
private:
    [[deprecated("ParticleGameObject::setRotationY not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1643d8
     * @note[short] MacOS (Intel): 0x1a1920
     * @note[short] iOS: 0x37a888
     * @note[short] Android
     */
    virtual void setRotationY(float p0);
public:
    
private:
    [[deprecated("ParticleGameObject::setChildColor not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x164668
     * @note[short] MacOS (Intel): 0x1a1ba0
     * @note[short] iOS: 0x37aaac
     * @note[short] Android
     */
    virtual void setChildColor(cocos2d::ccColor3B const& p0);
public:
    
private:
    [[deprecated("ParticleGameObject::customSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1635f0
     * @note[short] MacOS (Intel): 0x1a0b90
     * @note[short] iOS: 0x379c5c
     * @note[short] Android
     */
    virtual void customSetup();
public:
    
private:
    [[deprecated("ParticleGameObject::addMainSpriteToParent not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16369c
     * @note[short] MacOS (Intel): 0x1a0c60
     * @note[short] iOS: 0x379d08
     * @note[short] Android
     */
    virtual void addMainSpriteToParent(bool p0);
public:
    
private:
    [[deprecated("ParticleGameObject::resetObject not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x164834
     * @note[short] MacOS (Intel): 0x1a1d90
     * @note[short] iOS: 0x37ac6c
     * @note[short] Android
     */
    virtual void resetObject();
public:
    
private:
    [[deprecated("ParticleGameObject::deactivateObject not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1647f0
     * @note[short] MacOS (Intel): 0x1a1d50
     * @note[short] iOS: 0x37ac34
     * @note[short] Android
     */
    virtual void deactivateObject(bool p0);
public:
    
private:
    [[deprecated("ParticleGameObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1633d8
     * @note[short] MacOS (Intel): 0x1a08f0
     * @note[short] iOS: 0x379aac
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:
    
private:
    [[deprecated("ParticleGameObject::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x164a28
     * @note[short] MacOS (Intel): 0x1a1f90
     * @note[short] iOS: 0x37ae4c
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
public:
    
private:
    [[deprecated("ParticleGameObject::claimParticle not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16377c
     * @note[short] MacOS (Intel): 0x1a0d40
     * @note[short] iOS: 0x379de8
     * @note[short] Android
     */
    virtual void claimParticle();
public:
    
private:
    [[deprecated("ParticleGameObject::unclaimParticle not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x163d44
     * @note[short] MacOS (Intel): 0x1a12e0
     * @note[short] iOS: 0x37a390
     * @note[short] Android
     */
    virtual void unclaimParticle();
public:
    
private:
    [[deprecated("ParticleGameObject::particleWasActivated not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x163dd0
     * @note[short] MacOS (Intel): 0x1a1360
     * @note[short] iOS: 0x37a410
     * @note[short] Android
     */
    virtual void particleWasActivated();
public:
    
private:
    [[deprecated("ParticleGameObject::setObjectColor not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x164574
     * @note[short] MacOS (Intel): 0x1a1ab0
     * @note[short] iOS: 0x37a9b8
     * @note[short] Android
     */
    virtual void setObjectColor(cocos2d::ccColor3B const& p0);
public:
    
private:
    [[deprecated("ParticleGameObject::blendModeChanged not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16366c
     * @note[short] MacOS (Intel): 0x1a0c20
     * @note[short] iOS: 0x379cd8
     * @note[short] Android
     */
    virtual void blendModeChanged();
public:
    
private:
    [[deprecated("ParticleGameObject::updateParticleColor not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual void updateParticleColor(cocos2d::ccColor3B const& p0);
public:
    
private:
    [[deprecated("ParticleGameObject::updateParticleOpacity not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual void updateParticleOpacity(unsigned char p0);
public:
    
private:
    [[deprecated("ParticleGameObject::updateMainParticleOpacity not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16475c
     * @note[short] MacOS (Intel): 0x1a1c90
     * @note[short] iOS: 0x37aba0
     * @note[short] Android
     */
    virtual void updateMainParticleOpacity(unsigned char p0);
public:
    
private:
    [[deprecated("ParticleGameObject::updateSecondaryParticleOpacity not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1647a8
     * @note[short] MacOS (Intel): 0x1a1cf0
     * @note[short] iOS: 0x37abec
     * @note[short] Android
     */
    virtual void updateSecondaryParticleOpacity(unsigned char p0);
public:
    
private:
    [[deprecated("ParticleGameObject::updateSyncedAnimation not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16489c
     * @note[short] MacOS (Intel): 0x1a1df0
     * @note[short] iOS: 0x37acd4
     * @note[short] Android
     */
    virtual void updateSyncedAnimation(float p0, int p1);
public:
    
private:
    [[deprecated("ParticleGameObject::updateAnimateOnTrigger not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1649d8
     * @note[short] MacOS (Intel): 0x1a1f40
     * @note[short] iOS: 0x37adfc
     * @note[short] Android
     */
    virtual TodoReturn updateAnimateOnTrigger(bool p0);
public:
    
private:
    [[deprecated("ParticleGameObject::applyParticleSettings not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn applyParticleSettings(cocos2d::CCParticleSystemQuad* p0);
public:
    
private:
    [[deprecated("ParticleGameObject::createAndAddCustomParticle not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createAndAddCustomParticle();
public:
    
private:
    [[deprecated("ParticleGameObject::createParticlePreviewArt not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x164140
     * @note[short] MacOS (Intel): 0x1a16c0
     * @note[short] Android
     */
    TodoReturn createParticlePreviewArt();
public:

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
    
private:
    [[deprecated("ParticleGameObject::updateParticleAngle not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x1a11d0
     * @note[short] Android
     */
    TodoReturn updateParticleAngle(float p0, cocos2d::CCParticleSystemQuad* p1);
public:
    
private:
    [[deprecated("ParticleGameObject::updateParticlePreviewArtOpacity not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateParticlePreviewArtOpacity(float p0);
public:
    
private:
    [[deprecated("ParticleGameObject::updateParticleScale not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateParticleScale(float p0);
public:
    
private:
    [[deprecated("ParticleGameObject::updateParticleStruct not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x1a0d10
     * @note[short] Android
     */
    TodoReturn updateParticleStruct();
public:
    gd::string m_particleData;
    bool m_updatedParticleData;
    GEODE_PAD(291);
    bool m_hasUniformObjectColor;
    GEODE_PAD(7);
    bool m_shouldQuickStart;
    GEODE_PAD(15);
};
