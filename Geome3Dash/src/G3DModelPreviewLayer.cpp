#include "pch.h"
#include "../pch.h"

#include "G3DModelPreviewLayer.h"
#include "G3DBaseNode.h"
#include "G3DFragmentShaderLayer.h"

#include "3SusEngine/ShaderProgram.h"
#include "3SusEngine/Shader.h"
#include "3SusEngine/basicShaders.h"
#include "3SusEngine/Model.h"
#include "3SusEngine/Mesh.h"

#include "Library/tinyfiledialogs/tinyfiledialogs.h"

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
            "OBJ פאיכû",
            0
        );

        if (filePath)
            return std::string(filePath);
        return std::nullopt;
    }

    bool G3DModelPreviewLayer::init() {
        CCLayer::init();

        setKeyboardEnabled(true);

        auto vertexShader = Shader::createWithString(shaders::vertexShaderSource, ShaderType::kVertexShader);
        auto fragmentShader = Shader::createWithString(shaders::fragmentShaderSource, ShaderType::kFragmentShader);
        shaderProgram = ShaderProgram::create(vertexShader, fragmentShader);
        delete vertexShader;
        delete fragmentShader;

        layer3d = G3DBaseNode::create();
        layer3d->light.setPosition(glm::vec3(50, 100, 50));
        layer3d->setZOrder(10);
        this->addChild(layer3d);

        auto size = CCDirector::sharedDirector()->getWinSize();

        //auto testLayer = G3DFragmentShaderLayer::create(geode::Mod::get()->getResourcesDir() / "model3d" / "shader" / "star-nest.fsh");
        //this->addChild(testLayer);

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
        CCDirector::sharedDirector()->popSceneWithTransition(0.3, PopTransition::kPopTransitionFade);
    }

    void G3DModelPreviewLayer::draw() {
        CCLayer::draw();
        auto glView = CCDirector::sharedDirector()->m_pobOpenGLView;
        int invertedMouseY = glView->getFrameSize().height - static_cast<int>(glView->m_fMouseY);

        auto selected = layer3d->getObjectIDByMousePosition(static_cast<int>(glView->m_fMouseX), invertedMouseY);
        std::cout << selected.first << " " << selected.second << std::endl;

        for (int modelIndex = 0; modelIndex < layer3d->models.size(); modelIndex++) {
            for (size_t meshIndex = 0; meshIndex < layer3d->models[modelIndex]->meshes.size(); meshIndex++) {
                if (modelIndex == selected.first && meshIndex == selected.second)
                    layer3d->models[modelIndex]->meshes[meshIndex]->setCustomKa(glm::vec3(1, 0, 0));
                else
                    layer3d->models[modelIndex]->meshes[meshIndex]->disableKa();
            }
        }
    }

    void G3DModelPreviewLayer::onSelectModel(CCObject*) {
        auto path = openModelSelectModal();
        if (!path.has_value()) return;

        layer3d->loadAndAddModel(path.value(), shaderProgram);
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
