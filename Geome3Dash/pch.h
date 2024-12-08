#pragma once

#define GEODE_MOD_ID "rainixgd.geome3dash"
#define GEODE_COMP_GD_VERSION 22074
#define MAT_JSON_DYNAMIC 0

#define WIN32_LEAN_AND_MEAN

#include <pugixml.hpp>
#include <CCGL.h>

#include <matjson.hpp>
#include <Geode/external/result/result.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <Geode/ui/ScrollLayer.hpp>
#include <Geode/ui/Scrollbar.hpp>
#include <Geode/ui/TextInput.hpp>
#include <Geode/utils/cocos.hpp>
#include <gd.h>
using namespace cocos2d;

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>

#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <Windows.h>
#include <fstream>
#include <string>
#include <filesystem>
#include <memory>

// --- pre-load some stuff in pch ---

#include "engine/sus3d/ShaderProgram.h"
#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Texture.h"
#include "engine/sus3d/Model.h"
#include "engine/sus3d/Scene.h"
#include "engine/sus3d/Shaders.h"

#include "delegate/CustomKeyboard.h"
#include "delegate/CustomMouse.h"
#include "delegate/CustomTouch.h"

// --- pre-load some stuff in pch ---

