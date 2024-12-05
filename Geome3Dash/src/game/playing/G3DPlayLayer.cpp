#include "pch.h"
#include "pch.h"

#include "game/playing/G3DPlayLayer.h"
#include "LevelDataManager.h"
#include "BlockModelStorage.h"

namespace g3d
{
    G3DPlayLayer* G3DPlayLayer::instance = nullptr;

    void G3DPlayLayer::loadShader()
    {
        shaderProgram = dynamic_cast<CocosShaderProgram*>(BlockModelStorage::get()->getBlockSP());
    }

    void G3DPlayLayer::loadPlayers()
    {
        player1 = PlayerObjectModel(playLayer->m_player1, { splineTr, splineCamTr });
        player2 = PlayerObjectModel(playLayer->m_player2, { splineTr });
    }

    bool G3DPlayLayer::init()
    {
        CCNode::init();

        playLayer = GameManager::sharedState()->m_playLayer;

        // clear cache of bezier segments
        BezierManager::clearCache();

        levelData = LevelData::getDefault();

        try { levelData = getLevelData(playLayer); } catch (...) { }

        playerCameraOffset = glm::vec3(levelData.x, levelData.y, levelData.z);
        playerCameraYawOffset = levelData.yaw;
        playerCameraPitchOffset = levelData.pitch;
        //bezier = data.bezierCurve;
        //constexpr double bezierM = 1000;
        //bezier.cx1 *= bezierM;
        //bezier.cx2 *= bezierM;
        //bezier.cy1 *= bezierM;
        //bezier.cy2 *= bezierM;
        //bezier.x0 *= bezierM;
        //bezier.x1 *= bezierM;
        //bezier.y0 *= bezierM;
        //bezier.y1 *= bezierM;
        //bezierSegmentMultiplier = 1.0 / data.bezierMultiplier;

        float levelLength = 0;

        CCObject* obj;
        CCARRAY_FOREACH(playLayer->m_objects, obj) 
        {
            auto block = dynamic_cast<GameObject*>(obj);
            levelLength = std::max(block->getPositionX(), levelLength);
        }
        lengthScaleFactor = levelData.spline.length(10000) / levelLength;
        levelData.spline.updateParameterList();

        //bezierTr = new BezierGameObjectModelTransformer(bezier, bezierSegmentMultiplier, bezierSegmentCount);
        fadeTr = new FadeGameObjectModelTransformer(playLayer, 700, 400, ease::InOutSine::get(), glm::vec3(0, 0, 0));
        animTr = new AnimationGameObjectModelTransformer();
        camTr = new BezierCameraPlayerObjectModelTransformer(this);
        splineTr = new SplineGameObjectTransformer(&levelData.spline, &lengthScaleFactor);
        splineCamTr = new SplineCameraPlayerObjectModelTransformer(this);
            
        loadShader();
        loadPlayers();
        loadBlocks();

        return true;
    }

    G3DPlayLayer::~G3DPlayLayer()
    {
        instance = nullptr;
        //delete bezierTr;
        delete fadeTr;
        delete animTr;
        delete camTr;
        delete splineTr;
    }

    void G3DPlayLayer::updateCamera()
    {
        auto playerPos = player1.getPosition();
        auto newR = player1.getRotation();
        auto playerYaw = newR.y;
        auto playerYawR = -glm::radians(playerYaw);

        glm::vec3 rotatedOffset =
        {
            playerCameraOffset.x * std::cos(playerYawR) - playerCameraOffset.z * std::sin(playerYawR),
            playerCameraOffset.y,
            playerCameraOffset.x * std::sin(playerYawR) + playerCameraOffset.z * std::cos(playerYawR)
        };

        camera.setPosition(playerPos + rotatedOffset);
        // Clamp pitch to prevent flipping
        camera.setYaw(playerCameraYawOffset - playerYaw);
        auto pitch = std::clamp(static_cast<float>(playerCameraPitchOffset), -89.0f, 89.0f);
        camera.setPitch(pitch);
    }

