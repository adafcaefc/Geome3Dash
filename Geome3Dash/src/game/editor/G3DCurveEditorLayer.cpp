#include "pch.h"

#include "G3DCurveEditorLayer.h"

#include "helper/spline/Curve.h"
#include "helper/spline/Spline.h"
#include "helper/OpenGLStateHelper.h"
#include "game/component/G3DBaseNode.h"

#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Shaders.h"

#include "BlockModelsStorage.h"

namespace g3d
{
	void G3DCurveEditorLayer::onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) {
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

	void G3DCurveEditorLayer::onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) {
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

					glBindFramebuffer(GL_FRAMEBUFFER, layer3d->framebuffer);
					glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


					layer3d->getObjectIDByMousePositionShader->use();

					auto renderFunction = [&](int segmentIndex, glm::vec3 position) {
						pointModel->setScale(glm::vec3(0.07));
						pointModel->setPosition(position);
						glm::mat4 model = pointModel->prepareModelMatrix();
						layer3d->getObjectIDByMousePositionShader->setMat4("model", model);
						layer3d->getObjectIDByMousePositionShader->setMat4("view", layer3d->camera.getViewMat());
						layer3d->getObjectIDByMousePositionShader->setMat4("projection", layer3d->camera.getProjectionMat());
						glm::vec3 uniqueColor = layer3d->generateUniqueColor(5, segmentIndex);
						layer3d->getObjectIDByMousePositionShader->setVec3("color", uniqueColor);

						for (auto mesh : pointModel->meshes)
							mesh->render(layer3d->getObjectIDByMousePositionShader);
						};

					auto points = spline->getAllPoints();

					for (int pointIndex = 0; pointIndex < points.size(); pointIndex++) {

						renderFunction(pointIndex, points[pointIndex]);

					}

					glFlush();
					glDisable(GL_DEPTH_TEST);

					GLubyte pixelColor[3];
					glReadPixels(mouseX, mouseY, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixelColor);

					glBindFramebuffer(GL_FRAMEBUFFER, 0);
					OpenGLStateHelper::pushState();

					auto ids = layer3d->getObjectAndMeshIDFromColor(pixelColor);
					if (ids.second != -1) { selected = ids.second; }

					std::cout << fmt::format("({}, {})", ids.first, ids.second) << '\n';

					glm::vec3 newPosition = points[selected];
					
					glm::vec3 tangent = glm::normalize(glm::cross(layer3d->camera.getUp(), layer3d->camera.getFront()));
					glm::vec3 bionormal = glm::normalize(glm::cross(layer3d->camera.getFront(), tangent));

					newPosition -= tangent * (deltaX * 0.01f);
					newPosition -= bionormal * (deltaY * 0.01f);

					spline->editPointSymmetricCenterFix(selected, newPosition);

				}
				else if (isPressingControl) {
					float sensitivity = 0.032f;
					layer3d->camera.setPosition(layer3d->camera.getPosition() + layer3d->camera.getUp() * deltaY * sensitivity);
					layer3d->camera.setPosition(layer3d->camera.getPosition() + glm::normalize(glm::cross(layer3d->camera.getFront(), layer3d->camera.getUp())) * deltaX * -sensitivity);
				}
				else {
					float sensitivity = 0.05f;
					float yaw = layer3d->camera.getYaw() - deltaX * sensitivity;
					float pitch = layer3d->camera.getPitch() - deltaY * sensitivity;
					pitch = std::clamp(pitch, -89.0f, 89.0f);
					layer3d->camera.setYaw(yaw);
					layer3d->camera.setPitch(pitch);
				}
				lastMouseX = static_cast<float>(x);
				lastMouseY = static_cast<float>(y);
			}
		}
		else {
			selected = -1;
		}
	}

	void G3DCurveEditorLayer::updateLevel() {
		levelLength = 0;
		CCObject* obj;
		CCARRAY_FOREACH(lel->m_objects, obj) {
			auto block = static_cast<GameObject*>(obj);

			levelLength = std::max(block->getPositionX(), levelLength);
		}
	}

	bool G3DCurveEditorLayer::init(LevelEditorLayer* lel) {
		if (!CCLayer::init()) return false;
		this->setVisible(false);

		this->setTouchEnabled(true);
		this->setTouchPriority(-600);
		//CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 50, true);
		geode::cocos::handleTouchPriority(this, true);
		this->setZOrder(101);

		this->lel = lel;

		spline = new Spline();
		spline->addSegment(new Curve(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(2.0f, 0.0f, 0.0f), glm::vec3(3.0f, 0.0f, 0.0f)));

		auto size = CCDirector::sharedDirector()->getWinSize();

		bg = CCSprite::create("GJ_gradientBG.png");
		bg->setScaleX(size.width / bg->getContentSize().width);
		bg->setScaleY(size.height / bg->getContentSize().height);
		bg->setColor({ 0, 75, 110 });
		bg->setZOrder(-5);
		bg->setPosition(size / 2);
		this->addChild(bg);

		auto uiMenu = CCMenu::create();
		uiMenu->setPosition(0, 0);
		this->addChild(uiMenu);
		auto backBtnSprite = CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png");
		backBtnSprite->setScale(0.7);
		auto backBtn = CCMenuItemSpriteExtra::create(backBtnSprite, this, menu_selector(G3DCurveEditorLayer::hide));
		backBtn->setPosition(20, size.height - 20);
		uiMenu->addChild(backBtn);

		auto addCurveSprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
		addCurveSprite->setScale(0.7);
		auto addCurveLabel = CCLabelBMFont::create("+", "bigFont.fnt", 80.f);
		addCurveLabel->setScale(1.2);
		addCurveLabel->setPosition(addCurveSprite->getContentSize() / 2 - ccp(0, -4.f));
		addCurveSprite->addChild(addCurveLabel);
		auto addCurveBtn = CCMenuItemSpriteExtra::create(addCurveSprite, this, menu_selector(G3DCurveEditorLayer::onAddSegment));
		addCurveBtn->setPosition(60, size.height - 20);
		uiMenu->addChild(addCurveBtn);

		auto removeCurveSprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
		removeCurveSprite->setScale(0.7);
		auto removeCurveLabel = CCLabelBMFont::create("-", "bigFont.fnt", 80.f);
		removeCurveLabel->setScale(1.2);
		removeCurveLabel->setPosition(removeCurveSprite->getContentSize() / 2 - ccp(0, -4.f));
		removeCurveSprite->addChild(removeCurveLabel);
		auto removeCurveBtn = CCMenuItemSpriteExtra::create(removeCurveSprite, this, menu_selector(G3DCurveEditorLayer::onRemoveSegment));
		removeCurveBtn->setPosition(100, size.height - 20);
		uiMenu->addChild(removeCurveBtn);

		layer3d = G3DBaseNode::create();
		layer3d->camera.setPosition(glm::vec3(0, 0, 15));
		layer3d->light.setPosition(glm::vec3(0, 50, 1000));
		layer3d->setZOrder(10);

		setKeyboardEnabled(true);

		auto bms = BlockModelsStorage::getInstance();
		pointModel = bms->getModel(bms->getBP() / "editor" / "model" / "point.obj");
		pointModel->setScale(glm::vec3(0.2f));
		layer3d->models.push_back(pointModel);

		this->addChild(layer3d);

		return true;
	}



	void G3DCurveEditorLayer::onAddSegment(CCObject*) 
	{
		auto p1 = spline->segments.back()->p2;
		auto m1 = spline->segments.back()->p2 * 2.f - spline->segments.back()->m2;
		auto m2 = spline->segments.back()->p2 * 2.f - spline->segments.back()->m1;
		auto p2 = spline->segments.back()->p2 * 2.f - spline->segments.back()->p1;

		spline->addSegment(new Curve(p1, m1, m2, p2));
	}


	void G3DCurveEditorLayer::onRemoveSegment(CCObject*) {
		if (spline->segments.size() > 1)
			spline->removeLastSegment();
	}

	void G3DCurveEditorLayer::draw() {
		if (!this->isVisible()) return;

		if (!isRightClicking) {
			spline->updateParameterList();
		}

		auto shader = layer3d->shaderProgram;

		OpenGLStateHelper::saveState();
		for (auto segment : spline->segments) {
			pointModel->meshes[0]->setCustomKa(glm::vec3(1, 0, 0));
			pointModel->setScale(glm::vec3(0.07));
			pointModel->setPosition(segment->p1);
			pointModel->render(shader, layer3d->camera.getViewMat(), layer3d->light.getPosition(), layer3d->light.getColor(), layer3d->camera.getPosition(), layer3d->camera.getProjectionMat());
			pointModel->setPosition(segment->p2);
			pointModel->render(shader, layer3d->camera.getViewMat(), layer3d->light.getPosition(), layer3d->light.getColor(), layer3d->camera.getPosition(), layer3d->camera.getProjectionMat());

			pointModel->meshes[0]->setCustomKa(glm::vec3(0, 1, 0));
			pointModel->setScale(glm::vec3(0.05));
			pointModel->setPosition(segment->m1);
			pointModel->render(shader, layer3d->camera.getViewMat(), layer3d->light.getPosition(), layer3d->light.getColor(), layer3d->camera.getPosition(), layer3d->camera.getProjectionMat());
			pointModel->setPosition(segment->m2);
			pointModel->render(shader, layer3d->camera.getViewMat(), layer3d->light.getPosition(), layer3d->light.getColor(), layer3d->camera.getPosition(), layer3d->camera.getProjectionMat());
		}


		for (float i = 0; i < 3; i += 0.005) {
			pointModel->setPosition(spline->get(i));
			pointModel->meshes[0]->setCustomKa(glm::vec3(0.5, 0.5, 0.5));
			pointModel->setScale(glm::vec3(0.001));
			pointModel->render(shader, layer3d->camera.getViewMat(), layer3d->light.getPosition(), layer3d->light.getColor(), layer3d->camera.getPosition(), layer3d->camera.getProjectionMat());
		}

		float lengthScaleFactor = spline->length(10000) / levelLength;


		CCObject* obj;
		CCARRAY_FOREACH(lel->m_objects, obj) {
			auto block = static_cast<GameObject*>(obj);

			auto data = spline->findClosestByLength(block->getPositionX() * lengthScaleFactor);

			auto pos = data.value;
			auto normal = glm::normalize(spline->normal(data.t));
			auto tangent = glm::normalize(spline->tangent(data.t));

			glm::vec3 side(1.f, 0.f, 0.f);
			float normalDeltaAngle = glm::radians(block->getRotation());

			glm::quat firstRotationQuat = glm::angleAxis(normalDeltaAngle, side);

			glm::vec3 binormal = glm::normalize(glm::cross(normal, tangent));
			glm::vec3 adjustedNormal = glm::normalize(glm::cross(tangent, binormal));

			glm::mat3 rotationMatrix(
				binormal,
				adjustedNormal,
				tangent);

			glm::quat rotationQuat = glm::quat_cast(rotationMatrix);
			glm::vec3 eulerDegrees = glm::degrees(glm::eulerAngles(rotationQuat * firstRotationQuat));

			auto bms = BlockModelsStorage::getInstance();
			if (auto blockModel = bms->getBlockModel(block->m_objectID))
			{
				blockModel->setPosition(pos + (normal * lengthScaleFactor * (block->getPositionY() - 110)));
				blockModel->setRotation(eulerDegrees);
				blockModel->setScale(glm::vec3(0.5 * (block->m_startFlipX ? -1 : 1) * lengthScaleFactor * 30, 0.5 * (block->m_startFlipY ? -1 : 1) * lengthScaleFactor * 30 * block->getScaleY(), 0.5 * lengthScaleFactor * 30 * block->getScaleX()));
				blockModel->render(
					layer3d->shaderProgram, 
					layer3d->camera.getViewMat(),
					layer3d->light.getPosition(),
					layer3d->light.getColor(),
					layer3d->camera.getPosition(),
					layer3d->camera.getProjectionMat());
			}
		}

		OpenGLStateHelper::pushState();
	}

	void G3DCurveEditorLayer::scrollWheel(float y, float x) {
		float zoomSensitivity = -0.0328f;
		layer3d->camera.setPosition(layer3d->camera.getPosition() + layer3d->camera.getFront() * y * zoomSensitivity);
	}

	void G3DCurveEditorLayer::onKey(enumKeyCodes key, bool pressed, bool holding) {
		switch (key) {
		case KEY_Control:
			isPressingControl = pressed;
			break;
		case KEY_Shift:
			isPressingShift = pressed;
			break;
		}
	}

	G3DCurveEditorLayer* G3DCurveEditorLayer::create(LevelEditorLayer* lel) {
		auto ret = new G3DCurveEditorLayer();
		if (ret && ret->init(lel)) {
			ret->autorelease();
			return ret;
		}
		delete ret;
		return nullptr;
	}
}