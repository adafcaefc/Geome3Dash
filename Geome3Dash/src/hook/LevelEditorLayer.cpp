#include "pch.h"
#include "game/editor/G3DEditorPopup.h"

namespace g3d
{
    class $modify(LevelEditorLayerG3D, LevelEditorLayer)
    {
        void onEditorPopup(CCObject * sender)
        {
            G3DEditorPopup::scene();
        }

        bool init(GJGameLevel * p0, bool p1)
        {
            if (!LevelEditorLayer::init(p0, p1)) { return false; }
            auto settingsButton = this->getChildByIDRecursive("settings-button");
            auto settingsMenu = this->getChildByIDRecursive("settings-menu");

            auto sprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");

            auto menu = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(LevelEditorLayerG3D::onEditorPopup));

            auto settingsButtonSprite = settingsButton->getChildByType<CCSprite>(0);
            sprite->setContentSize(settingsButtonSprite->getContentSize());
            sprite->setScale(settingsButtonSprite->getScale() * 0.8);
            sprite->setPosition(settingsButtonSprite->getPosition());
            menu->setContentSize(settingsButton->getContentSize());
            menu->setScale(settingsButton->getScale());
            menu->setPosition(settingsButton->getPosition() + CCPoint(-44.5, -2.75));
            auto label = CCLabelBMFont::create("CAM", "bigFont.fnt", sprite->getContentWidth());
            sprite->addChild(label);
            label->setPosition(CCPoint(23.5, 24.5));
            label->setScale(0.5);

            settingsMenu->addChild(menu);

            return true;
        }
    };
}