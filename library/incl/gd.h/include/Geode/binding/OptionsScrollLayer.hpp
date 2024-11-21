#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "FLAlertLayer.hpp"
#include "TableViewCellDelegate.hpp"

class OptionsScrollLayer : public FLAlertLayer, public TableViewCellDelegate {
public:
    static constexpr auto CLASS_NAME = "OptionsScrollLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(OptionsScrollLayer, FLAlertLayer)
    
private:
    [[deprecated("OptionsScrollLayer::create not implemented")]]
    /**
     * @note[short] Android
     */
    static OptionsScrollLayer* create(cocos2d::CCArray* p0, bool p1, int p2);
public:
    
private:
    [[deprecated("OptionsScrollLayer::registerWithTouchDispatcher not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x5282bc
     * @note[short] MacOS (Intel): 0x5f90f0
     * @note[short] iOS: 0x3bb598
     * @note[short] Android
     */
    virtual void registerWithTouchDispatcher();
public:

    /**
     * @note[short] MacOS (ARM): 0x528198
     * @note[short] MacOS (Intel): 0x5f8fc0
     * @note[short] Windows: 0x326150
     * @note[short] iOS: 0x3bb58c
     * @note[short] Android
     */
    virtual void keyBackClicked();
    
private:
    [[deprecated("OptionsScrollLayer::cellPerformedAction not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x5282f4
     * @note[short] MacOS (Intel): 0x5f9130
     * @note[short] iOS: 0x3bb5d0
     * @note[short] Android
     */
    virtual bool cellPerformedAction(TableViewCell* p0, int p1, CellAction p2, cocos2d::CCNode* p3);
public:
    
private:
    [[deprecated("OptionsScrollLayer::getRelevantObjects not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getRelevantObjects(cocos2d::CCArray* p0);
public:
    
private:
    [[deprecated("OptionsScrollLayer::init not implemented")]]
    /**
     * @note[short] Android
     */
    bool init(cocos2d::CCArray* p0, bool p1, int p2);
public:
    
private:
    [[deprecated("OptionsScrollLayer::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("OptionsScrollLayer::setupList not implemented")]]
    /**
     * @note[short] Android
     */
    void setupList(cocos2d::CCArray* p0);
public:
};
