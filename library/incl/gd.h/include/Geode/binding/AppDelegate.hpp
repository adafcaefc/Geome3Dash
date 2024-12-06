#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class AppDelegate : public cocos2d::CCApplication, public cocos2d::CCSceneDelegate {
public:
    static constexpr auto CLASS_NAME = "AppDelegate";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(AppDelegate, cocos2d::CCApplication)

    /**
     * @note[short] MacOS (ARM): 0x56e744
     * @note[short] MacOS (Intel): 0x645fb0
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android
     */
    static AppDelegate* get();

    /**
     * @note[short] MacOS (ARM): 0x56e5c0
     * @note[short] MacOS (Intel): 0x645e30
     * @note[short] Windows: 0x829f0
     * @note[short] iOS: 0x268414
     * @note[short] Android
     */
    virtual bool applicationDidFinishLaunching();

    /**
     * @note[short] MacOS (ARM): 0x56e838
     * @note[short] MacOS (Intel): 0x6460d0
     * @note[short] Windows: 0x82da0
     * @note[short] iOS: 0x2685f8
     * @note[short] Android
     */
    virtual void applicationDidEnterBackground();

    /**
     * @note[short] MacOS (ARM): 0x56e978
     * @note[short] MacOS (Intel): 0x646230
     * @note[short] Windows: 0x82e20
     * @note[short] iOS: 0x2686b4
     * @note[short] Android
     */
    virtual void applicationWillEnterForeground();

    /**
     * @note[short] MacOS (ARM): 0x56e754
     * @note[short] MacOS (Intel): 0x645fd0
     * @note[short] Windows: 0x82d40
     * @note[short] iOS: 0x268578
     * @note[short] Android
     */
    virtual void applicationWillBecomeActive();

    /**
     * @note[short] MacOS (ARM): 0x56e768
     * @note[short] MacOS (Intel): 0x645ff0
     * @note[short] Windows: 0x82d90
     * @note[short] iOS: 0x26858c
     * @note[short] Android
     */
    virtual void applicationWillResignActive();

    /**
     * @note[short] MacOS (ARM): 0x56ebfc
     * @note[short] MacOS (Intel): 0x6464c0
     * @note[short] Windows: 0x834b0
     * @note[short] iOS: 0x268884
     * @note[short] Android
     */
    virtual void trySaveGame(bool p0);

    /**
     * @note[short] MacOS (ARM): 0x56ecd4
     * @note[short] MacOS (Intel): 0x6465a0
     * @note[short] Windows: 0x83590
     * @note[short] iOS: 0x26885c
     * @note[short] Android
     */
    virtual void willSwitchToScene(cocos2d::CCScene* p0);
    
private:
    [[deprecated("AppDelegate::bgScale not implemented")]]
    /**
     * @note[short] Android
     */
    float bgScale();
public:
    
private:
    [[deprecated("AppDelegate::checkSound not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn checkSound();
public:
    
private:
    [[deprecated("AppDelegate::hideLoadingCircle not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn hideLoadingCircle();
public:
    
private:
    [[deprecated("AppDelegate::loadingIsFinished not implemented")]]
    /**
     * @note[short] Android
     */
    void loadingIsFinished();
public:

    /**
     * @note[short] Windows: 0x83370
     * @note[short] Android
     */
    bool musicTest();

    /**
     * @note[short] Windows: 0x82ff0
     * @note[short] Android
     */
    void pauseGame();

    /**
     * @note[short] Windows: 0x830d0
     * @note[short] Android
     */
    void pauseSound();

    /**
     * @note[short] Windows: 0x82560
     * @note[short] Android
     */
    void platformShutdown();

    /**
     * @note[short] MacOS (ARM): 0x56ea64
     * @note[short] Windows: 0x83270
     * @note[short] Android
     */
    void resumeSound();
    
private:
    [[deprecated("AppDelegate::setIdleTimerDisabled not implemented")]]
    /**
     * @note[short] Android
     */
    void setIdleTimerDisabled(bool p0);
public:

    /**
     * @note[short] Windows: 0x82580
     * @note[short] Android
     */
    void setupGLView();
    
private:
    [[deprecated("AppDelegate::showLoadingCircle not implemented")]]
    /**
     * @note[short] Android
     */
    void showLoadingCircle(bool p0, bool p1, bool p2);
public:
    GEODE_PAD(4);
    cocos2d::CCScene* m_runningScene;
};
