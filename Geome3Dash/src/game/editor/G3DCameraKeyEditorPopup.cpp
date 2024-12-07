#include "pch.h"

#include "G3DCameraKeyEditorPopup.h"
#include "G3DCameraKeyEditorLoader.h"

#include "helper/spline/Curve.h"
#include "helper/spline/Spline.h"
#include "helper/OpenGLStateHelper.h"
#include "helper/CameraKeyframeBuffer.h"
#include "game/component/G3DBaseNode.h"

#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Shaders.h"

#include "BlockModelStorage.h"
#include "LevelDataManager.h"

namespace g3d 
{
	static LevelData currentLevelData = LevelData::getDefault();

	void G3DCameraKeyEditorPopup::onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) {
		if (!isEditing) return;
		if (button == GLFW_MOUSE_BUTTON_LEFT) {
			if (action == GLFW_PRESS) {
				isRightClicking = true;
				isRightClickingGetPos = false;
			}
			else if (action == GLFW_RELEASE) {
				isRightClicking = false;
			}
		}
	}

	void G3DCameraKeyEditorPopup::onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) {
		if (!isEditing) return;
		if (isRightClicking) {
			if (!isRightClickingGetPos) {
				lastMouseX = static_cast<float>(x);
				lastMouseY = static_cast<float>(y);
				isRightClickingGetPos = true;
			}
			else {
				float deltaX = static_cast<float>(x) - lastMouseX;
				float deltaY = static_cast<float>(y) - lastMouseY;
				if (isPressingControl) {
					float sensitivity = 0.032f;

					auto front = ckel->layer3d->camera.getFront();
					auto up = ckel->layer3d->camera.getUp();
					auto side = glm::normalize(glm::cross(front, up));

					auto localUp = glm::normalize(glm::cross(side, front));

					ckel->layer3d->camera.setPosition(
						ckel->layer3d->camera.getPosition() +
						deltaY * sensitivity * localUp +
						deltaX * -sensitivity * side);
				}
				else {
					float sensitivity = 0.05f;
					float yaw = ckel->layer3d->camera.getYaw() - deltaX * sensitivity;
					float pitch = ckel->layer3d->camera.getPitch() - deltaY * sensitivity;
					pitch = std::clamp(pitch, -89.0f, 89.0f);
					ckel->layer3d->camera.setYaw(yaw);
					ckel->layer3d->camera.setPitch(pitch);
				}
				lastMouseX = static_cast<float>(x);
				lastMouseY = static_cast<float>(y);
			}
		}
	}


	void G3DCameraKeyEditorPopup::scrollWheel(float y, float x) {
		if (!isEditing) return;
		float zoomSensitivity = -0.0328f;
		ckel->layer3d->camera.setPosition(ckel->layer3d->camera.getPosition() + ckel->layer3d->camera.getFront() * y * zoomSensitivity);
	}

	void G3DCameraKeyEditorPopup::onKey(enumKeyCodes key, bool pressed, bool holding) {
		switch (key) {
		case KEY_A:
			if (pressed)
				onAdd(nullptr);
			break;
		case KEY_Space:
			pressed ? ckel->lel->m_player1->pushButton(PlayerButton::Jump) : ckel->lel->m_player1->releaseButton(PlayerButton::Jump);
			break;
		case KEY_Control:
			isPressingControl = pressed;
			break;
		default:
			break;
		}
	}

	bool G3DCameraKeyEditorPopup::setup(G3DCameraKeyEditorLoader* ckel) {

		currentLevelData = LevelData::getDefault();
		try {
			currentLevelData = getLevelData(LevelEditorLayer::get());
		}
		catch (...) {

		}

		ckel->keyframeBuffer = currentLevelData.keyframe;
		ckel->spline = currentLevelData.spline;

		ckel->updateLevel();
		ckel->spline.updateParameterList();
		setStartingKeyframe(
			&currentLevelData, 
			&ckel->keyframeBuffer, 
			ckel->lengthScaleFactor);
		// need to delete this on destructor (later)
		splineTr = new SplineGameObjectTransformer(&ckel->spline, &ckel->lengthScaleFactor);
		splinePlayerTr = new SplinePlayerObjectTransformer(&ckel->spline, &ckel->lengthScaleFactor);
		splineCamTr = new SplineCameraPlayerObjectModelTransformer(&ckel->spline, &ckel->keyframeBuffer, &ckel->layer3d->camera, &ckel->layer3d->light, &ckel->lengthScaleFactor, &isEditing);

		CCObject* obj;
		CCARRAY_FOREACH(ckel->lel->m_objects, obj)
		{
			if (auto block = dynamic_cast<GameObject*>(obj))
			{
				if (BlockModelStorage::get()->getBlockModel(block->m_objectID))
				{
					blocks.push_back(GameObjectModel(block, { splineTr }));
				}
			}
		}

		player1 = PlayerObjectModel(ckel->lel->m_player1, { splinePlayerTr, splineCamTr });
		player2 = PlayerObjectModel(ckel->lel->m_player2, { splinePlayerTr });

		this->setMouseEnabled(true);
		this->ckel = ckel;

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
		auto addCurveBtn = CCMenuItemSpriteExtra::create(addCurveSprite, this, menu_selector(G3DCameraKeyEditorPopup::onAdd));
		addCurveBtn->setPosition(60, size.height - 20);
		this->m_buttonMenu->addChild(addCurveBtn);

		auto removeCurveSprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
		removeCurveSprite->setScale(0.7f);
		auto removeCurveLabel = CCLabelBMFont::create("-", "bigFont.fnt", 80.f);
		removeCurveLabel->setScale(1.2f);
		removeCurveLabel->setPosition(removeCurveSprite->getContentSize() / 2 - ccp(0, -4.f));
		removeCurveSprite->addChild(removeCurveLabel);
		auto removeCurveBtn = CCMenuItemSpriteExtra::create(removeCurveSprite, this, menu_selector(G3DCameraKeyEditorPopup::onRemoveLast));
		removeCurveBtn->setPosition(100, size.height - 20);
		this->m_buttonMenu->addChild(removeCurveBtn);

		return true;
	}

	void G3DCameraKeyEditorPopup::onClose(CCObject* obj) {
		if (ckel->keyframeBuffer.keyframes.empty()) 
		{ 
			setStartingKeyframe(
				&currentLevelData,
				&ckel->keyframeBuffer,
				ckel->lengthScaleFactor);
		}
		currentLevelData.keyframe = ckel->keyframeBuffer;
		setLevelData(LevelEditorLayer::get(), currentLevelData);
		this->setMouseEnabled(false);
		ckel->popup = nullptr;
		ckel->lel->onStopPlaytest();
		Popup::onClose(obj);
	}

	void G3DCameraKeyEditorPopup::onAdd(CCObject*) {
		if (isEditing) {
			
			auto deltaPos = ckel->layer3d->camera.getPosition() - splineCamTr->getPlayerOrientedCameraPosition(&player1);
			auto deltaFront = ckel->layer3d->camera.getFront() - splineCamTr->getPlayerOrientedCameraFront(&player1);
			ckel->keyframeBuffer.setKeyframe(ckel->lel->m_player1->getPositionX(),
				deltaPos,
				deltaFront);
		}
		else {

		}
		ckel->lel->m_editorUI->onPlaytest(nullptr);
		isEditing = !isEditing;
	}
	void G3DCameraKeyEditorPopup::onRemoveLast(CCObject*) {
		ckel->keyframeBuffer.removeLastKeyframe();
		if (ckel->keyframeBuffer.keyframes.empty())
		{
			setStartingKeyframe(
				&currentLevelData,
				&ckel->keyframeBuffer,
				ckel->lengthScaleFactor);
		}
	}

	void G3DCameraKeyEditorPopup::draw() 
	{
		OpenGLStateHelper::saveState();

		glEnable(GL_BLEND);
		glEnable(GL_ALPHA_TEST);
		glEnable(GL_DEPTH_TEST);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		player1.render(ckel->blockShaderProgram, ckel->layer3d->camera, ckel->layer3d->light);
		if (ckel->lel->m_gameState.m_isDualMode) { player2.render(ckel->blockShaderProgram, ckel->layer3d->camera, ckel->layer3d->light); }
		
		for (auto& block : blocks) { block.render(ckel->blockShaderProgram, ckel->layer3d->camera, ckel->layer3d->light); }

		glDisable(GL_DEPTH_TEST);
		glDisable(GL_BLEND);
		glDisable(GL_BLEND_COLOR);

		OpenGLStateHelper::pushState();
	}


	G3DCameraKeyEditorPopup* G3DCameraKeyEditorPopup::create(G3DCameraKeyEditorLoader* ckel) {
		auto ret = new G3DCameraKeyEditorPopup();
		auto size = CCDirector::sharedDirector()->getWinSize();
		if (ret->initAnchored(size.width, size.height, ckel)) {
			ret->autorelease();
			return ret;
		}

		delete ret;
		return nullptr;
	}
}