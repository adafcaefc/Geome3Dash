#include "pch.h"

#include "G3DCameraKeyframeEditorLoader.h"
#include "G3DCameraKeyframeEditorPopup.h"

#include "helper/spline/Curve.h"
#include "helper/spline/Spline.h"
#include "helper/OpenGLStateHelper.h"
#include "helper/CameraKeyframeBuffer.h"
#include "game/component/G3DBaseNode.h"

#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Shaders.h"

#include "BlockModelStorage.h"
#include "LevelDataManager.h"

namespace g3d
{
	bool G3DCameraKeyframeEditorLoader::setup(LevelEditorLayer* lel)
	{
		if (!CCNode::init()) return false;

		this->lel = lel;

		layer3d = G3DBaseNode::create();
		layer3d->camera.setPosition(glm::vec3(0, 0, 15));
		layer3d->light.setPosition(glm::vec3(0, 50, 1000));
		layer3d->retain();//sus

		auto bms = BlockModelStorage::get();

		blockShaderProgram = bms->getBlockSP();
		cube = bms->getModel(bms->getBP() / "player" / "cube" / "0" / "model.obj");

		updateLevel();

		//bgModel = layer3d->loadAndAddModel("./models/bg/bg.obj", blockShaderProgram);
		//bgModel->setPosition(glm::vec3(300, -100, -300));
		//bgModel->setScale(glm::vec3(7, 7, 7));
		//groundModel = Model::create("./models/ground/model.obj", blockShaderProgram);

		return true;
	}

	void G3DCameraKeyframeEditorLoader::updateLevel() {
		levelLength = 0;
		CCObject* obj;
		CCARRAY_FOREACH(lel->m_objects, obj) {
			auto block = static_cast<GameObject*>(obj);
			levelLength = std::max(block->getPositionX(), levelLength);
		}

		lengthScaleFactor = spline.length(10000) / levelLength;
	}

	void G3DCameraKeyframeEditorLoader::show() {
		updateLevel();
		popup = G3DCameraKeyframeEditorPopup::create(this);
		popup->show();
	}

	void G3DCameraKeyframeEditorLoader::hide() {
		if (popup) {
			popup->onClose(nullptr);
		}
	}

	G3DCameraKeyframeEditorLoader* G3DCameraKeyframeEditorLoader::create(LevelEditorLayer* lel) {
		auto ret = new G3DCameraKeyframeEditorLoader();
		if (ret && ret->setup(lel)) {
			ret->autorelease();
			return ret;
		}

		delete ret;
		return nullptr;
	}
}