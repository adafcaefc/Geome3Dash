#include "pch.h"

#include "CommonHelper.h"

#include <shlobj.h>
#include <shlwapi.h>
#include <psapi.h>
#include <shlwapi.h>

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

        std::filesystem::path get_app_data_path()
        {
            PWSTR szPath = nullptr;

            if (!SUCCEEDED(SHGetKnownFolderPath(FOLDERID_RoamingAppData, NULL, NULL, &szPath)))
            {
                CoTaskMemFree(szPath);
                return std::filesystem::path();
            }

            std::filesystem::path path(szPath);
            CoTaskMemFree(szPath);

            return path.parent_path();
        }

        std::filesystem::path get_common_app_data_path()
        {
            TCHAR szPath[MAX_PATH];
            if (!SUCCEEDED(SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0, szPath)))
            {
                return std::filesystem::path();
            }
            return szPath;
        }

        std::filesystem::path get_executable_path()
        {
            char szFilePath[MAX_PATH + 1] = { 0 };
            GetModuleFileNameA(NULL, szFilePath, MAX_PATH);
            return szFilePath;
        }

        std::filesystem::path get_song_path()
        {
           return get_app_data_path() / "Local" / get_executable_path().filename().replace_extension();
        }
    }
}