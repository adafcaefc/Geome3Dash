#pragma once

#include <CCGL.h>

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
        int width;
        int height;
        int nrChannels;
        unsigned char* data;
        GLuint textureID = 0;

        Texture() {}
        static Texture* load(const std::filesystem::path& filename);
        static Texture* getTextureByFilename(const std::filesystem::path& filename);
        static void cleanup();
    };
}
