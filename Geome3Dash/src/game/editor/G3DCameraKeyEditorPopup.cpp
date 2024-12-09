#include "pch.h"

#include "G3DCameraKeyEditorPopup.h"
#include "G3DCameraKeyEditorLoader.h"
#include "game/component/G3DBaseNode.h"

#include "helper/spline/Curve.h"
#include "helper/spline/Spline.h"
#include "helper/OpenGLStateHelper.h"
#include "helper/KeyframeData.h"

#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Shaders.h"

#include "manager/ModelManager.h"
#include "manager/LevelDataManager.h"

namespace g3d 
{
	bool G3DCameraKeyEditorPopup::setup(G3DCameraKeyEditorLoader* ckel) 
	{
		this->ckel = ckel;
		this->scene = G3DCameraKeyEditorScene::create(ckel->lel);
		this->m_mainLayer->addChild(scene);


		this->setMouseEnabled(true);

		this->m_bgSprite->removeFromParent();
		this->m_closeBtn->removeFromParent();

		auto size = CCDirector::sharedDirector()->getWinSize();

		auto bg = CCSprite::create("GJ_gradientBG.png");
		bg->setScaleX(size.width / bg->getContentSize().width);
		bg->setScaleY(size.height / bg->getContentSize().height);
		bg->setColor({ 0, 75, 110 });
		bg->setZOrder(-5);
		bg->setPosition(size / 2);
		this->addChild(bg);

		this->m_buttonMenu->setPosition(size / 2);

		auto backBtnSprite = CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png");
		backBtnSprite->setScale(0.7f);
		auto backBtn = CCMenuItemSpriteExtra::create(backBtnSprite, this, menu_selector(G3DCameraKeyEditorPopup::onClose));
		backBtn->setPosition(20, size.height - 20);
		this->m_buttonMenu->addChild(backBtn);

		auto addCurveSprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
		addCurveSprite->setScale(0.7f);
		auto addCurveLabel = CCLabelBMFont::create("+", "bigFont.fnt", 80.f);
		addCurveLabel->setScale(1.2f);
		addCurveLabel->setPosition(addCurveSprite->getContentSize() / 2 - ccp(0, -4.f));
		addCurveSprite->addChild(addCurveLabel);
		auto addCurveBtn = CCMenuItemSpriteExtra::create(addCurveSprite, this->scene, menu_selector(G3DCameraKeyEditorScene::onAdd));
		addCurveBtn->setPosition(60, size.height - 20);
		this->m_buttonMenu->addChild(addCurveBtn);

		auto removeCurveSprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
		removeCurveSprite->setScale(0.7f);
		auto removeCurveLabel = CCLabelBMFont::create("-", "bigFont.fnt", 80.f);
		removeCurveLabel->setScale(1.2f);
		removeCurveLabel->setPosition(removeCurveSprite->getContentSize() / 2 - ccp(0, -4.f));
		removeCurveSprite->addChild(removeCurveLabel);
		auto removeCurveBtn = CCMenuItemSpriteExtra::create(removeCurveSprite, this->scene, menu_selector(G3DCameraKeyEditorScene::onRemoveLast));
		removeCurveBtn->setPosition(100, size.height - 20);
		this->m_buttonMenu->addChild(removeCurveBtn);

		return true;
	}

	void G3DCameraKeyEditorPopup::onClose(CCObject* obj) {
		if (scene->levelData.keyframe.keyframes.empty())
		{ 
			setStartingKeyframe(
				&scene->levelData,
				&scene->levelData.keyframe,
				scene->lengthScaleFactor);
		}
		scene->levelData.keyframe = scene->levelData.keyframe;
		setLevelData(LevelEditorLayer::get(), scene->levelData);
		this->setMouseEnabled(false);
		ckel->popup = nullptr;
		scene->levelEditorLayer->onStopPlaytest();
		Popup::onClose(obj);
	}

	G3DCameraKeyEditorPopup* G3DCameraKeyEditorPopup::create(G3DCameraKeyEditorLoader* ckel) 
	{
		auto ret = new G3DCameraKeyEditorPopup();
		auto size = CCDirector::sharedDirector()->getWinSize();
		if (ret->initAnchored(size.width, size.height, ckel)) 
		{
			ret->autorelease();
			return ret;
		}
		delete ret;
		return nullptr;
	}
}