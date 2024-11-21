#pragma once

namespace g3d
{
    enum ShaderType {
        kVertexShader,
        kFragmentShader
    };

    class Shader {
        unsigned int id;
        ShaderType type;
        Shader() {}

        bool initVertexShader(const char* shaderString);
        bool initFragmentShader(const char* shaderString);
        bool initShader(std::string shaderString);
    public:
        ~Shader();
        static std::string readFile(std::string filename);
        static Shader* createWithString(std::string shaderString, ShaderType type);
        static Shader* createWithFile(std::string filename, ShaderType type);
        int get() { return id; }
        ShaderType getType() { return type; }
    };
}