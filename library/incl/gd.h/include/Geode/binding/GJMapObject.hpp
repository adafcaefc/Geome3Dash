#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJMapObject : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "GJMapObject";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJMapObject, cocos2d::CCNode)
    
private:
    [[deprecated("GJMapObject::create not implemented")]]
    /**
     * @note[short] Android
     */
    static GJMapObject* create(cocos2d::CCNode* p0);
public:
    
private:
    [[deprecated("GJMapObject::createMonster not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createMonster(int p0);
public:
    
private:
    [[deprecated("GJMapObject::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(cocos2d::CCNode* p0);
public:
    
private:
    [[deprecated("GJMapObject::monsterIdle not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn monsterIdle();
public:
    
private:
    [[deprecated("GJMapObject::monsterJump not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn monsterJump();
public:
    
private:
    [[deprecated("GJMapObject::moveFinished not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn moveFinished();
public:
    
private:
    [[deprecated("GJMapObject::moveMonster not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn moveMonster();
public:
    
private:
    [[deprecated("GJMapObject::moveMonster not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn moveMonster(cocos2d::CCPoint p0, float p1);
public:
    
private:
    [[deprecated("GJMapObject::playerJump not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn playerJump();
public:
    
private:
    [[deprecated("GJMapObject::setObjectOrigin not implemented")]]
    /**
     * @note[short] Android
     */
    void setObjectOrigin(cocos2d::CCPoint p0, float p1);
public:
    
private:
    [[deprecated("GJMapObject::startMonsterJumpLoop not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn startMonsterJumpLoop();
public:
    
private:
    [[deprecated("GJMapObject::startPlayerJumpLoop not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn startPlayerJumpLoop();
public:
    
private:
    [[deprecated("GJMapObject::touchMonster not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn touchMonster();
public:
    
private:
    [[deprecated("GJMapObject::updateShadow not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateShadow(float p0, float p1, cocos2d::CCPoint p2);
public:
};
