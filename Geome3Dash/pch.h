#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Geode/cocos/platform/CCGL.h>

#include <matjson.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <Geode/ui/ScrollLayer.hpp>
#include <Geode/ui/Scrollbar.hpp>
#include <Geode/ui/TextInput.hpp>
#include <Geode/utils/cocos.hpp>
using namespace cocos2d;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>

#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

// --- pre-load some stuff in pch ---

#include "engine/sus3d/ShaderProgram.h"
#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Texture.h"
#include "engine/sus3d/Model.h"
#include "engine/sus3d/Scene.h"
#include "engine/sus3d/Shaders.h"
#include "engine/sus3d/spline/Curve.h"
#include "engine/sus3d/spline/Spline.h"

#include "delegate/CustomKeyboard.h"
#include "delegate/CustomMouse.h"
#include "delegate/CustomTouch.h"

// --- pre-load some stuff in pch ---

namespace glm 
{
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(vec3, x, y, z);
}

namespace sus3d 
{
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Curve, p1, m1, p2, m2);
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Spline, segments);
}
