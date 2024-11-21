#include "pch.h"
#include "Texture.h"
#include <stb_image.h>

namespace g3d
{
    Texture* Texture::load(std::string filename) {
        std::cout << "loading new texture" << std::endl;
        std::cout << loadedTextures.size() << std::endl;
        Texture* texture = new Texture();
        texture->name = filename;

        // free this?
        texture->data = stbi_load(filename.c_str(), &texture->width, &texture->height, &texture->nrChannels, 0);
        if (!texture->data) {
            std::cout << "Texture not found: " << filename << std::endl;
            return nullptr;
        }
        else {
            loadedTextures.push_back(texture);
            return texture;
        }
    }
    Texture* Texture::getTextureByFilename(std::string filename) {
        std::cout << filename << std::endl;
        for (auto texture : loadedTextures) {
            if (texture->name == filename)
                return texture;
        }
        return load(filename);
    }

    std::vector<Texture*> Texture::loadedTextures = {};
}