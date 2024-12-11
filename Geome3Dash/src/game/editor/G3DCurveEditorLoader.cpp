#include "pch.h"

#include "G3DCurveEditorLoader.h"
#include "G3DCurveEditorPopup.h"
#include "game/component/G3DBaseNode.h"

#include "helper/OpenGLStateHelper.h"

#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Shaders.h"
#include "engine/sus3d/spline/Curve.h"
#include "engine/sus3d/spline/Spline.h"

#include "manager/ModelManager.h"
#include "manager/LevelDataManager.h"

namespace g3d
{

	bool G3DCurveEditorLoader::setup(LevelEditorLayer* lel) {
		if (!CCNode::init()) return false;

		this->lel = lel;

		layer3d = G3DBaseNode::create();
		layer3d->camera.setPosition(glm::vec3(0, 0, 15));
		layer3d->light.setPosition(glm::vec3(0, 50, 1000));
		layer3d->setZOrder(10);
		layer3d->retain(); //sus

		auto bms = ModelManager::get();

		pointModel = bms->getModel(bms->getBP() / "editor" / "model" / "sphere.obj");

		return true;
	}

	void G3DCurveEditorLoader::addSegment() 
	{
		spline.addNewCurveToSpline();
		prepareSpline(lel, &spline, &lengthScaleFactor);
	}


	void G3DCurveEditorLoader::removeSegment() 
	{
		if (spline.segments.size() > 1) 
		{
			spline.removeLastSegment();
			prepareSpline(lel, &spline, &lengthScaleFactor);
		}
	}

	void G3DCurveEditorLoader::show() 
	{
		G3DCurveEditorPopup::create(this)->show();
	}


	G3DCurveEditorLoader* G3DCurveEditorLoader::create(LevelEditorLayer* lel) {
		auto ret = new G3DCurveEditorLoader();
		if (ret && ret->setup(lel)) {
			ret->autorelease();
			return ret;
		}

		delete ret;
		return nullptr;
	}
}