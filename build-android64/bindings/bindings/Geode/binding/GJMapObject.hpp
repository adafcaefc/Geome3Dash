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

    /**
     * @note[short] Android
     */
    static GJMapObject* create(cocos2d::CCNode* p0);

    /**
     * @note[short] Android
     */
    TodoReturn createMonster(int p0);

    /**
     * @note[short] Android
     */
    bool init(cocos2d::CCNode* p0);

    /**
     * @note[short] Android
     */
    TodoReturn monsterIdle();

    /**
     * @note[short] Android
     */
    TodoReturn monsterJump();

    /**
     * @note[short] Android
     */
    TodoReturn moveFinished();

    /**
     * @note[short] Android
     */
    TodoReturn moveMonster();

    /**
     * @note[short] Android
     */
    TodoReturn moveMonster(cocos2d::CCPoint p0, float p1);

    /**
     * @note[short] Android
     */
    TodoReturn playerJump();

    /**
     * @note[short] Android
     */
    void setObjectOrigin(cocos2d::CCPoint p0, float p1);

    /**
     * @note[short] Android
     */
    TodoReturn startMonsterJumpLoop();

    /**
     * @note[short] Android
     */
    TodoReturn startPlayerJumpLoop();

    /**
     * @note[short] Android
     */
    TodoReturn touchMonster();

    /**
     * @note[short] Android
     */
    TodoReturn updateShadow(float p0, float p1, cocos2d::CCPoint p2);
};
