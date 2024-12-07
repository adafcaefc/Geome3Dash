#include "pch.h"

#include "CloudModel.h"
#include "CloudMesh.h"

namespace g3d
{
    void CloudModel::setCloudOpacity(const float op)
    {
        for (auto& mesh : meshes)
        {
            if (auto cloudMesh = dynamic_cast<CloudMesh*>(mesh))
            {
                cloudMesh->opacityModifier = op;
            }
        }
    }

    bool CloudModel::init(const aiScene* scene)
    {
        for (unsigned int i = 0; i < scene->mNumMeshes; ++i)
        {
            sus3d::Mesh* mesh = CloudMesh::create(
                scene->mMeshes[i],
                scene->mMaterials[scene->mMeshes[i]->mMaterialIndex]);
            meshes.push_back(mesh);
        }

        return true;
    }

    CloudModel* CloudModel::create(const aiScene* scene) 
    {
        CloudModel* ret = new CloudModel();
        if (!ret || !ret->init(scene)) 
        {
            delete ret;
            return nullptr;
        }
        return ret;
    }
}