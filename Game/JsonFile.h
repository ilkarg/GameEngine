#pragma once

#include <iostream>
#include <vector>
#include "json.hpp"

using json = nlohmann::json;

class JsonFile {
public:
	const char* File;

	JsonFile(const char* file);

	json ReadFile();
};