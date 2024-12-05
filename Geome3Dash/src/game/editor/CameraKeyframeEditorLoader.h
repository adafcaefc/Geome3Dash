#pragma once

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
	class CameraKeyframeBuffer;
	class CameraKeyframeEditorPopup;

	class CameraKeyframeEditorLoader : public CCNode 
	{
		G3DBaseNode* layer3d;
		sus3d::ShaderProgram* blockShaderProgram;
		LevelEditorLayer* lel;
		Spline* spline;
		float levelLength;
		//sus3d::Model* bgModel;
		//sus3d::Model* groundModel;


		float lengthScaleFactor;

		sus3d::Model* cube;

		bool init(LevelEditorLayer* lel, Spline* spline, CameraKeyframeBuffer* defaultKeyframeBuffer);


		CameraKeyframeEditorPopup* popup;
	public:
		CameraKeyframeBuffer* keyframeBuffer;

		void updateLevel();

		void show();
		void hide();

		static CameraKeyframeEditorLoader* create(LevelEditorLayer* lel, Spline* spline, CameraKeyframeBuffer* defaultKeyframeBuffer);
		friend class CameraKeyframeEditorPopup;
	};
}