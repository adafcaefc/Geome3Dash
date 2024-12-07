#pragma once

#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Model.h"
#include "engine/sus3d/ShaderProgram.h"

namespace g3d
{
    class PlanetModel : public sus3d::Model 
    {
    public:
        sus3d::ShaderProgram* shaderProgram = nullptr;
        ~PlanetModel() override = default;
        glm::mat4 prepareModelMatrix() override;
        static PlanetModel* create(const aiScene* scene);
    };
}