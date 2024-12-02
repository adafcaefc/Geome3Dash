#include "pch.h"

#include "game/test/G3DModelPreviewLayer.h"
#include "game/component/G3DBaseNode.h"
#include "game/component/G3DFragmentShaderLayer.h"

#include "CocosShaderProgram.h"
#include "BlockModelsStorage.h"

#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Shaders.h"
#include "engine/sus3d/Model.h"
#include "engine/sus3d/Mesh.h"

#include "Helper/OpenGLStateHelper.h"
#include "Helper/CommonHelper.h"

#include "lib/tinyfiledialogs/tinyfiledialogs.h"

namespace g3d
{
    void G3DModelPreviewLayer::onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) {
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

    void G3DModelPreviewLayer::onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) {
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
                    layer3d->camera.setPosition(layer3d->camera.getPosition() + layer3d->camera.getUp() * deltaY * sensitivity);
                    layer3d->camera.setPosition(layer3d->camera.getPosition() + glm::normalize(glm::cross(layer3d->camera.getFront(), layer3d->camera.getUp())) * deltaX * -sensitivity);
                }
                else {
                    float sensitivity = 0.05f;
                    float yaw = layer3d->camera.getYaw() - deltaX * sensitivity;
                    float pitch = layer3d->camera.getPitch() - deltaY * sensitivity;
                    // Clamp pitch to prevent flipping
                    pitch = std::clamp(pitch, -89.0f, 89.0f);
                    layer3d->camera.setYaw(yaw);
                    layer3d->camera.setPitch(pitch);
                }
                lastMouseX = static_cast<float>(x);
                lastMouseY = static_cast<float>(y);
            }
        }
    }

    void G3DModelPreviewLayer::scrollWheel(float y, float x) {
        // Adjust the camera zoom level using the scroll wheel
        float zoomSensitivity = -0.128f;
        layer3d->camera.setPosition(layer3d->camera.getPosition() + layer3d->camera.getFront() * y * zoomSensitivity);
    }

    void G3DModelPreviewLayer::onKey(enumKeyCodes key, bool pressed, bool holding) {
        switch (key) {
        case KEY_Control:
            isPressingControl = pressed;
            break;
        default:
            break;
        }
    }

    std::optional<std::string> G3DModelPreviewLayer::openModelSelectModal() {
        const char* title = "select model";
        const char* filterPatterns[] = { "*.obj" };
        const char* filePath = tinyfd_openFileDialog(
            title,
            nullptr,
            1,
            filterPatterns,
            "OBJ",
            0
        );

        if (filePath)
            return std::string(filePath);
        return std::nullopt;
    }

    bool G3DModelPreviewLayer::init() {
        //FMODAudioEngine::get()->playMusic("A145 - A Newborn Spirit.mp3", true, 1, 0);
        CCLayer::init();

        setKeyboardEnabled(true);
        OpenGLStateHelper::saveState();
        auto vertexShader = sus3d::Shader::createWithString(sus3d::shaders::vertexShaderSource, sus3d::ShaderType::kVertexShader);
        auto fragmentShader = sus3d::Shader::createWithString(sus3d::shaders::fragmentShaderSource, sus3d::ShaderType::kFragmentShader);
        shaderProgram = CocosShaderProgram::create(vertexShader, fragmentShader);
        delete vertexShader;
        delete fragmentShader;
        OpenGLStateHelper::pushState();

        layer3d = G3DBaseNode::create();
        layer3d->light.setPosition(glm::vec3(50, 100, 50));
        layer3d->setZOrder(10);
        this->addChild(layer3d);

        auto size = CCDirector::sharedDirector()->getWinSize();

        auto testLayer = G3DFragmentShaderLayer::create(geode::Mod::get()->getResourcesDir() / "model3d" / "planet" / "shader" / "space.fsh");
        this->addChild(testLayer);

        auto bg = CCSprite::create("GJ_gradientBG.png");
        bg->setScaleX(size.width / bg->getContentSize().width);
        bg->setScaleY(size.height / bg->getContentSize().height);
        bg->setColor({ 0, 75, 110 });
        bg->setZOrder(-5);

        bg->setPosition(size / 2);

        this->addChild(bg);

        auto backButtonSprite = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
        auto backButton = CCMenuItemSpriteExtra::create(backButtonSprite, this, menu_selector(G3DModelPreviewLayer::onBack));
        auto backButtonMenu = CCMenu::create();
        backButtonMenu->setPosition(25, size.height - 25);
        backButtonMenu->addChild(backButton);
        this->addChild(backButtonMenu);


        auto selectModelButtonSprite = CCSprite::createWithSpriteFrameName("accountBtn_myLevels_001.png");
        auto selectModelButton = CCMenuItemSpriteExtra::create(selectModelButtonSprite, this, menu_selector(G3DModelPreviewLayer::onSelectModel));
        auto selectModelMenu = CCMenu::create();
        selectModelMenu->setPosition(size.width - 25, size.height - 25);
        selectModelMenu->addChild(selectModelButton);
        this->addChild(selectModelMenu);

        return true;
    }

    void G3DModelPreviewLayer::onBack(CCObject*) {
        keyBackClicked();
    }

    void G3DModelPreviewLayer::keyBackClicked(void) {
        CCDirector::sharedDirector()->popSceneWithTransition(0.3f, PopTransition::kPopTransitionFade);
        //FMODAudioEngine::get()->stopAllMusic(true);
    }

    void G3DModelPreviewLayer::draw() {
        CCLayer::draw();
        layer3d->light.setPosition(layer3d->camera.getPosition());

        auto selected = layer3d->getObjectIDByMousePosition();

        for (int modelIndex = 0; modelIndex < layer3d->models.size(); modelIndex++) {
            for (size_t meshIndex = 0; meshIndex < layer3d->models[modelIndex]->meshes.size(); meshIndex++) {
                if (modelIndex == selected.first && meshIndex == selected.second)
                    layer3d->models[modelIndex]->meshes[meshIndex]->setCustomKa(glm::vec3(1, 0, 0));
                else
                    layer3d->models[modelIndex]->meshes[meshIndex]->disableKa();
            }
        }
    }

    void G3DModelPreviewLayer::onSelectModel(CCObject*) 
    {
        auto path = openModelSelectModal();
        if (!path.has_value()) { return; }
        const auto obj_path = std::filesystem::path(path.value());
        layer3d->models.push_back(BlockModelsStorage::getInstance()->getModel(path.value()));
    }

    G3DModelPreviewLayer* G3DModelPreviewLayer::create() {
        auto node = new G3DModelPreviewLayer;
        if (node->init()) {
            node->autorelease();
        }
        else {
            CC_SAFE_DELETE(node);
        }
        return node;
    }
}
