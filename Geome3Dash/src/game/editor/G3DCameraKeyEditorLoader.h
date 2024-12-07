#pragma once

#include "helper/spline/Spline.h"
#include "helper/KeyframeData.h"

namespace sus3d
{
	class Model;
	class ShaderProgram;
}

namespace g3d
{
	class G3DBaseNode;
	class Spline;
	class KeyframeData;
	class G3DCameraKeyEditorPopup;

	class G3DCameraKeyEditorLoader : public CCNode 
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


		G3DCameraKeyEditorPopup* popup;
	public:
		KeyframeData keyframeBuffer;

		void updateLevel();

		void show();
		void hide();

		static G3DCameraKeyEditorLoader* create(LevelEditorLayer* lel);
		friend class G3DCameraKeyEditorPopup;
	};
}