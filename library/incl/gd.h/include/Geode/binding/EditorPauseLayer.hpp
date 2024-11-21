#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>

#include "CCBlockLayer.hpp"
#include "FLAlertLayerProtocol.hpp"

class EditorPauseLayer : public CCBlockLayer, public FLAlertLayerProtocol {
public:
    static constexpr auto CLASS_NAME = "EditorPauseLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(EditorPauseLayer, CCBlockLayer)

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     EditorPauseLayer();

    /**
     * @note[short] MacOS (ARM): 0x228ae4
     * @note[short] MacOS (Intel): 0x27f120
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static EditorPauseLayer* create(LevelEditorLayer* p0);

    /**
     * @note[short] MacOS (ARM): 0x22c910
     * @note[short] MacOS (Intel): 0x283060
     * @note[short] Windows: 0xdd0c0
     * @note[short] iOS: 0x3976d4
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x22c9f0
     * @note[short] MacOS (Intel): 0x283150
     * @note[short] Windows: 0xdd0d0
     * @note[short] iOS: 0x3976e0
     * @note[short] Android
     */
    virtual void keyDown(cocos2d::enumKeyCodes p0);

    /**
     * @note[short] MacOS (ARM): 0x2296c0
     * @note[short] MacOS (Intel): 0x27fa70
     * @note[short] Windows: 0xd9020
     * @note[short] iOS: 0x394ef0
     * @note[short] Android
     */
    virtual void customSetup();

    /**
     * @note[short] MacOS (ARM): 0x22c834
     * @note[short] MacOS (Intel): 0x282f80
     * @note[short] Windows: 0xdcfa0
     * @note[short] iOS: 0x397610
     * @note[short] Android
     */
    virtual void FLAlert_Clicked(FLAlertLayer* p0, bool p1);

    /**
     * @note[short] Windows: 0x2d2b80
     * @note[short] Android
     */
    TodoReturn doResetUnused();

    /**
     * @note[short] MacOS (ARM): 0x228bbc
     * @note[short] MacOS (Intel): 0x27f220
     * @note[short] Windows: 0xd8990
     * @note[short] Android
     */
    bool init(LevelEditorLayer* p0);

