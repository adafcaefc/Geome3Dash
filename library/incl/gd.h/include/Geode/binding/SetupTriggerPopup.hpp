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
#include "TextInputDelegate.hpp"
#include "ConfigureValuePopupDelegate.hpp"
#include "SliderDelegate.hpp"

class SetupTriggerPopup : public FLAlertLayer, public TextInputDelegate, public ConfigureValuePopupDelegate, public SliderDelegate {
public:
    static constexpr auto CLASS_NAME = "SetupTriggerPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupTriggerPopup, FLAlertLayer)
    
private:
    [[deprecated("SetupTriggerPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupTriggerPopup* create(EffectGameObject* p0, cocos2d::CCArray* p1, float p2, float p3, int p4);
public:
    
private:
    [[deprecated("SetupTriggerPopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static SetupTriggerPopup* create(float p0, float p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x1df150
     * @note[short] MacOS (Intel): 0x22e3e0
     * @note[short] Windows: 0x93d98
     * @note[short] iOS: 0x13803c
     * @note[short] Android
     */
    virtual bool ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);

    /**
     * @note[short] MacOS (ARM): 0x1d8cf8
     * @note[short] MacOS (Intel): 0x227290
     * @note[short] Windows: 0x44f1d0
     * @note[short] iOS: 0x133bfc
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x1d8b74
     * @note[short] MacOS (Intel): 0x2270d0
     * @note[short] Windows: 0x8ba30
     * @note[short] iOS: 0x133b20
     * @note[short] Android
     */
    virtual void show();

    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0xd590
     * @note[short] Android: Out of line
     */
    virtual void pageChanged();

    /**
     * @note[short] MacOS (ARM): 0x1d68d4
     * @note[short] MacOS (Intel): 0x223a40
     * @note[short] Windows: 0x45c310
     * @note[short] iOS: 0x131ef0
     * @note[short] Android
     */
    virtual void toggleGroup(int group, bool visible);

    /**
     * @note[short] MacOS (ARM): 0x1d7950
     * @note[short] MacOS (Intel): 0x224c20
     * @note[short] Windows: 0x45d060
     * @note[short] iOS: 0x132c40
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x1d8bc0
     * @note[short] MacOS (Intel): 0x227130
     * @note[short] Windows: 0x45d6a0
     * @note[short] iOS: 0x133b6c
     * @note[short] Android
     */
    virtual void onClose(cocos2d::CCObject* sender);
    
private:
    [[deprecated("SetupTriggerPopup::textInputClosed not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1d7c58
     * @note[short] MacOS (Intel): 0x224fa0
     * @note[short] iOS: 0x132e4c
     * @note[short] Android
     */
    virtual void textInputClosed(CCTextInputNode* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x1d7c74
     * @note[short] MacOS (Intel): 0x224fe0
     * @note[short] Windows: 0x45d4e0
     * @note[short] iOS: 0x132e68
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);
    
private:
    [[deprecated("SetupTriggerPopup::textInputShouldOffset not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1d8d1c
     * @note[short] MacOS (Intel): 0x2272d0
     * @note[short] iOS: 0x133c20
     * @note[short] Android
     */
    virtual void textInputShouldOffset(CCTextInputNode* p0, float p1);
public:
    
private:
    [[deprecated("SetupTriggerPopup::textInputReturn not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1d8dec
     * @note[short] MacOS (Intel): 0x227390
     * @note[short] iOS: 0x133c8c
     * @note[short] Android
     */
    virtual void textInputReturn(CCTextInputNode* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0xd590
     * @note[short] Android: Out of line
     */
    virtual void updateInputValue(int p0, float& p1);

    /**
     * @note[short] MacOS (ARM): 0x1d8ea4
     * @note[short] MacOS (Intel): 0x227440
     * @note[short] Windows: 0x45d7e0
     * @note[short] iOS: 0x133cec
     * @note[short] Android
     */
    virtual void sliderBegan(Slider* p0);

    /**
     * @note[short] MacOS (ARM): 0x1d8f7c
     * @note[short] MacOS (Intel): 0x227520
     * @note[short] Windows: 0x45d8b0
     * @note[short] iOS: 0x133db8
     * @note[short] Android
     */
    virtual void sliderEnded(Slider* p0);

    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0xd590
     * @note[short] Android: Out of line
     */
    virtual void onPlusButton(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0xd590
     * @note[short] Android: Out of line
     */
    virtual void onCustomButton(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x1db330
     * @note[short] MacOS (Intel): 0x229910
     * @note[short] Windows: 0x45f370
     * @note[short] iOS: 0x1358f4
     * @note[short] Android
     */
    virtual void updateDefaultTriggerValues();

    /**
     * @note[short] MacOS (ARM): 0x1dcdb8
     * @note[short] MacOS (Intel): 0x22c1e0
     * @note[short] Windows: 0x45f860
     * @note[short] iOS: 0x1363bc
     * @note[short] Android
     */
    virtual TodoReturn updateInputNode(int p0, float p1);

    /**
     * @note[short] MacOS (ARM): 0x1dcfe4
     * @note[short] MacOS (Intel): 0x22c3d0
     * @note[short] Windows: 0x45fc00
     * @note[short] iOS: 0x136588
     * @note[short] Android
     */
    virtual TodoReturn updateToggleItem(int p0, bool p1);

    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0xd590
     * @note[short] Android: Out of line
     */
    virtual void valueDidChange(int p0, float p1);

    /**
     * @note[short] MacOS (ARM): 0x1dd09c
     * @note[short] MacOS (Intel): 0x22c490
     * @note[short] Windows: 0x45fc70
     * @note[short] iOS: 0x1365f8
     * @note[short] Android
     */
    virtual float getValue(int p0);

    /**
     * @note[short] MacOS (ARM): 0x1dd478
     * @note[short] MacOS (Intel): 0x22c840
     * @note[short] Windows: 0x463c60
     * @note[short] iOS: 0x1367f8
     * @note[short] Android
     */
    virtual TodoReturn triggerValueFromSliderValue(int p0, float p1);

    /**
     * @note[short] MacOS (ARM): 0x1dd504
     * @note[short] MacOS (Intel): 0x22c8c0
     * @note[short] Windows: 0x463cf0
     * @note[short] iOS: 0x136864
     * @note[short] Android
     */
    virtual TodoReturn triggerSliderValueFromValue(int p0, float p1);

    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0xd590
     * @note[short] Android: Out of line
     */
    virtual void onCustomToggleTriggerValue(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x1de14c
     * @note[short] MacOS (Intel): 0x22d4e0
     * @note[short] Windows: 0x464c00
     * @note[short] iOS: 0x13733c
     * @note[short] Android
     */
    virtual void valuePopupClosed(ConfigureValuePopup* p0, float p1);

    /**
     * @note[short] Windows: 0x45c590
     * @note[short] Android
     */
    void addCloseButton(gd::string p0);

    /**
     * @note[short] Windows: 0x45c6a0
     * @note[short] Android
     */
    void addHelpButton(gd::string p0, gd::string p1, float p2);

    /**
     * @note[short] Windows: 0x45ee90
     * @note[short] Android
     */
    void addInfoLabel(gd::string p0, float p1, cocos2d::CCPoint p2, int p3, int p4);
    
private:
    [[deprecated("SetupTriggerPopup::addObjectsToGroup not implemented")]]
    /**
     * @note[short] Android
     */
    void addObjectsToGroup(cocos2d::CCArray* p0, int p1);
public:
    
private:
    [[deprecated("SetupTriggerPopup::addObjectsToPage not implemented")]]
    /**
     * @note[short] Android
     */
    void addObjectsToPage(cocos2d::CCArray* p0, int p1);
public:
    
private:
    [[deprecated("SetupTriggerPopup::addObjectToGroup not implemented")]]
    /**
     * @note[short] Android
     */
    void addObjectToGroup(cocos2d::CCObject* p0, int p1);
public:

    /**
     * @note[short] Windows: 0x45c400
     * @note[short] Android
     */
    void addObjectToPage(cocos2d::CCObject* p0, int p1);

    /**
     * @note[short] Windows: 0x45c490
     * @note[short] Android
     */
    void addTitle(gd::string p0);
    
private:
    [[deprecated("SetupTriggerPopup::closeInputNodes not implemented")]]
    /**
     * @note[short] Android
     */
    void closeInputNodes();
public:

    /**
     * @note[short] Windows: 0x45f110
     * @note[short] Android
     */
    void createCustomButton(int p0, gd::string p1, gd::string p2, cocos2d::CCPoint p3, float p4, float p5, bool p6, int p7, int p8);

    /**
     * @note[short] Windows: 0x464cc0
     * @note[short] Android
     */
    void createCustomEasingControls(gd::string p0, cocos2d::CCPoint p1, float p2, int p3, int p4, int p5, int p6);

    /**
     * @note[short] Windows: 0x45ec10
     * @note[short] Android
     */
    void createCustomToggleValueControl(int p0, bool p1, bool p2, gd::string p3, cocos2d::CCPoint p4, bool p5, int p6, int p7);

    /**
     * @note[short] MacOS (ARM): 0x1dd5b4
     * @note[short] MacOS (Intel): 0x22c970
     * @note[short] Windows: 0x463da0
     * @note[short] Android
     */
    void createEasingControls(cocos2d::CCPoint p0, float p1, int p2, int p3);

    /**
     * @note[short] MacOS (ARM): 0x1d71b0
     * @note[short] MacOS (Intel): 0x2243a0
     * @note[short] Windows: 0x45cd50
     * @note[short] Android
     */
    void createMultiTriggerItems(cocos2d::CCPoint touchPos, cocos2d::CCPoint spawnPos, cocos2d::CCPoint multiPos);

    /**
     * @note[short] Windows: 0x45ca40
     * @note[short] Android
     */
    void createMultiTriggerItemsCorner();

    /**
     * @note[short] MacOS (ARM): 0x1d70d0
     * @note[short] MacOS (Intel): 0x224290
     * @note[short] Windows: 0x45c930
     * @note[short] Android
     */
    void createMultiTriggerItemsDefault();

    /**
     * @note[short] Windows: 0x45cc40
     * @note[short] Android
     */
    void createMultiTriggerItemsDefaultHorizontal();

    /**
     * @note[short] Windows: 0x45cb40
     * @note[short] Android
     */
    void createMultiTriggerItemsDefaultVertical();

    /**
     * @note[short] Windows: 0x45bc80
     * @note[short] Android
     */
    void createPageButtons(float p0, int p1);

    /**
     * @note[short] Windows: 0x45ef70
     * @note[short] Android
     */
    void createPlusButton(int p0, cocos2d::CCPoint p1, float p2, gd::string p3, int p4, int p5);

    /**
     * @note[short] Windows: 0x45c800
     * @note[short] Android
     */
    CCMenuItemToggler* createToggleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCPoint p3);

    /**
     * @note[short] MacOS (ARM): 0x1da5ec
     * @note[short] MacOS (Intel): 0x228c00
     * @note[short] Windows: 0x45e900
     * @note[short] Android
     */
    cocos2d::CCArray* createToggleValueControl(int p0, gd::string p1, cocos2d::CCPoint p2, bool p3, int p4, int p5, float p6);
    
private:
    [[deprecated("SetupTriggerPopup::createToggleValueControlAdvanced not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1da73c
     * @note[short] MacOS (Intel): 0x228d30
     * @note[short] Android
     */
    cocos2d::CCArray* createToggleValueControlAdvanced(int p0, gd::string p1, cocos2d::CCPoint p2, bool p3, int p4, int p5, float p6, float p7, float p8, cocos2d::CCPoint p9);
public:

    /**
     * @note[short] Windows: 0x45db40
     * @note[short] Android
     */
    cocos2d::CCArray* createValueControl(int p0, gd::string p1, cocos2d::CCPoint p2, float p3, float p4, float p5);

    /**
     * @note[short] MacOS (ARM): 0x1d9550
     * @note[short] MacOS (Intel): 0x227b30
     * @note[short] Windows: 0x45dc30
     * @note[short] Android
     */
    cocos2d::CCArray* createValueControlAdvanced(int p0, gd::string p1, cocos2d::CCPoint p2, float p3, bool p4, InputValueType p5, int p6, bool p7, float p8, float p9, int p10, int p11, GJInputStyle p12, int p13, bool p14);
    
private:
    [[deprecated("SetupTriggerPopup::createValueControlWArrows not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCArray* createValueControlWArrows(int p0, gd::string p1, cocos2d::CCPoint p2, float p3);
public:
    
private:
    [[deprecated("SetupTriggerPopup::getGroupContainer not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCArray* getGroupContainer(int p0);
public:
    
private:
    [[deprecated("SetupTriggerPopup::getMaxSliderValue not implemented")]]
    /**
     * @note[short] Android
     */
    float getMaxSliderValue(int p0);
public:
    
private:
    [[deprecated("SetupTriggerPopup::getMinSliderValue not implemented")]]
    /**
     * @note[short] Android
     */
    float getMinSliderValue(int p0);
public:
    
private:
    [[deprecated("SetupTriggerPopup::getObjects not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCArray* getObjects();
public:
    
private:
    [[deprecated("SetupTriggerPopup::getPageContainer not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCArray* getPageContainer(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x1db6b4
     * @note[short] MacOS (Intel): 0x229d20
     * @note[short] Windows: 0x4620f0
     * @note[short] Android
     */
    float getTriggerValue(int property, GameObject* object);

    /**
     * @note[short] Windows: 0x45f750
     * @note[short] Android
     */
    float getTruncatedValue(float p0, int p1);
    
private:
    [[deprecated("SetupTriggerPopup::getTruncatedValueByTag not implemented")]]
    /**
     * @note[short] Android
     */
    float getTruncatedValueByTag(int p0, float p1);
public:

    /**
     * @note[short] Windows: 0x45c010
     * @note[short] Android
     */
    void goToPage(int p0, bool p1);
    
private:
    [[deprecated("SetupTriggerPopup::hideAll not implemented")]]
    /**
     * @note[short] Android
     */
    void hideAll();
public:

    /**
     * @note[short] MacOS (ARM): 0x1d5eb4
     * @note[short] MacOS (Intel): 0x222f20
     * @note[short] Windows: 0x45b900
     * @note[short] Android
     */
    bool init(EffectGameObject* trigger, cocos2d::CCArray* triggers, float width, float height, int unkEnum);

    /**
     * @note[short] Windows: 0x465590
     * @note[short] Android
     */
    void onCustomEaseArrow(int p0, bool p1);

    /**
     * @note[short] Windows: 0x465560
     * @note[short] Android
     */
    void onCustomEaseArrowDown(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x465530
     * @note[short] Android
     */
    void onCustomEaseArrowUp(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x465420
     * @note[short] Android
     */
    void onCustomEaseRate(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x45e7f0
     * @note[short] Android
     */
    void onDisableValue(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x464ac0
     * @note[short] Android
     */
    void onEase(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x464b30
     * @note[short] Android
     */
    void onEaseRate(cocos2d::CCObject* sender);
    
private:
    [[deprecated("SetupTriggerPopup::onMultiTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    void onMultiTrigger(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] Windows: 0x45bf30
     * @note[short] Android
     */
    void onPage(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x45d2d0
     * @note[short] Android
     */
    void onSpawnedByTrigger(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x45f6c0
     * @note[short] Android
     */
    void onToggleTriggerValue(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x45d1e0
     * @note[short] Android
     */
    void onTouchTriggered(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void postSetup();

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void preSetup();
    
private:
    [[deprecated("SetupTriggerPopup::refreshGroupVisibility not implemented")]]
    /**
     * @note[short] Android
     */
    void refreshGroupVisibility();
public:
    
private:
    [[deprecated("SetupTriggerPopup::removeObjectFromGroup not implemented")]]
    /**
     * @note[short] Android
     */
    void removeObjectFromGroup(cocos2d::CCObject* p0, int p1);
public:
    
private:
    [[deprecated("SetupTriggerPopup::removeObjectFromPage not implemented")]]
    /**
     * @note[short] Android
     */
    void removeObjectFromPage(cocos2d::CCObject* p0, int p1);
public:
    
private:
    [[deprecated("SetupTriggerPopup::resetDisabledValues not implemented")]]
    /**
     * @note[short] Android
     */
    void resetDisabledValues();
public:
    
private:
    [[deprecated("SetupTriggerPopup::setMaxSliderValue not implemented")]]
    /**
     * @note[short] Android
     */
    void setMaxSliderValue(float p0, int p1);
public:
    
private:
    [[deprecated("SetupTriggerPopup::setMinSliderValue not implemented")]]
    /**
     * @note[short] Android
     */
    void setMinSliderValue(float p0, int p1);
public:
    
private:
    [[deprecated("SetupTriggerPopup::shouldLimitValue not implemented")]]
    /**
     * @note[short] Android
     */
    bool shouldLimitValue(int p0);
public:
    
private:
    [[deprecated("SetupTriggerPopup::toggleBG not implemented")]]
    /**
     * @note[short] Android
     */
    void toggleBG(bool p0);
public:

    /**
     * @note[short] Windows: 0x465910
     * @note[short] Android
     */
    void toggleCustomEaseRateVisibility(int p0, int p1);

    /**
     * @note[short] Windows: 0x45e820
     * @note[short] Android
     */
    void toggleDisableButtons(bool p0);
    
private:
    [[deprecated("SetupTriggerPopup::toggleEaseRateVisibility not implemented")]]
    /**
     * @note[short] Android
     */
    void toggleEaseRateVisibility();
public:
    
private:
    [[deprecated("SetupTriggerPopup::toggleLimitValue not implemented")]]
    /**
     * @note[short] Android
     */
    void toggleLimitValue(int p0, bool p1);
public:
    
private:
    [[deprecated("SetupTriggerPopup::togglePageArrows not implemented")]]
    /**
     * @note[short] Android
     */
    void togglePageArrows(bool p0);
public:

    /**
     * @note[short] Windows: 0x45daa0
     * @note[short] Android
     */
    void triggerArrowChanged(int p0, bool p1);

    /**
     * @note[short] Windows: 0x45da40
     * @note[short] Android
     */
    void triggerArrowLeft(cocos2d::CCObject* p0);

    /**
     * @note[short] Windows: 0x45da70
     * @note[short] Android
     */
    void triggerArrowRight(cocos2d::CCObject* p0);

    /**
     * @note[short] Windows: 0x45d980
     * @note[short] Android
     */
    void triggerSliderChanged(cocos2d::CCObject* p0);

    /**
     * @note[short] Windows: 0x465630
     * @note[short] Android
     */
    void updateCustomEaseLabel(int p0, int p1);

    /**
     * @note[short] Windows: 0x465800
     * @note[short] Android
     */
    void updateCustomEaseRateLabel(int p0, float p1);
    
private:
    [[deprecated("SetupTriggerPopup::updateCustomToggleTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    void updateCustomToggleTrigger(int p0, bool p1);
public:
    
private:
    [[deprecated("SetupTriggerPopup::updateEaseLabel not implemented")]]
    /**
     * @note[short] Android
     */
    void updateEaseLabel();
public:
    
private:
    [[deprecated("SetupTriggerPopup::updateEaseRateLabel not implemented")]]
    /**
     * @note[short] Android
     */
    void updateEaseRateLabel();
public:
    
private:
    [[deprecated("SetupTriggerPopup::updateEditorLabel not implemented")]]
    /**
     * @note[short] Android
     */
    void updateEditorLabel();
public:

    /**
     * @note[short] Windows: 0x463be0
     * @note[short] Android
     */
    void updateInputNodeLabel(int p0, gd::string p1);
    
private:
    [[deprecated("SetupTriggerPopup::updateLabel not implemented")]]
    /**
     * @note[short] Android
     */
    void updateLabel(int p0, gd::string p1);
public:

    /**
     * @note[short] Windows: 0x45d3c0
     * @note[short] Android
     */
    void updateMultiTriggerBtn();
    
private:
    [[deprecated("SetupTriggerPopup::updateSlider not implemented")]]
    /**
     * @note[short] Android
     */
    void updateSlider(int p0, float p1);
public:
    
private:
    [[deprecated("SetupTriggerPopup::updateSlider not implemented")]]
    /**
     * @note[short] Android
     */
    void updateSlider(int p0);
public:

    /**
     * @note[short] Windows: 0x45d320
     * @note[short] Android
     */
    void updateSpawnedByTrigger();

    /**
     * @note[short] Windows: 0x45d230
     * @note[short] Android
     */
    void updateTouchTriggered();

    /**
     * @note[short] MacOS (ARM): 0x1da380
     * @note[short] MacOS (Intel): 0x2289d0
     * @note[short] Windows: 0x463b50
     * @note[short] Android
     */
    void updateValue(int property, float value);

    /**
     * @note[short] MacOS (ARM): 0x1d9370
     * @note[short] MacOS (Intel): 0x227950
     * @note[short] Windows: 0x45f7c0
     * @note[short] Android
     */
    void updateValueControls(int property, float value);

    /**
     * @note[short] MacOS (ARM): 0x1d7e68
     * @note[short] MacOS (Intel): 0x225210
     * @note[short] Windows: 0x45fd90
     * @note[short] Android
     */
    void valueChanged(int property, float value);
    EffectGameObject* m_gameObject;
    cocos2d::CCArray* m_gameObjects;
    bool m_touchTriggered;
    bool m_spawnTriggered;
    CCMenuItemToggler* m_touchToggle;
    CCMenuItemToggler* m_spawnToggle;
    cocos2d::CCArray* m_multiTriggerContainer;
    bool m_multiTriggered;
    float m_width;
    float m_height;
    bool m_disableTextDelegate;
    cocos2d::CCDictionary* m_valueToggles;
    cocos2d::CCDictionary* m_inputNodes;
    cocos2d::CCDictionary* m_valueControls;
    cocos2d::CCDictionary* m_customValueToggles;
    cocos2d::CCDictionary* m_disableButtons;
    cocos2d::CCLabelBMFont* m_easingLabel;
    cocos2d::CCLabelBMFont* m_easingRateLabel;
    CCMenuItemSpriteExtra* m_easingRateButton;
    int m_easingIndex;
    float m_easingRate;
    cocos2d::CCDictionary* m_inputLabels;
    cocos2d::CCDictionary* m_triggerValues;
    cocos2d::CCDictionary* m_minSliderValues;
    cocos2d::CCDictionary* m_maxSliderValues;
    gd::map<int, bool> m_shouldLimitValues;
    bool m_disableSliderDelegate;
    bool m_unk349;
    cocos2d::CCArray* m_pageContainers;
    int m_page;
    float m_easingControlScale;
    cocos2d::CCArray* m_groupContainers;
    cocos2d::CCDictionary* m_customEasingTags;
    cocos2d::CCDictionary* m_customEasingLabels;
    cocos2d::CCDictionary* m_customEasingButtons;
    cocos2d::CCDictionary* m_customEasingScales;
    cocos2d::CCDictionary* m_disabledEasingButtons;
    CCMenuItemSpriteExtra* m_prevButton;
    CCMenuItemSpriteExtra* m_nextButton;
    bool m_hideAll;
};
