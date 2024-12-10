#pragma once

#include <Geode/ui/GeodeUI.hpp>
#include <Geode/ui/ScrollLayer.hpp>
#include <Geode/ui/Scrollbar.hpp>
#include <Geode/ui/TextInput.hpp>

namespace g3d
{
    class G3DNumberSetting : public CCNode
    {
    public:
        std::optional<double> minValue = -360.0;
        std::optional<double> maxValue = 360.0;
        double defaultValue = 0;
        double bigArrowStepSize = 10;
        double arrowStepSize = 0.25;

        using ValueType = double;
        geode::TextInput* m_input;
        Slider* m_slider;
        CCMenuItemSpriteExtra* m_arrowLeftBtn;
        CCMenuItemSpriteExtra* m_bigArrowLeftBtn;
        CCMenuItemSpriteExtra* m_arrowRightBtn;
        CCMenuItemSpriteExtra* m_bigArrowRightBtn;
        CCSprite* m_arrowLeftBtnSpr;
        CCSprite* m_bigArrowLeftBtnSpr;
        CCSprite* m_arrowRightBtnSpr;
        CCSprite* m_bigArrowRightBtnSpr;

        CCLayerColor* m_impl_bg;
        CCMenu* m_impl_nameMenu;
        CCMenu* m_impl_buttonMenu;
        CCLabelBMFont* m_impl_nameLabel;
        CCLabelBMFont* m_impl_statusLabel;
        std::string m_impl_modName;
        std::optional<std::string> m_impl_modDescription;
        CCMenuItemSpriteExtra* m_impl_resetButton;

        double* m_ptrValue;
        double getValue() const { return *m_ptrValue; }
        void setValue(const double val, CCObject* sender) { *m_ptrValue = val; }

        cocos2d::CCMenu* getButtonMenu() { return m_impl_buttonMenu; }

        float valueToSlider(ValueType value) {
            auto min = minValue.value_or(-100);
            auto max = maxValue.value_or(+100);
            auto range = max - min;
            return static_cast<float>(std::clamp(static_cast<double>(value - min) / range, 0.0, 1.0));
        }
        ValueType valueFromSlider(float num) {
            auto min = minValue.value_or(-100);
            auto max = maxValue.value_or(+100);
            auto range = max - min;
            auto value = static_cast<ValueType>(num * range + min);
            auto step = 0;
            if (step > 0) {
                value = static_cast<ValueType>(round(value / step) * step);
            }
            return value;
        }

        void onDescription(CCObject*) {
            auto title = m_impl_modName;
            FLAlertLayer::create(
                nullptr,
                title.c_str(),
                m_impl_modDescription.value_or("No description provided"),
                "OK", nullptr,
                std::clamp(title.size() * 16, 300ul, 400ul)
            )->show();
        }

        bool init(const char* displayName, double* ptrValue, float width);
        virtual void updateState(CCNode* invoker);


        void onArrow(CCObject* sender) {
            auto value = this->getValue() + static_cast<geode::ObjWrapper<ValueType>*>(
                static_cast<CCNode*>(sender)->getUserObject()
                )->getValue();
            if (auto min = minValue) {
                value = std::fmax(*min, value);
            }
            if (auto max = maxValue) {
                value = std::fmin(*max, value);
            }
            this->setValue(value, static_cast<CCNode*>(sender));
            this->updateState(nullptr);
        }
        void onSlider(CCObject*) {
            this->setValue(this->valueFromSlider(m_slider->m_touchLogic->m_thumb->getValue()), m_slider);
            this->updateState(nullptr);
        }

    public:
        static G3DNumberSetting* create(const char* displayName, double* ptrValue, float width) {
            auto ret = new G3DNumberSetting();
            if (ret && ret->init(displayName, ptrValue, width)) {
                ret->autorelease();
                return ret;
            }
            CC_SAFE_DELETE(ret);
            return nullptr;
        }
    };
}