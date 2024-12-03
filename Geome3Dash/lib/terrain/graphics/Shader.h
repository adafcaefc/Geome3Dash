#ifndef _SHADER_H_
#define _SHADER_H_

/**************************************************
 * Simple function to read GLSL shader source from a file,
 * Then compile it and link to create a shader program ready for use.
 * Returns the ID of the shader program (assigned by OpenGL)
 * or 0 if error.
**************************************************/

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
	int shaderId;
    std::string shaderPath;
	int getHandle(std::string uniformName);
	int CompileShader(const char *ShaderPath, const GLuint ShaderID);
	GLuint LoadShaders(std::string vertex_file_path, std::string fragment_file_path);
public:
    Shader(std::string vertex_file_path, std::string fragment_file_path);
    void setMat4(std::string uniformName, const glm::mat4 &mat);
    void setVec3(std::string uniformName, const glm::vec3 &vec);
    void setVec3(std::string uniformName, float x, float y, float z);
    void setRgb(std::string uniformName, int x, int y, int z);
    void setFloat(std::string uniformName, float x);
    void setInt(std::string uniformName, int x);
    void setSampler2d(std::string uniformName, int x);
    int GetId();
    void EnableTexture(int textureId);
    void use();
    void PrintAllUniforms();
};

#endif
