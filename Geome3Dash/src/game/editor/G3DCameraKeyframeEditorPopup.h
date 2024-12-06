#pragma once

#include "delegate/CustomKeyboard.h"
#include "delegate/CustomMouse.h"
#include "delegate/CustomTouch.h"

#include "helper/spline/Spline.h"

#include "transformer/SplineCameraPlayerObjectModelTransformer.h"
#include "transformer/SplineGameObjectTransformer.h"
#include "transformer/SplinePlayerObjectTransformer.h"

#include "PlayerObjectModel.h"

namespace sus3d
{
	class Model;
	class ShaderProgram;
}

namespace g3d
{
	class G3DCameraKeyframeEditorLoader;

	class G3DCameraKeyframeEditorPopup 
		: public geode::Popup<G3DCameraKeyframeEditorLoader*>
		, public CustomKeyboardDelegate
		, public CustomMouseDelegate
		, public CustomTouchDelegate 
	{
	protected:
		G3DCameraKeyframeEditorLoader* ckel;

		bool isEditing = false;

		bool isPressingControl = false;
		bool isRightClicking = false;
		bool isRightClickingGetPos = false;
		float lastMouseX = 0.0;
		float lastMouseY = 0.0;

		virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods) override;
		virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y) override;
		virtual void scrollWheel(float y, float x) override;
		virtual void onKey(enumKeyCodes key, bool pressed, bool holding) override;

		bool setup(G3DCameraKeyframeEditorLoader* cel) override;

		void draw() override;

		void onAdd(CCObject*);
		void onRemoveLast(CCObject*);

		PlayerObjectModel player1;
		PlayerObjectModel player2;

		SplineGameObjectTransformer* splineTr;
		SplinePlayerObjectTransformer* splinePlayerTr;
		SplineCameraPlayerObjectModelTransformer* splineCamTr;

		std::vector<GameObjectModel> blocks;
	public:
		void onClose(CCObject* obj) override;

		static G3DCameraKeyframeEditorPopup* create(G3DCameraKeyframeEditorLoader* ckel);
	};
}