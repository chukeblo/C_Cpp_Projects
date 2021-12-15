#include "include/Logger.h"

using namespace std;
using namespace LogLevel;

void Logger::LogInfo(string component_name, string method_name, string message)
{
	Log(Info, component_name, method_name, message);
}

void Logger::LogDebug(string component_name, string method_name, string message)
{
	Log(Debug, component_name, method_name, message);
}

void Logger::LogWarning(string component_name, string method_name, string message)
{
	Log(Warning, component_name, method_name, message);
}

void Logger::LogError(string component_name, string method_name, string message)
{
	Log(Error, component_name, method_name, message);
}

void Logger::Log(string log_level, string component_name, string method_name, string message)
{
	cout << "[" + log_level + "] " + component_name + "::" + method_name + "() " + message << endl;
}