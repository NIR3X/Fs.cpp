#include "Fs.h"

using namespace NSFs;

std::expected<CPath, std::error_code> NSFs::Absolute(const CPath& p) {
	std::error_code ec;
	CPath absolutePath = fs::absolute(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return absolutePath;
}

std::expected<CPath, std::error_code> NSFs::Canonical(const CPath& p) {
	std::error_code ec;
	CPath canonicalPath = fs::canonical(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return canonicalPath;
}

std::expected<CPath, std::error_code> NSFs::WeaklyCanonical(const CPath& p) {
	std::error_code ec;
	CPath weaklyCanonicalPath = fs::weakly_canonical(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return weaklyCanonicalPath;
}

std::expected<CPath, std::error_code> NSFs::Relative(const CPath& p, const CPath& base) {
	std::error_code ec;
	CPath relativePath = fs::relative(p, base, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return relativePath;
}

std::expected<CPath, std::error_code> NSFs::Proximate(const CPath& p, const CPath& base) {
	std::error_code ec;
	CPath proximatePath = fs::proximate(p, base, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return proximatePath;
}

std::expected<void, std::error_code> NSFs::Copy(const CPath& from, const CPath& to, CCopyOptions options) {
	std::error_code ec;
	fs::copy(from, to, options, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return {};
}

std::expected<void, std::error_code> NSFs::CopyFile(const CPath& from, const CPath& to, CCopyOptions options) {
	std::error_code ec;
	fs::copy_file(from, to, options, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return {};
}

std::expected<void, std::error_code> NSFs::CopySymlink(const CPath& existingSymlink, const CPath& newSymlink) {
	std::error_code ec;
	fs::copy_symlink(existingSymlink, newSymlink, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return {};
}

std::expected<void, std::error_code> NSFs::CreateDirectory(const CPath& p) {
	std::error_code ec;
	fs::create_directory(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return {};
}

std::expected<void, std::error_code> NSFs::CreateDirectories(const CPath& p) {
	std::error_code ec;
	fs::create_directories(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return {};
}

std::expected<void, std::error_code> NSFs::CreateHardLink(const CPath& to, const CPath& newHardLink) {
	std::error_code ec;
	fs::create_hard_link(to, newHardLink, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return {};
}

std::expected<void, std::error_code> NSFs::CreateSymlink(const CPath& to, const CPath& newSymlink) {
	std::error_code ec;
	fs::create_symlink(to, newSymlink, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return {};
}

std::expected<void, std::error_code> NSFs::CreateDirectorySymlink(const CPath& to, const CPath& newSymlink) {
	std::error_code ec;
	fs::create_directory_symlink(to, newSymlink, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return {};
}

std::expected<CPath, std::error_code> NSFs::CurrentPath() {
	std::error_code ec;
	CPath currentPath = fs::current_path(ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return currentPath;
}

std::expected<bool, std::error_code> NSFs::Exists(const CPath& p) {
	std::error_code ec;
	bool exists = fs::exists(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return exists;
}

std::expected<bool, std::error_code> NSFs::Equivalent(const CPath& p1, const CPath& p2) {
	std::error_code ec;
	bool equivalent = fs::equivalent(p1, p2, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return equivalent;
}

std::expected<std::uintmax_t, std::error_code> NSFs::FileSize(const CPath& p) {
	std::error_code ec;
	std::uintmax_t size = fs::file_size(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return size;
}

std::expected<std::uintmax_t, std::error_code> NSFs::HardLinkCount(const CPath& p) {
	std::error_code ec;
	std::uintmax_t count = fs::hard_link_count(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return count;
}

std::expected<CFileTimeType, std::error_code> NSFs::LastWriteTime(const CPath& p) {
	std::error_code ec;
	CFileTimeType lastWriteTime = fs::last_write_time(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return lastWriteTime;
}

std::expected<void, std::error_code> NSFs::LastWriteTime(const CPath& p, const CFileTimeType& newTime) {
	std::error_code ec;
	fs::last_write_time(p, newTime, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return {};
}

std::expected<CPerms, std::error_code> NSFs::Permissions(const CPath& p) {
	std::error_code ec;
	CPerms permissions = fs::status(p, ec).permissions();
	if (ec) {
		return std::unexpected(ec);
	}
	return permissions;
}

std::expected<CPath, std::error_code> NSFs::ReadSymlink(const CPath& p) {
	std::error_code ec;
	CPath symlinkPath = fs::read_symlink(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return symlinkPath;
}

std::expected<void, std::error_code> NSFs::Remove(const CPath& p) {
	std::error_code ec;
	fs::remove(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return {};
}

std::expected<std::uintmax_t, std::error_code> NSFs::RemoveAll(const CPath& p) {
	std::error_code ec;
	std::uintmax_t count = fs::remove_all(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return count;
}

std::expected<void, std::error_code> NSFs::Rename(const CPath& oldP, const CPath& newP) {
	std::error_code ec;
	fs::rename(oldP, newP, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return {};
}

std::expected<void, std::error_code> NSFs::ResizeFile(const CPath& p, std::uintmax_t newSize) {
	std::error_code ec;
	fs::resize_file(p, newSize, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return {};
}

std::expected<CSpaceInfo, std::error_code> NSFs::Space(const CPath& p) {
	std::error_code ec;
	CSpaceInfo spaceInfo = fs::space(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return spaceInfo;
}

std::expected<CFileStatus, std::error_code> NSFs::Status(const CPath& p) {
	std::error_code ec;
	CFileStatus status = fs::status(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return status;
}

std::expected<CFileStatus, std::error_code> NSFs::SymlinkStatus(const CPath& p) {
	std::error_code ec;
	CFileStatus status = fs::symlink_status(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return status;
}

std::expected<CPath, std::error_code> NSFs::TempDirectoryPath() {
	std::error_code ec;
	CPath tempDirPath = fs::temp_directory_path(ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return tempDirPath;
}

std::expected<bool, std::error_code> NSFs::IsBlockFile(const CPath& p) {
	std::error_code ec;
	bool isBlockFile = fs::is_block_file(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return isBlockFile;
}

std::expected<bool, std::error_code> NSFs::IsCharacterFile(const CPath& p) {
	std::error_code ec;
	bool isCharacterFile = fs::is_character_file(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return isCharacterFile;
}

std::expected<bool, std::error_code> NSFs::IsDirectory(const CPath& p) {
	std::error_code ec;
	bool isDirectory = fs::is_directory(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return isDirectory;
}

std::expected<bool, std::error_code> NSFs::IsEmpty(const CPath& p) {
	std::error_code ec;
	bool isEmpty = fs::is_empty(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return isEmpty;
}

std::expected<bool, std::error_code> NSFs::IsFifo(const CPath& p) {
	std::error_code ec;
	bool isFifo = fs::is_fifo(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return isFifo;
}

std::expected<bool, std::error_code> NSFs::IsOther(const CPath& p) {
	std::error_code ec;
	bool isOther = fs::is_other(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return isOther;
}

std::expected<bool, std::error_code> NSFs::IsRegularFile(const CPath& p) {
	std::error_code ec;
	bool isRegularFile = fs::is_regular_file(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return isRegularFile;
}

std::expected<bool, std::error_code> NSFs::IsSocket(const CPath& p) {
	std::error_code ec;
	bool isSocket = fs::is_socket(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return isSocket;
}

std::expected<bool, std::error_code> NSFs::IsSymlink(const CPath& p) {
	std::error_code ec;
	bool isSymlink = fs::is_symlink(p, ec);
	if (ec) {
		return std::unexpected(ec);
	}
	return isSymlink;
}

std::expected<bool, std::error_code> NSFs::StatusKnown(const CFileStatus& status) {
	bool statusKnown = fs::status_known(status);
	return statusKnown;
}
