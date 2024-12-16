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
    inline void to_json(nlohmann::json& j, const vec3& v) 
    {
        j = nlohmann::json{ {"x", v.x}, {"y", v.y}, {"z", v.z} };
    }

    inline void from_json(const nlohmann::json& j, vec3& v) 
    {
        j.at("x").get_to(v.x);
        j.at("y").get_to(v.y);
        j.at("z").get_to(v.z);
    }
}

namespace sus3d 
{
    inline void to_json(nlohmann::json& j, const Curve& c) 
    {
        j = nlohmann::json{ {"p1", c.p1}, {"m1", c.m1}, {"p2", c.p2}, {"m2", c.m2} };
    }

    inline void from_json(const nlohmann::json& j, Curve& c) 
    {
        j.at("p1").get_to(c.p1);
        j.at("m1").get_to(c.m1);
        j.at("p2").get_to(c.p2);
        j.at("m2").get_to(c.m2);
    }

    inline void to_json(nlohmann::json& j, const Spline& s) 
    {
        j = nlohmann::json{ {"segments", s.segments} };
    }

    inline void from_json(const nlohmann::json& j, Spline& s) 
    {
        j.at("segments").get_to(s.segments);
    }
}
