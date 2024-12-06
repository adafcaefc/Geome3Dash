#include "pch.h"

#include <hjfod.gmd-api/include/GMD.hpp>

#include "G3DPlanetPopup.h"
#include "G3DPlanetLayer.h"

#include "game/component/G3DProgressBar.h"
#include "game/component/G3DComingSoonPopup.h"

#include "helper/CommonHelper.h"

#include "PlanetStateManager.h"

namespace g3d
{
    bool G3DPlanetPopup::setup(int levelID) 
    {
        this->levelID = levelID;
        level = nullptr;
        const auto path = geode::Mod::get()->getResourcesDir() / "level" / (std::to_string(levelID) + ".gmd");
        if (std::filesystem::exists(path))
        {
            if (level = gmd::importGmdAsLevel(path).unwrapOr(nullptr))
            {
                level->m_levelID = levelID;
                this->addChild(level);
            }
        }

        if (level) { this->setTitle(level->m_levelName); }
        else { this->setTitle("Coming Soon!"); }
        this->levelID = levelID;
        auto mySize = this->m_bgSprite->getContentSize();

        this->m_closeBtn->setZOrder(5);

        auto corner1 = CCSprite::createWithSpriteFrameName("rewardCorner_001.png");
        corner1->setPosition({ 0, 0 });
        corner1->setAnchorPoint({ 0, 0 });
        m_buttonMenu->addChild(corner1);

        auto corner2 = CCSprite::createWithSpriteFrameName("rewardCorner_001.png");
        corner2->setPosition({ 0, mySize.height });
        corner2->setRotation(90);
        corner2->setAnchorPoint({ 0, 0 });
        m_buttonMenu->addChild(corner2);

        auto corner3 = CCSprite::createWithSpriteFrameName("rewardCorner_001.png");
        corner3->setPosition({ mySize.width, mySize.height });
        corner3->setRotation(180);
        corner3->setAnchorPoint({ 0, 0 });
        m_buttonMenu->addChild(corner3);

        auto corner4 = CCSprite::createWithSpriteFrameName("rewardCorner_001.png");
        corner4->setPosition({ mySize.width, 0 });
        corner4->setRotation(270);
        corner4->setAnchorPoint({ 0, 0 });
        m_buttonMenu->addChild(corner4);

        auto playBtnSprite = CCSprite::createWithSpriteFrameName("GJ_playBtn2_001.png");
        auto playBtn = CCMenuItemSpriteExtra::create(playBtnSprite, this, menu_selector(G3DPlanetPopup::onPlayLevel));
        playBtn->setPosition({ mySize.width / 2, mySize.height / 2 + 20 });
        m_buttonMenu->addChild(playBtn);

        normalBar = G3DProgressBar::create();
        normalBar->setPosition({ mySize.width / 2, mySize.height / 2 - 50 });
        normalBar->setScale(0.5);
        m_buttonMenu->addChild(normalBar);

        practiceBar = G3DProgressBar::create();
        practiceBar->setPosition({ mySize.width / 2, mySize.height / 2 - 65 });
        practiceBar->setScale(0.5);
        m_buttonMenu->addChild(practiceBar);

        return true;
    }

    void G3DPlanetPopup::onEnter() {
        Popup::onEnter();

        if (openOnce) { parentLayer->playNewSongType(); }
        openOnce = true;
        auto psm = PlanetStateManager::getInstance();
        normalBar->setProgress(psm->currentProgress[levelID].normal);
        normalBar->setColor(ccc3(0, 255, 0));

        practiceBar->setProgress(psm->currentProgress[levelID].practice);
        practiceBar->setColor(ccc3(0, 150, 255));
    }

    void G3DPlanetPopup::onPlayLevel(CCObject*) 
    {
        if (level)
        {
            auto playLayer = PlayLayer::scene(level, 0, 0);
            CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.3f, playLayer));
        }
        else
        {
            std::vector<std::string> comingSoonTexts =
            {
                "",
                "",
                "Prepare for the next big leap in <cy>Geome3Dash</c>.",
                "New levels are in the works with <cr>epic 3D adventures</c>.",
                "Our team is crafting something <co>unforgettable</c> just for you!",
                "<cy>What to expect:</c>",
                "<cr>New Levels</c> - Explore unique challenges in vibrant 3D worlds.",
                "<cg>Expanded Story Mode</c> - Unlock deeper gameplay and surprises.",
                "<co>Stay connected</c> - Follow updates on our GitHub."
            };
            G3DComingSoonPopup::scene(comingSoonTexts, parentLayer);
        }
    }

    void G3DPlanetPopup::onClose(cocos2d::CCObject* obj) {
        Popup::onClose(obj);
        isOpened = false;
    }

    void G3DPlanetPopup::tryOpen(int levelID, G3DPlanetLayer* parentLayer) {
        if (!isOpened) {
            isOpened = true;
            auto ret = new G3DPlanetPopup();
            if (ret->initAnchored(240.f, 200.f, levelID)) {
                ret->parentLayer = parentLayer;
                ret->autorelease();
                ret->show();
                return;
            }
            delete ret;
        }
    }

    bool G3DPlanetPopup::isOpened = false;
}
