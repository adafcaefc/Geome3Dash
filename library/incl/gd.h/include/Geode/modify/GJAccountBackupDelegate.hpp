#pragma once
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/Field.hpp>
#include <Geode/binding/GJAccountBackupDelegate.hpp>
using namespace geode::modifier;
namespace geode::modifier {
    
	#ifndef GEODE_STATICS_backupAccountFinished
		#define GEODE_STATICS_backupAccountFinished
		GEODE_AS_STATIC_FUNCTION(backupAccountFinished) 
	#endif

	#ifndef GEODE_STATICS_backupAccountFailed
		#define GEODE_STATICS_backupAccountFailed
		GEODE_AS_STATIC_FUNCTION(backupAccountFailed) 
	#endif

    
	#ifndef GEODE_CONCEPT_CHECK_backupAccountFinished
		#define GEODE_CONCEPT_CHECK_backupAccountFinished
		GEODE_CONCEPT_FUNCTION_CHECK(backupAccountFinished) 
	#endif

	#ifndef GEODE_CONCEPT_CHECK_backupAccountFailed
		#define GEODE_CONCEPT_CHECK_backupAccountFailed
		GEODE_CONCEPT_FUNCTION_CHECK(backupAccountFailed) 
	#endif


	template<class Der>
	struct ModifyDerive<Der, GJAccountBackupDelegate> : ModifyBase<ModifyDerive<Der, GJAccountBackupDelegate>> {
        using BaseModify = ModifyBase<ModifyDerive<Der, GJAccountBackupDelegate>>;
		using ModifyBase<ModifyDerive<Der, GJAccountBackupDelegate>>::ModifyBase;
		using Base = GJAccountBackupDelegate;
        using Derived = Der;
		void apply() override {

			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(GJAccountBackupDelegate, backupAccountFinished, )
			GEODE_APPLY_MODIFY_FOR_FUNCTION_ERROR(GJAccountBackupDelegate, backupAccountFailed, , BackupAccountError, int)
		}
	};
}
