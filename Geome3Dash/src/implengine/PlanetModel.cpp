#include "pch.h"

#include "PlanetModel.h"

namespace g3d
{
    glm::mat4 PlanetModel::prepareModelMatrix()
    {
        glm::mat4 model = glm::mat4(1.0f);

        model = glm::translate(model, position);

        // Apply rotations (Z, Y, X in this order)
        if (rotation.z != 0.0f) 
            model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));  
        if (rotation.y != 0.0f) 
            model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)); 
        if (rotation.x != 0.0f)  
            model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)); 

        model = glm::scale(model, scale);

        return model;
    }

    PlanetModel* PlanetModel::create(const aiScene* scene) 
    {
        PlanetModel* ret = new PlanetModel();
        if (!ret || !ret->init(scene)) 
        {
            delete ret;
            return nullptr;
        }
        return ret;
    }
}