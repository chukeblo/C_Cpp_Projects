#include "ConsoleIOManager.h"

#include <iostream>
#include "Logger.h"

static const std::string AnswerYes = "y";
static const std::string AnswerNo = "n";
static const std::string AskSourceFileNameMessage = "Input source file name: ";
static const std::string AskBinaryFileNameMessage = "Input binary file name: ";
static const int MaxRetryCounts = 3;

void ConsoleIOManager::HandleEvent(EventData* data)
{
    switch (data->GetEventType()) {
	case EventType::EnteredIdleState:
		AskUserToAssemble();
		break;
	case EventType::EnteredInitializeState:
		AskForSourceFileName();
		break;
	case EventType::SourceFileNameEnrolled:
		AskForBinaryFileName();
		break;
    default:
        break;
    }
}

std::string* ConsoleIOManager::WaitForComfirmedUserInput(std::string message)
{
	std::string input;
	std::string answer;
	int retry_counts = 0;
	do {
		if (retry_counts++ > MaxRetryCounts) {
			break;
		}
		std::cout << message;
		std::cin >> input;
		std::cout << "Confirm your input? [" + input + "] (y, n) : ";
		std::cin >> answer;
	} while (answer != AnswerYes && answer != AnswerNo);
	return new std::string(input);
}

void ConsoleIOManager::AskUserToAssemble()
{
	std::cout << "Start Assembler Application" << std::endl;

	std::cout << "Do you have any file to assemble? (y, n) : ";
	std::string answer;
	do {
		std::cin >> answer;
	} while (answer != AnswerYes && answer != AnswerNo);

	EventType type;
	if (answer == AnswerYes) {
		type = EventType::HasFileToAssemble;
	}
	else {
		type = EventType::NoFileLeftToAssemble;
	}

	EventHandler::GetInstance()->Enqueue(new EventData(type));
}

void ConsoleIOManager::AskForSourceFileName()
{
	source_file_name_ = WaitForComfirmedUserInput(AskSourceFileNameMessage);

	Logger::LogDebug(ComponentName::ConsoleIOManager, MethodName::AskForSourceFileName,
		"source file = " + *source_file_name_);

	EventHandler::GetInstance()->Enqueue(new EventData(EventType::SourceFileNameEnrolled));
}

void ConsoleIOManager::AskForBinaryFileName()
{
	binary_file_name_ = WaitForComfirmedUserInput(AskBinaryFileNameMessage);

	Logger::LogDebug(ComponentName::ConsoleIOManager, MethodName::AskForBinaryFileName,
		"binary file = " + *binary_file_name_);
}
