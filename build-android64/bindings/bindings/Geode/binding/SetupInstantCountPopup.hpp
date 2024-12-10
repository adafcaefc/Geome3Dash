#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "SetupTriggerPopup.hpp"

class SetupInstantCountPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupInstantCountPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupInstantCountPopup, SetupTriggerPopup)

    /**
     * @note[short] Windows: 0x40a520
     * @note[short] Android
     */
    static SetupInstantCountPopup* create(CountTriggerGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] MacOS (ARM): 0x505b58
     * @note[short] MacOS (Intel): 0x5d1dc0
     * @note[short] iOS: 0x1bebe0
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x506090
     * @note[short] MacOS (Intel): 0x5d23f0
     * @note[short] iOS: 0x1befc0
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x505e14
     * @note[short] MacOS (Intel): 0x5d2100
     * @note[short] Windows: 0x40b740
     * @note[short] iOS: 0x1bee80
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);

    /**
     * @note[short] MacOS (ARM): 0x504958
     * @note[short] MacOS (Intel): 0x5d09c0
     * @note[short] Windows: 0x40a660
     * @note[short] Android
     */
    bool init(CountTriggerGameObject* p0, cocos2d::CCArray* p1);

    /**
     * @note[short] Android
     */
    void onCountType(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onEnableGroup(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onTargetCountArrow(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onTargetID2Arrow(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x4045c0
     * @note[short] Android
     */
    void onTargetIDArrow(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    TodoReturn updateCountTextInputLabel();

    /**
     * @note[short] Windows: 0x401fd0
     * @note[short] Android
     */
    void updateItemID();

    /**
     * @note[short] Android
     */
    TodoReturn updateItemIDInputLabel();

    /**
     * @note[short] Android
     */
    TodoReturn updateTargetCount();

    /**
     * @note[short] Android
     */
    TodoReturn updateTargetID();

    /**
     * @note[short] Android
     */
    TodoReturn updateTargetIDInputLabel();
    CCTextInputNode* m_unk3a8;
    CCTextInputNode* m_unk3b0;
    CCTextInputNode* m_unk3b8;
    int m_itemID;
    int m_targetID;
    int m_targetCount;
    int m_unk3cc;
    int m_mode;
};
