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

class GJOptionsLayer : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "GJOptionsLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(GJOptionsLayer, SetupTriggerPopup)

    /**
     * @note[short] Windows: 0x285940
     * @note[short] Android
     */
     GJOptionsLayer();
    
private:
    [[deprecated("GJOptionsLayer::create not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x289c00
     * @note[short] Android
     */
    static GJOptionsLayer* create(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x2333c8
     * @note[short] MacOS (Intel): 0x28a640
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x2d3b84
     * @note[short] Android: Out of line
     */
    virtual void setupOptions();
    
private:
    [[deprecated("GJOptionsLayer::didToggleGV not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] iOS: 0xd590
     * @note[short] Android
     */
    virtual void didToggleGV(gd::string p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x8fb0
     * @note[short] MacOS (Intel): 0x7150
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0xd590
     * @note[short] Android: Out of line
     */
    virtual void didToggle(int p0);

    /**
     * @note[short] MacOS (ARM): 0x2333cc
     * @note[short] MacOS (Intel): 0x28a650
     * @note[short] Windows: 0x288470
     * @note[short] Android
     */
    void addGVToggle(char const* p0, char const* p1, char const* p2);

    /**
     * @note[short] MacOS (ARM): 0x233518
     * @note[short] MacOS (Intel): 0x28a780
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void addToggle(char const* p0, int p1, bool p2, char const* p3);

    /**
     * @note[short] Windows: 0x2885b0
     * @note[short] Android
     */
    void addToggleInternal(char const* p0, int p1, bool p2, char const* p3);
    
private:
    [[deprecated("GJOptionsLayer::countForPage not implemented")]]
    /**
     * @note[short] Android
     */
    int countForPage(int p0);
public:
    
private:
    [[deprecated("GJOptionsLayer::goToPage not implemented")]]
    /**
     * @note[short] Android
     */
    void goToPage(int p0);
public:

    /**
     * @note[short] Windows: 0x288b80
     * @note[short] Android
     */
    void incrementCountForPage(int p0);
    
private:
    [[deprecated("GJOptionsLayer::infoKey not implemented")]]
    /**
     * @note[short] Android
     */
    const char* infoKey(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x232c90
     * @note[short] MacOS (Intel): 0x289e50
     * @note[short] Windows: 0x288130
     * @note[short] Android
     */
    bool init(int p0);

    /**
     * @note[short] MacOS (ARM): 0x233acc
     * @note[short] MacOS (Intel): 0x28ada0
     * @note[short] Windows: 0x288e10
     * @note[short] Android
     */
    cocos2d::CCLayer* layerForPage(int p0);
    
private:
    [[deprecated("GJOptionsLayer::layerKey not implemented")]]
    /**
     * @note[short] Android
     */
    const char* layerKey(int p0);
public:
    
private:
    [[deprecated("GJOptionsLayer::nextPosition not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x2339d4
     * @note[short] MacOS (Intel): 0x28aca0
     * @note[short] Android
     */
    cocos2d::CCPoint nextPosition(int p0);
public:
    
private:
    [[deprecated("GJOptionsLayer::objectKey not implemented")]]
    /**
     * @note[short] Android
     */
    const char* objectKey(int p0);
public:
    
private:
    [[deprecated("GJOptionsLayer::objectsForPage not implemented")]]
    /**
     * @note[short] Android
     */
    cocos2d::CCArray* objectsForPage(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x2333a4
     * @note[short] MacOS (Intel): 0x28a610
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    void offsetToNextPage();
    
private:
    [[deprecated("GJOptionsLayer::onInfo not implemented")]]
    /**
     * @note[short] Android
     */
    void onInfo(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJOptionsLayer::onNextPage not implemented")]]
    /**
     * @note[short] Android
     */
    void onNextPage(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("GJOptionsLayer::onPrevPage not implemented")]]
    /**
     * @note[short] Android
     */
    void onPrevPage(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x233cb8
     * @note[short] MacOS (Intel): 0x28afa0
     * @note[short] Windows: 0x2893e0
     * @note[short] Android
     */
    void onToggle(cocos2d::CCObject* sender);
    
private:
    [[deprecated("GJOptionsLayer::pageKey not implemented")]]
    /**
     * @note[short] Android
     */
    const char* pageKey(int p0);
public:
    float m_gap;
    int m_page;
    int m_togglesPerPage;
    int m_toggleCount;
    int m_maxPage;
    float m_maxLabelScale;
    float m_maxLabelWidth;
    cocos2d::CCDictionary* m_values;
    cocos2d::CCDictionary* m_variables;
    CCMenuItemSpriteExtra* m_prevButton;
    CCMenuItemSpriteExtra* m_nextButton;
    float m_offset;
};
