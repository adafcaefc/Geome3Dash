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
#include "GJDropDownLayerDelegate.hpp"
#include "MusicBrowserDelegate.hpp"

class CustomSongLayer : public FLAlertLayer, public TextInputDelegate, public GJDropDownLayerDelegate, public MusicBrowserDelegate {
public:
    static constexpr auto CLASS_NAME = "CustomSongLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(CustomSongLayer, FLAlertLayer)

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     CustomSongLayer();

    /**
     * @note[short] MacOS (ARM): 0x1b82a4
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static CustomSongLayer* create(CustomSongDelegate* delegate);

    /**
     * @note[short] MacOS (ARM): 0x1b9a48
     * @note[short] MacOS (Intel): 0x2048b0
     * @note[short] Windows: 0xc3760
     * @note[short] iOS: 0x1483d8
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x1b9b34
     * @note[short] MacOS (Intel): 0x2049a0
     * @note[short] Windows: 0xc3770
     * @note[short] iOS: 0x1483e4
     * @note[short] Android
     */
    virtual void show();
    
private:
    [[deprecated("CustomSongLayer::textChanged not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1b9518
     * @note[short] MacOS (Intel): 0x204340
     * @note[short] iOS: 0x1480ac
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);
public:
    
private:
    [[deprecated("CustomSongLayer::textInputOpened not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1b9498
     * @note[short] MacOS (Intel): 0x2042e0
     * @note[short] iOS: 0x148074
     * @note[short] Android
     */
    virtual void textInputOpened(CCTextInputNode* p0);
public:
    
private:
    [[deprecated("CustomSongLayer::textInputClosed not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1b9418
     * @note[short] MacOS (Intel): 0x204280
     * @note[short] iOS: 0x14803c
     * @note[short] Android
     */
    virtual void textInputClosed(CCTextInputNode* p0);
public:
    
private:
    [[deprecated("CustomSongLayer::textInputShouldOffset not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1b9538
     * @note[short] MacOS (Intel): 0x204360
     * @note[short] iOS: 0x1480cc
     * @note[short] Android
     */
    virtual void textInputShouldOffset(CCTextInputNode* p0, float p1);
public:
    
private:
    [[deprecated("CustomSongLayer::textInputReturn not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1b9608
     * @note[short] MacOS (Intel): 0x204420
     * @note[short] iOS: 0x148138
     * @note[short] Android
     */
    virtual void textInputReturn(CCTextInputNode* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x1b98b8
     * @note[short] MacOS (Intel): 0x204750
     * @note[short] Windows: 0xc34f0
     * @note[short] iOS: 0x148300
     * @note[short] Android
     */
    virtual void dropDownLayerWillClose(GJDropDownLayer* p0);

    /**
     * @note[short] MacOS (ARM): 0x1b9980
     * @note[short] MacOS (Intel): 0x204800
     * @note[short] Windows: 0xc35c0
     * @note[short] iOS: 0x14836c
     * @note[short] Android
     */
    virtual void musicBrowserClosed(MusicBrowser* p0);

    /**
     * @note[short] MacOS (ARM): 0x1b83c0
     * @note[short] MacOS (Intel): 0x203120
     * @note[short] Windows: 0xc1f00
     * @note[short] Android
     */
    bool init(CustomSongDelegate* p0);

    /**
     * @note[short] Windows: 0xc3690
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
    
private:
    [[deprecated("CustomSongLayer::onCreateLines not implemented")]]
    /**
     * @note[short] Android
     */
    void onCreateLines(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x1b902c
     * @note[short] MacOS (Intel): 0x203e50
     * @note[short] Windows: 0xc31a0
     * @note[short] Android
     */
    void onMusicBrowser(cocos2d::CCObject* sender);
    
private:
    [[deprecated("CustomSongLayer::onNCSBrowser not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x203e30
     * @note[short] Android
     */
    void onNCSBrowser(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] Windows: 0xc3300
     * @note[short] Android
     */
    void onNewgroundsBrowser(cocos2d::CCObject* sender);
    
private:
    [[deprecated("CustomSongLayer::onOptions not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x30eaf4
     * @note[short] MacOS (Intel): 0x203f00
     * @note[short] Android
     */
    void onOptions(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x1b90ec
     * @note[short] Windows: 0xc2c80
     * @note[short] Android
     */
    void onSearch(cocos2d::CCObject* sender);
    
private:
    [[deprecated("CustomSongLayer::onSongBrowser not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1b8fac
     * @note[short] Android
     */
    void onSongBrowser(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CustomSongLayer::showNewgroundsMessage not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x1b9264
     * @note[short] MacOS (Intel): 0x204090
     * @note[short] Android
     */
    void showNewgroundsMessage();
public:
    CustomSongDelegate* m_songDelegate;
    CCTextInputNode* m_songIDInput;
    CustomSongWidget* m_songWidget;
    CustomSongLayerDelegate* m_delegate;
};
