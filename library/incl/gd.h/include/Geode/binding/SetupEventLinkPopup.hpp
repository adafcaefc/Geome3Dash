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

class SetupEventLinkPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupEventLinkPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupEventLinkPopup, SetupTriggerPopup)
    
private:
    [[deprecated("SetupEventLinkPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupEventLinkPopup* create(EventLinkTrigger* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupEventLinkPopup::init not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4b6fa8
     * @note[short] MacOS (Intel): 0x560620
     * @note[short] Android
     */
    bool init(EventLinkTrigger* p0, cocos2d::CCArray* p1);
public:
    
private:
    [[deprecated("SetupEventLinkPopup::onSelectEvent not implemented")]]
    /**
     * @note[short] Android
     */
    void onSelectEvent(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetupEventLinkPopup::updateEventIDs not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateEventIDs(gd::set<int>& p0);
public:
};
