#include "pch.h"
#include "../pch.h"

#include "G3DPlayLayer.h"

namespace g3d
{
    G3DPlayLayer* G3DPlayLayer::instance = nullptr;

    // temporary
    static std::string svgData = R"(
        <svg xmlns="http://www.w3.org/2000/svg" width="1200" height="200" style="background-color: lightgray;">
          <path d="M0,0 C2277,1521 -1558,1140 1000,0" stroke="blue" fill="none" />
        </svg>
    )";

    // temporary
    // short worm thingy
    static CubicBezier bezier = {
        98.0, 314.0,   // x0, y0: Starting point
        575.0, 335.0,  // cx1, cy1: First control point
        22.0, 192.0,   // cx2, cy2: Second control point
        511.0, 220.0   // x1, y1: End point
    };

    // wild stuff
    //CubicBezier bezier = {
    //    42, 529,   // x0, y0: Starting point
    //    245, 439,  // cx1, cy1: First control point
    //    255, 11,   // cx2, cy2: Second control point
    //    71, 549   // x1, y1: End point
    //};

    //CubicBezier bezier = {
    //    0.0, 0.0,   // x0, y0
    //    2277.0, 1521.0,   // cx1, cy1
    //    -1558.0, 1140.0,  // cx2, cy2
    //    1000.0, 0.0    // x1, y1
    //};

    //CubicBezier bezier = {
    //    87.843, 82.446,        // x0, y0
    //    1000.0, 505.226,       // cx1, cy1
    //    95.319, 372.064,       // cx2, cy2
    //    586.566, 1000.0        // x1, y1
    //};

    //// straight
    //CubicBezier bezier = {
    //    100, 300,   // x0, y0: Starting point
    //    200, 300,  // cx1, cy1: First control point
    //    300, 300,   // cx2, cy2: Second control point
    //    500, 300   // x1, y1: End point
    //};

    std::filesystem::path G3DPlayerObject::getPlayerModelPath(const std::string& type, const int id)
    {
        return geode::Mod::get()->getResourcesDir() / "model3d" / "player" / type / std::to_string(id) / "model.obj";
    }

    std::filesystem::path G3DPlayerObject::getFixedPlayerModelPath(const std::string& type, const int id)
    {
        const auto path = getPlayerModelPath(type, id);
        return std::filesystem::exists(path)
            ? path
            : getPlayerModelPath(type, 0);
    }

    void G3DPlayerObject::loadPlayerModel(Model** model, const std::string& type, const int id)
    {
        *model = ShaderScene::loadWithoutAddModel(getFixedPlayerModelPath(type, id), playLayer3D->shaderProgram);
        (*model)->setScale(glm::vec3(0.75));
    }

    void G3DPlayerObject::loadPlayerModels()
    {
        loadPlayerModel(&cube, "cube", GameManager::get()->getPlayerFrame());
        loadPlayerModel(&ship, "ship", GameManager::get()->getPlayerShip());
        loadPlayerModel(&ball, "ball", GameManager::get()->getPlayerBall());
        loadPlayerModel(&bird, "bird", GameManager::get()->getPlayerBird());
        loadPlayerModel(&dart, "dart", GameManager::get()->getPlayerDart());
        loadPlayerModel(&robot, "robot", GameManager::get()->getPlayerRobot());
        loadPlayerModel(&spider, "spider", GameManager::get()->getPlayerSpider());
        loadPlayerModel(&swing, "swing", GameManager::get()->getPlayerSwing());
        player = cube;
    }

    void G3DPlayerObject::init(G3DPlayLayer* playLayer3DP, PlayerObject* playerObjectP)
    {
        playLayer3D = playLayer3DP;
        playerObject = playerObjectP;
        loadPlayerModels();
    }

    void G3DPlayerObject::updateModel()
    {
        player = cube;
        if (playerObject->m_isShip) {
            player = ship;
        }
        else if (playerObject->m_isBall) {
            player = ball;
        }
        else if (playerObject->m_isBird) {
            player = bird;
        }
        else if (playerObject->m_isDart) {
            player = dart;
        }
        else if (playerObject->m_isRobot) {
            player = robot;
        }
        else if (playerObject->m_isSpider) {
            player = spider;
        }
        else if (playerObject->m_isSwing) {
            player = swing;
        }

        auto newX = playerObject->m_position.x * 0.05;
        auto newY = playerObject->m_position.y * 0.05;
        auto newZ = 20.f;
        auto newR = playerObject->getRotation();
        auto bCoordinate = BezierManager::transformIntoBezierCoordinate(
            bezier,
            newX, newY, newZ,
            playLayer3D->bezierSegmentCount,
            playLayer3D->bezierSegmentMultiplier);
        player->setPosition(bCoordinate.position);
        player->setRotationY(360 - bCoordinate.rotation);
        player->setRotationZ(360 - newR);
        player->setScaleY(std::abs(player->getScaleY()) * (playerObject->m_isUpsideDown ? -1.f : 1.f));
    }

    void G3DPlayerObject::drawModel()
    {
        player->render(
            playLayer3D->camera.getViewMat(),
            playLayer3D->light.getPosition(),
            playLayer3D->light.getColor(),
            playLayer3D->camera.getPosition(),
            playLayer3D->camera.getProjectionMat());
    }

    void G3DPlayLayer::loadShader()
    {
        auto vertexShader = Shader::createWithString(shaders::vertexShaderSource, ShaderType::kVertexShader);
        auto fragmentShader = Shader::createWithString(shaders::fragmentShaderSource, ShaderType::kFragmentShader);

        shaderProgram = ShaderProgram::create(vertexShader, fragmentShader);

        delete vertexShader;
        delete fragmentShader;
    }

    // mtl model path fix (model path must be absolute)
    void G3DPlayLayer::parseMtlPath(const std::filesystem::path& mtl_path)
    {
        if (std::filesystem::exists(mtl_path))
        {
            auto mtl_file = utils::read_from_file(mtl_path);
            // to do: leave the model png!!!
            if (mtl_file.find("{{MODEL_PATH}}") != std::string::npos)
            {
                utils::replace_all(mtl_file, "{{MODEL_PATH}}", mtl_path.parent_path().string());
            }
            utils::write_to_file(mtl_path, mtl_file);
        }
    }

    void G3DPlayLayer::loadObjectModels()
    {
        CCObject* obj;
        CCARRAY_FOREACH(GameManager::sharedState()->m_playLayer->m_objects, obj)
        {
            auto block = dynamic_cast<GameObject*>(obj);
            const auto model_dir = geode::Mod::get()->getResourcesDir() / "model3d" / "object" / std::to_string(block->m_objectID);
            const auto model_path = model_dir / "model.obj";
            const auto mtl_path = model_dir / "model.mtl";
            if (std::filesystem::exists(model_path))
            {
                parseMtlPath(mtl_path);
                if (blockModels.find(block->m_objectID) == blockModels.end())
                {
                    if (auto blockModel = ShaderScene::loadWithoutAddModel(model_path, shaderProgram))
                    {
                        blockModels.emplace(block->m_objectID, blockModel);
                    }
                }
                if (blockModels.find(block->m_objectID) != blockModels.end())
                {
                    blocks.emplace(block, blockModels.at(block->m_objectID));
                    // cache
                    updateBlock(block, blockModels.at(block->m_objectID));
                }
            }
        }
    }

    void G3DPlayLayer::loadPlayers()
    {
        auto playLayer = GameManager::sharedState()->m_playLayer;
        player1.init(this, playLayer->m_player1);
        //player2.init(this, playLayer->m_player2);
    }

    bool G3DPlayLayer::init()
    {
        CCNode::init();

        // clear cache of bezier segments
        BezierManager::clearCache();

        this->loadShader();
        this->loadPlayers();
        this->loadObjectModels();

        // default camera position
        playerCameraOffset = glm::vec3(-20, 5, -20);
        playerCameraYawOffset = 60.f;
        playerCameraPitchOffset = -6.f;

        //// Add some example camera actions
        //cameraActionHandler.addAction({ +1, +2, -2, +5, +3, 1.0, 200 });
        //cameraActionHandler.addAction({ +5, +3, -1, -5, -3, 2.0, 1000 });

        return true;
    }

    G3DPlayLayer::~G3DPlayLayer()
    {
        for (auto [_, block] : blockModels) { delete block; }
        instance = nullptr;
    }

    void G3DPlayLayer::updateCamera()
    {
        auto playerPos = player1.player->getPosition();
        auto newR = player1.player->getRotation();
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

    void G3DPlayLayer::updateBlock(GameObject* obj, Model* model)
    {
        auto newX = obj->m_positionX * 0.05;
        auto newY = obj->m_positionY * 0.05;
        auto newZ = 20.f;
        auto bCoordinate = BezierManager::transformIntoBezierCoordinate(
            bezier,
            newX, newY, newZ,
            bezierSegmentCount, bezierSegmentMultiplier);
        model->setPosition(bCoordinate.position);
        model->setRotationY(360 - bCoordinate.rotation);;
        model->setScale(glm::vec3(0.75 * (obj->m_startFlipX ? -1 : 1), 0.75 * (obj->m_startFlipY ? -1 : 1), 0.75));
        model->setRotationZ(360 - obj->getRotation()); // block rotation
    }

    void G3DPlayLayer::drawBlocks()
    {
        auto playLayer = GameManager::sharedState()->m_playLayer;
        for (auto [obj, model] : blocks)
        {
            if (std::abs(playLayer->m_player1->m_position.x - obj->getPositionX()) < 2000.f)
            {
                updateBlock(obj, model);

                if (obj->m_objectID == 36)
                {
                    // jump rings
                    model->setRotation(model->getRotation() + glm::vec3(3, 7, 1));
                }
                //else if (obj->m_objectID == 142)
                //{
                //    // secret coins
                //    model->setRotation(model->getRotation() + glm::vec3(0, 11, 0));
                //}
                model->render(
                    camera.getViewMat(),
                    light.getPosition(),
                    light.getColor(),
                    camera.getPosition(),
                    camera.getProjectionMat());
            }
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

    void G3DPlayLayer::updatePlayers()
    {
        player1.updateModel();
        //player2.updateModel();
    }

    void G3DPlayLayer::drawPlayers()
    {
        player1.drawModel();
        //player2.updateModel();
    }

    void G3DPlayLayer::draw()
    {
        CCNode::draw();

        auto playLayer = GameManager::sharedState()->m_playLayer;
        playLayer->m_player1->getParent()->setVisible(false);
        playLayer->m_groundLayer->setVisible(false);
        playLayer->m_groundLayer2->setVisible(false);

        updateCameraAction(playLayer->m_player1->m_position.x);
        updatePlayers();
        updateCamera();
        updateLight();

        OpenGLStateHelper::saveState();
        glEnable(GL_BLEND);
        glEnable(GL_ALPHA_TEST);
        glEnable(GL_DEPTH_TEST);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        drawPlayers();
        drawBlocks();

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
        }
    }
}