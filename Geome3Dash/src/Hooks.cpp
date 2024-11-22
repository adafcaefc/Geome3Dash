#include "pch.h"
#include "../pch.h"
#include "ShaderProgram.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Model.h"
#include "OpenGLStateHelper.h"
#include "CustomKeyboard.h"
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

    class My3DScene : public ShaderScene, public CustomKeyboardDelegate {
        Model* model;
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
                camera->setPosition(camera->getPosition() + camera->getFront());
                break;
            case KEY_S:
                camera->setPosition(camera->getPosition() - camera->getFront());
                break;
            case KEY_A:
                camera->setPosition(camera->getPosition() - glm::normalize(glm::cross(camera->getFront(), camera->getUp())));
                break;
            case KEY_D:
                camera->setPosition(camera->getPosition() + glm::normalize(glm::cross(camera->getFront(), camera->getUp())));
                break;
            default:
                break;
            }
        }

        bool init() {
            CCNode::init();

            camera->setPosition(glm::vec3(0.0f, 0.0f, 3.0f));
            light->setPosition(glm::vec3(300.0f, 200.0f, 100.0f));


            auto vertexShader = Shader::createWithString(vertexShaderSource, ShaderType::kVertexShader);
            auto fragmentShader = Shader::createWithString(fragmentShaderSource, ShaderType::kFragmentShader);

            auto shaderProgram = ShaderProgram::create(vertexShader, fragmentShader);

            delete vertexShader;
            delete fragmentShader;

            // temporarily disabled by adaf
            //Assimp::Importer importer;
            //const aiScene* scene = importer.ReadFile("./cliff.obj",
            //    aiProcess_Triangulate |
            //    aiProcess_FlipUVs |
            //    aiProcess_JoinIdenticalVertices |
            //    aiProcess_SortByPType);
            //model = Model::create(scene, shaderProgram);
            //const aiScene* scene2 = importer.ReadFile("./lightcube.obj",
            //    aiProcess_Triangulate |
            //    aiProcess_FlipUVs |
            //    aiProcess_JoinIdenticalVertices |
            //    aiProcess_SortByPType);
            //auto model2 = Model::create(scene2, shaderProgram);
            //model2->setPosition(glm::vec3(0, 0, -80));
            //this->models.push_back(model);
            //this->models.push_back(model2);

            return true;
        }
        virtual void draw() {
            ShaderScene::draw();
            model->setRotationY(model->getRotationY() + 0.1);
        }
    public:
        static auto create() {
            auto node = new My3DScene;
            if (node->init()) {
                node->autorelease();
            }
            else {
                CC_SAFE_DELETE(node);
            }
            return node;
        }
    };

    class GJ3DGameLayer : public ShaderScene, public CustomKeyboardDelegate {
        Model* bg;
        Model* player;
        Ground3D* ground;
        Ground3D* ground2;
        std::vector<Model*> blocks;
        glm::vec3 playerCameraOffset;
        float groundHeight = 105 * 0.05;

    public:
        static GJ3DGameLayer* instance;

        void updateGrounds() {
            ground->updateGround();
            ground2->updateGround();
        }

        void resetGrounds() {
            ground->resetGround();
            ground2->resetGround();
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

        bool init() {
            CCNode::init();

            auto vertexShader = Shader::createWithString(vertexShaderSource, ShaderType::kVertexShader);
            auto fragmentShader = Shader::createWithString(fragmentShaderSource, ShaderType::kFragmentShader);

            auto shaderProgram = ShaderProgram::create(vertexShader, fragmentShader);

            delete vertexShader;
            delete fragmentShader;

            const auto res_path = geode::Mod::get()->getResourcesDir();

            CCObject* obj;
            CCARRAY_FOREACH(GameManager::sharedState()->m_playLayer->m_objects, obj) {
                auto block = dynamic_cast<GameObject*>(obj);
                const auto model_dir = res_path / "model3d" / "object" / std::to_string(block->m_objectID) ;
                const auto model_path = model_dir / "model.obj";
                const auto mtl_path = model_dir / "model.mtl";
                const auto png_path = model_dir / "model.png";
                if (std::filesystem::exists(model_path)) {
                    // mtl model path fix (model path must be absolute
                    if (std::filesystem::exists(mtl_path)) {
                        auto mtl_file = read_from_file(mtl_path);
                        if (mtl_file.find("{{MODEL_PATH}}") != std::string::npos) {
                            replace_all(mtl_file, "{{MODEL_PATH}}", png_path.string());
                        }
                        write_to_file(mtl_path, mtl_file);
                    }
                    if (auto blockModel = loadWithoutAddModel(model_path, shaderProgram)) {
                        blockModel->setPosition(glm::vec3(block->getPositionX() * 0.05, block->getPositionY() * 0.05, 20.f));
                        std::cout << block->m_objectID << " " << block->m_startFlipX << " " << block->m_scaleX << " " << std::endl;
                        blockModel->setScale(glm::vec3(0.75 * (block->m_startFlipX ? -1 : 1), 0.75 * (block->m_startFlipY ? -1 : 1), 0.75));
                        blockModel->setRotationZ(360 - block->getRotation());
                        blocks.push_back(blockModel);
                    }
                }
            }

            // temporarily disabled by adaf
            //bg = loadAndAddModel("./cliff.obj", shaderProgram);
            //bg->setPosition(glm::vec3(300, -100, -300));
            //bg->setScale(glm::vec3(3, 3, 3));

            // to do : icon selection
            player = loadAndAddModel(res_path / "model3d" / "player" / "cube" / "0" / "model.obj", shaderProgram);
            player->setScale(glm::vec3(0.75));
            

            ground = Ground3D::create(this, shaderProgram, -200, 3, 50, groundHeight - 3 * 2, 0);
            ground2 = Ground3D::create(this, shaderProgram, -200, 3, 50, groundHeight, 1);

            playerCameraOffset = glm::vec3(0, 5, 20);

            return true;
        }
        ~GJ3DGameLayer() {
            for (auto block : blocks) {
                delete block;
            }
            instance = nullptr;
        }
        virtual void draw() {

            ground2->setVisible(GameManager::sharedState()->m_playLayer->m_player1->m_isShip);
            // rainix, what value is this?
            //ground2->updateYPos(MBO(float, GameManager::sharedState()->m_playLayer, 0x2A0));
            //if (GameManager::sharedState()->m_playLayer->m_player1->m_isShip)
            //    ground->updateYPos(MBO(float, GameManager::sharedState()->m_playLayer, 0x2A0) - 300);
            //else
            //    ground->updateYPos(-60);

            OpenGLStateHelper::saveState();

            updateGrounds();

            glEnable(GL_BLEND);
            glEnable(GL_ALPHA_TEST);
            glEnable(GL_DEPTH_TEST);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            glm::mat4 view = camera->getViewMat();

            glm::mat4 projection = camera->getProjectionMat();

            for (auto model : models) {
                model->render(view, light->getPosition(), light->getColor(), camera->getPosition(), projection);
            }

            //glDepthMask(GL_FALSE);

            for (auto model : blocks) {
                if (abs(model->getPositionX() - player->getPositionX()) < 150)
                    model->render(view, light->getPosition(), light->getColor(), camera->getPosition(), projection);
            }

            //glDepthMask(GL_TRUE);

            glDisable(GL_DEPTH_TEST);

            OpenGLStateHelper::pushState();

            auto newX = GameManager::sharedState()->m_playLayer->m_player1->getPositionX() * 0.05;
            auto newY = GameManager::sharedState()->m_playLayer->m_player1->getPositionY() * 0.05;
            auto newZ = 20.f;
            auto newR = GameManager::sharedState()->m_playLayer->m_player1->getRotation();

            player->setPosition(glm::vec3(newX, newY, newZ));
            player->setRotationZ(360 - newR);
            //camera->setPosition(glm::vec3(newX + playerCameraOffset.x, groundHeight + playerCameraOffset.y, newZ + playerCameraOffset.z));
            camera->setPosition(glm::vec3(newX + playerCameraOffset.x, newY + playerCameraOffset.y, newZ + playerCameraOffset.z));
            light->setPosition(glm::vec3(newX + 50, groundHeight + 50, newZ + 50));

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

    void HookAll()
    {
        auto mod = geode::Mod::get();
        for (auto& hook : mod->getHooks()) { hook->enable(); }
    }
}