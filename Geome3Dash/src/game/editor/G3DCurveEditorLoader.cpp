#include "pch.h"

#include "G3DCurveEditorLoader.h"
#include "G3DCurveEditorPopup.h"

#include "helper/spline/Curve.h"
#include "helper/spline/Spline.h"
#include "helper/OpenGLStateHelper.h"
#include "game/component/G3DBaseNode.h"

#include "engine/sus3d/Mesh.h"
#include "engine/sus3d/Shader.h"
#include "engine/sus3d/Shaders.h"

#include "BlockModelStorage.h"

namespace g3d
{
	void G3DCurveEditorLoader::updateLevel() {
		levelLength = 0;

		CCObject* obj;
		CCARRAY_FOREACH(lel->m_objects, obj) {
			auto block = static_cast<GameObject*>(obj);

			levelLength = std::max(block->getPositionX(), levelLength);
		}

		lengthScaleFactor = spline->length(10000) / levelLength;
	}

	bool G3DCurveEditorLoader::init(LevelEditorLayer* lel, Spline* defaultSpline) {
		if (!CCNode::init()) return false;

		this->lel = lel;

		if (defaultSpline) {
			spline = defaultSpline;
		}
		else {
			spline = new Spline();
			spline->addSegment(new Curve(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(2.0f, 0.0f, 0.0f), glm::vec3(3.0f, 0.0f, 0.0f)));
		}

		layer3d = G3DBaseNode::create();
		layer3d->camera.setPosition(glm::vec3(0, 0, 15));
		layer3d->light.setPosition(glm::vec3(0, 50, 1000));
		layer3d->setZOrder(10);
		layer3d->retain(); //sus

		auto bms = BlockModelStorage::get();

		blockShaderProgram = bms->getBlockSP();

		pointModel = bms->getModel(bms->getBP() / "editor" / "model" / "sphere.obj");

		updateLevel();
		spline->updateParameterList();

		return true;
	}



	void G3DCurveEditorLoader::addSegment() {
		auto p1 = spline->segments.back()->p2;
		auto m1 = spline->segments.back()->p2 * 2.f - spline->segments.back()->m2;
		auto m2 = spline->segments.back()->p2 * 2.f - spline->segments.back()->m1;
		auto p2 = spline->segments.back()->p2 * 2.f - spline->segments.back()->p1;

		spline->addSegment(new Curve(p1, m1, m2, p2));

		updateLevel();
	}


	void G3DCurveEditorLoader::removeSegment() {
		if (spline->segments.size() > 1) {
			spline->removeLastSegment();
			updateLevel();
		}
	}

	void G3DCurveEditorLoader::show() {
		updateLevel();
		G3DCurveEditorPopup::create(this)->show();
	}


	G3DCurveEditorLoader* G3DCurveEditorLoader::create(LevelEditorLayer* lel, Spline* defaultSpline) {
		auto ret = new G3DCurveEditorLoader();
		if (ret && ret->init(lel, defaultSpline)) {
			ret->autorelease();
			return ret;
		}

		delete ret;
		return nullptr;
	}
}