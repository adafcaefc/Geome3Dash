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
#include "BezierHelper.h"
#include <numeric>

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

    //CubicBezier bezier = {
    //    98.0, 314.0,   // x0, y0: Starting point
    //    575.0, 335.0,  // cx1, cy1: First control point
    //    22.0, 192.0,   // cx2, cy2: Second control point
    //    511.0, 220.0   // x1, y1: End point
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

    CubicBezier bezier = {
        100, 300,   // x0, y0: Starting point
        200, 300,  // cx1, cy1: First control point
        300, 300,   // cx2, cy2: Second control point
        500, 300   // x1, y1: End point
    };



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

    struct CameraAction 
    {
        double x, y, z;         // Position
        double yaw, pitch;      // Rotation
        double time;            // Duration of the action
        double triggerAt;       // Trigger when the x-position reaches this value
    };

    double easeInOutQuad(double t, double b, double c, double d) 
    {
        t /= d / 2;
        if (t < 1) { return c / 2 * t * t + b; }
        t--;
        return -c / 2 * (t * (t - 2) - 1) + b;
    }

    class CameraActionHandler 
    {
    private:
        std::vector<CameraAction> actions; // List of actions
        double currentTime;                // Time tracker for animation
        size_t currentActionIndex;         // Current action being processed

        double interpolate(double start, double end, double progress) 
        {
            return easeInOutQuad(progress, start, end - start, 1.0);
        }

    public:
        CameraActionHandler() : currentTime(0), currentActionIndex(0) {}

        void addAction(const CameraAction& action) 
        {
            actions.push_back(action);
        }
        double previousX = 0, previousY = 0, previousZ = 0, previousYaw = 0, previousPitch = 0;

        void update(double deltaTime, double currentXPosition,
            double& deltaX, double& deltaY, double& deltaZ,
            double& deltaYaw, double& deltaPitch)
        {
            if (currentActionIndex >= actions.size()) return;

            CameraAction& action = actions[currentActionIndex];

            // Check if the action should start based on the trigger
            if (currentXPosition < action.triggerAt) return;

            // Increment time for the current action
            currentTime += deltaTime;

            // Calculate interpolation progress
            double progress = currentTime / action.time;
            if (progress > 1.0) progress = 1.0; // Clamp progress to 1.0

            // Interpolate position and rotation
            double newX = interpolate(0, action.x, progress);
            double newY = interpolate(0, action.y, progress);
            double newZ = interpolate(0, action.z, progress);
            double newYaw = interpolate(0, action.yaw, progress);
            double newPitch = interpolate(0, action.pitch, progress);

            // Calculate deltas and output through references
            deltaX = newX - previousX;
            deltaY = newY - previousY;
            deltaZ = newZ - previousZ;
            deltaYaw = newYaw - previousYaw;
            deltaPitch = newPitch - previousPitch;

            // Update the previous values
            previousX = newX;
            previousY = newY;
            previousZ = newZ;
            previousYaw = newYaw;
            previousPitch = newPitch;

            // Move to the next action if done
            if (progress >= 1.0)
            {
                currentActionIndex++;
                currentTime = 0; // Reset time for the next action
                previousX = 0;
                previousY = 0;
                previousZ = 0;
                previousYaw = 0;
                previousPitch = 0;
            }
        }
    };



    struct BezierCoordinate
    {
        glm::vec3 position;
        double rotation;
    };

    static std::unordered_map<CubicBezier, std::pair<std::vector<double>, double>, CubicBezierHash> arcLengths;
    BezierCoordinate transformIntoBezierCoordinate(
        const CubicBezier& segment, 
        double x, double y, double z,
        int segmentCount)
    {
        constexpr double MULTIPLIER_SEGMENT = 7.5;
        if (arcLengths.find(segment) == arcLengths.end())
        {
            arcLengths[segment] = std::pair<std::vector<double>, double>();
            computeArcLengths(
                segment.x0, segment.y0,
                segment.cx1, segment.cy1,
                segment.cx2, segment.cy2,
                segment.x1, segment.y1,
                arcLengths.at(segment).first, segmentCount);
            arcLengths.at(segment).second = std::accumulate(
                arcLengths.at(segment).first.begin(),
                arcLengths.at(segment).first.end(),
                0.0);
        }
        double t = x / arcLengths.at(segment).second * 460808.571428 * MULTIPLIER_SEGMENT;
        CubicBezier segmentCopy = segment;

        if (t > 1)
        {
            double mrt = std::fmod(t, 1.0);
            double art = t - mrt;
            t = mrt;
            double tmpx1 = art * (segment.x1 - segment.x0);
            double tmpy1 = art * (segment.y1 - segment.y0);
            segmentCopy = 
            {
                tmpx1 + segment.x0, tmpy1 + segment.y0,
                tmpx1 +  segment.cx1, tmpy1 + segment.cy1,
                tmpx1 +  segment.cx2, tmpy1 + segment.cy2,
                tmpx1 +  segment.x1, tmpy1 + segment.y1,
            };
        }

        // First, we need to evaluate the Bezier curve for X and Z axis
        double bezierX = 0.0, bezierZ = 0.0, rotationY = 0.0;

        //// Evaluate the Bezier curve for X-axis using the segment's start and end points, and control points
        //evaluateCubicBezier(t, segment.x0, segment.y0, segment.cx1, segment.cy1, segment.cx2, segment.cy2, segment.x1, segment.y1,
        //    bezierX, bezierZ, rotationY);


        if (arcLengths.find(segmentCopy) == arcLengths.end())
        {
            arcLengths[segmentCopy] = std::pair<std::vector<double>, double>();
            computeArcLengths(
                segmentCopy.x0, segmentCopy.y0,
                segmentCopy.cx1, segmentCopy.cy1,
                segmentCopy.cx2, segmentCopy.cy2,
                segmentCopy.x1, segmentCopy.y1,
                arcLengths.at(segmentCopy).first, segmentCount);
            arcLengths.at(segmentCopy).second = std::accumulate(
                arcLengths.at(segmentCopy).first.begin(),
                arcLengths.at(segmentCopy).first.end(),
                0.0);
        }

        // Evaluate the Bezier curve for X-axis using the segment's start and end points, and control points
        evaluateCubicBezierUniform(
            t,
            segmentCopy.x0, segmentCopy.y0,
            segmentCopy.cx1, segmentCopy.cy1,
            segmentCopy.cx2, segmentCopy.cy2,
            segmentCopy.x1, segmentCopy.y1,
            bezierX, bezierZ, rotationY, 
            arcLengths.at(segmentCopy).first);


        // Return the transformed coordinates as a glm::vec3, with the original Y and Z coordinates being transformed along the curve
        return { glm::vec3(bezierX / MULTIPLIER_SEGMENT, y, bezierZ / MULTIPLIER_SEGMENT), glm::degrees(rotationY) };  // Since y is not involved in the Bezier curve transformation, it remains unchanged
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

            auto newX = playerObject->m_position.x * 0.05;
            auto newY = playerObject->m_position.y * 0.05;
            auto newZ = 20.f;
            auto newR = playerObject->getRotation();
            auto bCoordinate = transformIntoBezierCoordinate(bezier, newX, newY, newZ, 1000000);
            player->setPosition(bCoordinate.position);
            player->setRotationY(360 - bCoordinate.rotation);
            player->setRotationZ(360 - newR);
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

        std::unordered_map<GameObject*, Model*> blocks;
        std::unordered_map<int, Model*> blockModels;
        glm::vec3 playerCameraOffset;
        double playerCameraYawOffset;
        double playerCameraPitchOffset;
        g3d::ShaderProgram* shaderProgram;

        Camera camera;
        Light light;

        CameraActionHandler cameraActionHandler;

    public:
        static PlayLayer3D* instance;

        void loadShader()
        {
            auto vertexShader = Shader::createWithString(vertexShaderSource, ShaderType::kVertexShader);
            auto fragmentShader = Shader::createWithString(fragmentShaderSource, ShaderType::kFragmentShader);

            shaderProgram = ShaderProgram::create(vertexShader, fragmentShader);

            delete vertexShader;
            delete fragmentShader;
        }

        // mtl model path fix (model path must be absolute)
        void parseMtlPath(const std::filesystem::path& mtl_path)
        {
            if (std::filesystem::exists(mtl_path))
            {
                auto mtl_file = read_from_file(mtl_path);
                // to do: leave the model png!!!
                if (mtl_file.find("{{MODEL_PATH}}") != std::string::npos)
                {
                    replace_all(mtl_file, "{{MODEL_PATH}}", mtl_path.parent_path().string());
                }
                write_to_file(mtl_path, mtl_file);
            }
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

        bool init() 
        {
            CCNode::init();

            // clear cache of bezier segments
            arcLengths.clear();

            this->loadShader();

            auto playLayer = GameManager::sharedState()->m_playLayer;

            this->loadObjectModels();
            player1.init(shaderProgram, playLayer->m_player1, &this->camera, &this->light);

            playerCameraOffset = glm::vec3(-20, 5, -20);
            playerCameraYawOffset = 60.f;
            playerCameraPitchOffset = -6.f;

            // Add some example camera actions
            cameraActionHandler.addAction({ +1, +2, -2, +5, +3, 1.0, 200 });
            cameraActionHandler.addAction({ +5, +3, -1, -5, -3, 2.0, 1000 });

            return true;
        }
        ~PlayLayer3D() 
        {
            for (auto [_, block] : blockModels) { delete block; }
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
            light.setPosition(camera.getPosition());
        }

        void updateBlock(GameObject* obj, Model* model)
        {
            auto newX = obj->m_positionX * 0.05;
            auto newY = obj->m_positionY * 0.05;
            auto newZ = 20.f;
            auto bCoordinate = transformIntoBezierCoordinate(
                bezier,
                newX, newY, newZ,
                1000000);
            model->setPosition(bCoordinate.position);
            model->setRotationY(360 - bCoordinate.rotation);;
            model->setScale(glm::vec3(0.75 * (obj->m_startFlipX ? -1 : 1), 0.75 * (obj->m_startFlipY ? -1 : 1), 0.75));
            model->setRotationZ(360 - obj->getRotation()); // block rotation
        }

        void drawBlocks()
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

        // Timing
        std::chrono::steady_clock::time_point lastUpdate;
        void updateCameraAction(const float currentXPosition)
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

        virtual void draw() 
        {
            CCNode::draw();

            auto playLayer = GameManager::sharedState()->m_playLayer;

            updateCameraAction(playLayer->m_player1->m_position.x);

            playLayer->m_player1->getParent()->setVisible(false);
            // ground calculations is so hard -adaf
            playLayer->m_groundLayer->setVisible(false);
            playLayer->m_groundLayer2->setVisible(false);

            player1.updateModel();
            updateCamera();
            updateLight();

            OpenGLStateHelper::saveState();
            glEnable(GL_BLEND);
            glEnable(GL_ALPHA_TEST);
            glEnable(GL_DEPTH_TEST);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            player1.drawModel();
            drawBlocks();

            glDisable(GL_DEPTH_TEST);
            OpenGLStateHelper::pushState();
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
        struct Fields
        {
            PlayLayer3D* playLayer3D = nullptr;
        };

        void resetLevel()
        {
            if (!m_fields->playLayer3D)
            {
                m_fields->playLayer3D = PlayLayer3D::create();
                m_fields->playLayer3D->setZOrder(10);
                this->addChild(m_fields->playLayer3D);
            }
            PlayLayer::resetLevel();
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