#pragma once

#include <optional>
#include <Geode/Result.hpp>
#include <Geode/utils/general.hpp>
#include <Geode/utils/cocos.hpp>
#include <Geode/binding/GJGameLevel.hpp>

#ifdef GEODE_IS_WINDOWS
    #ifdef HJFOD_GMDAPI_EXPORTING
        #define GMDAPI_DLL __declspec(dllexport)
    #else
        #define GMDAPI_DLL __declspec(dllimport)
    #endif
#else
    #define GMDAPI_DLL __attribute__((visibility("default")))
#endif

namespace gmd {
    class ImportGmdFile;
    class ExportGmdFile;

    enum class GmdFileType {
        /**
         * Lvl contains the level data as a Plist string with GZip-compression 
         * applied. A fully obsolete format, supported for basically no reason 
         * other than that it can be 
         */
        Lvl,
        /**
         * Gmd contains the level data as a basic Plist string
         */
        Gmd,
        /**
         * Gmd2 is a Zip file that contains the level data in Gmd format 
         * under level.data, plus metadata under level.meta. May also include 
         * the level's song file in the package
         * @note Old GDShare implementations supported compression schemes in 
         * Gmd2 - those are not supported in GMD-API due to being completely 
         * redundant
         */
        Gmd2,
    };
    enum class GmdListFileType {
        /**
         * Gmdl contains the list data as a basic Plist string
         */
        Gmdl,
    };

    constexpr auto DEFAULT_GMD_TYPE = GmdFileType::Gmd;
    constexpr auto DEFAULT_GMD_LIST_TYPE = GmdListFileType::Gmdl;
    constexpr auto GMD2_VERSION = 1;

    constexpr const char* gmdTypeToString(GmdFileType type) {
        switch (type) {
            case GmdFileType::Lvl:  return "lvl";
            case GmdFileType::Gmd:  return "gmd";
            case GmdFileType::Gmd2: return "gmd2";
            default:                return nullptr;
        }
    }
    constexpr std::optional<GmdFileType> gmdTypeFromString(const char* type) {
        using geode::utils::hash;
        switch (hash(type)) {
            case hash("lvl"):  return GmdFileType::Lvl;
            case hash("gmd"):  return GmdFileType::Gmd;
            case hash("gmd2"): return GmdFileType::Gmd2;
            default:           return std::nullopt;
        }
    }

    constexpr const char* gmdListTypeToString(GmdListFileType type) {
        switch (type) {
            case GmdListFileType::Gmdl: return "gmdl";
            default:                    return nullptr;
        }
    }
    constexpr std::optional<GmdListFileType> gmdListTypeFromString(const char* type) {
        using geode::utils::hash;
        switch (hash(type)) {
            case hash("gmdl"): return GmdListFileType::Gmdl;
            default:           return std::nullopt;
        }
    }

    enum class GmdFileKind {
        None,
        Level,
        List,
    };
    GMDAPI_DLL GmdFileKind getGmdFileKind(std::filesystem::path const& path);

    template<class T>
    class IGmdFile {
    protected:
        std::optional<GmdFileType> m_type;
    
    public:
        T& setType(GmdFileType type) {
            m_type = type;
            return *static_cast<T*>(this);
        }
    };

    /**
     * Class for working with importing levels as GMD files
     */
    class GMDAPI_DLL ImportGmdFile : public IGmdFile<ImportGmdFile> {
    protected:
        std::filesystem::path m_path;
        bool m_importSong = false;

        ImportGmdFile(std::filesystem::path const& path);

        geode::Result<std::string> getLevelData() const;

    public:
        /**
         * Create an ImportGmdFile instance from a file
         * @param path The file to import
         */
        static ImportGmdFile from(std::filesystem::path const& path);
        /**
         * Try to infer the file type from the file's path
         * @returns True if the type was inferred, false if not
         */
        bool tryInferType();
        /**
         * Try to infer the file type from the file's extension. If the 
         * extension is unknown, the type is inferred as DEFAULT_GMD_TYPE
        */
        ImportGmdFile& inferType();
        /**
         * Set whether to import the song file included in this file or not
         */
        ImportGmdFile& setImportSong(bool song);
        /**
         * Load the file and parse it into a GJGameLevel
         * @returns An Ok Result with the parsed level, or an Err with info
         * @note Does not add the level to the user's local created levels - 
         * the GJGameLevel will not be retained by anything!
         */
        geode::Result<GJGameLevel*> intoLevel() const;
    };

