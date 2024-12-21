#include "pch.h"

#include "G3DComingSoonPopup.h"

namespace g3d
{
	bool G3DComingSoonPopup::setup(const std::vector<std::string>& strings)
	{
		this->setTitle("Coming Soon!");
		m_title->setScale(1.25);
		m_title->setPosition(m_title->getPosition() - ccp(0, 15.f));

		auto textLayer = CCLayer::create();
		m_buttonMenu->addChild(textLayer);
		m_closeBtn->setZOrder(1);
		textLayer->setPosition(m_buttonMenu->getPosition());

		textLayer->setAnchorPoint(ccp(0, 0));

		auto corner1 = CCSprite::createWithSpriteFrameName("dailyLevelCorner_001.png");
		corner1->setPosition({ m_size.width / 2 - corner1->getContentSize().width / 2, m_size.height / 2 - corner1->getContentSize().height / 2 });
		corner1->setRotation(180);
		textLayer->addChild(corner1);

		auto corner2 = CCSprite::createWithSpriteFrameName("dailyLevelCorner_001.png");
		corner2->setPosition({ -m_size.width / 2 + corner2->getContentSize().width / 2, m_size.height / 2 - corner2->getContentSize().height / 2 });
		corner2->setRotation(90);
		textLayer->addChild(corner2);

		auto corner3 = CCSprite::createWithSpriteFrameName("dailyLevelCorner_001.png");
		corner3->setPosition({ m_size.width / 2 - corner3->getContentSize().width / 2, -m_size.height / 2 + corner3->getContentSize().height / 2 });
		corner3->setRotation(270);
		textLayer->addChild(corner3);

		auto corner4 = CCSprite::createWithSpriteFrameName("dailyLevelCorner_001.png");
		corner4->setPosition({ -m_size.width / 2 + corner4->getContentSize().width / 2, -m_size.height / 2 + corner4->getContentSize().height / 2 });
		textLayer->addChild(corner4);

		float height = 100;
		for (const std::string& string : strings)
		{
			auto textarea = TextArea::create(string, "chatFont.fnt", 1, 380, { 0.5, 0.5 }, 10, 0);
			textarea->setPositionY(height);
			textLayer->addChild(textarea);
			height -= 25;
		}

		return true;
	}

	void G3DComingSoonPopup::onClose(CCObject* sender)
	{
		geode::Popup<const std::vector<std::string>&>::onClose(sender);
	}


	void G3DComingSoonPopup::scene(
		const std::vector<std::string>& strings, 
		CCLayer* parentLayer)
	{
		const CCSize uiSize = CCDirector::sharedDirector()->getWinSize() - CCSize(60, 40);
		G3DComingSoonPopup* instance = new G3DComingSoonPopup();
		if (instance && instance->initAnchored(uiSize.width, uiSize.height, strings))
		{
			instance->m_noElasticity = true;
			instance->setID("g3d-popup-coming-soon");
			instance->autorelease();
			instance->show();
		}
		else
		{
			CC_SAFE_DELETE(instance);
		}
	}
}