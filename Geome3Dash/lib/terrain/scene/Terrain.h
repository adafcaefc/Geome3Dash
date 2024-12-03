#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#include <vector>
#include <glm/glm.hpp>
#include "graphics/ObjContainer.h"
#include "graphics/Shader.h"
#include "graphics/Viewer.h"
#include "scene/SceneComponent.h"

struct shape_terrain
{
    unsigned int VAO;   
    unsigned int vCount;   
};

// Repsonsible For Tracking the players movements
class Terrain : public SceneComponent
{
private:
    // Terrain properties
    glm::vec3 terrainLocation;
    glm::vec3 terrainSize;
    glm::vec3 minLimits;
    glm::vec3 maxLimits;
    glm::ivec3 gridCount; 

    const float waveFreqX = 0.2;
    const float waveFreqZ = 0.2;

    Shader* shader;
    // Vertices
    std::vector<shape_terrain> shapes;
    void AddVertex(std::vector<float> *verts, int x, int z);
    void finishShape(std::vector<float> verts);
        
public:
    Terrain(glm::vec3 terrainLocation, glm::vec3 terrainSize, glm::ivec3 gridCount);
    void onSetup();
    void render(glm::mat4 viewMtx, glm::mat4 projectionMtx);
    float CalculateTerrainHeight(float x, float z);
};

#endif