    /**
     * @note[short] Windows: 0xdb9e0
     * @note[short] Android
     */
    void onAlignX(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0xdba10
     * @note[short] Android
     */
    void onAlignY(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0xdb7d0
     * @note[short] Android
     */
    void onBuildHelper(cocos2d::CCObject* sender);
    
private:
    [[deprecated("EditorPauseLayer::onCopyWColor not implemented")]]
    /**
     * @note[short] Android
     */
    void onCopyWColor(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] Windows: 0xdb760
     * @note[short] Android
     */
    void onCreateExtras(cocos2d::CCObject* sender);
    
private:
    [[deprecated("EditorPauseLayer::onCreateLoop not implemented")]]
    /**
     * @note[short] Android
     */
    void onCreateLoop(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("EditorPauseLayer::onCreateTemplate not implemented")]]
    /**
     * @note[short] Android
     */
    void onCreateTemplate(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x22c7fc
     * @note[short] Windows: 0xdcd60
     * @note[short] Android
     */
    void onExitEditor(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x22b51c
     * @note[short] MacOS (Intel): 0x281ad0
     * @note[short] Windows: 0xdce30
     * @note[short] Android
     */
    void onExitNoSave(cocos2d::CCObject* sender);
    
private:
    [[deprecated("EditorPauseLayer::onHelp not implemented")]]
    /**
     * @note[short] Android
     */
    void onHelp(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("EditorPauseLayer::onKeybindings not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x22bc3c
     * @note[short] Android
     */
    void onKeybindings(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("EditorPauseLayer::onNewGroupX not implemented")]]
    /**
     * @note[short] Android
     */
    void onNewGroupX(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("EditorPauseLayer::onNewGroupY not implemented")]]
    /**
     * @note[short] Android
     */
    void onNewGroupY(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("EditorPauseLayer::onOptions not implemented")]]
    /**
     * @note[short] Android
     */
    void onOptions(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("EditorPauseLayer::onPasteWColor not implemented")]]
    /**
     * @note[short] Android
     */
    void onPasteWColor(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("EditorPauseLayer::onReGroup not implemented")]]
    /**
     * @note[short] Android
     */
    void onReGroup(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("EditorPauseLayer::onResetUnusedColors not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x22b850
     * @note[short] MacOS (Intel): 0x281e30
     * @note[short] Android
     */
    void onResetUnusedColors(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x22b2c4
     * @note[short] MacOS (Intel): 0x2818a0
     * @note[short] Windows: 0xdc140
     * @note[short] Android
     */
    void onResume(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x22b42c
     * @note[short] MacOS (Intel): 0x2819f0
     * @note[short] Windows: 0xdcbf0
     * @note[short] Android
     */
    void onSave(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x22b3c0
     * @note[short] MacOS (Intel): 0x281980
     * @note[short] Windows: 0xdcd20
     * @note[short] Android
     */
    void onSaveAndExit(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x22b330
     * @note[short] MacOS (Intel): 0x281910
     * @note[short] Windows: 0xdc9a0
     * @note[short] Android
     */
    void onSaveAndPlay(cocos2d::CCObject* sender);

    /**
     * @note[short] Windows: 0xdb870
     * @note[short] Android
     */
    void onSelectAll(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x22ba48
     * @note[short] MacOS (Intel): 0x2820b0
     * @note[short] Windows: 0xdb9a0
     * @note[short] Android
     */
    void onSelectAllLeft(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x22ba58
     * @note[short] MacOS (Intel): 0x2820d0
     * @note[short] Windows: 0xdb9c0
     * @note[short] Android
     */
    void onSelectAllRight(cocos2d::CCObject* sender);
    
private:
    [[deprecated("EditorPauseLayer::onSong not implemented")]]
    /**
     * @note[short] Android
     */
    void onSong(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("EditorPauseLayer::onUnlockAllLayers not implemented")]]
    /**
     * @note[short] Android
     */
    void onUnlockAllLayers(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("EditorPauseLayer::playStep2 not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn playStep2();
public:

    /**
     * @note[short] Windows: 0xdcb50
     * @note[short] Android
     */
    TodoReturn playStep3();

    /**
     * @note[short] MacOS (ARM): 0x22c274
     * @note[short] MacOS (Intel): 0x282980
     * @note[short] Windows: 0xdc310
     * @note[short] Android
     */
    void saveLevel();
    
private:
    [[deprecated("EditorPauseLayer::toggleDebugDraw not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleDebugDraw(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("EditorPauseLayer::toggleEditorBackground not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleEditorBackground(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("EditorPauseLayer::toggleEditorColorMode not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleEditorColorMode(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("EditorPauseLayer::toggleEditorGrid not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleEditorGrid(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("EditorPauseLayer::toggleEditorGround not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleEditorGround(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("EditorPauseLayer::toggleEffectDuration not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleEffectDuration(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("EditorPauseLayer::toggleEffectLines not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleEffectLines(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("EditorPauseLayer::toggleFollowPlayer not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleFollowPlayer(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("EditorPauseLayer::toggleGridOnTop not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleGridOnTop(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("EditorPauseLayer::toggleHideInvisible not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleHideInvisible(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("EditorPauseLayer::toggleIgnoreDamage not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleIgnoreDamage(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("EditorPauseLayer::togglePlaytestMusic not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn togglePlaytestMusic(cocos2d::CCObject* p0);
public:

    /**
     * @note[short] Windows: 0xdbc10
     * @note[short] Android
     */
    void togglePreviewAnim(cocos2d::CCObject* p0);
    
private:
    [[deprecated("EditorPauseLayer::togglePreviewParticles not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn togglePreviewParticles(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("EditorPauseLayer::togglePreviewShaders not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn togglePreviewShaders(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("EditorPauseLayer::toggleRecordOrder not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleRecordOrder(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("EditorPauseLayer::toggleSelectFilter not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleSelectFilter(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("EditorPauseLayer::toggleShowObjectInfo not implemented")]]
    /**
     * @note[short] Android
     */
    void toggleShowObjectInfo(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("EditorPauseLayer::uncheckAllPortals not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x281d60
     * @note[short] Android
     */
    TodoReturn uncheckAllPortals(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("EditorPauseLayer::updateSongButton not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateSongButton();
public:
    bool m_saved;
    CCMenuItemSpriteExtra* m_guidelinesOffButton;
    CCMenuItemSpriteExtra* m_guidelinesOnButton;
    LevelEditorLayer* m_editorLayer;
    GEODE_PAD(32);
};
