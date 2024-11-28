#pragma once

#define GEODE_MOD_ID "rainixgd.geome3dash"
#define GEODE_COMP_GD_VERSION 22074
#define MAT_JSON_DYNAMIC 0

#define WIN32_LEAN_AND_MEAN

#include <pugixml.hpp>
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

