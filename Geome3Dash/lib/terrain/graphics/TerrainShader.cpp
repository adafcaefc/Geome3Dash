#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include <GL/glew.h>

#include "graphics/Shader.h"

int Shader::CompileShader(const char *ShaderPath, const GLuint ShaderID)
{
	// Read shader code from file
	std::string ShaderCode;
	std::ifstream ShaderStream (ShaderPath, std::ios::in);
	if (ShaderStream.is_open()) {
		std::string Line = "";
		while (getline(ShaderStream, Line)) {
			ShaderCode += "\n" + Line;
        }
		ShaderStream.close();
	}
    else {
        std::cerr << "Cannot open " << ShaderPath << ". Are you in the right directory?" << std::endl;
		return 0;
	}

	// Compile Shader
	char const *SourcePointer = ShaderCode.c_str();
	glShaderSource(ShaderID, 1, &SourcePointer , NULL);
	glCompileShader(ShaderID);

	// Check Shader
	GLint Result = GL_FALSE;
	int InfoLogLength;

	glGetShaderiv(ShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(ShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    // printf("compiled shader %d %d\n", Result, InfoLogLength);
	if ( InfoLogLength > 1 ) {
        char ShaderErrorMessage[InfoLogLength+1];
		glGetShaderInfoLog( ShaderID,
                            InfoLogLength,
                            NULL,
                            &ShaderErrorMessage[0]);
        std::cerr << &ShaderErrorMessage[0] << std::endl;
        return 0;
	}
    return 1;
}

GLuint Shader::LoadShaders(std::string vertex_file_path,
                   std::string fragment_file_path)
{
	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // Compile both shaders. Exit if compile errors.
    if ( !CompileShader(vertex_file_path.c_str(), VertexShaderID)
         || !CompileShader(fragment_file_path.c_str(), FragmentShaderID) ) {
        return 0;
    }
    
	// Link the program
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	GLint Result = GL_FALSE;
	int InfoLogLength;
    
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ) {
		std::vector<char> ProgramErrorMessage(InfoLogLength+1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        std::cerr << &ProgramErrorMessage[0] << std::endl;
	}

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	return ProgramID;
}

Shader::Shader(std::string vertex_file_path,
                   std::string fragment_file_path)
{
    this->shaderPath = vertex_file_path;
	this->shaderId = this->LoadShaders(vertex_file_path, fragment_file_path);
    if (this->shaderId == 0)
        exit(0);
	this->use();
}

void Shader::use()
{
    glUseProgram(this->shaderId);
}

void Shader::setMat4(std::string uniformName, const glm::mat4 &mat)
{
    use();
    glUniformMatrix4fv(this->getHandle(uniformName), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::setVec3(std::string uniformName, const glm::vec3 &vec)
{
    glUniform3fv(this->getHandle(uniformName), 1, glm::value_ptr(vec));
}

void Shader::setVec3(std::string uniformName, float x, float y, float z)
{
    glUniform3f(this->getHandle(uniformName), x, y, z);
}

float rgbNorm(int rgbVal)
{
    return (rgbVal*1.0f/255.0f); 
}

void Shader::setRgb(std::string uniformName, int r, int g, int b)
{
    glUniform3f(this->getHandle(uniformName), rgbNorm(r), rgbNorm(g), rgbNorm(b));
}

void Shader::setFloat(std::string uniformName, float x)
{
    glUniform1f(this->getHandle(uniformName), x);
}

void Shader::setInt(std::string uniformName, int x)
{
    glUniform1i(this->getHandle(uniformName), x);
}

void Shader::setSampler2d(std::string uniformName, int x)
{
    glUniform1i(this->getHandle(uniformName), x);
}

int Shader::getHandle(std::string uniformName)
{
    int handle = glGetUniformLocation(this->shaderId, uniformName.c_str());
    if (handle == -1) {
        std::cout << "error: " << this->shaderPath << ", uniform '" << uniformName.c_str() << "' is not active, ShaderID=" << this->shaderId << ", Handle=" << handle << std::endl;
    }
    return handle;
}

void Shader::EnableTexture(int textureDiffuseId) 
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureDiffuseId);
}

int Shader::GetId()
{
	return this->shaderId;
}

// https://stackoverflow.com/questions/440144/in-opengl-is-there-a-way-to-get-a-list-of-all-uniforms-attribs-used-by-a-shade
void Shader::PrintAllUniforms()
{
    GLint i;
    GLint count;
    int maxCount = 100;

    GLint size; // size of the variable
    GLenum type; // type of the variable (float, vec3 or mat4, etc)

    const GLsizei bufSize = 32; // maximum name length
    GLchar name[bufSize]; // variable name in GLSL
    GLsizei length; // name length

    glGetProgramiv(shaderId, GL_ACTIVE_UNIFORMS, &count);
    printf("Active Uniforms: %d\n", count);
    if(count > maxCount)
        count = maxCount;
    for (i = 0; i < count; i++)
    {
        glGetActiveUniform(shaderId, (GLuint)i, bufSize, &length, &size, &type, name);

        printf("Uniform #%d Type: %u Name: %s\n", i, type, name);        
    }
}