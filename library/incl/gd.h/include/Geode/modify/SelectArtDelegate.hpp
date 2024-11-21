#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/SelectArtDelegate.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_selectArtClosed
		#define GEODE_STATICS_selectArtClosed
		GEODE_AS_STATIC_FUNCTION(selectArtClosed) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_selectArtClosed
		#define GEODE_CONCEPT_CHECK_selectArtClosed
		GEODE_CONCEPT_FUNCTION_CHECK(selectArtClosed) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, SelectArtDelegate> : ModifyBase<ModifyDerive<Der, SelectArtDelegate>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, SelectArtDelegate>>;
		using ModifyBase<ModifyDerive<Der, SelectArtDelegate>>::ModifyBase;
		using Base = SelectArtDelegate;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(SelectArtDelegate, selectArtClosed, , SelectArtLayer*)
		}
	};
}
