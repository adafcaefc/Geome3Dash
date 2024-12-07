#include "pch.h"

#include "G3DCameraKeyEditorLoader.h"
#include "G3DCameraKeyEditorPopup.h"

#include "helper/spline/Curve.h"
#include "helper/spline/Spline.h"
#include "helper/OpenGLStateHelper.h"
#include "helper/KeyframeData.h"
#include "game/component/G3DBaseNode.h"

#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Shaders.h"

#include "manager/ModelManager.h"
#include "manager/LevelDataManager.h"

namespace g3d
{
	bool G3DCameraKeyEditorLoader::setup(LevelEditorLayer* lel)
	{
		if (!CCNode::init()) { return false; }

		this->lel = lel;

		layer3d = G3DBaseNode::create();
		layer3d->camera.setPosition(glm::vec3(0, 0, 15));
		layer3d->light.setPosition(glm::vec3(0, 50, 1000));
		layer3d->retain();

		return true;
	}

	void G3DCameraKeyEditorLoader::show() 
	{
		popup = G3DCameraKeyEditorPopup::create(this);
		popup->show();
	}

	void G3DCameraKeyEditorLoader::hide() 
	{
		if (popup) { popup->onClose(nullptr); }
	}

	G3DCameraKeyEditorLoader* G3DCameraKeyEditorLoader::create(LevelEditorLayer* lel) {
		auto ret = new G3DCameraKeyEditorLoader();
		if (ret && ret->setup(lel)) {
			ret->autorelease();
			return ret;
		}
		delete ret;
		return nullptr;
	}
}