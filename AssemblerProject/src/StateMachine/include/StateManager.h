#pragma once

#include <string>
#include "../../Event/include/EventData.h"
#include "StateBase.h"
#include "StateType.h"

class StateManager
{
private:
	StateBase *current_state_;
	void ChangeState(StateBase *type);
	std::string ExtractStateName(const char *original_typename);

public:
	void Initialize();
	void HandleEvent(EventData *data);
};
