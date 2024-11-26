#pragma once

#include <string>
#include <filesystem>

namespace sus3d
{
    class Texture {
    private:
        static std::vector<Texture*> loadedTextures;
    public:
        std::filesystem::path name;
        int width;
        int height;
        int nrChannels;
        unsigned char* data;

        Texture() {}
        static Texture* load(const std::filesystem::path& filename);
        static Texture* getTextureByFilename(const std::filesystem::path& filename);
    };
}
