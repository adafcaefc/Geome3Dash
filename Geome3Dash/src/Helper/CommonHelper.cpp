#include "pch.h"

#include "CommonHelper.h"

namespace g3d
{
	namespace utils
	{
        std::string read_from_file(
            const std::filesystem::path& path)
        {
            if (!std::filesystem::exists(path)) { return std::string(); }
            std::ifstream input(path);
            if (!input.is_open()) { return std::string(); }
            std::stringstream buffer;
            buffer << input.rdbuf();
            input.close();
            return buffer.str();
        }

        bool write_to_file(
            const std::filesystem::path& path,
            const std::string& data)
        {
            std::ofstream output(path);
            if (!output.is_open()) { return false; }
            output << data;
            return true;
        }

        void replace_all(
            std::string& str,
            const std::string& from,
            const std::string& to)
        {
            if (from.empty()) { return; }
            size_t start_pos = 0;
            while ((start_pos = str.find(from, start_pos)) != std::string::npos)
            {
                str.replace(start_pos, from.length(), to);
                start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
            }
        }
	}
}