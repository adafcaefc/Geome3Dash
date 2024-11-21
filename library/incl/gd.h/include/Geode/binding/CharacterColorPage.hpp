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

class CharacterColorPage : public FLAlertLayer {
public:
    static constexpr auto CLASS_NAME = "CharacterColorPage";
    GEODE_CUSTOM_CONSTRUCTOR_GD(CharacterColorPage, FLAlertLayer)

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     CharacterColorPage();

    /**
     * @note[short] MacOS (ARM): 0x56ee50
     * @note[short] MacOS (Intel): 0x6467b0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static CharacterColorPage* create();

    /**
     * @note[short] MacOS (ARM): 0x56ef58
     * @note[short] MacOS (Intel): 0x646910
     * @note[short] Windows: 0x87f30
     * @note[short] iOS: 0x12bf2c
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (ARM): 0x570eb4
     * @note[short] MacOS (Intel): 0x6488c0
     * @note[short] Windows: 0x425d0
     * @note[short] iOS: 0x12d844
     * @note[short] Android
     */
    virtual void registerWithTouchDispatcher();

    /**
     * @note[short] MacOS (ARM): 0x570e08
     * @note[short] MacOS (Intel): 0x648820
     * @note[short] Windows: 0x8a7a0
     * @note[short] iOS: 0x12d7e8
     * @note[short] Android
     */
    virtual void keyBackClicked();
    
private:
    [[deprecated("CharacterColorPage::show not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x570c80
     * @note[short] MacOS (Intel): 0x648690
     * @note[short] iOS: 0x12d674
     * @note[short] Android
     */
    virtual void show();
public:
    
private:
    [[deprecated("CharacterColorPage::activeColorForMode not implemented")]]
    /**
     * @note[short] Android
     */
    int activeColorForMode(int mode);
public:
    
private:
    [[deprecated("CharacterColorPage::checkColor not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn checkColor(int p0, UnlockType p1);
public:
    
private:
    [[deprecated("CharacterColorPage::colorForIndex not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x648300
     * @note[short] Android
     */
    int colorForIndex(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x56ffac
     * @note[short] Windows: 0x88e50
     * @note[short] Android
     */
    void createColorMenu();
    
private:
    [[deprecated("CharacterColorPage::FLAlert_Clicked not implemented")]]
    /**
     * @note[short] Android
     */
    void FLAlert_Clicked(FLAlertLayer* p0, bool p1);
public:
    
private:
    [[deprecated("CharacterColorPage::offsetForIndex not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x648570
     * @note[short] Android
     */
    cocos2d::CCPoint offsetForIndex(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x56fb64
     * @note[short] MacOS (Intel): 0x647590
     * @note[short] Windows: 0x8a760
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x56fc80
     * @note[short] MacOS (Intel): 0x647690
     * @note[short] Windows: 0x89550
     * @note[short] Android
     */
    void onMode(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x570904
     * @note[short] MacOS (Intel): 0x648320
     * @note[short] Windows: 0x89d60
     * @note[short] Android
     */
    void onPlayerColor(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x570384
     * @note[short] MacOS (Intel): 0x647d80
     * @note[short] Windows: 0x88da0
     * @note[short] Android
     */
    void toggleGlow(cocos2d::CCObject* p0);
    
private:
    [[deprecated("CharacterColorPage::toggleGlowItems not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleGlowItems(bool p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x56fbb8
     * @note[short] MacOS (Intel): 0x6475e0
     * @note[short] Windows: 0x88c80
     * @note[short] Android
     */
    void toggleShip(cocos2d::CCObject* p0);
    
private:
    [[deprecated("CharacterColorPage::updateColorMode not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x647dc0
     * @note[short] Android
     */
    void updateColorMode(int p0);
public:

    /**
     * @note[short] MacOS (Intel): 0x647850
     * @note[short] Windows: 0x8a540
     * @note[short] Android
     */
    void updateIconColors();
    int m_colorMode;
    float m_height;
    float m_width;
    cocos2d::CCArray* m_playerObjects;
    cocos2d::CCArray* m_modeButtons;
    cocos2d::CCDictionary* m_colorButtons;
    cocos2d::CCArray* m_cursors;
    CharacterColorDelegate* m_delegate;
    CCMenuItemToggler* m_glowToggler;
    cocos2d::CCLabelBMFont* m_glowLabel;
};
