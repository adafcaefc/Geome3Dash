#include "pch.h"

#include "G3DCurveEditorPopup.h"
#include "G3DCurveEditorLoader.h"

#include "helper/spline/Curve.h"
#include "helper/spline/Spline.h"
#include "helper/OpenGLStateHelper.h"
#include "game/component/G3DBaseNode.h"

#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Shaders.h"

#include "BlockModelStorage.h"
#include "LevelDataManager.h"

namespace g3d
{
	static LevelData currentLevelData = LevelData::getDefault();

	void G3DCurveEditorPopup::onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) {
		if (!this->isVisible()) return;
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

	void G3DCurveEditorPopup::onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) {
		if (!this->isVisible()) return;
		if (isRightClicking) {
			if (!isRightClickingGetPos) {
				lastMouseX = static_cast<float>(x);
				lastMouseY = static_cast<float>(y);
				isRightClickingGetPos = true;
			}
			else {
				float deltaX = static_cast<float>(x) - lastMouseX;
				float deltaY = static_cast<float>(y) - lastMouseY;
				if (isPressingShift) {


					auto glView = CCDirector::sharedDirector()->m_pobOpenGLView;
					int mouseX = static_cast<int>(glView->m_fMouseX);
					int mouseY = glView->getFrameSize().height - static_cast<int>(glView->m_fMouseY);

					OpenGLStateHelper::saveState();
					glEnable(GL_DEPTH_TEST);

					glBindFramebuffer(GL_FRAMEBUFFER, cel->layer3d->framebuffer);
					glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


					cel->layer3d->getObjectIDByMousePositionShader->use();

					auto renderFunction = [&](int segmentIndex, glm::vec3 position) {
						cel->pointModel->setScale(glm::vec3(0.07f));
						cel->pointModel->setPosition(position);
						glm::mat4 model = cel->pointModel->prepareModelMatrix();
						cel->layer3d->getObjectIDByMousePositionShader->setMat4("model", model);
						cel->layer3d->getObjectIDByMousePositionShader->setMat4("view", cel->layer3d->camera.getViewMat());
						cel->layer3d->getObjectIDByMousePositionShader->setMat4("projection", cel->layer3d->camera.getProjectionMat());
						glm::vec3 uniqueColor = cel->layer3d->generateUniqueColor(5, segmentIndex);
						cel->layer3d->getObjectIDByMousePositionShader->setVec3("color", uniqueColor);

						for (auto mesh : cel->pointModel->meshes)
							mesh->render(cel->layer3d->getObjectIDByMousePositionShader);
						};

					auto points = cel->spline.getAllPoints();

					for (int pointIndex = 0; pointIndex < points.size(); pointIndex++) {

						renderFunction(pointIndex, points[pointIndex]);

					}

					glFlush();
					glDisable(GL_DEPTH_TEST);

					GLubyte pixelColor[3];
					glReadPixels(mouseX, mouseY, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixelColor);

					glBindFramebuffer(GL_FRAMEBUFFER, 0);
					OpenGLStateHelper::pushState();

					auto ids = cel->layer3d->getObjectAndMeshIDFromColor(pixelColor);

					//std::cout << ids.first << " " << ids.second << std::endl;
					if (ids.second != -1) {
						selected = ids.second;
					}

					glm::vec3 newPosition = points[selected];

					glm::vec3 tangent = glm::normalize(glm::cross(cel->layer3d->camera.getUp(), cel->layer3d->camera.getFront()));
					glm::vec3 bionormal = glm::normalize(glm::cross(cel->layer3d->camera.getFront(), tangent));

					newPosition -= tangent * (deltaX * 0.01f);
					newPosition -= bionormal * (deltaY * 0.01f);

					cel->spline.editPointSymmetricCenterFix(selected, newPosition);

				}
				else if (isPressingControl) {
					float sensitivity = 0.032f;

					auto front = cel->layer3d->camera.getFront();
					auto up = cel->layer3d->camera.getUp();
					auto side = glm::normalize(glm::cross(front, up));

					auto localUp = glm::normalize(glm::cross(side, front));

					cel->layer3d->camera.setPosition(
						cel->layer3d->camera.getPosition() +
						deltaY * sensitivity * localUp +
						deltaX * -sensitivity * side);
				}
				else {
					float sensitivity = 0.05f;
					float yaw = cel->layer3d->camera.getYaw() - deltaX * sensitivity;
					float pitch = cel->layer3d->camera.getPitch() - deltaY * sensitivity;
					pitch = std::clamp(pitch, -89.0f, 89.0f);
					cel->layer3d->camera.setYaw(yaw);
					cel->layer3d->camera.setPitch(pitch);
				}
				lastMouseX = static_cast<float>(x);
				lastMouseY = static_cast<float>(y);
			}
		}
		else {
			selected = -1;
		}
	}

	void G3DCurveEditorPopup::scrollWheel(float y, float x) {
		float zoomSensitivity = -0.0328f;
		cel->layer3d->camera.setPosition(cel->layer3d->camera.getPosition() + cel->layer3d->camera.getFront() * y * zoomSensitivity);
	}

	void G3DCurveEditorPopup::onKey(enumKeyCodes key, bool pressed, bool holding) {
		switch (key) {
		case KEY_Control:
			isPressingControl = pressed;
			break;
		case KEY_Shift:
			isPressingShift = pressed;
			break;
		default:
			break;
		}
	}

	void G3DCurveEditorPopup::onClose(CCObject* obj) {
		currentLevelData.spline = cel->spline;
		setLevelData(LevelEditorLayer::get(), currentLevelData);
		this->setMouseEnabled(false);
		Popup::onClose(obj);
	}

	bool G3DCurveEditorPopup::setup(G3DCurveEditorLoader* cel) {

		currentLevelData = LevelData::getDefault();
		try {
			currentLevelData = getLevelData(LevelEditorLayer::get());
		}
		catch (...) {

		}
		cel->spline = currentLevelData.spline;
		cel->updateLevel();
		cel->spline.updateParameterList();

		// need to delete this on destructor (later)
		splineTr = new SplineGameObjectTransformer(&cel->spline, &cel->lengthScaleFactor);

		CCObject* obj;
		CCARRAY_FOREACH(cel->lel->m_objects, obj)
		{
			if (auto block = dynamic_cast<GameObject*>(obj))
			{
				if (BlockModelStorage::get()->getBlockModel(block->m_objectID))
				{
					blocks.push_back(GameObjectModel(block, { splineTr }));
				}
			}
		}

		this->setMouseEnabled(true);
		this->cel = cel;

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
		auto backBtn = CCMenuItemSpriteExtra::create(backBtnSprite, this, menu_selector(G3DCurveEditorPopup::onClose));
		backBtn->setPosition(20, size.height - 20);
		this->m_buttonMenu->addChild(backBtn);

		auto addCurveSprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
		addCurveSprite->setScale(0.7f);
		auto addCurveLabel = CCLabelBMFont::create("+", "bigFont.fnt", 80.f);
		addCurveLabel->setScale(1.2f);
		addCurveLabel->setPosition(addCurveSprite->getContentSize() / 2 - ccp(0, -4.f));
		addCurveSprite->addChild(addCurveLabel);
		auto addCurveBtn = CCMenuItemSpriteExtra::create(addCurveSprite, this, menu_selector(G3DCurveEditorPopup::onAddSegment));
		addCurveBtn->setPosition(60, size.height - 20);
		this->m_buttonMenu->addChild(addCurveBtn);

		auto removeCurveSprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
		removeCurveSprite->setScale(0.7f);
		auto removeCurveLabel = CCLabelBMFont::create("-", "bigFont.fnt", 80.f);
		removeCurveLabel->setScale(1.2f);
		removeCurveLabel->setPosition(removeCurveSprite->getContentSize() / 2 - ccp(0, -4.f));
		removeCurveSprite->addChild(removeCurveLabel);
		auto removeCurveBtn = CCMenuItemSpriteExtra::create(removeCurveSprite, this, menu_selector(G3DCurveEditorPopup::onRemoveSegment));
		removeCurveBtn->setPosition(100, size.height - 20);
		this->m_buttonMenu->addChild(removeCurveBtn);

		return true;
	}

	void G3DCurveEditorPopup::onAddSegment(CCObject*) {
		cel->addSegment();
	}

	void G3DCurveEditorPopup::onRemoveSegment(CCObject*) {
		cel->removeSegment();
	}

	void G3DCurveEditorPopup::draw() {

		if (!isRightClicking) {
			cel->spline.updateParameterList();
		}
		auto shaderProgram = BlockModelStorage::get()->getBlockSP();

		OpenGLStateHelper::saveState();
		for (auto segment : cel->spline.segments) {
			cel->pointModel->meshes[0]->setCustomKa(glm::vec3(1, 0, 0));
			cel->pointModel->setScale(glm::vec3(0.07f));
			cel->pointModel->setPosition(segment.p1);
			cel->pointModel->render(shaderProgram, cel->layer3d->camera.getViewMat(), cel->layer3d->light.getPosition(), cel->layer3d->light.getColor(), cel->layer3d->camera.getPosition(), cel->layer3d->camera.getProjectionMat());
			cel->pointModel->setPosition(segment.p2);
			cel->pointModel->render(shaderProgram, cel->layer3d->camera.getViewMat(), cel->layer3d->light.getPosition(), cel->layer3d->light.getColor(), cel->layer3d->camera.getPosition(), cel->layer3d->camera.getProjectionMat());

			cel->pointModel->meshes[0]->setCustomKa(glm::vec3(0, 1, 0));
			cel->pointModel->setScale(glm::vec3(0.05f));
			cel->pointModel->setPosition(segment.m1);
			cel->pointModel->render(shaderProgram, cel->layer3d->camera.getViewMat(), cel->layer3d->light.getPosition(), cel->layer3d->light.getColor(), cel->layer3d->camera.getPosition(), cel->layer3d->camera.getProjectionMat());
			cel->pointModel->setPosition(segment.m2);
			cel->pointModel->render(shaderProgram, cel->layer3d->camera.getViewMat(), cel->layer3d->light.getPosition(), cel->layer3d->light.getColor(), cel->layer3d->camera.getPosition(), cel->layer3d->camera.getProjectionMat());
		}


		for (float i = 0; i < 3; i += 0.005f) {
			cel->pointModel->setPosition(cel->spline.get(i));
			cel->pointModel->meshes[0]->setCustomKa(glm::vec3(0.5, 0.5, 0.5));
			cel->pointModel->setScale(glm::vec3(0.001f));
			cel->pointModel->render(shaderProgram, cel->layer3d->camera.getViewMat(), cel->layer3d->light.getPosition(), cel->layer3d->light.getColor(), cel->layer3d->camera.getPosition(), cel->layer3d->camera.getProjectionMat());
		}

		for (auto& block : blocks) { block.render(shaderProgram, cel->layer3d->camera, cel->layer3d->light); }

		OpenGLStateHelper::pushState();
	}

	G3DCurveEditorPopup* G3DCurveEditorPopup::create(G3DCurveEditorLoader* cel) {
		auto ret = new G3DCurveEditorPopup();
		auto size = CCDirector::sharedDirector()->getWinSize();
		if (ret->initAnchored(size.width, size.height, cel)) {
			ret->autorelease();
			return ret;
		}

		delete ret;
		return nullptr;
	}
}