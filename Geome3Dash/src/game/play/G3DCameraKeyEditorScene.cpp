#include "pch.h"

#include "game/play/G3DCameraKeyEditorScene.h"
#include "manager/ModelManager.h"
#include "manager/LevelDataManager.h"

namespace g3d
{
    G3DCameraKeyEditorScene* G3DCameraKeyEditorScene::instance = nullptr;

	void G3DCameraKeyEditorScene::onGLFWMouseCallBack(
		GLFWwindow* window, 
		int button, int action, int mods) 
	{
		if (!isEditing) { return; }
		if (button == GLFW_MOUSE_BUTTON_LEFT) 
		{
			if (action == GLFW_PRESS)
			{
				isRightClicking = true;
				isRightClickingGetPos = false;
			}
			else if (action == GLFW_RELEASE) 
			{
				isRightClicking = false;
			}
		}
	}

	void G3DCameraKeyEditorScene::onGLFWMouseMoveCallBack(
		GLFWwindow* window, 
		double x, double y) 
	{
		if (!isEditing) { return; }
		if (isRightClicking) 
		{
			if (!isRightClickingGetPos) 
			{
				lastMouseX = static_cast<float>(x);
				lastMouseY = static_cast<float>(y);
				isRightClickingGetPos = true;
			}
			else 
			{
				float deltaX = static_cast<float>(x) - lastMouseX;
				float deltaY = static_cast<float>(y) - lastMouseY;
				if (isPressingControl) 
				{
					float sensitivity = 0.032f;

					auto front = camera.getFront();
					auto up = camera.getUp();
					auto side = glm::normalize(glm::cross(front, up));

					auto localUp = glm::normalize(glm::cross(side, front));

					camera.setPosition(
						camera.getPosition() +
						deltaY * sensitivity * localUp +
						deltaX * -sensitivity * side);
				}
				else 
				{
					float sensitivity = 0.05f;
					float yaw = camera.getYaw() - deltaX * sensitivity;
					float pitch = camera.getPitch() - deltaY * sensitivity;
					pitch = std::clamp(pitch, -89.0f, 89.0f);
					camera.setYaw(yaw);
					camera.setPitch(pitch);
				}
				lastMouseX = static_cast<float>(x);
				lastMouseY = static_cast<float>(y);
			}
		}
	}

	void G3DCameraKeyEditorScene::scrollWheel(float y, float x) 
	{
		if (!isEditing) { return; }
		float zoomSensitivity = -0.0328f;
		camera.setPosition(camera.getPosition() + camera.getFront() * y * zoomSensitivity);
	}

	void G3DCameraKeyEditorScene::onKey(
		enumKeyCodes key, 
		bool pressed, bool holding) 
	{
		switch (key) 
		{
		case KEY_A:
			if (pressed) { onAdd(nullptr); }
			break;
		case KEY_Space:
			pressed 
				? gameLayer->m_player1->pushButton(PlayerButton::Jump) 
				: gameLayer->m_player1->releaseButton(PlayerButton::Jump);
			break;
		case KEY_Control:
			isPressingControl = pressed;
			break;
		default:
			break;
		}
	}

	bool G3DCameraKeyEditorScene::setup(LevelEditorLayer* gameLayer) 
	{
		if (!G3DGameLayer::setup(gameLayer)) { return false; }
		this->levelEditorLayer = dynamic_cast<LevelEditorLayer*>(gameLayer);
		splineCamTr = PomtSplineCamera(
			&levelData.spline, 
			&levelData.keyframe, 
			&camera, &light, 
			&lengthScaleFactor, 
			&isEditing);
		return true;
	}

	G3DCameraKeyEditorScene::~G3DCameraKeyEditorScene()
	{
		instance = nullptr;
	}

	void G3DCameraKeyEditorScene::onAdd(CCObject* caller)
	{
		if (isEditing) 
		{
			auto deltaPos = camera.getPosition() - splineCamTr.getPlayerOrientedCameraPosition(&player1);
			auto deltaFront = camera.getFront() - splineCamTr.getPlayerOrientedCameraFront(&player1);
			levelData.keyframe.setKeyframe(
				gameLayer->m_player1->getPositionX(),
				deltaPos,
				deltaFront);
		}

		levelEditorLayer->m_editorUI->onPlaytest(caller);
		isEditing = !isEditing;
	}

	void G3DCameraKeyEditorScene::onRemoveLast(CCObject*) 
	{
		levelData.keyframe.removeLastKeyframe();
		if (levelData.keyframe.keyframes.empty())
		{
			setStartingKeyframe(
				&levelData,
				&levelData.keyframe,
				lengthScaleFactor);
		}
	}
}