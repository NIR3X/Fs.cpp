# Fs.cpp Library - A C++ Filesystem Utility Library

Fs.cpp is a C++ library providing a set of convenient functions for working with the filesystem. It aims to simplify common filesystem operations and provide error-handling using `std::expected`.

## Features

* **Filesystem Operations**: Perform various filesystem tasks such as file copy, symlink creation, directory operations, and more.
* **Error Handling**: Uses `std::expected` to handle errors and provide clear feedback.
* **Convenient API**: Designed for ease of use with straightforward functions for common filesystem tasks.

## Requirements

* C++23 or later.
* A compiler that supports the C++23 standard.

## Installation

To use this package, you can clone the repository and compile it using a C++ compiler:

```bash
git clone https://github.com/NIR3X/Fs.cpp
cd Fs.cpp
make
```

## Usage

Here's a simple example demonstrating the usage of the library:

```cpp
#include "Fs.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

int main() {
	// Example usage of Fs.cpp functions
	NSFs::CPath filePath = L"test.txt";
	std::string content = "Hello, World!";
	
	// Write content to file
	assert(NSFs::WriteFile(filePath, content).has_value());

	// Check if file exists
	auto exists = NSFs::Exists(filePath);
	assert(exists.has_value());
	assert(exists.value());

	// Check if it's a regular file
	auto isRegularFile = NSFs::IsRegularFile(filePath);
	assert(isRegularFile.has_value());
	assert(isRegularFile.value());

	// Read file content
	auto read = NSFs::ReadFile<std::vector<uint8_t>>(filePath);
	assert(read.has_value());
	assert(content == std::string(read.value().begin(), read.value().end()));

	// Remove the file
	assert(NSFs::Remove(filePath).has_value());

	// Verify removal
	exists = NSFs::Exists(filePath);
	assert(exists.has_value());
	assert(!exists.value());

	std::cout << "PASS" << std::endl;

	return 0;
}
```

## License

[![GNU AGPLv3 Image](https://www.gnu.org/graphics/agplv3-155x51.png)](https://www.gnu.org/licenses/agpl-3.0.html)

This program is Free Software: You can use, study share and improve it at your
will. Specifically you can redistribute and/or modify it under the terms of the
[GNU Affero General Public License](https://www.gnu.org/licenses/agpl-3.0.html) as
published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
