#include "pch.h"
#include "pch.h"

#include "game/playing/G3DPlayLayer.h"
#include "LevelDataManager.h"
#include "BlockModelStorage.h"

namespace g3d
{
    G3DPlayLayer* G3DPlayLayer::instance = nullptr;

    void G3DPlayLayer::loadShader()
    {
        shaderProgram = dynamic_cast<CocosShaderProgram*>(BlockModelStorage::get()->getBlockSP());
    }

    void G3DPlayLayer::loadPlayers()
    {
        player1 = PlayerObjectModel(playLayer->m_player1, { splinePlayerTr, splineCamTr });
        player2 = PlayerObjectModel(playLayer->m_player2, { splinePlayerTr });
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
            
        groundModel = BlockModelStorage::get()->getModel(BlockModelStorage::get()->getBP() / "environment" / "ground" / "0" / "model.obj");

        loadShader();
        loadPlayers();
        loadBlocks();

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
                if (auto model = BlockModelStorage::get()->getBlockModel(obj->m_objectID))
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
            if (distance < maxRender) { block.render(shaderProgram, camera, light); }
        }
    }

    void G3DPlayLayer::drawPlayers()
    {
        player1.render(shaderProgram, camera, light);
        if (playLayer->m_gameState.m_isDualMode) { player2.render(shaderProgram, camera, light); }
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
            renderGround();
            drawBlocks();
        }
        catch (...) {

        }

        glDisable(GL_DEPTH_TEST);
        OpenGLStateHelper::pushState();
    }

    void G3DPlayLayer::renderGround() {
        glm::vec3 groundSize = glm::vec3(0.5 * lengthScaleFactor * 30 * 3);

        auto playerData = levelData.spline.findClosestByLength(playLayer->m_player1->getPositionX() * lengthScaleFactor);

        const int groundPartsForRender = 30;

        for (float l = 0; l < playerData.l + groundSize.x * groundPartsForRender; l += groundSize.x * 2) {

            if (l < playerData.l - groundSize.x * groundPartsForRender) continue;

            auto groundData = levelData.spline.findClosestByLength(l);

            auto normal = glm::normalize(levelData.spline.normal(groundData.t));
            auto tangent = glm::normalize(levelData.spline.tangent(groundData.t));


            glm::vec3 binormal = glm::normalize(glm::cross(normal, tangent));
            glm::vec3 adjustedNormal = glm::normalize(glm::cross(tangent, binormal));


            glm::mat3 rotationMatrix(
                binormal,
                adjustedNormal,
                tangent
            );

            glm::quat rotationQuat = glm::quat_cast(rotationMatrix);
            glm::vec3 eulerDegrees = glm::degrees(glm::eulerAngles(rotationQuat));

            groundModel->setRotation(eulerDegrees);

            groundModel->setPosition(groundData.value - normal * groundSize * 1.5f);
            groundModel->setScale(groundSize);

            
            if (auto gsprites = this->playLayer->getChildByIDRecursive("ground-sprites"))
            {
                if (auto grounds = gsprites->getChildByType<CCSprite>(0))
                {
                    if (auto ground = grounds->getChildByType<CCSprite>(0))
                    {
                        auto color = ground->getColor();
                        for (auto& mesh : groundModel->meshes)
                        {
                            mesh->setCustomKa(glm::vec3(color.r, color.g, color.b) * glm::vec3(1.f / 255.f));
                        }
                    }
                }
            }

            groundModel->render(shaderProgram, camera.getViewMat(), light.getPosition(), light.getColor(), camera.getPosition(), camera.getProjectionMat());

            for (auto& mesh : groundModel->meshes)
            {
                mesh->disableKa();
            }
        }
    }
}