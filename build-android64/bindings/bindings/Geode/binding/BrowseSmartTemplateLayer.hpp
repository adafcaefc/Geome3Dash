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

class BrowseSmartTemplateLayer : public FLAlertLayer {
public:
    static constexpr auto CLASS_NAME = "BrowseSmartTemplateLayer";
    GEODE_CUSTOM_CONSTRUCTOR_GD(BrowseSmartTemplateLayer, FLAlertLayer)

    /**
     * @note[short] Android
     */
    static BrowseSmartTemplateLayer* create(GJSmartTemplate* p0, SmartBrowseFilter p1);

    /**
     * @note[short] MacOS (ARM): 0x43b324
     * @note[short] MacOS (Intel): 0x4d7a20
     * @note[short] Windows: 0x443040
     * @note[short] iOS: 0x76884
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x43b348
     * @note[short] MacOS (Intel): 0x4d7a60
     * @note[short] Windows: 0x443060
     * @note[short] iOS: 0x768a8
     * @note[short] Android
     */
    virtual void onBack(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    TodoReturn addObjectToPage(cocos2d::CCObject* p0, int p1);

    /**
     * @note[short] Android
     */
    TodoReturn addPrefabMenuItem(SmartPrefabResult p0, int p1);

    /**
     * @note[short] Android
     */
    TodoReturn baseSetup();

    /**
     * @note[short] Android
     */
    TodoReturn createDots();

    /**
     * @note[short] Android
     */
    TodoReturn createPrefab(gd::string p0, int p1);

    /**
     * @note[short] Android
     */
    void goToPage(int p0);

    /**
     * @note[short] MacOS (ARM): 0x439948
     * @note[short] MacOS (Intel): 0x4d5f10
     * @note[short] Android
     */
    bool init(GJSmartTemplate* p0, SmartBrowseFilter p1);

    /**
     * @note[short] Android
     */
    void onClick(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    void onTemplateObject(cocos2d::CCObject* sender);

    /**
     * @note[short] Android
     */
    TodoReturn updateDots();
    GJSmartTemplate* m_template;
    cocos2d::CCArray* m_pages;
    int m_page;
    cocos2d::CCNode* m_nextPageBtn;
    cocos2d::CCNode* m_prevPageBtn;
    cocos2d::CCArray* m_dotsArray;
};
