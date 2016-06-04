#pragma once
#include <fstream>
#include <string>

class Debug
{
public:
	static void Log(const char * text);
	static void Log(const std::string text);
	static void Log(const int & val);
	static void Log(const float & val);
	static void Log(const double & val);
};

