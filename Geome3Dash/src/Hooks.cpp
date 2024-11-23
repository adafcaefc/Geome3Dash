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

    class GJ3DGameLayer
        : public ShaderScene
        , public CustomKeyboardDelegate
        , public CustomTouchDelegate
        , public CustomMouseDelegate
    {
        Model* bg;
        Model* cube;
        Model* ship;
        Model* ball;
        Model* bird;
        Model* dart;
        Model* robot;
        Model* spider;
        Model* swing;
        Ground3D* ground;
        Ground3D* ground2;
        std::vector<Model*> blocks;
        glm::vec3 playerCameraOffset;
        g3d::ShaderProgram* shaderProgram;

    public:
        static GJ3DGameLayer* instance;

        auto getResDir()
        {
            return geode::Mod::get()->getResourcesDir();
        }
        
        void updateGrounds() 
        {
            ground->updateGround();
            ground2->updateGround();
        }

        void resetGrounds() 
        {
            ground->resetGround();
            ground2->resetGround();
        }

        void loadShader()
        {
            auto vertexShader = Shader::createWithString(vertexShaderSource, ShaderType::kVertexShader);
            auto fragmentShader = Shader::createWithString(fragmentShaderSource, ShaderType::kFragmentShader);

            shaderProgram = ShaderProgram::create(vertexShader, fragmentShader);

            delete vertexShader;
            delete fragmentShader;
        }

        void loadPlayerModels()
        {
            // to do : icon selection (default 0)
            cube = loadWithoutAddModel(getResDir() / "model3d" / "player" / "cube" / "0" / "model.obj", shaderProgram);
            cube->setScale(glm::vec3(0.75));

            ship = loadWithoutAddModel(getResDir() / "model3d" / "player" / "ship" / "0" / "model.obj", shaderProgram);
            ship->setScale(glm::vec3(0.75));

            ball = loadWithoutAddModel(getResDir() / "model3d" / "player" / "ball" / "0" / "model.obj", shaderProgram);
            ball->setScale(glm::vec3(0.75));

            bird = loadWithoutAddModel(getResDir() / "model3d" / "player" / "bird" / "0" / "model.obj", shaderProgram);
            bird->setScale(glm::vec3(0.75));

            dart = loadWithoutAddModel(getResDir() / "model3d" / "player" / "dart" / "0" / "model.obj", shaderProgram);
            dart->setScale(glm::vec3(0.75));

            robot = loadWithoutAddModel(getResDir() / "model3d" / "player" / "robot" / "0" / "model.obj", shaderProgram);
            robot->setScale(glm::vec3(0.75));

            spider = loadWithoutAddModel(getResDir() / "model3d" / "player" / "spider" / "0" / "model.obj", shaderProgram);
            spider->setScale(glm::vec3(0.75));

            swing = loadWithoutAddModel(getResDir() / "model3d" / "player" / "swing" / "0" / "model.obj", shaderProgram);
            swing->setScale(glm::vec3(0.75));
        }

        void loadObjectModels()
        {
            CCObject* obj;
            CCARRAY_FOREACH(GameManager::sharedState()->m_playLayer->m_objects, obj) 
            {
                auto block = dynamic_cast<GameObject*>(obj);
                const auto model_dir = getResDir() / "model3d" / "object" / std::to_string(block->m_objectID);
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
                    if (auto blockModel = loadWithoutAddModel(model_path, shaderProgram)) 
                    {
                        blockModel->setPosition(glm::vec3(block->getPositionX() * 0.05, block->getPositionY() * 0.05, 20.f));
                        geode::log::info("Loading block ID {} ({}, {})", block->m_objectID, block->m_startFlipX, block->m_scaleX);
                        blockModel->setScale(glm::vec3(0.75 * (block->m_startFlipX ? -1 : 1), 0.75 * (block->m_startFlipY ? -1 : 1), 0.75));
                        blockModel->setRotationZ(360 - block->getRotation());
                        blocks.push_back(blockModel);
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

            this->loadObjectModels();
            this->loadPlayerModels();

            auto playLayer = GameManager::sharedState()->m_playLayer;
            ground = Ground3D::create(this, shaderProgram, -200, 3, 50, playLayer->m_groundLayer->getPositionY() + playLayer->m_groundLayer->getContentSize().height - 3 * 2, 0);
            ground2 = Ground3D::create(this, shaderProgram, -200, 3, 50, playLayer->m_groundLayer2->getPositionY() + playLayer->m_groundLayer2->getContentSize().height, 1);

            playerCameraOffset = glm::vec3(0, 5, 20);

            // initial setup
            camera->setYaw(camera->getYaw() + 30.0f);
            playerCameraOffset -= camera->getFront() * 8.0f;
            camera->setPitch(camera->getPitch() - 6.0f);

            return true;
        }
        ~GJ3DGameLayer() {
            for (auto block : blocks) {
                delete block;
            }
            instance = nullptr;
        }
        virtual void draw() {
            //ground2->setVisible(GameManager::sharedState()->m_playLayer->m_player1->m_isShip);
            // rainix, what value is this?
            //ground2->updateYPos(MBO(float, GameManager::sharedState()->m_playLayer, 0x2A0));
            //if (GameManager::sharedState()->m_playLayer->m_player1->m_isShip)
            //    ground->updateYPos(MBO(float, GameManager::sharedState()->m_playLayer, 0x2A0) - 300);
            //else
            //    ground->updateYPos(-60);

            auto playLayer = GameManager::sharedState()->m_playLayer;
            ground->updateYPos(playLayer->m_groundLayer->getPositionY() + playLayer->m_groundLayer->getContentSize().height - 75.0f);
            ground2->updateYPos(playLayer->m_groundLayer2->getPositionY() + playLayer->m_groundLayer2->getContentSize().height + 75.0f);
            ground->setVisible(playLayer->m_groundLayer->isVisible());
            ground2->setVisible(playLayer->m_groundLayer2->isVisible());

            OpenGLStateHelper::saveState();

            updateGrounds();

            glEnable(GL_BLEND);
            glEnable(GL_ALPHA_TEST);
            glEnable(GL_DEPTH_TEST);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            glm::mat4 view = camera->getViewMat();

            glm::mat4 projection = camera->getProjectionMat();

            for (auto model : models) {
                model->render(
                    view,
                    light->getPosition(),
                    light->getColor(),
                    camera->getPosition(),
                    projection);
            }

            Model* player = cube;
            auto playerObject = playLayer->m_player1;
            playerObject->getParent()->setVisible(false);
            // ground calculations is so hard -adaf
            playLayer->m_groundLayer->setVisible(false);
            playLayer->m_groundLayer2->setVisible(false);
            ground->updateYPos(playLayer->m_groundLayer->getPositionY());
            ground2->updateYPos(playLayer->m_groundLayer2->getPositionY());
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

            //glDepthMask(GL_FALSE);

            for (auto model : blocks) {
                if (abs(model->getPositionX() - player->getPositionX()) < 150)
                    model->render(view, light->getPosition(), light->getColor(), camera->getPosition(), projection);
            }
            player->render(view, light->getPosition(), light->getColor(), camera->getPosition(), projection);

            //glDepthMask(GL_TRUE);

            glDisable(GL_DEPTH_TEST);

            OpenGLStateHelper::pushState();

            auto newX = playerObject->getPositionX() * 0.05;
            auto newY = playerObject->getPositionY() * 0.05;
            auto newZ = 20.f;
            auto newR = playerObject->getRotation();

            auto groundHeight = (playLayer->m_groundLayer->getPositionY() + playLayer->m_groundLayer->getContentSize().height) * 0.05;

            player->setPosition(glm::vec3(newX, newY, newZ));
            player->setRotationZ(360 - newR);
            camera->setPosition(glm::vec3(newX + playerCameraOffset.x, newY + playerCameraOffset.y, newZ + playerCameraOffset.z));
            light->setPosition(glm::vec3(newX + 50, groundHeight + 50, newZ + 50));
        }

        CCPoint lastTouchPosition;
        bool isTouching = false;
        virtual void touch(CCSet* touches, CCEvent* event, unsigned int type) {
            auto touch = static_cast<CCTouch*>(*touches->begin());
            auto currentTouchPosition = touch->getLocation();

            switch (type) {
            case 0: // Touch began
                isTouching = true;
                lastTouchPosition = currentTouchPosition;
                break;

            case 1: // Touch moved
                if (isTouching) {
                    CCPoint delta = currentTouchPosition - lastTouchPosition;

                    // Adjust camera pitch and yaw based on touch delta
                    float sensitivity = 0.1f;
                    float yaw = camera->getYaw() - delta.x * sensitivity;
                    float pitch = camera->getPitch() - delta.y * sensitivity;

                    // Clamp pitch to prevent flipping
                    pitch = std::clamp(pitch, -89.0f, 89.0f);

                    camera->setYaw(yaw);
                    camera->setPitch(pitch);

                    lastTouchPosition = currentTouchPosition;
                }
                break;

            case 2: // Touch ended
                isTouching = false;
                break;
            }
        }

        bool isRightClicking = false;
        float lastMouseX = 0.0;
        float lastMouseY = 0.0;

        virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) {
            if (button == GLFW_MOUSE_BUTTON_RIGHT) {
                if (action == GLFW_PRESS) {
                    isRightClicking = true;

                    // Initialize the last mouse position
                    double x, y;
                    glfwGetCursorPos(window, &x, &y);
                    lastMouseX = static_cast<float>(x);
                    lastMouseY = static_cast<float>(y);
                }
                else if (action == GLFW_RELEASE) {
                    isRightClicking = false;
                }
            }
        }

        virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) {
            if (isRightClicking) {
                // Calculate mouse movement delta
                float deltaX = static_cast<float>(x) - lastMouseX;
                float deltaY = static_cast<float>(y) - lastMouseY;

                // Adjust camera pitch and yaw based on delta
                float sensitivity = 0.1f;
                float yaw = camera->getYaw() - deltaX * sensitivity;
                float pitch = camera->getPitch() - deltaY * sensitivity;

                // Clamp pitch to prevent flipping
                pitch = std::clamp(pitch, -89.0f, 89.0f);

                // Update camera orientation
                camera->setYaw(yaw);
                camera->setPitch(pitch);

                // Update last mouse position
                lastMouseX = static_cast<float>(x);
                lastMouseY = static_cast<float>(y);
            }
        }

        virtual void scrollWheel(float x, float y) {
            // Adjust the camera zoom level using the scroll wheel
            float zoomSensitivity = 5.0f;
            glm::vec3 position = camera->getPosition();
            // Move the camera closer or further along its front direction
            camera->setPosition(position + camera->getFront() * (x * zoomSensitivity));
        }

        virtual void onKey(enumKeyCodes key, bool pressed, bool holding) {
            switch (key) {
            case KEY_Up:
                camera->setPitch(camera->getPitch() + 1.0f);
                break;
            case KEY_Down:
                camera->setPitch(camera->getPitch() - 1.0f);
                break;
            case KEY_Right:
                camera->setYaw(camera->getYaw() + 5.0f);
                break;
            case KEY_Left:
                camera->setYaw(camera->getYaw() - 5.0f);
                break;
            case KEY_W:
                playerCameraOffset += camera->getFront();
                break;
            case KEY_S:
                playerCameraOffset -= camera->getFront();
                break;
            case KEY_A:
                playerCameraOffset -= glm::normalize(glm::cross(camera->getFront(), camera->getUp()));
                break;
            case KEY_D:
                playerCameraOffset += glm::normalize(glm::cross(camera->getFront(), camera->getUp()));
                break;
            default:
                break;
            }
        }

    public:
        static auto create() {
            auto node = new GJ3DGameLayer;
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

    GJ3DGameLayer* GJ3DGameLayer::instance = nullptr;

    class $modify(PlayLayer)
    {
        void resetLevel()
        {
            PlayLayer::resetLevel();
            if (GJ3DGameLayer::instance) { GJ3DGameLayer::instance->resetGrounds(); }
        }

        bool init(GJGameLevel * level, bool useReplay, bool dontCreateObjects)
        {
            if (!PlayLayer::init(level, useReplay, dontCreateObjects)) { return false; }

            GJ3DGameLayer* node = GJ3DGameLayer::create();

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