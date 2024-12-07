cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(geome3dash VERSION 1.0.0)

add_library(${PROJECT_NAME} SHARED
    Geome3Dash/dllmain.cpp
    Geome3Dash/pch.cpp
    Geome3Dash/src/BlockModelStorage.cpp
    Geome3Dash/src/CocosShaderProgram.cpp
    Geome3Dash/src/GameObjectModel.cpp
    Geome3Dash/src/game/component/G3DProgressBar.cpp
    Geome3Dash/src/game/component/G3DRainixPopup.cpp
    Geome3Dash/src/game/editor/G3DCameraKeyframeEditorLoader.cpp
    Geome3Dash/src/game/editor/G3DCameraKeyframeEditorPopup.cpp
    Geome3Dash/src/game/editor/G3DCurveEditorLoader.cpp
    Geome3Dash/src/game/editor/G3DCurveEditorPopup.cpp
    Geome3Dash/src/game/component/G3DComingSoonPopup.cpp
    Geome3Dash/src/game/planet/G3DPlanetPopup.cpp
    Geome3Dash/src/helper/CameraKeyframeBuffer.cpp
    Geome3Dash/src/helper/Easing.cpp
    Geome3Dash/src/engine/sus3d/Mesh.cpp
    Geome3Dash/src/engine/sus3d/Model.cpp
    Geome3Dash/src/engine/sus3d/Scene.cpp
    Geome3Dash/src/engine/sus3d/Shader.cpp
    Geome3Dash/src/engine/sus3d/ShaderProgram.cpp
    Geome3Dash/src/engine/sus3d/Shaders.cpp
    Geome3Dash/src/engine/sus3d/Texture.cpp
    Geome3Dash/src/game/component/G3DBaseNode.cpp
    Geome3Dash/src/game/component/G3DFragmentShaderLayer.cpp
    Geome3Dash/src/game/editor/G3DCameraEditorPopup.cpp
    Geome3Dash/src/game/component/G3DNumberSetting.cpp
    Geome3Dash/src/game/planet/G3DPlanetLayer.cpp
    Geome3Dash/src/game/playing/G3DPlayLayer.cpp
    Geome3Dash/src/helper/spline/Curve.cpp
    Geome3Dash/src/helper/spline/Spline.cpp
    Geome3Dash/src/hook/CCEGLView.cpp
    Geome3Dash/src/hook/CCKeyboardDispatcher.cpp
    Geome3Dash/src/hook/CCMouseDispatcher.cpp
    Geome3Dash/src/hook/CCTouchDispatcher.cpp
    Geome3Dash/src/hook/CreatorLayer.cpp
    Geome3Dash/src/hook/GameManager.cpp
    Geome3Dash/src/hook/LevelEditorLayer.cpp
    Geome3Dash/src/hook/MenuGameLayer.cpp
    Geome3Dash/src/hook/MenuLayer.cpp
    Geome3Dash/src/hook/PlayLayer.cpp
    Geome3Dash/src/LevelDataManager.cpp
    Geome3Dash/src/delegate/CustomKeyboard.cpp
    Geome3Dash/src/delegate/CustomMouse.cpp
    Geome3Dash/src/delegate/CustomTouch.cpp
    Geome3Dash/src/helper/CommonHelper.cpp
    Geome3Dash/src/helper/OpenGLStateHelper.cpp
    Geome3Dash/src/Geome3DashEntry.cpp
    Geome3Dash/src/LevelEditorImGui.cpp
    Geome3Dash/src/PlanetStateManager.cpp
    Geome3Dash/src/PlayerObjectModel.cpp
    Geome3Dash/src/transformer/AnimationGameObjectModelTransformer.cpp
    Geome3Dash/src/transformer/DefaultGameObjectModelTransformer.cpp
    Geome3Dash/src/transformer/FadeGameObjectModelTransformer.cpp
    Geome3Dash/src/transformer/GameObjectModelTransformer.cpp
    Geome3Dash/src/transformer/SplineCameraPlayerObjectModelTransformer.cpp
    Geome3Dash/src/transformer/SplineGameObjectTransformer.cpp
    Geome3Dash/src/transformer/SplinePlayerObjectTransformer.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    Geome3Dash
    Geome3Dash/src
    library/incl
    library/incl/glm
    library/incl/stb
    library/incl/nlohmann
)

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

set(BUILD_SHARED_LIBS OFF)
set(ASSIMP_BUILD_TESTS OFF)
set(ASSIMP_INSTALL OFF)
# set(ASSIMP_BUILD_ZLIB OFF)
set(ASSIMP_INSTALL_PDB OFF)
set(ASSIMP_INSTALL_PDB OFF)
set(ASSIMP_BUILD_ALL_EXPORTERS_BY_DEFAULT OFF)
set(ASSIMP_BUILD_ALL_IMPORTERS_BY_DEFAULT OFF)
set(ASSIMP_BUILD_OBJ_IMPORTER ON)
CPMAddPackage("gh:assimp/assimp#v5.4.3")

CPMAddPackage("gh:matcool/gd-imgui-cocos#0207a36")

target_link_libraries(${PROJECT_NAME} assimp imgui-cocos)

setup_geode_mod(${PROJECT_NAME})