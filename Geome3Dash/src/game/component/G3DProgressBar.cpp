#include "pch.h"

#include "G3DProgressBar.h"

namespace g3d
{

	bool G3DProgressBar::init() {
		if (!CCSprite::initWithFile("GJ_progressBar_001.png")) return false;
		this->updateDisplayedColor(ccc3(0, 0, 0));
		this->setOpacity(100);

		clipper = CCClippingNode::create();
		stencil = CCDrawNode::create();
		clipper->setPosition({ 0, 0 });
		clipper->setContentSize(this->getContentSize());
		updateClipper();
		clipper->setStencil(stencil);
		this->addChild(clipper);

		filling = CCSprite::create("GJ_progressBar_001.png");
		filling->setScaleX(0.98f);
		filling->setScaleY(0.7f);
		filling->setColor(ccc3(255, 255, 0));
		filling->setPosition(this->getContentSize() / 2);
		clipper->addChild(filling);

		label = CCLabelBMFont::create((std::to_string(progress) + "%").c_str(), "bigFont.fnt");
		label->setPosition(this->getContentSize() / 2);
		label->setScale(0.5);
		this->addChild(label);

		return true;
	}

	void G3DProgressBar::updateClipper() {
		stencil->drawRect(CCRect(2, 0, (this->getContentSize().width - 4) / 100 * progress, this->getContentSize().height), ccColor4F(1, 1, 1, 1), 0, ccColor4F(1, 1, 1, 1));
	}

	void G3DProgressBar::setColor(const ccColor3B& color) {
		filling->setColor(color);
	}

	void G3DProgressBar::setProgress(int progress) {
		this->progress = progress;
		updateClipper();
		label->setString((std::to_string(progress) + "%").c_str());
	}

	G3DProgressBar* G3DProgressBar::create() {
		auto ret = new G3DProgressBar();
		if (ret && ret->init()) {
			ret->autorelease();
			return ret;
		}

		delete ret;
		return nullptr;
	}
}