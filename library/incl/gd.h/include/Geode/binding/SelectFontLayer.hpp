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

class SelectFontLayer : public FLAlertLayer {
public:
    static constexpr auto CLASS_NAME = "SelectFontLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SelectFontLayer, FLAlertLayer)

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     SelectFontLayer();

    /**
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static SelectFontLayer* create(LevelEditorLayer* editorLayer);
    
private:
    [[deprecated("SelectFontLayer::keyBackClicked not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x231a94
     * @note[short] MacOS (Intel): 0x2887b0
     * @note[short] iOS: 0x2d2a78
     * @note[short] Android
     */
    virtual void keyBackClicked();
public:

    /**
     * @note[short] MacOS (ARM): 0x2312e4
     * @note[short] MacOS (Intel): 0x287fe0
     * @note[short] Windows: 0x286be0
     * @note[short] Android
     */
    bool init(LevelEditorLayer* p0);

    /**
     * @note[short] MacOS (ARM): 0x231900
     * @note[short] MacOS (Intel): 0x2885f0
     * @note[short] Windows: 0x287400
     * @note[short] Android
     */
    void onChangeFont(cocos2d::CCObject* sender);
    
private:
    [[deprecated("SelectFontLayer::onClose not implemented")]]
    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x231994
     * @note[short] MacOS (Intel): 0x288690
     * @note[short] Windows: 0x287200
     * @note[short] Android
     */
    void updateFontLabel();
    int m_font;
    LevelEditorLayer* m_editorLayer;
    cocos2d::CCLabelBMFont* m_fontLabel;
};
