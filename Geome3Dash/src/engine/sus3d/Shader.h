#pragma once

#include <string>
#include <filesystem>

namespace sus3d
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
        bool initShader(const std::string& shaderString);
    public:
        ~Shader();
        static std::string readFile(const std::filesystem::path& filename);
        static Shader* createWithString(const std::string& shaderString, ShaderType type);
        static Shader* createWithFile(const std::filesystem::path& filename, ShaderType type);
        int get() { return id; }
        ShaderType getType() { return type; }
    };
}