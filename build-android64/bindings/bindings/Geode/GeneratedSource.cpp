
#include <stdexcept>
#include <Geode/Bindings.hpp>
#include <Geode/utils/addresser.hpp>
#include <Geode/modify/Traits.hpp>
#include <Geode/loader/Tulip.hpp>

using namespace geode;
using namespace geode::modifier;
using cocos2d::CCDestructor;

std::unordered_map<void*, bool>& CCDestructor::destructorLock() {{
	static thread_local std::unordered_map<void*, bool> ret;
	return ret;
}}
bool& CCDestructor::globalLock() {{
	static thread_local bool ret = false;
	return ret; 
}}
bool& CCDestructor::lock(void* self) {
	return destructorLock()[self];
}
CCDestructor::~CCDestructor() {{
	destructorLock().erase(this);
}}

auto wrapFunction(uintptr_t address, tulip::hook::WrapperMetadata const& metadata) {
	auto wrapped = geode::hook::createWrapper(reinterpret_cast<void*>(address), metadata);
	if (wrapped.isErr()) {{
		throw std::runtime_error(wrapped.unwrapErr());
	}}
	return wrapped.unwrap();
}

// So apparently Clang considers cdecl to return floats through ST0, whereas 
// MSVC thinks they are returned through XMM0. This has caused a lot of pain 
// and misery for me


