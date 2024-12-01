#include "pch.h"

#include "G3DPlanetPopup.h"
#include "G3DPlanetLayer.h"

#include "game/component/G3DProgressBar.h"

#include "PlanetStateManager.h"

namespace g3d
{
    bool G3DPlanetPopup::setup(int levelID) {
        this->setTitle(std::to_string(levelID));
        this->levelID = levelID;
        auto size = CCDirector::sharedDirector()->getWinSize();
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

        normalBar->setProgress(PlanetStateManager::getInstance()->getProgressByLevelID(levelID)->normal);
        normalBar->setColor(ccc3(0, 255, 0));

        practiceBar->setProgress(PlanetStateManager::getInstance()->getProgressByLevelID(levelID)->practice);
        practiceBar->setColor(ccc3(0, 150, 255));
    }

    void G3DPlanetPopup::onPlayLevel(CCObject*) {
        auto level = GJGameLevel::create();
        level->m_levelID = levelID;
        level->m_levelType = GJLevelType::Editor;
        level->m_normalPercent = PlanetStateManager::getInstance()->getProgressByLevelID(levelID)->normal;
        level->m_practicePercent = PlanetStateManager::getInstance()->getProgressByLevelID(levelID)->practice;
        auto playLayer = PlayLayer::scene(level, 0, 0);
        CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.3, playLayer));
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
