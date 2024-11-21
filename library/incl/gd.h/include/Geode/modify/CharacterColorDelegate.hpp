#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/CharacterColorDelegate.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_playerColorChanged
		#define GEODE_STATICS_playerColorChanged
		GEODE_AS_STATIC_FUNCTION(playerColorChanged) 
	#endif

	#ifndef GEODE_STATICS_showUnlockPopup
		#define GEODE_STATICS_showUnlockPopup
		GEODE_AS_STATIC_FUNCTION(showUnlockPopup) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_playerColorChanged
		#define GEODE_CONCEPT_CHECK_playerColorChanged
		GEODE_CONCEPT_FUNCTION_CHECK(playerColorChanged) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_showUnlockPopup
		#define GEODE_CONCEPT_CHECK_showUnlockPopup
		GEODE_CONCEPT_FUNCTION_CHECK(showUnlockPopup) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, CharacterColorDelegate> : ModifyBase<ModifyDerive<Der, CharacterColorDelegate>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, CharacterColorDelegate>>;
		using ModifyBase<ModifyDerive<Der, CharacterColorDelegate>>::ModifyBase;
		using Base = CharacterColorDelegate;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(CharacterColorDelegate, playerColorChanged, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(CharacterColorDelegate, showUnlockPopup, , int, UnlockType)
		}
	};
}