cocos2d::CCEGLViewProtocol::CCEGLViewProtocol() {
	using FunctionType = void(*)(cocos2d::CCEGLViewProtocol*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d17CCEGLViewProtocolC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCEGLViewProtocol::~CCEGLViewProtocol() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCEGLViewProtocol*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d17CCEGLViewProtocolD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	CCDestructor::lock(this) = true;
}

cocos2d::CCObject::CCObject() : cocos2d::CCObject(geode::CutoffConstructor, sizeof(cocos2d::CCObject)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCObject::~CCObject();
	using FunctionType = void(*)(cocos2d::CCObject*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d8CCObjectC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCObject::~CCObject() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCObject*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d8CCObjectD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCObject(geode::CutoffConstructor, sizeof(cocos2d::CCObject));
	CCDestructor::lock(this) = true;
}

cocos2d::CCNode::CCNode() : cocos2d::CCNode(geode::CutoffConstructor, sizeof(cocos2d::CCNode)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCNode::~CCNode();
	using FunctionType = void(*)(cocos2d::CCNode*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d6CCNodeC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCNode::~CCNode() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCNode*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d6CCNodeD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCNode(geode::CutoffConstructor, sizeof(cocos2d::CCNode));
	CCDestructor::lock(this) = true;
}

cocos2d::CCNodeRGBA::CCNodeRGBA() : cocos2d::CCNodeRGBA(geode::CutoffConstructor, sizeof(cocos2d::CCNodeRGBA)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCNodeRGBA::~CCNodeRGBA();
	using FunctionType = void(*)(cocos2d::CCNodeRGBA*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d10CCNodeRGBAC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCNodeRGBA::~CCNodeRGBA() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCNodeRGBA*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d10CCNodeRGBAD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCNodeRGBA(geode::CutoffConstructor, sizeof(cocos2d::CCNodeRGBA));
	CCDestructor::lock(this) = true;
}

cocos2d::CCMotionStreak::CCMotionStreak() : cocos2d::CCMotionStreak(geode::CutoffConstructor, sizeof(cocos2d::CCMotionStreak)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCMotionStreak::~CCMotionStreak();
	using FunctionType = void(*)(cocos2d::CCMotionStreak*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d14CCMotionStreakC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCMotionStreak::~CCMotionStreak() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCMotionStreak*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d14CCMotionStreakD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCMotionStreak(geode::CutoffConstructor, sizeof(cocos2d::CCMotionStreak));
	CCDestructor::lock(this) = true;
}

cocos2d::CCAction::CCAction() : cocos2d::CCAction(geode::CutoffConstructor, sizeof(cocos2d::CCAction)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCAction::~CCAction();
	using FunctionType = void(*)(cocos2d::CCAction*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d8CCActionC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCAction::~CCAction() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCAction*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d8CCActionD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCAction(geode::CutoffConstructor, sizeof(cocos2d::CCAction));
	CCDestructor::lock(this) = true;
}

cocos2d::CCActionInstant::CCActionInstant() : cocos2d::CCActionInstant(geode::CutoffConstructor, sizeof(cocos2d::CCActionInstant)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCActionInstant::~CCActionInstant();
	using FunctionType = void(*)(cocos2d::CCActionInstant*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d15CCActionInstantC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCScene::~CCScene() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCScene*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d7CCSceneD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCScene(geode::CutoffConstructor, sizeof(cocos2d::CCScene));
	CCDestructor::lock(this) = true;
}

cocos2d::CCSet::CCSet() : cocos2d::CCSet(geode::CutoffConstructor, sizeof(cocos2d::CCSet)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCSet::~CCSet();
	using FunctionType = void(*)(cocos2d::CCSet*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d5CCSetC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCSet::~CCSet() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCSet*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d5CCSetD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCSet(geode::CutoffConstructor, sizeof(cocos2d::CCSet));
	CCDestructor::lock(this) = true;
}

cocos2d::CCParticleSystem::~CCParticleSystem() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCParticleSystem*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d16CCParticleSystemD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCParticleSystem(geode::CutoffConstructor, sizeof(cocos2d::CCParticleSystem));
	CCDestructor::lock(this) = true;
}

cocos2d::CCParticleSystemQuad::~CCParticleSystemQuad() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCParticleSystemQuad*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d20CCParticleSystemQuadD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCParticleSystemQuad(geode::CutoffConstructor, sizeof(cocos2d::CCParticleSystemQuad));
	CCDestructor::lock(this) = true;
}

auto cocos2d::CCFileUtils::addSuffix(gd::string p0, gd::string p1) -> decltype(addSuffix(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string, gd::string>::func(&cocos2d::CCFileUtils::addSuffix), this);
	using FunctionType = decltype(addSuffix(p0, p1))(*)(cocos2d::CCFileUtils*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d11CCFileUtils9addSuffixESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCFileUtils::createCCArrayWithContentsOfFile(gd::string const& p0) -> decltype(createCCArrayWithContentsOfFile(p0)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&>::func(&cocos2d::CCFileUtils::createCCArrayWithContentsOfFile), this);
	using FunctionType = decltype(createCCArrayWithContentsOfFile(p0))(*)(cocos2d::CCFileUtils*, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d11CCFileUtils31createCCArrayWithContentsOfFileERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCFileUtils::createCCDictionaryWithContentsOfFile(gd::string const& p0) -> decltype(createCCDictionaryWithContentsOfFile(p0)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&>::func(&cocos2d::CCFileUtils::createCCDictionaryWithContentsOfFile), this);
	using FunctionType = decltype(createCCDictionaryWithContentsOfFile(p0))(*)(cocos2d::CCFileUtils*, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d11CCFileUtils36createCCDictionaryWithContentsOfFileERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCFileUtils::getFullPathForDirectoryAndFilename(gd::string const& p0, gd::string const& p1) -> decltype(getFullPathForDirectoryAndFilename(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&, gd::string const&>::func(&cocos2d::CCFileUtils::getFullPathForDirectoryAndFilename), this);
	using FunctionType = decltype(getFullPathForDirectoryAndFilename(p0, p1))(*)(cocos2d::CCFileUtils*, gd::string const&, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d11CCFileUtils34getFullPathForDirectoryAndFilenameERKSsS1_")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto cocos2d::CCFileUtils::getPathForFilename(gd::string const& p0, gd::string const& p1, gd::string const& p2) -> decltype(getPathForFilename(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&, gd::string const&, gd::string const&>::func(&cocos2d::CCFileUtils::getPathForFilename), this);
	using FunctionType = decltype(getPathForFilename(p0, p1, p2))(*)(cocos2d::CCFileUtils*, gd::string const&, gd::string const&, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d11CCFileUtils18getPathForFilenameERKSsS1_S1_")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto cocos2d::CCFileUtils::isAbsolutePath(gd::string const& p0) -> decltype(isAbsolutePath(p0)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&>::func(&cocos2d::CCFileUtils::isAbsolutePath), this);
	using FunctionType = decltype(isAbsolutePath(p0))(*)(cocos2d::CCFileUtils*, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d11CCFileUtils14isAbsolutePathERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCFileUtils::setAndroidPath(gd::string p0) -> decltype(setAndroidPath(p0)) {
	using FunctionType = decltype(setAndroidPath(p0))(*)(cocos2d::CCFileUtils*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d11CCFileUtils14setAndroidPathESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCFileUtils::setSearchPaths(gd::vector<gd::string> const& p0) -> decltype(setSearchPaths(p0)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string> const&>::func(&cocos2d::CCFileUtils::setSearchPaths), this);
	using FunctionType = decltype(setSearchPaths(p0))(*)(cocos2d::CCFileUtils*, gd::vector<gd::string> const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d11CCFileUtils14setSearchPathsERKSt6vectorISsSaISsEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCFileUtils::setSearchResolutionsOrder(gd::vector<gd::string> const& p0) -> decltype(setSearchResolutionsOrder(p0)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string> const&>::func(&cocos2d::CCFileUtils::setSearchResolutionsOrder), this);
	using FunctionType = decltype(setSearchResolutionsOrder(p0))(*)(cocos2d::CCFileUtils*, gd::vector<gd::string> const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d11CCFileUtils25setSearchResolutionsOrderERKSt6vectorISsSaISsEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto cocos2d::CCFileUtils::writeToFile(cocos2d::CCDictionary* p0, gd::string const& p1) -> decltype(writeToFile(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCDictionary*, gd::string const&>::func(&cocos2d::CCFileUtils::writeToFile), this);
	using FunctionType = decltype(writeToFile(p0, p1))(*)(cocos2d::CCFileUtils*, cocos2d::CCDictionary*, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d11CCFileUtils11writeToFileEPNS_12CCDictionaryERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

cocos2d::CCGLProgram::~CCGLProgram() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCGLProgram*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d11CCGLProgramD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCGLProgram(geode::CutoffConstructor, sizeof(cocos2d::CCGLProgram));
	CCDestructor::lock(this) = true;
}

cocos2d::CCGLProgram::CCGLProgram() : cocos2d::CCGLProgram(geode::CutoffConstructor, sizeof(cocos2d::CCGLProgram)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCGLProgram::~CCGLProgram();
	using FunctionType = void(*)(cocos2d::CCGLProgram*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d11CCGLProgramC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCLayer::CCLayer() : cocos2d::CCLayer(geode::CutoffConstructor, sizeof(cocos2d::CCLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCLayer::~CCLayer();
	using FunctionType = void(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d7CCLayerC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCLayer::~CCLayer() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d7CCLayerD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCLayer(geode::CutoffConstructor, sizeof(cocos2d::CCLayer));
	CCDestructor::lock(this) = true;
}

cocos2d::CCLayerRGBA::CCLayerRGBA() : cocos2d::CCLayerRGBA(geode::CutoffConstructor, sizeof(cocos2d::CCLayerRGBA)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCLayerRGBA::~CCLayerRGBA();
	using FunctionType = void(*)(cocos2d::CCLayerRGBA*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d11CCLayerRGBAC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCLayerRGBA::~CCLayerRGBA() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCLayerRGBA*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d11CCLayerRGBAD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCLayerRGBA(geode::CutoffConstructor, sizeof(cocos2d::CCLayerRGBA));
	CCDestructor::lock(this) = true;
}

cocos2d::CCLayerColor::CCLayerColor() : cocos2d::CCLayerColor(geode::CutoffConstructor, sizeof(cocos2d::CCLayerColor)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCLayerColor::~CCLayerColor();
	using FunctionType = void(*)(cocos2d::CCLayerColor*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d12CCLayerColorC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCLayerColor::~CCLayerColor() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCLayerColor*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d12CCLayerColorD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCLayerColor(geode::CutoffConstructor, sizeof(cocos2d::CCLayerColor));
	CCDestructor::lock(this) = true;
}

cocos2d::CCTexture2D::~CCTexture2D() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d11CCTexture2DD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCTexture2D(geode::CutoffConstructor, sizeof(cocos2d::CCTexture2D));
	CCDestructor::lock(this) = true;
}

cocos2d::CCTexture2D::CCTexture2D() : cocos2d::CCTexture2D(geode::CutoffConstructor, sizeof(cocos2d::CCTexture2D)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCTexture2D::~CCTexture2D();
	using FunctionType = void(*)(cocos2d::CCTexture2D*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d11CCTexture2DC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCImage::CCImage() : cocos2d::CCImage(geode::CutoffConstructor, sizeof(cocos2d::CCImage)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCImage::~CCImage();
	using FunctionType = void(*)(cocos2d::CCImage*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d7CCImageC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCImage::~CCImage() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCImage*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d7CCImageD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCImage(geode::CutoffConstructor, sizeof(cocos2d::CCImage));
	CCDestructor::lock(this) = true;
}

cocos2d::CCIMEDelegate::~CCIMEDelegate() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCIMEDelegate*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d13CCIMEDelegateD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	CCDestructor::lock(this) = true;
}

auto cocos2d::CCDirector::toggleShowFPS(bool p0, gd::string p1, cocos2d::CCPoint p2) -> decltype(toggleShowFPS(p0, p1, p2)) {
	using FunctionType = decltype(toggleShowFPS(p0, p1, p2))(*)(cocos2d::CCDirector*, bool, gd::string, cocos2d::CCPoint);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d10CCDirector13toggleShowFPSEbSsNS_7CCPointE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

cocos2d::CCSprite::CCSprite() : cocos2d::CCSprite(geode::CutoffConstructor, sizeof(cocos2d::CCSprite)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCSprite::~CCSprite();
	using FunctionType = void(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d8CCSpriteC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCSprite::~CCSprite() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCSprite*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d8CCSpriteD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCSprite(geode::CutoffConstructor, sizeof(cocos2d::CCSprite));
	CCDestructor::lock(this) = true;
}

cocos2d::CCSpriteBatchNode::CCSpriteBatchNode() : cocos2d::CCSpriteBatchNode(geode::CutoffConstructor, sizeof(cocos2d::CCSpriteBatchNode)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCSpriteBatchNode::~CCSpriteBatchNode();
	using FunctionType = void(*)(cocos2d::CCSpriteBatchNode*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d17CCSpriteBatchNodeC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCSpriteBatchNode::~CCSpriteBatchNode() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCSpriteBatchNode*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d17CCSpriteBatchNodeD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCSpriteBatchNode(geode::CutoffConstructor, sizeof(cocos2d::CCSpriteBatchNode));
	CCDestructor::lock(this) = true;
}

cocos2d::CCLabelBMFont::CCLabelBMFont() : cocos2d::CCLabelBMFont(geode::CutoffConstructor, sizeof(cocos2d::CCLabelBMFont)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCLabelBMFont::~CCLabelBMFont();
	using FunctionType = void(*)(cocos2d::CCLabelBMFont*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d13CCLabelBMFontC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCLabelBMFont::~CCLabelBMFont() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCLabelBMFont*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d13CCLabelBMFontD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCLabelBMFont(geode::CutoffConstructor, sizeof(cocos2d::CCLabelBMFont));
	CCDestructor::lock(this) = true;
}

auto cocos2d::CCDictionary::setObject(cocos2d::CCObject* p0, gd::string const& p1) -> decltype(setObject(p0, p1)) {
	using FunctionType = decltype(setObject(p0, p1))(*)(cocos2d::CCDictionary*, cocos2d::CCObject*, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d12CCDictionary9setObjectEPNS_8CCObjectERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto cocos2d::CCDictionary::setObjectUnSafe(cocos2d::CCObject* p0, gd::string const& p1) -> decltype(setObjectUnSafe(p0, p1)) {
	using FunctionType = decltype(setObjectUnSafe(p0, p1))(*)(cocos2d::CCDictionary*, cocos2d::CCObject*, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d12CCDictionary15setObjectUnSafeEPNS_8CCObjectERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

cocos2d::CCDictionary::CCDictionary() : cocos2d::CCDictionary(geode::CutoffConstructor, sizeof(cocos2d::CCDictionary)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCDictionary::~CCDictionary();
	using FunctionType = void(*)(cocos2d::CCDictionary*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d12CCDictionaryC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCDictionary::~CCDictionary() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCDictionary*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d12CCDictionaryD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCDictionary(geode::CutoffConstructor, sizeof(cocos2d::CCDictionary));
	CCDestructor::lock(this) = true;
}

auto cocos2d::CCDictionary::charForKey(gd::string const& p0) -> decltype(charForKey(p0)) {
	using FunctionType = decltype(charForKey(p0))(*)(cocos2d::CCDictionary*, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d12CCDictionary10charForKeyERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDictionary::objectForKey(gd::string const& p0) -> decltype(objectForKey(p0)) {
	using FunctionType = decltype(objectForKey(p0))(*)(cocos2d::CCDictionary*, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d12CCDictionary12objectForKeyERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDictionary::removeObjectForKey(gd::string const& p0) -> decltype(removeObjectForKey(p0)) {
	using FunctionType = decltype(removeObjectForKey(p0))(*)(cocos2d::CCDictionary*, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d12CCDictionary18removeObjectForKeyERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto cocos2d::CCDictionary::valueForKey(gd::string const& p0) -> decltype(valueForKey(p0)) {
	using FunctionType = decltype(valueForKey(p0))(*)(cocos2d::CCDictionary*, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d12CCDictionary11valueForKeyERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

cocos2d::CCRenderTexture::CCRenderTexture() : cocos2d::CCRenderTexture(geode::CutoffConstructor, sizeof(cocos2d::CCRenderTexture)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCRenderTexture::~CCRenderTexture();
	using FunctionType = void(*)(cocos2d::CCRenderTexture*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d15CCRenderTextureC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCTransitionScene::~CCTransitionScene() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCTransitionScene*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d17CCTransitionSceneD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCTransitionScene(geode::CutoffConstructor, sizeof(cocos2d::CCTransitionScene));
	CCDestructor::lock(this) = true;
}

cocos2d::CCClippingNode::CCClippingNode() : cocos2d::CCClippingNode(geode::CutoffConstructor, sizeof(cocos2d::CCClippingNode)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCClippingNode::~CCClippingNode();
	using FunctionType = void(*)(cocos2d::CCClippingNode*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d14CCClippingNodeC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCClippingNode::~CCClippingNode() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCClippingNode*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d14CCClippingNodeD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCClippingNode(geode::CutoffConstructor, sizeof(cocos2d::CCClippingNode));
	CCDestructor::lock(this) = true;
}

cocos2d::CCDrawNode::CCDrawNode() : cocos2d::CCDrawNode(geode::CutoffConstructor, sizeof(cocos2d::CCDrawNode)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCDrawNode::~CCDrawNode();
	using FunctionType = void(*)(cocos2d::CCDrawNode*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d10CCDrawNodeC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCDrawNode::~CCDrawNode() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCDrawNode*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d10CCDrawNodeD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCDrawNode(geode::CutoffConstructor, sizeof(cocos2d::CCDrawNode));
	CCDestructor::lock(this) = true;
}

auto cocos2d::CCSpriteFrame::setFrameName(gd::string p0) -> decltype(setFrameName(p0)) {
	using FunctionType = decltype(setFrameName(p0))(*)(cocos2d::CCSpriteFrame*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d13CCSpriteFrame12setFrameNameESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

cocos2d::CCMenuItem::~CCMenuItem() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCMenuItem*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d10CCMenuItemD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCMenuItem(geode::CutoffConstructor, sizeof(cocos2d::CCMenuItem));
	CCDestructor::lock(this) = true;
}

auto cocos2d::cc_utf8_trim_ws(gd::vector<unsigned short>* p0) -> decltype(cc_utf8_trim_ws(p0)) {
	using FunctionType = decltype(cc_utf8_trim_ws(p0))(*)(gd::vector<unsigned short>*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d15cc_utf8_trim_wsEPSt6vectorItSaItEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

DS_Dictionary::DS_Dictionary() {
	using FunctionType = void(*)(DS_Dictionary*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DS_DictionaryC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

auto DS_Dictionary::addBoolValuesToMapForKey(gd::map<gd::string, bool>& p0, char const* p1, bool p2) -> decltype(addBoolValuesToMapForKey(p0, p1, p2)) {
	using FunctionType = decltype(addBoolValuesToMapForKey(p0, p1, p2))(*)(DS_Dictionary*, gd::map<gd::string, bool>&, char const*, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DS_Dictionary24addBoolValuesToMapForKeyERSt3mapISsbSt4lessISsESaISt4pairIKSsbEEEPKcb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto DS_Dictionary::addBoolValuesToMapForKeySpecial(gd::map<gd::string, bool>& p0, char const* p1, bool p2) -> decltype(addBoolValuesToMapForKeySpecial(p0, p1, p2)) {
	using FunctionType = decltype(addBoolValuesToMapForKeySpecial(p0, p1, p2))(*)(DS_Dictionary*, gd::map<gd::string, bool>&, char const*, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DS_Dictionary31addBoolValuesToMapForKeySpecialERSt3mapISsbSt4lessISsESaISt4pairIKSsbEEEPKcb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto DS_Dictionary::cleanStringWhiteSpace(gd::string const& p0) -> decltype(cleanStringWhiteSpace(p0)) {
	using FunctionType = decltype(cleanStringWhiteSpace(p0))(*)(DS_Dictionary*, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DS_Dictionary21cleanStringWhiteSpaceERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto DS_Dictionary::loadRootSubDictFromString(gd::string const& p0) -> decltype(loadRootSubDictFromString(p0)) {
	using FunctionType = decltype(loadRootSubDictFromString(p0))(*)(DS_Dictionary*, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DS_Dictionary25loadRootSubDictFromStringERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto DS_Dictionary::rectFromString(gd::string const& p0, cocos2d::CCRect& p1) -> decltype(rectFromString(p0, p1)) {
	using FunctionType = decltype(rectFromString(p0, p1))(*)(DS_Dictionary*, gd::string const&, cocos2d::CCRect&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DS_Dictionary14rectFromStringERKSsRN7cocos2d6CCRectE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto DS_Dictionary::setBoolMapForKey(char const* p0, gd::map<gd::string, bool>& p1) -> decltype(setBoolMapForKey(p0, p1)) {
	using FunctionType = decltype(setBoolMapForKey(p0, p1))(*)(DS_Dictionary*, char const*, gd::map<gd::string, bool>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DS_Dictionary16setBoolMapForKeyEPKcRSt3mapISsbSt4lessISsESaISt4pairIKSsbEEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto DS_Dictionary::setRectArrayForKey(char const* p0, gd::vector<cocos2d::CCRect> const& p1) -> decltype(setRectArrayForKey(p0, p1)) {
	using FunctionType = decltype(setRectArrayForKey(p0, p1))(*)(DS_Dictionary*, char const*, gd::vector<cocos2d::CCRect> const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DS_Dictionary18setRectArrayForKeyEPKcRKSt6vectorI7cocos2d6CCRectSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto DS_Dictionary::setRectArrayForKey(char const* p0, gd::vector<cocos2d::CCRect> const& p1, bool p2) -> decltype(setRectArrayForKey(p0, p1, p2)) {
	using FunctionType = decltype(setRectArrayForKey(p0, p1, p2))(*)(DS_Dictionary*, char const*, gd::vector<cocos2d::CCRect> const&, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DS_Dictionary18setRectArrayForKeyEPKcRKSt6vectorI7cocos2d6CCRectSaIS4_EEb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto DS_Dictionary::setStringArrayForKey(char const* p0, gd::vector<gd::string> const& p1) -> decltype(setStringArrayForKey(p0, p1)) {
	using FunctionType = decltype(setStringArrayForKey(p0, p1))(*)(DS_Dictionary*, char const*, gd::vector<gd::string> const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DS_Dictionary20setStringArrayForKeyEPKcRKSt6vectorISsSaISsEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto DS_Dictionary::setStringArrayForKey(char const* p0, gd::vector<gd::string> const& p1, bool p2) -> decltype(setStringArrayForKey(p0, p1, p2)) {
	using FunctionType = decltype(setStringArrayForKey(p0, p1, p2))(*)(DS_Dictionary*, char const*, gd::vector<gd::string> const&, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DS_Dictionary20setStringArrayForKeyEPKcRKSt6vectorISsSaISsEEb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto DS_Dictionary::setStringForKey(char const* p0, gd::string const& p1) -> decltype(setStringForKey(p0, p1)) {
	using FunctionType = decltype(setStringForKey(p0, p1))(*)(DS_Dictionary*, char const*, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DS_Dictionary15setStringForKeyEPKcRKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto DS_Dictionary::setStringForKey(char const* p0, gd::string const& p1, bool p2) -> decltype(setStringForKey(p0, p1, p2)) {
	using FunctionType = decltype(setStringForKey(p0, p1, p2))(*)(DS_Dictionary*, char const*, gd::string const&, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DS_Dictionary15setStringForKeyEPKcRKSsb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto DS_Dictionary::setVec2ArrayForKey(char const* p0, gd::vector<cocos2d::CCPoint> const& p1) -> decltype(setVec2ArrayForKey(p0, p1)) {
	using FunctionType = decltype(setVec2ArrayForKey(p0, p1))(*)(DS_Dictionary*, char const*, gd::vector<cocos2d::CCPoint> const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DS_Dictionary18setVec2ArrayForKeyEPKcRKSt6vectorI7cocos2d7CCPointSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto DS_Dictionary::setVec2ArrayForKey(char const* p0, gd::vector<cocos2d::CCPoint> const& p1, bool p2) -> decltype(setVec2ArrayForKey(p0, p1, p2)) {
	using FunctionType = decltype(setVec2ArrayForKey(p0, p1, p2))(*)(DS_Dictionary*, char const*, gd::vector<cocos2d::CCPoint> const&, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DS_Dictionary18setVec2ArrayForKeyEPKcRKSt6vectorI7cocos2d7CCPointSaIS4_EEb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto DS_Dictionary::split(gd::string const& p0, char const* p1, gd::vector<gd::string>& p2) -> decltype(split(p0, p1, p2)) {
	using FunctionType = decltype(split(p0, p1, p2))(*)(DS_Dictionary*, gd::string const&, char const*, gd::vector<gd::string>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DS_Dictionary5splitERKSsPKcRSt6vectorISsSaISsEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto DS_Dictionary::splitWithForm(gd::string const& p0, gd::vector<gd::string>& p1) -> decltype(splitWithForm(p0, p1)) {
	using FunctionType = decltype(splitWithForm(p0, p1))(*)(DS_Dictionary*, gd::string const&, gd::vector<gd::string>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DS_Dictionary13splitWithFormERKSsRSt6vectorISsSaISsEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto DS_Dictionary::vec2FromString(gd::string const& p0, cocos2d::CCPoint& p1) -> decltype(vec2FromString(p0, p1)) {
	using FunctionType = decltype(vec2FromString(p0, p1))(*)(DS_Dictionary*, gd::string const&, cocos2d::CCPoint&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DS_Dictionary14vec2FromStringERKSsRN7cocos2d7CCPointE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

cocos2d::extension::CCScale9Sprite::CCScale9Sprite() : cocos2d::extension::CCScale9Sprite(geode::CutoffConstructor, sizeof(cocos2d::extension::CCScale9Sprite)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::extension::CCScale9Sprite::~CCScale9Sprite();
	using FunctionType = void(*)(cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d9extension14CCScale9SpriteC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::extension::CCScale9Sprite::~CCScale9Sprite() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::extension::CCScale9Sprite*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d9extension14CCScale9SpriteD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::extension::CCScale9Sprite(geode::CutoffConstructor, sizeof(cocos2d::extension::CCScale9Sprite));
	CCDestructor::lock(this) = true;
}

auto cocos2d::ZipUtils::base64DecodeEnc(gd::string const& p0, gd::string p1) -> decltype(base64DecodeEnc(p0, p1)) {
	using FunctionType = decltype(base64DecodeEnc(p0, p1))(*)(gd::string const&, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d8ZipUtils15base64DecodeEncERKSsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::ZipUtils::base64EncodeEnc(gd::string const& p0, gd::string p1) -> decltype(base64EncodeEnc(p0, p1)) {
	using FunctionType = decltype(base64EncodeEnc(p0, p1))(*)(gd::string const&, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d8ZipUtils15base64EncodeEncERKSsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::ZipUtils::base64URLDecode(gd::string const& p0) -> decltype(base64URLDecode(p0)) {
	using FunctionType = decltype(base64URLDecode(p0))(*)(gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d8ZipUtils15base64URLDecodeERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ZipUtils::base64URLEncode(gd::string const& p0) -> decltype(base64URLEncode(p0)) {
	using FunctionType = decltype(base64URLEncode(p0))(*)(gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d8ZipUtils15base64URLEncodeERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ZipUtils::compressString(gd::string const& data, bool encrypt, int encryptionKey) -> decltype(compressString(data, encrypt, encryptionKey)) {
	using FunctionType = decltype(compressString(data, encrypt, encryptionKey))(*)(gd::string const&, bool, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d8ZipUtils14compressStringERKSsbi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(data, encrypt, encryptionKey);
}

auto cocos2d::ZipUtils::decompressString(gd::string const& data, bool encrypt, int encryptionKey) -> decltype(decompressString(data, encrypt, encryptionKey)) {
	using FunctionType = decltype(decompressString(data, encrypt, encryptionKey))(*)(gd::string const&, bool, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d8ZipUtils16decompressStringERKSsbi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(data, encrypt, encryptionKey);
}

auto cocos2d::ZipUtils::encryptDecrypt(gd::string const& data, int encryptionKey) -> decltype(encryptDecrypt(data, encryptionKey)) {
	using FunctionType = decltype(encryptDecrypt(data, encryptionKey))(*)(gd::string const&, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d8ZipUtils14encryptDecryptERKSsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(data, encryptionKey);
}

auto cocos2d::ZipUtils::encryptDecryptWKey(gd::string const& p0, gd::string p1) -> decltype(encryptDecryptWKey(p0, p1)) {
	using FunctionType = decltype(encryptDecryptWKey(p0, p1))(*)(gd::string const&, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d8ZipUtils18encryptDecryptWKeyERKSsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto cocos2d::ZipUtils::hexToChar(gd::string const& p0) -> decltype(hexToChar(p0)) {
	using FunctionType = decltype(hexToChar(p0))(*)(gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d8ZipUtils9hexToCharERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto cocos2d::ZipUtils::urlDecode(gd::string const& p0) -> decltype(urlDecode(p0)) {
	using FunctionType = decltype(urlDecode(p0))(*)(gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d8ZipUtils9urlDecodeERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

pugi::xml_document::xml_document() {
	using FunctionType = void(*)(pugi::xml_document*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN4pugi12xml_documentC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

pugi::xml_document::~xml_document() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(pugi::xml_document*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN4pugi12xml_documentD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	CCDestructor::lock(this) = true;
}

pugi::xml_node::xml_node() {
	using FunctionType = void(*)(pugi::xml_node*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN4pugi8xml_nodeC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCLightning::CCLightning() : cocos2d::CCLightning(geode::CutoffConstructor, sizeof(cocos2d::CCLightning)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	cocos2d::CCLightning::~CCLightning();
	using FunctionType = void(*)(cocos2d::CCLightning*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d11CCLightningC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

cocos2d::CCLightning::~CCLightning() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(cocos2d::CCLightning*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d11CCLightningD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) cocos2d::CCLightning(geode::CutoffConstructor, sizeof(cocos2d::CCLightning));
	CCDestructor::lock(this) = true;
}

auto cocos2d::CCConfiguration::checkForGLExtension(gd::string const& p0) const  -> decltype(checkForGLExtension(p0)) {
	using FunctionType = decltype(checkForGLExtension(p0))(*)(cocos2d::CCConfiguration const *, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7cocos2d15CCConfiguration19checkForGLExtensionERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

bool GJDropDownLayer::ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) { return true; }

void GJDropDownLayer::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

void GJDropDownLayer::ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

void GJDropDownLayer::ccTouchCancelled(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

void GJDropDownLayer::customSetup() {}

void GJDropDownLayer::enterAnimFinished() {}

void FLAlertLayerProtocol::FLAlert_Clicked(FLAlertLayer* p0, bool p1) {}

auto AccountLayer::createToggleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCMenu* p3, cocos2d::CCPoint p4) -> decltype(createToggleButton(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(createToggleButton(p0, p1, p2, p3, p4))(*)(AccountLayer*, gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12AccountLayer18createToggleButtonESsMN7cocos2d8CCObjectEFvPS1_EbPNS0_6CCMenuENS0_7CCPointE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

void AccountLayer::exitLayer() {
        this->setKeypadEnabled(false);
        this->disableUI();
        this->hideLayer(m_fastMenu);
    }

void AccountLayer::hideLoadingUI() {
        this->toggleUI(true);
        m_loadingCircle->setVisible(false);
    }

void AccountLayer::showLoadingUI() {
        this->toggleUI(false);
        m_loadingCircle->setVisible(true);
    }

void AccountLayer::toggleUI(bool enable) {
        m_buttonMenu->setEnabled(enable);
        this->setKeypadEnabled(enable);
    }

FLAlertLayer::FLAlertLayer() { // ios 0xa7ec : this seems too small?
        m_buttonMenu = nullptr;
        m_controlConnected = -1;
        m_mainLayer = nullptr;
        m_ZOrder = 0;
        m_noElasticity = false;
        m_reverseKeyBack = false;
        m_scene = nullptr;
        m_alertProtocol = nullptr;
        m_scrollingLayer = nullptr;
        m_button2 = nullptr;
        m_button1 = nullptr;
        m_joystickConnected = -1;
        m_containsBorder = 0;
        m_forcePrioRegistered = false;
    }

FLAlertLayer::~FLAlertLayer() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(FLAlertLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12FLAlertLayerD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) FLAlertLayer(geode::CutoffConstructor, sizeof(FLAlertLayer));
	CCDestructor::lock(this) = true;
}

auto FLAlertLayer::create(FLAlertLayerProtocol* delegate, char const* title, gd::string desc, char const* btn1, char const* btn2, float width, bool scroll, float height, float textScale) -> decltype(create(delegate, title, desc, btn1, btn2, width, scroll, height, textScale)) {
	using FunctionType = decltype(create(delegate, title, desc, btn1, btn2, width, scroll, height, textScale))(*)(FLAlertLayerProtocol*, char const*, gd::string, char const*, char const*, float, bool, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12FLAlertLayer6createEP20FLAlertLayerProtocolPKcSsS3_S3_fbff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(delegate, title, desc, btn1, btn2, width, scroll, height, textScale);
}

auto FLAlertLayer::create(FLAlertLayerProtocol* delegate, char const* title, gd::string desc, char const* btn1, char const* btn2, float width) -> decltype(create(delegate, title, desc, btn1, btn2, width)) {
	using FunctionType = decltype(create(delegate, title, desc, btn1, btn2, width))(*)(FLAlertLayerProtocol*, char const*, gd::string, char const*, char const*, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12FLAlertLayer6createEP20FLAlertLayerProtocolPKcSsS3_S3_f")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(delegate, title, desc, btn1, btn2, width);
}

FLAlertLayer* FLAlertLayer::create(FLAlertLayerProtocol* delegate, char const* title, gd::string desc, char const* btn1, char const* btn2) {
        return FLAlertLayer::create(delegate, title, desc, btn1, btn2, 300.0);
    }

FLAlertLayer* FLAlertLayer::create(char const* title, const gd::string& desc, char const* btn) {
        return FLAlertLayer::create(nullptr, title, desc, btn, nullptr, 300.0);
    }

auto FLAlertLayer::init(FLAlertLayerProtocol* p0, char const* p1, gd::string p2, char const* p3, char const* p4, float p5, bool p6, float p7, float p8) -> decltype(init(p0, p1, p2, p3, p4, p5, p6, p7, p8)) {
	using FunctionType = decltype(init(p0, p1, p2, p3, p4, p5, p6, p7, p8))(*)(FLAlertLayer*, FLAlertLayerProtocol*, char const*, gd::string, char const*, char const*, float, bool, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12FLAlertLayer4initEP20FLAlertLayerProtocolPKcSsS3_S3_fbff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7, p8);
}

void TextInputDelegate::textChanged(CCTextInputNode* p0) {}

void TextInputDelegate::textInputOpened(CCTextInputNode* p0) {}

void TextInputDelegate::textInputClosed(CCTextInputNode* p0) {}

void TextInputDelegate::textInputShouldOffset(CCTextInputNode* p0, float p1) {}

void TextInputDelegate::textInputReturn(CCTextInputNode* p0) {}

bool TextInputDelegate::allowTextInput(CCTextInputNode* p0) { return true; }

void TextInputDelegate::enterPressed(CCTextInputNode* p0) {}

auto AccountLoginLayer::create(gd::string p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17AccountLoginLayer6createESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

void AccountLoginLayer::textInputOpened(CCTextInputNode* p0) {}

void AccountLoginLayer::textChanged(CCTextInputNode* p0) {}

auto AccountLoginLayer::init(gd::string p0) -> decltype(init(p0)) {
	using FunctionType = decltype(init(p0))(*)(AccountLoginLayer*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17AccountLoginLayer4initESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

void AccountRegisterLayer::textInputOpened(CCTextInputNode* p0) {}

void AccountRegisterLayer::textChanged(CCTextInputNode* p0) {}

auto AccountRegisterLayer::createTextInput(cocos2d::CCPoint p0, cocos2d::CCSize p1, gd::string p2, int p3) -> decltype(createTextInput(p0, p1, p2, p3)) {
	using FunctionType = decltype(createTextInput(p0, p1, p2, p3))(*)(AccountRegisterLayer*, cocos2d::CCPoint, cocos2d::CCSize, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20AccountRegisterLayer15createTextInputEN7cocos2d7CCPointENS0_6CCSizeESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto AccountRegisterLayer::createTextLabel(cocos2d::CCPoint p0, gd::string p1, cocos2d::CCSize p2) -> decltype(createTextLabel(p0, p1, p2)) {
	using FunctionType = decltype(createTextLabel(p0, p1, p2))(*)(AccountRegisterLayer*, cocos2d::CCPoint, gd::string, cocos2d::CCSize);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20AccountRegisterLayer15createTextLabelEN7cocos2d7CCPointESsNS0_6CCSizeE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto AccountRegisterLayer::validEmail(gd::string p0) -> decltype(validEmail(p0)) {
	using FunctionType = decltype(validEmail(p0))(*)(AccountRegisterLayer*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20AccountRegisterLayer10validEmailESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto AccountRegisterLayer::validPassword(gd::string p0) -> decltype(validPassword(p0)) {
	using FunctionType = decltype(validPassword(p0))(*)(AccountRegisterLayer*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20AccountRegisterLayer13validPasswordESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto AccountRegisterLayer::validUser(gd::string p0) -> decltype(validUser(p0)) {
	using FunctionType = decltype(validUser(p0))(*)(AccountRegisterLayer*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20AccountRegisterLayer9validUserESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

AchievementBar::AchievementBar(unsigned int idk) : AchievementBar(geode::CutoffConstructor, sizeof(AchievementBar)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	AchievementBar::~AchievementBar();
	using FunctionType = void(*)(AchievementBar*, unsigned int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14AchievementBarC2Ej")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, idk);
}

CCIndexPath::CCIndexPath() {}

TableViewCell::TableViewCell(char const* p0, float p1, float p2) : TableViewCell(geode::CutoffConstructor, sizeof(TableViewCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	TableViewCell::~TableViewCell();
	using FunctionType = void(*)(TableViewCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13TableViewCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

AchievementCell::AchievementCell(char const* p0, float p1, float p2) : AchievementCell(geode::CutoffConstructor, sizeof(AchievementCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	AchievementCell::~AchievementCell();
	using FunctionType = void(*)(AchievementCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15AchievementCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto AchievementManager::addAchievement(gd::string p0, gd::string p1, gd::string p2, gd::string p3, gd::string p4, int p5) -> decltype(addAchievement(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(addAchievement(p0, p1, p2, p3, p4, p5))(*)(AchievementManager*, gd::string, gd::string, gd::string, gd::string, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN18AchievementManager14addAchievementESsSsSsSsSsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto AchievementManager::isAchievementAvailable(gd::string p0) -> decltype(isAchievementAvailable(p0)) {
	using FunctionType = decltype(isAchievementAvailable(p0))(*)(AchievementManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN18AchievementManager22isAchievementAvailableESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto AchievementManager::limitForAchievement(gd::string id) -> decltype(limitForAchievement(id)) {
	using FunctionType = decltype(limitForAchievement(id))(*)(AchievementManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN18AchievementManager19limitForAchievementESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, id);
}

AchievementsLayer::AchievementsLayer() : AchievementsLayer(geode::CutoffConstructor, sizeof(AchievementsLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	AchievementsLayer::~AchievementsLayer();
	using FunctionType = void(*)(AchievementsLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17AchievementsLayerC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

GameObject::GameObject() : GameObject(geode::CutoffConstructor, sizeof(GameObject)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	GameObject::~GameObject();
	using FunctionType = void(*)(GameObject*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10GameObjectC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

auto GameObject::objectFromVector(gd::vector<gd::string>& p0, gd::vector<void*>& p1, GJBaseGameLayer* p2, bool p3) -> decltype(objectFromVector(p0, p1, p2, p3)) {
	using FunctionType = decltype(objectFromVector(p0, p1, p2, p3))(*)(gd::vector<gd::string>&, gd::vector<void*>&, GJBaseGameLayer*, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10GameObject16objectFromVectorERSt6vectorISsSaISsEERS0_IPvSaIS4_EEP15GJBaseGameLayerb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto GameObject::setupCustomSprites(gd::string p0) -> decltype(setupCustomSprites(p0)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string>::func(&GameObject::setupCustomSprites), this);
	using FunctionType = decltype(setupCustomSprites(p0))(*)(GameObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10GameObject18setupCustomSpritesESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto GameObject::triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2) -> decltype(triggerObject(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*, int, gd::vector<int> const*>::func(&GameObject::triggerObject), this);
	using FunctionType = decltype(triggerObject(p0, p1, p2))(*)(GameObject*, GJBaseGameLayer*, int, gd::vector<int> const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10GameObject13triggerObjectEP15GJBaseGameLayeriPKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto GameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&GameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(GameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10GameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto GameObject::addColorSprite(gd::string p0) -> decltype(addColorSprite(p0)) {
	using FunctionType = decltype(addColorSprite(p0))(*)(GameObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10GameObject14addColorSpriteESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameObject::addCustomBlackChild(gd::string p0, float p1, bool p2) -> decltype(addCustomBlackChild(p0, p1, p2)) {
	using FunctionType = decltype(addCustomBlackChild(p0, p1, p2))(*)(GameObject*, gd::string, float, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10GameObject19addCustomBlackChildESsfb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GameObject::addCustomChild(gd::string p0, cocos2d::CCPoint p1, int p2) -> decltype(addCustomChild(p0, p1, p2)) {
	using FunctionType = decltype(addCustomChild(p0, p1, p2))(*)(GameObject*, gd::string, cocos2d::CCPoint, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10GameObject14addCustomChildESsN7cocos2d7CCPointEi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GameObject::addCustomColorChild(gd::string p0) -> decltype(addCustomColorChild(p0)) {
	using FunctionType = decltype(addCustomColorChild(p0))(*)(GameObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10GameObject19addCustomColorChildESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameObject::addGlow(gd::string p0) -> decltype(addGlow(p0)) {
	using FunctionType = decltype(addGlow(p0))(*)(GameObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10GameObject7addGlowESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameObject::addInternalChild(cocos2d::CCSprite* p0, gd::string p1, cocos2d::CCPoint p2, int p3) -> decltype(addInternalChild(p0, p1, p2, p3)) {
	using FunctionType = decltype(addInternalChild(p0, p1, p2, p3))(*)(GameObject*, cocos2d::CCSprite*, gd::string, cocos2d::CCPoint, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10GameObject16addInternalChildEPN7cocos2d8CCSpriteESsNS0_7CCPointEi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto GameObject::addInternalCustomColorChild(gd::string p0, cocos2d::CCPoint p1, int p2) -> decltype(addInternalCustomColorChild(p0, p1, p2)) {
	using FunctionType = decltype(addInternalCustomColorChild(p0, p1, p2))(*)(GameObject*, gd::string, cocos2d::CCPoint, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10GameObject27addInternalCustomColorChildESsN7cocos2d7CCPointEi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GameObject::addInternalGlowChild(gd::string p0, cocos2d::CCPoint p1) -> decltype(addInternalGlowChild(p0, p1)) {
	using FunctionType = decltype(addInternalGlowChild(p0, p1))(*)(GameObject*, gd::string, cocos2d::CCPoint);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10GameObject20addInternalGlowChildESsN7cocos2d7CCPointE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GameObject::createGlow(gd::string p0) -> decltype(createGlow(p0)) {
	using FunctionType = decltype(createGlow(p0))(*)(GameObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10GameObject10createGlowESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameObject::getColorFrame(gd::string p0) -> decltype(getColorFrame(p0)) {
	using FunctionType = decltype(getColorFrame(p0))(*)(GameObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10GameObject13getColorFrameESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameObject::getGlowFrame(gd::string p0) -> decltype(getGlowFrame(p0)) {
	using FunctionType = decltype(getGlowFrame(p0))(*)(GameObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10GameObject12getGlowFrameESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameObject::loadGroupsFromString(gd::string p0) -> decltype(loadGroupsFromString(p0)) {
	using FunctionType = decltype(loadGroupsFromString(p0))(*)(GameObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10GameObject20loadGroupsFromStringESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto EnhancedGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&EnhancedGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(EnhancedGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN18EnhancedGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto EffectGameObject::triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2) -> decltype(triggerObject(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*, int, gd::vector<int> const*>::func(&EffectGameObject::triggerObject), this);
	using FunctionType = decltype(triggerObject(p0, p1, p2))(*)(EffectGameObject*, GJBaseGameLayer*, int, gd::vector<int> const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16EffectGameObject13triggerObjectEP15GJBaseGameLayeriPKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto EffectGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&EffectGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(EffectGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16EffectGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto AdvancedFollowTriggerObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&AdvancedFollowTriggerObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(AdvancedFollowTriggerObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN27AdvancedFollowTriggerObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto AdvancedFollowEditObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&AdvancedFollowEditObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(AdvancedFollowEditObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN24AdvancedFollowEditObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto SpritePartDelegate::displayFrameChanged(cocos2d::CCObject* p0, gd::string p1) -> decltype(displayFrameChanged(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*, gd::string>::func(&SpritePartDelegate::displayFrameChanged), this);
	using FunctionType = decltype(displayFrameChanged(p0, p1))(*)(SpritePartDelegate*, cocos2d::CCObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN18SpritePartDelegate19displayFrameChangedEPN7cocos2d8CCObjectESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto AnimatedGameObject::displayFrameChanged(cocos2d::CCObject* p0, gd::string p1) -> decltype(displayFrameChanged(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<cocos2d::CCObject*, gd::string>::func(&AnimatedGameObject::displayFrameChanged), this);
	using FunctionType = decltype(displayFrameChanged(p0, p1))(*)(AnimatedGameObject*, cocos2d::CCObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN18AnimatedGameObject19displayFrameChangedEPN7cocos2d8CCObjectESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

CCAnimatedSprite::CCAnimatedSprite() {
        m_unkString1 = "";
        m_unkString2 = "";
        m_animationManager = nullptr;
        m_sprite = nullptr;
        m_fbfSprite = nullptr;
        m_paSprite = nullptr;
        m_spriteMode = (spriteMode)0;
        m_currentAnim = "";
        m_delegate = nullptr;
    }

auto CCAnimatedSprite::runAnimation(gd::string p0) -> decltype(runAnimation(p0)) {
	using FunctionType = decltype(runAnimation(p0))(*)(CCAnimatedSprite*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16CCAnimatedSprite12runAnimationESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto CCAnimatedSprite::runAnimationForced(gd::string p0) -> decltype(runAnimationForced(p0)) {
	using FunctionType = decltype(runAnimationForced(p0))(*)(CCAnimatedSprite*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16CCAnimatedSprite18runAnimationForcedESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto CCAnimatedSprite::tweenToAnimation(gd::string p0, float p1) -> decltype(tweenToAnimation(p0, p1)) {
	using FunctionType = decltype(tweenToAnimation(p0, p1))(*)(CCAnimatedSprite*, gd::string, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16CCAnimatedSprite16tweenToAnimationESsf")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

AnimatedShopKeeper::AnimatedShopKeeper() {
        m_type = ShopType::Normal;
        m_idleInt1 = 0;
        m_idleInt2 = 0;
        m_looking = false;
        m_reacting = false;
        m_reactCount = 0;
        m_gruntIndex = 0;
    }

ArtistCell::ArtistCell(char const* p0, float p1, float p2) : ArtistCell(geode::CutoffConstructor, sizeof(ArtistCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	ArtistCell::~ArtistCell();
	using FunctionType = void(*)(ArtistCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10ArtistCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto ArtTriggerGameObject::triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2) -> decltype(triggerObject(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*, int, gd::vector<int> const*>::func(&ArtTriggerGameObject::triggerObject), this);
	using FunctionType = decltype(triggerObject(p0, p1, p2))(*)(ArtTriggerGameObject*, GJBaseGameLayer*, int, gd::vector<int> const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20ArtTriggerGameObject13triggerObjectEP15GJBaseGameLayeriPKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto ArtTriggerGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&ArtTriggerGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(ArtTriggerGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20ArtTriggerGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

void MusicDownloadDelegate::loadSongInfoFinished(SongInfoObject* p0) {}

void MusicDownloadDelegate::loadSongInfoFailed(int p0, GJSongError p1) {}

void MusicDownloadDelegate::downloadSongFinished(int p0) {}

void MusicDownloadDelegate::downloadSongFailed(int p0, GJSongError p1) {}

void MusicDownloadDelegate::songStateChanged() {}

void MusicDownloadDelegate::downloadSFXFinished(int p0) {}

void MusicDownloadDelegate::downloadSFXFailed(int p0, GJSongError p1) {}

void MusicDownloadDelegate::musicActionFinished(GJMusicAction p0) {}

void MusicDownloadDelegate::musicActionFailed(GJMusicAction p0) {}

auto AudioAssetsBrowser::create(gd::vector<int>& songIds, gd::vector<int>& sfxIds) -> decltype(create(songIds, sfxIds)) {
	using FunctionType = decltype(create(songIds, sfxIds))(*)(gd::vector<int>&, gd::vector<int>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN18AudioAssetsBrowser6createERSt6vectorIiSaIiEES3_")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(songIds, sfxIds);
}

auto AudioAssetsBrowser::init(gd::vector<int>& songIds, gd::vector<int>& sfxIds) -> decltype(init(songIds, sfxIds)) {
	using FunctionType = decltype(init(songIds, sfxIds))(*)(AudioAssetsBrowser*, gd::vector<int>&, gd::vector<int>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN18AudioAssetsBrowser4initERSt6vectorIiSaIiEES3_")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, songIds, sfxIds);
}

auto AudioEffectsLayer::create(gd::string p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17AudioEffectsLayer6createESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

void AudioEffectsLayer::draw() {}

auto AudioEffectsLayer::init(gd::string p0) -> decltype(init(p0)) {
	using FunctionType = decltype(init(p0))(*)(AudioEffectsLayer*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17AudioEffectsLayer4initESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto AudioLineGuideGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&AudioLineGuideGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(AudioLineGuideGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN24AudioLineGuideGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

BitmapFontCache::BitmapFontCache() {}

auto BonusDropdown::create(gd::string p0, int p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13BonusDropdown6createESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto BonusDropdown::init(gd::string p0, int p1) -> decltype(init(p0, p1)) {
	using FunctionType = decltype(init(p0, p1))(*)(BonusDropdown*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13BonusDropdown4initESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

void TableViewDelegate::willTweenToIndexPath(CCIndexPath& p0, TableViewCell* p1, TableView* p2) {}

void TableViewDelegate::didEndTweenToIndexPath(CCIndexPath& p0, TableView* p1) {}

void TableViewDelegate::TableViewWillDisplayCellForRowAtIndexPath(CCIndexPath& p0, TableViewCell* p1, TableView* p2) {}

void TableViewDelegate::TableViewDidDisplayCellForRowAtIndexPath(CCIndexPath& p0, TableViewCell* p1, TableView* p2) {}

void TableViewDelegate::TableViewWillReloadCellForRowAtIndexPath(CCIndexPath& p0, TableViewCell* p1, TableView* p2) {}

float TableViewDelegate::cellHeightForRowAtIndexPath(CCIndexPath& p0, TableView* p1) { return 0; }

void TableViewDelegate::didSelectRowAtIndexPath(CCIndexPath& p0, TableView* p1) {}

int TableViewDataSource::numberOfRowsInSection(unsigned int p0, TableView* p1) { return 0; }

unsigned int TableViewDataSource::numberOfSectionsInTableView(TableView* p0) { return 0; }

void TableViewDataSource::TableViewCommitCellEditingStyleForRowAtIndexPath(TableView* p0, TableViewCellEditingStyle p1, CCIndexPath& p2) {}

TableViewCell* TableViewDataSource::cellForRowAtIndexPath(CCIndexPath& p0, TableView* p1) { return nullptr; }

BoomListView::BoomListView() {}

BoomListView::~BoomListView() {
        CC_SAFE_RELEASE(m_entries);
    }

void BoomListView::draw() {}

void BoomListView::TableViewWillDisplayCellForRowAtIndexPath(CCIndexPath& p0, TableViewCell* p1, TableView* p2) {}

void BoomListView::didSelectRowAtIndexPath(CCIndexPath& p0, TableView* p1) {}

unsigned int BoomListView::numberOfSectionsInTableView(TableView* p0) { return 1; }

void BoomListView::TableViewCommitCellEditingStyleForRowAtIndexPath(TableView* p0, TableViewCellEditingStyle p1, CCIndexPath& p2) {}

void BoomListView::TableViewWillReloadCellForRowAtIndexPath(CCIndexPath& p0, TableViewCell* p1, TableView* p2) {}

bool BoomListView::init(cocos2d::CCArray* entries, BoomListType type, float width, float height) {
        return this->init(entries, nullptr, height, width, 0, type, 0.0f);
    }

BoomScrollLayer::BoomScrollLayer() : BoomScrollLayer(geode::CutoffConstructor, sizeof(BoomScrollLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	BoomScrollLayer::~BoomScrollLayer();
	using FunctionType = void(*)(BoomScrollLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15BoomScrollLayerC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

auto BrowseSmartTemplateLayer::createPrefab(gd::string p0, int p1) -> decltype(createPrefab(p0, p1)) {
	using FunctionType = decltype(createPrefab(p0, p1))(*)(BrowseSmartTemplateLayer*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN24BrowseSmartTemplateLayer12createPrefabESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto BrowseSmartKeyLayer::create(GJSmartTemplate* p0, gd::string p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19BrowseSmartKeyLayer6createEP15GJSmartTemplateSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto BrowseSmartKeyLayer::init(GJSmartTemplate* p0, gd::string p1) -> decltype(init(p0, p1)) {
	using FunctionType = decltype(init(p0, p1))(*)(BrowseSmartKeyLayer*, GJSmartTemplate*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19BrowseSmartKeyLayer4initEP15GJSmartTemplateSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

ButtonSprite::ButtonSprite() : ButtonSprite(geode::CutoffConstructor, sizeof(ButtonSprite)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	ButtonSprite::~ButtonSprite();
	using FunctionType = void(*)(ButtonSprite*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12ButtonSpriteC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

ButtonSprite* ButtonSprite::create(cocos2d::CCSprite* topSprite, int width, bool absolute, float height, const char* texture, float scale) {
        return create(topSprite, width, 0, height, scale, absolute, texture, true);
    }

ButtonSprite* ButtonSprite::create(const char* caption, int width, bool absolute, const char* font, const char* texture, float height, float scale) {
        return create(caption, width, 0, scale, absolute, font, texture, height);
    }

ButtonSprite* ButtonSprite::create(char const* caption) {
        return ButtonSprite::create(caption, 0, false, "goldFont.fnt", "GJ_button_01.png", .0f, 1.f);
    }

ButtonSprite* ButtonSprite::create(char const* caption, const char* font, const char* texture) {
        return ButtonSprite::create(caption, 0, false, font, texture, .0f, 1.f);
    }

ButtonSprite* ButtonSprite::create(char const* caption, const char* font, const char* texture, float scale) {
        return ButtonSprite::create(caption, 0, false, font, texture, .0f, scale);
    }

ButtonSprite* ButtonSprite::create(char const* caption, float scale) {
        return ButtonSprite::create(caption, 0, false, "goldFont.fnt", "GJ_button_01.png", .0f, scale);
    }

ButtonSprite* ButtonSprite::create(char const* caption, int width, int p2, float scale, bool absolute, char const* font, char const* bg) {
        return ButtonSprite::create(caption, width, p2, scale, absolute, font, bg, .0f);
    }

ButtonSprite* ButtonSprite::create(char const* caption, int width, int p2, float scale, bool absolute) {
        return ButtonSprite::create(caption, width, p2, scale, absolute, "goldFont.fnt", "GJ_button_01.png", .0f);
    }

ButtonSprite* ButtonSprite::create(cocos2d::CCSprite* topSprite, int width, int unused, float height, float scale, bool absolute) {
        return ButtonSprite::create(topSprite, width, unused, height, scale, absolute, "GJ_button_01.png", false);
    }

ButtonSprite* ButtonSprite::create(cocos2d::CCSprite* topSprite) {
        return ButtonSprite::create(topSprite, 0, 0, .0f, 1.f, false, "GJ_button_01.png", false);
    }

void ButtonSprite::setColor(cocos2d::ccColor3B color) {
        // i love inlined funcs
        if (m_label) m_label->setColor(color);
        if (m_subSprite) m_subSprite->setColor(color);
        if (m_subBGSprite) m_subBGSprite->setColor(color);
        if (m_BGSprite) m_BGSprite->setColor(color);
    }

auto CameraTriggerGameObject::triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2) -> decltype(triggerObject(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*, int, gd::vector<int> const*>::func(&CameraTriggerGameObject::triggerObject), this);
	using FunctionType = decltype(triggerObject(p0, p1, p2))(*)(CameraTriggerGameObject*, GJBaseGameLayer*, int, gd::vector<int> const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN23CameraTriggerGameObject13triggerObjectEP15GJBaseGameLayeriPKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto CameraTriggerGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&CameraTriggerGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(CameraTriggerGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN23CameraTriggerGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

CCBlockLayer::CCBlockLayer() {
        m_unknown = nullptr;
    }

void CCBlockLayer::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

void CCBlockLayer::ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

void CCBlockLayer::ccTouchCancelled(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

void CCBlockLayer::customSetup() {}

void CCBlockLayer::enterAnimFinished() {}

void CCBlockLayer::disableUI() {}

void CCBlockLayer::enableUI() {}

void CCCircleWaveDelegate::circleWaveWillBeRemoved(CCCircleWave* p0) {}

CCContentLayer::~CCContentLayer() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(CCContentLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14CCContentLayerD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) CCContentLayer(geode::CutoffConstructor, sizeof(CCContentLayer));
	CCDestructor::lock(this) = true;
}

CCLightFlash::CCLightFlash() : CCLightFlash(geode::CutoffConstructor, sizeof(CCLightFlash)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	CCLightFlash::~CCLightFlash();
	using FunctionType = void(*)(CCLightFlash*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12CCLightFlashC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

CCLightStrip::CCLightStrip() : CCLightStrip(geode::CutoffConstructor, sizeof(CCLightStrip)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	CCLightStrip::~CCLightStrip();
	using FunctionType = void(*)(CCLightStrip*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12CCLightStripC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

CCMenuItemSpriteExtra::CCMenuItemSpriteExtra() {
        m_animationEnabled = false; //this is changed to true in init
        m_colorEnabled = false;
        m_colorDip = 0.784314f;
        m_scaleMultiplier = 1.f; //this is changed to 1.26f in init
        m_volume = 1.f;
        m_duration = 0.3f;
        m_unselectedDuration = 0.4f;
        m_animationType = MenuAnimationType::Scale;
        m_unknown4 = 0;
        //m_baseScale is initialized in init
    }

CCMenuItemSpriteExtra::~CCMenuItemSpriteExtra() {}

CCMenuItemSpriteExtra* CCMenuItemSpriteExtra::create(cocos2d::CCNode* sprite, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback) {
        return CCMenuItemSpriteExtra::create(sprite, nullptr, target, callback);
    }

void CCMenuItemSpriteExtra::setSprite(cocos2d::CCSprite* sprite) {
        this->setNormalImage(sprite);
        this->updateSprite();
    }

void CCMenuItemSpriteExtra::updateSprite() {
        auto sprite = this->getNormalImage();
        auto size = sprite->getScaledContentSize();
        sprite->setPosition(size / 2);
        sprite->setAnchorPoint({ .5f, .5f });
        this->setContentSize(size);
    }

CCMenuItemToggler::CCMenuItemToggler() {}

CCMenuItemToggler* CCMenuItemToggler::createWithSize(const char* spr1, const char* spr2, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback, float scale) {
        auto sprOff = cocos2d::CCSprite::createWithSpriteFrameName(spr1);
        auto sprOn = cocos2d::CCSprite::createWithSpriteFrameName(spr2);

        sprOff->setScale(scale);
        sprOn->setScale(scale);

        return create(sprOff, sprOn, target, callback);
    }

CCMenuItemToggler* CCMenuItemToggler::createWithStandardSprites(cocos2d::CCObject* target, cocos2d::SEL_MenuHandler callback, float scale) {
        auto sprOff = cocos2d::CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
        auto sprOn = cocos2d::CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");

        float maxWidth = (std::max)(sprOff->getContentSize().width, sprOn->getContentSize().width);
        float maxHeight = (std::max)(sprOff->getContentSize().height, sprOn->getContentSize().height);

        sprOff->setScale(scale);
        sprOn->setScale(scale);

        auto ret = create(sprOff, sprOn, target, callback);

        ret->setContentSize({maxWidth, maxHeight});

        ret->m_offButton->setContentSize({maxWidth, maxHeight});
        ret->m_onButton->setContentSize({maxWidth, maxHeight});

             ret->m_offButton->setPosition({maxWidth/2, maxHeight/2});
        ret->m_onButton->setPosition({maxWidth/2, maxHeight/2});

        sprOff->setPosition({maxWidth/2, maxHeight/2});
        sprOn->setPosition({maxWidth/2, maxHeight/2});

        return ret;
    }

bool CCMenuItemToggler::isOn() {
        return m_toggled;
    }

bool CCMenuItemToggler::isToggled() {
        return m_toggled;
    }

void CCMenuItemToggler::setClickable(bool on) {
        m_notClickable = !on;
    }

void CCMenuItemToggler::toggleWithCallback(bool on) {
        this->activate();
        this->toggle(on);
    }

void CCMenuItemToggler::updateSprite() {
        m_offButton->updateSprite();
        m_onButton->updateSprite();
        auto size = m_offButton->getScaledContentSize();
        m_offButton->setPosition(size / 2);
        m_offButton->setAnchorPoint({ .5f, .5f });
        m_onButton->setPosition(size / 2);
        m_onButton->setAnchorPoint({ .5f, .5f });
        this->setContentSize(size);
    }

CCScrollLayerExt::CCScrollLayerExt(cocos2d::CCRect p0) : CCScrollLayerExt(geode::CutoffConstructor, sizeof(CCScrollLayerExt)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	CCScrollLayerExt::~CCScrollLayerExt();
	using FunctionType = void(*)(CCScrollLayerExt*, cocos2d::CCRect);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16CCScrollLayerExtC2EN7cocos2d6CCRectE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0);
}

void CCScrollLayerExtDelegate::scrllViewWillBeginDecelerating(CCScrollLayerExt* p0) {}

void CCScrollLayerExtDelegate::scrollViewDidEndDecelerating(CCScrollLayerExt* p0) {}

void CCScrollLayerExtDelegate::scrollViewTouchMoving(CCScrollLayerExt* p0) {}

void CCScrollLayerExtDelegate::scrollViewDidEndMoving(CCScrollLayerExt* p0) {}

void CCScrollLayerExtDelegate::scrollViewTouchBegin(CCScrollLayerExt* p0) {}

void CCScrollLayerExtDelegate::scrollViewTouchEnd(CCScrollLayerExt* p0) {}

CCSpriteWithHue::CCSpriteWithHue() {}

auto CCSpriteWithHue::create(gd::string const& file, cocos2d::CCRect const& rect) -> decltype(create(file, rect)) {
	using FunctionType = decltype(create(file, rect))(*)(gd::string const&, cocos2d::CCRect const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15CCSpriteWithHue6createERKSsRKN7cocos2d6CCRectE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(file, rect);
}

auto CCSpriteWithHue::create(gd::string const& file) -> decltype(create(file)) {
	using FunctionType = decltype(create(file))(*)(gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15CCSpriteWithHue6createERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(file);
}

auto CCSpriteWithHue::createWithSpriteFrameName(gd::string const& p0) -> decltype(createWithSpriteFrameName(p0)) {
	using FunctionType = decltype(createWithSpriteFrameName(p0))(*)(gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15CCSpriteWithHue25createWithSpriteFrameNameERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

CCSpriteGrayscale::CCSpriteGrayscale() {}

auto CCSpriteGrayscale::create(gd::string const& file, cocos2d::CCRect const& rect) -> decltype(create(file, rect)) {
	using FunctionType = decltype(create(file, rect))(*)(gd::string const&, cocos2d::CCRect const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17CCSpriteGrayscale6createERKSsRKN7cocos2d6CCRectE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(file, rect);
}

auto CCSpriteGrayscale::create(gd::string const& file) -> decltype(create(file)) {
	using FunctionType = decltype(create(file))(*)(gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17CCSpriteGrayscale6createERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(file);
}

auto CCSpriteGrayscale::createWithSpriteFrameName(gd::string const& frameName) -> decltype(createWithSpriteFrameName(frameName)) {
	using FunctionType = decltype(createWithSpriteFrameName(frameName))(*)(gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17CCSpriteGrayscale25createWithSpriteFrameNameERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(frameName);
}

auto CCSpritePart::frameChanged(gd::string p0) -> decltype(frameChanged(p0)) {
	using FunctionType = decltype(frameChanged(p0))(*)(CCSpritePart*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12CCSpritePart12frameChangedESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto CCSpritePart::updateDisplayFrame(gd::string p0) -> decltype(updateDisplayFrame(p0)) {
	using FunctionType = decltype(updateDisplayFrame(p0))(*)(CCSpritePart*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12CCSpritePart18updateDisplayFrameESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

CCTextInputNode::CCTextInputNode() {
        m_numberInput = false;
        m_caption = "";
        m_unknown1 = 0;
        m_selected = false;
        m_unknown2 = false;
        m_fontValue1 = -0.5f;
        m_fontValue2 = 8.0f;
        m_isChatFont = false;
        m_allowedChars = "";
        m_maxLabelWidth = 0.0f;
        m_maxLabelScale = 0.0f;
        m_placeholderScale = 0.0f;
        m_placeholderColor = cocos2d::ccc3(0, 0, 0);
        m_textColor = cocos2d::ccc3(0, 0, 0);
        m_cursor = nullptr;
        m_textField = nullptr;
        m_delegate = nullptr;
        m_maxLabelLength = 0;
        m_placeholderLabel = nullptr;
        m_filterSwearWords = false;
        m_usePasswordChar = false;
        m_forceOffset = false;
        m_textArea = nullptr;
        m_valueType = (InputValueType)0;
        m_decimalPlaces = 0;
        m_kerningAmount = 0;
    }

CCTextInputNode* CCTextInputNode::create(float width, float height, char const* placeholder, char const* fontPath) {
        return CCTextInputNode::create(width, height, placeholder, 0x18, fontPath);
    }

CCTextInputNode* CCTextInputNode::create(float width, float height, char const* placeholder, int fontSize, char const* fontPath) {
        return CCTextInputNode::create(width, height, placeholder, "Thonburi", fontSize, fontPath);
    }

void CCTextInputNode::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

void CCTextInputNode::ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

void CCTextInputNode::ccTouchCancelled(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

cocos2d::CCLabelBMFont* CCTextInputNode::getPlaceholderLabel() {
        return m_placeholderLabel;
    }

auto CCTextInputNode::setAllowedChars(gd::string filter) -> decltype(setAllowedChars(filter)) {
	using FunctionType = decltype(setAllowedChars(filter))(*)(CCTextInputNode*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15CCTextInputNode15setAllowedCharsESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, filter);
}

void CCTextInputNode::setDelegate(TextInputDelegate* delegate) {
        m_delegate = delegate;
    }

void CCTextInputNode::setMaxLabelLength(int v) {
        m_maxLabelLength = v;
        this->refreshLabel();
    }

auto CCTextInputNode::setString(gd::string p0) -> decltype(setString(p0)) {
	using FunctionType = decltype(setString(p0))(*)(CCTextInputNode*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15CCTextInputNode9setStringESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto CCTextInputNode::updateDefaultFontValues(gd::string p0) -> decltype(updateDefaultFontValues(p0)) {
	using FunctionType = decltype(updateDefaultFontValues(p0))(*)(CCTextInputNode*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15CCTextInputNode23updateDefaultFontValuesESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto CCTextInputNode::updateLabel(gd::string p0) -> decltype(updateLabel(p0)) {
	using FunctionType = decltype(updateLabel(p0))(*)(CCTextInputNode*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15CCTextInputNode11updateLabelESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto CCURLObject::create(gd::string p0, gd::string p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11CCURLObject6createESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto CCURLObject::init(gd::string p0, gd::string p1) -> decltype(init(p0, p1)) {
	using FunctionType = decltype(init(p0, p1))(*)(CCURLObject*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11CCURLObject4initESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

void CurrencyRewardDelegate::currencyWillExit(CurrencyRewardLayer* p0) {}

void ChallengesPage::FLAlert_Clicked(FLAlertLayer* p0, bool p1) {}

auto GJChallengeItem::create(GJChallengeType challengeType, int goal, int reward, int timeLeft, gd::string questName) -> decltype(create(challengeType, goal, reward, timeLeft, questName)) {
	using FunctionType = decltype(create(challengeType, goal, reward, timeLeft, questName))(*)(GJChallengeType, int, int, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJChallengeItem6createE15GJChallengeTypeiiiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(challengeType, goal, reward, timeLeft, questName);
}

auto GJChallengeItem::createFromString(gd::string string) -> decltype(createFromString(string)) {
	using FunctionType = decltype(createFromString(string))(*)(gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJChallengeItem16createFromStringESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(string);
}

auto GJChallengeItem::init(GJChallengeType challengeType, int goal, int reward, int timeLeft, gd::string questName) -> decltype(init(challengeType, goal, reward, timeLeft, questName)) {
	using FunctionType = decltype(init(challengeType, goal, reward, timeLeft, questName))(*)(GJChallengeItem*, GJChallengeType, int, int, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJChallengeItem4initE15GJChallengeTypeiiiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, challengeType, goal, reward, timeLeft, questName);
}

auto ChallengeNode::updateTimeLabel(gd::string p0) -> decltype(updateTimeLabel(p0)) {
	using FunctionType = decltype(updateTimeLabel(p0))(*)(ChallengeNode*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13ChallengeNode15updateTimeLabelESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto ChanceTriggerGameObject::remapChanceObjects(gd::unordered_map<int, int> const* p0) -> decltype(remapChanceObjects(p0)) {
	using FunctionType = decltype(remapChanceObjects(p0))(*)(ChanceTriggerGameObject*, gd::unordered_map<int, int> const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN23ChanceTriggerGameObject18remapChanceObjectsEPKSt13unordered_mapIiiSt4hashIiESt8equal_toIiESaISt4pairIKiiEEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

CharacterColorPage::CharacterColorPage() {
        m_colorMode = 0;
        m_playerObjects = nullptr;
        m_modeButtons = nullptr;
        m_colorButtons = nullptr;
        m_cursors = nullptr;
        m_delegate = nullptr;
        m_glowToggler = nullptr;
        m_glowLabel = nullptr;
    }

auto CheckpointGameObject::setupCustomSprites(gd::string p0) -> decltype(setupCustomSprites(p0)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string>::func(&CheckpointGameObject::setupCustomSprites), this);
	using FunctionType = decltype(setupCustomSprites(p0))(*)(CheckpointGameObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20CheckpointGameObject18setupCustomSpritesESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto CheckpointGameObject::triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2) -> decltype(triggerObject(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*, int, gd::vector<int> const*>::func(&CheckpointGameObject::triggerObject), this);
	using FunctionType = decltype(triggerObject(p0, p1, p2))(*)(CheckpointGameObject*, GJBaseGameLayer*, int, gd::vector<int> const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20CheckpointGameObject13triggerObjectEP15GJBaseGameLayeriPKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto CheckpointGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&CheckpointGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(CheckpointGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20CheckpointGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

EnterEffectInstance::EnterEffectInstance(EnterEffectObject* p0, int p1, int p2, int p3, int p4, int p5, int p6) {
	using FunctionType = void(*)(EnterEffectInstance*, EnterEffectObject*, int, int, int, int, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19EnterEffectInstanceC2EP17EnterEffectObjectiiiiii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6);
}

auto KeyframeObject::setupSpline(gd::vector<KeyframeObject*>& p0) -> decltype(setupSpline(p0)) {
	using FunctionType = decltype(setupSpline(p0))(*)(KeyframeObject*, gd::vector<KeyframeObject*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14KeyframeObject11setupSplineERSt6vectorIPS_SaIS1_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

CheckpointObject::CheckpointObject() : CheckpointObject(geode::CutoffConstructor, sizeof(CheckpointObject)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	CheckpointObject::~CheckpointObject();
	using FunctionType = void(*)(CheckpointObject*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16CheckpointObjectC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

auto CollisionBlockPopup::createToggleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCMenu* p3, cocos2d::CCPoint p4) -> decltype(createToggleButton(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(createToggleButton(p0, p1, p2, p3, p4))(*)(CollisionBlockPopup*, gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19CollisionBlockPopup18createToggleButtonESsMN7cocos2d8CCObjectEFvPS1_EbPNS0_6CCMenuENS0_7CCPointE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

void ColorAction::loadFromState(CAState& state) {
        m_fromColor = state.m_fromColor;
        m_toColor = state.m_toColor;
        m_color = state.m_color;
        m_property19 = state.m_property19;
        m_blending = state.m_blending;
        m_copyOpacity = state.m_copyOpacity;
        m_unknown = state.m_unknown;
        m_playerColor = state.m_playerColor;
        m_colorID = state.m_colorID;
        m_copyID = state.m_copyID;
        m_unknown2 = state.m_unknown2;
        m_duration = state.m_duration;
        m_fromOpacity = state.m_fromOpacity;
        m_toOpacity = state.m_toOpacity;
        m_deltaTime = state.m_deltaTime;
        m_copyHSV = state.m_copyHSV;
    }

void ColorAction::saveToState(CAState& state) {
        state.m_fromColor = m_fromColor;
        state.m_toColor = m_toColor;
        state.m_color = m_color;
        state.m_property19 = m_property19;
        state.m_blending = m_blending;
        state.m_copyOpacity = m_copyOpacity;
        state.m_unknown = m_unknown;
        state.m_playerColor = m_playerColor;
        state.m_colorID = m_colorID;
        state.m_copyID = m_copyID;
        state.m_unknown2 = m_unknown2;
        state.m_duration = m_duration;
        state.m_fromOpacity = m_fromOpacity;
        state.m_toOpacity = m_toOpacity;
        state.m_deltaTime = m_deltaTime;
        state.m_copyHSV = m_copyHSV;
    }

auto ColorAction::setupFromMap(gd::map<gd::string, gd::string>& p0) -> decltype(setupFromMap(p0)) {
	using FunctionType = decltype(setupFromMap(p0))(*)(ColorAction*, gd::map<gd::string, gd::string>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11ColorAction12setupFromMapERSt3mapISsSsSt4lessISsESaISt4pairIKSsSsEEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto ColorAction::setupFromString(gd::string p0) -> decltype(setupFromString(p0)) {
	using FunctionType = decltype(setupFromString(p0))(*)(ColorAction*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11ColorAction15setupFromStringESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

ColorAction2::ColorAction2(cocos2d::ccColor3B p0, cocos2d::ccColor3B p1, float p2, double p3, bool p4, int p5, float p6, float p7) {
	using FunctionType = void(*)(ColorAction2*, cocos2d::ccColor3B, cocos2d::ccColor3B, float, double, bool, int, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12ColorAction2C2EN7cocos2d10_ccColor3BES1_fdbiff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7);
}

auto ColorSelectLiveOverlay::createToggleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCMenu* p3, cocos2d::CCPoint p4) -> decltype(createToggleButton(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(createToggleButton(p0, p1, p2, p3, p4))(*)(ColorSelectLiveOverlay*, gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22ColorSelectLiveOverlay18createToggleButtonESsMN7cocos2d8CCObjectEFvPS1_EbPNS0_6CCMenuENS0_7CCPointE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

void SliderDelegate::sliderBegan(Slider* p0) {}

void SliderDelegate::sliderEnded(Slider* p0) {}

void SetupTriggerPopup::pageChanged() {}

void SetupTriggerPopup::updateInputValue(int p0, float& p1) {}

void SetupTriggerPopup::onPlusButton(cocos2d::CCObject* sender) {}

void SetupTriggerPopup::onCustomButton(cocos2d::CCObject* sender) {}

void SetupTriggerPopup::valueDidChange(int p0, float p1) {}

void SetupTriggerPopup::onCustomToggleTriggerValue(cocos2d::CCObject* sender) {}

auto SetupTriggerPopup::addCloseButton(gd::string p0) -> decltype(addCloseButton(p0)) {
	using FunctionType = decltype(addCloseButton(p0))(*)(SetupTriggerPopup*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17SetupTriggerPopup14addCloseButtonESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto SetupTriggerPopup::addHelpButton(gd::string p0, gd::string p1, float p2) -> decltype(addHelpButton(p0, p1, p2)) {
	using FunctionType = decltype(addHelpButton(p0, p1, p2))(*)(SetupTriggerPopup*, gd::string, gd::string, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17SetupTriggerPopup13addHelpButtonESsSsf")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto SetupTriggerPopup::addInfoLabel(gd::string p0, float p1, cocos2d::CCPoint p2, int p3, int p4) -> decltype(addInfoLabel(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(addInfoLabel(p0, p1, p2, p3, p4))(*)(SetupTriggerPopup*, gd::string, float, cocos2d::CCPoint, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17SetupTriggerPopup12addInfoLabelESsfN7cocos2d7CCPointEii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto SetupTriggerPopup::addTitle(gd::string p0) -> decltype(addTitle(p0)) {
	using FunctionType = decltype(addTitle(p0))(*)(SetupTriggerPopup*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17SetupTriggerPopup8addTitleESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto SetupTriggerPopup::createCustomButton(int p0, gd::string p1, gd::string p2, cocos2d::CCPoint p3, float p4, float p5, bool p6, int p7, int p8) -> decltype(createCustomButton(p0, p1, p2, p3, p4, p5, p6, p7, p8)) {
	using FunctionType = decltype(createCustomButton(p0, p1, p2, p3, p4, p5, p6, p7, p8))(*)(SetupTriggerPopup*, int, gd::string, gd::string, cocos2d::CCPoint, float, float, bool, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17SetupTriggerPopup18createCustomButtonEiSsSsN7cocos2d7CCPointEffbii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7, p8);
}

auto SetupTriggerPopup::createCustomEasingControls(gd::string p0, cocos2d::CCPoint p1, float p2, int p3, int p4, int p5, int p6) -> decltype(createCustomEasingControls(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(createCustomEasingControls(p0, p1, p2, p3, p4, p5, p6))(*)(SetupTriggerPopup*, gd::string, cocos2d::CCPoint, float, int, int, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17SetupTriggerPopup26createCustomEasingControlsESsN7cocos2d7CCPointEfiiii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6);
}

auto SetupTriggerPopup::createCustomToggleValueControl(int p0, bool p1, bool p2, gd::string p3, cocos2d::CCPoint p4, bool p5, int p6, int p7) -> decltype(createCustomToggleValueControl(p0, p1, p2, p3, p4, p5, p6, p7)) {
	using FunctionType = decltype(createCustomToggleValueControl(p0, p1, p2, p3, p4, p5, p6, p7))(*)(SetupTriggerPopup*, int, bool, bool, gd::string, cocos2d::CCPoint, bool, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17SetupTriggerPopup30createCustomToggleValueControlEibbSsN7cocos2d7CCPointEbii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7);
}

auto SetupTriggerPopup::createPlusButton(int p0, cocos2d::CCPoint p1, float p2, gd::string p3, int p4, int p5) -> decltype(createPlusButton(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(createPlusButton(p0, p1, p2, p3, p4, p5))(*)(SetupTriggerPopup*, int, cocos2d::CCPoint, float, gd::string, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17SetupTriggerPopup16createPlusButtonEiN7cocos2d7CCPointEfSsii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto SetupTriggerPopup::createToggleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCPoint p3) -> decltype(createToggleButton(p0, p1, p2, p3)) {
	using FunctionType = decltype(createToggleButton(p0, p1, p2, p3))(*)(SetupTriggerPopup*, gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCPoint);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17SetupTriggerPopup18createToggleButtonESsMN7cocos2d8CCObjectEFvPS1_EbNS0_7CCPointE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto SetupTriggerPopup::createToggleValueControl(int p0, gd::string p1, cocos2d::CCPoint p2, bool p3, int p4, int p5, float p6) -> decltype(createToggleValueControl(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(createToggleValueControl(p0, p1, p2, p3, p4, p5, p6))(*)(SetupTriggerPopup*, int, gd::string, cocos2d::CCPoint, bool, int, int, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17SetupTriggerPopup24createToggleValueControlEiSsN7cocos2d7CCPointEbiif")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6);
}

auto SetupTriggerPopup::createToggleValueControlAdvanced(int p0, gd::string p1, cocos2d::CCPoint p2, bool p3, int p4, int p5, float p6, float p7, float p8, cocos2d::CCPoint p9) -> decltype(createToggleValueControlAdvanced(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9)) {
	using FunctionType = decltype(createToggleValueControlAdvanced(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9))(*)(SetupTriggerPopup*, int, gd::string, cocos2d::CCPoint, bool, int, int, float, float, float, cocos2d::CCPoint);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17SetupTriggerPopup32createToggleValueControlAdvancedEiSsN7cocos2d7CCPointEbiifffS1_")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
}

auto SetupTriggerPopup::createValueControl(int p0, gd::string p1, cocos2d::CCPoint p2, float p3, float p4, float p5) -> decltype(createValueControl(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(createValueControl(p0, p1, p2, p3, p4, p5))(*)(SetupTriggerPopup*, int, gd::string, cocos2d::CCPoint, float, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17SetupTriggerPopup18createValueControlEiSsN7cocos2d7CCPointEfff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto SetupTriggerPopup::createValueControlAdvanced(int p0, gd::string p1, cocos2d::CCPoint p2, float p3, bool p4, InputValueType p5, int p6, bool p7, float p8, float p9, int p10, int p11, GJInputStyle p12, int p13, bool p14) -> decltype(createValueControlAdvanced(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14)) {
	using FunctionType = decltype(createValueControlAdvanced(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14))(*)(SetupTriggerPopup*, int, gd::string, cocos2d::CCPoint, float, bool, InputValueType, int, bool, float, float, int, int, GJInputStyle, int, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17SetupTriggerPopup26createValueControlAdvancedEiSsN7cocos2d7CCPointEfb14InputValueTypeibffii12GJInputStyleib")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
}

auto SetupTriggerPopup::createValueControlWArrows(int p0, gd::string p1, cocos2d::CCPoint p2, float p3) -> decltype(createValueControlWArrows(p0, p1, p2, p3)) {
	using FunctionType = decltype(createValueControlWArrows(p0, p1, p2, p3))(*)(SetupTriggerPopup*, int, gd::string, cocos2d::CCPoint, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17SetupTriggerPopup25createValueControlWArrowsEiSsN7cocos2d7CCPointEf")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto SetupTriggerPopup::updateInputNodeLabel(int p0, gd::string p1) -> decltype(updateInputNodeLabel(p0, p1)) {
	using FunctionType = decltype(updateInputNodeLabel(p0, p1))(*)(SetupTriggerPopup*, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17SetupTriggerPopup20updateInputNodeLabelEiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto SetupTriggerPopup::updateLabel(int p0, gd::string p1) -> decltype(updateLabel(p0, p1)) {
	using FunctionType = decltype(updateLabel(p0, p1))(*)(SetupTriggerPopup*, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17SetupTriggerPopup11updateLabelEiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto ColorSelectPopup::hexToColor(gd::string p0) -> decltype(hexToColor(p0)) {
	using FunctionType = decltype(hexToColor(p0))(*)(gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16ColorSelectPopup10hexToColorESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

void LikeItemDelegate::likedItem(LikeItemType p0, int p1, bool p2) {}

CommentCell::CommentCell(char const* p0, float p1, float p2) : CommentCell(geode::CutoffConstructor, sizeof(CommentCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	CommentCell::~CommentCell();
	using FunctionType = void(*)(CommentCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11CommentCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

void CommentUploadDelegate::commentDeleteFailed(int p0, int p1) {}

auto CommunityCreditNode::create(int p0, int p1, int p2, gd::string p3) -> decltype(create(p0, p1, p2, p3)) {
	using FunctionType = decltype(create(p0, p1, p2, p3))(*)(int, int, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19CommunityCreditNode6createEiiiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto CommunityCreditNode::init(int unlockType, int iconID, int unknown, gd::string author) -> decltype(init(unlockType, iconID, unknown, author)) {
	using FunctionType = decltype(init(unlockType, iconID, unknown, author))(*)(CommunityCreditNode*, int, int, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19CommunityCreditNode4initEiiiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, unlockType, iconID, unknown, author);
}

CommunityCreditsPage::CommunityCreditsPage() {
        m_pageObjects = nullptr;
        m_prevButton = nullptr;
        m_nextButton = nullptr;
        m_page = -1;
    }

void ConfigureHSVWidget::textInputOpened(CCTextInputNode* p0) {}

auto ConfigureValuePopup::create(ConfigureValuePopupDelegate* p0, float p1, float p2, float p3, gd::string p4, gd::string p5) -> decltype(create(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(create(p0, p1, p2, p3, p4, p5))(*)(ConfigureValuePopupDelegate*, float, float, float, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19ConfigureValuePopup6createEP27ConfigureValuePopupDelegatefffSsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4, p5);
}

auto ConfigureValuePopup::init(ConfigureValuePopupDelegate* p0, float p1, float p2, float p3, gd::string p4, gd::string p5) -> decltype(init(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(init(p0, p1, p2, p3, p4, p5))(*)(ConfigureValuePopup*, ConfigureValuePopupDelegate*, float, float, float, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19ConfigureValuePopup4initEP27ConfigureValuePopupDelegatefffSsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto CountTriggerGameObject::triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2) -> decltype(triggerObject(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*, int, gd::vector<int> const*>::func(&CountTriggerGameObject::triggerObject), this);
	using FunctionType = decltype(triggerObject(p0, p1, p2))(*)(CountTriggerGameObject*, GJBaseGameLayer*, int, gd::vector<int> const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22CountTriggerGameObject13triggerObjectEP15GJBaseGameLayeriPKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto CountTriggerGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&CountTriggerGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(CountTriggerGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22CountTriggerGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

void CreateGuidelinesLayer::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

void CreateGuidelinesLayer::keyUp(cocos2d::enumKeyCodes p0) {}

auto CreateGuidelinesLayer::getMergedRecordString(gd::string p0, gd::string p1) -> decltype(getMergedRecordString(p0, p1)) {
	using FunctionType = decltype(getMergedRecordString(p0, p1))(*)(CreateGuidelinesLayer*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN21CreateGuidelinesLayer21getMergedRecordStringESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto CreateParticlePopup::create(gd::string p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19CreateParticlePopup6createESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto CreateParticlePopup::create(ParticleGameObject* p0, cocos2d::CCArray* p1, gd::string p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(ParticleGameObject*, cocos2d::CCArray*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19CreateParticlePopup6createEP18ParticleGameObjectPN7cocos2d7CCArrayESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto CreateParticlePopup::init(ParticleGameObject* p0, cocos2d::CCArray* p1, gd::string p2) -> decltype(init(p0, p1, p2)) {
	using FunctionType = decltype(init(p0, p1, p2))(*)(CreateParticlePopup*, ParticleGameObject*, cocos2d::CCArray*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19CreateParticlePopup4initEP18ParticleGameObjectPN7cocos2d7CCArrayESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

void DialogDelegate::dialogClosed(DialogLayer* p0) {}

CreatorLayer::CreatorLayer() {
        m_secretDoorSprite = nullptr;
        m_questsSprite = nullptr;
        m_vaultDialogIndex = -1;
        m_versusDialogIndex = 0;
    }

CurrencySprite::CurrencySprite() : CurrencySprite(geode::CutoffConstructor, sizeof(CurrencySprite)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	CurrencySprite::~CurrencySprite();
	using FunctionType = void(*)(CurrencySprite*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14CurrencySpriteC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

void HSVWidgetDelegate::hsvPopupClosed(HSVWidgetPopup* p0, cocos2d::ccHSVValue p1) {}

void HSVWidgetDelegate::hsvChanged(ConfigureHSVWidget* p0) {}

auto CustomizeObjectLayer::createToggleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCMenu* p3, cocos2d::CCPoint p4) -> decltype(createToggleButton(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(createToggleButton(p0, p1, p2, p3, p4))(*)(CustomizeObjectLayer*, gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20CustomizeObjectLayer18createToggleButtonESsMN7cocos2d8CCObjectEFvPS1_EbPNS0_6CCMenuENS0_7CCPointE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

CustomListView::~CustomListView() {}

CustomListView* CustomListView::create(cocos2d::CCArray* entries, BoomListType type, float width, float height) {
        return CustomListView::create(entries, nullptr, width, height, 0, type, 0.0f);
    }

CustomSongCell::CustomSongCell(char const* p0, float p1, float p2) : CustomSongCell(geode::CutoffConstructor, sizeof(CustomSongCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	CustomSongCell::~CustomSongCell();
	using FunctionType = void(*)(CustomSongCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14CustomSongCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

CustomMusicCell::CustomMusicCell(char const* p0, float p1, float p2) : CustomMusicCell(geode::CutoffConstructor, sizeof(CustomMusicCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	CustomMusicCell::~CustomMusicCell();
	using FunctionType = void(*)(CustomMusicCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15CustomMusicCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

CustomSFXCell::CustomSFXCell(char const* p0, float p1, float p2) : CustomSFXCell(geode::CutoffConstructor, sizeof(CustomSFXCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	CustomSFXCell::~CustomSFXCell();
	using FunctionType = void(*)(CustomSFXCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13CustomSFXCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

void GJDropDownLayerDelegate::dropDownLayerWillClose(GJDropDownLayer* p0) {}

void MusicBrowserDelegate::musicBrowserClosed(MusicBrowser* p0) {}

CustomSongLayer::CustomSongLayer() {
        m_songDelegate = nullptr;
        m_songIDInput = nullptr;
        m_delegate = nullptr;
    }

void CustomSongLayerDelegate::customSongLayerClosed() {}

CustomSongWidget::CustomSongWidget() : CustomSongWidget(geode::CutoffConstructor, sizeof(CustomSongWidget)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	CustomSongWidget::~CustomSongWidget();
	using FunctionType = void(*)(CustomSongWidget*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16CustomSongWidgetC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

auto CustomSongWidget::updateWithMultiAssets(gd::string p0, gd::string p1, int p2) -> decltype(updateWithMultiAssets(p0, p1, p2)) {
	using FunctionType = decltype(updateWithMultiAssets(p0, p1, p2))(*)(CustomSongWidget*, gd::string, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16CustomSongWidget21updateWithMultiAssetsESsSsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto DailyLevelNode::updateTimeLabel(gd::string p0) -> decltype(updateTimeLabel(p0)) {
	using FunctionType = decltype(updateTimeLabel(p0))(*)(DailyLevelNode*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14DailyLevelNode15updateTimeLabelESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

void LevelDownloadDelegate::levelDownloadFinished(GJGameLevel* p0) {}

void LevelDownloadDelegate::levelDownloadFailed(int p0) {}

void DailyLevelPage::FLAlert_Clicked(FLAlertLayer* p0, bool p1) {}

auto RingObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&RingObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(RingObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10RingObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto DashRingObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&DashRingObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(DashRingObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14DashRingObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

void DemonFilterDelegate::demonFilterSelectClosed(int p0) {}

DemonFilterSelectLayer::DemonFilterSelectLayer() {}

auto DemonInfoPopup::createFromString(gd::string p0) -> decltype(createFromString(p0)) {
	using FunctionType = decltype(createFromString(p0))(*)(gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14DemonInfoPopup16createFromStringESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

void DialogLayer::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

auto DialogObject::create(gd::string character, gd::string text, int characterFrame, float textScale, bool skippable, cocos2d::ccColor3B color) -> decltype(create(character, text, characterFrame, textScale, skippable, color)) {
	using FunctionType = decltype(create(character, text, characterFrame, textScale, skippable, color))(*)(gd::string, gd::string, int, float, bool, cocos2d::ccColor3B);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12DialogObject6createESsSsifbN7cocos2d10_ccColor3BE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(character, text, characterFrame, textScale, skippable, color);
}

auto DialogObject::init(gd::string character, gd::string text, int characterFrame, float textScale, bool skippable, cocos2d::ccColor3B color) -> decltype(init(character, text, characterFrame, textScale, skippable, color)) {
	using FunctionType = decltype(init(character, text, characterFrame, textScale, skippable, color))(*)(DialogObject*, gd::string, gd::string, int, float, bool, cocos2d::ccColor3B);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12DialogObject4initESsSsifbN7cocos2d10_ccColor3BE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, character, text, characterFrame, textScale, skippable, color);
}

auto DrawGridLayer::loadTimeMarkers(gd::string p0) -> decltype(loadTimeMarkers(p0)) {
	using FunctionType = decltype(loadTimeMarkers(p0))(*)(DrawGridLayer*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13DrawGridLayer15loadTimeMarkersESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

DungeonBarsSprite::DungeonBarsSprite() {
        m_barsSprite = nullptr;
    }

void DynamicScrollDelegate::updatePageWithObject(cocos2d::CCObject* p0, cocos2d::CCObject* p1) {}

void UploadActionDelegate::uploadActionFinished(int p0, int p1) {}

void UploadActionDelegate::uploadActionFailed(int p0, int p1) {}

void UploadPopupDelegate::onClosePopup(UploadActionPopup* p0) {}

void SetIDPopupDelegate::setIDPopupClosed(SetIDPopup* p0, int p1) {}

EditLevelLayer::EditLevelLayer() {}

EditLevelLayer::~EditLevelLayer() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(EditLevelLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14EditLevelLayerD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) EditLevelLayer(geode::CutoffConstructor, sizeof(EditLevelLayer));
	CCDestructor::lock(this) = true;
}

GJOptionsLayer::GJOptionsLayer() : GJOptionsLayer(geode::CutoffConstructor, sizeof(GJOptionsLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	GJOptionsLayer::~GJOptionsLayer();
	using FunctionType = void(*)(GJOptionsLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14GJOptionsLayerC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

void GJOptionsLayer::setupOptions() {}

auto GJOptionsLayer::didToggleGV(gd::string p0) -> decltype(didToggleGV(p0)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string>::func(&GJOptionsLayer::didToggleGV), this);
	using FunctionType = decltype(didToggleGV(p0))(*)(GJOptionsLayer*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14GJOptionsLayer11didToggleGVESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

void GJOptionsLayer::didToggle(int p0) {}

EditorPauseLayer::EditorPauseLayer() {
        m_saved = false;
        m_guidelinesOffButton = nullptr;
        m_guidelinesOnButton = nullptr;
        m_editorLayer = nullptr;
    }

void GJRotationControlDelegate::angleChanged(float angle) {}

void GJRotationControlDelegate::angleChangeBegin() {}

void GJRotationControlDelegate::angleChangeEnded() {}

void GJScaleControlDelegate::scaleXChanged(float scaleX, bool lock) {}

void GJScaleControlDelegate::scaleYChanged(float scaleY, bool lock) {}

void GJScaleControlDelegate::scaleXYChanged(float scaleX, float scaleY, bool lock) {}

void GJScaleControlDelegate::scaleChangeBegin() {}

void GJScaleControlDelegate::scaleChangeEnded() {}

void GJScaleControlDelegate::updateScaleControl() {}

void GJScaleControlDelegate::anchorPointMoved(cocos2d::CCPoint newAnchor) {}

EditorUI::EditorUI() : EditorUI(geode::CutoffConstructor, sizeof(EditorUI)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	EditorUI::~EditorUI();
	using FunctionType = void(*)(EditorUI*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8EditorUIC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

EditorUI* EditorUI::get() {
        auto lel = LevelEditorLayer::get();
        if (!lel) return nullptr;
        return lel->m_editorUI;
    }

void EditorUI::transformChangeEnded() {}

void EditorUI::angleChangeEnded() {}

void EditorUI::scaleChangeEnded() {}

auto EditorUI::createPrefab(GJSmartTemplate* p0, gd::string p1, int p2) -> decltype(createPrefab(p0, p1, p2)) {
	using FunctionType = decltype(createPrefab(p0, p1, p2))(*)(EditorUI*, GJSmartTemplate*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8EditorUI12createPrefabEP15GJSmartTemplateSsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto EditorUI::getSimpleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, cocos2d::CCMenu* p2) -> decltype(getSimpleButton(p0, p1, p2)) {
	using FunctionType = decltype(getSimpleButton(p0, p1, p2))(*)(EditorUI*, gd::string, cocos2d::SEL_MenuHandler, cocos2d::CCMenu*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8EditorUI15getSimpleButtonESsMN7cocos2d8CCObjectEFvPS1_EPNS0_6CCMenuE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto EditorUI::menuItemFromObjectString(gd::string p0, int p1) -> decltype(menuItemFromObjectString(p0, p1)) {
	using FunctionType = decltype(menuItemFromObjectString(p0, p1))(*)(EditorUI*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8EditorUI24menuItemFromObjectStringESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto EditorUI::pasteObjects(gd::string p0, bool p1, bool p2) -> decltype(pasteObjects(p0, p1, p2)) {
	using FunctionType = decltype(pasteObjects(p0, p1, p2))(*)(EditorUI*, gd::string, bool, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8EditorUI12pasteObjectsESsbb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

void EditorUI::reloadCustomItems() {
        GameManager* gm = GameManager::sharedState();
        int buttonsPerRow = gm->getIntGameVariable("0049");
        int buttonRows = gm->getIntGameVariable("0050");
        cocos2d::CCArray* customItems = createCustomItems();
        m_buttonBar->loadFromItems(customItems,buttonsPerRow,buttonRows,true);
    }

auto EditorUI::spriteFromObjectString(gd::string str, bool p1, bool p2, int objLimit, cocos2d::CCArray* p4, cocos2d::CCArray* p5, GameObject* p6) -> decltype(spriteFromObjectString(str, p1, p2, objLimit, p4, p5, p6)) {
	using FunctionType = decltype(spriteFromObjectString(str, p1, p2, objLimit, p4, p5, p6))(*)(EditorUI*, gd::string, bool, bool, int, cocos2d::CCArray*, cocos2d::CCArray*, GameObject*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8EditorUI22spriteFromObjectStringESsbbiPN7cocos2d7CCArrayES2_P10GameObject")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, str, p1, p2, objLimit, p4, p5, p6);
}

void EditorUI::updateDeleteMenu() {
        m_deleteMenu->setVisible(m_selectedMode == 1);
    }

void EditorUI::updateEditMenu() {
        m_editButtonBar->setVisible(m_selectedMode == 3);
    }

void EndLevelLayer::enterAnimFinished() {}

void EndLevelLayer::keyUp(cocos2d::enumKeyCodes p0) {}

auto EndTriggerGameObject::triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2) -> decltype(triggerObject(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*, int, gd::vector<int> const*>::func(&EndTriggerGameObject::triggerObject), this);
	using FunctionType = decltype(triggerObject(p0, p1, p2))(*)(EndTriggerGameObject*, GJBaseGameLayer*, int, gd::vector<int> const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20EndTriggerGameObject13triggerObjectEP15GJBaseGameLayeriPKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto EndTriggerGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&EndTriggerGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(EndTriggerGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20EndTriggerGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto EnhancedTriggerObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&EnhancedTriggerObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(EnhancedTriggerObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN21EnhancedTriggerObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto EnterEffectObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&EnterEffectObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(EnterEffectObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17EnterEffectObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto EventLinkTrigger::triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2) -> decltype(triggerObject(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*, int, gd::vector<int> const*>::func(&EventLinkTrigger::triggerObject), this);
	using FunctionType = decltype(triggerObject(p0, p1, p2))(*)(EventLinkTrigger*, GJBaseGameLayer*, int, gd::vector<int> const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16EventLinkTrigger13triggerObjectEP15GJBaseGameLayeriPKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto EventLinkTrigger::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&EventLinkTrigger::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(EventLinkTrigger*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16EventLinkTrigger17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

ExtendedLayer::ExtendedLayer() {}

auto GManager::loadDataFromFile(gd::string const& p0) -> decltype(loadDataFromFile(p0)) {
	using FunctionType = decltype(loadDataFromFile(p0))(*)(GManager*, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8GManager16loadDataFromFileERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GManager::loadFromCompressedString(gd::string& p0) -> decltype(loadFromCompressedString(p0)) {
	using FunctionType = decltype(loadFromCompressedString(p0))(*)(GManager*, gd::string&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8GManager24loadFromCompressedStringERSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GManager::loadFromString(gd::string& p0) -> decltype(loadFromString(p0)) {
	using FunctionType = decltype(loadFromString(p0))(*)(GManager*, gd::string&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8GManager14loadFromStringERSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GManager::saveData(DS_Dictionary* p0, gd::string p1) -> decltype(saveData(p0, p1)) {
	using FunctionType = decltype(saveData(p0, p1))(*)(GManager*, DS_Dictionary*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8GManager8saveDataEP13DS_DictionarySs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GManager::saveGMTo(gd::string p0) -> decltype(saveGMTo(p0)) {
	using FunctionType = decltype(saveGMTo(p0))(*)(GManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8GManager8saveGMToESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GManager::tryLoadData(DS_Dictionary* p0, gd::string const& p1) -> decltype(tryLoadData(p0, p1)) {
	using FunctionType = decltype(tryLoadData(p0, p1))(*)(GManager*, DS_Dictionary*, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8GManager11tryLoadDataEP13DS_DictionaryRKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

void FindBPMLayer::onInfo(cocos2d::CCObject* sender) {}

auto SetIDPopup::create(int current, int begin, int end, gd::string title, gd::string button, bool p5, int p6, float p7, bool p8, bool p9) -> decltype(create(current, begin, end, title, button, p5, p6, p7, p8, p9)) {
	using FunctionType = decltype(create(current, begin, end, title, button, p5, p6, p7, p8, p9))(*)(int, int, int, gd::string, gd::string, bool, int, float, bool, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10SetIDPopup6createEiiiSsSsbifbb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(current, begin, end, title, button, p5, p6, p7, p8, p9);
}

void SetIDPopup::valueChanged() {}

auto SetIDPopup::init(int current, int begin, int end, gd::string title, gd::string button, bool p5, int p6, float p7, bool p8, bool p9) -> decltype(init(current, begin, end, title, button, p5, p6, p7, p8, p9)) {
	using FunctionType = decltype(init(current, begin, end, title, button, p5, p6, p7, p8, p9))(*)(SetIDPopup*, int, int, int, gd::string, gd::string, bool, int, float, bool, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10SetIDPopup4initEiiiSsSsbifbb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, current, begin, end, title, button, p5, p6, p7, p8, p9);
}

FMODAudioEngine::FMODAudioEngine() : FMODAudioEngine(geode::CutoffConstructor, sizeof(FMODAudioEngine)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	FMODAudioEngine::~FMODAudioEngine();
	using FunctionType = void(*)(FMODAudioEngine*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngineC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

FMODAudioEngine* FMODAudioEngine::get() {
        return FMODAudioEngine::sharedEngine();
    }

int FMODAudioEngine::countActiveEffects() {
        return m_channelIDToChannel.size() - countActiveMusic();
    }

int FMODAudioEngine::countActiveMusic() {
        int count = 0;
        for (auto& music : m_musicChannels) {
            if (music.second.m_channelID > 0) {
                ++count;
            }
        }
        return count;
    }

auto FMODAudioEngine::createStream(gd::string p0) -> decltype(createStream(p0)) {
	using FunctionType = decltype(createStream(p0))(*)(FMODAudioEngine*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine12createStreamESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

void FMODAudioEngine::disableMetering() {
        this->m_metering = false;
    }

void FMODAudioEngine::enableMetering() {
        this->m_metering = true;
        this->m_pulse1 = 0.1f;
        this->m_pulse2 = 0.1f;
        this->m_pulse3 = 0.0f;
    }

float FMODAudioEngine::getEffectsVolume() {
        return m_sfxVolume;
    }

auto FMODAudioEngine::isEffectLoaded(gd::string path) -> decltype(isEffectLoaded(path)) {
	using FunctionType = decltype(isEffectLoaded(path))(*)(FMODAudioEngine*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine14isEffectLoadedESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, path);
}

auto FMODAudioEngine::isMusicPlaying(gd::string path, int p1) -> decltype(isMusicPlaying(path, p1)) {
	using FunctionType = decltype(isMusicPlaying(path, p1))(*)(FMODAudioEngine*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine14isMusicPlayingESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, path, p1);
}

auto FMODAudioEngine::isPersistentMatchPlaying(gd::string p0, int p1) -> decltype(isPersistentMatchPlaying(p0, p1)) {
	using FunctionType = decltype(isPersistentMatchPlaying(p0, p1))(*)(FMODAudioEngine*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine24isPersistentMatchPlayingESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto FMODAudioEngine::lengthForSound(gd::string path) -> decltype(lengthForSound(path)) {
	using FunctionType = decltype(lengthForSound(path))(*)(FMODAudioEngine*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine14lengthForSoundESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, path);
}

auto FMODAudioEngine::loadAndPlayMusic(gd::string p0, unsigned int p1, int p2) -> decltype(loadAndPlayMusic(p0, p1, p2)) {
	using FunctionType = decltype(loadAndPlayMusic(p0, p1, p2))(*)(FMODAudioEngine*, gd::string, unsigned int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine16loadAndPlayMusicESsji")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto FMODAudioEngine::loadMusic(gd::string path, float speed, float p2, float volume, bool shouldLoop, int p5, int p6) -> decltype(loadMusic(path, speed, p2, volume, shouldLoop, p5, p6)) {
	using FunctionType = decltype(loadMusic(path, speed, p2, volume, shouldLoop, p5, p6))(*)(FMODAudioEngine*, gd::string, float, float, float, bool, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine9loadMusicESsfffbii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, path, speed, p2, volume, shouldLoop, p5, p6);
}

void FMODAudioEngine::loadMusic(gd::string path) {
        this->loadMusic(path, 1.f, 0.f, 1.f, false, 0, 0);
    }

auto FMODAudioEngine::loadMusic(gd::string p0, float p1, float p2, float p3, bool p4, int p5, int p6, bool p7) -> decltype(loadMusic(p0, p1, p2, p3, p4, p5, p6, p7)) {
	using FunctionType = decltype(loadMusic(p0, p1, p2, p3, p4, p5, p6, p7))(*)(FMODAudioEngine*, gd::string, float, float, float, bool, int, int, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine9loadMusicESsfffbiib")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7);
}

void FMODAudioEngine::pauseAllEffects() {
        m_globalChannel->setPaused(true);
    }

auto FMODAudioEngine::playEffect(gd::string path, float speed, float p2, float volume) -> decltype(playEffect(path, speed, p2, volume)) {
	using FunctionType = decltype(playEffect(path, speed, p2, volume))(*)(FMODAudioEngine*, gd::string, float, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine10playEffectESsfff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, path, speed, p2, volume);
}

auto FMODAudioEngine::playEffect(gd::string path) -> decltype(playEffect(path)) {
	using FunctionType = decltype(playEffect(path))(*)(FMODAudioEngine*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine10playEffectESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, path);
}

auto FMODAudioEngine::playEffectAdvanced(gd::string path, float speed, float p2, float volume, float pitch, bool fastFourierTransform, bool reverb, int startMillis, int endMillis, int fadeIn, int fadeOut, bool loopEnabled, int p12, bool override, bool p14, int p15, int uniqueID, float minInterval, int sfxGroup) -> decltype(playEffectAdvanced(path, speed, p2, volume, pitch, fastFourierTransform, reverb, startMillis, endMillis, fadeIn, fadeOut, loopEnabled, p12, override, p14, p15, uniqueID, minInterval, sfxGroup)) {
	using FunctionType = decltype(playEffectAdvanced(path, speed, p2, volume, pitch, fastFourierTransform, reverb, startMillis, endMillis, fadeIn, fadeOut, loopEnabled, p12, override, p14, p15, uniqueID, minInterval, sfxGroup))(*)(FMODAudioEngine*, gd::string, float, float, float, float, bool, bool, int, int, int, int, bool, int, bool, bool, int, int, float, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine18playEffectAdvancedESsffffbbiiiibibbiifi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, path, speed, p2, volume, pitch, fastFourierTransform, reverb, startMillis, endMillis, fadeIn, fadeOut, loopEnabled, p12, override, p14, p15, uniqueID, minInterval, sfxGroup);
}

auto FMODAudioEngine::playEffectAsync(gd::string path) -> decltype(playEffectAsync(path)) {
	using FunctionType = decltype(playEffectAsync(path))(*)(FMODAudioEngine*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine15playEffectAsyncESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, path);
}

auto FMODAudioEngine::playMusic(gd::string path, bool shouldLoop, float fadeInTime, int channel) -> decltype(playMusic(path, shouldLoop, fadeInTime, channel)) {
	using FunctionType = decltype(playMusic(path, shouldLoop, fadeInTime, channel))(*)(FMODAudioEngine*, gd::string, bool, float, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine9playMusicESsbfi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, path, shouldLoop, fadeInTime, channel);
}

auto FMODAudioEngine::preloadEffect(gd::string path) -> decltype(preloadEffect(path)) {
	using FunctionType = decltype(preloadEffect(path))(*)(FMODAudioEngine*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine13preloadEffectESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, path);
}

auto FMODAudioEngine::preloadEffectAsync(gd::string path) -> decltype(preloadEffectAsync(path)) {
	using FunctionType = decltype(preloadEffectAsync(path))(*)(FMODAudioEngine*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine18preloadEffectAsyncESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, path);
}

auto FMODAudioEngine::preloadMusic(gd::string path, bool p1, int p2) -> decltype(preloadMusic(path, p1, p2)) {
	using FunctionType = decltype(preloadMusic(path, p1, p2))(*)(FMODAudioEngine*, gd::string, bool, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine12preloadMusicESsbi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, path, p1, p2);
}

auto FMODAudioEngine::queuedEffectFinishedLoading(gd::string p0) -> decltype(queuedEffectFinishedLoading(p0)) {
	using FunctionType = decltype(queuedEffectFinishedLoading(p0))(*)(FMODAudioEngine*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine27queuedEffectFinishedLoadingESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto FMODAudioEngine::queuePlayEffect(gd::string p0, float p1, float p2, float p3, float p4, bool p5, bool p6, int p7, int p8, int p9, int p10, bool p11, int p12, bool p13, int p14, float p15, int p16) -> decltype(queuePlayEffect(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16)) {
	using FunctionType = decltype(queuePlayEffect(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16))(*)(FMODAudioEngine*, gd::string, float, float, float, float, bool, bool, int, int, int, int, bool, int, bool, int, float, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine15queuePlayEffectESsffffbbiiiibibifi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16);
}

auto FMODAudioEngine::queueStartMusic(gd::string audioFilename, float p1, float p2, float p3, bool p4, int ms, int p6, int p7, int p8, int p9, bool p10, int p11, bool p12, bool p13) -> decltype(queueStartMusic(audioFilename, p1, p2, p3, p4, ms, p6, p7, p8, p9, p10, p11, p12, p13)) {
	using FunctionType = decltype(queueStartMusic(audioFilename, p1, p2, p3, p4, ms, p6, p7, p8, p9, p10, p11, p12, p13))(*)(FMODAudioEngine*, gd::string, float, float, float, bool, int, int, int, int, int, bool, int, bool, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine15queueStartMusicESsfffbiiiiibibb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, audioFilename, p1, p2, p3, p4, ms, p6, p7, p8, p9, p10, p11, p12, p13);
}

void FMODAudioEngine::resumeEffect(unsigned int p0) {}

auto FMODAudioEngine::storeEffect(FMOD::Sound* sound, gd::string path) -> decltype(storeEffect(sound, path)) {
	using FunctionType = decltype(storeEffect(sound, path))(*)(FMODAudioEngine*, FMOD::Sound*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine11storeEffectEPN4FMOD5SoundESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, sound, path);
}

auto FMODAudioEngine::unloadEffect(gd::string path) -> decltype(unloadEffect(path)) {
	using FunctionType = decltype(unloadEffect(path))(*)(FMODAudioEngine*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15FMODAudioEngine12unloadEffectESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, path);
}

FontObject::FontObject() {}

auto ForceBlockGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&ForceBlockGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(ForceBlockGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20ForceBlockGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto FriendRequestDelegate::setupPageInfo(gd::string p0, char const* p1) -> decltype(setupPageInfo(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string, char const*>::func(&FriendRequestDelegate::setupPageInfo), this);
	using FunctionType = decltype(setupPageInfo(p0, p1))(*)(FriendRequestDelegate*, gd::string, char const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN21FriendRequestDelegate13setupPageInfoESsPKc")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto FRequestProfilePage::setupPageInfo(gd::string p0, char const* p1) -> decltype(setupPageInfo(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string, char const*>::func(&FRequestProfilePage::setupPageInfo), this);
	using FunctionType = decltype(setupPageInfo(p0, p1))(*)(FRequestProfilePage*, gd::string, char const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19FRequestProfilePage13setupPageInfoESsPKc")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

GameCell::GameCell(char const* p0, float p1, float p2) : GameCell(geode::CutoffConstructor, sizeof(GameCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	GameCell::~GameCell();
	using FunctionType = void(*)(GameCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8GameCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GameCell::loadFromString(gd::string p0) -> decltype(loadFromString(p0)) {
	using FunctionType = decltype(loadFromString(p0))(*)(GameCell*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8GameCell14loadFromStringESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

GameLevelManager* GameLevelManager::get() {
        return GameLevelManager::sharedState();
    }

auto GameLevelManager::responseToDict(gd::string p0, bool p1) -> decltype(responseToDict(p0, p1)) {
	using FunctionType = decltype(responseToDict(p0, p1))(*)(gd::string, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager14responseToDictESsb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto GameLevelManager::createAndGetAccountComments(gd::string p0, int p1) -> decltype(createAndGetAccountComments(p0, p1)) {
	using FunctionType = decltype(createAndGetAccountComments(p0, p1))(*)(GameLevelManager*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager27createAndGetAccountCommentsESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GameLevelManager::createAndGetCommentsFull(gd::string p0, int p1, bool p2) -> decltype(createAndGetCommentsFull(p0, p1, p2)) {
	using FunctionType = decltype(createAndGetCommentsFull(p0, p1, p2))(*)(GameLevelManager*, gd::string, int, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager24createAndGetCommentsFullESsib")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GameLevelManager::createAndGetLevelComments(gd::string p0, int p1) -> decltype(createAndGetLevelComments(p0, p1)) {
	using FunctionType = decltype(createAndGetLevelComments(p0, p1))(*)(GameLevelManager*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager25createAndGetLevelCommentsESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GameLevelManager::createAndGetLevelLists(gd::string p0) -> decltype(createAndGetLevelLists(p0)) {
	using FunctionType = decltype(createAndGetLevelLists(p0))(*)(GameLevelManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager22createAndGetLevelListsESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameLevelManager::createAndGetLevels(gd::string p0) -> decltype(createAndGetLevels(p0)) {
	using FunctionType = decltype(createAndGetLevels(p0))(*)(GameLevelManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager18createAndGetLevelsESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameLevelManager::createAndGetMapPacks(gd::string p0) -> decltype(createAndGetMapPacks(p0)) {
	using FunctionType = decltype(createAndGetMapPacks(p0))(*)(GameLevelManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager20createAndGetMapPacksESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameLevelManager::createAndGetScores(gd::string p0, GJScoreType p1) -> decltype(createAndGetScores(p0, p1)) {
	using FunctionType = decltype(createAndGetScores(p0, p1))(*)(GameLevelManager*, gd::string, GJScoreType);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager18createAndGetScoresESs11GJScoreType")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

char const* GameLevelManager::getAccountCommentKey(int p0, int p1) {
        return cocos2d::CCString::createWithFormat("%i_%i", p0, p1)->getCString();
    }

gd::string GameLevelManager::getCommentKey(int ID, int page, int mode, CommentKeyType keytype) {
        return cocos2d::CCString::createWithFormat("comment_%i_%i_%i_%i", ID, page, mode, (int) keytype)->getCString();
    }

auto GameLevelManager::getGJSecretReward(gd::string p0) -> decltype(getGJSecretReward(p0)) {
	using FunctionType = decltype(getGJSecretReward(p0))(*)(GameLevelManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager17getGJSecretRewardESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

const char* GameLevelManager::getLevelDownloadKey(int levelID, bool isGauntlet) {
        return cocos2d::CCString::createWithFormat("%i_%i", levelID, isGauntlet)->getCString();
    }

const char* GameLevelManager::getLevelKey(int levelID) {
        return cocos2d::CCString::createWithFormat("%i", levelID)->getCString();
    }

auto GameLevelManager::getLocalLevelByName(gd::string p0) -> decltype(getLocalLevelByName(p0)) {
	using FunctionType = decltype(getLocalLevelByName(p0))(*)(GameLevelManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager19getLocalLevelByNameESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameLevelManager::getNextLevelName(gd::string p0) -> decltype(getNextLevelName(p0)) {
	using FunctionType = decltype(getNextLevelName(p0))(*)(GameLevelManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager16getNextLevelNameESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

const char* GameLevelManager::getTopArtistsKey(int page) {
        return cocos2d::CCString::createWithFormat("topArtists_%i", page)->getCString();
    }

auto GameLevelManager::handleIt(bool p0, gd::string p1, gd::string p2, GJHttpType p3) -> decltype(handleIt(p0, p1, p2, p3)) {
	using FunctionType = decltype(handleIt(p0, p1, p2, p3))(*)(GameLevelManager*, bool, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager8handleItEbSsSs10GJHttpType")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto GameLevelManager::handleItDelayed(bool p0, gd::string p1, gd::string p2, GJHttpType p3) -> decltype(handleItDelayed(p0, p1, p2, p3)) {
	using FunctionType = decltype(handleItDelayed(p0, p1, p2, p3))(*)(GameLevelManager*, bool, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager15handleItDelayedEbSsSs10GJHttpType")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto GameLevelManager::onAcceptFriendRequestCompleted(gd::string response, gd::string tag) -> decltype(onAcceptFriendRequestCompleted(response, tag)) {
	using FunctionType = decltype(onAcceptFriendRequestCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager30onAcceptFriendRequestCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onBanUserCompleted(gd::string response, gd::string tag) -> decltype(onBanUserCompleted(response, tag)) {
	using FunctionType = decltype(onBanUserCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager18onBanUserCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onBlockUserCompleted(gd::string response, gd::string tag) -> decltype(onBlockUserCompleted(response, tag)) {
	using FunctionType = decltype(onBlockUserCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager20onBlockUserCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onDeleteCommentCompleted(gd::string response, gd::string tag) -> decltype(onDeleteCommentCompleted(response, tag)) {
	using FunctionType = decltype(onDeleteCommentCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager24onDeleteCommentCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onDeleteFriendRequestCompleted(gd::string response, gd::string tag) -> decltype(onDeleteFriendRequestCompleted(response, tag)) {
	using FunctionType = decltype(onDeleteFriendRequestCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager30onDeleteFriendRequestCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onDeleteServerLevelCompleted(gd::string response, gd::string tag) -> decltype(onDeleteServerLevelCompleted(response, tag)) {
	using FunctionType = decltype(onDeleteServerLevelCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager28onDeleteServerLevelCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onDeleteServerLevelListCompleted(gd::string response, gd::string tag) -> decltype(onDeleteServerLevelListCompleted(response, tag)) {
	using FunctionType = decltype(onDeleteServerLevelListCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager32onDeleteServerLevelListCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onDeleteUserMessagesCompleted(gd::string response, gd::string tag) -> decltype(onDeleteUserMessagesCompleted(response, tag)) {
	using FunctionType = decltype(onDeleteUserMessagesCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager29onDeleteUserMessagesCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onDownloadLevelCompleted(gd::string response, gd::string tag) -> decltype(onDownloadLevelCompleted(response, tag)) {
	using FunctionType = decltype(onDownloadLevelCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager24onDownloadLevelCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onDownloadUserMessageCompleted(gd::string response, gd::string tag) -> decltype(onDownloadUserMessageCompleted(response, tag)) {
	using FunctionType = decltype(onDownloadUserMessageCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager30onDownloadUserMessageCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetAccountCommentsCompleted(gd::string response, gd::string tag) -> decltype(onGetAccountCommentsCompleted(response, tag)) {
	using FunctionType = decltype(onGetAccountCommentsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager29onGetAccountCommentsCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetFriendRequestsCompleted(gd::string response, gd::string tag) -> decltype(onGetFriendRequestsCompleted(response, tag)) {
	using FunctionType = decltype(onGetFriendRequestsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager28onGetFriendRequestsCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetGauntletsCompleted(gd::string response, gd::string tag) -> decltype(onGetGauntletsCompleted(response, tag)) {
	using FunctionType = decltype(onGetGauntletsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager23onGetGauntletsCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetGJChallengesCompleted(gd::string response, gd::string tag) -> decltype(onGetGJChallengesCompleted(response, tag)) {
	using FunctionType = decltype(onGetGJChallengesCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager26onGetGJChallengesCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetGJDailyLevelStateCompleted(gd::string response, gd::string tag) -> decltype(onGetGJDailyLevelStateCompleted(response, tag)) {
	using FunctionType = decltype(onGetGJDailyLevelStateCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager31onGetGJDailyLevelStateCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetGJRewardsCompleted(gd::string response, gd::string tag) -> decltype(onGetGJRewardsCompleted(response, tag)) {
	using FunctionType = decltype(onGetGJRewardsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager23onGetGJRewardsCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetGJSecretRewardCompleted(gd::string p0, gd::string p1) -> decltype(onGetGJSecretRewardCompleted(p0, p1)) {
	using FunctionType = decltype(onGetGJSecretRewardCompleted(p0, p1))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager28onGetGJSecretRewardCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GameLevelManager::onGetGJUserInfoCompleted(gd::string response, gd::string tag) -> decltype(onGetGJUserInfoCompleted(response, tag)) {
	using FunctionType = decltype(onGetGJUserInfoCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager24onGetGJUserInfoCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetLeaderboardScoresCompleted(gd::string response, gd::string tag) -> decltype(onGetLeaderboardScoresCompleted(response, tag)) {
	using FunctionType = decltype(onGetLeaderboardScoresCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager31onGetLeaderboardScoresCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetLevelCommentsCompleted(gd::string response, gd::string tag) -> decltype(onGetLevelCommentsCompleted(response, tag)) {
	using FunctionType = decltype(onGetLevelCommentsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager27onGetLevelCommentsCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetLevelLeaderboardCompleted(gd::string response, gd::string tag) -> decltype(onGetLevelLeaderboardCompleted(response, tag)) {
	using FunctionType = decltype(onGetLevelLeaderboardCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager30onGetLevelLeaderboardCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetLevelListsCompleted(gd::string response, gd::string tag) -> decltype(onGetLevelListsCompleted(response, tag)) {
	using FunctionType = decltype(onGetLevelListsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager24onGetLevelListsCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetLevelSaveDataCompleted(gd::string response, gd::string tag) -> decltype(onGetLevelSaveDataCompleted(response, tag)) {
	using FunctionType = decltype(onGetLevelSaveDataCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager27onGetLevelSaveDataCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetMapPacksCompleted(gd::string response, gd::string tag) -> decltype(onGetMapPacksCompleted(response, tag)) {
	using FunctionType = decltype(onGetMapPacksCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager22onGetMapPacksCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetNewsCompleted(gd::string response, gd::string tag) -> decltype(onGetNewsCompleted(response, tag)) {
	using FunctionType = decltype(onGetNewsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager18onGetNewsCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetOnlineLevelsCompleted(gd::string response, gd::string tag) -> decltype(onGetOnlineLevelsCompleted(response, tag)) {
	using FunctionType = decltype(onGetOnlineLevelsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager26onGetOnlineLevelsCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetTopArtistsCompleted(gd::string response, gd::string tag) -> decltype(onGetTopArtistsCompleted(response, tag)) {
	using FunctionType = decltype(onGetTopArtistsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager24onGetTopArtistsCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetUserListCompleted(gd::string response, gd::string tag) -> decltype(onGetUserListCompleted(response, tag)) {
	using FunctionType = decltype(onGetUserListCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager22onGetUserListCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetUserMessagesCompleted(gd::string response, gd::string tag) -> decltype(onGetUserMessagesCompleted(response, tag)) {
	using FunctionType = decltype(onGetUserMessagesCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager26onGetUserMessagesCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onGetUsersCompleted(gd::string response, gd::string tag) -> decltype(onGetUsersCompleted(response, tag)) {
	using FunctionType = decltype(onGetUsersCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager19onGetUsersCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onLikeItemCompleted(gd::string response, gd::string tag) -> decltype(onLikeItemCompleted(response, tag)) {
	using FunctionType = decltype(onLikeItemCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager19onLikeItemCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onRateDemonCompleted(gd::string response, gd::string tag) -> decltype(onRateDemonCompleted(response, tag)) {
	using FunctionType = decltype(onRateDemonCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager20onRateDemonCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onRateStarsCompleted(gd::string response, gd::string tag) -> decltype(onRateStarsCompleted(response, tag)) {
	using FunctionType = decltype(onRateStarsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager20onRateStarsCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onReadFriendRequestCompleted(gd::string response, gd::string tag) -> decltype(onReadFriendRequestCompleted(response, tag)) {
	using FunctionType = decltype(onReadFriendRequestCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager28onReadFriendRequestCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onRemoveFriendCompleted(gd::string response, gd::string tag) -> decltype(onRemoveFriendCompleted(response, tag)) {
	using FunctionType = decltype(onRemoveFriendCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager23onRemoveFriendCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onReportLevelCompleted(gd::string response, gd::string tag) -> decltype(onReportLevelCompleted(response, tag)) {
	using FunctionType = decltype(onReportLevelCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager22onReportLevelCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onRequestUserAccessCompleted(gd::string response, gd::string tag) -> decltype(onRequestUserAccessCompleted(response, tag)) {
	using FunctionType = decltype(onRequestUserAccessCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager28onRequestUserAccessCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onRestoreItemsCompleted(gd::string response, gd::string tag) -> decltype(onRestoreItemsCompleted(response, tag)) {
	using FunctionType = decltype(onRestoreItemsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager23onRestoreItemsCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onSetLevelFeaturedCompleted(gd::string response, gd::string tag) -> decltype(onSetLevelFeaturedCompleted(response, tag)) {
	using FunctionType = decltype(onSetLevelFeaturedCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager27onSetLevelFeaturedCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onSetLevelStarsCompleted(gd::string response, gd::string tag) -> decltype(onSetLevelStarsCompleted(response, tag)) {
	using FunctionType = decltype(onSetLevelStarsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager24onSetLevelStarsCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onSubmitUserInfoCompleted(gd::string response, gd::string tag) -> decltype(onSubmitUserInfoCompleted(response, tag)) {
	using FunctionType = decltype(onSubmitUserInfoCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager25onSubmitUserInfoCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onSuggestLevelStarsCompleted(gd::string response, gd::string tag) -> decltype(onSuggestLevelStarsCompleted(response, tag)) {
	using FunctionType = decltype(onSuggestLevelStarsCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager28onSuggestLevelStarsCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onUnblockUserCompleted(gd::string response, gd::string tag) -> decltype(onUnblockUserCompleted(response, tag)) {
	using FunctionType = decltype(onUnblockUserCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager22onUnblockUserCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onUpdateDescriptionCompleted(gd::string response, gd::string tag) -> decltype(onUpdateDescriptionCompleted(response, tag)) {
	using FunctionType = decltype(onUpdateDescriptionCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager28onUpdateDescriptionCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onUpdateLevelCompleted(gd::string response, gd::string tag) -> decltype(onUpdateLevelCompleted(response, tag)) {
	using FunctionType = decltype(onUpdateLevelCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager22onUpdateLevelCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onUpdateUserScoreCompleted(gd::string response, gd::string tag) -> decltype(onUpdateUserScoreCompleted(response, tag)) {
	using FunctionType = decltype(onUpdateUserScoreCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager26onUpdateUserScoreCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onUploadCommentCompleted(gd::string response, gd::string tag) -> decltype(onUploadCommentCompleted(response, tag)) {
	using FunctionType = decltype(onUploadCommentCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager24onUploadCommentCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onUploadFriendRequestCompleted(gd::string response, gd::string tag) -> decltype(onUploadFriendRequestCompleted(response, tag)) {
	using FunctionType = decltype(onUploadFriendRequestCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager30onUploadFriendRequestCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onUploadLevelCompleted(gd::string response, gd::string tag) -> decltype(onUploadLevelCompleted(response, tag)) {
	using FunctionType = decltype(onUploadLevelCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager22onUploadLevelCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onUploadLevelListCompleted(gd::string response, gd::string tag) -> decltype(onUploadLevelListCompleted(response, tag)) {
	using FunctionType = decltype(onUploadLevelListCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager26onUploadLevelListCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::onUploadUserMessageCompleted(gd::string response, gd::string tag) -> decltype(onUploadUserMessageCompleted(response, tag)) {
	using FunctionType = decltype(onUploadUserMessageCompleted(response, tag))(*)(GameLevelManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager28onUploadUserMessageCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag);
}

auto GameLevelManager::parseRestoreData(gd::string p0) -> decltype(parseRestoreData(p0)) {
	using FunctionType = decltype(parseRestoreData(p0))(*)(GameLevelManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager16parseRestoreDataESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameLevelManager::ProcessHttpRequest(gd::string endpoint, gd::string params, gd::string tag, GJHttpType httpType) -> decltype(ProcessHttpRequest(endpoint, params, tag, httpType)) {
	using FunctionType = decltype(ProcessHttpRequest(endpoint, params, tag, httpType))(*)(GameLevelManager*, gd::string, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager18ProcessHttpRequestESsSsSs10GJHttpType")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, endpoint, params, tag, httpType);
}

auto GameLevelManager::processOnDownloadLevelCompleted(gd::string response, gd::string tag, bool p2) -> decltype(processOnDownloadLevelCompleted(response, tag, p2)) {
	using FunctionType = decltype(processOnDownloadLevelCompleted(response, tag, p2))(*)(GameLevelManager*, gd::string, gd::string, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager31processOnDownloadLevelCompletedESsSsb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, response, tag, p2);
}

auto GameLevelManager::removeDelimiterChars(gd::string p0, bool p1) -> decltype(removeDelimiterChars(p0, p1)) {
	using FunctionType = decltype(removeDelimiterChars(p0, p1))(*)(GameLevelManager*, gd::string, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager20removeDelimiterCharsESsb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

void GameLevelManager::resetAccountComments(int accountID) {
        for(int i = 0; i <= 1; i++) {
            auto key = getAccountCommentKey(accountID, i);
            if(getStoredOnlineLevels(key)) {
                m_storedLevels->removeObjectForKey(key);
            }
        }
    }

auto GameLevelManager::setFolderName(int p0, gd::string p1, bool p2) -> decltype(setFolderName(p0, p1, p2)) {
	using FunctionType = decltype(setFolderName(p0, p1, p2))(*)(GameLevelManager*, int, gd::string, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager13setFolderNameEiSsb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GameLevelManager::storeCommentsResult(cocos2d::CCArray* p0, gd::string p1, char const* p2) -> decltype(storeCommentsResult(p0, p1, p2)) {
	using FunctionType = decltype(storeCommentsResult(p0, p1, p2))(*)(GameLevelManager*, cocos2d::CCArray*, gd::string, char const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager19storeCommentsResultEPN7cocos2d7CCArrayESsPKc")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GameLevelManager::storeSearchResult(cocos2d::CCArray* levels, gd::string pageInfo, char const* searchKey) -> decltype(storeSearchResult(levels, pageInfo, searchKey)) {
	using FunctionType = decltype(storeSearchResult(levels, pageInfo, searchKey))(*)(GameLevelManager*, cocos2d::CCArray*, gd::string, char const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager17storeSearchResultEPN7cocos2d7CCArrayESsPKc")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, levels, pageInfo, searchKey);
}

auto GameLevelManager::storeUserName(int userID, int accountID, gd::string userName) -> decltype(storeUserName(userID, accountID, userName)) {
	using FunctionType = decltype(storeUserName(userID, accountID, userName))(*)(GameLevelManager*, int, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager13storeUserNameEiiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, userID, accountID, userName);
}

auto GameLevelManager::storeUserNames(gd::string usernameString) -> decltype(storeUserNames(usernameString)) {
	using FunctionType = decltype(storeUserNames(usernameString))(*)(GameLevelManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager14storeUserNamesESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, usernameString);
}

auto GameLevelManager::updateDescription(int p0, gd::string p1) -> decltype(updateDescription(p0, p1)) {
	using FunctionType = decltype(updateDescription(p0, p1))(*)(GameLevelManager*, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager17updateDescriptionEiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GameLevelManager::uploadAccountComment(gd::string p0) -> decltype(uploadAccountComment(p0)) {
	using FunctionType = decltype(uploadAccountComment(p0))(*)(GameLevelManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager20uploadAccountCommentESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameLevelManager::uploadComment(gd::string p0, CommentType p1, int p2, int p3) -> decltype(uploadComment(p0, p1, p2, p3)) {
	using FunctionType = decltype(uploadComment(p0, p1, p2, p3))(*)(GameLevelManager*, gd::string, CommentType, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager13uploadCommentESs11CommentTypeii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto GameLevelManager::uploadFriendRequest(int p0, gd::string p1) -> decltype(uploadFriendRequest(p0, p1)) {
	using FunctionType = decltype(uploadFriendRequest(p0, p1))(*)(GameLevelManager*, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager19uploadFriendRequestEiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GameLevelManager::uploadLevelComment(int p0, gd::string p1, int p2) -> decltype(uploadLevelComment(p0, p1, p2)) {
	using FunctionType = decltype(uploadLevelComment(p0, p1, p2))(*)(GameLevelManager*, int, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager18uploadLevelCommentEiSsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GameLevelManager::uploadUserMessage(int p0, gd::string p1, gd::string p2) -> decltype(uploadUserMessage(p0, p1, p2)) {
	using FunctionType = decltype(uploadUserMessage(p0, p1, p2))(*)(GameLevelManager*, int, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameLevelManager17uploadUserMessageEiSsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

GameManager::~GameManager() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(GameManager*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameManagerD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) GameManager(geode::CutoffConstructor, sizeof(GameManager));
	CCDestructor::lock(this) = true;
}

GameManager* GameManager::get() {
        return GameManager::sharedState();
    }

auto GameManager::addCustomAnimationFrame(int p0, int p1, gd::string p2, gd::string p3) -> decltype(addCustomAnimationFrame(p0, p1, p2, p3)) {
	using FunctionType = decltype(addCustomAnimationFrame(p0, p1, p2, p3))(*)(GameManager*, int, int, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameManager23addCustomAnimationFrameEiiSsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto GameManager::addGameAnimation(int p0, int p1, float p2, gd::string p3, gd::string p4, int p5) -> decltype(addGameAnimation(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(addGameAnimation(p0, p1, p2, p3, p4, p5))(*)(GameManager*, int, int, float, gd::string, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameManager16addGameAnimationEiifSsSsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto GameManager::addNewCustomObject(gd::string str) -> decltype(addNewCustomObject(str)) {
	using FunctionType = decltype(addNewCustomObject(str))(*)(GameManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameManager18addNewCustomObjectESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, str);
}

auto GameManager::claimItemsResponse(gd::string p0) -> decltype(claimItemsResponse(p0)) {
	using FunctionType = decltype(claimItemsResponse(p0))(*)(GameManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameManager18claimItemsResponseESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameManager::completedAchievement(gd::string p0) -> decltype(completedAchievement(p0)) {
	using FunctionType = decltype(completedAchievement(p0))(*)(GameManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameManager20completedAchievementESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameManager::fadeInMusic(gd::string p0) -> decltype(fadeInMusic(p0)) {
	using FunctionType = decltype(fadeInMusic(p0))(*)(GameManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameManager11fadeInMusicESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

LevelEditorLayer* GameManager::getEditorLayer() {
        return m_levelEditorLayer;
    }

GJBaseGameLayer* GameManager::getGameLayer() {
        return m_gameLayer;
    }

bool GameManager::getGameVariableDefault(const char* key, bool defaultValue) {
        //helper function
        auto object = static_cast<cocos2d::CCString*>(m_valueKeeper->objectForKey(std::string("gv_") + key));
        if (object == nullptr)
            return defaultValue;
        return object->boolValue();
    }

int GameManager::getIconRequestID() {
        return m_iconRequestID++;
    }

int GameManager::getIntGameVariableDefault(const char* key, int defaultValue) {
        //helper function
        auto object = static_cast<cocos2d::CCString*>(m_valueKeeper->objectForKey(std::string("gv_") + key));
        if (object == nullptr)
            return defaultValue;
        return object->intValue();
    }

int GameManager::getPlayerBall() {
        return m_playerBall;
    }

int GameManager::getPlayerBird() {
        return m_playerBird;
    }

int GameManager::getPlayerColor() {
        return m_playerColor;
    }

int GameManager::getPlayerColor2() {
        return m_playerColor2;
    }

int GameManager::getPlayerDart() {
        return m_playerDart;
    }

int GameManager::getPlayerDeathEffect() {
        return m_playerDeathEffect;
    }

int GameManager::getPlayerFrame() {
        return m_playerFrame;
    }

bool GameManager::getPlayerGlow() {
        return m_playerGlow;
    }

int GameManager::getPlayerGlowColor() {
        return m_playerGlowColor;
    }

int GameManager::getPlayerJetpack() {
        return m_playerJetpack;
    }

int GameManager::getPlayerRobot() {
        return m_playerRobot;
    }

int GameManager::getPlayerShip() {
        return m_playerShip;
    }

int GameManager::getPlayerShipFire() {
        return m_playerShipFire;
    }

int GameManager::getPlayerSpider() {
        return m_playerSpider;
    }

int GameManager::getPlayerStreak() {
        return m_playerStreak;
    }

int GameManager::getPlayerSwing() {
        return m_playerSwing;
    }

PlayLayer* GameManager::getPlayLayer() {
        return m_playLayer;
    }

auto GameManager::getUnlockForAchievement(gd::string p0, int& p1, UnlockType& p2) -> decltype(getUnlockForAchievement(p0, p1, p2)) {
	using FunctionType = decltype(getUnlockForAchievement(p0, p1, p2))(*)(GameManager*, gd::string, int&, UnlockType&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameManager23getUnlockForAchievementESsRiR10UnlockType")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

int GameManager::keyForIcon(int iconIdx, int iconEnum) {
        return m_keyStartForIcon.at(iconEnum) + iconIdx - 1;
    }

auto GameManager::loadDpadFromString(UIButtonConfig& p0, gd::string p1) -> decltype(loadDpadFromString(p0, p1)) {
	using FunctionType = decltype(loadDpadFromString(p0, p1))(*)(GameManager*, UIButtonConfig&, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameManager18loadDpadFromStringER14UIButtonConfigSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GameManager::recountUserStats(gd::string p0) -> decltype(recountUserStats(p0)) {
	using FunctionType = decltype(recountUserStats(p0))(*)(GameManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameManager16recountUserStatsESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

void GameManager::reloadAll(bool switchingModes, bool toFullscreen, bool unused) {
        return this->reloadAll(switchingModes, toFullscreen, false, false, unused);
    }

auto GameManager::resetAchievement(gd::string p0) -> decltype(resetAchievement(p0)) {
	using FunctionType = decltype(resetAchievement(p0))(*)(GameManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameManager16resetAchievementESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

void GameManager::setPlayerBall(int id) {
        m_playerBall = id;
    }

void GameManager::setPlayerBird(int id) {
        m_playerBird = id;
    }

void GameManager::setPlayerColor(int id) {
        m_playerColor = id;
    }

void GameManager::setPlayerColor2(int id) {
        m_playerColor2 = id;
    }

void GameManager::setPlayerColor3(int id) {
        m_playerGlowColor = id;
    }

void GameManager::setPlayerDart(int id) {
        m_playerDart = id;
    }

void GameManager::setPlayerDeathEffect(int id) {
        m_playerDeathEffect = id;
    }

void GameManager::setPlayerFrame(int id) {
        m_playerFrame = id;
    }

void GameManager::setPlayerGlow(bool v) {
        m_playerGlow = v;
    }

void GameManager::setPlayerJetpack(int id) {
        m_playerJetpack = id;
    }

void GameManager::setPlayerRobot(int id) {
        m_playerRobot = id;
    }

void GameManager::setPlayerShip(int id) {
        m_playerShip = id;
    }

void GameManager::setPlayerShipStreak(int id) {
        m_playerShipFire = id;
    }

void GameManager::setPlayerSpider(int id) {
        m_playerSpider = id;
    }

void GameManager::setPlayerStreak(int id) {
        m_playerStreak = id;
    }

void GameManager::setPlayerSwing(int id) {
        m_playerSwing = id;
    }

GameOptionsLayer::GameOptionsLayer() : GameOptionsLayer(geode::CutoffConstructor, sizeof(GameOptionsLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	GameOptionsLayer::~GameOptionsLayer();
	using FunctionType = void(*)(GameOptionsLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameOptionsLayerC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

auto GameOptionsTrigger::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&GameOptionsTrigger::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(GameOptionsTrigger*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN18GameOptionsTrigger17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

GameStatsManager* GameStatsManager::get() {
        return GameStatsManager::sharedState();
    }

auto GameStatsManager::addSimpleSpecialChestReward(gd::string p0, UnlockType p1, int p2, bool p3) -> decltype(addSimpleSpecialChestReward(p0, p1, p2, p3)) {
	using FunctionType = decltype(addSimpleSpecialChestReward(p0, p1, p2, p3))(*)(GameStatsManager*, gd::string, UnlockType, int, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameStatsManager27addSimpleSpecialChestRewardESs10UnlockTypeib")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto GameStatsManager::addSpecialRewardDescription(gd::string p0, gd::string p1) -> decltype(addSpecialRewardDescription(p0, p1)) {
	using FunctionType = decltype(addSpecialRewardDescription(p0, p1))(*)(GameStatsManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameStatsManager27addSpecialRewardDescriptionESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GameStatsManager::createReward(GJRewardType p0, int p1, gd::string p2) -> decltype(createReward(p0, p1, p2)) {
	using FunctionType = decltype(createReward(p0, p1, p2))(*)(GameStatsManager*, GJRewardType, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameStatsManager12createRewardE12GJRewardTypeiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GameStatsManager::getRewardForSpecialChest(gd::string p0) -> decltype(getRewardForSpecialChest(p0)) {
	using FunctionType = decltype(getRewardForSpecialChest(p0))(*)(GameStatsManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameStatsManager24getRewardForSpecialChestESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameStatsManager::getSpecialRewardDescription(gd::string p0, bool p1) -> decltype(getSpecialRewardDescription(p0, p1)) {
	using FunctionType = decltype(getSpecialRewardDescription(p0, p1))(*)(GameStatsManager*, gd::string, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameStatsManager27getSpecialRewardDescriptionESsb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GameStatsManager::isSecretCoin(gd::string p0) -> decltype(isSecretCoin(p0)) {
	using FunctionType = decltype(isSecretCoin(p0))(*)(GameStatsManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameStatsManager12isSecretCoinESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameStatsManager::isSecretCoinValid(gd::string p0) -> decltype(isSecretCoinValid(p0)) {
	using FunctionType = decltype(isSecretCoinValid(p0))(*)(GameStatsManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameStatsManager17isSecretCoinValidESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameStatsManager::isSpecialChestLiteUnlockable(gd::string p0) -> decltype(isSpecialChestLiteUnlockable(p0)) {
	using FunctionType = decltype(isSpecialChestLiteUnlockable(p0))(*)(GameStatsManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameStatsManager28isSpecialChestLiteUnlockableESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameStatsManager::isSpecialChestUnlocked(gd::string p0) -> decltype(isSpecialChestUnlocked(p0)) {
	using FunctionType = decltype(isSpecialChestUnlocked(p0))(*)(GameStatsManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameStatsManager22isSpecialChestUnlockedESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameStatsManager::linkSpecialChestUnlocks(GJRewardItem* p0, gd::string p1) -> decltype(linkSpecialChestUnlocks(p0, p1)) {
	using FunctionType = decltype(linkSpecialChestUnlocks(p0, p1))(*)(GameStatsManager*, GJRewardItem*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameStatsManager23linkSpecialChestUnlocksEP12GJRewardItemSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GameStatsManager::resetSpecialChest(gd::string p0) -> decltype(resetSpecialChest(p0)) {
	using FunctionType = decltype(resetSpecialChest(p0))(*)(GameStatsManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameStatsManager17resetSpecialChestESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameStatsManager::storeOnlineChest(gd::string p0, GJRewardItem* p1) -> decltype(storeOnlineChest(p0, p1)) {
	using FunctionType = decltype(storeOnlineChest(p0, p1))(*)(GameStatsManager*, gd::string, GJRewardItem*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameStatsManager16storeOnlineChestESsP12GJRewardItem")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GameStatsManager::storeRewardState(GJRewardType p0, int p1, int p2, gd::string p3) -> decltype(storeRewardState(p0, p1, p2, p3)) {
	using FunctionType = decltype(storeRewardState(p0, p1, p2, p3))(*)(GameStatsManager*, GJRewardType, int, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameStatsManager16storeRewardStateE12GJRewardTypeiiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto GameStatsManager::unlockOnlineChest(gd::string p0) -> decltype(unlockOnlineChest(p0)) {
	using FunctionType = decltype(unlockOnlineChest(p0))(*)(GameStatsManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameStatsManager17unlockOnlineChestESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameStatsManager::unlockSpecialChest(gd::string p0) -> decltype(unlockSpecialChest(p0)) {
	using FunctionType = decltype(unlockSpecialChest(p0))(*)(GameStatsManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GameStatsManager18unlockSpecialChestESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GameToolbox::createHashString(gd::string const& p0, int p1) -> decltype(createHashString(p0, p1)) {
	using FunctionType = decltype(createHashString(p0, p1))(*)(gd::string const&, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameToolbox16createHashStringERKSsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto GameToolbox::createToggleButton(gd::string label, cocos2d::SEL_MenuHandler selector, bool state, cocos2d::CCMenu* menu, cocos2d::CCPoint position, cocos2d::CCNode* parent, cocos2d::CCNode* labelParent, cocos2d::CCArray* container) -> decltype(createToggleButton(label, selector, state, menu, position, parent, labelParent, container)) {
	using FunctionType = decltype(createToggleButton(label, selector, state, menu, position, parent, labelParent, container))(*)(gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint, cocos2d::CCNode*, cocos2d::CCNode*, cocos2d::CCArray*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameToolbox18createToggleButtonESsMN7cocos2d8CCObjectEFvPS1_EbPNS0_6CCMenuENS0_7CCPointEPNS0_6CCNodeES9_PNS0_7CCArrayE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(label, selector, state, menu, position, parent, labelParent, container);
}

auto GameToolbox::createToggleButton(gd::string label, cocos2d::SEL_MenuHandler selector, bool state, cocos2d::CCMenu* menu, cocos2d::CCPoint position, cocos2d::CCNode* parent, cocos2d::CCNode* labelParent, float buttonScale, float maxLabelScale, float maxLabelWidth, cocos2d::CCPoint labelOffset, char const* font, bool labelTop, int labelTag, cocos2d::CCArray* container) -> decltype(createToggleButton(label, selector, state, menu, position, parent, labelParent, buttonScale, maxLabelScale, maxLabelWidth, labelOffset, font, labelTop, labelTag, container)) {
	using FunctionType = decltype(createToggleButton(label, selector, state, menu, position, parent, labelParent, buttonScale, maxLabelScale, maxLabelWidth, labelOffset, font, labelTop, labelTag, container))(*)(gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint, cocos2d::CCNode*, cocos2d::CCNode*, float, float, float, cocos2d::CCPoint, char const*, bool, int, cocos2d::CCArray*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameToolbox18createToggleButtonESsMN7cocos2d8CCObjectEFvPS1_EbPNS0_6CCMenuENS0_7CCPointEPNS0_6CCNodeES9_fffS7_PKcbiPNS0_7CCArrayE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(label, selector, state, menu, position, parent, labelParent, buttonScale, maxLabelScale, maxLabelWidth, labelOffset, font, labelTop, labelTag, container);
}

auto GameToolbox::hsvFromString(gd::string const& p0, char const* p1) -> decltype(hsvFromString(p0, p1)) {
	using FunctionType = decltype(hsvFromString(p0, p1))(*)(gd::string const&, char const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameToolbox13hsvFromStringERKSsPKc")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto GameToolbox::openRateURL(gd::string p0, gd::string p1) -> decltype(openRateURL(p0, p1)) {
	using FunctionType = decltype(openRateURL(p0, p1))(*)(gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameToolbox11openRateURLESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto GameToolbox::particleFromString(gd::string const& str, cocos2d::CCParticleSystemQuad* system, bool p2) -> decltype(particleFromString(str, system, p2)) {
	using FunctionType = decltype(particleFromString(str, system, p2))(*)(gd::string const&, cocos2d::CCParticleSystemQuad*, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameToolbox18particleFromStringERKSsPN7cocos2d20CCParticleSystemQuadEb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(str, system, p2);
}

auto GameToolbox::particleStringToStruct(gd::string const& p0, cocos2d::ParticleStruct& p1) -> decltype(particleStringToStruct(p0, p1)) {
	using FunctionType = decltype(particleStringToStruct(p0, p1))(*)(gd::string const&, cocos2d::ParticleStruct&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameToolbox22particleStringToStructERKSsRN7cocos2d14ParticleStructE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto GameToolbox::saveStringToFile(gd::string const& p0, gd::string const& p1) -> decltype(saveStringToFile(p0, p1)) {
	using FunctionType = decltype(saveStringToFile(p0, p1))(*)(gd::string const&, gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameToolbox16saveStringToFileERKSsS1_")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto GameToolbox::stringSetupToDict(gd::string const& p0, char const* p1) -> decltype(stringSetupToDict(p0, p1)) {
	using FunctionType = decltype(stringSetupToDict(p0, p1))(*)(gd::string const&, char const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameToolbox17stringSetupToDictERKSsPKc")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto GameToolbox::stringSetupToMap(gd::string const& p0, char const* p1, gd::map<gd::string, gd::string>& p2) -> decltype(stringSetupToMap(p0, p1, p2)) {
	using FunctionType = decltype(stringSetupToMap(p0, p1, p2))(*)(gd::string const&, char const*, gd::map<gd::string, gd::string>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GameToolbox16stringSetupToMapERKSsPKcRSt3mapISsSsSt4lessISsESaISt4pairIS0_SsEEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

void LevelManagerDelegate::loadLevelsFinished(cocos2d::CCArray* p0, char const* p1) {}

void LevelManagerDelegate::loadLevelsFailed(char const* p0) {}

void LevelManagerDelegate::loadLevelsFinished(cocos2d::CCArray* p0, char const* p1, int p2) {}

void LevelManagerDelegate::loadLevelsFailed(char const* p0, int p1) {}

void LevelManagerDelegate::setupPageInfo(gd::string p0, char const* p1) {}

GauntletLayer::GauntletLayer() {}

GauntletNode::GauntletNode() {}

GauntletSelectLayer::GauntletSelectLayer() {}

GauntletSprite::GauntletSprite() {}

void GhostTrailEffect::draw() {}

GJAccountManager* GJAccountManager::get() {
        return GJAccountManager::sharedState();
    }

auto GJAccountManager::backupAccount(gd::string p0) -> decltype(backupAccount(p0)) {
	using FunctionType = decltype(backupAccount(p0))(*)(GJAccountManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GJAccountManager13backupAccountESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJAccountManager::getShaPassword(gd::string p0) -> decltype(getShaPassword(p0)) {
	using FunctionType = decltype(getShaPassword(p0))(*)(GJAccountManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GJAccountManager14getShaPasswordESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJAccountManager::handleIt(bool p0, gd::string p1, gd::string p2, GJHttpType p3) -> decltype(handleIt(p0, p1, p2, p3)) {
	using FunctionType = decltype(handleIt(p0, p1, p2, p3))(*)(GJAccountManager*, bool, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GJAccountManager8handleItEbSsSs10GJHttpType")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto GJAccountManager::handleItDelayed(bool p0, gd::string p1, gd::string p2, GJHttpType p3) -> decltype(handleItDelayed(p0, p1, p2, p3)) {
	using FunctionType = decltype(handleItDelayed(p0, p1, p2, p3))(*)(GJAccountManager*, bool, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GJAccountManager15handleItDelayedEbSsSs10GJHttpType")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto GJAccountManager::linkToAccount(gd::string p0, gd::string p1, int p2, int p3) -> decltype(linkToAccount(p0, p1, p2, p3)) {
	using FunctionType = decltype(linkToAccount(p0, p1, p2, p3))(*)(GJAccountManager*, gd::string, gd::string, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GJAccountManager13linkToAccountESsSsii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto GJAccountManager::loginAccount(gd::string p0, gd::string p1) -> decltype(loginAccount(p0, p1)) {
	using FunctionType = decltype(loginAccount(p0, p1))(*)(GJAccountManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GJAccountManager12loginAccountESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJAccountManager::onBackupAccountCompleted(gd::string p0, gd::string p1) -> decltype(onBackupAccountCompleted(p0, p1)) {
	using FunctionType = decltype(onBackupAccountCompleted(p0, p1))(*)(GJAccountManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GJAccountManager24onBackupAccountCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJAccountManager::onGetAccountBackupURLCompleted(gd::string p0, gd::string p1) -> decltype(onGetAccountBackupURLCompleted(p0, p1)) {
	using FunctionType = decltype(onGetAccountBackupURLCompleted(p0, p1))(*)(GJAccountManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GJAccountManager30onGetAccountBackupURLCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJAccountManager::onGetAccountSyncURLCompleted(gd::string p0, gd::string p1) -> decltype(onGetAccountSyncURLCompleted(p0, p1)) {
	using FunctionType = decltype(onGetAccountSyncURLCompleted(p0, p1))(*)(GJAccountManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GJAccountManager28onGetAccountSyncURLCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJAccountManager::onLoginAccountCompleted(gd::string p0, gd::string p1) -> decltype(onLoginAccountCompleted(p0, p1)) {
	using FunctionType = decltype(onLoginAccountCompleted(p0, p1))(*)(GJAccountManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GJAccountManager23onLoginAccountCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJAccountManager::onRegisterAccountCompleted(gd::string p0, gd::string p1) -> decltype(onRegisterAccountCompleted(p0, p1)) {
	using FunctionType = decltype(onRegisterAccountCompleted(p0, p1))(*)(GJAccountManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GJAccountManager26onRegisterAccountCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJAccountManager::onSyncAccountCompleted(gd::string p0, gd::string p1) -> decltype(onSyncAccountCompleted(p0, p1)) {
	using FunctionType = decltype(onSyncAccountCompleted(p0, p1))(*)(GJAccountManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GJAccountManager22onSyncAccountCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJAccountManager::onUpdateAccountSettingsCompleted(gd::string p0, gd::string p1) -> decltype(onUpdateAccountSettingsCompleted(p0, p1)) {
	using FunctionType = decltype(onUpdateAccountSettingsCompleted(p0, p1))(*)(GJAccountManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GJAccountManager32onUpdateAccountSettingsCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJAccountManager::ProcessHttpRequest(gd::string p0, gd::string p1, gd::string p2, GJHttpType p3) -> decltype(ProcessHttpRequest(p0, p1, p2, p3)) {
	using FunctionType = decltype(ProcessHttpRequest(p0, p1, p2, p3))(*)(GJAccountManager*, gd::string, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GJAccountManager18ProcessHttpRequestESsSsSs10GJHttpType")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto GJAccountManager::registerAccount(gd::string p0, gd::string p1, gd::string p2) -> decltype(registerAccount(p0, p1, p2)) {
	using FunctionType = decltype(registerAccount(p0, p1, p2))(*)(GJAccountManager*, gd::string, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GJAccountManager15registerAccountESsSsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GJAccountManager::syncAccount(gd::string p0) -> decltype(syncAccount(p0)) {
	using FunctionType = decltype(syncAccount(p0))(*)(GJAccountManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GJAccountManager11syncAccountESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJAccountManager::updateAccountSettings(int p0, int p1, int p2, gd::string p3, gd::string p4, gd::string p5) -> decltype(updateAccountSettings(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(updateAccountSettings(p0, p1, p2, p3, p4, p5))(*)(GJAccountManager*, int, int, int, gd::string, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GJAccountManager21updateAccountSettingsEiiiSsSsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto GJAccountSettingsLayer::createToggleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCMenu* p3, cocos2d::CCPoint p4, float p5, float p6) -> decltype(createToggleButton(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(createToggleButton(p0, p1, p2, p3, p4, p5, p6))(*)(GJAccountSettingsLayer*, gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22GJAccountSettingsLayer18createToggleButtonESsMN7cocos2d8CCObjectEFvPS1_EbPNS0_6CCMenuENS0_7CCPointEff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6);
}

void TriggerEffectDelegate::toggleGroupTriggered(int p0, bool p1, gd::vector<int> const& p2, int p3, int p4) {}

void TriggerEffectDelegate::spawnGroup(int p0, bool p1, double p2, gd::vector<int> const& p3, int p4, int p5) {}

void TriggerEffectDelegate::spawnObject(GameObject* p0, double p1, gd::vector<int> const& p2) {}

GJBaseGameLayer::~GJBaseGameLayer() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(GJBaseGameLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayerD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) GJBaseGameLayer(geode::CutoffConstructor, sizeof(GJBaseGameLayer));
	CCDestructor::lock(this) = true;
}

GJBaseGameLayer* GJBaseGameLayer::get() {
        return GameManager::get()->m_gameLayer;
    }

auto GJBaseGameLayer::toggleGroupTriggered(int p0, bool p1, gd::vector<int> const& p2, int p3, int p4) -> decltype(toggleGroupTriggered(p0, p1, p2, p3, p4)) {
	auto self = addresser::thunkAdjust(Resolve<int, bool, gd::vector<int> const&, int, int>::func(&GJBaseGameLayer::toggleGroupTriggered), this);
	using FunctionType = decltype(toggleGroupTriggered(p0, p1, p2, p3, p4))(*)(GJBaseGameLayer*, int, bool, gd::vector<int> const&, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer20toggleGroupTriggeredEibRKSt6vectorIiSaIiEEii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2, p3, p4);
}

auto GJBaseGameLayer::spawnGroup(int p0, bool p1, double p2, gd::vector<int> const& p3, int p4, int p5) -> decltype(spawnGroup(p0, p1, p2, p3, p4, p5)) {
	auto self = addresser::thunkAdjust(Resolve<int, bool, double, gd::vector<int> const&, int, int>::func(&GJBaseGameLayer::spawnGroup), this);
	using FunctionType = decltype(spawnGroup(p0, p1, p2, p3, p4, p5))(*)(GJBaseGameLayer*, int, bool, double, gd::vector<int> const&, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer10spawnGroupEibdRKSt6vectorIiSaIiEEii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2, p3, p4, p5);
}

auto GJBaseGameLayer::spawnObject(GameObject* p0, double p1, gd::vector<int> const& p2) -> decltype(spawnObject(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<GameObject*, double, gd::vector<int> const&>::func(&GJBaseGameLayer::spawnObject), this);
	using FunctionType = decltype(spawnObject(p0, p1, p2))(*)(GJBaseGameLayer*, GameObject*, double, gd::vector<int> const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer11spawnObjectEP10GameObjectdRKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto GJBaseGameLayer::activatePlatformerEndTrigger(EndTriggerGameObject* p0, gd::vector<int> const& p1) -> decltype(activatePlatformerEndTrigger(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<EndTriggerGameObject*, gd::vector<int> const&>::func(&GJBaseGameLayer::activatePlatformerEndTrigger), this);
	using FunctionType = decltype(activatePlatformerEndTrigger(p0, p1))(*)(GJBaseGameLayer*, EndTriggerGameObject*, gd::vector<int> const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer28activatePlatformerEndTriggerEP20EndTriggerGameObjectRKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

void GJBaseGameLayer::toggleGlitter(bool p0) {}

float GJBaseGameLayer::timeForPos(cocos2d::CCPoint p0, int p1, int p2, bool p3, int p4) { return 0.f; }

cocos2d::CCPoint GJBaseGameLayer::posForTime(float p0) { return { 0.f, 0.f }; }

void GJBaseGameLayer::resetSPTriggered() {}

auto GJBaseGameLayer::createCustomParticle(gd::string const& p0, cocos2d::ParticleStruct const& p1, int p2, bool p3) -> decltype(createCustomParticle(p0, p1, p2, p3)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&, cocos2d::ParticleStruct const&, int, bool>::func(&GJBaseGameLayer::createCustomParticle), this);
	using FunctionType = decltype(createCustomParticle(p0, p1, p2, p3))(*)(GJBaseGameLayer*, gd::string const&, cocos2d::ParticleStruct const&, int, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer20createCustomParticleERKSsRKN7cocos2d14ParticleStructEib")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2, p3);
}

auto GJBaseGameLayer::claimCustomParticle(gd::string const& p0, cocos2d::ParticleStruct const& p1, int p2, int p3, int p4, bool p5) -> decltype(claimCustomParticle(p0, p1, p2, p3, p4, p5)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&, cocos2d::ParticleStruct const&, int, int, int, bool>::func(&GJBaseGameLayer::claimCustomParticle), this);
	using FunctionType = decltype(claimCustomParticle(p0, p1, p2, p3, p4, p5))(*)(GJBaseGameLayer*, gd::string const&, cocos2d::ParticleStruct const&, int, int, int, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer19claimCustomParticleERKSsRKN7cocos2d14ParticleStructEiiib")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2, p3, p4, p5);
}

auto GJBaseGameLayer::unclaimCustomParticle(gd::string const& p0, cocos2d::CCParticleSystemQuad* p1) -> decltype(unclaimCustomParticle(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&, cocos2d::CCParticleSystemQuad*>::func(&GJBaseGameLayer::unclaimCustomParticle), this);
	using FunctionType = decltype(unclaimCustomParticle(p0, p1))(*)(GJBaseGameLayer*, gd::string const&, cocos2d::CCParticleSystemQuad*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer21unclaimCustomParticleERKSsPN7cocos2d20CCParticleSystemQuadE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto GJBaseGameLayer::activateEventTrigger(EventLinkTrigger* p0, gd::vector<int> const& p1) -> decltype(activateEventTrigger(p0, p1)) {
	using FunctionType = decltype(activateEventTrigger(p0, p1))(*)(GJBaseGameLayer*, EventLinkTrigger*, gd::vector<int> const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer20activateEventTriggerEP16EventLinkTriggerRKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJBaseGameLayer::activateItemCompareTrigger(ItemTriggerGameObject* p0, gd::vector<int> const& p1) -> decltype(activateItemCompareTrigger(p0, p1)) {
	using FunctionType = decltype(activateItemCompareTrigger(p0, p1))(*)(GJBaseGameLayer*, ItemTriggerGameObject*, gd::vector<int> const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer26activateItemCompareTriggerEP21ItemTriggerGameObjectRKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJBaseGameLayer::activateTimerTrigger(TimerTriggerGameObject* p0, gd::vector<int> const& p1) -> decltype(activateTimerTrigger(p0, p1)) {
	using FunctionType = decltype(activateTimerTrigger(p0, p1))(*)(GJBaseGameLayer*, TimerTriggerGameObject*, gd::vector<int> const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer20activateTimerTriggerEP22TimerTriggerGameObjectRKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJBaseGameLayer::addAreaEffect(EnterEffectObject* p0, gd::vector<EnterEffectInstance>* p1, GJAreaActionType p2) -> decltype(addAreaEffect(p0, p1, p2)) {
	using FunctionType = decltype(addAreaEffect(p0, p1, p2))(*)(GJBaseGameLayer*, EnterEffectObject*, gd::vector<EnterEffectInstance>*, GJAreaActionType);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer13addAreaEffectEP17EnterEffectObjectPSt6vectorI19EnterEffectInstanceSaIS3_EE16GJAreaActionType")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GJBaseGameLayer::addRemapTargets(gd::set<int>& p0) -> decltype(addRemapTargets(p0)) {
	using FunctionType = decltype(addRemapTargets(p0))(*)(GJBaseGameLayer*, gd::set<int>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer15addRemapTargetsERSt3setIiSt4lessIiESaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJBaseGameLayer::applyRemap(EffectGameObject* p0, gd::vector<int> const& p1, gd::unordered_map<int, int>& p2) -> decltype(applyRemap(p0, p1, p2)) {
	using FunctionType = decltype(applyRemap(p0, p1, p2))(*)(GJBaseGameLayer*, EffectGameObject*, gd::vector<int> const&, gd::unordered_map<int, int>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer10applyRemapEP16EffectGameObjectRKSt6vectorIiSaIiEERSt13unordered_mapIiiSt4hashIiESt8equal_toIiESaISt4pairIKiiEEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GJBaseGameLayer::canProcessSFX(SFXTriggerState& p0, gd::unordered_map<int, int>& p1, gd::unordered_map<int, float>& p2, gd::vector<SFXTriggerState>& p3) -> decltype(canProcessSFX(p0, p1, p2, p3)) {
	using FunctionType = decltype(canProcessSFX(p0, p1, p2, p3))(*)(GJBaseGameLayer*, SFXTriggerState&, gd::unordered_map<int, int>&, gd::unordered_map<int, float>&, gd::vector<SFXTriggerState>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer13canProcessSFXER15SFXTriggerStateRSt13unordered_mapIiiSt4hashIiESt8equal_toIiESaISt4pairIKiiEEERS2_IifS4_S6_SaIS7_IS8_fEEERSt6vectorIS0_SaIS0_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto GJBaseGameLayer::checkCollisionBlocks(EffectGameObject* p0, gd::vector<EffectGameObject*>* p1, int p2) -> decltype(checkCollisionBlocks(p0, p1, p2)) {
	using FunctionType = decltype(checkCollisionBlocks(p0, p1, p2))(*)(GJBaseGameLayer*, EffectGameObject*, gd::vector<EffectGameObject*>*, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer20checkCollisionBlocksEP16EffectGameObjectPSt6vectorIS1_SaIS1_EEi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GJBaseGameLayer::claimParticle(gd::string p0, int p1) -> decltype(claimParticle(p0, p1)) {
	using FunctionType = decltype(claimParticle(p0, p1))(*)(GJBaseGameLayer*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer13claimParticleESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJBaseGameLayer::collisionCheckObjects(PlayerObject* p0, gd::vector<GameObject*>* p1, int p2, float p3) -> decltype(collisionCheckObjects(p0, p1, p2, p3)) {
	using FunctionType = decltype(collisionCheckObjects(p0, p1, p2, p3))(*)(GJBaseGameLayer*, PlayerObject*, gd::vector<GameObject*>*, int, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer21collisionCheckObjectsEP12PlayerObjectPSt6vectorIP10GameObjectSaIS4_EEif")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto GJBaseGameLayer::controlAreaEffect(EnterEffectObject* p0, gd::vector<EnterEffectInstance>* p1, GJActionCommand p2) -> decltype(controlAreaEffect(p0, p1, p2)) {
	using FunctionType = decltype(controlAreaEffect(p0, p1, p2))(*)(GJBaseGameLayer*, EnterEffectObject*, gd::vector<EnterEffectInstance>*, GJActionCommand);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer17controlAreaEffectEP17EnterEffectObjectPSt6vectorI19EnterEffectInstanceSaIS3_EE15GJActionCommand")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GJBaseGameLayer::controlDynamicCommand(EffectGameObject* p0, int p1, gd::vector<DynamicObjectAction>& p2, GJActionCommand p3) -> decltype(controlDynamicCommand(p0, p1, p2, p3)) {
	using FunctionType = decltype(controlDynamicCommand(p0, p1, p2, p3))(*)(GJBaseGameLayer*, EffectGameObject*, int, gd::vector<DynamicObjectAction>&, GJActionCommand);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer21controlDynamicCommandEP16EffectGameObjectiRSt6vectorI19DynamicObjectActionSaIS3_EE15GJActionCommand")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto GJBaseGameLayer::getParticleKey2(gd::string p0) -> decltype(getParticleKey2(p0)) {
	using FunctionType = decltype(getParticleKey2(p0))(*)(GJBaseGameLayer*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer15getParticleKey2ESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

bool GJBaseGameLayer::isFlipping() {
        return m_gameState.m_levelFlipping != 0.f && m_gameState.m_levelFlipping != 1.f;
    }

auto GJBaseGameLayer::loadGroupParentsFromString(GameObject* p0, gd::string p1) -> decltype(loadGroupParentsFromString(p0, p1)) {
	using FunctionType = decltype(loadGroupParentsFromString(p0, p1))(*)(GJBaseGameLayer*, GameObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer26loadGroupParentsFromStringEP10GameObjectSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJBaseGameLayer::playKeyframeAnimation(KeyframeAnimTriggerObject* p0, gd::vector<int> const& p1) -> decltype(playKeyframeAnimation(p0, p1)) {
	using FunctionType = decltype(playKeyframeAnimation(p0, p1))(*)(GJBaseGameLayer*, KeyframeAnimTriggerObject*, gd::vector<int> const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer21playKeyframeAnimationEP25KeyframeAnimTriggerObjectRKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJBaseGameLayer::processAreaEffects(gd::vector<EnterEffectInstance>* p0, GJAreaActionType p1, float p2, bool p3) -> decltype(processAreaEffects(p0, p1, p2, p3)) {
	using FunctionType = decltype(processAreaEffects(p0, p1, p2, p3))(*)(GJBaseGameLayer*, gd::vector<EnterEffectInstance>*, GJAreaActionType, float, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer18processAreaEffectsEPSt6vectorI19EnterEffectInstanceSaIS1_EE16GJAreaActionTypefb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto GJBaseGameLayer::processSongState(int p0, float p1, float p2, int p3, float p4, float p5, gd::vector<SongTriggerState>* p6, SongTriggerGameObject* p7) -> decltype(processSongState(p0, p1, p2, p3, p4, p5, p6, p7)) {
	using FunctionType = decltype(processSongState(p0, p1, p2, p3, p4, p5, p6, p7))(*)(GJBaseGameLayer*, int, float, float, int, float, float, gd::vector<SongTriggerState>*, SongTriggerGameObject*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer16processSongStateEiffiffPSt6vectorI16SongTriggerStateSaIS1_EEP21SongTriggerGameObject")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7);
}

auto GJBaseGameLayer::registerSpawnRemap(gd::vector<ChanceObject>& p0) -> decltype(registerSpawnRemap(p0)) {
	using FunctionType = decltype(registerSpawnRemap(p0))(*)(GJBaseGameLayer*, gd::vector<ChanceObject>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer18registerSpawnRemapERSt6vectorI12ChanceObjectSaIS1_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJBaseGameLayer::restoreRemap(EffectGameObject* p0, gd::unordered_map<int, int>& p1) -> decltype(restoreRemap(p0, p1)) {
	using FunctionType = decltype(restoreRemap(p0, p1))(*)(GJBaseGameLayer*, EffectGameObject*, gd::unordered_map<int, int>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer12restoreRemapEP16EffectGameObjectRSt13unordered_mapIiiSt4hashIiESt8equal_toIiESaISt4pairIKiiEEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJBaseGameLayer::setupReplay(gd::string p0) -> decltype(setupReplay(p0)) {
	using FunctionType = decltype(setupReplay(p0))(*)(GJBaseGameLayer*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer11setupReplayESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJBaseGameLayer::spawnGroupTriggered(int groupID, float p1, bool p2, gd::vector<int> const& p3, int p4, int p5) -> decltype(spawnGroupTriggered(groupID, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(spawnGroupTriggered(groupID, p1, p2, p3, p4, p5))(*)(GJBaseGameLayer*, int, float, bool, gd::vector<int> const&, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer19spawnGroupTriggeredEifbRKSt6vectorIiSaIiEEii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, groupID, p1, p2, p3, p4, p5);
}

auto GJBaseGameLayer::spawnObjectsInOrder(cocos2d::CCArray* p0, double p1, gd::vector<int> const& p2, int p3, int p4) -> decltype(spawnObjectsInOrder(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(spawnObjectsInOrder(p0, p1, p2, p3, p4))(*)(GJBaseGameLayer*, cocos2d::CCArray*, double, gd::vector<int> const&, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer19spawnObjectsInOrderEPN7cocos2d7CCArrayEdRKSt6vectorIiSaIiEEii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto GJBaseGameLayer::testInstantCountTrigger(int p0, int p1, int p2, bool p3, int p4, gd::vector<int> const& p5, int p6, int p7) -> decltype(testInstantCountTrigger(p0, p1, p2, p3, p4, p5, p6, p7)) {
	using FunctionType = decltype(testInstantCountTrigger(p0, p1, p2, p3, p4, p5, p6, p7))(*)(GJBaseGameLayer*, int, int, int, bool, int, gd::vector<int> const&, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer23testInstantCountTriggerEiiibiRKSt6vectorIiSaIiEEii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7);
}

auto GJBaseGameLayer::updateLayerCapacity(gd::string p0) -> decltype(updateLayerCapacity(p0)) {
	using FunctionType = decltype(updateLayerCapacity(p0))(*)(GJBaseGameLayer*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJBaseGameLayer19updateLayerCapacityESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJBigSprite::loadSpriteAsync(gd::string p0, int p1) -> decltype(loadSpriteAsync(p0, p1)) {
	using FunctionType = decltype(loadSpriteAsync(p0, p1))(*)(GJBigSprite*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GJBigSprite15loadSpriteAsyncESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJBigSprite::unloadSprite(gd::string p0, int p1) -> decltype(unloadSprite(p0, p1)) {
	using FunctionType = decltype(unloadSprite(p0, p1))(*)(GJBigSprite*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GJBigSprite12unloadSpriteESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJEffectManager::createKeyframeCommand(int p0, cocos2d::CCArray* p1, GameObject* p2, int p3, int p4, bool p5, float p6, float p7, float p8, float p9, float p10, float p11, gd::vector<int> const& p12) -> decltype(createKeyframeCommand(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12)) {
	using FunctionType = decltype(createKeyframeCommand(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12))(*)(GJEffectManager*, int, cocos2d::CCArray*, GameObject*, int, int, bool, float, float, float, float, float, float, gd::vector<int> const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJEffectManager21createKeyframeCommandEiPN7cocos2d7CCArrayEP10GameObjectiibffffffRKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
}

auto GJEffectManager::getLoadedMoveOffset(gd::unordered_map<int, std::pair<double, double>>& p0) -> decltype(getLoadedMoveOffset(p0)) {
	using FunctionType = decltype(getLoadedMoveOffset(p0))(*)(GJEffectManager*, gd::unordered_map<int, std::pair<double, double>>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJEffectManager19getLoadedMoveOffsetERSt13unordered_mapIiSt4pairIddESt4hashIiESt8equal_toIiESaIS1_IKiS2_EEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJEffectManager::registerCollisionTrigger(int p0, int p1, int p2, bool p3, bool p4, gd::vector<int> const& p5, int p6, int p7) -> decltype(registerCollisionTrigger(p0, p1, p2, p3, p4, p5, p6, p7)) {
	using FunctionType = decltype(registerCollisionTrigger(p0, p1, p2, p3, p4, p5, p6, p7))(*)(GJEffectManager*, int, int, int, bool, bool, gd::vector<int> const&, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJEffectManager24registerCollisionTriggerEiiibbRKSt6vectorIiSaIiEEii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7);
}

auto GJEffectManager::runCountTrigger(int p0, int p1, bool p2, int p3, bool p4, gd::vector<int> const& p5, int p6, int p7) -> decltype(runCountTrigger(p0, p1, p2, p3, p4, p5, p6, p7)) {
	using FunctionType = decltype(runCountTrigger(p0, p1, p2, p3, p4, p5, p6, p7))(*)(GJEffectManager*, int, int, bool, int, bool, gd::vector<int> const&, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJEffectManager15runCountTriggerEiibibRKSt6vectorIiSaIiEEii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7);
}

auto GJEffectManager::runDeathTrigger(int p0, bool p1, gd::vector<int> const& p2, int p3, int p4) -> decltype(runDeathTrigger(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(runDeathTrigger(p0, p1, p2, p3, p4))(*)(GJEffectManager*, int, bool, gd::vector<int> const&, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJEffectManager15runDeathTriggerEibRKSt6vectorIiSaIiEEii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto GJEffectManager::runTimerTrigger(int p0, double p1, bool p2, int p3, gd::vector<int> const& p4, int p5, int p6) -> decltype(runTimerTrigger(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(runTimerTrigger(p0, p1, p2, p3, p4, p5, p6))(*)(GJEffectManager*, int, double, bool, int, gd::vector<int> const&, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJEffectManager15runTimerTriggerEidbiRKSt6vectorIiSaIiEEii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6);
}

auto GJEffectManager::runTouchTriggerCommand(int p0, bool p1, TouchTriggerType p2, TouchTriggerControl p3, bool p4, gd::vector<int> const& p5, int p6, int p7) -> decltype(runTouchTriggerCommand(p0, p1, p2, p3, p4, p5, p6, p7)) {
	using FunctionType = decltype(runTouchTriggerCommand(p0, p1, p2, p3, p4, p5, p6, p7))(*)(GJEffectManager*, int, bool, TouchTriggerType, TouchTriggerControl, bool, gd::vector<int> const&, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJEffectManager22runTouchTriggerCommandEib16TouchTriggerType19TouchTriggerControlbRKSt6vectorIiSaIiEEii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7);
}

auto GJEffectManager::setupFromString(gd::string p0) -> decltype(setupFromString(p0)) {
	using FunctionType = decltype(setupFromString(p0))(*)(GJEffectManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJEffectManager15setupFromStringESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJEffectManager::spawnGroup(int p0, float p1, bool p2, gd::vector<int> const& p3, int p4, int p5) -> decltype(spawnGroup(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(spawnGroup(p0, p1, p2, p3, p4, p5))(*)(GJEffectManager*, int, float, bool, gd::vector<int> const&, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJEffectManager10spawnGroupEifbRKSt6vectorIiSaIiEEii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto GJEffectManager::spawnObject(GameObject* p0, float p1, gd::vector<int> const& p2, int p3, int p4) -> decltype(spawnObject(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(spawnObject(p0, p1, p2, p3, p4))(*)(GJEffectManager*, GameObject*, float, gd::vector<int> const&, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJEffectManager11spawnObjectEP10GameObjectfRKSt6vectorIiSaIiEEii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto GJEffectManager::startTimer(int p0, double p1, double p2, bool p3, bool p4, bool p5, float p6, bool p7, int p8, gd::vector<int> const& p9, int p10, int p11) -> decltype(startTimer(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11)) {
	using FunctionType = decltype(startTimer(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11))(*)(GJEffectManager*, int, double, double, bool, bool, bool, float, bool, int, gd::vector<int> const&, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJEffectManager10startTimerEiddbbbfbiRKSt6vectorIiSaIiEEii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
}

void GJGroundLayer::draw() {}

auto GJGameLevel::parseSettingsString(gd::string p0) -> decltype(parseSettingsString(p0)) {
	using FunctionType = decltype(parseSettingsString(p0))(*)(GJGameLevel*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GJGameLevel19parseSettingsStringESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJGameLevel::scoreStringToVector(gd::string& p0, gd::vector<int>& p1) -> decltype(scoreStringToVector(p0, p1)) {
	using FunctionType = decltype(scoreStringToVector(p0, p1))(*)(GJGameLevel*, gd::string&, gd::vector<int>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GJGameLevel19scoreStringToVectorERSsRSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJGameLevel::scoreVectorToString(gd::vector<int>& p0, int p1) -> decltype(scoreVectorToString(p0, p1)) {
	using FunctionType = decltype(scoreVectorToString(p0, p1))(*)(GJGameLevel*, gd::vector<int>&, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GJGameLevel19scoreVectorToStringERSt6vectorIiSaIiEEi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

GJGarageLayer::GJGarageLayer() : GJGarageLayer(geode::CutoffConstructor, sizeof(GJGarageLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	GJGarageLayer::~GJGarageLayer();
	using FunctionType = void(*)(GJGarageLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13GJGarageLayerC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

auto GJHttpResult::create(bool p0, gd::string p1, gd::string p2, GJHttpType p3) -> decltype(create(p0, p1, p2, p3)) {
	using FunctionType = decltype(create(p0, p1, p2, p3))(*)(bool, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12GJHttpResult6createEbSsSs10GJHttpType")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto GJHttpResult::init(bool p0, gd::string p1, gd::string p2, GJHttpType p3) -> decltype(init(p0, p1, p2, p3)) {
	using FunctionType = decltype(init(p0, p1, p2, p3))(*)(GJHttpResult*, bool, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12GJHttpResult4initEbSsSs10GJHttpType")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

GJItemIcon::GJItemIcon() {}

auto GJLevelList::parseListLevels(gd::string p0) -> decltype(parseListLevels(p0)) {
	using FunctionType = decltype(parseListLevels(p0))(*)(GJLevelList*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GJLevelList15parseListLevelsESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

GJLevelScoreCell::GJLevelScoreCell(char const* p0, float p1, float p2) : GJLevelScoreCell(geode::CutoffConstructor, sizeof(GJLevelScoreCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	GJLevelScoreCell::~GJLevelScoreCell();
	using FunctionType = void(*)(GJLevelScoreCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16GJLevelScoreCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

GJLocalLevelScoreCell::GJLocalLevelScoreCell(char const* p0, float p1, float p2) : GJLocalLevelScoreCell(geode::CutoffConstructor, sizeof(GJLocalLevelScoreCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	GJLocalLevelScoreCell::~GJLocalLevelScoreCell();
	using FunctionType = void(*)(GJLocalLevelScoreCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN21GJLocalLevelScoreCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

GJMapPack::GJMapPack() {
        m_levels = nullptr;
        m_packID = 0;
        m_difficulty = GJDifficulty::Auto;
        m_stars = 0;
        m_coins = 0;
        m_packName = "";
        m_levelStrings = "";
        m_MId = 0;
        m_isGauntlet = false;
    }

auto GJMapPack::parsePackColors(gd::string p0, gd::string p1) -> decltype(parsePackColors(p0, p1)) {
	using FunctionType = decltype(parsePackColors(p0, p1))(*)(GJMapPack*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN9GJMapPack15parsePackColorsESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJMapPack::parsePackLevels(gd::string p0) -> decltype(parsePackLevels(p0)) {
	using FunctionType = decltype(parsePackLevels(p0))(*)(GJMapPack*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN9GJMapPack15parsePackLevelsESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

GJMessageCell::GJMessageCell(char const* p0, float p1, float p2) : GJMessageCell(geode::CutoffConstructor, sizeof(GJMessageCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	GJMessageCell::~GJMessageCell();
	using FunctionType = void(*)(GJMessageCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13GJMessageCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

void GJMGLayer::draw() {}

auto GJMultiplayerManager::addComment(gd::string p0, int p1) -> decltype(addComment(p0, p1)) {
	using FunctionType = decltype(addComment(p0, p1))(*)(GJMultiplayerManager*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20GJMultiplayerManager10addCommentESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJMultiplayerManager::createAndAddComment(gd::string p0, int p1) -> decltype(createAndAddComment(p0, p1)) {
	using FunctionType = decltype(createAndAddComment(p0, p1))(*)(GJMultiplayerManager*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20GJMultiplayerManager19createAndAddCommentESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJMultiplayerManager::handleIt(bool p0, gd::string p1, gd::string p2, GJHttpType p3) -> decltype(handleIt(p0, p1, p2, p3)) {
	using FunctionType = decltype(handleIt(p0, p1, p2, p3))(*)(GJMultiplayerManager*, bool, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20GJMultiplayerManager8handleItEbSsSs10GJHttpType")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto GJMultiplayerManager::handleItDelayed(bool p0, gd::string p1, gd::string p2, GJHttpType p3) -> decltype(handleItDelayed(p0, p1, p2, p3)) {
	using FunctionType = decltype(handleItDelayed(p0, p1, p2, p3))(*)(GJMultiplayerManager*, bool, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20GJMultiplayerManager15handleItDelayedEbSsSs10GJHttpType")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto GJMultiplayerManager::onExitLobbyCompleted(gd::string p0, gd::string p1) -> decltype(onExitLobbyCompleted(p0, p1)) {
	using FunctionType = decltype(onExitLobbyCompleted(p0, p1))(*)(GJMultiplayerManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20GJMultiplayerManager20onExitLobbyCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJMultiplayerManager::onJoinLobbyCompleted(gd::string p0, gd::string p1) -> decltype(onJoinLobbyCompleted(p0, p1)) {
	using FunctionType = decltype(onJoinLobbyCompleted(p0, p1))(*)(GJMultiplayerManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20GJMultiplayerManager20onJoinLobbyCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJMultiplayerManager::onUploadCommentCompleted(gd::string p0, gd::string p1) -> decltype(onUploadCommentCompleted(p0, p1)) {
	using FunctionType = decltype(onUploadCommentCompleted(p0, p1))(*)(GJMultiplayerManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20GJMultiplayerManager24onUploadCommentCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJMultiplayerManager::ProcessHttpRequest(gd::string p0, gd::string p1, gd::string p2, GJHttpType p3) -> decltype(ProcessHttpRequest(p0, p1, p2, p3)) {
	using FunctionType = decltype(ProcessHttpRequest(p0, p1, p2, p3))(*)(GJMultiplayerManager*, gd::string, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20GJMultiplayerManager18ProcessHttpRequestESsSsSs10GJHttpType")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto GJMultiplayerManager::uploadComment(gd::string p0, int p1) -> decltype(uploadComment(p0, p1)) {
	using FunctionType = decltype(uploadComment(p0, p1))(*)(GJMultiplayerManager*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20GJMultiplayerManager13uploadCommentESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

void GJOnlineRewardDelegate::onlineRewardStatusFinished(gd::string p0) {}

void GJOnlineRewardDelegate::onlineRewardStatusFailed() {}

void GJPathRewardPopup::keyBackClicked() {}

auto GJPromoPopup::create(gd::string p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12GJPromoPopup6createESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto GJPromoPopup::init(gd::string p0) -> decltype(init(p0)) {
	using FunctionType = decltype(init(p0))(*)(GJPromoPopup*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12GJPromoPopup4initESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

GJRequestCell::GJRequestCell(char const* p0, float p1, float p2) : GJRequestCell(geode::CutoffConstructor, sizeof(GJRequestCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	GJRequestCell::~GJRequestCell();
	using FunctionType = void(*)(GJRequestCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13GJRequestCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GJRewardItem::create(int chestID, int timeRemaining, gd::string p2) -> decltype(create(chestID, timeRemaining, p2)) {
	using FunctionType = decltype(create(chestID, timeRemaining, p2))(*)(int, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12GJRewardItem6createEiiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(chestID, timeRemaining, p2);
}

auto GJRewardItem::init(int chestID, int timeRemaining, gd::string p2) -> decltype(init(chestID, timeRemaining, p2)) {
	using FunctionType = decltype(init(chestID, timeRemaining, p2))(*)(GJRewardItem*, int, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12GJRewardItem4initEiiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, chestID, timeRemaining, p2);
}

auto GJRobotSprite::init(int p0, gd::string p1) -> decltype(init(p0, p1)) {
	using FunctionType = decltype(init(p0, p1))(*)(GJRobotSprite*, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13GJRobotSprite4initEiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

GJRotationControl::GJRotationControl() {
        m_cursorDifference = cocos2d::CCPointMake(0.0f, 0.0f);
        m_controlPosition = cocos2d::CCPointMake(0.0f, 0.0f);
        m_controlSprite = nullptr;
        m_startingRotation = 0.0f;
        m_currentRotation = 0.0f;
        m_touchID = -1;
        m_delegate = nullptr;
    }

GJScaleControl::GJScaleControl() {
        m_sliderX = nullptr;
        m_sliderY = nullptr;
        m_sliderXY = nullptr;
        m_touchID = -1;
        m_valueX = 0.0f;
        m_valueY = 0.0f;
        m_unkSize4 = 0;
        m_changedValueX = 0.0f;
        m_changedValueY = 0.0f;
        m_scale1Lock = false;
        m_scaleButtonType = 0;
        m_delegate = nullptr;
        m_upperBound = 2.0f;
        m_lowerBound = 0.5f;
        m_senderTag = 0;
        m_scaleLockButton = nullptr;
        m_scaleLocked = false;
    }

auto GJScaleControl::loadValues(GameObject* p0, cocos2d::CCArray* p1, gd::unordered_map<int, GameObjectEditorState>& p2) -> decltype(loadValues(p0, p1, p2)) {
	using FunctionType = decltype(loadValues(p0, p1, p2))(*)(GJScaleControl*, GameObject*, cocos2d::CCArray*, gd::unordered_map<int, GameObjectEditorState>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14GJScaleControl10loadValuesEP10GameObjectPN7cocos2d7CCArrayERSt13unordered_mapIi21GameObjectEditorStateSt4hashIiESt8equal_toIiESaISt4pairIKiS6_EEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

GJScoreCell::GJScoreCell(char const* p0, float p1, float p2) : GJScoreCell(geode::CutoffConstructor, sizeof(GJScoreCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	GJScoreCell::~GJScoreCell();
	using FunctionType = void(*)(GJScoreCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GJScoreCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GJSearchObject::create(SearchType searchType, gd::string searchQuery, gd::string difficulty, gd::string length, int page, bool star, bool uncompleted, bool featured, int songID, bool original, bool twoPlayer, bool customSong, bool songFilter, bool noStar, bool coins, bool epic, bool legendary, bool mythic, bool onlyCompleted, int demonFilter, int folder, int searchMode) -> decltype(create(searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode)) {
	using FunctionType = decltype(create(searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode))(*)(SearchType, gd::string, gd::string, gd::string, int, bool, bool, bool, int, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, int, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14GJSearchObject6createE10SearchTypeSsSsSsibbbibbbbbbbbbbiii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode);
}

auto GJSearchObject::create(SearchType searchType, gd::string searchQuery) -> decltype(create(searchType, searchQuery)) {
	using FunctionType = decltype(create(searchType, searchQuery))(*)(SearchType, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14GJSearchObject6createE10SearchTypeSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(searchType, searchQuery);
}

auto GJSearchObject::getSearchKey(SearchType searchType, gd::string searchQuery, gd::string difficulty, gd::string length, int page, bool star, bool uncompleted, bool featured, int songID, bool original, bool twoPlayer, bool customSong, bool songFilter, bool noStar, bool coins, bool epic, bool legendary, bool mythic, bool onlyCompleted, int demonFilter, int folder, int searchMode) -> decltype(getSearchKey(searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode)) {
	using FunctionType = decltype(getSearchKey(searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode))(*)(GJSearchObject*, SearchType, gd::string, gd::string, gd::string, int, bool, bool, bool, int, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, int, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14GJSearchObject12getSearchKeyE10SearchTypeSsSsSsibbbibbbbbbbbbbiii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode);
}

auto GJSearchObject::init(SearchType searchType, gd::string searchQuery, gd::string difficulty, gd::string length, int page, bool star, bool uncompleted, bool featured, int songID, bool original, bool twoPlayer, bool customSong, bool songFilter, bool noStar, bool coins, bool epic, bool legendary, bool mythic, bool onlyCompleted, int demonFilter, int folder, int searchMode) -> decltype(init(searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode)) {
	using FunctionType = decltype(init(searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode))(*)(GJSearchObject*, SearchType, gd::string, gd::string, gd::string, int, bool, bool, bool, int, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, int, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14GJSearchObject4initE10SearchTypeSsSsSsibbbibbbbbbbbbbiii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, searchType, searchQuery, difficulty, length, page, star, uncompleted, featured, songID, original, twoPlayer, customSong, songFilter, noStar, coins, epic, legendary, mythic, onlyCompleted, demonFilter, folder, searchMode);
}

GJShopLayer::GJShopLayer() {
        m_closing = false;
        m_currencyLabel = nullptr;
        m_shopItems = nullptr;
        m_type = ShopType::Normal;
        m_sheetName = "";
        m_unkNode1 = nullptr;
        m_unkNode2 = nullptr;
        m_videoPlaying = false;
        m_unkBool = false;
        m_shopKeeper = nullptr;
        m_zolgurothDialogIndex = 0;
        m_affordDialogIndex = 0;
    }

void GJShopLayer::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

void GJShopLayer::ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

auto GJSmartBlockPreview::create(gd::string p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19GJSmartBlockPreview6createESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto GJSmartBlockPreview::addPreview(gd::string p0, gd::string p1, LevelEditorLayer* p2) -> decltype(addPreview(p0, p1, p2)) {
	using FunctionType = decltype(addPreview(p0, p1, p2))(*)(GJSmartBlockPreview*, gd::string, gd::string, LevelEditorLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19GJSmartBlockPreview10addPreviewESsSsP16LevelEditorLayer")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GJSmartBlockPreview::addTemplateGuide(gd::string p0, int p1) -> decltype(addTemplateGuide(p0, p1)) {
	using FunctionType = decltype(addTemplateGuide(p0, p1))(*)(GJSmartBlockPreview*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19GJSmartBlockPreview16addTemplateGuideESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJSmartBlockPreview::init(gd::string p0) -> decltype(init(p0)) {
	using FunctionType = decltype(init(p0))(*)(GJSmartBlockPreview*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19GJSmartBlockPreview4initESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJSmartTemplate::flipKey(gd::string p0, bool p1, bool p2) -> decltype(flipKey(p0, p1, p2)) {
	using FunctionType = decltype(flipKey(p0, p1, p2))(*)(GJSmartTemplate*, gd::string, bool, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJSmartTemplate7flipKeyESsbb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GJSmartTemplate::getNoCornerKey(gd::string p0) -> decltype(getNoCornerKey(p0)) {
	using FunctionType = decltype(getNoCornerKey(p0))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJSmartTemplate14getNoCornerKeyESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJSmartTemplate::getPrefab(gd::string p0, bool p1, bool p2) -> decltype(getPrefab(p0, p1, p2)) {
	using FunctionType = decltype(getPrefab(p0, p1, p2))(*)(GJSmartTemplate*, gd::string, bool, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJSmartTemplate9getPrefabESsbb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GJSmartTemplate::getPrefabs(gd::string p0) -> decltype(getPrefabs(p0)) {
	using FunctionType = decltype(getPrefabs(p0))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJSmartTemplate10getPrefabsESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJSmartTemplate::getPrefabWithID(gd::string p0, int p1) -> decltype(getPrefabWithID(p0, p1)) {
	using FunctionType = decltype(getPrefabWithID(p0, p1))(*)(GJSmartTemplate*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJSmartTemplate15getPrefabWithIDESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJSmartTemplate::getRandomPrefab(gd::string p0) -> decltype(getRandomPrefab(p0)) {
	using FunctionType = decltype(getRandomPrefab(p0))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJSmartTemplate15getRandomPrefabESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJSmartTemplate::getSimplifiedKey(gd::string p0) -> decltype(getSimplifiedKey(p0)) {
	using FunctionType = decltype(getSimplifiedKey(p0))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJSmartTemplate16getSimplifiedKeyESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJSmartTemplate::getTemplateState(gd::vector<SmartPrefabResult>& p0) -> decltype(getTemplateState(p0)) {
	using FunctionType = decltype(getTemplateState(p0))(*)(GJSmartTemplate*, gd::vector<SmartPrefabResult>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJSmartTemplate16getTemplateStateERSt6vectorI17SmartPrefabResultSaIS1_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJSmartTemplate::getTotalChanceForPrefab(gd::string p0) -> decltype(getTotalChanceForPrefab(p0)) {
	using FunctionType = decltype(getTotalChanceForPrefab(p0))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJSmartTemplate23getTotalChanceForPrefabESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJSmartTemplate::getVerySimplifiedKey(gd::string p0) -> decltype(getVerySimplifiedKey(p0)) {
	using FunctionType = decltype(getVerySimplifiedKey(p0))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJSmartTemplate20getVerySimplifiedKeyESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJSmartTemplate::isUnrequired(gd::string p0) -> decltype(isUnrequired(p0)) {
	using FunctionType = decltype(isUnrequired(p0))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJSmartTemplate12isUnrequiredESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJSmartTemplate::removePrefab(gd::string p0, int p1) -> decltype(removePrefab(p0, p1)) {
	using FunctionType = decltype(removePrefab(p0, p1))(*)(GJSmartTemplate*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJSmartTemplate12removePrefabESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJSmartTemplate::rotateKey(gd::string p0, int p1) -> decltype(rotateKey(p0, p1)) {
	using FunctionType = decltype(rotateKey(p0, p1))(*)(GJSmartTemplate*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJSmartTemplate9rotateKeyESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJSmartTemplate::savePrefab(gd::string p0, gd::string p1) -> decltype(savePrefab(p0, p1)) {
	using FunctionType = decltype(savePrefab(p0, p1))(*)(GJSmartTemplate*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJSmartTemplate10savePrefabESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto GJSmartTemplate::saveRemap(gd::string p0) -> decltype(saveRemap(p0)) {
	using FunctionType = decltype(saveRemap(p0))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJSmartTemplate9saveRemapESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJSmartTemplate::saveRemapToDict(gd::string p0, gd::string p1, cocos2d::CCDictionary* p2) -> decltype(saveRemapToDict(p0, p1, p2)) {
	using FunctionType = decltype(saveRemapToDict(p0, p1, p2))(*)(GJSmartTemplate*, gd::string, gd::string, cocos2d::CCDictionary*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJSmartTemplate15saveRemapToDictESsSsPN7cocos2d12CCDictionaryE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto GJSmartTemplate::scanForPrefab(gd::string p0) -> decltype(scanForPrefab(p0)) {
	using FunctionType = decltype(scanForPrefab(p0))(*)(GJSmartTemplate*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15GJSmartTemplate13scanForPrefabESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

GJStoreItem::GJStoreItem() {
        m_index = 0;
        m_typeID = 0;
        m_unlockType = 0;
        m_price = 0;
        m_shopType = ShopType::Normal;
    }

auto GJTransformControl::loadValues(GameObject* p0, cocos2d::CCArray* p1, gd::unordered_map<int, GameObjectEditorState>& p2) -> decltype(loadValues(p0, p1, p2)) {
	using FunctionType = decltype(loadValues(p0, p1, p2))(*)(GJTransformControl*, GameObject*, cocos2d::CCArray*, gd::unordered_map<int, GameObjectEditorState>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN18GJTransformControl10loadValuesEP10GameObjectPN7cocos2d7CCArrayERSt13unordered_mapIi21GameObjectEditorStateSt4hashIiESt8equal_toIiESaISt4pairIKiS6_EEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

cocos2d::CCSprite* GJTransformControl::spriteByTag(int tag) {
        return static_cast<cocos2d::CCSprite*>(m_warpSprites->objectAtIndex(tag - 1));
    }

GJUserCell::GJUserCell(char const* p0, float p1, float p2) : GJUserCell(geode::CutoffConstructor, sizeof(GJUserCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	GJUserCell::~GJUserCell();
	using FunctionType = void(*)(GJUserCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10GJUserCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

GJUserScore::GJUserScore() : GJUserScore(geode::CutoffConstructor, sizeof(GJUserScore)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	GJUserScore::~GJUserScore();
	using FunctionType = void(*)(GJUserScore*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11GJUserScoreC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

void GJWriteMessagePopup::textInputOpened(CCTextInputNode* p0) {}

auto GJWriteMessagePopup::updateBody(gd::string p0) -> decltype(updateBody(p0)) {
	using FunctionType = decltype(updateBody(p0))(*)(GJWriteMessagePopup*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19GJWriteMessagePopup10updateBodyESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJWriteMessagePopup::updateSubject(gd::string p0) -> decltype(updateSubject(p0)) {
	using FunctionType = decltype(updateSubject(p0))(*)(GJWriteMessagePopup*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19GJWriteMessagePopup13updateSubjectESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto GJWriteMessagePopup::updateText(gd::string p0, int p1) -> decltype(updateText(p0, p1)) {
	using FunctionType = decltype(updateText(p0, p1))(*)(GJWriteMessagePopup*, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19GJWriteMessagePopup10updateTextESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

void GooglePlayDelegate::googlePlaySignedIn() {}

auto GradientTriggerObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&GradientTriggerObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(GradientTriggerObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN21GradientTriggerObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

GraphicsReloadLayer::GraphicsReloadLayer() {
        m_resolution = cocos2d::CCSize {};
    }

HSVLiveOverlay::HSVLiveOverlay() {
        m_object = nullptr;
        m_objects = nullptr;
        m_controls = nullptr;
        m_unkArray = nullptr;
        m_delegate = nullptr;
        m_activeTab = -1;
        m_widget = nullptr;
        m_unkBool1 = false;
        m_unkBool2 = false;
        m_unkBool3 = false;
    }

auto HSVWidgetPopup::create(cocos2d::ccHSVValue p0, HSVWidgetDelegate* p1, gd::string p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(cocos2d::ccHSVValue, HSVWidgetDelegate*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14HSVWidgetPopup6createEN7cocos2d10ccHSVValueEP17HSVWidgetDelegateSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto HSVWidgetPopup::init(cocos2d::ccHSVValue p0, HSVWidgetDelegate* p1, gd::string p2) -> decltype(init(p0, p1, p2)) {
	using FunctionType = decltype(init(p0, p1, p2))(*)(HSVWidgetPopup*, cocos2d::ccHSVValue, HSVWidgetDelegate*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14HSVWidgetPopup4initEN7cocos2d10ccHSVValueEP17HSVWidgetDelegateSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto InfoAlertButton::create(gd::string title, gd::string desc, float spriteScale) -> decltype(create(title, desc, spriteScale)) {
	using FunctionType = decltype(create(title, desc, spriteScale))(*)(gd::string, gd::string, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15InfoAlertButton6createESsSsf")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(title, desc, spriteScale);
}

auto InfoAlertButton::init(gd::string title, gd::string desc, float spriteScale) -> decltype(init(title, desc, spriteScale)) {
	using FunctionType = decltype(init(title, desc, spriteScale))(*)(InfoAlertButton*, gd::string, gd::string, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15InfoAlertButton4initESsSsf")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, title, desc, spriteScale);
}

void LevelCommentDelegate::loadCommentsFinished(cocos2d::CCArray* p0, char const* p1) {}

void LevelCommentDelegate::loadCommentsFailed(char const* p0) {}

void LevelCommentDelegate::updateUserScoreFinished() {}

void LevelCommentDelegate::setupPageInfo(gd::string p0, char const* p1) {}

auto InfoLayer::setupPageInfo(gd::string p0, char const* p1) -> decltype(setupPageInfo(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string, char const*>::func(&InfoLayer::setupPageInfo), this);
	using FunctionType = decltype(setupPageInfo(p0, p1))(*)(InfoLayer*, gd::string, char const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN9InfoLayer13setupPageInfoESsPKc")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

int InfoLayer::getID() {
        if(m_score) return m_score->m_userID;
        if(m_levelList) return - m_levelList->m_listID;
        if(m_level) return m_level->m_levelID;
        return 0;
    }

auto ItemTriggerGameObject::triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2) -> decltype(triggerObject(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*, int, gd::vector<int> const*>::func(&ItemTriggerGameObject::triggerObject), this);
	using FunctionType = decltype(triggerObject(p0, p1, p2))(*)(ItemTriggerGameObject*, GJBaseGameLayer*, int, gd::vector<int> const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN21ItemTriggerGameObject13triggerObjectEP15GJBaseGameLayeriPKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto ItemTriggerGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&ItemTriggerGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(ItemTriggerGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN21ItemTriggerGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto KeyframeAnimTriggerObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&KeyframeAnimTriggerObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(KeyframeAnimTriggerObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN25KeyframeAnimTriggerObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto KeyframeGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&KeyframeGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(KeyframeGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN18KeyframeGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto LabelGameObject::setupCustomSprites(gd::string p0) -> decltype(setupCustomSprites(p0)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string>::func(&LabelGameObject::setupCustomSprites), this);
	using FunctionType = decltype(setupCustomSprites(p0))(*)(LabelGameObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15LabelGameObject18setupCustomSpritesESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto LabelGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&LabelGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(LabelGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15LabelGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto LabelGameObject::createLabel(gd::string p0) -> decltype(createLabel(p0)) {
	using FunctionType = decltype(createLabel(p0))(*)(LabelGameObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15LabelGameObject11createLabelESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto LabelGameObject::queueUpdateLabel(gd::string p0) -> decltype(queueUpdateLabel(p0)) {
	using FunctionType = decltype(queueUpdateLabel(p0))(*)(LabelGameObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15LabelGameObject16queueUpdateLabelESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto LabelGameObject::updateLabel(gd::string p0) -> decltype(updateLabel(p0)) {
	using FunctionType = decltype(updateLabel(p0))(*)(LabelGameObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15LabelGameObject11updateLabelESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

void LeaderboardManagerDelegate::updateUserScoreFinished() {}

void LeaderboardManagerDelegate::updateUserScoreFailed() {}

void LeaderboardManagerDelegate::loadLeaderboardFinished(cocos2d::CCArray* p0, char const* p1) {}

void LeaderboardManagerDelegate::loadLeaderboardFailed(char const* p0) {}

void SetTextPopupDelegate::setTextPopupClosed(SetTextPopup* p0, gd::string p1) {}

auto ShareCommentDelegate::shareCommentClosed(gd::string p0, ShareCommentLayer* p1) -> decltype(shareCommentClosed(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string, ShareCommentLayer*>::func(&ShareCommentDelegate::shareCommentClosed), this);
	using FunctionType = decltype(shareCommentClosed(p0, p1))(*)(ShareCommentDelegate*, gd::string, ShareCommentLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20ShareCommentDelegate18shareCommentClosedESsP17ShareCommentLayer")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

LevelBrowserLayer::LevelBrowserLayer() {}

LevelBrowserLayer::~LevelBrowserLayer() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(LevelBrowserLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17LevelBrowserLayerD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) LevelBrowserLayer(geode::CutoffConstructor, sizeof(LevelBrowserLayer));
	CCDestructor::lock(this) = true;
}

void LevelBrowserLayer::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

void LevelBrowserLayer::ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

void LevelBrowserLayer::ccTouchCancelled(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

auto LevelBrowserLayer::setupPageInfo(gd::string p0, char const* p1) -> decltype(setupPageInfo(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string, char const*>::func(&LevelBrowserLayer::setupPageInfo), this);
	using FunctionType = decltype(setupPageInfo(p0, p1))(*)(LevelBrowserLayer*, gd::string, char const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17LevelBrowserLayer13setupPageInfoESsPKc")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto LevelBrowserLayer::shareCommentClosed(gd::string p0, ShareCommentLayer* p1) -> decltype(shareCommentClosed(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string, ShareCommentLayer*>::func(&LevelBrowserLayer::shareCommentClosed), this);
	using FunctionType = decltype(shareCommentClosed(p0, p1))(*)(LevelBrowserLayer*, gd::string, ShareCommentLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17LevelBrowserLayer18shareCommentClosedESsP17ShareCommentLayer")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto LevelBrowserLayer::setTextPopupClosed(SetTextPopup* p0, gd::string p1) -> decltype(setTextPopupClosed(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<SetTextPopup*, gd::string>::func(&LevelBrowserLayer::setTextPopupClosed), this);
	using FunctionType = decltype(setTextPopupClosed(p0, p1))(*)(LevelBrowserLayer*, SetTextPopup*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17LevelBrowserLayer18setTextPopupClosedEP12SetTextPopupSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto LevelBrowserLayer::getItemsMatchingSearch(cocos2d::CCArray* p0, gd::string p1, GJSearchObject* p2) -> decltype(getItemsMatchingSearch(p0, p1, p2)) {
	using FunctionType = decltype(getItemsMatchingSearch(p0, p1, p2))(*)(LevelBrowserLayer*, cocos2d::CCArray*, gd::string, GJSearchObject*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17LevelBrowserLayer22getItemsMatchingSearchEPN7cocos2d7CCArrayESsP14GJSearchObject")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

void LevelBrowserLayer::reloadAllObjects() {
        static_cast<CustomListView*>(m_list->m_listView)->reloadAll();
    }

LevelCell::LevelCell(char const* p0, float p1, float p2) : LevelCell(geode::CutoffConstructor, sizeof(LevelCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	LevelCell::~LevelCell();
	using FunctionType = void(*)(LevelCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN9LevelCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

void LevelDeleteDelegate::levelDeleteFinished(int p0) {}

void LevelDeleteDelegate::levelDeleteFailed(int p0) {}

void LevelSettingsDelegate::levelSettingsUpdated() {}

LevelEditorLayer::LevelEditorLayer() : LevelEditorLayer(geode::CutoffConstructor, sizeof(LevelEditorLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	LevelEditorLayer::~LevelEditorLayer();
	using FunctionType = void(*)(LevelEditorLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16LevelEditorLayerC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

LevelEditorLayer* LevelEditorLayer::get() {
        return GameManager::sharedState()->m_levelEditorLayer;
    }

auto LevelEditorLayer::claimCustomParticle(gd::string const& p0, cocos2d::ParticleStruct const& p1, int p2, int p3, int p4, bool p5) -> decltype(claimCustomParticle(p0, p1, p2, p3, p4, p5)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&, cocos2d::ParticleStruct const&, int, int, int, bool>::func(&LevelEditorLayer::claimCustomParticle), this);
	using FunctionType = decltype(claimCustomParticle(p0, p1, p2, p3, p4, p5))(*)(LevelEditorLayer*, gd::string const&, cocos2d::ParticleStruct const&, int, int, int, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16LevelEditorLayer19claimCustomParticleERKSsRKN7cocos2d14ParticleStructEiiib")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2, p3, p4, p5);
}

auto LevelEditorLayer::unclaimCustomParticle(gd::string const& p0, cocos2d::CCParticleSystemQuad* p1) -> decltype(unclaimCustomParticle(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string const&, cocos2d::CCParticleSystemQuad*>::func(&LevelEditorLayer::unclaimCustomParticle), this);
	using FunctionType = decltype(unclaimCustomParticle(p0, p1))(*)(LevelEditorLayer*, gd::string const&, cocos2d::CCParticleSystemQuad*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16LevelEditorLayer21unclaimCustomParticleERKSsPN7cocos2d20CCParticleSystemQuadE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto LevelEditorLayer::addObjectFromVector(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(addObjectFromVector(p0, p1)) {
	using FunctionType = decltype(addObjectFromVector(p0, p1))(*)(LevelEditorLayer*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16LevelEditorLayer19addObjectFromVectorERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto LevelEditorLayer::createObjectsFromSetup(gd::string& p0) -> decltype(createObjectsFromSetup(p0)) {
	using FunctionType = decltype(createObjectsFromSetup(p0))(*)(LevelEditorLayer*, gd::string&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16LevelEditorLayer22createObjectsFromSetupERSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto LevelEditorLayer::createObjectsFromString(gd::string const& p0, bool p1, bool p2) -> decltype(createObjectsFromString(p0, p1, p2)) {
	using FunctionType = decltype(createObjectsFromString(p0, p1, p2))(*)(LevelEditorLayer*, gd::string const&, bool, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16LevelEditorLayer23createObjectsFromStringERKSsbb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

bool LevelEditorLayer::isLayerLocked(int layer) {
        if (layer < 10000 && m_layerLockingEnabled) {
            return m_lockedLayers.at(layer);
        }
        return false;
    }

void LevelUpdateDelegate::levelUpdateFinished(GJGameLevel* p0, UpdateResponse p1) {}

void LevelUpdateDelegate::levelUpdateFailed(int p0) {}

void RateLevelDelegate::rateLevelClosed() {}

void NumberInputDelegate::numberInputClosed(NumberInputLayer* p0) {}

auto LevelLeaderboard::getSpriteButton(gd::string p0, cocos2d::SEL_MenuHandler p1, cocos2d::CCMenu* p2, float p3, cocos2d::CCPoint p4, int p5) -> decltype(getSpriteButton(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(getSpriteButton(p0, p1, p2, p3, p4, p5))(*)(LevelLeaderboard*, gd::string, cocos2d::SEL_MenuHandler, cocos2d::CCMenu*, float, cocos2d::CCPoint, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16LevelLeaderboard15getSpriteButtonESsMN7cocos2d8CCObjectEFvPS1_EPNS0_6CCMenuEfNS0_7CCPointEi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

LevelListCell::LevelListCell(char const* p0, float p1, float p2) : LevelListCell(geode::CutoffConstructor, sizeof(LevelListCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	LevelListCell::~LevelListCell();
	using FunctionType = void(*)(LevelListCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13LevelListCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

void LevelListDeleteDelegate::levelListDeleteFinished(int p0) {}

void LevelListDeleteDelegate::levelListDeleteFailed(int p0) {}

void SelectListIconDelegate::iconSelectClosed(SelectListIconLayer* p0) {}

LevelListLayer::LevelListLayer() {
        m_buttonMenu = nullptr;
        m_searchKey1 = "";
        m_levelList = nullptr;
        m_searchKey2 = "";
        m_likeButton = nullptr;
        m_exiting = false;
        m_titleInput = nullptr;
        m_editMode = 0;
        m_objects = nullptr;
        m_diffSprite = nullptr;
        m_featureSprite = nullptr;
        m_rewardPosition = cocos2d::CCPointMake(0.f, 0.f);
        m_exited = false;
    }

auto LevelListLayer::shareCommentClosed(gd::string p0, ShareCommentLayer* p1) -> decltype(shareCommentClosed(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string, ShareCommentLayer*>::func(&LevelListLayer::shareCommentClosed), this);
	using FunctionType = decltype(shareCommentClosed(p0, p1))(*)(LevelListLayer*, gd::string, ShareCommentLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14LevelListLayer18shareCommentClosedESsP17ShareCommentLayer")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

LevelPage::LevelPage() {}

void LevelPage::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

void LevelPage::ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

auto LevelSearchLayer::getSearchObject(SearchType p0, gd::string p1) -> decltype(getSearchObject(p0, p1)) {
	using FunctionType = decltype(getSearchObject(p0, p1))(*)(LevelSearchLayer*, SearchType, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16LevelSearchLayer15getSearchObjectE10SearchTypeSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

LevelSelectLayer::LevelSelectLayer() {}

LevelSelectLayer::~LevelSelectLayer() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(LevelSelectLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16LevelSelectLayerD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) LevelSelectLayer(geode::CutoffConstructor, sizeof(LevelSelectLayer));
	CCDestructor::lock(this) = true;
}

auto LevelSettingsLayer::createToggleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCMenu* p3, cocos2d::CCPoint p4) -> decltype(createToggleButton(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(createToggleButton(p0, p1, p2, p3, p4))(*)(LevelSettingsLayer*, gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN18LevelSettingsLayer18createToggleButtonESsMN7cocos2d8CCObjectEFvPS1_EbPNS0_6CCMenuENS0_7CCPointE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto LevelSettingsObject::objectFromString(gd::string const& str) -> decltype(objectFromString(str)) {
	using FunctionType = decltype(objectFromString(str))(*)(gd::string const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19LevelSettingsObject16objectFromStringERKSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(str);
}

auto LevelTools::base64DecodeString(gd::string p0) -> decltype(base64DecodeString(p0)) {
	using FunctionType = decltype(base64DecodeString(p0))(*)(gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10LevelTools18base64DecodeStringESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto LevelTools::base64EncodeString(gd::string p0) -> decltype(base64EncodeString(p0)) {
	using FunctionType = decltype(base64EncodeString(p0))(*)(gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10LevelTools18base64EncodeStringESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto LevelTools::verifyLevelIntegrity(gd::string p0, int p1) -> decltype(verifyLevelIntegrity(p0, p1)) {
	using FunctionType = decltype(verifyLevelIntegrity(p0, p1))(*)(gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10LevelTools20verifyLevelIntegrityESsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

void LevelUploadDelegate::levelUploadFinished(GJGameLevel* p0) {}

void LevelUploadDelegate::levelUploadFailed(GJGameLevel* p0) {}

ListCell::ListCell(char const* p0, float p1, float p2) : ListCell(geode::CutoffConstructor, sizeof(ListCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	ListCell::~ListCell();
	using FunctionType = void(*)(ListCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8ListCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

LoadingCircle::LoadingCircle() {}

bool LoadingCircle::ccTouchBegan(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) { return true; }

void LoadingCircle::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

void LoadingCircle::ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

void LoadingCircle::ccTouchCancelled(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

void LoadingCircle::setFade(bool fade) {
        m_fade = fade;
    }

auto LocalLevelManager::getAllLevelsWithName(gd::string p0) -> decltype(getAllLevelsWithName(p0)) {
	using FunctionType = decltype(getAllLevelsWithName(p0))(*)(LocalLevelManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17LocalLevelManager20getAllLevelsWithNameESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

MapPackCell::MapPackCell(char const* p0, float p1, float p2) : MapPackCell(geode::CutoffConstructor, sizeof(MapPackCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	MapPackCell::~MapPackCell();
	using FunctionType = void(*)(MapPackCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11MapPackCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

MenuGameLayer::MenuGameLayer() {}

void MenuGameLayer::ccTouchMoved(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

void MenuGameLayer::ccTouchEnded(cocos2d::CCTouch* p0, cocos2d::CCEvent* p1) {}

MenuLayer* MenuLayer::get() {
        return GameManager::get()->m_menuLayer;
    }

void MenuLayer::onEveryplay(cocos2d::CCObject* sender) {}

void MenuLayer::showMeltdownPromo() {}

void MessageListDelegate::loadMessagesFinished(cocos2d::CCArray* p0, char const* p1) {}

void MessageListDelegate::loadMessagesFailed(char const* p0, GJErrorCode p1) {}

void MessageListDelegate::forceReloadMessages(bool p0) {}

void MessageListDelegate::setupPageInfo(gd::string p0, char const* p1) {}

auto MessagesProfilePage::setupPageInfo(gd::string p0, char const* p1) -> decltype(setupPageInfo(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string, char const*>::func(&MessagesProfilePage::setupPageInfo), this);
	using FunctionType = decltype(setupPageInfo(p0, p1))(*)(MessagesProfilePage*, gd::string, char const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19MessagesProfilePage13setupPageInfoESsPKc")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

MoreOptionsLayer::MoreOptionsLayer() {}

auto MoreSearchLayer::createToggleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCMenu* p3, cocos2d::CCPoint p4) -> decltype(createToggleButton(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(createToggleButton(p0, p1, p2, p3, p4))(*)(MoreSearchLayer*, gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15MoreSearchLayer18createToggleButtonESsMN7cocos2d8CCObjectEFvPS1_EbPNS0_6CCMenuENS0_7CCPointE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

MoreVideoOptionsLayer::MoreVideoOptionsLayer() {
        m_page = 0;
        m_toggleCount = 0;
        m_pageCount = 0;
        m_fpsInput = nullptr;
        m_fpsNodes = nullptr;
    }

MultilineBitmapFont::MultilineBitmapFont() {
        m_specialDescriptors = nullptr;
        m_characters = nullptr;
        m_lines = nullptr;
        m_unkInt = 0;
        m_unkBool = false;
        m_unkPtr = nullptr;
        m_height = 0;
        m_width = 0;
        m_position = cocos2d::CCPointMake(0.f, 0.f);
        m_maxWidth = 0.f;
        m_disableColor = false;
    }

auto MultilineBitmapFont::createWithFont(char const* p0, gd::string p1, float p2, float p3, cocos2d::CCPoint p4, int p5, bool p6) -> decltype(createWithFont(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(createWithFont(p0, p1, p2, p3, p4, p5, p6))(*)(char const*, gd::string, float, float, cocos2d::CCPoint, int, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19MultilineBitmapFont14createWithFontEPKcSsffN7cocos2d7CCPointEib")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4, p5, p6);
}

auto MultilineBitmapFont::initWithFont(char const* p0, gd::string p1, float p2, float p3, cocos2d::CCPoint p4, int p5, bool p6) -> decltype(initWithFont(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(initWithFont(p0, p1, p2, p3, p4, p5, p6))(*)(MultilineBitmapFont*, char const*, gd::string, float, float, cocos2d::CCPoint, int, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19MultilineBitmapFont12initWithFontEPKcSsffN7cocos2d7CCPointEib")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6);
}

auto MultilineBitmapFont::readColorInfo(gd::string p0) -> decltype(readColorInfo(p0)) {
	using FunctionType = decltype(readColorInfo(p0))(*)(MultilineBitmapFont*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19MultilineBitmapFont13readColorInfoESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto MultilineBitmapFont::stringWithMaxWidth(gd::string p0, float p1, float p2) -> decltype(stringWithMaxWidth(p0, p1, p2)) {
	using FunctionType = decltype(stringWithMaxWidth(p0, p1, p2))(*)(MultilineBitmapFont*, gd::string, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19MultilineBitmapFont18stringWithMaxWidthESsff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto MusicArtistObject::create(int p0, gd::string p1, gd::string p2, gd::string p3) -> decltype(create(p0, p1, p2, p3)) {
	using FunctionType = decltype(create(p0, p1, p2, p3))(*)(int, gd::string, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17MusicArtistObject6createEiSsSsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto MusicArtistObject::init(int p0, gd::string p1, gd::string p2, gd::string p3) -> decltype(init(p0, p1, p2, p3)) {
	using FunctionType = decltype(init(p0, p1, p2, p3))(*)(MusicArtistObject*, int, gd::string, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17MusicArtistObject4initEiSsSsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto MusicBrowser::setTextPopupClosed(SetTextPopup* p0, gd::string p1) -> decltype(setTextPopupClosed(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<SetTextPopup*, gd::string>::func(&MusicBrowser::setTextPopupClosed), this);
	using FunctionType = decltype(setTextPopupClosed(p0, p1))(*)(MusicBrowser*, SetTextPopup*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12MusicBrowser18setTextPopupClosedEP12SetTextPopupSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

void PlatformDownloadDelegate::downloadFinished(char const* p0) {}

void PlatformDownloadDelegate::downloadFailed(char const* p0) {}

auto MusicDownloadManager::responseToDict(gd::string p0, char const* p1) -> decltype(responseToDict(p0, p1)) {
	using FunctionType = decltype(responseToDict(p0, p1))(*)(gd::string, char const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20MusicDownloadManager14responseToDictESsPKc")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto MusicDownloadManager::addSongObjectFromString(gd::string p0) -> decltype(addSongObjectFromString(p0)) {
	using FunctionType = decltype(addSongObjectFromString(p0))(*)(MusicDownloadManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20MusicDownloadManager23addSongObjectFromStringESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto MusicDownloadManager::createArtistsInfo(gd::string p0) -> decltype(createArtistsInfo(p0)) {
	using FunctionType = decltype(createArtistsInfo(p0))(*)(MusicDownloadManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20MusicDownloadManager17createArtistsInfoESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto MusicDownloadManager::createSongsInfo(gd::string p0, gd::string p1) -> decltype(createSongsInfo(p0, p1)) {
	using FunctionType = decltype(createSongsInfo(p0, p1))(*)(MusicDownloadManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20MusicDownloadManager15createSongsInfoESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto MusicDownloadManager::generateCustomContentURL(gd::string p0) -> decltype(generateCustomContentURL(p0)) {
	using FunctionType = decltype(generateCustomContentURL(p0))(*)(MusicDownloadManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20MusicDownloadManager24generateCustomContentURLESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto MusicDownloadManager::handleIt(bool p0, gd::string p1, gd::string p2, GJHttpType p3) -> decltype(handleIt(p0, p1, p2, p3)) {
	using FunctionType = decltype(handleIt(p0, p1, p2, p3))(*)(MusicDownloadManager*, bool, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20MusicDownloadManager8handleItEbSsSs10GJHttpType")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto MusicDownloadManager::handleItDelayed(bool p0, gd::string p1, gd::string p2, GJHttpType p3) -> decltype(handleItDelayed(p0, p1, p2, p3)) {
	using FunctionType = decltype(handleItDelayed(p0, p1, p2, p3))(*)(MusicDownloadManager*, bool, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20MusicDownloadManager15handleItDelayedEbSsSs10GJHttpType")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto MusicDownloadManager::onGetCustomContentURLCompleted(gd::string p0, gd::string p1) -> decltype(onGetCustomContentURLCompleted(p0, p1)) {
	using FunctionType = decltype(onGetCustomContentURLCompleted(p0, p1))(*)(MusicDownloadManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20MusicDownloadManager30onGetCustomContentURLCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto MusicDownloadManager::onGetSongInfoCompleted(gd::string p0, gd::string p1) -> decltype(onGetSongInfoCompleted(p0, p1)) {
	using FunctionType = decltype(onGetSongInfoCompleted(p0, p1))(*)(MusicDownloadManager*, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20MusicDownloadManager22onGetSongInfoCompletedESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto MusicDownloadManager::ProcessHttpGetRequest(gd::string p0, gd::string p1, cocos2d::extension::SEL_HttpResponse p2, int p3, int p4) -> decltype(ProcessHttpGetRequest(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(ProcessHttpGetRequest(p0, p1, p2, p3, p4))(*)(MusicDownloadManager*, gd::string, gd::string, cocos2d::extension::SEL_HttpResponse, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20MusicDownloadManager21ProcessHttpGetRequestESsSsN7cocos2d9extension16SEL_HttpResponseEii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto MusicDownloadManager::ProcessHttpRequest(gd::string p0, gd::string p1, gd::string p2, GJHttpType p3) -> decltype(ProcessHttpRequest(p0, p1, p2, p3)) {
	using FunctionType = decltype(ProcessHttpRequest(p0, p1, p2, p3))(*)(MusicDownloadManager*, gd::string, gd::string, gd::string, GJHttpType);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20MusicDownloadManager18ProcessHttpRequestESsSsSs10GJHttpType")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

MusicSearchResult::MusicSearchResult() : MusicSearchResult(geode::CutoffConstructor, sizeof(MusicSearchResult)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	MusicSearchResult::~MusicSearchResult();
	using FunctionType = void(*)(MusicSearchResult*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17MusicSearchResultC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

auto MusicSearchResult::getFilesMatchingSearch(cocos2d::CCArray* p0, gd::string p1) -> decltype(getFilesMatchingSearch(p0, p1)) {
	using FunctionType = decltype(getFilesMatchingSearch(p0, p1))(*)(MusicSearchResult*, cocos2d::CCArray*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17MusicSearchResult22getFilesMatchingSearchEPN7cocos2d7CCArrayESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

NumberInputLayer::NumberInputLayer() {
        m_okButton = nullptr;
        m_minimum = 4;
        m_maximum = 4;
        m_inputString = "";
        m_delegate = nullptr;
    }

auto ObjectControlGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&ObjectControlGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(ObjectControlGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN23ObjectControlGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

const char* ObjectToolbox::intKeyToFrame(int key) {
        return m_allKeys[key].c_str();
    }

void OnlineListDelegate::loadListFinished(cocos2d::CCArray* p0, char const* p1) {}

void OnlineListDelegate::loadListFailed(char const* p0) {}

void OnlineListDelegate::setupPageInfo(gd::string p0, char const* p1) {}

OptionsCell::OptionsCell(char const* p0, float p1, float p2) : OptionsCell(geode::CutoffConstructor, sizeof(OptionsCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	OptionsCell::~OptionsCell();
	using FunctionType = void(*)(OptionsCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11OptionsCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

void OptionsLayer::FLAlert_Clicked(FLAlertLayer* p0, bool p1) {}

auto OptionsLayer::createToggleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCMenu* p3, cocos2d::CCPoint p4) -> decltype(createToggleButton(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(createToggleButton(p0, p1, p2, p3, p4))(*)(OptionsLayer*, gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12OptionsLayer18createToggleButtonESsMN7cocos2d8CCObjectEFvPS1_EbPNS0_6CCMenuENS0_7CCPointE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto OptionsObject::create(int p0, bool p1, gd::string p2, OptionsObjectDelegate* p3) -> decltype(create(p0, p1, p2, p3)) {
	using FunctionType = decltype(create(p0, p1, p2, p3))(*)(int, bool, gd::string, OptionsObjectDelegate*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13OptionsObject6createEibSsP21OptionsObjectDelegate")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3);
}

auto OptionsObject::init(int p0, bool p1, gd::string p2, OptionsObjectDelegate* p3) -> decltype(init(p0, p1, p2, p3)) {
	using FunctionType = decltype(init(p0, p1, p2, p3))(*)(OptionsObject*, int, bool, gd::string, OptionsObjectDelegate*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13OptionsObject4initEibSsP21OptionsObjectDelegate")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3);
}

auto ParticleGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&ParticleGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(ParticleGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN18ParticleGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto ParticleGameObject::setParticleString(gd::string p0) -> decltype(setParticleString(p0)) {
	using FunctionType = decltype(setParticleString(p0))(*)(ParticleGameObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN18ParticleGameObject17setParticleStringESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

PauseLayer::PauseLayer() : PauseLayer(geode::CutoffConstructor, sizeof(PauseLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	PauseLayer::~PauseLayer();
	using FunctionType = void(*)(PauseLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10PauseLayerC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

void PauseLayer::keyUp(cocos2d::enumKeyCodes p0) {}

auto PauseLayer::createToggleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCMenu* p3, cocos2d::CCPoint p4) -> decltype(createToggleButton(p0, p1, p2, p3, p4)) {
	using FunctionType = decltype(createToggleButton(p0, p1, p2, p3, p4))(*)(PauseLayer*, gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10PauseLayer18createToggleButtonESsMN7cocos2d8CCObjectEFvPS1_EbPNS0_6CCMenuENS0_7CCPointE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4);
}

auto PlatformToolbox::copyToClipboard(gd::string p0) -> decltype(copyToClipboard(p0)) {
	using FunctionType = decltype(copyToClipboard(p0))(*)(gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15PlatformToolbox15copyToClipboardESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto PlatformToolbox::doesFileExist(gd::string p0) -> decltype(doesFileExist(p0)) {
	using FunctionType = decltype(doesFileExist(p0))(*)(gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15PlatformToolbox13doesFileExistESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto PlatformToolbox::downloadAndSavePromoImage(gd::string p0, gd::string p1) -> decltype(downloadAndSavePromoImage(p0, p1)) {
	using FunctionType = decltype(downloadAndSavePromoImage(p0, p1))(*)(gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15PlatformToolbox25downloadAndSavePromoImageESsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto PlatformToolbox::loadAndDecryptFileToString(char const* p0, char const* p1, gd::string& p2) -> decltype(loadAndDecryptFileToString(p0, p1, p2)) {
	using FunctionType = decltype(loadAndDecryptFileToString(p0, p1, p2))(*)(char const*, char const*, gd::string&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15PlatformToolbox26loadAndDecryptFileToStringEPKcS1_RSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto PlatformToolbox::saveAndEncryptStringToFile(gd::string& p0, char const* p1, char const* p2) -> decltype(saveAndEncryptStringToFile(p0, p1, p2)) {
	using FunctionType = decltype(saveAndEncryptStringToFile(p0, p1, p2))(*)(gd::string&, char const*, char const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15PlatformToolbox26saveAndEncryptStringToFileERSsPKcS2_")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto PlatformToolbox::spriteFromSavedFile(gd::string p0) -> decltype(spriteFromSavedFile(p0)) {
	using FunctionType = decltype(spriteFromSavedFile(p0))(*)(gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15PlatformToolbox19spriteFromSavedFileESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto PlatformToolbox::tryShowRateDialog(gd::string p0) -> decltype(tryShowRateDialog(p0)) {
	using FunctionType = decltype(tryShowRateDialog(p0))(*)(gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15PlatformToolbox17tryShowRateDialogESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

PlayerCheckpoint::PlayerCheckpoint() : PlayerCheckpoint(geode::CutoffConstructor, sizeof(PlayerCheckpoint)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	PlayerCheckpoint::~PlayerCheckpoint();
	using FunctionType = void(*)(PlayerCheckpoint*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16PlayerCheckpointC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

auto PlayerControlGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&PlayerControlGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(PlayerControlGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN23PlayerControlGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

void PlayerObject::disableCustomGlowColor() {
        m_hasCustomGlowColor = false;
    }

void PlayerObject::runNormalRotation() {
        this->runNormalRotation(false, 1.0f);
    }

void PlayerObject::setYVelocity(double velocity, int p1) {
        double rounded = (int)velocity;
        if (velocity != rounded) {
            m_yVelocity = std::round((velocity - rounded) * 1000) / 1000. + rounded;
        } else {
            m_yVelocity = velocity;
        }
    }

void PlayerObject::togglePlatformerMode(bool val) {
        m_isPlatformer = val;
    }

auto PlayerObject::updatePlayerSpriteExtra(gd::string p0) -> decltype(updatePlayerSpriteExtra(p0)) {
	using FunctionType = decltype(updatePlayerSpriteExtra(p0))(*)(PlayerObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12PlayerObject23updatePlayerSpriteExtraESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto PlayerObject::updateShipSpriteExtra(gd::string p0) -> decltype(updateShipSpriteExtra(p0)) {
	using FunctionType = decltype(updateShipSpriteExtra(p0))(*)(PlayerObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12PlayerObject21updateShipSpriteExtraESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

PlayLayer::PlayLayer() : PlayLayer(geode::CutoffConstructor, sizeof(PlayLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	PlayLayer::~PlayLayer();
	using FunctionType = void(*)(PlayLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN9PlayLayerC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

PlayLayer::~PlayLayer() {
	// basically we destruct it once by calling the gd function, 
	// then lock it, so that other gd destructors dont get called
	if (CCDestructor::lock(this)) return;
	using FunctionType = void(*)(PlayLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN9PlayLayerD2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
	// we need to construct it back so that it uhhh ummm doesnt crash
	// while going to the child destructors
	auto thing = new (this) PlayLayer(geode::CutoffConstructor, sizeof(PlayLayer));
	CCDestructor::lock(this) = true;
}

PlayLayer* PlayLayer::get() {
        return GameManager::get()->m_playLayer;
    }

auto PlayLayer::activatePlatformerEndTrigger(EndTriggerGameObject* p0, gd::vector<int> const& p1) -> decltype(activatePlatformerEndTrigger(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<EndTriggerGameObject*, gd::vector<int> const&>::func(&PlayLayer::activatePlatformerEndTrigger), this);
	using FunctionType = decltype(activatePlatformerEndTrigger(p0, p1))(*)(PlayLayer*, EndTriggerGameObject*, gd::vector<int> const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN9PlayLayer28activatePlatformerEndTriggerEP20EndTriggerGameObjectRKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

void PlayLayer::addCircle(CCCircleWave* cw) {
        m_circleWaveArray->addObject(cw);
    }

auto PlayLayer::loadActiveSaveObjects(gd::vector<SavedActiveObjectState>& p0, gd::vector<SavedSpecialObjectState>& p1) -> decltype(loadActiveSaveObjects(p0, p1)) {
	using FunctionType = decltype(loadActiveSaveObjects(p0, p1))(*)(PlayLayer*, gd::vector<SavedActiveObjectState>&, gd::vector<SavedSpecialObjectState>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN9PlayLayer21loadActiveSaveObjectsERSt6vectorI22SavedActiveObjectStateSaIS1_EERS0_I23SavedSpecialObjectStateSaIS5_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto PlayLayer::loadDynamicSaveObjects(gd::vector<SavedObjectStateRef>& p0) -> decltype(loadDynamicSaveObjects(p0)) {
	using FunctionType = decltype(loadDynamicSaveObjects(p0))(*)(PlayLayer*, gd::vector<SavedObjectStateRef>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN9PlayLayer22loadDynamicSaveObjectsERSt6vectorI19SavedObjectStateRefSaIS1_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto PlayLayer::playReplay(gd::string p0) -> decltype(playReplay(p0)) {
	using FunctionType = decltype(playReplay(p0))(*)(PlayLayer*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN9PlayLayer10playReplayESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto PlayLayer::prepareCreateObjectsFromSetup(gd::string& p0) -> decltype(prepareCreateObjectsFromSetup(p0)) {
	using FunctionType = decltype(prepareCreateObjectsFromSetup(p0))(*)(PlayLayer*, gd::string&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN9PlayLayer29prepareCreateObjectsFromSetupERSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto PlayLayer::saveActiveSaveObjects(gd::vector<SavedActiveObjectState>& p0, gd::vector<SavedSpecialObjectState>& p1) -> decltype(saveActiveSaveObjects(p0, p1)) {
	using FunctionType = decltype(saveActiveSaveObjects(p0, p1))(*)(PlayLayer*, gd::vector<SavedActiveObjectState>&, gd::vector<SavedSpecialObjectState>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN9PlayLayer21saveActiveSaveObjectsERSt6vectorI22SavedActiveObjectStateSaIS1_EERS0_I23SavedSpecialObjectStateSaIS5_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto PlayLayer::saveDynamicSaveObjects(gd::vector<SavedObjectStateRef>& p0) -> decltype(saveDynamicSaveObjects(p0)) {
	using FunctionType = decltype(saveDynamicSaveObjects(p0))(*)(PlayLayer*, gd::vector<SavedObjectStateRef>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN9PlayLayer22saveDynamicSaveObjectsERSt6vectorI19SavedObjectStateRefSaIS1_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto ProfilePage::setupPageInfo(gd::string p0, char const* p1) -> decltype(setupPageInfo(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string, char const*>::func(&ProfilePage::setupPageInfo), this);
	using FunctionType = decltype(setupPageInfo(p0, p1))(*)(ProfilePage*, gd::string, char const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11ProfilePage13setupPageInfoESsPKc")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto RandTriggerGameObject::triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2) -> decltype(triggerObject(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*, int, gd::vector<int> const*>::func(&RandTriggerGameObject::triggerObject), this);
	using FunctionType = decltype(triggerObject(p0, p1, p2))(*)(RandTriggerGameObject*, GJBaseGameLayer*, int, gd::vector<int> const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN21RandTriggerGameObject13triggerObjectEP15GJBaseGameLayeriPKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto RandTriggerGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&RandTriggerGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(RandTriggerGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN21RandTriggerGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

RateDemonLayer::RateDemonLayer() {
        m_uploadFinished = false;
        m_submitButton = nullptr;
        m_demons = nullptr;
        m_unkPtr = nullptr;
        m_levelID = 0;
        m_demonRate = 0;
        m_moderator = false;
        m_popup = nullptr;
        m_delegate = nullptr;
    }

RateLevelLayer::RateLevelLayer() {
        m_submitButton = nullptr;
        m_difficulties = nullptr;
        m_levelID = 0;
        m_levelRate = 0;
        m_delegate = nullptr;
    }

RateStarsLayer::RateStarsLayer() : RateStarsLayer(geode::CutoffConstructor, sizeof(RateStarsLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	RateStarsLayer::~RateStarsLayer();
	using FunctionType = void(*)(RateStarsLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14RateStarsLayerC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

void RetryLevelLayer::keyUp(cocos2d::enumKeyCodes p0) {}

RewardsPage::RewardsPage() {
        m_leftLabel = nullptr;
        m_rightLabel = nullptr;
        m_leftChest = nullptr;
        m_rightChest = nullptr;
        m_leftOpen = false;
        m_rightOpen = false;
        m_openLayer = nullptr;
    }

void RewardsPage::FLAlert_Clicked(FLAlertLayer* p0, bool p1) {}

void RewardUnlockLayer::keyBackClicked() {}

auto RotateGameplayGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&RotateGameplayGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(RotateGameplayGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN24RotateGameplayGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto SetTextPopup::create(gd::string value, gd::string placeholder, int maxLength, gd::string title, gd::string okBtnText, bool showResetBtn, float p6) -> decltype(create(value, placeholder, maxLength, title, okBtnText, showResetBtn, p6)) {
	using FunctionType = decltype(create(value, placeholder, maxLength, title, okBtnText, showResetBtn, p6))(*)(gd::string, gd::string, int, gd::string, gd::string, bool, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12SetTextPopup6createESsSsiSsSsbf")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(value, placeholder, maxLength, title, okBtnText, showResetBtn, p6);
}

auto SetTextPopup::init(gd::string p0, gd::string p1, int p2, gd::string p3, gd::string p4, bool p5, float p6) -> decltype(init(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(init(p0, p1, p2, p3, p4, p5, p6))(*)(SetTextPopup*, gd::string, gd::string, int, gd::string, gd::string, bool, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12SetTextPopup4initESsSsiSsSsbf")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6);
}

auto SearchSFXPopup::create(gd::string p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14SearchSFXPopup6createESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto SearchSFXPopup::init(gd::string p0) -> decltype(init(p0)) {
	using FunctionType = decltype(init(p0))(*)(SearchSFXPopup*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14SearchSFXPopup4initESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

void SecretLayer::FLAlert_Clicked(FLAlertLayer* p0, bool p1) {}

auto SecretLayer::updateMessageLabel(gd::string p0) -> decltype(updateMessageLabel(p0)) {
	using FunctionType = decltype(updateMessageLabel(p0))(*)(SecretLayer*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN11SecretLayer18updateMessageLabelESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

void SecretLayer2::FLAlert_Clicked(FLAlertLayer* p0, bool p1) {}

auto SecretLayer2::updateMessageLabel(gd::string text) -> decltype(updateMessageLabel(text)) {
	using FunctionType = decltype(updateMessageLabel(text))(*)(SecretLayer2*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12SecretLayer218updateMessageLabelESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, text);
}

SecretLayer3::SecretLayer3() {
        m_lockInput = false;
        m_locksArray = nullptr;
        m_demonEyes = nullptr;
        m_demonBody = nullptr;
        m_secretChest = nullptr;
    }

void SecretLayer4::FLAlert_Clicked(FLAlertLayer* p0, bool p1) {}

void SecretLayer4::dialogClosed(DialogLayer* p0) {}

auto SecretLayer4::updateMessageLabel(gd::string p0) -> decltype(updateMessageLabel(p0)) {
	using FunctionType = decltype(updateMessageLabel(p0))(*)(SecretLayer4*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12SecretLayer418updateMessageLabelESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

SecretLayer5::SecretLayer5() {
        m_unk1b8 = -1;
        m_unk1bc = -1;
        m_unk1c0 = 0;
        m_unk1c4 = 0;
        m_unk1c8 = 0;
        m_unk1cc = -1;
        m_textInput = nullptr;
        m_messageLabel = nullptr;
        m_exiting = false;
        m_torchFires = nullptr;
        m_loading = false;
        m_rewardStatus = 0;
        m_chestID = "";
        m_uiLocked = false;
        m_soundEffects = {};
        m_chatIndex = -1;
    }

void SecretLayer5::FLAlert_Clicked(FLAlertLayer* p0, bool p1) {}

void SecretLayer5::dialogClosed(DialogLayer* p0) {}

auto SecretLayer5::onlineRewardStatusFinished(gd::string p0) -> decltype(onlineRewardStatusFinished(p0)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string>::func(&SecretLayer5::onlineRewardStatusFinished), this);
	using FunctionType = decltype(onlineRewardStatusFinished(p0))(*)(SecretLayer5*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12SecretLayer526onlineRewardStatusFinishedESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0);
}

auto SecretLayer5::updateMessageLabel(gd::string text) -> decltype(updateMessageLabel(text)) {
	using FunctionType = decltype(updateMessageLabel(text))(*)(SecretLayer5*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12SecretLayer518updateMessageLabelESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, text);
}

SecretLayer6::SecretLayer6() : SecretLayer6(geode::CutoffConstructor, sizeof(SecretLayer6)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	SecretLayer6::~SecretLayer6();
	using FunctionType = void(*)(SecretLayer6*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12SecretLayer6C2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

SecretRewardsLayer::SecretRewardsLayer() {
        m_mainLayer = nullptr;
        m_secondaryLayer = nullptr;
        m_chestCounter = nullptr;
        m_chestCounters = nullptr;
        m_backSprite = nullptr;
        m_unkSize4_2 = 0;
        m_secondaryScrollLayer = nullptr;
        m_scratchDialogIndex = 0;
        m_potborDialogIndex = 0;
        m_diamondDialogIndex = 0;
        m_mechanicDialogIndex = 0;
        m_inMainLayer = false;
        m_rewardType = GJRewardType::Unknown;
        m_lockedDialogIndex = 0;
    }

auto SelectEventLayer::create(SetupEventLinkPopup* p0, gd::set<int>& p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(SetupEventLinkPopup*, gd::set<int>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16SelectEventLayer6createEP19SetupEventLinkPopupRSt3setIiSt4lessIiESaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto SelectEventLayer::addToggle(int p0, gd::string p1) -> decltype(addToggle(p0, p1)) {
	using FunctionType = decltype(addToggle(p0, p1))(*)(SelectEventLayer*, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16SelectEventLayer9addToggleEiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto SelectEventLayer::init(SetupEventLinkPopup* p0, gd::set<int>& p1) -> decltype(init(p0, p1)) {
	using FunctionType = decltype(init(p0, p1))(*)(SelectEventLayer*, SetupEventLinkPopup*, gd::set<int>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16SelectEventLayer4initEP19SetupEventLinkPopupRSt3setIiSt4lessIiESaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

SelectFontLayer::SelectFontLayer() {
        m_font = -1;
        m_editorLayer = nullptr;
        m_fontLabel = nullptr;
    }

SelectListIconLayer::SelectListIconLayer() {}

SelectSFXSortLayer::SelectSFXSortLayer() {
        m_sortType = AudioSortType::NameAscending;
        m_delegate = nullptr;
    }

auto SequenceTriggerGameObject::triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2) -> decltype(triggerObject(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*, int, gd::vector<int> const*>::func(&SequenceTriggerGameObject::triggerObject), this);
	using FunctionType = decltype(triggerObject(p0, p1, p2))(*)(SequenceTriggerGameObject*, GJBaseGameLayer*, int, gd::vector<int> const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN25SequenceTriggerGameObject13triggerObjectEP15GJBaseGameLayeriPKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto SequenceTriggerGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&SequenceTriggerGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(SequenceTriggerGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN25SequenceTriggerGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto SetFolderPopup::create(int value, bool isCreated, gd::string title) -> decltype(create(value, isCreated, title)) {
	using FunctionType = decltype(create(value, isCreated, title))(*)(int, bool, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14SetFolderPopup6createEibSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(value, isCreated, title);
}

auto SetFolderPopup::setTextPopupClosed(SetTextPopup* p0, gd::string p1) -> decltype(setTextPopupClosed(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<SetTextPopup*, gd::string>::func(&SetFolderPopup::setTextPopupClosed), this);
	using FunctionType = decltype(setTextPopupClosed(p0, p1))(*)(SetFolderPopup*, SetTextPopup*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14SetFolderPopup18setTextPopupClosedEP12SetTextPopupSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto SetFolderPopup::init(int value, bool isCreated, gd::string title) -> decltype(init(value, isCreated, title)) {
	using FunctionType = decltype(init(value, isCreated, title))(*)(SetFolderPopup*, int, bool, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14SetFolderPopup4initEibSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, value, isCreated, title);
}

auto SetGroupIDLayer::createTextInput(cocos2d::CCPoint p0, int p1, int p2, gd::string p3, float p4, int p5) -> decltype(createTextInput(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(createTextInput(p0, p1, p2, p3, p4, p5))(*)(SetGroupIDLayer*, cocos2d::CCPoint, int, int, gd::string, float, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15SetGroupIDLayer15createTextInputEN7cocos2d7CCPointEiiSsfi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto SetTargetIDLayer::create(EffectGameObject* p0, cocos2d::CCArray* p1, gd::string p2, gd::string p3, int p4, int p5, int p6) -> decltype(create(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(create(p0, p1, p2, p3, p4, p5, p6))(*)(EffectGameObject*, cocos2d::CCArray*, gd::string, gd::string, int, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16SetTargetIDLayer6createEP16EffectGameObjectPN7cocos2d7CCArrayESsSsiii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4, p5, p6);
}

auto SetTargetIDLayer::init(EffectGameObject* p0, cocos2d::CCArray* p1, gd::string p2, gd::string p3, int p4, int p5, int p6) -> decltype(init(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(init(p0, p1, p2, p3, p4, p5, p6))(*)(SetTargetIDLayer*, EffectGameObject*, cocos2d::CCArray*, gd::string, gd::string, int, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16SetTargetIDLayer4initEP16EffectGameObjectPN7cocos2d7CCArrayESsSsiii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6);
}

auto SetupAreaAnimTriggerPopup::createValueControlAdvancedAnim(int p0, gd::string p1, cocos2d::CCPoint p2, float p3, bool p4, InputValueType p5, int p6, bool p7, float min, float max, int p10, int p11, GJInputStyle p12) -> decltype(createValueControlAdvancedAnim(p0, p1, p2, p3, p4, p5, p6, p7, min, max, p10, p11, p12)) {
	using FunctionType = decltype(createValueControlAdvancedAnim(p0, p1, p2, p3, p4, p5, p6, p7, min, max, p10, p11, p12))(*)(SetupAreaAnimTriggerPopup*, int, gd::string, cocos2d::CCPoint, float, bool, InputValueType, int, bool, float, float, int, int, GJInputStyle);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN25SetupAreaAnimTriggerPopup30createValueControlAdvancedAnimEiSsN7cocos2d7CCPointEfb14InputValueTypeibffii12GJInputStyle")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7, min, max, p10, p11, p12);
}

auto SetupEventLinkPopup::updateEventIDs(gd::set<int>& p0) -> decltype(updateEventIDs(p0)) {
	using FunctionType = decltype(updateEventIDs(p0))(*)(SetupEventLinkPopup*, gd::set<int>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN19SetupEventLinkPopup14updateEventIDsERSt3setIiSt4lessIiESaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto SetupOptionsTriggerPopup::addOption(int p0, gd::string p1) -> decltype(addOption(p0, p1)) {
	using FunctionType = decltype(addOption(p0, p1))(*)(SetupOptionsTriggerPopup*, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN24SetupOptionsTriggerPopup9addOptionEiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

void SetupPulsePopup::textInputOpened(CCTextInputNode* p0) {}

void SetupRandAdvTriggerPopup::textChanged(CCTextInputNode* p0) {}

void SetupSFXPopup::sfxObjectSelected(SFXInfoObject* p0) {}

SFXBrowser::SFXBrowser() {
        m_searchResult = nullptr;
        m_sfxObjects = nullptr;
        m_listLayer = nullptr;
        m_nameLabel = nullptr;
        m_pathLabel = nullptr;
        m_infoLabel = nullptr;
        m_pageLabel = nullptr;
        m_searchLabel = nullptr;
        m_prevButton = nullptr;
        m_refreshButton = nullptr;
        m_clearSearchButton = nullptr;
        m_circleSprite = nullptr;
        m_libraryVersion = 0;
        m_cellAmount = 0;
        m_gettingURL = false;
        m_selectedCell = false;
        m_snapToSelected = false;
        m_compactMode = false;
        m_sortType = AudioSortType::NameAscending;
        m_delegate = nullptr;
        #ifdef GEODE_IS_DESKTOP
        m_autoUpdating = false;
        #endif
    }

auto SFXBrowser::setTextPopupClosed(SetTextPopup* p0, gd::string p1) -> decltype(setTextPopupClosed(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<SetTextPopup*, gd::string>::func(&SFXBrowser::setTextPopupClosed), this);
	using FunctionType = decltype(setTextPopupClosed(p0, p1))(*)(SFXBrowser*, SetTextPopup*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10SFXBrowser18setTextPopupClosedEP12SetTextPopupSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

SFXInfoObject::SFXInfoObject() {
        m_sfxID = 0;
        m_folderID = 0;
        m_size = 0;
        m_duration = 0;
        m_folder = false;
        m_unk049 = false;
        m_name = "";
    }

auto SFXInfoObject::create(int id, gd::string name, int folderID, int size, int duration) -> decltype(create(id, name, folderID, size, duration)) {
	using FunctionType = decltype(create(id, name, folderID, size, duration))(*)(int, gd::string, int, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13SFXInfoObject6createEiSsiii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(id, name, folderID, size, duration);
}

auto SFXInfoObject::init(int id, gd::string name, int folderID, int size, int duration) -> decltype(init(id, name, folderID, size, duration)) {
	using FunctionType = decltype(init(id, name, folderID, size, duration))(*)(SFXInfoObject*, int, gd::string, int, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13SFXInfoObject4initEiSsiii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, id, name, folderID, size, duration);
}

SFXFolderObject::SFXFolderObject() {
        m_sfxObjects = nullptr;
    }

auto SFXFolderObject::create(int p0, gd::string p1, int p2) -> decltype(create(p0, p1, p2)) {
	using FunctionType = decltype(create(p0, p1, p2))(*)(int, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15SFXFolderObject6createEiSsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2);
}

auto SFXFolderObject::init(int p0, gd::string p1, int p2) -> decltype(init(p0, p1, p2)) {
	using FunctionType = decltype(init(p0, p1, p2))(*)(SFXFolderObject*, int, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15SFXFolderObject4initEiSsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto SFXTriggerGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&SFXTriggerGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(SFXTriggerGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20SFXTriggerGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto ShaderGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&ShaderGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(ShaderGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN16ShaderGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

ShardsPage::ShardsPage() {
        m_pages = nullptr;
        m_prevButton = nullptr;
        m_nextButton = nullptr;
        m_tierSprite = nullptr;
        m_page = -1;
    }

ShareCommentLayer::ShareCommentLayer() : ShareCommentLayer(geode::CutoffConstructor, sizeof(ShareCommentLayer)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	ShareCommentLayer::~ShareCommentLayer();
	using FunctionType = void(*)(ShareCommentLayer*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17ShareCommentLayerC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

auto ShareCommentLayer::create(gd::string title, int charLimit, CommentType type, int ID, gd::string desc) -> decltype(create(title, charLimit, type, ID, desc)) {
	using FunctionType = decltype(create(title, charLimit, type, ID, desc))(*)(gd::string, int, CommentType, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17ShareCommentLayer6createESsi11CommentTypeiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(title, charLimit, type, ID, desc);
}

void ShareCommentLayer::textInputOpened(CCTextInputNode* textInput) {}

auto ShareCommentLayer::init(gd::string title, int charLimit, CommentType type, int ID, gd::string desc) -> decltype(init(title, charLimit, type, ID, desc)) {
	using FunctionType = decltype(init(title, charLimit, type, ID, desc))(*)(ShareCommentLayer*, gd::string, int, CommentType, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17ShareCommentLayer4initESsi11CommentTypeiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, title, charLimit, type, ID, desc);
}

auto ShareCommentLayer::updateDescText(gd::string desc) -> decltype(updateDescText(desc)) {
	using FunctionType = decltype(updateDescText(desc))(*)(ShareCommentLayer*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17ShareCommentLayer14updateDescTextESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, desc);
}

ShareLevelLayer::ShareLevelLayer() {
        m_level = nullptr;
        m_starsRequested = 0;
        m_starButtons = nullptr;
    }

ShareLevelSettingsLayer::ShareLevelSettingsLayer() {}

ShareListLayer::ShareListLayer() {
        m_list = nullptr;
        m_friendsOnlyToggler = nullptr;
        m_friendsOnlyLabel = nullptr;
    }

void SimplePlayer::disableCustomGlowColor() {
        m_hasCustomGlowColor = false;
    }

void SimplePlayer::enableCustomGlowColor(cocos2d::ccColor3B const& color) {
        m_hasCustomGlowColor = true;
        m_glowColor = color;
    }

void SimplePlayer::setSecondColor(cocos2d::ccColor3B const& color) {
        m_secondLayer->setColor(color);
        updateColors();
    }

void SliderThumb::setMaxOffset(float offset) {
        float value = getValue();
        m_length = offset;
        this->setPosition({0, 0});
        setValue(value);
    }

void SliderThumb::setRotated(bool rotated) {
        float value = getValue();
        m_vertical = rotated;
        this->setPosition({0, 0});
        setValue(value);
    }

void SliderTouchLogic::setMaxOffset(float offset) {
        float newOffset = m_thumb->getScale() * offset;
        m_length = newOffset;
        m_thumb->setMaxOffset(newOffset);
    }

void SliderTouchLogic::setRotated(bool rotated) {
        m_rotated = rotated;
        m_thumb->setRotated(rotated);
    }

Slider* Slider::create(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler handler) {
        return Slider::create(target, handler, 1.f);
    }

Slider* Slider::create(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler handler, float scale) {
        return Slider::create(target, handler, "sliderBar.png", "slidergroove.png", "sliderthumb.png", "sliderthumbsel.png", scale);
    }

bool Slider::getLiveDragging() {
        return m_touchLogic->m_activateThumb;
    }

SliderThumb* Slider::getThumb() {
        return m_touchLogic->m_thumb;
    }

float Slider::getValue() {
        return this->getThumb()->getValue();
    }

void Slider::hideGroove(bool visibility) {
        m_groove->setVisible(!visibility);
    }

void Slider::setBarVisibility(bool visibility) {
        m_sliderBar->setVisible(visibility);
    }

void Slider::setLiveDragging(bool activateThumb) {
        m_touchLogic->m_activateThumb = activateThumb;
    }

void Slider::setMaxOffset(float offset) {
        m_touchLogic->setMaxOffset(offset);
    }

void Slider::setRotated(bool rotated) {
        m_touchLogic->setRotated(rotated);
        m_groove->setRotation((rotated) ? -90 : 0);
    }

void Slider::updateBar() {
        float local_8;
        auto thumb = this->getThumb();
        if (!thumb->m_vertical) {
            local_8 = thumb->getPositionX();
        } else {
            local_8 = thumb->getPositionY();
        }

        float local_c = thumb->getScale() * thumb->m_length * 0.5f + local_8;
        float fVar6 = m_width;
        local_c = local_c / (thumb->getScale() * thumb->m_length);
        if (fVar6 * local_c <= fVar6) {
            fVar6 = fVar6 * local_c;
        }

        this->m_sliderBar->setTextureRect(cocos2d::CCRect(0.0f, 0.0f, fVar6, m_height));
    }

auto SmartGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&SmartGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(SmartGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15SmartGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

SmartTemplateCell::SmartTemplateCell(char const* p0, float p1, float p2) : SmartTemplateCell(geode::CutoffConstructor, sizeof(SmartTemplateCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	SmartTemplateCell::~SmartTemplateCell();
	using FunctionType = void(*)(SmartTemplateCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17SmartTemplateCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

SongCell::SongCell(char const* p0, float p1, float p2) : SongCell(geode::CutoffConstructor, sizeof(SongCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	SongCell::~SongCell();
	using FunctionType = void(*)(SongCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8SongCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto SongInfoLayer::create(gd::string p0, gd::string p1, gd::string p2, gd::string p3, gd::string p4, gd::string p5, int p6, gd::string p7, int p8) -> decltype(create(p0, p1, p2, p3, p4, p5, p6, p7, p8)) {
	using FunctionType = decltype(create(p0, p1, p2, p3, p4, p5, p6, p7, p8))(*)(gd::string, gd::string, gd::string, gd::string, gd::string, gd::string, int, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13SongInfoLayer6createESsSsSsSsSsSsiSsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4, p5, p6, p7, p8);
}

auto SongInfoLayer::init(gd::string p0, gd::string p1, gd::string p2, gd::string p3, gd::string p4, gd::string p5, int p6, gd::string p7, int p8) -> decltype(init(p0, p1, p2, p3, p4, p5, p6, p7, p8)) {
	using FunctionType = decltype(init(p0, p1, p2, p3, p4, p5, p6, p7, p8))(*)(SongInfoLayer*, gd::string, gd::string, gd::string, gd::string, gd::string, gd::string, int, gd::string, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13SongInfoLayer4initESsSsSsSsSsSsiSsi")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7, p8);
}

auto SongInfoObject::create(int songID, gd::string songName, gd::string artistName, int artistID, float filesize, gd::string youtubeVideo, gd::string youtubeChannel, gd::string url, int nongType, gd::string extraArtistIDs, bool isNew, int newType, int priority) -> decltype(create(songID, songName, artistName, artistID, filesize, youtubeVideo, youtubeChannel, url, nongType, extraArtistIDs, isNew, newType, priority)) {
	using FunctionType = decltype(create(songID, songName, artistName, artistID, filesize, youtubeVideo, youtubeChannel, url, nongType, extraArtistIDs, isNew, newType, priority))(*)(int, gd::string, gd::string, int, float, gd::string, gd::string, gd::string, int, gd::string, bool, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14SongInfoObject6createEiSsSsifSsSsSsiSsbii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(songID, songName, artistName, artistID, filesize, youtubeVideo, youtubeChannel, url, nongType, extraArtistIDs, isNew, newType, priority);
}

auto SongInfoObject::addTags(gd::string p0) -> decltype(addTags(p0)) {
	using FunctionType = decltype(addTags(p0))(*)(SongInfoObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14SongInfoObject7addTagsESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto SongInfoObject::init(int songID, gd::string songName, gd::string artistName, int artistID, float filesize, gd::string youtubeVideo, gd::string youtubeChannel, gd::string url, int nongType, gd::string extraArtistIDs, bool isNew, int newType, int priority) -> decltype(init(songID, songName, artistName, artistID, filesize, youtubeVideo, youtubeChannel, url, nongType, extraArtistIDs, isNew, newType, priority)) {
	using FunctionType = decltype(init(songID, songName, artistName, artistID, filesize, youtubeVideo, youtubeChannel, url, nongType, extraArtistIDs, isNew, newType, priority))(*)(SongInfoObject*, int, gd::string, gd::string, int, float, gd::string, gd::string, gd::string, int, gd::string, bool, int, int);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14SongInfoObject4initEiSsSsifSsSsSsiSsbii")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, songID, songName, artistName, artistID, filesize, youtubeVideo, youtubeChannel, url, nongType, extraArtistIDs, isNew, newType, priority);
}

auto SongInfoObject::updateArtists(gd::string p0) -> decltype(updateArtists(p0)) {
	using FunctionType = decltype(updateArtists(p0))(*)(SongInfoObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14SongInfoObject13updateArtistsESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

SongObject::SongObject() : SongObject(geode::CutoffConstructor, sizeof(SongObject)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	SongObject::~SongObject();
	using FunctionType = void(*)(SongObject*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN10SongObjectC2Ev")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this);
}

auto SongTriggerGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&SongTriggerGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(SongTriggerGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN21SongTriggerGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto SpawnParticleGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&SpawnParticleGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(SpawnParticleGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN23SpawnParticleGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto SpawnTriggerGameObject::triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2) -> decltype(triggerObject(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*, int, gd::vector<int> const*>::func(&SpawnTriggerGameObject::triggerObject), this);
	using FunctionType = decltype(triggerObject(p0, p1, p2))(*)(SpawnTriggerGameObject*, GJBaseGameLayer*, int, gd::vector<int> const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22SpawnTriggerGameObject13triggerObjectEP15GJBaseGameLayeriPKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto SpawnTriggerGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&SpawnTriggerGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(SpawnTriggerGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22SpawnTriggerGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto SpawnTriggerGameObject::updateRemapKeys(gd::vector<int> const& p0) -> decltype(updateRemapKeys(p0)) {
	using FunctionType = decltype(updateRemapKeys(p0))(*)(SpawnTriggerGameObject*, gd::vector<int> const&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22SpawnTriggerGameObject15updateRemapKeysERKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto SpecialAnimGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&SpecialAnimGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(SpecialAnimGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN21SpecialAnimGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto SpriteAnimationManager::createAnimations(gd::string p0) -> decltype(createAnimations(p0)) {
	using FunctionType = decltype(createAnimations(p0))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22SpriteAnimationManager16createAnimationsESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto SpriteAnimationManager::createWithOwner(CCAnimatedSprite* p0, gd::string p1) -> decltype(createWithOwner(p0, p1)) {
	using FunctionType = decltype(createWithOwner(p0, p1))(*)(SpriteAnimationManager*, CCAnimatedSprite*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22SpriteAnimationManager15createWithOwnerEP16CCAnimatedSpriteSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto SpriteAnimationManager::executeAnimation(gd::string p0) -> decltype(executeAnimation(p0)) {
	using FunctionType = decltype(executeAnimation(p0))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22SpriteAnimationManager16executeAnimationESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto SpriteAnimationManager::finishAnimation(gd::string p0) -> decltype(finishAnimation(p0)) {
	using FunctionType = decltype(finishAnimation(p0))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22SpriteAnimationManager15finishAnimationESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto SpriteAnimationManager::getAnimType(gd::string p0) -> decltype(getAnimType(p0)) {
	using FunctionType = decltype(getAnimType(p0))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22SpriteAnimationManager11getAnimTypeESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto SpriteAnimationManager::getPrio(gd::string p0) -> decltype(getPrio(p0)) {
	using FunctionType = decltype(getPrio(p0))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22SpriteAnimationManager7getPrioESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto SpriteAnimationManager::initWithOwner(CCAnimatedSprite* p0, gd::string p1) -> decltype(initWithOwner(p0, p1)) {
	using FunctionType = decltype(initWithOwner(p0, p1))(*)(SpriteAnimationManager*, CCAnimatedSprite*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22SpriteAnimationManager13initWithOwnerEP16CCAnimatedSpriteSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto SpriteAnimationManager::loadAnimations(gd::string p0) -> decltype(loadAnimations(p0)) {
	using FunctionType = decltype(loadAnimations(p0))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22SpriteAnimationManager14loadAnimationsESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto SpriteAnimationManager::playSound(gd::string p0) -> decltype(playSound(p0)) {
	using FunctionType = decltype(playSound(p0))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22SpriteAnimationManager9playSoundESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto SpriteAnimationManager::playSoundForAnimation(gd::string p0) -> decltype(playSoundForAnimation(p0)) {
	using FunctionType = decltype(playSoundForAnimation(p0))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22SpriteAnimationManager21playSoundForAnimationESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto SpriteAnimationManager::queueAnimation(gd::string p0) -> decltype(queueAnimation(p0)) {
	using FunctionType = decltype(queueAnimation(p0))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22SpriteAnimationManager14queueAnimationESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto SpriteAnimationManager::runAnimation(gd::string p0) -> decltype(runAnimation(p0)) {
	using FunctionType = decltype(runAnimation(p0))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22SpriteAnimationManager12runAnimationESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto SpriteAnimationManager::storeAnimation(cocos2d::CCAnimate* p0, cocos2d::CCAnimate* p1, gd::string p2, int p3, spriteMode p4, cocos2d::CCSpriteFrame* p5) -> decltype(storeAnimation(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(storeAnimation(p0, p1, p2, p3, p4, p5))(*)(SpriteAnimationManager*, cocos2d::CCAnimate*, cocos2d::CCAnimate*, gd::string, int, spriteMode, cocos2d::CCSpriteFrame*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22SpriteAnimationManager14storeAnimationEPN7cocos2d9CCAnimateES2_Ssi10spriteModePNS0_13CCSpriteFrameE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

auto SpriteAnimationManager::storeSoundForAnimation(cocos2d::CCString* p0, gd::string p1, float p2) -> decltype(storeSoundForAnimation(p0, p1, p2)) {
	using FunctionType = decltype(storeSoundForAnimation(p0, p1, p2))(*)(SpriteAnimationManager*, cocos2d::CCString*, gd::string, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22SpriteAnimationManager22storeSoundForAnimationEPN7cocos2d8CCStringESsf")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto SpriteAnimationManager::switchToFirstFrameOfAnimation(gd::string p0) -> decltype(switchToFirstFrameOfAnimation(p0)) {
	using FunctionType = decltype(switchToFirstFrameOfAnimation(p0))(*)(SpriteAnimationManager*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22SpriteAnimationManager29switchToFirstFrameOfAnimationESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

SpriteDescription::SpriteDescription() {
        m_position = cocos2d::CCPointMake(0.f, 0.f);
        m_scale = cocos2d::CCPointMake(0.f, 0.f);
        m_flipped = cocos2d::CCPointMake(0.f, 0.f);
        m_rotation = 0;
        m_zValue = 0;
        m_tag = 0;
        m_usesCustomTag = false;
        m_texture = nullptr;
    }

auto StarInfoPopup::createFromString(gd::string p0) -> decltype(createFromString(p0)) {
	using FunctionType = decltype(createFromString(p0))(*)(gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13StarInfoPopup16createFromStringESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto StarInfoPopup::createFromStringMoons(gd::string p0) -> decltype(createFromStringMoons(p0)) {
	using FunctionType = decltype(createFromStringMoons(p0))(*)(gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13StarInfoPopup21createFromStringMoonsESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto StartPosObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&StartPosObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(StartPosObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14StartPosObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto StartPosObject::loadSettingsFromString(gd::string p0) -> decltype(loadSettingsFromString(p0)) {
	using FunctionType = decltype(loadSettingsFromString(p0))(*)(StartPosObject*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14StartPosObject22loadSettingsFromStringESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

StatsCell::StatsCell(char const* p0, float p1, float p2) : StatsCell(geode::CutoffConstructor, sizeof(StatsCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	StatsCell::~StatsCell();
	using FunctionType = void(*)(StatsCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN9StatsCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto SupportLayer::createToggleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCMenu* p3, cocos2d::CCPoint p4, cocos2d::CCArray* p5) -> decltype(createToggleButton(p0, p1, p2, p3, p4, p5)) {
	using FunctionType = decltype(createToggleButton(p0, p1, p2, p3, p4, p5))(*)(SupportLayer*, gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint, cocos2d::CCArray*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12SupportLayer18createToggleButtonESsMN7cocos2d8CCObjectEFvPS1_EbPNS0_6CCMenuENS0_7CCPointEPNS0_7CCArrayE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5);
}

void TableView::scrllViewWillBeginDecelerating(CCScrollLayerExt* p0) {}

void TableView::scrollViewDidEndDecelerating(CCScrollLayerExt* p0) {}

void TableView::scrollViewTouchMoving(CCScrollLayerExt* p0) {}

void TableView::scrollViewDidEndMoving(CCScrollLayerExt* p0) {}

auto TeleportPortalObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&TeleportPortalObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(TeleportPortalObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20TeleportPortalObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto TextAlertPopup::create(gd::string text, float delay, float scale, int opacity, gd::string font) -> decltype(create(text, delay, scale, opacity, font)) {
	using FunctionType = decltype(create(text, delay, scale, opacity, font))(*)(gd::string, float, float, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14TextAlertPopup6createESsffiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(text, delay, scale, opacity, font);
}

auto TextAlertPopup::init(gd::string text, float delay, float scale, int opacity, gd::string font) -> decltype(init(text, delay, scale, opacity, font)) {
	using FunctionType = decltype(init(text, delay, scale, opacity, font))(*)(TextAlertPopup*, gd::string, float, float, int, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14TextAlertPopup4initESsffiSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, text, delay, scale, opacity, font);
}

auto TextArea::create(gd::string str, char const* font, float scale, float width, cocos2d::CCPoint anchor, float lineHeight, bool disableColor) -> decltype(create(str, font, scale, width, anchor, lineHeight, disableColor)) {
	using FunctionType = decltype(create(str, font, scale, width, anchor, lineHeight, disableColor))(*)(gd::string, char const*, float, float, cocos2d::CCPoint, float, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8TextArea6createESsPKcffN7cocos2d7CCPointEfb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(str, font, scale, width, anchor, lineHeight, disableColor);
}

void TextArea::draw() {}

auto TextArea::init(gd::string str, char const* font, float scale, float width, cocos2d::CCPoint anchor, float lineHeight, bool disableColor) -> decltype(init(str, font, scale, width, anchor, lineHeight, disableColor)) {
	using FunctionType = decltype(init(str, font, scale, width, anchor, lineHeight, disableColor))(*)(TextArea*, gd::string, char const*, float, float, cocos2d::CCPoint, float, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8TextArea4initESsPKcffN7cocos2d7CCPointEfb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, str, font, scale, width, anchor, lineHeight, disableColor);
}

auto TextArea::setString(gd::string p0) -> decltype(setString(p0)) {
	using FunctionType = decltype(setString(p0))(*)(TextArea*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN8TextArea9setStringESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

auto TextGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&TextGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(TextGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14TextGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto TextGameObject::updateTextObject(gd::string p0, bool p1) -> decltype(updateTextObject(p0, p1)) {
	using FunctionType = decltype(updateTextObject(p0, p1))(*)(TextGameObject*, gd::string, bool);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN14TextGameObject16updateTextObjectESsb")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto TimerTriggerGameObject::triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2) -> decltype(triggerObject(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*, int, gd::vector<int> const*>::func(&TimerTriggerGameObject::triggerObject), this);
	using FunctionType = decltype(triggerObject(p0, p1, p2))(*)(TimerTriggerGameObject*, GJBaseGameLayer*, int, gd::vector<int> const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22TimerTriggerGameObject13triggerObjectEP15GJBaseGameLayeriPKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto TimerTriggerGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&TimerTriggerGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(TimerTriggerGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN22TimerTriggerGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

TopArtistsLayer::TopArtistsLayer() {
        m_topArtists = nullptr;
        m_listLayer = nullptr;
        m_loadingCircle = nullptr;
        m_page = 0;
    }

auto TopArtistsLayer::setupPageInfo(gd::string p0, char const* p1) -> decltype(setupPageInfo(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::string, char const*>::func(&TopArtistsLayer::setupPageInfo), this);
	using FunctionType = decltype(setupPageInfo(p0, p1))(*)(TopArtistsLayer*, gd::string, char const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN15TopArtistsLayer13setupPageInfoESsPKc")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

void TOSPopup::keyBackClicked() {}

auto TransformTriggerGameObject::triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2) -> decltype(triggerObject(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*, int, gd::vector<int> const*>::func(&TransformTriggerGameObject::triggerObject), this);
	using FunctionType = decltype(triggerObject(p0, p1, p2))(*)(TransformTriggerGameObject*, GJBaseGameLayer*, int, gd::vector<int> const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN26TransformTriggerGameObject13triggerObjectEP15GJBaseGameLayeriPKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto TransformTriggerGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&TransformTriggerGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(TransformTriggerGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN26TransformTriggerGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto TriggerControlGameObject::triggerObject(GJBaseGameLayer* p0, int p1, gd::vector<int> const* p2) -> decltype(triggerObject(p0, p1, p2)) {
	auto self = addresser::thunkAdjust(Resolve<GJBaseGameLayer*, int, gd::vector<int> const*>::func(&TriggerControlGameObject::triggerObject), this);
	using FunctionType = decltype(triggerObject(p0, p1, p2))(*)(TriggerControlGameObject*, GJBaseGameLayer*, int, gd::vector<int> const*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN24TriggerControlGameObject13triggerObjectEP15GJBaseGameLayeriPKSt6vectorIiSaIiEE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1, p2);
}

auto TriggerControlGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&TriggerControlGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(TriggerControlGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN24TriggerControlGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

auto TutorialPopup::create(gd::string p0) -> decltype(create(p0)) {
	using FunctionType = decltype(create(p0))(*)(gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13TutorialPopup6createESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0);
}

auto TutorialPopup::init(gd::string p0) -> decltype(init(p0)) {
	using FunctionType = decltype(init(p0))(*)(TutorialPopup*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN13TutorialPopup4initESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0);
}

UILayer* UILayer::get() {
        if (auto gjbgl = GJBaseGameLayer::get()) return gjbgl->m_uiLayer;
        return nullptr;
    }

void UILayer::draw() {}

auto UISettingsGameObject::customObjectSetup(gd::vector<gd::string>& p0, gd::vector<void*>& p1) -> decltype(customObjectSetup(p0, p1)) {
	auto self = addresser::thunkAdjust(Resolve<gd::vector<gd::string>&, gd::vector<void*>&>::func(&UISettingsGameObject::customObjectSetup), this);
	using FunctionType = decltype(customObjectSetup(p0, p1))(*)(UISettingsGameObject*, gd::vector<gd::string>&, gd::vector<void*>&);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN20UISettingsGameObject17customObjectSetupERSt6vectorISsSaISsEERS0_IPvSaIS4_EE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(self, p0, p1);
}

UndoObject::UndoObject() {
        m_objectCopy = nullptr;
        m_objects = nullptr;
        // some of the floats are set to 1.0 but idk which who cares
    }

UndoObject::~UndoObject() {
        if (m_objectCopy) m_objectCopy->release();
        if (m_objects) m_objects->release();
    }

UndoObject* UndoObject::createWithArray(cocos2d::CCArray* arrOfObjects, UndoCommand command) {
        auto* ret = new UndoObject();
        if (ret->init(arrOfObjects, command)) {
            ret->autorelease();
            return ret;
        }
        delete ret;
        return nullptr;
    }

bool UndoObject::init(cocos2d::CCArray* array, UndoCommand command) {
        m_command = command;
        if (array != nullptr) {
            m_objects = cocos2d::CCArray::create();
            m_objects->addObjectsFromArray(array);
            m_objects->retain();
        }
        return true;
    }

auto UpdateAccountSettingsPopup::create(GJAccountSettingsLayer* p0, int p1, int p2, int p3, gd::string p4, gd::string p5, gd::string p6) -> decltype(create(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(create(p0, p1, p2, p3, p4, p5, p6))(*)(GJAccountSettingsLayer*, int, int, int, gd::string, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN26UpdateAccountSettingsPopup6createEP22GJAccountSettingsLayeriiiSsSsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1, p2, p3, p4, p5, p6);
}

auto UpdateAccountSettingsPopup::init(GJAccountSettingsLayer* p0, int p1, int p2, int p3, gd::string p4, gd::string p5, gd::string p6) -> decltype(init(p0, p1, p2, p3, p4, p5, p6)) {
	using FunctionType = decltype(init(p0, p1, p2, p3, p4, p5, p6))(*)(UpdateAccountSettingsPopup*, GJAccountSettingsLayer*, int, int, int, gd::string, gd::string, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN26UpdateAccountSettingsPopup4initEP22GJAccountSettingsLayeriiiSsSsSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6);
}

auto UploadActionPopup::create(UploadPopupDelegate* delegate, gd::string str) -> decltype(create(delegate, str)) {
	using FunctionType = decltype(create(delegate, str))(*)(UploadPopupDelegate*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17UploadActionPopup6createEP19UploadPopupDelegateSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(delegate, str);
}

auto UploadActionPopup::init(UploadPopupDelegate* delegate, gd::string str) -> decltype(init(delegate, str)) {
	using FunctionType = decltype(init(delegate, str))(*)(UploadActionPopup*, UploadPopupDelegate*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17UploadActionPopup4initEP19UploadPopupDelegateSs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, delegate, str);
}

auto UploadActionPopup::showFailMessage(gd::string message) -> decltype(showFailMessage(message)) {
	using FunctionType = decltype(showFailMessage(message))(*)(UploadActionPopup*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17UploadActionPopup15showFailMessageESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, message);
}

auto UploadActionPopup::showSuccessMessage(gd::string message) -> decltype(showSuccessMessage(message)) {
	using FunctionType = decltype(showSuccessMessage(message))(*)(UploadActionPopup*, gd::string);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17UploadActionPopup18showSuccessMessageESs")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, message);
}

void UploadListPopup::keyBackClicked() {}

void UploadPopup::keyBackClicked() {}

URLCell::URLCell(char const* p0, float p1, float p2) : URLCell(geode::CutoffConstructor, sizeof(URLCell)) {
	// here we construct it as normal as we can, then destruct it
	// using the generated functions. this ensures no memory gets leaked
	// no crashes :pray:
	CCDestructor::lock(this) = true;
	URLCell::~URLCell();
	using FunctionType = void(*)(URLCell*, char const*, float, float);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN7URLCellC2EPKcff")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	reinterpret_cast<FunctionType>(func)(this, p0, p1, p2);
}

auto URLViewLayer::create(gd::string p0, cocos2d::CCArray* p1) -> decltype(create(p0, p1)) {
	using FunctionType = decltype(create(p0, p1))(*)(gd::string, cocos2d::CCArray*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12URLViewLayer6createESsPN7cocos2d7CCArrayE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(p0, p1);
}

auto URLViewLayer::init(gd::string p0, cocos2d::CCArray* p1) -> decltype(init(p0, p1)) {
	using FunctionType = decltype(init(p0, p1))(*)(URLViewLayer*, gd::string, cocos2d::CCArray*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN12URLViewLayer4initESsPN7cocos2d7CCArrayE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1);
}

auto VideoOptionsLayer::createToggleButton(gd::string p0, cocos2d::SEL_MenuHandler p1, bool p2, cocos2d::CCMenu* p3, cocos2d::CCPoint p4, float p5, float p6, bool p7, cocos2d::CCArray* p8) -> decltype(createToggleButton(p0, p1, p2, p3, p4, p5, p6, p7, p8)) {
	using FunctionType = decltype(createToggleButton(p0, p1, p2, p3, p4, p5, p6, p7, p8))(*)(VideoOptionsLayer*, gd::string, cocos2d::SEL_MenuHandler, bool, cocos2d::CCMenu*, cocos2d::CCPoint, float, float, bool, cocos2d::CCArray*);
	static auto func = wrapFunction(reinterpret_cast<uintptr_t>(dlsym(dlopen("libcocos2dcpp.so", RTLD_NOW), "_ZN17VideoOptionsLayer18createToggleButtonESsMN7cocos2d8CCObjectEFvPS1_EbPNS0_6CCMenuENS0_7CCPointEffbPNS0_7CCArrayE")), tulip::hook::WrapperMetadata{
		.m_convention = geode::hook::createConvention(tulip::hook::TulipConvention::Default),
		.m_abstract = tulip::hook::AbstractFunction::from(FunctionType(nullptr)),
	});
	return reinterpret_cast<FunctionType>(func)(this, p0, p1, p2, p3, p4, p5, p6, p7, p8);
}
