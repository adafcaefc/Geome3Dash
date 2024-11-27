#include "pch.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <Geode/GeneratedSource.cpp>

#include <Geode/loader/Loader.hpp>
#include <Geode/loader/Mod.hpp>

namespace geode {
    /**
     * To bypass the need for cyclic dependencies,
     * this function does the exact same as Mod::get()
     * However, it can be externed, unlike Mod::get()
     * @returns Same thing Mod::get() returns
     */
    Mod* getMod() {
        return Mod::get();
    }
}

GEODE_API void geodeImplicitEntry() {
    // to make sure the instance is set into the sharedMod<> in load time
    (void)geode::getMod();
}

void  __cdecl geode::log::vlogImpl(
    struct geode::Severity,
    class geode::Mod*,
    class fmt::v10::basic_string_view<char>,
    class fmt::v10::basic_format_args<class fmt::v10::basic_format_context<class fmt::v10::appender, char>>)
{

}