    /**
     * Class for working with exporting levels as GMD files
     */
    class GMDAPI_DLL ExportGmdFile : public IGmdFile<ExportGmdFile> {
    protected:
        GJGameLevel* m_level;
        bool m_includeSong = false;

        ExportGmdFile(GJGameLevel* level);

        geode::Result<std::string> getLevelData() const;

    public:
        /**
         * Create an ExportGmdFile instance for a level
         * @param path The level to export
         */
        static ExportGmdFile from(GJGameLevel* level);
        /**
         * Set whether to include the song file with the exported file or not 
         * @note Currently only supported in GMD2 files
         */
        ExportGmdFile& setIncludeSong(bool song);
        /**
         * Export the level into an in-stream byte array
         * @returns Ok Result with the byte data if succesful, Err otherwise
         */
        geode::Result<geode::ByteVector> intoBytes() const;
        /**
         * Export the level into a file
         * @param path The file to export into. Will be created if it doesn't 
         * exist yet
         * @returns Ok Result if exporting succeeded, Err otherwise
         */
        geode::Result<> intoFile(std::filesystem::path const& path) const;
    };

    /**
     * Export a level as a GMD file. For more control over the exporting 
     * options, use the ExportGmdFile class
     * @param level The level you want to export
     * @param to The path of the file to export to
     * @param type The type to export the level as
     * @returns Ok Result on success, Err on error
     */
    GMDAPI_DLL geode::Result<> exportLevelAsGmd(
        GJGameLevel* level,
        std::filesystem::path const& to,
        GmdFileType type = DEFAULT_GMD_TYPE
    );

    /**
     * Import a level from a GMD file. For more control over the importing 
     * options, use the ImportGmdFile class
     * @param from The path of the file to import. The path's extension is used 
     * to infer the type of the file to import - if the extension is unknown, 
     * DEFAULT_GMD_TYPE is assumed
     * @note The level is **not** added to the local created levels list 
     */
    GMDAPI_DLL geode::Result<GJGameLevel*> importGmdAsLevel(
        std::filesystem::path const& from
    );

    class GMDAPI_DLL ImportGmdList final {
    private:
        class Impl;
        std::unique_ptr<Impl> m_impl;

        ImportGmdList(std::filesystem::path const& path);

    public:
        static ImportGmdList from(std::filesystem::path const& path);
        ~ImportGmdList();

        ImportGmdList& setType(GmdListFileType type);

        geode::Result<geode::Ref<GJLevelList>> intoList();
    };

    class GMDAPI_DLL ExportGmdList final {
    private:
        class Impl;
        std::unique_ptr<Impl> m_impl;

        ExportGmdList(GJLevelList* list);

    public:
        static ExportGmdList from(GJLevelList* list);
        ~ExportGmdList();

        ExportGmdList& setType(GmdListFileType type);

        /**
         * Export the list into an in-stream byte array
         * @returns Ok Result with the byte data if succesful, Err otherwise
         */
        geode::Result<geode::ByteVector> intoBytes() const;
        /**
         * Export the list into a file
         * @param path The file to export into. Will be created if it doesn't 
         * exist yet
         * @returns Ok Result if exporting succeeded, Err otherwise
         */
        geode::Result<> intoFile(std::filesystem::path const& path) const;
    };

    /**
     * Export a list as a GMD file. For more control over the exporting 
     * options, use the ExportGmdFile class
     * @param list The list you want to export
     * @param to The path of the file to export to
     * @param type The type to export the level as
     * @returns Ok Result on success, Err on error
     */
    GMDAPI_DLL geode::Result<> exportListAsGmd(
        GJLevelList* list,
        std::filesystem::path const& to,
        GmdListFileType type = DEFAULT_GMD_LIST_TYPE
    );

    /**
     * Import a list from a GMD file. For more control over the importing 
     * options, use the ImportGmdFile class
     * @param from The path of the file to import. The path's extension is used 
     * to infer the type of the file to import - if the extension is unknown, 
     * DEFAULT_GMD_LIST_TYPE is assumed
     * @note The list is **not** added to the local created lists list 
     */
    GMDAPI_DLL geode::Result<geode::Ref<GJLevelList>> importGmdAsList(
        std::filesystem::path const& from
    );
}
