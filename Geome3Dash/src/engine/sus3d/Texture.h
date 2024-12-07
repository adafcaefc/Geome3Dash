#pragma once

#include <Geode/cocos/platform/CCGL.h>

#include <string>
#include <filesystem>
#include <unordered_map>

namespace sus3d
{
    class Texture {
    private:
        static std::unordered_map<std::string, Texture*> loadedTextures;
    public:
        std::filesystem::path name;
        int width = 0;
        int height = 0;
        int nrChannels = 0;
        unsigned char* data = nullptr;
        GLuint textureID = 0;

        Texture() {}
        static Texture* load(const std::filesystem::path& filename);
        static Texture* getTextureByFilename(const std::filesystem::path& filename);
        static void cleanup();
    };
}
