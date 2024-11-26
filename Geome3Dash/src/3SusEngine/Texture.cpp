#include "Texture.h"

#include <stb_image.h>

namespace sus3d
{
    Texture* Texture::load(const std::filesystem::path& filename) {
        Texture* texture = new Texture();
        texture->name = filename;

        // free this?
        texture->data = stbi_load(texture->name.string().c_str(), &texture->width, &texture->height, &texture->nrChannels, 0);
        if (!texture->data) {
            return nullptr;
        }
        else {
            loadedTextures.push_back(texture);
            return texture;
        }
    }
    Texture* Texture::getTextureByFilename(const std::filesystem::path& filename) {
        for (auto texture : loadedTextures) {
            if (texture->name == filename)
                return texture;
        }
        return load(filename);
    }

    std::vector<Texture*> Texture::loadedTextures = {};
}