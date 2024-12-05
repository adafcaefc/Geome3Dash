#include "pch.h"

#include "CameraKeyframeEditorPopup.h"
#include "CameraKeyframeEditorLoader.h"

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

	void CameraKeyframeEditorPopup::onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) {
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

	void CameraKeyframeEditorPopup::onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) {
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
						deltaX * -sensitivity * side
					);
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


	void CameraKeyframeEditorPopup::scrollWheel(float y, float x) {
		if (!isEditing) return;
		float zoomSensitivity = -0.0328f;
		ckel->layer3d->camera.setPosition(ckel->layer3d->camera.getPosition() + ckel->layer3d->camera.getFront() * y * zoomSensitivity);
	}

	void CameraKeyframeEditorPopup::onKey(enumKeyCodes key, bool pressed, bool holding) {
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
		}
	}

	bool CameraKeyframeEditorPopup::setup(CameraKeyframeEditorLoader* ckel) {

		currentLevelData = LevelData::getDefault();
		try {
			currentLevelData = getLevelData(LevelEditorLayer::get());
		}
		catch (...) {

		}

		ckel->keyframeBuffer = currentLevelData.keyframe;
		ckel->spline = currentLevelData.spline;
		if (ckel->keyframeBuffer.keyframes.empty()) { ckel->keyframeBuffer.setKeyframe(0, glm::vec3(0), glm::vec3(0)); }
		ckel->updateLevel();
		ckel->spline.updateParameterList();

		glm::vec3 newFront;
		newFront.x = cos(glm::radians(currentLevelData.yaw)) * cos(glm::radians(currentLevelData.pitch));
		newFront.y = sin(glm::radians(currentLevelData.pitch));
		newFront.z = sin(glm::radians(currentLevelData.yaw)) * cos(glm::radians(currentLevelData.pitch));
		const auto front = glm::normalize(newFront);
		ckel->keyframeBuffer.setKeyframe(0, glm::vec3(currentLevelData.x, currentLevelData.y, currentLevelData.z) * glm::vec3(ckel->lengthScaleFactor * 16 / 9), newFront);
		
		std::cout << nlohmann::json(ckel->keyframeBuffer).dump() << '\n';

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
		backBtnSprite->setScale(0.7);
		auto backBtn = CCMenuItemSpriteExtra::create(backBtnSprite, this, menu_selector(CameraKeyframeEditorPopup::onClose));
		backBtn->setPosition(20, size.height - 20);
		this->m_buttonMenu->addChild(backBtn);

		auto addCurveSprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
		addCurveSprite->setScale(0.7);
		auto addCurveLabel = CCLabelBMFont::create("+", "bigFont.fnt", 80.f);
		addCurveLabel->setScale(1.2);
		addCurveLabel->setPosition(addCurveSprite->getContentSize() / 2 - ccp(0, -4.f));
		addCurveSprite->addChild(addCurveLabel);
		auto addCurveBtn = CCMenuItemSpriteExtra::create(addCurveSprite, this, menu_selector(CameraKeyframeEditorPopup::onAdd));
		addCurveBtn->setPosition(60, size.height - 20);
		this->m_buttonMenu->addChild(addCurveBtn);

		auto removeCurveSprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
		removeCurveSprite->setScale(0.7);
		auto removeCurveLabel = CCLabelBMFont::create("-", "bigFont.fnt", 80.f);
		removeCurveLabel->setScale(1.2);
		removeCurveLabel->setPosition(removeCurveSprite->getContentSize() / 2 - ccp(0, -4.f));
		removeCurveSprite->addChild(removeCurveLabel);
		auto removeCurveBtn = CCMenuItemSpriteExtra::create(removeCurveSprite, this, menu_selector(CameraKeyframeEditorPopup::onRemoveLast));
		removeCurveBtn->setPosition(100, size.height - 20);
		this->m_buttonMenu->addChild(removeCurveBtn);

		return true;
	}


	void CameraKeyframeEditorPopup::renderPlayer() {
		auto playerDataStruct = ckel->spline.findClosestByLength(ckel->lel->m_player1->getPositionX() * ckel->lengthScaleFactor);
		auto normal = glm::normalize(ckel->spline.normal(playerDataStruct.t));
		auto tangent = glm::normalize(ckel->spline.tangent(playerDataStruct.t));

		glm::vec3 side(1.f, 0.f, 0.f);
		float normalDeltaAngle = glm::radians(ckel->lel->m_player1->getRotation());

		glm::quat firstRotationQuat = glm::angleAxis(normalDeltaAngle, side);



		glm::vec3 binormal = glm::normalize(glm::cross(normal, tangent));
		glm::vec3 adjustedNormal = glm::normalize(glm::cross(tangent, binormal));


		glm::mat3 rotationMatrix(
			binormal,
			adjustedNormal,
			tangent
		);

		glm::quat rotationQuat = glm::quat_cast(rotationMatrix);
		glm::vec3 eulerDegrees = glm::degrees(glm::eulerAngles(rotationQuat * firstRotationQuat));

		ckel->cube->setRotation(eulerDegrees);
		ckel->cube->setScale(glm::vec3(0.5 * ckel->lengthScaleFactor * 30, 0.5 * ckel->lengthScaleFactor * 30, 0.5 * ckel->lengthScaleFactor * 30));
		ckel->cube->setPosition(glm::vec3(playerDataStruct.value + (ckel->spline.normal(playerDataStruct.t) * ckel->lengthScaleFactor * (ckel->lel->m_player1->getPositionY() - 110))));
		ckel->cube->render(ckel->layer3d->shaderProgram, ckel->layer3d->camera.getViewMat(), ckel->layer3d->light.getPosition(), ckel->layer3d->light.getColor(), ckel->layer3d->camera.getPosition(), ckel->layer3d->camera.getProjectionMat());
	}

	void CameraKeyframeEditorPopup::renderGround() {
		glm::vec3 groundSize = glm::vec3(0.5 * ckel->lengthScaleFactor * 30 * 3);

		auto playerData = ckel->spline.findClosestByLength(ckel->lel->m_player1->getPositionX() * ckel->lengthScaleFactor);

		const int groundPartsForRender = 20;

		for (float l = 0; l < playerData.l + groundSize.x * groundPartsForRender; l += groundSize.x * 2) {

			if (l < playerData.l - groundSize.x * groundPartsForRender) continue;

			auto groundData = ckel->spline.findClosestByLength(l);

			auto normal = glm::normalize(ckel->spline.normal(groundData.t));
			auto tangent = glm::normalize(ckel->spline.tangent(groundData.t));


			glm::vec3 binormal = glm::normalize(glm::cross(normal, tangent));
			glm::vec3 adjustedNormal = glm::normalize(glm::cross(tangent, binormal));


			glm::mat3 rotationMatrix(
				binormal,
				adjustedNormal,
				tangent
			);

			glm::quat rotationQuat = glm::quat_cast(rotationMatrix);
			glm::vec3 eulerDegrees = glm::degrees(glm::eulerAngles(rotationQuat));

			//ckel->groundModel->setRotation(eulerDegrees);
			//ckel->groundModel->setPosition(groundData.value - normal * groundSize * 1.5f);
			//ckel->groundModel->setScale(groundSize);
			//ckel->groundModel->render(ckel->layer3d->shaderProgram, ckel->layer3d->camera.getViewMat(), ckel->layer3d->light.getPosition(), ckel->layer3d->light.getColor(), ckel->layer3d->camera.getPosition(), ckel->layer3d->camera.getProjectionMat());
		}
	}

	void CameraKeyframeEditorPopup::onClose(CCObject* obj) {
		currentLevelData.keyframe = ckel->keyframeBuffer;
		setLevelData(LevelEditorLayer::get(), currentLevelData);
		this->setMouseEnabled(false);
		ckel->popup = nullptr;
		ckel->lel->onStopPlaytest();
		Popup::onClose(obj);
	}

	glm::vec3 CameraKeyframeEditorPopup::getPlayerOrientedCameraFront() {
		auto playerDataStruct = ckel->spline.findClosestByLength(ckel->lel->m_player1->getPositionX() * ckel->lengthScaleFactor);
		return ckel->spline.tangent(playerDataStruct.t);
	}

	glm::vec3 CameraKeyframeEditorPopup::getPlayerOrientedCameraPosition() {
		auto playerDataStruct = ckel->spline.findClosestByLength(ckel->lel->m_player1->getPositionX() * ckel->lengthScaleFactor);
		return playerDataStruct.value + (ckel->spline.normal(playerDataStruct.t) * ckel->lengthScaleFactor * (ckel->lel->m_player1->getPositionY() - 110));
	}

	void CameraKeyframeEditorPopup::onAdd(CCObject*) {
		if (isEditing) {
			auto deltaPos = ckel->layer3d->camera.getPosition() - getPlayerOrientedCameraPosition();
			auto deltaFront = ckel->layer3d->camera.getFront() - getPlayerOrientedCameraFront();
			ckel->keyframeBuffer.setKeyframe(ckel->lel->m_player1->getPositionX(),
				deltaPos,
				deltaFront);
		}
		else {

		}
		ckel->lel->m_editorUI->onPlaytest(nullptr);
		isEditing = !isEditing;
	}
	void CameraKeyframeEditorPopup::onRemoveLast(CCObject*) {
		ckel->keyframeBuffer.removeLastKeyframe();
	}

	void CameraKeyframeEditorPopup::draw() {
		OpenGLStateHelper::saveState();


		glEnable(GL_BLEND);
		glEnable(GL_ALPHA_TEST);
		glEnable(GL_DEPTH_TEST);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		//auto playerDataStruct = ckel->spline.findClosestByLength(ckel->lel->m_player1->getPositionX() * ckel->lengthScaleFactor);

		if (!isEditing) {
			auto cameraState = ckel->keyframeBuffer.getInterpolatedCameraKeyframe(ckel->lel->m_player1->getPositionX());

			ckel->layer3d->camera.setPosition(getPlayerOrientedCameraPosition() + cameraState.offset);
			ckel->layer3d->camera.setFront(getPlayerOrientedCameraFront() + cameraState.front);
		}
		//layer3d->camera->setPosition(playerDataStruct.value + (spline->normal(playerDataStruct.t) * lengthScaleFactor * (pl->m_player1->getPositionY() - 110)) + spline->tangent(playerDataStruct.t) * -0.5f);
		//layer3d->camera->setFront(spline->tangent(playerDataStruct.t));

		renderPlayer();

		renderGround();

		//ckel->bgModel->render(ckel->layer3d->shaderProgram, ckel->layer3d->camera.getViewMat(), ckel->layer3d->light.getPosition(), ckel->layer3d->light.getColor(), ckel->layer3d->camera.getPosition(), ckel->layer3d->camera.getProjectionMat());

		CCObject* obj;
		CCARRAY_FOREACH(ckel->lel->m_objects, obj) {
			auto block = static_cast<GameObject*>(obj);

			if (abs(block->getPositionX() - ckel->lel->m_player1->getPositionX()) > 150 * 30) continue;

			auto data = ckel->spline.findClosestByLength(block->getPositionX() * ckel->lengthScaleFactor);

			auto pos = data.value;
			auto normal = glm::normalize(ckel->spline.normal(data.t));
			auto tangent = glm::normalize(ckel->spline.tangent(data.t));

			glm::vec3 side(1.f, 0.f, 0.f);
			float normalDeltaAngle = glm::radians(block->getRotation());

			glm::quat firstRotationQuat = glm::angleAxis(normalDeltaAngle, side);



			glm::vec3 binormal = glm::normalize(glm::cross(normal, tangent));
			glm::vec3 adjustedNormal = glm::normalize(glm::cross(tangent, binormal));


			glm::mat3 rotationMatrix(
				binormal,
				adjustedNormal,
				tangent
			);

			glm::quat rotationQuat = glm::quat_cast(rotationMatrix);
			glm::vec3 eulerDegrees = glm::degrees(glm::eulerAngles(rotationQuat * firstRotationQuat));

			if (auto model = BlockModelStorage::get()->getBlockModel(block->m_objectID))
			{
				model->setPosition(pos + (normal * ckel->lengthScaleFactor * (block->getPositionY() - 110)));
				model->setRotation(eulerDegrees);
				model->setScale(glm::vec3(0.5 * (block->m_startFlipX ? -1 : 1) * ckel->lengthScaleFactor * 30, 0.5 * (block->m_startFlipY ? -1 : 1) * ckel->lengthScaleFactor * 30 * block->getScaleY(), 0.5 * ckel->lengthScaleFactor * 30 * block->getScaleX()));
				BlockModelStorage::get()->tryRenderBlock(
					block->m_objectID,
					&ckel->layer3d->camera,
					&ckel->layer3d->light);
			}
		}

		glDisable(GL_DEPTH_TEST);
		glDisable(GL_BLEND);
		glDisable(GL_BLEND_COLOR);

		OpenGLStateHelper::pushState();
	}


	CameraKeyframeEditorPopup* CameraKeyframeEditorPopup::create(CameraKeyframeEditorLoader* ckel) {
		auto ret = new CameraKeyframeEditorPopup();
		auto size = CCDirector::sharedDirector()->getWinSize();
		if (ret->initAnchored(size.width, size.height, ckel)) {
			ret->autorelease();
			return ret;
		}

		delete ret;
		return nullptr;
	}
}