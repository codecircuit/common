#pragma once
#include <string>
template <class IntType>
void commandLineGetInt(IntType* p, const std::string& key, int argc,
                       char* argv[]) {
	for (int i = 1; i < argc; ++i) {
		if (std::string(argv[i]) == key) {
			*p = std::stoll(argv[i + 1]);
			break;
		}
	}
}

void commandLineGetFloat(float* p, const std::string& key, int argc,
                         char* argv[]) {
	for (int i = 1; i < argc; ++i) {
		if (std::string(argv[i]) == key) {
			*p = std::stof(argv[i + 1]);
			break;
		}
	}
}

void commandLineGetString(std::string* s, const std::string& key,
                          int argc, char* argv[]) {
	for (int i = 1; i < argc; ++i) {
		if (std::string(argv[i]) == key) {
			*s = argv[i + 1];
			break;
		}
	}
}

void commandLineGetBool(bool* p, const std::string& key, int argc,
                        char* argv[]) {
	for (int i = 1; i < argc; ++i) {
		if (std::string(argv[i]) == key) {
			*p = true;
			break;
		}
	}
}
