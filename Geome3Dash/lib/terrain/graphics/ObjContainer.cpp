#include <stdio.h>
#include <string>
#include <iostream>
#include <unordered_map>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "external_files/tiny_obj_loader.h"
#include "external_files/stb_image.h"
#include "graphics/ObjContainer.h"
#include "utils/FileUtils.h"
#include "graphics/Shape.h"
#include "graphics/Shader.h"

ObjContainer::ObjContainer(char* objFilePath) {    
    this->maxExtents = glm::vec3(-FLT_MAX,-FLT_MAX,-FLT_MAX);
    this->minExtents = glm::vec3( FLT_MAX, FLT_MAX, FLT_MAX);
    this->FilePath = objFilePath;
    this->loadModel(objFilePath);    
}

// OBJ { SHAPES { VERTICES 

void ObjContainer::loadModel(char* objFilePath) {
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string base_dir = GetBaseDir(objFilePath);
    if (base_dir.empty()) {
        base_dir = ".";
    }
    base_dir += "/";

    std::string err;
    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &err, objFilePath, base_dir.c_str());

    if (!err.empty()) { // `err` may contain warning message.
        std::cerr << err << std::endl;
    }

    if (!ret) {
        exit(1);
    }
 
    // Loop over shapes
    for (size_t s = 0; s < shapes.size(); s++) {
        Shape currShape;
        // Loop over faces(polygon)
        size_t index_offset = 0;
        for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
            int fv = shapes[s].mesh.num_face_vertices[f];
            // Loop over vertices in the face.
            // Assumed 3 vertices to a FACE
            for (size_t v = 0; v < fv; v++) {
                // access to vertex
                tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
                tinyobj::real_t vx = attrib.vertices[3*idx.vertex_index+0];
                tinyobj::real_t vy = attrib.vertices[3*idx.vertex_index+1];
                tinyobj::real_t vz = attrib.vertices[3*idx.vertex_index+2];
                tinyobj::real_t nx = attrib.normals[3*idx.normal_index+0];
                tinyobj::real_t ny = attrib.normals[3*idx.normal_index+1];
                tinyobj::real_t nz = attrib.normals[3*idx.normal_index+2];
                tinyobj::real_t tx = 0;
                tinyobj::real_t ty = 0;
                if(idx.texcoord_index != -1) {
                    tx = attrib.texcoords[2*idx.texcoord_index+0];
                    ty = attrib.texcoords[2*idx.texcoord_index+1];
                }
                // // Optional: vertex colors
                // tinyobj::real_t red = attrib.colors[3*idx.vertex_index+0];
                // tinyobj::real_t green = attrib.colors[3*idx.vertex_index+1];
                // tinyobj::real_t blue = attrib.colors[3*idx.vertex_index+2];

                checkMaxExtents(vx,vy,vz);
                checkMinExtents(vx,vy,vz);

                currShape.AddVertex(vx,vy,vz,nx,ny,nz,tx,ty);
            }
            index_offset += fv;
        }
        // Set material attributes for shape
        int matId = shapes[s].mesh.material_ids[0];
        currShape.material.diffuse.x = materials[matId].diffuse[0];
        currShape.material.diffuse.y = materials[matId].diffuse[1];
        currShape.material.diffuse.z = materials[matId].diffuse[2];
        currShape.material.specular.x = materials[matId].specular[0];
        currShape.material.specular.y = materials[matId].specular[1];
        currShape.material.specular.z = materials[matId].specular[2];
        currShape.material.ambient.x = materials[matId].ambient[0];
        currShape.material.ambient.y = materials[matId].ambient[1];
        currShape.material.ambient.z = materials[matId].ambient[2];
        currShape.material.shininess = materials[matId].shininess;
        std::string diffuseTexname = materials[matId].diffuse_texname;
        if (diffuseTexname.size() > 0) {
            currShape.textureDiffuseId = this->loadTexture(base_dir + diffuseTexname);
        }
        currShape.SetVertices();
        this->shapes.push_back(currShape);
    }
}

int ObjContainer::loadTexture(std::string texture_filename) {
    GLuint texture_id;
    int w, h;
    int comp;

    if (!FileExists(texture_filename)) {
        // Append base dir.
        std::cerr << "Unable to find file: " << texture_filename << std::endl;        
    }

    unsigned char* image = stbi_load(texture_filename.c_str(), &w, &h, &comp, STBI_default);
    if (!image) {
        std::cerr << "Unable to load texture: " << texture_filename << std::endl;
    }

    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if (comp == 3) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    } else if (comp == 4) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    } else {
    }
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(image);
    return texture_id;
}

void ObjContainer::checkMaxExtents(float x, float y, float z) {
    if (x > maxExtents.x)
        maxExtents.x = x;
    if (y > maxExtents.y)
        maxExtents.y = y;
    if (z > maxExtents.z)
        maxExtents.z = z;    
}

void ObjContainer::checkMinExtents(float x, float y, float z) {
    if (x < minExtents.x)
        minExtents.x = x;
    if (y < minExtents.y)
        minExtents.y = y;
    if (z < minExtents.z)
        minExtents.z = z;
}

float ObjContainer::GetBiggestLength() {
    float width = maxExtents.x - minExtents.x;
    float height = maxExtents.y - minExtents.y;
    float depth = maxExtents.z - minExtents.z;

    if (width > height && width > depth)
        return width;
    else if (height > width && height > depth)
        return height;
    else
        return depth;
}

glm::vec3 ObjContainer::GetObjSize() {
    float x = maxExtents.x - minExtents.x;
    float y = maxExtents.y - minExtents.y;
    float z = maxExtents.z - minExtents.z;
    return glm::vec3(x,y,z);
}

glm::vec3 ObjContainer::GetOffsetCenter() {
    glm::vec3 objSize = this->GetObjSize();
    float x = maxExtents.x - (objSize.x / 2.0f);
    float y = maxExtents.y - (objSize.y / 2.0f);// + 1; // Aligned by bottom
    float z = maxExtents.z - (objSize.z / 2.0f);
    return glm::vec3(x,y,z);
}
