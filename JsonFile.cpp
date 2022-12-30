#include "JsonFile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

JsonFile::JsonFile(const char* file) {
	this->File = file;
}

json JsonFile::ReadFile() {
	std::string line;
	std::string data;

	std::ifstream in(this->File);

	if (in.is_open())
		while (getline(in, line))
			data += line;

	in.close();

	return json::parse(data);
}