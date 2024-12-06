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

class SetGroupIDLayer : public FLAlertLayer, public TextInputDelegate {
public:
    static constexpr auto CLASS_NAME = "SetGroupIDLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetGroupIDLayer, FLAlertLayer)
    
private:
    [[deprecated("SetGroupIDLayer::create not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2965a4
     * @note[short] MacOS (Intel): 0x2fe420
     * @note[short] Android
     */
    static SetGroupIDLayer* create(GameObject* p0, cocos2d::CCArray* p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x29b16c
     * @note[short] MacOS (Intel): 0x303620
     * @note[short] Windows: 0x3e62e0
     * @note[short] iOS: 0x42db0
     * @note[short] Android
     */
    virtual void keyBackClicked();
    
private:
    [[deprecated("SetGroupIDLayer::textInputClosed not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x29aa40
     * @note[short] MacOS (Intel): 0x302ea0
     * @note[short] iOS: 0x42820
     * @note[short] Android
     */
    virtual void textInputClosed(CCTextInputNode* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x29aa5c
     * @note[short] MacOS (Intel): 0x302ee0
     * @note[short] Windows: 0x3e4400
     * @note[short] iOS: 0x4283c
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);
    
private:
    [[deprecated("SetGroupIDLayer::addGroupID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn addGroupID(int p0);
public:
    
private:
    [[deprecated("SetGroupIDLayer::callRemoveFromGroup not implemented")]]
    /**
     * @note[short] Android
     */
    void callRemoveFromGroup(float p0);
public:
    
private:
    [[deprecated("SetGroupIDLayer::createTextInput not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createTextInput(cocos2d::CCPoint p0, int p1, int p2, gd::string p3, float p4, int p5);
public:
    
private:
    [[deprecated("SetGroupIDLayer::determineStartValues not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn determineStartValues();
public:

    /**
     * @note[short] MacOS (ARM): 0x296704
     * @note[short] MacOS (Intel): 0x2fe5f0
     * @note[short] Windows: 0x3e1260
     * @note[short] Android
     */
    bool init(GameObject* obj, cocos2d::CCArray* objs);

    /**
     * @note[short] MacOS (ARM): 0x298c74
     * @note[short] MacOS (Intel): 0x300d30
     * @note[short] Windows: 0x3e52b0
     * @note[short] Android
     */
    void onAddGroup(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x298c7c
     * @note[short] MacOS (Intel): 0x300d40
     * @note[short] Windows: 0x3e5420
     * @note[short] Android
     */
    void onAddGroupParent(cocos2d::CCObject* sender);
    
private:
    [[deprecated("SetGroupIDLayer::onAnim not implemented")]]
    /**
     * @note[short] Android
     */
    void onAnim(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] Windows: 0x3e39e0
     * @note[short] Android
     */
    void onArrow(int tag, int increment);

    /**
     * @note[short] Windows: 0x3e3980
     * @note[short] Android
     */
    void onArrowLeft(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x3e39b0
     * @note[short] Android
     */
    void onArrowRight(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x298444
     * @note[short] Windows: 0x3e5f60
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
    
private:
    [[deprecated("SetGroupIDLayer::onCopy not implemented")]]
    /**
     * @note[short] Android
     */
    void onCopy(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] Windows: 0x3e40d0
     * @note[short] Android
     */
    void onExtra(cocos2d::CCObject* sender);
    
private:
    [[deprecated("SetGroupIDLayer::onExtra2 not implemented")]]
    /**
     * @note[short] Android
     */
    void onExtra2(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetGroupIDLayer::onNextFreeEditorLayer1 not implemented")]]
    /**
     * @note[short] Android
     */
    void onNextFreeEditorLayer1(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetGroupIDLayer::onNextFreeEditorLayer2 not implemented")]]
    /**
     * @note[short] Android
     */
    void onNextFreeEditorLayer2(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetGroupIDLayer::onNextFreeOrderChannel not implemented")]]
    /**
     * @note[short] Android
     */
    void onNextFreeOrderChannel(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x298c40
     * @note[short] Windows: 0x3e48d0
     * @note[short] Android
     */
    void onNextGroupID1(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0x111a80
     * @note[short] Android
     */
    void onPaste(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x29ae48
     * @note[short] MacOS (Intel): 0x3032f0
     * @note[short] Windows: 0x3e51e0
     * @note[short] Android
     */
    void onRemoveFromGroup(cocos2d::CCObject* sender);
    
private:
    [[deprecated("SetGroupIDLayer::onSmoothEase not implemented")]]
    /**
     * @note[short] Android
     */
    void onSmoothEase(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetGroupIDLayer::onToggleGuide not implemented")]]
    /**
     * @note[short] Android
     */
    void onToggleGuide(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetGroupIDLayer::onToggleSelectedOrder not implemented")]]
    /**
     * @note[short] Android
     */
    void onToggleSelectedOrder(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetGroupIDLayer::onZLayer not implemented")]]
    /**
     * @note[short] Android
     */
    void onZLayer(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetGroupIDLayer::onZLayerShift not implemented")]]
    /**
     * @note[short] Android
     */
    void onZLayerShift(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("SetGroupIDLayer::removeGroupID not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn removeGroupID(int p0);
public:

    /**
     * @note[short] Windows: 0x3e5920
     * @note[short] Android
     */
    void updateEditorLabel();

    /**
     * @note[short] Windows: 0x3e59b0
     * @note[short] Android
     */
    void updateEditorLabel2();
    
private:
    [[deprecated("SetGroupIDLayer::updateEditorLayerID not implemented")]]
    /**
     * @note[short] Android
     */
    void updateEditorLayerID();
public:
    
private:
    [[deprecated("SetGroupIDLayer::updateEditorLayerID2 not implemented")]]
    /**
     * @note[short] Android
     */
    void updateEditorLayerID2();
public:
    
private:
    [[deprecated("SetGroupIDLayer::updateEditorOrder not implemented")]]
    /**
     * @note[short] Android
     */
    void updateEditorOrder();
public:
    
private:
    [[deprecated("SetGroupIDLayer::updateEditorOrderLabel not implemented")]]
    /**
     * @note[short] Android
     */
    void updateEditorOrderLabel();
public:

    /**
     * @note[short] Windows: 0x3e4940
     * @note[short] Android
     */
    void updateGroupIDButtons();

    /**
     * @note[short] Windows: 0x3e5ad0
     * @note[short] Android
     */
    void updateGroupIDLabel();
    
private:
    [[deprecated("SetGroupIDLayer::updateOrderChannel not implemented")]]
    /**
     * @note[short] Android
     */
    void updateOrderChannel();
public:
    
private:
    [[deprecated("SetGroupIDLayer::updateOrderChannelLabel not implemented")]]
    /**
     * @note[short] Android
     */
    void updateOrderChannelLabel();
public:

    /**
     * @note[short] Windows: 0x3e5d30
     * @note[short] Android
     */
    void updateZLayerButtons();

    /**
     * @note[short] Windows: 0x3e5890
     * @note[short] Android
     */
    void updateZOrder();

    /**
     * @note[short] Windows: 0x3e5a40
     * @note[short] Android
     */
    void updateZOrderLabel();
    GameObject* m_targetObject;
    cocos2d::CCArray* m_targetObjects;
    cocos2d::CCArray* m_array0;
    cocos2d::CCArray* m_groupIDObjects;
    CCTextInputNode* m_editorLayerInput;
    CCTextInputNode* m_editorLayer2Input;
    CCTextInputNode* m_zOrderInput;
    CCTextInputNode* m_groupIDInput;
    CCTextInputNode* m_orderInput;
    CCTextInputNode* m_channelInput;
    bool m_showChannelOrder;
    int m_channelValue;
    bool m_channelUpdated;
    int m_groupIDValue;
    int m_editorLayerValue;
    int m_editorLayer2Value;
    int m_zOrderValue;
    ZLayer m_zLayerValue;
    int m_orderValue;
    bool m_channelOrderEdited;
    bool m_editorLayerEdited;
    bool m_removeGroupsLock;
    int m_groupToRemove;
    bool m_addedGroup;
    bool m_unkBool0;
    bool m_hasTargetObjects;
};
