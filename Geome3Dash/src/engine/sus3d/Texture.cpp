#include "Texture.h"

#include <stb_image.h>

#include <Geode/cocos/platform/CCGL.h>

#include <unordered_map>

#ifdef GEODE_IS_ANDROID
struct GLFWwindow {};
#include <algorithm>
#define GL_RED 0x1903
#define GL_COMPRESSED_RED 0x8225
#define GL_COMPRESSED_RG 0x8226
#define GL_RG 0x8227
#define GL_RG_INTEGER 0x8228
#define GL_R8 0x8229
#define GL_R16 0x822A
#define GL_RG8 0x822B
#define GL_RG16 0x822C
#define GL_R16F 0x822D
#define GL_R32F 0x822E
#define GL_RG16F 0x822F
#define GL_RG32F 0x8230
#define GL_R8I 0x8231
#define GL_R8UI 0x8232
#define GL_R16I 0x8233
#define GL_R16UI 0x8234
#define GL_R32I 0x8235
#define GL_R32UI 0x8236
#define GL_RG8I 0x8237
#define GL_RG8UI 0x8238
#define GL_RG16I 0x8239
#define GL_RG16UI 0x823A
#define GL_RG32I 0x823B
#define GL_RG32UI 0x823C
#define GL_ALPHA_TEST 0x0BC0
#endif

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