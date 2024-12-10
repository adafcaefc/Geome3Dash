#include "pch.h"
#include "pch.h"

#include "game/play/AG3DGameLayer.h"
#include "manager/ModelManager.h"
#include "manager/LevelDataManager.h"

namespace g3d
{
    void AG3DGameLayer::loadPlayers()
    {
        this->player1 = PlayerObjectModel(gameLayer->m_player1, { &splinePlayerTr, &splineCamTr });
        this->player2 = PlayerObjectModel(gameLayer->m_player2, { &splinePlayerTr });
    }

    bool AG3DGameLayer::setup(GJBaseGameLayer* layer)
    {
        if (!CCNode::init()) { return false; }

        this->gameLayer = layer;
        this->levelData = LevelData::getDefault();

        try { levelData = getLevelData(gameLayer); } catch (...) { }

        prepareSpline(gameLayer, &levelData.spline, &lengthScaleFactor);
        setStartingKeyframe(&levelData, &levelData.keyframe, lengthScaleFactor);

        splineTr = GomtSpline(&levelData.spline, &lengthScaleFactor);
        splinePlayerTr = PomtSpline(&levelData.spline, &lengthScaleFactor);

        static bool isEditing = false;
        splineCamTr = PomtSplineCamera(
            &levelData.spline, 
            &levelData.keyframe,
            &camera,
            &light,
            &lengthScaleFactor,
            &isEditing);
   
        loadBlocks();
        loadPlayers();

        return true;
    }

    AG3DGameLayer::~AG3DGameLayer()
    {

    }

    void AG3DGameLayer::loadBlocks()
    {
        CCObject* objP = nullptr;
        CCARRAY_FOREACH(gameLayer->m_objects, objP)
        {
            if (auto obj = dynamic_cast<GameObject*>(objP))
            {
                if (obj == gameLayer->m_anticheatSpike) { continue; }
                if (auto model = ModelManager::get()->getBlockModel(obj->m_objectID))
                {
                    blocks.push_back(GameObjectModel(obj, { &splineTr }));
                }
            }
        }
    }

    void AG3DGameLayer::drawBlocks()
    {
        auto sp = ModelManager::get()->getBlockSP();
        for (auto& block : blocks) { block.render(sp, camera, light); }
    }

    void AG3DGameLayer::drawPlayers()
    {
        auto sp = ModelManager::get()->getBlockSP();
        player1.render(sp, camera, light);
        if (gameLayer->m_gameState.m_isDualMode) { player2.render(sp, camera, light); }
    }

    void AG3DGameLayer::saveOpenGL()
    {
        OpenGLStateHelper::saveState();
        glEnable(GL_BLEND);
        glEnable(GL_ALPHA_TEST);
        glEnable(GL_DEPTH_TEST);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    void AG3DGameLayer::loadOpenGL()
    {
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_BLEND);
        glDisable(GL_BLEND_COLOR);
        OpenGLStateHelper::pushState();
    }

    void AG3DGameLayer::draw3d()
    {
        drawPlayers();
        drawBlocks();
    }

    void AG3DGameLayer::draw()
    {
        CCNode::draw();
        saveOpenGL();
        try { this->draw3d(); } catch (...) {  }
        loadOpenGL();
    }
}