#include "pch.h"

#include "game/play/G3DPlayLayer.h"
#include "manager/ModelManager.h"
#include "manager/LevelDataManager.h"

namespace g3d
{
    G3DPlayLayer* G3DPlayLayer::instance = nullptr;

    void G3DPlayLayer::loadGround()
    {
        // todo: add more ground types
        ground = GroundObjectModel(90.f, 40, 0, gameLayer, { &splineTr });
    }

    bool G3DPlayLayer::setup(PlayLayer* layer)
    {
        instance = this;
        fadeTr = GomtFade(layer, 700, 400, ease::InOutSine::get(), glm::vec3(0, 0, 0));
        animTr = GomtAnimation(&levelData.spline, &lengthScaleFactor);
        if (!G3DGameLayer::setup(layer)) { return false; }   
        loadGround();
        return true;
    }

    G3DPlayLayer::~G3DPlayLayer()
    {
        instance = nullptr;
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
                    blocks.push_back(GameObjectModel(obj, { &splineTr, &fadeTr, &animTr }));
                }
            }
        }
    }

    void G3DPlayLayer::drawBlocks()
    {
        for (auto& block : blocks) 
        { 
            auto distance = std::abs(gameLayer->m_player1->m_position.x - block.getGameObject()->getPositionX());
            auto maxRender = fadeTr.getMaxRender();
            if (distance < maxRender) { block.render(ModelManager::get()->getBlockSP(), camera, light); }
        }
    }


    void G3DPlayLayer::draw3d()
    {
        gameLayer->m_player1->getParent()->setVisible(false);
        gameLayer->m_groundLayer->setVisible(false);
        gameLayer->m_groundLayer2->setVisible(false);
        G3DGameLayer::draw3d();
        drawGround();
    }

    void G3DPlayLayer::drawGround() 
    {
        ground.render(ModelManager::get()->getBlockSP(), camera, light);
    }
}