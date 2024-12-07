#include "pch.h"
#include "pch.h"

#include "game/play/G3DPlayLayer.h"
#include "manager/ModelManager.h"
#include "manager/LevelDataManager.h"

namespace g3d
{
    G3DPlayLayer* G3DPlayLayer::instance = nullptr;

    void G3DPlayLayer::loadPlayers()
    {
        player1 = PlayerObjectModel(playLayer->m_player1, { splinePlayerTr, splineCamTr });
        player2 = PlayerObjectModel(playLayer->m_player2, { splinePlayerTr });
    }

    void G3DPlayLayer::loadGround()
    {
        ground = GroundObjectModel(90.f, 30, 0, playLayer, { splineTr });
    }

    bool G3DPlayLayer::init()
    {
        CCNode::init();

        playLayer = GameManager::sharedState()->m_playLayer;

        levelData = LevelData::getDefault();

        try { levelData = getLevelData(playLayer); } catch (...) { }

        prepareSpline(playLayer, &levelData.spline, &lengthScaleFactor);
        setStartingKeyframe(&levelData, &levelData.keyframe, lengthScaleFactor);

        fadeTr = new GomtFade(playLayer, 700, 400, ease::InOutSine::get(), glm::vec3(0, 0, 0));
        animTr = new GomtAnimation(&levelData.spline, &lengthScaleFactor);
        splineTr = new GomtSpline(&levelData.spline, &lengthScaleFactor);
        splinePlayerTr = new PomtSpline(&levelData.spline, &lengthScaleFactor);
        static bool isEditing = false;
        splineCamTr = new PomtSplineCamera(
            &levelData.spline, 
            &levelData.keyframe,
            &camera,
            &light,
            &lengthScaleFactor,
            &isEditing);
   
        loadBlocks();
        loadPlayers();
        loadGround();

        return true;
    }

    G3DPlayLayer::~G3DPlayLayer()
    {
        instance = nullptr;
        delete fadeTr;
        delete animTr;
        delete splineTr;
        delete splinePlayerTr;
        delete splineCamTr;
    }

    void G3DPlayLayer::loadBlocks()
    {
        auto playLayer = GameManager::sharedState()->m_playLayer;
        CCObject* objxx = nullptr;
        CCARRAY_FOREACH(playLayer->m_objects, objxx)
        {
            if (auto obj = dynamic_cast<GameObject*>(objxx))
            {
                if (obj == playLayer->m_anticheatSpike) { continue; }
                if (auto model = ModelManager::get()->getBlockModel(obj->m_objectID))
                {
                    blocks.push_back(GameObjectModel(obj, { splineTr, fadeTr, animTr }));
                }
            }
        }
    }

    void G3DPlayLayer::drawBlocks()
    {
        for (auto& block : blocks) 
        { 
            auto distance = std::abs(playLayer->m_player1->m_position.x - block.getGameObject()->getPositionX());
            auto maxRender = fadeTr->getMaxRender();
            if (distance < maxRender) { block.render(ModelManager::get()->getBlockSP(), camera, light); }
        }
    }

    void G3DPlayLayer::drawPlayers()
    {
        player1.render(ModelManager::get()->getBlockSP(), camera, light);
        if (playLayer->m_gameState.m_isDualMode) { player2.render(ModelManager::get()->getBlockSP(), camera, light); }
    }

    void G3DPlayLayer::draw()
    {
        CCNode::draw();

        playLayer->m_player1->getParent()->setVisible(false);
        playLayer->m_groundLayer->setVisible(false);
        playLayer->m_groundLayer2->setVisible(false);


        OpenGLStateHelper::saveState();
        glEnable(GL_BLEND);
        glEnable(GL_ALPHA_TEST);
        glEnable(GL_DEPTH_TEST);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        try {
            drawPlayers();
            drawBlocks();
            drawGround();
        }
        catch (...) {

        }

        glDisable(GL_DEPTH_TEST);
        OpenGLStateHelper::pushState();
    }

    void G3DPlayLayer::drawGround() 
    {
        ground.render(ModelManager::get()->getBlockSP(), camera, light);
    }
}