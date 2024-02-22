#include "Fs.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

int main() {
	NSFs::CPath filePath = L"test.txt";
	std::string content = "Hello, World!";
	assert(NSFs::WriteFile(filePath, content).has_value());

	auto exists = NSFs::Exists(filePath);
	assert(exists.has_value());
	assert(exists.value());

	auto isRegularFile = NSFs::IsRegularFile(filePath);
	assert(isRegularFile.has_value());
	assert(isRegularFile.value());

	auto isDirectory = NSFs::IsDirectory(filePath);
	assert(isDirectory.has_value());
	assert(!isDirectory.value());

	auto read = NSFs::ReadFile<std::vector<uint8_t>>(filePath);
	assert(read.has_value());
	assert(content == std::string(read.value().begin(), read.value().end()));

	assert(NSFs::Remove(filePath).has_value());

	exists = NSFs::Exists(filePath);
	assert(exists.has_value());
	assert(!exists.value());

	isRegularFile = NSFs::IsRegularFile(filePath);
	assert(!isRegularFile.has_value());

	isDirectory = NSFs::IsDirectory(filePath);
	assert(!isDirectory.has_value());

	std::cout << "PASS" << std::endl;
}
