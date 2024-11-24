#include "pch.h"
#include "../pch.h"
#include "ShaderProgram.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Model.h"
#include "OpenGLStateHelper.h"
#include "CustomKeyboard.h"
#include "CustomMouse.h"
#include "CustomTouch.h"
#include "ShaderScene.h"
#include "Ground3D.h"
#include "BezierHelper.h"

#define STRINGIFY(...) #__VA_ARGS__

namespace g3d
{
    const char* vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        layout (location = 1) in vec2 aTexCoord;
        layout (location = 2) in vec3 aNormal;

        out vec2 TexCoord;
        out vec3 Normal;
        out vec3 FragPos;

        uniform mat4 model;
        uniform mat4 view;
        uniform mat4 projection;

        void main() {
            FragPos = vec3(model * vec4(aPos, 1.0));
            Normal = mat3(transpose(inverse(model))) * aNormal;
            TexCoord = aTexCoord;
            gl_Position = projection * view * model * vec4(aPos, 1.0);
        }
    )";

    const char* fragmentShaderSource = R"(
        #version 330 core

        in vec2 TexCoord;
        in vec3 Normal;
        in vec3 FragPos;

        uniform sampler2D texture1;
        uniform int isTexture;
        uniform vec3 Ka; // Ambient reflectivity
        uniform vec3 Kd; // Diffuse reflectivity
        uniform vec3 Ks; // Specular reflectivity
        uniform vec3 lightColor; // Light color
        uniform vec3 lightPos; // Light position
        uniform vec3 viewPos; // View position
        uniform float shininess; // Shininess factor

        out vec4 FragColor;

        void main() {
            // Ambient
            vec3 ambient = lightColor * Ka;
    
            // Diffuse
            vec3 norm = normalize(Normal);
            vec3 lightDir = normalize(lightPos - FragPos);
            float diff = max(dot(norm, lightDir), 0.0);
            vec3 diffuse = diff * lightColor * Kd;

            // Specular
            vec3 viewDir = normalize(viewPos - FragPos);
            vec3 reflectDir = reflect(-lightDir, norm);
            float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
            vec3 specular = spec * lightColor * Ks;
    
            vec3 result = ambient + diffuse + specular;
    
            vec4 color;
            if (isTexture == 1) {
                vec4 texColor = texture(texture1, TexCoord);
                color = texColor * vec4(result, 1.0);
            } else {
                color = vec4(result, 1.0);
            }
    
            FragColor = color;
        }
    )";

    // temporary
    std::string svgData = R"(
        <svg xmlns="http://www.w3.org/2000/svg" width="1200" height="200" style="background-color: lightgray;">
          <path d="M0,0 C2277,1521 -1558,1140 1000,0" stroke="blue" fill="none" />
        </svg>
    )";

    CubicBezier bezier = {
        0.0, 0.0,   // x0, y0
        2277.0, 1521.0,   // cx1, cy1
        -1558.0, 1140.0,  // cx2, cy2
        1000.0, 0.0    // x1, y1
    };

    //CubicBezier bezier = {
    //    87.843, 82.446,        // x0, y0
    //    1000.0, 505.226,       // cx1, cy1
    //    95.319, 372.064,       // cx2, cy2
    //    586.566, 1000.0        // x1, y1
    //};


    std::string read_from_file(
        const std::filesystem::path& path)
    {
        if (!std::filesystem::exists(path)) { return std::string(); }
        std::ifstream input(path);
        if (!input.is_open()) { return std::string(); }
        std::stringstream buffer;
        buffer << input.rdbuf();
        input.close();
        return buffer.str();
    }

    bool write_to_file(
        const std::filesystem::path& path,
        const std::string& data)
    {
        std::ofstream output(path);
        if (!output.is_open()) { return false; }
        output << data;
        return true;
    }

    void replace_all(
        std::string& str,
        const std::string& from,
        const std::string& to)
    {
        if (from.empty()) { return; }
        size_t start_pos = 0;
        while ((start_pos = str.find(from, start_pos)) != std::string::npos)
        {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
        }
    }

    double getLevelProgress(double x, GJBaseGameLayer* level)
    {
        if (level->m_levelLength == 0 || x == 0) { return 0; }
        return static_cast<double>(x) / static_cast<double>(level->m_levelLength);
    }

    struct BezierCoordinate
    {
        glm::vec3 position;
        double rotation;
    };

    BezierCoordinate transformIntoBezierCoordinate(const CubicBezier& segment, double t, double x, double y, double z)
    {
        t = std::clamp(t, 0.0001, 0.9999);

        // First, we need to evaluate the Bezier curve for X and Z axis
        double bezierX = 0.0, bezierZ = 0.0, rotationY = 0.0;

        // Evaluate the Bezier curve for X-axis using the segment's start and end points, and control points
        evaluateCubicBezier(t, segment.x0, segment.y0, segment.cx1, segment.cy1, segment.cx2, segment.cy2, segment.x1, segment.y1,
            bezierX, bezierZ, rotationY);

        // Return the transformed coordinates as a glm::vec3, with the original Y and Z coordinates being transformed along the curve
        return { glm::vec3(bezierX / 4.0, y, bezierZ / 4.0), glm::degrees(rotationY) };  // Since y is not involved in the Bezier curve transformation, it remains unchanged
    }

    class PlayerObject3D
    {
    private:
        Model* cube;
        Model* ship;
        Model* ball;
        Model* bird;
        Model* dart;
        Model* robot;
        Model* spider;
        Model* swing;

        Camera* camera;
        Light* light;

        g3d::ShaderProgram* shaderProgram;

        std::filesystem::path getPlayerModelPath(const std::string& type, const int id)
        {
            return geode::Mod::get()->getResourcesDir() / "model3d" / "player" / type / std::to_string(id) / "model.obj";
        }

        std::filesystem::path getFixedPlayerModelPath(const std::string& type, const int id)
        {
            const auto path = getPlayerModelPath(type, id);
            return std::filesystem::exists(path)
                ? path
                : getPlayerModelPath(type, 0);
        }

        void loadPlayerModel(Model** model, const std::string& type, const int id)
        {
            *model = ShaderScene::loadWithoutAddModel(getFixedPlayerModelPath(type, id), shaderProgram);
            (*model)->setScale(glm::vec3(0.75));
        }

        void loadPlayerModels()
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

    public:
        PlayerObject* playerObject;
        Model* player;

        PlayerObject3D() {}

        PlayerObject3D(
            g3d::ShaderProgram* shaderProgramP, 
            PlayerObject* playerObjectP, 
            Camera* cameraP, 
            Light* lightP)
            : shaderProgram(shaderProgramP)
            , playerObject(playerObjectP)
            , camera(cameraP)
            , light(lightP)
        {

        }

        void init(
            g3d::ShaderProgram* shaderProgramP,
            PlayerObject* playerObjectP,
            Camera* cameraP, 
            Light* lightP)
        {
            shaderProgram = shaderProgramP;
            playerObject = playerObjectP;
            camera = cameraP;
            light = lightP;
            loadPlayerModels();
        }

        void updateModel()
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

            //auto bezierSegment = parseSVGPath(svgData)[0];
            auto progress = getLevelProgress(playerObject->m_position.x, playerObject->m_gameLayer);
            auto newX = playerObject->getPositionX() * 0.05;
            auto newY = playerObject->getPositionY() * 0.05;
            auto newZ = 20.f;
            auto newR = playerObject->getRotation();
            //player->setPosition(glm::vec3(newX, newY, newZ));
            auto bCoordinate = transformIntoBezierCoordinate(bezier, progress, newX, newY, newZ);
            player->setPosition(bCoordinate.position);
            player->setRotationY(360 - bCoordinate.rotation);
            player->setScaleY(std::abs(player->getScaleY()) * (playerObject->m_isUpsideDown ? -1.f : 1.f));
        }

        void drawModel()
        {
            player->render(
                camera->getViewMat(),
                light->getPosition(),
                light->getColor(),
                camera->getPosition(),
                camera->getProjectionMat());
        }
    };

    class PlayLayer3D
        : public CCNode
        , public CustomKeyboardDelegate
        , public CustomTouchDelegate
        , public CustomMouseDelegate
    {
        Model* bg;

        PlayerObject3D player1;
        //PlayerObject3D* player2; // not yet implemented!

        //Ground3D* ground;
        //Ground3D* ground2;

        std::unordered_map<GameObject*, Model*> blocks;
        glm::vec3 playerCameraOffset;
        double playerCameraYawOffset;
        double playerCameraPitchOffset;
        g3d::ShaderProgram* shaderProgram;

        Camera camera;
        Light light;

    public:
        static PlayLayer3D* instance;
        
        //void updateGrounds() 
        //{
        //    ground->updateGround();
        //    ground2->updateGround();
        //}

        //void resetGrounds() 
        //{
        //    ground->resetGround();
        //    ground2->resetGround();
        //}

        void loadShader()
        {
            auto vertexShader = Shader::createWithString(vertexShaderSource, ShaderType::kVertexShader);
            auto fragmentShader = Shader::createWithString(fragmentShaderSource, ShaderType::kFragmentShader);

            shaderProgram = ShaderProgram::create(vertexShader, fragmentShader);

            delete vertexShader;
            delete fragmentShader;
        }

        void loadObjectModels()
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
                    // mtl model path fix (model path must be absolute
                    if (std::filesystem::exists(mtl_path)) 
                    {
                        auto mtl_file = read_from_file(mtl_path);
                        // to do: leave the model png!!!
                        if (mtl_file.find("{{MODEL_PATH}}") != std::string::npos) 
                        {
                            replace_all(mtl_file, "{{MODEL_PATH}}", model_dir.string());
                        }
                        write_to_file(mtl_path, mtl_file);
                    }
                    if (auto blockModel = ShaderScene::loadWithoutAddModel(model_path, shaderProgram)) 
                    {
                        auto newX = block->getPositionX() * 0.05;
                        auto newY = block->getPositionY() * 0.05;
                        auto newZ = 20.f;
                        auto bCoordinate = transformIntoBezierCoordinate(
                            bezier,
                            getLevelProgress(block->getPositionX(), GameManager::sharedState()->m_playLayer),
                            newX, newY, newZ);
                        blockModel->setPosition(bCoordinate.position);
                        blockModel->setRotationY(360 - bCoordinate.rotation);
                        //blockModel->setPosition(glm::vec3(block->getPositionX() * 0.05, block->getPositionY() * 0.05, 20.f));
                        geode::log::info("Loading block ID {} ({}, {})", block->m_objectID, block->m_startFlipX, block->m_scaleX);
                        blockModel->setScale(glm::vec3(0.75 * (block->m_startFlipX ? -1 : 1), 0.75 * (block->m_startFlipY ? -1 : 1), 0.75));
                        //blockModel->setRotationZ(360 - block->getRotation());
                        blocks.emplace(block, blockModel);
                    }
                }
            }
        }

        bool init() 
        {
            CCNode::init();

            this->loadShader();

            // temporarily disabled by adaf
            //bg = loadAndAddModel("./cliff.obj", shaderProgram);
            //bg->setPosition(glm::vec3(300, -100, -300));
            //bg->setScale(glm::vec3(3, 3, 3));

            auto playLayer = GameManager::sharedState()->m_playLayer;

            this->loadObjectModels();
            player1.init(shaderProgram, playLayer->m_player1, &this->camera, &this->light);

            //ground = Ground3D::create(this, shaderProgram, -200, 3, 50, playLayer->m_groundLayer->getPositionY() + playLayer->m_groundLayer->getContentSize().height - 3 * 2, 0);
            //ground2 = Ground3D::create(this, shaderProgram, -200, 3, 50, playLayer->m_groundLayer2->getPositionY() + playLayer->m_groundLayer2->getContentSize().height, 1);

            playerCameraOffset = glm::vec3(-20, 5, -20);
            playerCameraYawOffset = 30.f;
            playerCameraPitchOffset = -6.f;

            return true;
        }
        ~PlayLayer3D() 
        {
            // delete player here too?
            for (auto [_, block] : blocks) { delete block; }
            instance = nullptr;
        }

        void updateCamera()
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

        void updateLight()
        {
            auto playLayer = GameManager::sharedState()->m_playLayer;
            auto playerPos = player1.player->getPosition();
            auto groundHeight = (playLayer->m_groundLayer->getPositionY() + playLayer->m_groundLayer->getContentSize().height) * 0.05;
            light.setPosition(glm::vec3(playerPos.x + 50, groundHeight + 50, playerPos.z + 50));
        }

        virtual void draw() 
        {
            CCNode::draw();

            auto playLayer = GameManager::sharedState()->m_playLayer;
            if (playLayer->m_player1->m_position.x <= 0.f) { return; }

            //ground2->setVisible(GameManager::sharedState()->m_playLayer->m_player1.m_isShip);
            // rainix, what value is this?
            //ground2->updateYPos(MBO(float, GameManager::sharedState()->m_playLayer, 0x2A0));
            //if (GameManager::sharedState()->m_playLayer->m_player1.m_isShip)
            //    ground->updateYPos(MBO(float, GameManager::sharedState()->m_playLayer, 0x2A0) - 300);
            //else
            //    ground->updateYPos(-60);

            //ground->updateYPos(playLayer->m_groundLayer->getPositionY() + playLayer->m_groundLayer->getContentSize().height - 75.0f);
            //ground2->updateYPos(playLayer->m_groundLayer2->getPositionY() + playLayer->m_groundLayer2->getContentSize().height + 75.0f);
            //ground->setVisible(playLayer->m_groundLayer->isVisible());
            //ground2->setVisible(playLayer->m_groundLayer2->isVisible());

            playLayer->m_player1->getParent()->setVisible(false);
            // ground calculations is so hard -adaf
            playLayer->m_groundLayer->setVisible(false);
            playLayer->m_groundLayer2->setVisible(false);
            //ground->updateYPos(playLayer->m_groundLayer->getPositionY());
            //ground2->updateYPos(playLayer->m_groundLayer2->getPositionY());

            //updateGrounds();

            player1.updateModel();
            updateCamera();
            updateLight();

            OpenGLStateHelper::saveState();
            glEnable(GL_BLEND);
            glEnable(GL_ALPHA_TEST);
            glEnable(GL_DEPTH_TEST);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            player1.drawModel();

            for (auto [obj, model] : blocks)
            {
                if (std::abs(playLayer->m_player1->m_position.x - obj->getPositionX()) < 2000.f)
                {
                    model->render(
                        camera.getViewMat(),
                        light.getPosition(),
                        light.getColor(),
                        camera.getPosition(),
                        camera.getProjectionMat());
                }
            }

            glDisable(GL_DEPTH_TEST);
            OpenGLStateHelper::pushState();

            //auto newX = player1.player->getPositionX();
            //auto newY = player1.player->getPositionY();
            //auto newZ = player1.player->getPositionZ();
            //auto newR = player1.playerObject->getRotation();
            //camera.setPosition(glm::vec3(newX + playerCameraOffset.x, newY + playerCameraOffset.y, newZ + playerCameraOffset.z));

            //// Clamp pitch to prevent flipping
            //camera.setYaw(playerCameraYawOffset + player1.player->getRotationY());
            //auto pitch = std::clamp(static_cast<float>(playerCameraPitchOffset), -89.0f, 89.0f);
            //camera.setPitch(pitch);



    
        }

        bool isPressingControl = false;
        bool isRightClicking = false;
        bool isRightClickingGetPos = false;
        float lastMouseX = 0.0;
        float lastMouseY = 0.0;

        virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) {
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

        virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) {
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

        virtual void scrollWheel(float y, float x) {
            // Adjust the camera zoom level using the scroll wheel
            float zoomSensitivity = -0.128f;
            playerCameraOffset += camera.getFront() * y * zoomSensitivity;
        }

        virtual void onKey(enumKeyCodes key, bool pressed, bool holding) {
            switch (key) {
            case KEY_Control:
                isPressingControl = pressed;
                break;
            }
        }

    public:
        static auto create() {
            auto node = new PlayLayer3D;
            instance = node;
            if (node->init()) {
                node->autorelease();
            }
            else {
                CC_SAFE_DELETE(node);
            }
            return node;
        }
    };

    PlayLayer3D* PlayLayer3D::instance = nullptr;

    class $modify(PlayLayer)
    {
        void resetLevel()
        {
            PlayLayer::resetLevel();
            //if (PlayLayer3D::instance) { PlayLayer3D::instance->resetGrounds(); }
        }

        bool init(GJGameLevel * level, bool useReplay, bool dontCreateObjects)
        {
            if (!PlayLayer::init(level, useReplay, dontCreateObjects)) { return false; }

            PlayLayer3D* node = PlayLayer3D::create();

            if (node == nullptr) { return true; }

            node->setZOrder(10);
            this->addChild(node);

            return true;
        }
    };

    class $modify(CCKeyboardDispatcher)
    {
        bool dispatchKeyboardMSG(enumKeyCodes key, bool isKeyDown, bool isKeyRepeat)
        {
            CustomKeyboardManager::updateDelegates(key, isKeyDown, isKeyRepeat);
            return CCKeyboardDispatcher::dispatchKeyboardMSG(key, isKeyDown, isKeyRepeat);
        }
    };

    class $modify(CCMouseDispatcher)
    {
        bool dispatchScrollMSG(float x, float y)
        {
            CustomMouseManager::updateDelegates(x, y);
            return CCMouseDispatcher::dispatchScrollMSG(x, y);
        }
    };

    class $modify(CCEGLView)
    {
        void onGLFWMouseMoveCallBack(GLFWwindow * window, double x, double y)
        {
            CustomTouchManager::onGLFWMouseMoveCallBack(window, x, y);
            CCEGLView::onGLFWMouseMoveCallBack(window, x, y);
        }

        void onGLFWMouseCallBack(GLFWwindow * window, int button, int action, int mods)
        {
            CustomTouchManager::onGLFWMouseCallBack(window, button, action, mods);
            CCEGLView::onGLFWMouseCallBack(window, button, action, mods);
        }
    };

    class $modify(CCTouchDispatcher)
    {
        void touches(CCSet* touches, CCEvent* event, unsigned int type)
        {
            CustomTouchManager::updateDelegates(touches, event, type);
            CCTouchDispatcher::touches(touches, event, type);
        }
    };

    void HookAll()
    {
        auto mod = geode::Mod::get();
        for (auto& hook : mod->getHooks()) { hook->enable(); }
    }
}