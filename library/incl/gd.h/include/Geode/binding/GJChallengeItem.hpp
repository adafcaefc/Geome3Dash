#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GJChallengeItem : public cocos2d::CCObject {
public:
    static constexpr auto CLASS_NAME = "GJChallengeItem";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJChallengeItem, cocos2d::CCObject)
    
private:
    [[deprecated("GJChallengeItem::create not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8286c
     * @note[short] Android
     */
    static GJChallengeItem* create();
public:
    
private:
    [[deprecated("GJChallengeItem::create not implemented")]]
    /**
     * @note[short] Android
     */
    static GJChallengeItem* create(GJChallengeType challengeType, int goal, int reward, int timeLeft, gd::string questName);
public:
    
private:
    [[deprecated("GJChallengeItem::createFromString not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x8ef00
     * @note[short] Android
     */
    static GJChallengeItem* createFromString(gd::string string);
public:
    
private:
    [[deprecated("GJChallengeItem::createWithCoder not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x82a9c
     * @note[short] MacOS (Intel): 0x8f320
     * @note[short] Android
     */
    static GJChallengeItem* createWithCoder(DS_Dictionary* dsdict);
public:

    /**
     * @note[short] MacOS (ARM): 0x82c58
     * @note[short] MacOS (Intel): 0x8f4c0
     * @note[short] Windows: 0x1f16a0
     * @note[short] iOS: 0x340730
     * @note[short] Android
     */
    virtual void encodeWithCoder(DS_Dictionary* dsdict);
    
private:
    [[deprecated("GJChallengeItem::canEncode not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x82d34
     * @note[short] MacOS (Intel): 0x8f590
     * @note[short] iOS: 0x34080c
     * @note[short] Android
     */
    virtual bool canEncode();
public:
    
private:
    [[deprecated("GJChallengeItem::dataLoaded not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x82af0
     * @note[short] MacOS (Intel): 0x8f360
     * @note[short] Android
     */
    void dataLoaded(DS_Dictionary* dsdict);
public:
    
private:
    [[deprecated("GJChallengeItem::incrementCount not implemented")]]
    /**
     * @note[short] Android
     */
    void incrementCount(int add);
public:
    
private:
    [[deprecated("GJChallengeItem::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(GJChallengeType challengeType, int goal, int reward, int timeLeft, gd::string questName);
public:
    
private:
    [[deprecated("GJChallengeItem::setCount not implemented")]]
    /**
     * @note[short] Android
     */
    void setCount(int value);
public:
    GJChallengeType m_challengeType;
    geode::SeedValueSRV m_count;
    geode::SeedValueSRV m_reward;
    geode::SeedValueSRV m_goal;
    int m_timeLeft;
    bool m_canClaim;
    int m_position;
    gd::string m_name;
};
