#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <cocos2d.h>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_swapBuffers
		#define GEODE_STATICS_swapBuffers
		GEODE_AS_STATIC_FUNCTION(swapBuffers) 
	#endif

	#ifndef GEODE_STATICS_end
		#define GEODE_STATICS_end
		GEODE_AS_STATIC_FUNCTION(end) 
	#endif

	#ifndef GEODE_STATICS_toggleFullScreen
		#define GEODE_STATICS_toggleFullScreen
		GEODE_AS_STATIC_FUNCTION(toggleFullScreen) 
	#endif

	#ifndef GEODE_STATICS_pollEvents
		#define GEODE_STATICS_pollEvents
		GEODE_AS_STATIC_FUNCTION(pollEvents) 
	#endif

	#ifndef GEODE_STATICS_setupWindow
		#define GEODE_STATICS_setupWindow
		GEODE_AS_STATIC_FUNCTION(setupWindow) 
	#endif

	#ifndef GEODE_STATICS_onGLFWCharCallback
		#define GEODE_STATICS_onGLFWCharCallback
		GEODE_AS_STATIC_FUNCTION(onGLFWCharCallback) 
	#endif

	#ifndef GEODE_STATICS_onGLFWCursorEnterFunCallback
		#define GEODE_STATICS_onGLFWCursorEnterFunCallback
		GEODE_AS_STATIC_FUNCTION(onGLFWCursorEnterFunCallback) 
	#endif

	#ifndef GEODE_STATICS_onGLFWDeviceChangeFunCallback
		#define GEODE_STATICS_onGLFWDeviceChangeFunCallback
		GEODE_AS_STATIC_FUNCTION(onGLFWDeviceChangeFunCallback) 
	#endif

	#ifndef GEODE_STATICS_onGLFWError
		#define GEODE_STATICS_onGLFWError
		GEODE_AS_STATIC_FUNCTION(onGLFWError) 
	#endif

	#ifndef GEODE_STATICS_onGLFWKeyCallback
		#define GEODE_STATICS_onGLFWKeyCallback
		GEODE_AS_STATIC_FUNCTION(onGLFWKeyCallback) 
	#endif

	#ifndef GEODE_STATICS_onGLFWMouseCallBack
		#define GEODE_STATICS_onGLFWMouseCallBack
		GEODE_AS_STATIC_FUNCTION(onGLFWMouseCallBack) 
	#endif

	#ifndef GEODE_STATICS_onGLFWMouseMoveCallBack
		#define GEODE_STATICS_onGLFWMouseMoveCallBack
		GEODE_AS_STATIC_FUNCTION(onGLFWMouseMoveCallBack) 
	#endif

	#ifndef GEODE_STATICS_onGLFWMouseScrollCallback
		#define GEODE_STATICS_onGLFWMouseScrollCallback
		GEODE_AS_STATIC_FUNCTION(onGLFWMouseScrollCallback) 
	#endif

	#ifndef GEODE_STATICS_onGLFWWindowIconifyFunCallback
		#define GEODE_STATICS_onGLFWWindowIconifyFunCallback
		GEODE_AS_STATIC_FUNCTION(onGLFWWindowIconifyFunCallback) 
	#endif

	#ifndef GEODE_STATICS_onGLFWWindowPosCallback
		#define GEODE_STATICS_onGLFWWindowPosCallback
		GEODE_AS_STATIC_FUNCTION(onGLFWWindowPosCallback) 
	#endif

	#ifndef GEODE_STATICS_onGLFWWindowSizeFunCallback
		#define GEODE_STATICS_onGLFWWindowSizeFunCallback
		GEODE_AS_STATIC_FUNCTION(onGLFWWindowSizeFunCallback) 
	#endif

	#ifndef GEODE_STATICS_onGLFWframebuffersize
		#define GEODE_STATICS_onGLFWframebuffersize
		GEODE_AS_STATIC_FUNCTION(onGLFWframebuffersize) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_swapBuffers
		#define GEODE_CONCEPT_CHECK_swapBuffers
		GEODE_CONCEPT_FUNCTION_CHECK(swapBuffers) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_end
		#define GEODE_CONCEPT_CHECK_end
		GEODE_CONCEPT_FUNCTION_CHECK(end) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_toggleFullScreen
		#define GEODE_CONCEPT_CHECK_toggleFullScreen
		GEODE_CONCEPT_FUNCTION_CHECK(toggleFullScreen) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_pollEvents
		#define GEODE_CONCEPT_CHECK_pollEvents
		GEODE_CONCEPT_FUNCTION_CHECK(pollEvents) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_setupWindow
		#define GEODE_CONCEPT_CHECK_setupWindow
		GEODE_CONCEPT_FUNCTION_CHECK(setupWindow) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWCharCallback
		#define GEODE_CONCEPT_CHECK_onGLFWCharCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWCharCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWCursorEnterFunCallback
		#define GEODE_CONCEPT_CHECK_onGLFWCursorEnterFunCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWCursorEnterFunCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWDeviceChangeFunCallback
		#define GEODE_CONCEPT_CHECK_onGLFWDeviceChangeFunCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWDeviceChangeFunCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWError
		#define GEODE_CONCEPT_CHECK_onGLFWError
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWError) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWKeyCallback
		#define GEODE_CONCEPT_CHECK_onGLFWKeyCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWKeyCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWMouseCallBack
		#define GEODE_CONCEPT_CHECK_onGLFWMouseCallBack
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWMouseCallBack) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWMouseMoveCallBack
		#define GEODE_CONCEPT_CHECK_onGLFWMouseMoveCallBack
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWMouseMoveCallBack) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWMouseScrollCallback
		#define GEODE_CONCEPT_CHECK_onGLFWMouseScrollCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWMouseScrollCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWWindowIconifyFunCallback
		#define GEODE_CONCEPT_CHECK_onGLFWWindowIconifyFunCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWWindowIconifyFunCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWWindowPosCallback
		#define GEODE_CONCEPT_CHECK_onGLFWWindowPosCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWWindowPosCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWWindowSizeFunCallback
		#define GEODE_CONCEPT_CHECK_onGLFWWindowSizeFunCallback
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWWindowSizeFunCallback) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_onGLFWframebuffersize
		#define GEODE_CONCEPT_CHECK_onGLFWframebuffersize
		GEODE_CONCEPT_FUNCTION_CHECK(onGLFWframebuffersize) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, cocos2d::CCEGLView> : ModifyBase<ModifyDerive<Der, cocos2d::CCEGLView>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, cocos2d::CCEGLView>>;
		using ModifyBase<ModifyDerive<Der, cocos2d::CCEGLView>>::ModifyBase;
		using Base = cocos2d::CCEGLView;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<>::func(&cocos2d::CCEGLView::swapBuffers)), Thiscall, cocos2d::CCEGLView, swapBuffers, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<>::func(&cocos2d::CCEGLView::end)), Thiscall, cocos2d::CCEGLView, end, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<bool, bool, bool>::func(&cocos2d::CCEGLView::toggleFullScreen)), Thiscall, cocos2d::CCEGLView, toggleFullScreen, bool, bool, bool)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<>::func(&cocos2d::CCEGLView::pollEvents)), Thiscall, cocos2d::CCEGLView, pollEvents, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<cocos2d::CCRect>::func(&cocos2d::CCEGLView::setupWindow)), Thiscall, cocos2d::CCEGLView, setupWindow, cocos2d::CCRect)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<GLFWwindow*, unsigned int>::func(&cocos2d::CCEGLView::onGLFWCharCallback)), Thiscall, cocos2d::CCEGLView, onGLFWCharCallback, GLFWwindow*, unsigned int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<GLFWwindow*, int>::func(&cocos2d::CCEGLView::onGLFWCursorEnterFunCallback)), Thiscall, cocos2d::CCEGLView, onGLFWCursorEnterFunCallback, GLFWwindow*, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<GLFWwindow*>::func(&cocos2d::CCEGLView::onGLFWDeviceChangeFunCallback)), Thiscall, cocos2d::CCEGLView, onGLFWDeviceChangeFunCallback, GLFWwindow*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<int, char const*>::func(&cocos2d::CCEGLView::onGLFWError)), Thiscall, cocos2d::CCEGLView, onGLFWError, int, char const*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<GLFWwindow*, int, int, int, int>::func(&cocos2d::CCEGLView::onGLFWKeyCallback)), Thiscall, cocos2d::CCEGLView, onGLFWKeyCallback, GLFWwindow*, int, int, int, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<GLFWwindow*, int, int, int>::func(&cocos2d::CCEGLView::onGLFWMouseCallBack)), Thiscall, cocos2d::CCEGLView, onGLFWMouseCallBack, GLFWwindow*, int, int, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<GLFWwindow*, double, double>::func(&cocos2d::CCEGLView::onGLFWMouseMoveCallBack)), Thiscall, cocos2d::CCEGLView, onGLFWMouseMoveCallBack, GLFWwindow*, double, double)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<GLFWwindow*, double, double>::func(&cocos2d::CCEGLView::onGLFWMouseScrollCallback)), Thiscall, cocos2d::CCEGLView, onGLFWMouseScrollCallback, GLFWwindow*, double, double)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<GLFWwindow*, int>::func(&cocos2d::CCEGLView::onGLFWWindowIconifyFunCallback)), Thiscall, cocos2d::CCEGLView, onGLFWWindowIconifyFunCallback, GLFWwindow*, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<GLFWwindow*, int, int>::func(&cocos2d::CCEGLView::onGLFWWindowPosCallback)), Thiscall, cocos2d::CCEGLView, onGLFWWindowPosCallback, GLFWwindow*, int, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<GLFWwindow*, int, int>::func(&cocos2d::CCEGLView::onGLFWWindowSizeFunCallback)), Thiscall, cocos2d::CCEGLView, onGLFWWindowSizeFunCallback, GLFWwindow*, int, int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getNonVirtual(Resolve<GLFWwindow*, int, int>::func(&cocos2d::CCEGLView::onGLFWframebuffersize)), Thiscall, cocos2d::CCEGLView, onGLFWframebuffersize, GLFWwindow*, int, int)
		}
	};
}
