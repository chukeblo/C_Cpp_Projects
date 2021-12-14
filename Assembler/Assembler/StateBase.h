#pragma once

#include "EventData.h"
#include "EventHandler.h"
#include "StateType.h"

class StateBase
{
public:
	virtual ~StateBase() {}
	virtual void Initialize() {}
	virtual void Finalize() {}
	virtual void HandleEvent(EventData* data);
	static StateBase* GetInstance(StateType type);
};

