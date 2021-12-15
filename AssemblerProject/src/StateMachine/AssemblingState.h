#pragma once

#include "StateBase.h"

class AssemblingState : public StateBase
{
public:
	virtual void HandleEvent(EventData* data);
};

