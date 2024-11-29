#pragma once

#include <string>
#include <filesystem>

namespace g3d
{
	namespace utils
	{
        std::string read_from_file(
            const std::filesystem::path& path);
        bool write_to_file(
            const std::filesystem::path& path,
            const std::string& data);
        void replace_all(
            std::string& str,
            const std::string& from,
            const std::string& to);
	}
}