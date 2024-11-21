#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/CustomSFXDelegate.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_sfxObjectSelected
		#define GEODE_STATICS_sfxObjectSelected
		GEODE_AS_STATIC_FUNCTION(sfxObjectSelected) 
	#endif

	#ifndef GEODE_STATICS_getActiveSFXID
		#define GEODE_STATICS_getActiveSFXID
		GEODE_AS_STATIC_FUNCTION(getActiveSFXID) 
	#endif

	#ifndef GEODE_STATICS_overridePlaySFX
		#define GEODE_STATICS_overridePlaySFX
		GEODE_AS_STATIC_FUNCTION(overridePlaySFX) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_sfxObjectSelected
		#define GEODE_CONCEPT_CHECK_sfxObjectSelected
		GEODE_CONCEPT_FUNCTION_CHECK(sfxObjectSelected) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getActiveSFXID
		#define GEODE_CONCEPT_CHECK_getActiveSFXID
		GEODE_CONCEPT_FUNCTION_CHECK(getActiveSFXID) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_overridePlaySFX
		#define GEODE_CONCEPT_CHECK_overridePlaySFX
		GEODE_CONCEPT_FUNCTION_CHECK(overridePlaySFX) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, CustomSFXDelegate> : ModifyBase<ModifyDerive<Der, CustomSFXDelegate>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, CustomSFXDelegate>>;
		using ModifyBase<ModifyDerive<Der, CustomSFXDelegate>>::ModifyBase;
		using Base = CustomSFXDelegate;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(CustomSFXDelegate, sfxObjectSelected, , SFXInfoObject*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(CustomSFXDelegate, getActiveSFXID, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(CustomSFXDelegate, overridePlaySFX, , SFXInfoObject*)
		}
	};
}
