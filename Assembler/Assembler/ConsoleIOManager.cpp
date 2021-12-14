#include "ConsoleIOManager.h"

#include <iostream>
#include <string>

static const std::string AnswerYes = "y";
static const std::string AnswerNo = "n";

void ConsoleIOManager::HandleEvent(EventData* data)
{
    switch (data->GetEventType()) {
	case EventType::EnteredIdleState:
		AskUserToAssemble();
		break;
	case EventType::HasFileToAssemble:
		break;
    default:
        break;
    }
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
