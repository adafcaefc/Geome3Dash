#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <vector>
#include <array>
#include <glm/glm.hpp>

struct Material {
    glm::vec3 diffuse;
    glm::vec3 specular;
    glm::vec3 ambient;
    float shininess;
}; 

class Shape
{

public:
    Shape();

    void DrawShape();
    void SetVertices();

    Material material;

    int vertexCount;
    int textureDiffuseId;

    std::vector<float> vertices;

    void AddVertex(float px, float py, float pz,
                float nx, float ny, float nz,
                float tx, float ty);
private:
    
    unsigned int VAO;

    void loadModel(char* filePath);
};

#endif