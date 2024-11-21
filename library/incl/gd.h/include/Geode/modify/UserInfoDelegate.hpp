#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/UserInfoDelegate.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_getUserInfoFinished
		#define GEODE_STATICS_getUserInfoFinished
		GEODE_AS_STATIC_FUNCTION(getUserInfoFinished) 
	#endif

	#ifndef GEODE_STATICS_getUserInfoFailed
		#define GEODE_STATICS_getUserInfoFailed
		GEODE_AS_STATIC_FUNCTION(getUserInfoFailed) 
	#endif

	#ifndef GEODE_STATICS_userInfoChanged
		#define GEODE_STATICS_userInfoChanged
		GEODE_AS_STATIC_FUNCTION(userInfoChanged) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_getUserInfoFinished
		#define GEODE_CONCEPT_CHECK_getUserInfoFinished
		GEODE_CONCEPT_FUNCTION_CHECK(getUserInfoFinished) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_getUserInfoFailed
		#define GEODE_CONCEPT_CHECK_getUserInfoFailed
		GEODE_CONCEPT_FUNCTION_CHECK(getUserInfoFailed) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_userInfoChanged
		#define GEODE_CONCEPT_CHECK_userInfoChanged
		GEODE_CONCEPT_FUNCTION_CHECK(userInfoChanged) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, UserInfoDelegate> : ModifyBase<ModifyDerive<Der, UserInfoDelegate>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, UserInfoDelegate>>;
		using ModifyBase<ModifyDerive<Der, UserInfoDelegate>>::ModifyBase;
		using Base = UserInfoDelegate;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(UserInfoDelegate, getUserInfoFinished, , GJUserScore*)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(UserInfoDelegate, getUserInfoFailed, , int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(UserInfoDelegate, userInfoChanged, , GJUserScore*)
		}
	};
}
