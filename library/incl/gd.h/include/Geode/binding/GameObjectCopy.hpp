#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GameObjectCopy : public cocos2d::CCObject {
public:
    static constexpr auto CLASS_NAME = "GameObjectCopy";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GameObjectCopy, cocos2d::CCObject)
    
private:
    [[deprecated("GameObjectCopy::create not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0xe3820
     * @note[short] Android
     */
    static GameObjectCopy* create(GameObject* p0);
public:
    
private:
    [[deprecated("GameObjectCopy::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(GameObject* p0);
public:

    /**
     * @note[short] MacOS (Intel): 0xe3940
     * @note[short] Windows: 0x2db140
     * @note[short] Android
     */
    void resetObject();
    GameObject* m_object;
    cocos2d::CCPoint m_position;
    float m_rotationX;
    float m_rotationY;
    bool m_isFlipX;
    bool m_isFlipY;
    float m_customScaleX;
    float m_customScaleY;
};
