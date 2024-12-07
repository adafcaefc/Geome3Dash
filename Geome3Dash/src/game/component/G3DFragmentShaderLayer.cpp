#include "pch.h"

#include "G3DFragmentShaderLayer.h"

#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Shaders.h"
#include "engine/sus3d/ShaderProgram.h"

#include "implengine/CocosShaderProgram.h"

#include "helper/OpenGLStateHelper.h"

namespace g3d
{
    bool G3DFragmentShaderLayer::initShader(const std::filesystem::path& fragmentShaderFile) {
        if (!CCLayer::init()) return false;
        OpenGLStateHelper::saveState();
        auto vertexShader = sus3d::Shader::createWithString(sus3d::shaders::basicVertexShader, sus3d::ShaderType::kVertexShader);
        auto fragmentShader = sus3d::Shader::createWithFile(fragmentShaderFile, sus3d::ShaderType::kFragmentShader);
        shaderProgram = CocosShaderProgram::create(vertexShader, fragmentShader);

        delete vertexShader;
        delete fragmentShader;
        OpenGLStateHelper::pushState();
        prepareBuffers();

        return true;
    }

    void G3DFragmentShaderLayer::prepareBuffers() {
        OpenGLStateHelper::saveState();
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindVertexArray(0);
        OpenGLStateHelper::pushState();
    }

    void G3DFragmentShaderLayer::draw() {
        CCLayer::draw();
        OpenGLStateHelper::saveState();
        shaderProgram->use();

        auto screenSize = CCDirector::sharedDirector()->getWinSize();
        float screenWidth = screenSize.width;
        float screenHeight = screenSize.height;

        float time = CCDirector::sharedDirector()->getTotalFrames() * CCDirector::sharedDirector()->getAnimationInterval();

        shaderProgram->setVec2("iResolution", glm::vec2(screenWidth, screenHeight));
        shaderProgram->setFloat("iTime", time);

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        OpenGLStateHelper::pushState();
    }

    G3DFragmentShaderLayer* G3DFragmentShaderLayer::create(const std::filesystem::path& fragmentShaderFile) {
        auto ret = new G3DFragmentShaderLayer();
        if (ret && ret->initShader(fragmentShaderFile)) {
            ret->autorelease();
            return ret;
        }
        delete ret;
        return nullptr;
    }

    const std::vector<float> G3DFragmentShaderLayer::vertices = {
        -1.f, -1.f,
         1.f, -1.f,
         1.f,  1.f,
        -1.f,  1.f
    };

    const std::vector<unsigned int> G3DFragmentShaderLayer::indices = {
        0, 1, 2,
        2, 3, 0
    };
}