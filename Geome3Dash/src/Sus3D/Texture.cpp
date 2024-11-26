#include "Texture.h"

#include <stb_image.h>

#include <CCGL.h>

#include <unordered_map>

namespace sus3d
{
    Texture* Texture::getTextureByFilename(const std::filesystem::path& filename) {
        auto it = loadedTextures.find(filename.string());
        if (it != loadedTextures.end()) {
            return it->second; 
        }

        return load(filename);
    }

    void Texture::cleanup() {
        for (auto& pair : loadedTextures) {
            stbi_image_free(pair.second->data);
            delete pair.second;
        }
        loadedTextures.clear();
    }

    Texture* Texture::load(const  std::filesystem::path& filename) {
        if (loadedTextures.find(filename.string()) != loadedTextures.end()) {
            return loadedTextures[filename.string()];
        }

        Texture* texture = new Texture();
        texture->name = filename;

        texture->data = stbi_load(filename.string().c_str(), &texture->width, &texture->height, &texture->nrChannels, 0);
        if (!texture->data) {
            delete texture;
            return nullptr;
        }

        glGenTextures(1, &texture->textureID);
        glBindTexture(GL_TEXTURE_2D, texture->textureID);
        GLenum format = (texture->nrChannels == 1) ? GL_RED :
            (texture->nrChannels == 3) ? GL_RGB : GL_RGBA;
        glTexImage2D(GL_TEXTURE_2D, 0, format, texture->width, texture->height, 0, format, GL_UNSIGNED_BYTE, texture->data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glBindTexture(GL_TEXTURE_2D, 0);

        loadedTextures[filename.string()] = texture;
        return texture;
    }

    std::unordered_map<std::string, Texture*> Texture::loadedTextures = {};
}