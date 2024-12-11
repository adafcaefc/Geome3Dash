#include "pch.h"
#include "game/editor/G3DCameraEditorPopup.h"
#include "game/editor/G3DCurveEditorLoader.h"
#include "game/editor/G3DCameraKeyEditorLoader.h"
#include "engine/sus3d/spline/Spline.h"
#include "engine/sus3d/spline/Curve.h"

namespace g3d
{
    class $modify(LevelEditorLayerG3D, LevelEditorLayer)
    {
        struct Fields {
            G3DCurveEditorLoader* curveEditorLayer = nullptr;
            G3DCameraKeyEditorLoader* keyframeEditorLayer = nullptr;
        };

        void onCameraKeyframesEditor(CCObject* obj) {
            this->onPlaytest();
            m_fields->keyframeEditorLayer->show();
        }

        void onStopPlaytest() {
            LevelEditorLayer::onStopPlaytest();
            const auto enabled = !geode::Mod::get()->getSettingValue<bool>("disable-general-3d");
            if (enabled) { m_fields->keyframeEditorLayer->hide(); }
        }

        void onSplineEditor(CCObject * obj) 
        {
            m_fields->curveEditorLayer->show();
        }

        void onEditorPopup(CCObject * sender)
        {
            G3DCameraEditorPopup::scene(this);
        }

        void addG3DMenu(
            const CCPoint& shift,
            const char* text,
            CCNode * settingsButton,
            CCNode * settingsMenu,
            CCMenuItemSpriteExtra * menu,
            CCSprite * sprite)
        {
            auto settingsButtonSprite = settingsButton->getChildByType<CCSprite>(0);
            sprite->setContentSize(settingsButtonSprite->getContentSize());
            sprite->setScale(settingsButtonSprite->getScale() * 0.8);
            sprite->setPosition(settingsButtonSprite->getPosition());
            menu->setContentSize(settingsButton->getContentSize());
            menu->setScale(settingsButton->getScale());
            menu->setPosition(settingsButton->getPosition() + CCPoint(-44.5, -2.75) + shift);
            auto label = CCLabelBMFont::create(text, "bigFont.fnt", sprite->getContentWidth());
            sprite->addChild(label);
            label->setPosition(CCPoint(23.5, 24.5));
            label->setScale(0.5);

            settingsMenu->addChild(menu);
        }

        bool init(GJGameLevel * p0, bool p1)
        {
            if (!LevelEditorLayer::init(p0, p1)) { return false; }

            const auto enabled = !geode::Mod::get()->getSettingValue<bool>("disable-general-3d");
            if (!enabled) { return true; }

            auto settingsButton = this->getChildByIDRecursive("settings-button");
            auto settingsMenu = this->getChildByIDRecursive("settings-menu");

            auto sprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
            auto menu = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(LevelEditorLayerG3D::onEditorPopup));
            addG3DMenu(ccp(-28, -40), "CAM", settingsButton, settingsMenu, menu, sprite);

            auto sprite2 = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
            auto menu2 = CCMenuItemSpriteExtra::create(sprite2, this, menu_selector(LevelEditorLayerG3D::onSplineEditor));
            addG3DMenu(ccp(-28, -120), "PATH", settingsButton, settingsMenu, menu2, sprite2);

            auto sprite3 = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
            auto menu3 = CCMenuItemSpriteExtra::create(sprite3, this, menu_selector(LevelEditorLayerG3D::onCameraKeyframesEditor));
            addG3DMenu(ccp(-28, -80), "KEY", settingsButton, settingsMenu, menu3, sprite3);

            m_fields->curveEditorLayer = G3DCurveEditorLoader::create(this);
            this->addChild(m_fields->curveEditorLayer);

            m_fields->keyframeEditorLayer = G3DCameraKeyEditorLoader::create(this);
            this->addChild(m_fields->keyframeEditorLayer);

            return true;
        }
    };
}