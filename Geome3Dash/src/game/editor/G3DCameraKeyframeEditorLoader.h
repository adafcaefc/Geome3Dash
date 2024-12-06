#pragma once

#include "helper/spline/Spline.h"
#include "helper/CameraKeyframeBuffer.h"

namespace sus3d
{
	class Model;
	class ShaderProgram;
}

namespace g3d
{
	class G3DBaseNode;
	class Spline;
	class CameraKeyframeBuffer;
	class G3DCameraKeyframeEditorPopup;

	class G3DCameraKeyframeEditorLoader : public CCNode 
	{
		G3DBaseNode* layer3d;
		sus3d::ShaderProgram* blockShaderProgram;
		LevelEditorLayer* lel;
		Spline spline;
		float levelLength;
		//sus3d::Model* bgModel;
		//sus3d::Model* groundModel;


		float lengthScaleFactor;

		sus3d::Model* cube;

		bool setup(LevelEditorLayer* lel);


		G3DCameraKeyframeEditorPopup* popup;
	public:
		CameraKeyframeBuffer keyframeBuffer;

		void updateLevel();

		void show();
		void hide();

		static G3DCameraKeyframeEditorLoader* create(LevelEditorLayer* lel);
		friend class G3DCameraKeyframeEditorPopup;
	};
}