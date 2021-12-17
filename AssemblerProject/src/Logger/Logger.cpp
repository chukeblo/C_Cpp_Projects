#include "include/Logger.h"

void Logger::LogInfo(std::string component_name, std::string method_name, std::string message)
{
	Log(LogLevel::Info, component_name, method_name, message);
}

void Logger::LogDebug(std::string component_name, std::string method_name, std::string message)
{
	Log(LogLevel::Debug, component_name, method_name, message);
}

void Logger::LogWarning(std::string component_name, std::string method_name, std::string message)
{
	Log(LogLevel::Warning, component_name, method_name, message);
}

void Logger::LogError(std::string component_name, std::string method_name, std::string message)
{
	Log(LogLevel::Error, component_name, method_name, message);
}

void Logger::Log(std::string log_level, std::string component_name, std::string method_name, std::string message)
{
	cout << "[" + log_level + "] " + component_name + "::" + method_name + "() " + message << endl;
}