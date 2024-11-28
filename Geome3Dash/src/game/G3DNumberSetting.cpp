#include "pch.h"

#include "Game/G3DNumberSetting.h"

namespace g3d
{
    bool G3DNumberSetting::init(const char* displayName, double* ptrValue, float width) 
    {
        m_ptrValue = ptrValue;
        m_impl_modName = displayName;

        m_impl_bg = CCLayerColor::create({ 0, 0, 0, 0 });
        m_impl_bg->setContentSize({ width, 0 });
        m_impl_bg->ignoreAnchorPointForPosition(false);
        m_impl_bg->setAnchorPoint(ccp(.5f, .5f));
        this->addChildAtPosition(m_impl_bg, geode::Anchor::Center);

        m_impl_nameMenu = CCMenu::create();
        m_impl_nameMenu->setContentWidth(width / 2 + 25);

        m_impl_nameLabel = CCLabelBMFont::create(displayName, "bigFont.fnt");
        m_impl_nameLabel->setLayoutOptions(geode::AxisLayoutOptions::create()->setScaleLimits(.1f, .4f)->setScalePriority(1));
        m_impl_nameMenu->addChild(m_impl_nameLabel);

        m_impl_statusLabel = CCLabelBMFont::create("", "bigFont.fnt");
        m_impl_statusLabel->setScale(.25f);
        this->addChildAtPosition(m_impl_statusLabel, geode::Anchor::Left, ccp(10, -10), ccp(0, .5f));

        auto descSpr = CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
        descSpr->setScale(.5f);
        auto descBtn = CCMenuItemSpriteExtra::create(
            descSpr, this, menu_selector(G3DNumberSetting::onDescription)
        );
        m_impl_nameMenu->addChild(descBtn);

        //auto resetSpr = CCSprite::createWithSpriteFrameName("reset-gold.png"_spr);
        //resetSpr->setScale(.5f);
        //m_impl_resetButton = CCMenuItemSpriteExtra::create(
        //    resetSpr, this, menu_selector(SettingNodeV3::onReset)
        //);
        //m_impl_nameMenu->addChild(m_impl_resetButton);

        m_impl_nameMenu->setLayout(geode::RowLayout::create()->setAxisAlignment(geode::AxisAlignment::Start));
        m_impl_nameMenu->getLayout()->ignoreInvisibleChildren(true);
        this->addChildAtPosition(m_impl_nameMenu, geode::Anchor::Left, ccp(10, 0), ccp(0, .5f));

        m_impl_buttonMenu = CCMenu::create();
        m_impl_buttonMenu->setContentSize({ width / 2 - 55, 30 });
        m_impl_buttonMenu->setLayout(geode::AnchorLayout::create());
        this->addChildAtPosition(m_impl_buttonMenu, geode::Anchor::Right, ccp(-10, 0), ccp(1, .5f));

        // manual adaf fix
        m_impl_nameMenu->setPositionY(m_impl_buttonMenu->getPositionY() + 20);
        m_impl_buttonMenu->setContentSize(CCSize(m_impl_buttonMenu->getContentSize().width + 50, m_impl_buttonMenu->getContentSize().height));

        this->setAnchorPoint({ .5f, .5f });
        this->setContentSize({ width, 30 });

        m_bigArrowLeftBtnSpr = CCSprite::create();
        m_bigArrowLeftBtnSpr->setCascadeColorEnabled(true);
        m_bigArrowLeftBtnSpr->setCascadeOpacityEnabled(true);

        auto bigArrowLeftSpr1 = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
        auto bigArrowLeftSpr2 = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
        m_bigArrowLeftBtnSpr->setContentSize(bigArrowLeftSpr1->getContentSize() + ccp(20, 0));
        m_bigArrowLeftBtnSpr->addChildAtPosition(bigArrowLeftSpr2, geode::Anchor::Center, ccp(10, 0));
        m_bigArrowLeftBtnSpr->addChildAtPosition(bigArrowLeftSpr1, geode::Anchor::Center, ccp(-10, 0));
        m_bigArrowLeftBtnSpr->setScale(.3f);

        m_bigArrowLeftBtn = CCMenuItemSpriteExtra::create(
            m_bigArrowLeftBtnSpr, this, menu_selector(G3DNumberSetting::onArrow)
        );
        m_bigArrowLeftBtn->setUserObject(geode::ObjWrapper<ValueType>::create(-bigArrowStepSize));
        m_bigArrowLeftBtn->setVisible(true); // setting->isBigArrowsEnabled()
        this->getButtonMenu()->addChildAtPosition(m_bigArrowLeftBtn, geode::Anchor::Left, ccp(5, 0));

        m_arrowLeftBtnSpr = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
        m_arrowLeftBtnSpr->setScale(.5f);
        m_arrowLeftBtn = CCMenuItemSpriteExtra::create(
            m_arrowLeftBtnSpr, this, menu_selector(G3DNumberSetting::onArrow)
        );
        m_arrowLeftBtn->setUserObject(geode::ObjWrapper<ValueType>::create(-arrowStepSize));
        m_arrowLeftBtn->setVisible(true); // setting->isArrowsEnabled()
        this->getButtonMenu()->addChildAtPosition(m_arrowLeftBtn, geode::Anchor::Left, ccp(22, 0));

        m_input = geode::TextInput::create(this->getButtonMenu()->getContentWidth() - 40, "Num");
        m_input->setScale(.7f);
        m_input->setCallback([this](auto const& str) {
            this->setValue([this, str]() -> double { try { return std::atof(str.c_str()); } catch (...) { return defaultValue; }}(), m_input);
            this->updateState(m_input);
            });
        //if (!setting->isInputEnabled()) {
        //    m_input->getBGSprite()->setVisible(false);
        //    m_input->setEnabled(false);
        //    m_input->getInputNode()->m_placeholderLabel->setOpacity(255);
        //    m_input->getInputNode()->m_placeholderLabel->setColor(ccWHITE);
        //}
        this->getButtonMenu()->addChildAtPosition(m_input, geode::Anchor::Center);

        m_arrowRightBtnSpr = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
        m_arrowRightBtnSpr->setFlipX(true);
        m_arrowRightBtnSpr->setScale(.5f);
        m_arrowRightBtn = CCMenuItemSpriteExtra::create(
            m_arrowRightBtnSpr, this, menu_selector(G3DNumberSetting::onArrow)
        );
        m_arrowRightBtn->setUserObject(geode::ObjWrapper<ValueType>::create(arrowStepSize));
        m_arrowRightBtn->setVisible(true); // setting->isArrowsEnabled()
        this->getButtonMenu()->addChildAtPosition(m_arrowRightBtn, geode::Anchor::Right, ccp(-22, 0));

        m_bigArrowRightBtnSpr = CCSprite::create();
        m_bigArrowRightBtnSpr->setCascadeColorEnabled(true);
        m_bigArrowRightBtnSpr->setCascadeOpacityEnabled(true);
        auto bigArrowRightSpr1 = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
        bigArrowRightSpr1->setFlipX(true);
        auto bigArrowRightSpr2 = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
        bigArrowRightSpr2->setFlipX(true);

        m_bigArrowRightBtnSpr->setContentSize(bigArrowRightSpr1->getContentSize() + ccp(20, 0));
        m_bigArrowRightBtnSpr->addChildAtPosition(bigArrowRightSpr1, geode::Anchor::Center, ccp(-10, 0));
        m_bigArrowRightBtnSpr->addChildAtPosition(bigArrowRightSpr2, geode::Anchor::Center, ccp(10, 0));
        m_bigArrowRightBtnSpr->setScale(.3f);

        m_bigArrowRightBtn = CCMenuItemSpriteExtra::create(
            m_bigArrowRightBtnSpr, this, menu_selector(G3DNumberSetting::onArrow)
        );
        m_bigArrowRightBtn->setUserObject(geode::ObjWrapper<ValueType>::create(bigArrowStepSize));
        m_bigArrowRightBtn->setVisible(true); // setting->isBigArrowsEnabled()
        this->getButtonMenu()->addChildAtPosition(m_bigArrowRightBtn, geode::Anchor::Right, ccp(-5, 0));

        this->setContentHeight(45);
        this->getButtonMenu()->updateAnchoredPosition(geode::Anchor::Right, ccp(-10, 7));

        m_slider = Slider::create(this, menu_selector(G3DNumberSetting::onSlider));
        m_slider->setScale(.5f);
        this->getButtonMenu()->addChildAtPosition(m_slider, geode::Anchor::Center, ccp(0, -20), ccp(0, 0));

        this->updateState(nullptr);

        return true;
    }

