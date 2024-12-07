#pragma once

#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Model.h"
#include "engine/sus3d/ShaderProgram.h"

namespace g3d
{ 
    class CloudMesh : public sus3d::Mesh 
    {
    public:
        float opacityModifier = 1.0f;
        ~CloudMesh() override = default;
        virtual bool init(aiMesh* mesh, aiMaterial* material) override;
        virtual void render(sus3d::ShaderProgram* shaderProgram) const override;
        static CloudMesh* create(aiMesh* mesh, aiMaterial* material);
    };
}