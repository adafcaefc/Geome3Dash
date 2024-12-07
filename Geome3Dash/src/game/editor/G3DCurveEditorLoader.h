#pragma once

#include "delegate/CustomKeyboard.h"
#include "delegate/CustomMouse.h"
#include "delegate/CustomTouch.h"

#include "helper/spline/Spline.h"

namespace sus3d
{
	class Model;
	class ShaderProgram;
}

namespace g3d
{
	class G3DBaseNode;
	class Spline;

	class G3DCurveEditorLoader : public CCNode 
	{
		G3DBaseNode* layer3d;
		LevelEditorLayer* lel;
		sus3d::Model* pointModel;

		float levelLength = 0;
		float lengthScaleFactor;

		virtual bool setup(LevelEditorLayer* lel);

		void addSegment();
		void removeSegment();

	public:
		Spline spline;
		void show();

		static G3DCurveEditorLoader* create(LevelEditorLayer* lel);

		friend class KeyframeEditorLayer;
		friend class G3DCurveEditorPopup;
	};
}