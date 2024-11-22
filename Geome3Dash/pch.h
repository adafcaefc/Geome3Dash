#pragma once

#define GEODE_MOD_ID "rainixgd.geome3dash"
#define GEODE_COMP_GD_VERSION 22007
#define MAT_JSON_DYNAMIC 0

#define WIN32_LEAN_AND_MEAN

#include <CCGL.h>

#include <matjson.hpp>
#include <Geode/external/result/result.hpp>
#include <gd.h>

#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <Windows.h>
#include <fstream>
#include <string>
#include <filesystem>

using namespace cocos2d;

struct VertexIndex {
    unsigned int positionIndex;
    unsigned int texCoordIndex;
    unsigned int normalIndex;
};

struct Face {
    std::vector<VertexIndex> vertecies;
};

struct TriangleFace {
    std::array<VertexIndex, 3> vertecies;
public:
    TriangleFace(VertexIndex v1, VertexIndex v2, VertexIndex v3) {
        vertecies[0] = v1;
        vertecies[1] = v2;
        vertecies[2] = v3;
    }
};

struct Material {
    std::string name;
    int illum;
    glm::vec3 Kd;
    glm::vec3 Ke;
    float Pr;
    float Pm;
    float d;
    float Tr;
    std::string map_Kd;
};