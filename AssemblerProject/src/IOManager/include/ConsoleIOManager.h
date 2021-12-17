#pragma once

#include "IOManagerBase.h"

class ConsoleIOManager : public IOManagerBase
{
public:
	ConsoleIOManager() {}
	~ConsoleIOManager() {}
	virtual void HandleEvent(EventData *data) override;

private:
	std::string *WaitForComfirmedUserInput(std::string message);
	void AskUserToAssemble();
	void AskForSourceFileName();
	void AskForBinaryFileName();
};
