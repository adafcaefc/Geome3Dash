#include "pch.h"
#include "game/editor/G3DEditorPopup.h"
#include "game/editor/G3DCurveEditorLayer.h"

namespace g3d
{
    class $modify(LevelEditorLayerG3D, LevelEditorLayer)
    {
        struct Fields {
            G3DCurveEditorLayer* curveEditorLayer = nullptr;
        };

        //std::optional<std::string> getFrameName(CCSprite* sprite)
        //{
        //    auto texture = sprite->getTexture();
        //    auto rect = sprite->getTextureRect();
        //    auto* cachedFrames = CCSpriteFrameCache::sharedSpriteFrameCache()->m_pSpriteFrames;
        //    for (auto [key, frame] : geode::cocos::CCDictionaryExt<std::string, CCSpriteFrame*>(cachedFrames))
        //    {
        //        if (frame->getTexture() == texture && frame->getRect() == rect) { return key; }
        //    }
        //    return std::nullopt;
        //}

        void onSplineEditor(CCObject * obj) 
        {
            //auto editorUI = dynamic_cast<EditorUI*>(this->getChildByID("EditorUI"));
            //auto playtestButton = this->getChildByIDRecursive("playtest-button");
            //auto playtestButtonSprite = playtestButton->getChildByType<CCSprite>(0);
            //bool isPlayTesting = false;
            //auto cFrame = getFrameName(playtestButtonSprite);
            //if (cFrame.has_value() && cFrame.value() == "GJ_pauseEditorBtn_001.png") { isPlayTesting = true; }
            //if (isPlayTesting) { editorUI->onPlaytest(playtestButton); }
            m_fields->curveEditorLayer->show();
        }

        void onEditorPopup(CCObject * sender)
        {
            G3DEditorPopup::scene();
        }

        void addG3DMenu(
            const int shiftAmount,
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
            menu->setPosition(settingsButton->getPosition() + CCPoint(-44.5 - 40.0 * shiftAmount, -2.75));
            auto label = CCLabelBMFont::create(text, "bigFont.fnt", sprite->getContentWidth());
            sprite->addChild(label);
            label->setPosition(CCPoint(23.5, 24.5));
            label->setScale(0.5);

            settingsMenu->addChild(menu);
        }

        bool init(GJGameLevel * p0, bool p1)
        {
            if (!LevelEditorLayer::init(p0, p1)) { return false; }

            auto settingsButton = this->getChildByIDRecursive("settings-button");
            auto settingsMenu = this->getChildByIDRecursive("settings-menu");

            auto sprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
            auto menu = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(LevelEditorLayerG3D::onEditorPopup));
            addG3DMenu(0, "CAM", settingsButton, settingsMenu, menu, sprite);

            auto sprite2 = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
            auto menu2 = CCMenuItemSpriteExtra::create(sprite2, this, menu_selector(LevelEditorLayerG3D::onSplineEditor));
            addG3DMenu(1, "PATH", settingsButton, settingsMenu, menu2, sprite2);

            m_fields->curveEditorLayer = G3DCurveEditorLayer::create(this);
            this->addChild(m_fields->curveEditorLayer);

            return true;
        }
    };
}