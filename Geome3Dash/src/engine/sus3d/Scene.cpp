#include "Scene.h"

#include "ShaderProgram.h"
#include "Model.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <glm/glm/gtc/matrix_transform.hpp>

#include <CCGL.h>

namespace sus3d
{
    glm::mat4 Camera::getViewMat() { return glm::lookAt(position, position + front, up); }
    glm::mat4 Camera::getProjectionMat() { return glm::perspective(glm::radians(fov), (float)1920 / float(1080), 0.1f, 6000.0f); }
}