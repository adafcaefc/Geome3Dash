#pragma once

#include "impl/engine/CocosShaderProgram.h"

namespace g3d
{
    class CocosShaderProgram;
    class G3DFragmentShaderLayer : public CCLayer 
    {
        CocosShaderProgram* shaderProgram;
        unsigned int VAO, VBO, EBO;

        static const std::vector<float> vertices;
        static const std::vector<unsigned int> indices;

        virtual bool initShader(const std::filesystem::path& fragmentShaderFile);
        void prepareBuffers();
        virtual void draw();
    public:
        static G3DFragmentShaderLayer* create(const std::filesystem::path& fragmentShaderFile);

        G3DFragmentShaderLayer()
            : shaderProgram(nullptr), VAO(0), VBO(0), EBO(0) {}

        ~G3DFragmentShaderLayer() {
            glDeleteVertexArrays(1, &VAO);
            glDeleteBuffers(1, &VBO);
            glDeleteBuffers(1, &EBO);
            delete shaderProgram;
        }
    };
}