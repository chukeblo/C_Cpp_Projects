#pragma once

#include "StateBase.h"

class ShowingResultState : public StateBase
{
public:
	virtual void HandleEvent(EventData* data);
};

