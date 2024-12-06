#pragma once
#include <stdexcept>
#include <Geode/platform/platform.hpp>
#include <Geode/c++stl/gdstdlib.hpp>
#include <cocos2d.h>
#include <cocos-ext.h>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/SeedValue.hpp>


class GameToolbox {
public:
    static constexpr auto CLASS_NAME = "GameToolbox";

    /**
     * @note[short] MacOS (ARM): 0x43f944
     * @note[short] MacOS (Intel): 0x4dc890
     * @note[short] Windows: 0x65010
     * @note[short] Android
     */
    static void addBackButton(cocos2d::CCLayer* p0, cocos2d::CCMenuItem* p1);

    /**
     * @note[short] MacOS (ARM): 0x43fa2c
     * @note[short] MacOS (Intel): 0x4dc960
     * @note[short] Windows: 0x650f0
     * @note[short] Android
     */
    static void addRThumbScrollButton(cocos2d::CCLayer* p0);

    /**
     * @note[short] MacOS (ARM): 0x43e460
     * @note[short] MacOS (Intel): 0x4db280
     * @note[short] Windows: 0x64110
     * @note[short] Android
     */
    static void alignItemsHorisontally(cocos2d::CCArray* p0, float p1, cocos2d::CCPoint p2, bool p3);
    
private:
    [[deprecated("GameToolbox::alignItemsVertically not implemented")]]
    /**
     * @note[short] Android
     */
    static void alignItemsVertically(cocos2d::CCArray* p0, float p1, cocos2d::CCPoint p2);
public:
    
private:
    [[deprecated("GameToolbox::bounceTime not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn bounceTime(float p0);
public:
    
private:
    [[deprecated("GameToolbox::colorToSepia not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn colorToSepia(cocos2d::ccColor3B p0, float p1);
public:
    
private:
    [[deprecated("GameToolbox::contentScaleClipRect not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn contentScaleClipRect(cocos2d::CCRect& p0);
public:
    
private:
    [[deprecated("GameToolbox::createHashString not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn createHashString(gd::string const& p0, int p1);
public:
    
private:
    [[deprecated("GameToolbox::createToggleButton not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x4dbd60
     * @note[short] Android
     */
    static CCMenuItemToggler* createToggleButton(gd::string label, cocos2d::SEL_MenuHandler selector, bool state, cocos2d::CCMenu* menu, cocos2d::CCPoint position, cocos2d::CCNode* parent, cocos2d::CCNode* labelParent, cocos2d::CCArray* container);
public:

    /**
     * @note[short] MacOS (ARM): 0x43ef50
     * @note[short] MacOS (Intel): 0x4dbe90
     * @note[short] Windows: 0x64670
     * @note[short] Android
     */
    static CCMenuItemToggler* createToggleButton(gd::string label, cocos2d::SEL_MenuHandler selector, bool state, cocos2d::CCMenu* menu, cocos2d::CCPoint position, cocos2d::CCNode* parent, cocos2d::CCNode* labelParent, float buttonScale, float maxLabelScale, float maxLabelWidth, cocos2d::CCPoint labelOffset, char const* font, bool labelTop, int labelTag, cocos2d::CCArray* container);
    
private:
    [[deprecated("GameToolbox::doWeHaveInternet not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x43e8a8
     * @note[short] MacOS (Intel): 0x4db770
     * @note[short] Android
     */
    static bool doWeHaveInternet();
public:
    
private:
    [[deprecated("GameToolbox::easeToText not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x445748
     * @note[short] MacOS (Intel): 0x4e34f0
     * @note[short] Android
     */
    static TodoReturn easeToText(int p0);
public:
    
private:
    [[deprecated("GameToolbox::fast_rand not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn fast_rand();
public:
    
private:
    [[deprecated("GameToolbox::fast_rand_0_1 not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x441870
     * @note[short] MacOS (Intel): 0x4dea80
     * @note[short] Android
     */
    static float fast_rand_0_1();
public:
    
private:
    [[deprecated("GameToolbox::fast_rand_minus1_1 not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn fast_rand_minus1_1();
public:
    
private:
    [[deprecated("GameToolbox::fast_srand not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x441830
     * @note[short] MacOS (Intel): 0x4dea30
     * @note[short] Android
     */
    static void fast_srand(uint64_t p0);
public:
    
private:
    [[deprecated("GameToolbox::gen_random not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x464058
     * @note[short] MacOS (Intel): 0x504920
     * @note[short] Android
     */
    static TodoReturn gen_random(int p0);
public:
    
private:
    [[deprecated("GameToolbox::getDropActionWDelay not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn getDropActionWDelay(float p0, float p1, float p2, cocos2d::CCNode* p3, cocos2d::SEL_CallFunc p4);
public:
    
private:
    [[deprecated("GameToolbox::getDropActionWEnd not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn getDropActionWEnd(float p0, float p1, float p2, cocos2d::CCAction* p3, float p4);
public:
    
private:
    [[deprecated("GameToolbox::getEasedAction not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4415e8
     * @note[short] MacOS (Intel): 0x4de7b0
     * @note[short] Android
     */
    static cocos2d::CCActionEase* getEasedAction(cocos2d::CCActionInterval* p0, int p1, float p2);
public:

    /**
     * @note[short] Windows: 0x68b40
     * @note[short] Android
     */
    static TodoReturn getEasedValue(float p0, int p1, float p2);
    
private:
    [[deprecated("GameToolbox::getfast_srand not implemented")]]
    /**
     * @note[short] Android
     */
    static uint64_t getfast_srand();
public:
    
private:
    [[deprecated("GameToolbox::getInvertedEasing not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn getInvertedEasing(int p0);
public:
    
private:
    [[deprecated("GameToolbox::getLargestMergedIntDicts not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn getLargestMergedIntDicts(cocos2d::CCDictionary* p0, cocos2d::CCDictionary* p1);
public:
    
private:
    [[deprecated("GameToolbox::getMultipliedHSV not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn getMultipliedHSV(cocos2d::ccHSVValue const& p0, float p1);
public:

    /**
     * @note[short] Windows: 0x64970
     * @note[short] Android
     */
    static TodoReturn getRelativeOffset(GameObject* p0, cocos2d::CCPoint p1);

    /**
     * @note[short] MacOS (ARM): 0x43eb40
     * @note[short] MacOS (Intel): 0x4dba00
     * @note[short] Windows: 0x64310
     * @note[short] Android
     */
    static gd::string getResponse(cocos2d::extension::CCHttpResponse* p0);

    /**
     * @note[short] MacOS (ARM): 0x44145c
     * @note[short] MacOS (Intel): 0x4de620
     * @note[short] Windows: 0x65e20
     * @note[short] Android
     */
    static gd::string getTimeString(int p0, bool p1);
    
private:
    [[deprecated("GameToolbox::hsvFromString not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x4dd030
     * @note[short] Android
     */
    static TodoReturn hsvFromString(gd::string const& p0, char const* p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x4465bc
     * @note[short] MacOS (Intel): 0x4e4250
     * @note[short] Windows: 0x69120
     * @note[short] Android
     */
    static gd::string intToShortString(int p0);

    /**
     * @note[short] MacOS (ARM): 0x446284
     * @note[short] MacOS (Intel): 0x4e3f30
     * @note[short] Windows: 0x69060
     * @note[short] Android
     */
    static TodoReturn intToString(int p0);
    
private:
    [[deprecated("GameToolbox::isIOS not implemented")]]
    /**
     * @note[short] Android
     */
    static bool isIOS();
public:
    
private:
    [[deprecated("GameToolbox::isRateEasing not implemented")]]
    /**
     * @note[short] Android
     */
    static bool isRateEasing(int p0);
public:
    
private:
    [[deprecated("GameToolbox::mergeDictsSaveLargestInt not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn mergeDictsSaveLargestInt(cocos2d::CCDictionary* p0, cocos2d::CCDictionary* p1);
public:
    
private:
    [[deprecated("GameToolbox::mergeDictsSkipConflict not implemented")]]
    /**
     * @note[short] MacOS (Intel): 0x4dc610
     * @note[short] Android
     */
    static TodoReturn mergeDictsSkipConflict(cocos2d::CCDictionary* p0, cocos2d::CCDictionary* p1);
public:
    
private:
    [[deprecated("GameToolbox::msToTimeString not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x446c04
     * @note[short] MacOS (Intel): 0x4e48b0
     * @note[short] Android
     */
    static TodoReturn msToTimeString(int p0, int p1);
public:
    
private:
    [[deprecated("GameToolbox::multipliedColorValue not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn multipliedColorValue(cocos2d::ccColor3B p0, cocos2d::ccColor3B p1, float p2);
public:
    
private:
    [[deprecated("GameToolbox::openAppPage not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn openAppPage();
public:
    
private:
    [[deprecated("GameToolbox::openRateURL not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x43ea18
     * @note[short] MacOS (Intel): 0x4db8e0
     * @note[short] Android
     */
    static TodoReturn openRateURL(gd::string p0, gd::string p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x4451a0
     * @note[short] MacOS (Intel): 0x4e2ed0
     * @note[short] Windows: Out of line
     * @note[short] Android
     */
    static cocos2d::CCParticleSystemQuad* particleFromString(gd::string const& str, cocos2d::CCParticleSystemQuad* system, bool p2);

    /**
     * @note[short] MacOS (ARM): 0x44528c
     * @note[short] MacOS (Intel): 0x4e2fe0
     * @note[short] Windows: 0x68000
     * @note[short] Android
     */
    static cocos2d::CCParticleSystemQuad* particleFromStruct(cocos2d::ParticleStruct const& p0, cocos2d::CCParticleSystemQuad* p1, bool p2);

    /**
     * @note[short] MacOS (ARM): 0x444354
     * @note[short] MacOS (Intel): 0x4e1f80
     * @note[short] Windows: 0x67540
     * @note[short] Android
     */
    static void particleStringToStruct(gd::string const& p0, cocos2d::ParticleStruct& p1);

    /**
     * @note[short] MacOS (ARM): 0x446d4c
     * @note[short] MacOS (Intel): 0x4e49f0
     * @note[short] Windows: 0x69760
     * @note[short] Android
     */
    static gd::string pointsToString(int p0);
    
private:
    [[deprecated("GameToolbox::postClipVisit not implemented")]]
    /**
     * @note[short] Android
     */
    static void postClipVisit();
public:

    /**
     * @note[short] MacOS (ARM): 0x43ed28
     * @note[short] MacOS (Intel): 0x4dbc50
     * @note[short] Windows: 0x645c0
     * @note[short] Android
     */
    static void preVisitWithClippingRect(cocos2d::CCNode* p0, cocos2d::CCRect p1);
    
private:
    [[deprecated("GameToolbox::preVisitWithClipRect not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn preVisitWithClipRect(cocos2d::CCRect p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x4418f4
     * @note[short] MacOS (Intel): 0x4deb00
     * @note[short] Windows: 0x662d0
     * @note[short] Android
     */
    static gd::string saveParticleToString(cocos2d::CCParticleSystemQuad* p0);
    
private:
    [[deprecated("GameToolbox::saveStringToFile not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn saveStringToFile(gd::string const& p0, gd::string const& p1);
public:
    
private:
    [[deprecated("GameToolbox::stringFromHSV not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn stringFromHSV(cocos2d::ccHSVValue p0, char const* p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x440d54
     * @note[short] Windows: 0x65c30
     * @note[short] Android
     */
    static cocos2d::CCDictionary* stringSetupToDict(gd::string const& p0, char const* p1);

    /**
     * @note[short] Windows: 0x65890
     * @note[short] Android
     */
    static gd::map<gd::string,gd::string> stringSetupToMap(gd::string const& p0, char const* p1, gd::map<gd::string, gd::string>& p2);
    
private:
    [[deprecated("GameToolbox::strongColor not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn strongColor(cocos2d::ccColor3B p0);
public:
    
private:
    [[deprecated("GameToolbox::timestampToHumanReadable not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x4469a4
     * @note[short] MacOS (Intel): 0x4e4690
     * @note[short] Android
     */
    static TodoReturn timestampToHumanReadable(long p0);
public:

    /**
     * @note[short] Windows: 0x65290
     * @note[short] Android
     */
    static cocos2d::ccColor3B transformColor(cocos2d::ccColor3B const& p0, cocos2d::ccHSVValue p1);
    
private:
    [[deprecated("GameToolbox::transformColor not implemented")]]
    /**
     * @note[short] Android
     */
    static TodoReturn transformColor(cocos2d::ccColor3B const& p0, float p1, float p2, float p3);
public:
};
