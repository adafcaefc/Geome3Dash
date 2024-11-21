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
#include "ColorSelectDelegate.hpp"
#include "SliderDelegate.hpp"

class CreateParticlePopup : public FLAlertLayer, public TextInputDelegate, public ColorSelectDelegate, public SliderDelegate {
public:
    static constexpr auto CLASS_NAME = "CreateParticlePopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(CreateParticlePopup, FLAlertLayer)
    
private:
    [[deprecated("CreateParticlePopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static CreateParticlePopup* create(gd::string p0);
public:
    
private:
    [[deprecated("CreateParticlePopup::create not implemented")]]
    /**
     * @note[short] Android
     */
    static CreateParticlePopup* create(ParticleGameObject* p0, cocos2d::CCArray* p1, gd::string p2);
public:

    /**
     * @note[short] MacOS (Intel): 0x45bb50
     * @note[short] Windows: 0x414180
     * @note[short] Android
     */
    static CreateParticlePopup* create(ParticleGameObject* p0, cocos2d::CCArray* p1);
    
private:
    [[deprecated("CreateParticlePopup::update not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x3d3a48
     * @note[short] MacOS (Intel): 0x463940
     * @note[short] iOS: 0x2d0d74
     * @note[short] Android
     */
    virtual void update(float p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x3d4520
     * @note[short] MacOS (Intel): 0x4644c0
     * @note[short] Windows: 0x41d070
     * @note[short] iOS: 0x2d15dc
     * @note[short] Android
     */
    virtual bool ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);

    /**
     * @note[short] MacOS (ARM): 0x3d4614
     * @note[short] MacOS (Intel): 0x4645d0
     * @note[short] Windows: 0x41d170
     * @note[short] iOS: 0x2d16d0
     * @note[short] Android
     */
    virtual void ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);

    /**
     * @note[short] MacOS (ARM): 0x3d49b0
     * @note[short] MacOS (Intel): 0x4649a0
     * @note[short] Windows: 0x41d5a0
     * @note[short] iOS: 0x2d1a68
     * @note[short] Android
     */
    virtual void ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);
    
private:
    [[deprecated("CreateParticlePopup::ccTouchCancelled not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x3d49ec
     * @note[short] MacOS (Intel): 0x4649f0
     * @note[short] iOS: 0x2d1aa4
     * @note[short] Android
     */
    virtual void ccTouchCancelled(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1);
public:

    /**
     * @note[short] MacOS (ARM): 0x3d438c
     * @note[short] MacOS (Intel): 0x464320
     * @note[short] Windows: 0x41d060
     * @note[short] iOS: 0x2d1504
     * @note[short] Android
     */
    virtual void keyBackClicked();

    /**
     * @note[short] MacOS (ARM): 0x3d423c
     * @note[short] MacOS (Intel): 0x4641e0
     * @note[short] Windows: 0x41c7a0
     * @note[short] iOS: 0x2d13d4
     * @note[short] Android
     */
    virtual void sliderBegan(Slider* p0);

    /**
     * @note[short] MacOS (ARM): 0x3d4354
     * @note[short] MacOS (Intel): 0x4642c0
     * @note[short] Windows: 0x41c860
     * @note[short] iOS: 0x2d14ec
     * @note[short] Android
     */
    virtual void sliderEnded(Slider* p0);

    /**
     * @note[short] MacOS (ARM): 0x3d37d4
     * @note[short] MacOS (Intel): 0x4636b0
     * @note[short] Windows: 0x419e10
     * @note[short] iOS: 0x2d0b10
     * @note[short] Android
     */
    virtual void colorSelectClosed(cocos2d::CCNode* p0);
    
private:
    [[deprecated("CreateParticlePopup::textInputShouldOffset not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x3d4398
     * @note[short] MacOS (Intel): 0x464350
     * @note[short] iOS: 0x2d1510
     * @note[short] Android
     */
    virtual void textInputShouldOffset(CCTextInputNode* p0, float p1);
public:
    
private:
    [[deprecated("CreateParticlePopup::textInputReturn not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x3d4468
     * @note[short] MacOS (Intel): 0x464410
     * @note[short] iOS: 0x2d157c
     * @note[short] Android
     */
    virtual void textInputReturn(CCTextInputNode* p0);
public:
    
private:
    [[deprecated("CreateParticlePopup::textInputClosed not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x3d3b8c
     * @note[short] MacOS (Intel): 0x463ab0
     * @note[short] iOS: 0x2d0ea8
     * @note[short] Android
     */
    virtual void textInputClosed(CCTextInputNode* p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x3d3ba8
     * @note[short] MacOS (Intel): 0x463af0
     * @note[short] Windows: 0x41a6b0
     * @note[short] iOS: 0x2d0ec4
     * @note[short] Android
     */
    virtual void textChanged(CCTextInputNode* p0);
    
private:
    [[deprecated("CreateParticlePopup::centerAlignParticle not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn centerAlignParticle(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("CreateParticlePopup::createParticleSlider not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn createParticleSlider(gjParticleValue p0, int p1, bool p2, cocos2d::CCPoint p3, cocos2d::CCArray* p4);
public:
    
private:
    [[deprecated("CreateParticlePopup::getPage not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getPage(int p0);
public:
    
private:
    [[deprecated("CreateParticlePopup::getPageButton not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getPageButton(int p0);
public:
    
private:
    [[deprecated("CreateParticlePopup::getPageContainer not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getPageContainer(int p0);
public:
    
private:
    [[deprecated("CreateParticlePopup::getPageInputNodes not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getPageInputNodes(int p0);
public:
    
private:
    [[deprecated("CreateParticlePopup::getPageMenu not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getPageMenu(int p0);
public:
    
private:
    [[deprecated("CreateParticlePopup::getPageSliders not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn getPageSliders(int p0);
public:

    /**
     * @note[short] MacOS (ARM): 0x3ccd08
     * @note[short] MacOS (Intel): 0x45be60
     * @note[short] Windows: 0x414370
     * @note[short] Android
     */
    bool init(ParticleGameObject* p0, cocos2d::CCArray* p1, gd::string p2);
    
private:
    [[deprecated("CreateParticlePopup::maxSliderValueForType not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn maxSliderValueForType(gjParticleValue p0);
public:
    
private:
    [[deprecated("CreateParticlePopup::minSliderValueForType not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn minSliderValueForType(gjParticleValue p0);
public:
    
private:
    [[deprecated("CreateParticlePopup::onAnimateActiveOnly not implemented")]]
    /**
     * @note[short] Android
     */
    void onAnimateActiveOnly(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onAnimateOnTrigger not implemented")]]
    /**
     * @note[short] Android
     */
    void onAnimateOnTrigger(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onCalcEmission not implemented")]]
    /**
     * @note[short] Android
     */
    void onCalcEmission(cocos2d::CCObject* sender);
public:

    /**
     * @note[short] MacOS (ARM): 0x3d0ad8
     * @note[short] MacOS (Intel): 0x460450
     * @note[short] Windows: 0x41cf20
     * @note[short] Android
     */
    void onClose(cocos2d::CCObject* sender);
    
private:
    [[deprecated("CreateParticlePopup::onCopySettings not implemented")]]
    /**
     * @note[short] Android
     */
    void onCopySettings(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onDuplicateColor not implemented")]]
    /**
     * @note[short] Android
     */
    void onDuplicateColor(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onDurationForever not implemented")]]
    /**
     * @note[short] Android
     */
    void onDurationForever(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onDynamicColor not implemented")]]
    /**
     * @note[short] Android
     */
    void onDynamicColor(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onDynamicRotation not implemented")]]
    /**
     * @note[short] Android
     */
    void onDynamicRotation(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onEmitterMode not implemented")]]
    /**
     * @note[short] Android
     */
    void onEmitterMode(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onEndRGBVarSync not implemented")]]
    /**
     * @note[short] Android
     */
    void onEndRGBVarSync(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onMaxEmission not implemented")]]
    /**
     * @note[short] Android
     */
    void onMaxEmission(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onMode not implemented")]]
    /**
     * @note[short] Android
     */
    void onMode(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onOrderSensitive not implemented")]]
    /**
     * @note[short] Android
     */
    void onOrderSensitive(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onPage not implemented")]]
    /**
     * @note[short] Android
     */
    void onPage(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onPasteSettings not implemented")]]
    /**
     * @note[short] Android
     */
    void onPasteSettings(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onPosType not implemented")]]
    /**
     * @note[short] Android
     */
    void onPosType(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onQuickStart not implemented")]]
    /**
     * @note[short] Android
     */
    void onQuickStart(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onSelectColor not implemented")]]
    /**
     * @note[short] Android
     */
    void onSelectColor(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onSelectParticleTexture not implemented")]]
    /**
     * @note[short] Android
     */
    void onSelectParticleTexture(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onStartRGBVarSync not implemented")]]
    /**
     * @note[short] Android
     */
    void onStartRGBVarSync(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onToggleBlending not implemented")]]
    /**
     * @note[short] Android
     */
    void onToggleBlending(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onToggleStartRadiusEqualToEnd not implemented")]]
    /**
     * @note[short] Android
     */
    void onToggleStartRadiusEqualToEnd(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onToggleStartRotationIsDir not implemented")]]
    /**
     * @note[short] Android
     */
    void onToggleStartRotationIsDir(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onToggleStartSizeEqualToEnd not implemented")]]
    /**
     * @note[short] Android
     */
    void onToggleStartSizeEqualToEnd(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onToggleStartSpinEqualToEnd not implemented")]]
    /**
     * @note[short] Android
     */
    void onToggleStartSpinEqualToEnd(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::onUniformColor not implemented")]]
    /**
     * @note[short] Android
     */
    void onUniformColor(cocos2d::CCObject* sender);
public:
    
private:
    [[deprecated("CreateParticlePopup::particleValueIsInt not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn particleValueIsInt(gjParticleValue p0);
public:
    
private:
    [[deprecated("CreateParticlePopup::sliderChanged not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn sliderChanged(cocos2d::CCObject* p0);
public:
    
private:
    [[deprecated("CreateParticlePopup::titleForParticleValue not implemented")]]
    /**
     * @note[short] MacOS (ARM): 0x3e51c0
     * @note[short] Android
     */
    TodoReturn titleForParticleValue(gjParticleValue p0);
public:
    
private:
    [[deprecated("CreateParticlePopup::toggleGravityMode not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn toggleGravityMode(bool p0);
public:
    
private:
    [[deprecated("CreateParticlePopup::updateColorSprite not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateColorSprite(int p0);
public:
    
private:
    [[deprecated("CreateParticlePopup::updateInputNodeStringForType not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateInputNodeStringForType(gjParticleValue p0);
public:
    
private:
    [[deprecated("CreateParticlePopup::updateParticleValueForType not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateParticleValueForType(float p0, gjParticleValue p1, cocos2d::CCParticleSystemQuad* p2);
public:
    
private:
    [[deprecated("CreateParticlePopup::updateSliderForType not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn updateSliderForType(gjParticleValue p0);
public:
    
private:
    [[deprecated("CreateParticlePopup::valueForParticleValue not implemented")]]
    /**
     * @note[short] Android
     */
    TodoReturn valueForParticleValue(gjParticleValue p0);
public:
    
private:
    [[deprecated("CreateParticlePopup::willClose not implemented")]]
    /**
     * @note[short] Android
     */
    void willClose();
public:
    ParticleGameObject* m_targetObject;
    cocos2d::CCArray* m_targetObjects;
    cocos2d::CCArray* m_particles;
    bool m_unkBool;
    cocos2d::CCParticleSystemQuad* m_particle;
};
