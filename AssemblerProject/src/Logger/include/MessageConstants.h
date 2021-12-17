#pragma once

#include <string>
using namespace std;

namespace LogLevel
{
	// log level string list
	const string Info = "info";
	const string Debug = "debug";
	const string Warning = "warning";
	const string Error = "error";
}

namespace ComponentName
{
	// component name list
	// state machine
	const string StateManager = "StateManager";
	const string StateBase = "StateBase";
	const string IdleState = "IdleState";
	const string InitializeState = "InitializeState";
	const string ReadingState = "ReadingState";
	const string AssemblingState = "AssemblingState";
	const string WritingState = "WritingState";
	const string ShowingResultState = "ShowingResultState";
	const string FinalizeState = "FinalizeState";
	// event
	const string EventHandler = "EventHandler";
	// io manager
	const string IOManagerBase = "IOManagerBase";
	const string ConsoleIOManager = "ConsoleIOManager";
	const string FileIOManager = "FileIOManager";
}

namespace MethodName
{
	// general
	const string GetInstance = "GetInstance";
	const string HandleEvent = "HandleEvent";
	// state machine
	const string Initialize = "Initialize";
	const string Finalize = "Finalize";
	const string ChangeState = "ChangeState";
	// event
	const string Enqueue = "Enqueue";
	const string Dequeue = "Dequeue";
	// console io manager
	const string AskForSourceFileName = "AskForSourceFileName";
	const string AskForBinaryFileName = "AskForBinaryFileName";
	// file io manager
	const string CheckFilesAvailable = "CheckFilesAvailable";
}