    void G3DPlayLayer::updateLight()
    {
        light.setPosition(camera.getPosition());
    }

    void G3DPlayLayer::loadBlocks()
    {
        auto playLayer = GameManager::sharedState()->m_playLayer;
        CCObject* objxx = nullptr;
        CCARRAY_FOREACH(playLayer->m_objects, objxx)
        {
            if (auto obj = dynamic_cast<GameObject*>(objxx))
            {
                if (auto model = BlockModelStorage::get()->getBlockModel(obj->m_objectID))
                {
                    blocks.push_back(GameObjectModel(obj, { splineTr, fadeTr, animTr }));
                }
            }
        }
    }

    void G3DPlayLayer::drawBlocks()
    {
        for (auto& block : blocks) 
        { 
            auto distance = std::abs(playLayer->m_player1->m_position.x - block.getGameObject()->getPositionX());
            auto maxRender = fadeTr->getMaxRender();
            if (distance < maxRender) { block.render(shaderProgram, camera, light); }
        }
    }

    void G3DPlayLayer::updateCameraAction(const float currentXPosition)
    {
        // Calculate delta time
        auto now = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedTime = now - lastUpdate;
        lastUpdate = now;
        double deltaTime = elapsedTime.count();

        // Prepare variables for deltas
        double deltaX = 0.0, deltaY = 0.0, deltaZ = 0.0;
        double deltaYaw = 0.0, deltaPitch = 0.0;

        // Update camera action handler and get deltas
        cameraActionHandler.update(deltaTime, currentXPosition, deltaX, deltaY, deltaZ, deltaYaw, deltaPitch);

        // Apply deltas to the camera offsets
        playerCameraOffset += glm::vec3(deltaX, deltaY, deltaZ);
        playerCameraYawOffset += deltaYaw;
        playerCameraPitchOffset += deltaPitch;
    }
       
    void G3DPlayLayer::drawPlayers()
    {
        player1.render(shaderProgram, camera, light);
        player2.render(shaderProgram, camera, light);
    }

    void G3DPlayLayer::draw()
    {
        CCNode::draw();

        playLayer->m_player1->getParent()->setVisible(false);
        playLayer->m_groundLayer->setVisible(false);
        playLayer->m_groundLayer2->setVisible(false);


        OpenGLStateHelper::saveState();
        glEnable(GL_BLEND);
        glEnable(GL_ALPHA_TEST);
        glEnable(GL_DEPTH_TEST);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        drawPlayers();
        drawBlocks();

        updateCameraAction(playLayer->m_player1->m_position.x);
        updateCamera();
        updateLight();

        glDisable(GL_DEPTH_TEST);
        OpenGLStateHelper::pushState();
    }

    void G3DPlayLayer::onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) {
        if (button == GLFW_MOUSE_BUTTON_RIGHT) {
            if (action == GLFW_PRESS) {
                isRightClicking = true;
                isRightClickingGetPos = false;
            }
            else if (action == GLFW_RELEASE) {
                isRightClicking = false;
            }
        }
    }

    void G3DPlayLayer::onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) {
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
                    playerCameraOffset += camera.getUp() * deltaY * sensitivity;
                    playerCameraOffset += glm::normalize(glm::cross(camera.getFront(), camera.getUp())) * deltaX * -sensitivity;
                }
                else {
                    float sensitivity = 0.05f;
                    playerCameraYawOffset -= deltaX * sensitivity;
                    playerCameraPitchOffset -= deltaY * sensitivity;
                }
                lastMouseX = static_cast<float>(x);
                lastMouseY = static_cast<float>(y);
            }
        }
    }

    void G3DPlayLayer::scrollWheel(float y, float x) {
        // Adjust the camera zoom level using the scroll wheel
        float zoomSensitivity = -0.128f;
        playerCameraOffset += camera.getFront() * y * zoomSensitivity;
    }

    void G3DPlayLayer::onKey(enumKeyCodes key, bool pressed, bool holding) {
        switch (key) {
        case KEY_Control:
            isPressingControl = pressed;
            break;
        default:
            break;
        }
    }
}