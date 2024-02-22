#pragma once

#include <cstdint>
#include <expected>
#include <filesystem>
#include <fstream>

namespace NSFs {
	namespace fs = std::filesystem;

	using CPath = fs::path;
	using CFilesystemError = fs::filesystem_error;
	using CDirectoryEntry = fs::directory_entry;
	using CDirectoryIterator = fs::directory_iterator;
	using CRecursiveDirectoryIterator = fs::recursive_directory_iterator;
	using CFileStatus = fs::file_status;
	using CSpaceInfo = fs::space_info;
	using CFileType = fs::file_type;
	using CPerms = fs::perms;
	using CPermOptions = fs::perm_options;
	using CCopyOptions = fs::copy_options;
	using CDirectoryOptions = fs::directory_options;
	using CFileTimeType = fs::file_time_type;

	std::expected<CPath, std::error_code> Absolute(const CPath& p);

	std::expected<CPath, std::error_code> Canonical(const CPath& p);
	std::expected<CPath, std::error_code> WeaklyCanonical(const CPath& p);

	std::expected<CPath, std::error_code> Relative(const CPath& p, const CPath& base);
	std::expected<CPath, std::error_code> Proximate(const CPath& p, const CPath& base = fs::current_path());

	std::expected<void, std::error_code> Copy(const CPath& from, const CPath& to, CCopyOptions options = CCopyOptions::none);

	std::expected<void, std::error_code> CopyFile(const CPath& from, const CPath& to, CCopyOptions options = CCopyOptions::none);

	std::expected<void, std::error_code> CopySymlink(const CPath& existingSymlink, const CPath& newSymlink);

	std::expected<void, std::error_code> CreateDirectory(const CPath& p);
	std::expected<void, std::error_code> CreateDirectories(const CPath& p);

	std::expected<void, std::error_code> CreateHardLink(const CPath& to, const CPath& newHardLink);

	std::expected<void, std::error_code> CreateSymlink(const CPath& to, const CPath& newSymlink);
	std::expected<void, std::error_code> CreateDirectorySymlink(const CPath& to, const CPath& newSymlink);

	std::expected<CPath, std::error_code> CurrentPath();

	std::expected<bool, std::error_code> Exists(const CPath& p);

	std::expected<bool, std::error_code> Equivalent(const CPath& p1, const CPath& p2);

	std::expected<std::uintmax_t, std::error_code> FileSize(const CPath& p);

	std::expected<std::uintmax_t, std::error_code> HardLinkCount(const CPath& p);

	std::expected<CFileTimeType, std::error_code> LastWriteTime(const CPath& p);
	std::expected<void, std::error_code> LastWriteTime(const CPath& p, const CFileTimeType& newTime);

	std::expected<CPerms, std::error_code> Permissions(const CPath& p);

	std::expected<CPath, std::error_code> ReadSymlink(const CPath& p);

	std::expected<void, std::error_code> Remove(const CPath& p);
	std::expected<std::uintmax_t, std::error_code> RemoveAll(const CPath& p);

	std::expected<void, std::error_code> Rename(const CPath& oldP, const CPath& newP);

	std::expected<void, std::error_code> ResizeFile(const CPath& p, std::uintmax_t newSize);

	std::expected<CSpaceInfo, std::error_code> Space(const CPath& p);

	std::expected<CFileStatus, std::error_code> Status(const CPath& p);
	std::expected<CFileStatus, std::error_code> SymlinkStatus(const CPath& p);

	std::expected<CPath, std::error_code> TempDirectoryPath();

	std::expected<bool, std::error_code> IsBlockFile(const CPath& p);

	std::expected<bool, std::error_code> IsCharacterFile(const CPath& p);

	std::expected<bool, std::error_code> IsDirectory(const CPath& p);

	std::expected<bool, std::error_code> IsEmpty(const CPath& p);

	std::expected<bool, std::error_code> IsFifo(const CPath& p);

	std::expected<bool, std::error_code> IsOther(const CPath& p);

	std::expected<bool, std::error_code> IsRegularFile(const CPath& p);

	std::expected<bool, std::error_code> IsSocket(const CPath& p);

	std::expected<bool, std::error_code> IsSymlink(const CPath& p);

	std::expected<bool, std::error_code> StatusKnown(const CFileStatus& status);

	template <typename Container>
	std::expected<Container, std::error_code> ReadFile(const CPath& p) {
		std::error_code ec;
		std::ifstream file(p, std::ios::binary);
		if (!file.is_open()) {
			ec = std::make_error_code(std::errc::no_such_file_or_directory);
			return std::unexpected(ec);
		}

		file.seekg(0, std::ios::end);
		std::streamsize size = file.tellg();
		file.seekg(0, std::ios::beg);

		Container content;
		content.resize(size);
		file.read(reinterpret_cast<char*>(content.data()), size);
		file.close();

		if (file.fail()) {
			ec = std::make_error_code(std::errc::io_error);
			return std::unexpected(ec);
		}

		return content;
	}

	template <typename Container>
	std::expected<void, std::error_code> WriteFile(const CPath& p, const Container& content) {
		std::error_code ec;
		std::ofstream file(p, std::ios::binary);
		if (!file.is_open()) {
			ec = std::make_error_code(std::errc::permission_denied);
			return std::unexpected(ec);
		}

		file.write(reinterpret_cast<const char*>(content.data()), content.size());
		file.close();

		if (file.fail()) {
			ec = std::make_error_code(std::errc::io_error);
			return std::unexpected(ec);
		}

		return {};
	}

	template <typename Container>
	std::expected<void, std::error_code> AppendFile(const CPath& p, const Container& content) {
		std::error_code ec;
		std::ofstream file(p, std::ios::binary | std::ios::app);
		if (!file.is_open()) {
			ec = std::make_error_code(std::errc::permission_denied);
			return std::unexpected(ec);
		}

		file.write(reinterpret_cast<const char*>(content.data()), content.size());
		file.close();

		if (file.fail()) {
			ec = std::make_error_code(std::errc::io_error);
			return std::unexpected(ec);
		}

		return {};
	}
};
