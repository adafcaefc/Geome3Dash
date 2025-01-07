#include "pch.h"

#include "AnimatedModel.h"

#include "helper/CommonHelper.h"
#include "manager/ModelManager.h"

namespace g3d
{
    bool AnimatedModelNode::setup(const std::filesystem::path& base) {
        if (!CCNode::init()) { return false; }
        this->basePath = base;
        std::cout << "AnimatedModelInner path : " << basePath.string() << '\n';
        this->fps = std::stof(utils::read_from_file(base / "fps.txt"));
        size_t indexFrame = 0u;
        const auto getIdxFrame = [this](const size_t i) { return this->basePath / "frame" / std::to_string(i) / "model.obj"; };
        while (std::filesystem::exists(getIdxFrame(indexFrame))) {
            this->models.emplace_back(ModelManager::get()->getModel(getIdxFrame(indexFrame)));
            indexFrame++;
        }
        this->scheduleUpdate();
        return true;
    }

   AnimatedModelNode* AnimatedModelNode::create(const std::filesystem::path& base) {
        auto ret = new AnimatedModelNode();
        if (!ret || !ret->setup(base)) {
            delete ret;
            return nullptr;
        }
        return ret;
    }

    void AnimatedModelNode::update(float dt) {
        float frameTime = 1.0f / fps;
        timeAccumulator += dt;

        while (timeAccumulator >= frameTime) {
            // go into next model
            timeAccumulator -= frameTime;
            currentModelIndex = (currentModelIndex + 1) % models.size();
        }
    }

    bool AnimatedModel::setup(const std::filesystem::path& base, PlayerObject* player) {
        if (auto cnode = AnimatedModelNode::create(base)) {
            this->node = cnode;
            player->addChild(this->node);
            return true;
        }
        return false;
    }

    AnimatedModel* AnimatedModel::create(const std::filesystem::path& base, PlayerObject* player) {
        AnimatedModel* ret = new AnimatedModel();
        if (!ret || !ret->setup(base, player)) {
            delete ret;
            return nullptr;
        }
        return ret;
    }

    void AnimatedModel::setRotation(glm::vec3 rotation) {
        sus3d::Model::setRotation(rotation);
        for (auto& model : node->models) {
            model->setRotation(rotation);
        }
    }

    void AnimatedModel::setRotationX(float rotation) {
        sus3d::Model::setRotationX(rotation);
        for (auto& model : node->models) {
            model->setRotationX(rotation);
        }
    }

    void AnimatedModel::setRotationY(float rotation) {
        sus3d::Model::setRotationY(rotation);
        for (auto& model : node->models) {
            model->setRotationY(rotation);
        }
    }

    void AnimatedModel::setRotationZ(float rotation) {
        sus3d::Model::setRotationZ(rotation);
        for (auto& model : node->models) {
            model->setRotationZ(rotation);
        }
    }

    void AnimatedModel::setPosition(glm::vec3 position) {
        sus3d::Model::setPosition(position);
        for (auto& model : node->models) {
            model->setPosition(position);
        }
    }

    void AnimatedModel::setPositionX(float position) {
        sus3d::Model::setPositionX(position);
        for (auto& model : node->models) {
            model->setPositionX(position);
        }
    }

    void AnimatedModel::setPositionY(float position) {
        sus3d::Model::setPositionY(position);
        for (auto& model : node->models) {
            model->setPositionY(position);
        }
    }

    void AnimatedModel::setPositionZ(float position) {
        sus3d::Model::setPositionZ(position);
        for (auto& model : node->models) {
            model->setPositionZ(position);
        }
    }

    void AnimatedModel::setScale(glm::vec3 scale) {
        sus3d::Model::setScale(scale);
        for (auto& model : node->models) {
            model->setScale(scale);
        }
    }

    void AnimatedModel::setScaleX(float scale) {
        sus3d::Model::setScaleX(scale);
        for (auto& model : node->models) {
            model->setScaleX(scale);
        }
    }

    void AnimatedModel::setScaleY(float scale) {
        sus3d::Model::setScaleY(scale);
        for (auto& model : node->models) {
            model->setScaleY(scale);
        }
    }

    void AnimatedModel::setScaleZ(float scale) {
        sus3d::Model::setScaleZ(scale);
        for (auto& model : node->models) {
            model->setScaleZ(scale);
        }
    }

    void AnimatedModel::setVisible(bool visible) {
        sus3d::Model::setVisible(visible);
        for (auto& model : node->models) {
            model->setVisible(visible);
        }
    }
}