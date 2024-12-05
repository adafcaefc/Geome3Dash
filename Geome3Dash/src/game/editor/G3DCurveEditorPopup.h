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

	class G3DCurveEditorLoader;

	class G3DCurveEditorPopup 
		: public geode::Popup<G3DCurveEditorLoader*>
		, public CustomKeyboardDelegate
		, public CustomMouseDelegate
		, public CustomTouchDelegate 
	{
	protected:
		G3DCurveEditorLoader* cel;

		int selected = -1;

		bool isPressingControl = false;
		bool isPressingShift = false;
		bool isRightClicking = false;
		bool isRightClickingGetPos = false;
		float lastMouseX = 0.0;
		float lastMouseY = 0.0;

		virtual void onGLFWMouseCallBack(GLFWwindow* window, int button, int action, int mods);
		virtual void onGLFWMouseMoveCallBack(GLFWwindow* window, double x, double y);
		virtual void scrollWheel(float y, float x);
		virtual void onKey(enumKeyCodes key, bool pressed, bool holding);

		bool setup(G3DCurveEditorLoader* cel) override;

		void draw() override;

		void onAddSegment(CCObject*);
		void onRemoveSegment(CCObject*);

		void onClose(CCObject* obj);
	public:
		static G3DCurveEditorPopup* create(G3DCurveEditorLoader* cel);
	};
}