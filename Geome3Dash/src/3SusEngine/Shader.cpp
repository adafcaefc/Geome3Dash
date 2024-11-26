#include "pch.h"
#include "../pch.h"
#include "Shader.h"

namespace g3d
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
            geode::log::error("VERTEX ERROR: {}", infoLog);
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
            geode::log::error("FRAGMENT ERROR: {}", infoLog);
            return 0;
        }
        return 1;
    }

    bool Shader::initShader(std::string shaderString) {
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
        if (id)
            glDeleteShader(id);
    }

    std::string Shader::readFile(std::string filename) {
        const auto shaderPath = CCFileUtils::sharedFileUtils()->fullPathForFilename(filename.c_str(), false);
        std::string shaderSource;
        if (std::filesystem::exists(shaderPath)) {
            std::ifstream file;
            file.open(shaderPath, std::ios::in);
            std::ostringstream sstr;
            sstr << file.rdbuf();
            shaderSource = sstr.str();
            file.close();
        }
        return shaderSource;
    }

    Shader* Shader::createWithString(std::string shaderString, ShaderType type) {
        auto ret = new Shader();
        ret->type = type;
        if (!ret || !ret->initShader(shaderString)) {
            return nullptr;
        }
        return ret;
    }

    Shader* Shader::createWithFile(std::string filename, ShaderType type) {
        auto shaderString = readFile(filename);
        return createWithString(shaderString, type);
    }
}