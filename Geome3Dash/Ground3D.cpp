#include "pch.h"
#include "Ground3D.h"
#include "Model.h"
#include "ShaderScene.h"

namespace g3d
{
    bool Ground3D::init(ShaderScene* layer, ShaderProgram* shaderProgram) {

        for (int i = 0; i < partsCount; i++) {
            auto groundPart = layer->loadAndAddModel("./models/ground/model.obj", shaderProgram);
            groundPart->setScale(glm::vec3(size, size * (flipGroundModel ? -1 : 1), size));
            groundPart->setPosition(glm::vec3(size * 2 * i + startOffset, groundHeight + 3 * 2 - size - 0.75, 20));
            parts.push_back(groundPart);
        }
        playerPositionX = GameManager::sharedState()->m_playLayer->m_player1->getPositionX() * 0.05;

        return true;
    }

    void Ground3D::updateGround() {
        if (GameManager::sharedState()->m_playLayer->m_player1->getPositionX() * 0.05 - playerPositionX > size * 2) {
            for (auto ground : parts) {
                ground->setPositionX(ground->getPositionX() + (GameManager::sharedState()->m_playLayer->m_player1->getPositionX() * 0.05 - playerPositionX));
            }
            playerPositionX = GameManager::sharedState()->m_playLayer->m_player1->getPositionX() * 0.05;
        }
    }

    void Ground3D::updateYPos(float playLayerSecondGroundHeight) {
        for (auto ground : parts) {
            ground->setPositionY(groundHeight + 1.5 * (playLayerSecondGroundHeight + 60) / 30 + 3 * 2 - size - 0.75);
        }
    }

    void Ground3D::setVisible(bool visible) {
        for (auto ground : parts) {
            ground->setVisible(visible);
        }
    }

    void Ground3D::resetGround() {
        int i = 0;
        for (auto ground : parts) {
            ground->setPosition(glm::vec3(size * 2 * i + startOffset, groundHeight - size - 0.75, 20));
            i++;
        }
        playerPositionX = GameManager::sharedState()->m_playLayer->m_player1->getPositionX() * 0.05;
    }

    Ground3D* Ground3D::create(ShaderScene* layer, ShaderProgram* shaderProgram, float startOffset, float size, float partsCount, float groundHeight, bool flipGroundModel) {
        auto ret = new Ground3D();
        ret->startOffset = startOffset;
        ret->size = size;
        ret->partsCount = partsCount;
        ret->groundHeight = groundHeight;
        ret->flipGroundModel = flipGroundModel;
        if (!ret || !ret->init(layer, shaderProgram)) {
            return nullptr;
        }
        return ret;
    }
}