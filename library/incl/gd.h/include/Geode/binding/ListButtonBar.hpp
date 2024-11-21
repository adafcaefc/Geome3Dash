#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class ListButtonBar : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "ListButtonBar";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(ListButtonBar, cocos2d::CCNode)

    /**
     * @note[short] MacOS (ARM): 0x360e74
     * @note[short] MacOS (Intel): 0x3de040
     * @note[short] Windows: 0x6ad70
     * @note[short] Android
     */
    static ListButtonBar* create(cocos2d::CCArray* p0, cocos2d::CCPoint p1, int p2, int p3, float p4, float p5, float p6, float p7, int p8);
    
private:
    [[deprecated("ListButtonBar::getPage not implemented")]]
    /**
     * @note[short] Android
     */
    int getPage();
public:

    /**
     * @note[short] MacOS (ARM): 0x361584
     * @note[short] Windows: 0x6b380
     * @note[short] Android
     */
    void goToPage(int p0);

    /**
     * @note[short] MacOS (ARM): 0x360f58
     * @note[short] MacOS (Intel): 0x3de110
     * @note[short] Windows: 0x6ae80
     * @note[short] Android
     */
    bool init(cocos2d::CCArray* p0, cocos2d::CCPoint p1, int p2, int p3, float p4, float p5, float p6, float p7, int p8);

    /**
     * @note[short] MacOS (ARM): 0x361460
     * @note[short] Windows: 0x6b430
     * @note[short] Android
     */
    void onLeft(cocos2d::CCObject* sender);

    /**
     * @note[short] MacOS (ARM): 0x3614ec
     * @note[short] Windows: 0x6b410
     * @note[short] Android
     */
    void onRight(cocos2d::CCObject* sender);
    BoomScrollLayer* m_scrollLayer;
    cocos2d::CCArray* m_pages;
    ListButtonBarDelegate* m_delegate;
    bool m_useMoveAnimation;
};
