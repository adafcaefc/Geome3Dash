#pragma once

#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Model.h"
#include "engine/sus3d/ShaderProgram.h"

#include "PlanetModel.h"

namespace g3d
{
    class CloudModel : public PlanetModel 
    {
    public:
        ~CloudModel() override = default;
        virtual bool init(const aiScene* scene) override;
        static CloudModel* create(const aiScene* scene);
        virtual void setCloudOpacity(const float op);
    };
}