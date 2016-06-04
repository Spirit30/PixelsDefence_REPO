#include "Debug.h"

void Debug::Log(const char * text){

	fprintf(stderr, text);
}

void Debug::Log(const std::string text) {

	fprintf(stderr, text.c_str());
}

void Debug::Log(const int & val) {

	fprintf(stderr, std::to_string(val).c_str());
}

void Debug::Log(const float & val) {

	fprintf(stderr, std::to_string(val).c_str());
}

void Debug::Log(const double & val) {

	fprintf(stderr, std::to_string(val).c_str());
}
