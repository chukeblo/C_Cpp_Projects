#pragma once

#include "StateBase.h"

class ReadingState : public StateBase
{
public:
	virtual void HandleEvent(EventData *data);
};
