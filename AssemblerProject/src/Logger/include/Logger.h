#pragma once

#include <iostream>
#include <string>
#include "MessageConstants.h"

class Logger
{
public:
	static void LogInfo(std::string component_name, std::string method_name, std::string message);
	static void LogDebug(std::string component_name, std::string method_name, std::string message);
	static void LogWarning(std::string component_name, std::string method_name, std::string message);
	static void LogError(std::string component_name, std::string method_name, std::string message);

private:
	static void Log(std::string log_level, std::string component_name, std::string method_name, std::string message);
};
