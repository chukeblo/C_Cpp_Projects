#pragma once

#include "StateBase.h"

class IdleState : public StateBase
{
public:
	virtual void Initialize() override;
	virtual void HandleEvent(EventData* data) override;
};

