#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/GJTransformControlDelegate.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_transformScaleXChanged
		#define GEODE_STATICS_transformScaleXChanged
		GEODE_AS_STATIC_FUNCTION(transformScaleXChanged) 
	#endif

	#ifndef GEODE_STATICS_transformScaleYChanged
		#define GEODE_STATICS_transformScaleYChanged
		GEODE_AS_STATIC_FUNCTION(transformScaleYChanged) 
	#endif

	#ifndef GEODE_STATICS_transformScaleXYChanged
		#define GEODE_STATICS_transformScaleXYChanged
		GEODE_AS_STATIC_FUNCTION(transformScaleXYChanged) 
	#endif

	#ifndef GEODE_STATICS_transformRotationXChanged
		#define GEODE_STATICS_transformRotationXChanged
		GEODE_AS_STATIC_FUNCTION(transformRotationXChanged) 
	#endif

	#ifndef GEODE_STATICS_transformRotationYChanged
		#define GEODE_STATICS_transformRotationYChanged
		GEODE_AS_STATIC_FUNCTION(transformRotationYChanged) 
	#endif

	#ifndef GEODE_STATICS_transformRotationChanged
		#define GEODE_STATICS_transformRotationChanged
		GEODE_AS_STATIC_FUNCTION(transformRotationChanged) 
	#endif

	#ifndef GEODE_STATICS_transformResetRotation
		#define GEODE_STATICS_transformResetRotation
		GEODE_AS_STATIC_FUNCTION(transformResetRotation) 
	#endif

	#ifndef GEODE_STATICS_transformRestoreRotation
		#define GEODE_STATICS_transformRestoreRotation
		GEODE_AS_STATIC_FUNCTION(transformRestoreRotation) 
	#endif

	#ifndef GEODE_STATICS_transformSkewXChanged
		#define GEODE_STATICS_transformSkewXChanged
		GEODE_AS_STATIC_FUNCTION(transformSkewXChanged) 
	#endif

	#ifndef GEODE_STATICS_transformSkewYChanged
		#define GEODE_STATICS_transformSkewYChanged
		GEODE_AS_STATIC_FUNCTION(transformSkewYChanged) 
	#endif

	#ifndef GEODE_STATICS_transformChangeBegin
		#define GEODE_STATICS_transformChangeBegin
		GEODE_AS_STATIC_FUNCTION(transformChangeBegin) 
	#endif

	#ifndef GEODE_STATICS_transformChangeEnded
		#define GEODE_STATICS_transformChangeEnded
		GEODE_AS_STATIC_FUNCTION(transformChangeEnded) 
	#endif

	#ifndef GEODE_STATICS_updateTransformControl
		#define GEODE_STATICS_updateTransformControl
		GEODE_AS_STATIC_FUNCTION(updateTransformControl) 
	#endif

	#ifndef GEODE_STATICS_anchorPointMoved
		#define GEODE_STATICS_anchorPointMoved
		GEODE_AS_STATIC_FUNCTION(anchorPointMoved) 
	#endif

	#ifndef GEODE_STATICS_getTransformNode
		#define GEODE_STATICS_getTransformNode
		GEODE_AS_STATIC_FUNCTION(getTransformNode) 
	#endif

	#ifndef GEODE_STATICS_getUI
		#define GEODE_STATICS_getUI
		GEODE_AS_STATIC_FUNCTION(getUI) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_transformScaleXChanged
		#define GEODE_CONCEPT_CHECK_transformScaleXChanged
		GEODE_CONCEPT_FUNCTION_CHECK(transformScaleXChanged) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_transformScaleYChanged
		#define GEODE_CONCEPT_CHECK_transformScaleYChanged
		GEODE_CONCEPT_FUNCTION_CHECK(transformScaleYChanged) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_transformScaleXYChanged
		#define GEODE_CONCEPT_CHECK_transformScaleXYChanged
		GEODE_CONCEPT_FUNCTION_CHECK(transformScaleXYChanged) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_transformRotationXChanged
		#define GEODE_CONCEPT_CHECK_transformRotationXChanged
		GEODE_CONCEPT_FUNCTION_CHECK(transformRotationXChanged) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_transformRotationYChanged
		#define GEODE_CONCEPT_CHECK_transformRotationYChanged
		GEODE_CONCEPT_FUNCTION_CHECK(transformRotationYChanged) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_transformRotationChanged
		#define GEODE_CONCEPT_CHECK_transformRotationChanged
		GEODE_CONCEPT_FUNCTION_CHECK(transformRotationChanged) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_transformResetRotation
		#define GEODE_CONCEPT_CHECK_transformResetRotation
		GEODE_CONCEPT_FUNCTION_CHECK(transformResetRotation) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_transformRestoreRotation
		#define GEODE_CONCEPT_CHECK_transformRestoreRotation
		GEODE_CONCEPT_FUNCTION_CHECK(transformRestoreRotation) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_transformSkewXChanged
		#define GEODE_CONCEPT_CHECK_transformSkewXChanged
		GEODE_CONCEPT_FUNCTION_CHECK(transformSkewXChanged) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_transformSkewYChanged
		#define GEODE_CONCEPT_CHECK_transformSkewYChanged
		GEODE_CONCEPT_FUNCTION_CHECK(transformSkewYChanged) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_transformChangeBegin
		#define GEODE_CONCEPT_CHECK_transformChangeBegin
		GEODE_CONCEPT_FUNCTION_CHECK(transformChangeBegin) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_transformChangeEnded
		#define GEODE_CONCEPT_CHECK_transformChangeEnded
		GEODE_CONCEPT_FUNCTION_CHECK(transformChangeEnded) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateTransformControl
		#define GEODE_CONCEPT_CHECK_updateTransformControl
		GEODE_CONCEPT_FUNCTION_CHECK(updateTransformControl) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_anchorPointMoved
		#define GEODE_CONCEPT_CHECK_anchorPointMoved
		GEODE_CONCEPT_FUNCTION_CHECK(anchorPointMoved) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getTransformNode
		#define GEODE_CONCEPT_CHECK_getTransformNode
		GEODE_CONCEPT_FUNCTION_CHECK(getTransformNode) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getUI
		#define GEODE_CONCEPT_CHECK_getUI
		GEODE_CONCEPT_FUNCTION_CHECK(getUI) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, GJTransformControlDelegate> : ModifyBase<ModifyDerive<Der, GJTransformControlDelegate>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, GJTransformControlDelegate>>;
		using ModifyBase<ModifyDerive<Der, GJTransformControlDelegate>>::ModifyBase;
		using Base = GJTransformControlDelegate;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<float>::func(&GJTransformControlDelegate::transformScaleXChanged)), Default, GJTransformControlDelegate, transformScaleXChanged, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<float>::func(&GJTransformControlDelegate::transformScaleYChanged)), Default, GJTransformControlDelegate, transformScaleYChanged, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<float, float>::func(&GJTransformControlDelegate::transformScaleXYChanged)), Default, GJTransformControlDelegate, transformScaleXYChanged, float, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<float>::func(&GJTransformControlDelegate::transformRotationXChanged)), Default, GJTransformControlDelegate, transformRotationXChanged, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<float>::func(&GJTransformControlDelegate::transformRotationYChanged)), Default, GJTransformControlDelegate, transformRotationYChanged, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<float>::func(&GJTransformControlDelegate::transformRotationChanged)), Default, GJTransformControlDelegate, transformRotationChanged, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<>::func(&GJTransformControlDelegate::transformResetRotation)), Default, GJTransformControlDelegate, transformResetRotation, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<>::func(&GJTransformControlDelegate::transformRestoreRotation)), Default, GJTransformControlDelegate, transformRestoreRotation, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<float>::func(&GJTransformControlDelegate::transformSkewXChanged)), Default, GJTransformControlDelegate, transformSkewXChanged, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<float>::func(&GJTransformControlDelegate::transformSkewYChanged)), Default, GJTransformControlDelegate, transformSkewYChanged, float)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<>::func(&GJTransformControlDelegate::transformChangeBegin)), Default, GJTransformControlDelegate, transformChangeBegin, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<>::func(&GJTransformControlDelegate::transformChangeEnded)), Default, GJTransformControlDelegate, transformChangeEnded, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<>::func(&GJTransformControlDelegate::updateTransformControl)), Default, GJTransformControlDelegate, updateTransformControl, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<cocos2d::CCPoint>::func(&GJTransformControlDelegate::anchorPointMoved)), Default, GJTransformControlDelegate, anchorPointMoved, cocos2d::CCPoint)
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<>::func(&GJTransformControlDelegate::getTransformNode)), Default, GJTransformControlDelegate, getTransformNode, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION(addresser::getVirtual(Resolve<>::func(&GJTransformControlDelegate::getUI)), Default, GJTransformControlDelegate, getUI, )
		}
	};
}
