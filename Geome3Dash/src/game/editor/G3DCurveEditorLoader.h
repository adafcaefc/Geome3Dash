#pragma once

#include "delegate/CustomKeyboard.h"
#include "delegate/CustomMouse.h"
#include "delegate/CustomTouch.h"

namespace sus3d
{
	class Model;
	class ShaderProgram;
}

namespace g3d
{
	class G3DBaseNode;
	class Spline;

	class G3DCurveEditorLoader : public CCNode {
		G3DBaseNode* layer3d;
		sus3d::Model* pointModel;
		LevelEditorLayer* lel;
		sus3d::ShaderProgram* blockShaderProgram;

		float levelLength = 0;
		float lengthScaleFactor;

		virtual bool init(LevelEditorLayer* lel, Spline* defaultSpline);

		void updateLevel();

		void addSegment();
		void removeSegment();

	public:
		Spline* spline;
		void show();

		static G3DCurveEditorLoader* create(LevelEditorLayer* lel, Spline* defaultSpline = nullptr);

		friend class KeyframeEditorLayer;
		friend class G3DCurveEditorPopup;
	};
}