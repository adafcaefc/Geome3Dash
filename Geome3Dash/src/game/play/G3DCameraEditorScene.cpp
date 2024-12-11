#include "pch.h"

#include "game/play/G3DCameraEditorScene.h"
#include "game/editor/G3DCameraEditorPopup.h"
#include "manager/ModelManager.h"
#include "manager/LevelDataManager.h"

namespace g3d
{
    G3DCameraEditorScene* G3DCameraEditorScene::instance = nullptr;

    G3DCameraEditorScene::~G3DCameraEditorScene()
    {
        instance = nullptr;
    }

    void G3DCameraEditorScene::calculateJumpAndPos(float deltaTime)
    {
        // cube position

        cubePosition.x += deltaTime * 300;
        cubePosition.x = std::fmod(cubePosition.x, 1800);

        // Jumping logic

        static bool isJumping = false;
        static double jumpTime = 0.0;
        const double jumpDuration = 0.6;  // Jump duration in seconds
        const double jumpHeight = 65.0; // Height of the jump
        const double groundPositionY = 105.0; // Ground position
        static double initialRotationZ = 0.0; // Initial rotation at jump start

        // Handle jump logic
        if (!isJumping && cubePosition.x >= 840.0 && cubePosition.x < 900.0 + deltaTime * 300)
        {
            isJumping = true;
            jumpTime = 0.0; // Reset jump timer
            initialRotationZ = cubeRotationZ; // Store the initial rotation
        }

        if (isJumping)
        {
            jumpTime += deltaTime;
            double t = jumpTime / jumpDuration;
            if (t > 1.0)
            {
                t = 1.0;
                isJumping = false;
            }

            cubePosition.y = groundPositionY + jumpHeight * (1.0 - 4.0 * (t - 0.5) * (t - 0.5));
            cubeRotationZ = initialRotationZ + t * 180.0;

            if (!isJumping)
            {
                cubeRotationZ = std::round(cubeRotationZ / 90.0) * 90.0;
                cubePosition.y = groundPositionY;
            }
        }

        // render blocks

        for (float i = -900.f; i < 2400.f; i += 30.f)
        {
            auto obj = blockObjs[i];
            obj->m_positionX = i;
            obj->m_positionY = spikePosition.y - 30.f;
            obj->setPosition(ccp(obj->m_positionX, obj->m_positionY));
        }

        // render spikes

        for (int i = 0; i < spikeObjs.size(); i++)
        {
            auto obj = spikeObjs.at(i);
            obj->m_positionX = spikePosition.x + i * 30.f;
            obj->m_positionY = spikePosition.y;
            obj->setPosition(ccp(obj->m_positionX, obj->m_positionY));
        }

        playerObject->m_position = ccp(cubePosition.x, cubePosition.y);
        playerObject->setRotation(cubeRotationZ);
        playerObject->setPosition(playerObject->m_position);
    }

    void G3DCameraEditorScene::drawPlayers()
    {
        player1.render(ModelManager::get()->getBlockSP(), camera, light);
    }

    void G3DCameraEditorScene::loadBlocks()
    {
        for (int i = 0; i < 3; i++)
        {
            spikeObjs.push_back(GameObject::createWithKey(8));
            fakeGameLayer->addChild(spikeObjs.back());
            blocks.push_back(GameObjectModel(spikeObjs.back(), { &splineTr }));
        }
        for (float i = -900.f; i < 2400.f; i += 30.f)
        {
            blockObjs[i] = GameObject::createWithKey(1);
            fakeGameLayer->addChild(blockObjs[i]);
            blocks.push_back(GameObjectModel(blockObjs[i], { &splineTr }));
        }
    }

    void G3DCameraEditorScene::loadPlayers()
    {
        player1 = PlayerObjectModel(playerObject, { &splinePlayerTr, &splineCamTr });
    }

    void G3DCameraEditorScene::update(float delta)
    {
        this->calculateJumpAndPos(delta);
    }

    bool G3DCameraEditorScene::setup(LevelEditorLayer* layer)
    {
        this->levelEditorLayer = layer;
        playerObject = PlayerObject::create(0, 0, layer, layer->m_objectLayer, false);

        fakeGameLayer = CCLayer::create();
        fakeGameLayer->setScale(0.2f);
        fakeGameLayer->addChild(playerObject);
        fakeGameLayer->setVisible(false);

        this->addChild(fakeGameLayer);

        if (!AG3DGameLayer::setup(layer)) { return false; }

        this->scheduleUpdate();

        return true;
    }

    void G3DCameraEditorScene::onGLFWMouseCallBack(
        GLFWwindow* window, 
        int button, int action, int mods)
    {
        if (button == GLFW_MOUSE_BUTTON_RIGHT) 
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

    void G3DCameraEditorScene::onGLFWMouseMoveCallBack(
        GLFWwindow* window,
        double x, double y) 
    {
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
                glm::vec3 offset = glm::vec3(0.f);
                float deltaX = static_cast<float>(x) - lastMouseX;
                float deltaY = static_cast<float>(y) - lastMouseY;
                if (isPressingControl) 
                {
                    float sensitivity = 0.032f;
                    offset += camera.getUp() * deltaY * sensitivity;
                    offset += glm::normalize(glm::cross(camera.getFront(), camera.getUp())) * deltaX * -sensitivity;
                }
                else 
                {
                    float sensitivity = 0.05f;
                    levelData.yaw -= deltaX * sensitivity;
                    levelData.pitch -= deltaY * sensitivity;
                }
                lastMouseX = static_cast<float>(x);
                lastMouseY = static_cast<float>(y);
                levelData.x += offset.x;
                levelData.y += offset.y;
                levelData.z += offset.z;
                updatePopupState();
            }
        }
    }

    void G3DCameraEditorScene::updatePopupState()
    {
        if (auto layer = dynamic_cast<G3DCameraEditorPopup*>(this->getParent()->getParent()))
        {
            layer->updateState();
        }
    }

    void G3DCameraEditorScene::scrollWheel(float y, float x) 
    {
        if (isPressingControl) 
        {
            // Adjust the camera zoom level using the scroll wheel
            float zoomSensitivity = -0.128f;
            glm::vec3 offset = glm::vec3(0.f);
            offset += camera.getFront() * y * zoomSensitivity;
            levelData.x += offset.x;
            levelData.y += offset.y;
            levelData.z += offset.z;
            updatePopupState();
        }
    }

    void G3DCameraEditorScene::onKey(
        enumKeyCodes key, 
        bool pressed, bool holding) 
    {
        switch (key) {
        case KEY_Control:
            isPressingControl = pressed;
            break;
        default:
            break;
        }
    }
}