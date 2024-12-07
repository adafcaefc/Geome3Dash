cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(geome3dash VERSION 1.0.0)

file(GLOB_RECURSE SOURCES Geome3Dash/src/*.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCES} Geome3Dash/pch.cpp)

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