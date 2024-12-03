#ifndef _SKYBOX_H_
#define _SKYBOX_H_

#include <string>
#include <vector>

#include <glm/glm.hpp>
#include "scene/SceneComponent.h"
#include "graphics/Shader.h"

// Repsonsible For Tracking the players movements
class Skybox : public SceneComponent
{
private: 
    Shader* shader;
    unsigned int skyboxVAO, skyboxVBO;
    unsigned int cubemapTexture;
    unsigned int loadCubemap(std::vector<std::string> faces);
    std::string cubeMapDir;

public:
    Skybox(std::string cubeMapDir);
    void onSetup();
    void render(glm::mat4 viewMtx, glm::mat4 projectionMtx);
};

#endif