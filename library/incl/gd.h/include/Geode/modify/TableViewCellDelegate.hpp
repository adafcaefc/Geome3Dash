#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/TableViewCellDelegate.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_cellPerformedAction
		#define GEODE_STATICS_cellPerformedAction
		GEODE_AS_STATIC_FUNCTION(cellPerformedAction) 
	#endif

	#ifndef GEODE_STATICS_getSelectedCellIdx
		#define GEODE_STATICS_getSelectedCellIdx
		GEODE_AS_STATIC_FUNCTION(getSelectedCellIdx) 
	#endif

	#ifndef GEODE_STATICS_shouldSnapToSelected
		#define GEODE_STATICS_shouldSnapToSelected
		GEODE_AS_STATIC_FUNCTION(shouldSnapToSelected) 
	#endif

	#ifndef GEODE_STATICS_getCellDelegateType
		#define GEODE_STATICS_getCellDelegateType
		GEODE_AS_STATIC_FUNCTION(getCellDelegateType) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_cellPerformedAction
		#define GEODE_CONCEPT_CHECK_cellPerformedAction
		GEODE_CONCEPT_FUNCTION_CHECK(cellPerformedAction) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getSelectedCellIdx
		#define GEODE_CONCEPT_CHECK_getSelectedCellIdx
		GEODE_CONCEPT_FUNCTION_CHECK(getSelectedCellIdx) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_shouldSnapToSelected
		#define GEODE_CONCEPT_CHECK_shouldSnapToSelected
		GEODE_CONCEPT_FUNCTION_CHECK(shouldSnapToSelected) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getCellDelegateType
		#define GEODE_CONCEPT_CHECK_getCellDelegateType
		GEODE_CONCEPT_FUNCTION_CHECK(getCellDelegateType) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, TableViewCellDelegate> : ModifyBase<ModifyDerive<Der, TableViewCellDelegate>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, TableViewCellDelegate>>;
		using ModifyBase<ModifyDerive<Der, TableViewCellDelegate>>::ModifyBase;
		using Base = TableViewCellDelegate;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(TableViewCellDelegate, cellPerformedAction, , TableViewCell*, int, CellAction, cocos2d::CCNode*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(TableViewCellDelegate, getSelectedCellIdx, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(TableViewCellDelegate, shouldSnapToSelected, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(TableViewCellDelegate, getCellDelegateType, )
		}
	};
}
