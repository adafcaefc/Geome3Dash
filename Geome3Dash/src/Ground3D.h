#pragma once

namespace g3d
{
    class Model;
    class ShaderScene;
    class ShaderProgram;

    class Ground3D {
        std::vector<Model*> parts;
        float startOffset = -200;
        float size = 3;
        float partsCount = 50;
        float playerPositionX;
        float groundHeight;
        bool flipGroundModel = 0;

        virtual bool init(CCNode* layer, ShaderProgram* shaderProgram);
    public:
        void updateGround();
        void resetGround();
        void setVisible(bool visible);
        void updateYPos(float playLayerSecondGroundHeight);
        static Ground3D* create(CCNode* layer, ShaderProgram* shaderProgram, float startOffset, float size, float partsCount, float groundHeight, bool flipGroundModel);
    };
}