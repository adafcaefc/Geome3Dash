#include "Shader.h"

#include <Geode/cocos/platform/CCGL.h>

#include <fstream>
#include <sstream>

namespace sus3d
{
    bool Shader::initVertexShader(const char* shaderString) {
        id = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(id, 1, &shaderString, NULL);
        glCompileShader(id);

        int success;
        char infoLog[512];
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(id, 512, NULL, infoLog);
            return 0;
        }
        return 1;
    }

    bool Shader::initFragmentShader(const char* shaderString) {
        id = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(id, 1, &shaderString, NULL);
        glCompileShader(id);

        int success;
        char infoLog[512];
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(id, 512, NULL, infoLog);
            return 0;
        }
        return 1;
    }

    bool Shader::initShader(const std::string& shaderString) {
        switch (type) {
        case kVertexShader:
            return initVertexShader(shaderString.c_str());
            break;
        case kFragmentShader:
            return initFragmentShader(shaderString.c_str());
            break;
        default:
            return 0;
            break;
        }
    }

    Shader::~Shader() {
        if (id) { glDeleteShader(id); }
    }

    std::string Shader::readFile(const std::filesystem::path& filename) {
        if (!std::filesystem::exists(filename)) { return std::string(); }
        std::ifstream input(filename);
        if (!input.is_open()) { return std::string(); }
        std::stringstream buffer;
        buffer << input.rdbuf();
        input.close();
        return buffer.str();
    }

    Shader* Shader::createWithString(const std::string& shaderString, ShaderType type) {
        auto ret = new Shader();
        ret->type = type;
        if (!ret || !ret->initShader(shaderString)) {
            return nullptr;
        }
        return ret;
    }

    Shader* Shader::createWithFile(const std::filesystem::path& filename, ShaderType type) {
        auto shaderString = readFile(filename);
        return createWithString(shaderString, type);
    }
}