#pragma once

namespace g3d
{
    class Texture {
    private:
        static std::vector<Texture*> loadedTextures;
    public:
        std::string name;
        int width;
        int height;
        int nrChannels;
        unsigned char* data;

        Texture() {}
        static Texture* load(std::string filename);
        static Texture* getTextureByFilename(std::string filename);
    };
}
