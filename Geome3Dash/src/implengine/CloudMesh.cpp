#include "pch.h"

#include "CloudMesh.h"

namespace g3d
{
    static glm::vec3 calculateNormal(aiMesh* mesh, aiFace& face)
    {
        aiVector3D v0 = mesh->mVertices[face.mIndices[0]];
        aiVector3D v1 = mesh->mVertices[face.mIndices[1]];
        aiVector3D v2 = mesh->mVertices[face.mIndices[2]];

        glm::vec3 edge1(v1.x - v0.x, v1.y - v0.y, v1.z - v0.z);
        glm::vec3 edge2(v2.x - v0.x, v2.y - v0.y, v2.z - v0.z);

        glm::vec3 normal = glm::normalize(glm::cross(edge1, edge2));
        return normal;
    }

    static glm::vec3 calculateCentroid(aiMesh* mesh, aiFace& face)
    {
        aiVector3D v0 = mesh->mVertices[face.mIndices[0]];
        aiVector3D v1 = mesh->mVertices[face.mIndices[1]];
        aiVector3D v2 = mesh->mVertices[face.mIndices[2]];

        glm::vec3 centroid = glm::vec3(
            (v0.x + v1.x + v2.x) / 3.0f,
            (v0.y + v1.y + v2.y) / 3.0f,
            (v0.z + v1.z + v2.z) / 3.0f);

        return centroid;
    }

    bool CloudMesh::init(aiMesh* mesh, aiMaterial* material)
    {
        for (unsigned int i = 0; i < mesh->mNumVertices; i++)
        {
            vertices.push_back(mesh->mVertices[i].x);
            vertices.push_back(mesh->mVertices[i].y);
            vertices.push_back(mesh->mVertices[i].z);

            if (mesh->mTextureCoords[0])
            {
                vertices.push_back(mesh->mTextureCoords[0][i].x);
                vertices.push_back(mesh->mTextureCoords[0][i].y);
            }
            else
            {
                vertices.push_back(0.0f);
                vertices.push_back(0.0f);
            }

            vertices.push_back(mesh->mNormals[i].x);
            vertices.push_back(mesh->mNormals[i].y);
            vertices.push_back(mesh->mNormals[i].z);
        }

        glm::vec3 sphereCenter(0.0f, 0.0f, 0.0f);

        for (unsigned int i = 0; i < mesh->mNumFaces; i++)
        {
            aiFace face = mesh->mFaces[i];
            glm::vec3 normal = calculateNormal(mesh, face);
            glm::vec3 centroid = calculateCentroid(mesh, face);

            glm::vec3 centerDirection = glm::normalize(sphereCenter - centroid);

            // Compare face normal with the direction to the center
            float dot = glm::dot(normal, centerDirection);

            // Face points towards the center
            // Skip this face
            if (std::abs(dot) < 0.9f) { continue; }

            for (unsigned int j = 0; j < face.mNumIndices; j++)
            {
                indices.push_back(face.mIndices[j]);
            }
        }

        initBuffers(material);


        return true;
    }

    void CloudMesh::render(sus3d::ShaderProgram* shaderProgram) const
    {
        // custom renderer just to set the d value
        if (visible)
        {
            glBindVertexArray(VAO);
            glEnable(GL_DEPTH_TEST);
            glEnable(GL_BLEND);
            glEnable(GL_BLEND_COLOR);
            if (useTexture)
                glBindTexture(GL_TEXTURE_2D, texture);
            shaderProgram->setInt("isTexture", int(useTexture));
            shaderProgram->setVec3("Ka", isCustomKa ? customKa : Ka);
            shaderProgram->setVec3("Kd", isCustomKd ? customKd : Kd);
            shaderProgram->setVec3("Ks", isCustomKs ? customKs : Ks);
            shaderProgram->setFloat("shininess", 32);
            shaderProgram->setFloat("d", (isCustomD ? customD : d) * opacityModifier);
            glDrawElements(GL_TRIANGLES, static_cast<int>(indices.size()), GL_UNSIGNED_INT, NULL);
            glBindVertexArray(0);
            glDisable(GL_DEPTH_TEST);
            glDisable(GL_BLEND);
            glDisable(GL_BLEND_COLOR);
        }
    }

    CloudMesh* CloudMesh::create(aiMesh* mesh, aiMaterial* material) 
    {
        auto ret = new CloudMesh();
        if (!ret || !ret->init(mesh, material)) 
        {
            delete ret;
            return nullptr;
        }
        return ret;
    }
}