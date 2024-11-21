#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/GJMPDelegate.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_joinLobbyFinished
		#define GEODE_STATICS_joinLobbyFinished
		GEODE_AS_STATIC_FUNCTION(joinLobbyFinished) 
	#endif

	#ifndef GEODE_STATICS_joinLobbyFailed
		#define GEODE_STATICS_joinLobbyFailed
		GEODE_AS_STATIC_FUNCTION(joinLobbyFailed) 
	#endif

	#ifndef GEODE_STATICS_didUploadMPComment
		#define GEODE_STATICS_didUploadMPComment
		GEODE_AS_STATIC_FUNCTION(didUploadMPComment) 
	#endif

	#ifndef GEODE_STATICS_updateComments
		#define GEODE_STATICS_updateComments
		GEODE_AS_STATIC_FUNCTION(updateComments) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_joinLobbyFinished
		#define GEODE_CONCEPT_CHECK_joinLobbyFinished
		GEODE_CONCEPT_FUNCTION_CHECK(joinLobbyFinished) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_joinLobbyFailed
		#define GEODE_CONCEPT_CHECK_joinLobbyFailed
		GEODE_CONCEPT_FUNCTION_CHECK(joinLobbyFailed) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_didUploadMPComment
		#define GEODE_CONCEPT_CHECK_didUploadMPComment
		GEODE_CONCEPT_FUNCTION_CHECK(didUploadMPComment) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_updateComments
		#define GEODE_CONCEPT_CHECK_updateComments
		GEODE_CONCEPT_FUNCTION_CHECK(updateComments) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, GJMPDelegate> : ModifyBase<ModifyDerive<Der, GJMPDelegate>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, GJMPDelegate>>;
		using ModifyBase<ModifyDerive<Der, GJMPDelegate>>::ModifyBase;
		using Base = GJMPDelegate;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(GJMPDelegate, joinLobbyFinished, , int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(GJMPDelegate, joinLobbyFailed, , int, GJMPErrorCode)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(GJMPDelegate, didUploadMPComment, , int)
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(GJMPDelegate, updateComments, )
		}
	};
}
