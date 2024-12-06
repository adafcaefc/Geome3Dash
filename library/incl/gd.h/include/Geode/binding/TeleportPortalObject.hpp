#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "RingObject.hpp"

class TeleportPortalObject : public RingObject {
public:
    static constexpr auto CLASS_NAME = "TeleportPortalObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(TeleportPortalObject, RingObject)

    /**
     * @note[short] MacOS (ARM): 0x16da24
     * @note[short] MacOS (Intel): 0x1ac900
     * @note[short] Windows: 0x499670
     * @note[short] Android
     */
    static TeleportPortalObject* create(char const* p0, bool p1);
    
private:
    [[deprecated("TeleportPortalObject::setPosition not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16dd84
     * @note[short] MacOS (Intel): 0x1acca0
     * @note[short] iOS: 0x380764
     * @note[short] Android
     */
    virtual void setPosition(cocos2d::CCPoint const& p0);
public:
    
private:
    [[deprecated("TeleportPortalObject::setRotation not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16de2c
     * @note[short] MacOS (Intel): 0x1acd50
     * @note[short] iOS: 0x38080c
     * @note[short] Android
     */
    virtual void setRotation(float p0);
public:
    
private:
    [[deprecated("TeleportPortalObject::setStartPos not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16dbec
     * @note[short] MacOS (Intel): 0x1acb00
     * @note[short] iOS: 0x3805d8
     * @note[short] Android
     */
    virtual void setStartPos(cocos2d::CCPoint p0);
public:
    
private:
    [[deprecated("TeleportPortalObject::customObjectSetup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16fd10
     * @note[short] MacOS (Intel): 0x1af440
     * @note[short] iOS: 0x381168
     * @note[short] Android
     */
    virtual void customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1);
public:
    
private:
    [[deprecated("TeleportPortalObject::getSaveString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16df90
     * @note[short] MacOS (Intel): 0x1acea0
     * @note[short] iOS: 0x380960
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* p0);
public:
    
private:
    [[deprecated("TeleportPortalObject::addToGroup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16dea8
     * @note[short] MacOS (Intel): 0x1acde0
     * @note[short] iOS: 0x380888
     * @note[short] Android
     */
    virtual void addToGroup(int p0);
public:
    
private:
    [[deprecated("TeleportPortalObject::removeFromGroup not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16df2c
     * @note[short] MacOS (Intel): 0x1ace40
     * @note[short] iOS: 0x3808fc
     * @note[short] Android
     */
    virtual void removeFromGroup(int p0);
public:
    
private:
    [[deprecated("TeleportPortalObject::setRotation2 not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16de9c
     * @note[short] MacOS (Intel): 0x1acdb0
     * @note[short] iOS: 0x38087c
     * @note[short] Android
     */
    virtual void setRotation2(float p0);
public:
    
private:
    [[deprecated("TeleportPortalObject::addToGroup2 not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16dea0
     * @note[short] MacOS (Intel): 0x1acdc0
     * @note[short] iOS: 0x380880
     * @note[short] Android
     */
    virtual void addToGroup2(int p0);
public:
    
private:
    [[deprecated("TeleportPortalObject::removeFromGroup2 not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x16dea4
     * @note[short] MacOS (Intel): 0x1acdd0
     * @note[short] iOS: 0x380884
     * @note[short] Android
     */
    virtual void removeFromGroup2(int p0);
public:

    /**
     * @note[short] MacOS (Intel): 0x1acbd0
     * @note[short] Windows: 0x4998f0
     * @note[short] Android
     */
    TodoReturn getTeleportXOff(cocos2d::CCNode* p0);
    
private:
    [[deprecated("TeleportPortalObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(char const* p0, bool p1);
public:
    
private:
    [[deprecated("TeleportPortalObject::setPositionOverride not implemented")]]
    /**
     * @note[short] Android
     */
    void setPositionOverride(cocos2d::CCPoint p0);
public:
    
private:
    [[deprecated("TeleportPortalObject::setStartPosOverride not implemented")]]
    /**
     * @note[short] Android
     */
    void setStartPosOverride(cocos2d::CCPoint p0);
public:
    TeleportPortalObject* m_orangePortal;
    bool m_isYellowPortal;
    float m_teleportYOffset;
    bool m_teleportEase;
    bool m_staticForceEnabled;
    int m_staticForce;
    bool m_redirectForceEnabled;
    float m_redirectForceMod;
    float m_redirectForceMin;
    float m_redirectForceMax;
    bool m_saveOffset;
    bool m_ignoreX;
    bool m_ignoreY;
    int m_gravityMode;
    bool m_property443;
    bool m_property464;
    bool m_property510;
    bool m_property591;
    GJBaseGameLayer* m_gameLayer;
};