    void G3DNumberSetting::updateState(CCNode* invoker) {
        if (invoker != m_input) {
            m_input->setString(fmt::format(fmt::runtime("{:.2f}"), this->getValue()));
        }

        auto min = minValue;
        auto enableLeft = (!min || this->getValue() > *min);
        m_arrowLeftBtn->setEnabled(enableLeft);
        m_bigArrowLeftBtn->setEnabled(enableLeft);
        m_arrowLeftBtnSpr->setOpacity(enableLeft ? 255 : 155);
        m_arrowLeftBtnSpr->setColor(enableLeft ? ccWHITE : ccGRAY);
        m_bigArrowLeftBtnSpr->setOpacity(enableLeft ? 255 : 155);
        m_bigArrowLeftBtnSpr->setColor(enableLeft ? ccWHITE : ccGRAY);

        auto max = maxValue;
        auto enableRight = (!max || this->getValue() < *max);
        m_arrowRightBtn->setEnabled(enableRight);
        m_bigArrowRightBtn->setEnabled(enableRight);
        m_arrowRightBtnSpr->setOpacity(enableRight ? 255 : 155);
        m_arrowRightBtnSpr->setColor(enableRight ? ccWHITE : ccGRAY);
        m_bigArrowRightBtnSpr->setOpacity(enableRight ? 255 : 155);
        m_bigArrowRightBtnSpr->setColor(enableRight ? ccWHITE : ccGRAY);

        if (m_slider) {
            m_slider->m_touchLogic->m_thumb->setValue(this->valueToSlider(this->getValue()));
            m_slider->updateBar();
            m_slider->m_sliderBar->setColor(ccWHITE);
            m_slider->m_touchLogic->m_thumb->setColor(ccWHITE);
            m_slider->m_touchLogic->m_thumb->setEnabled(true);
        }
    }
}