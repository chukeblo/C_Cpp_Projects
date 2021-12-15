#pragma once

#include "StateBase.h"

class WritingState : public StateBase
{
public:
    virtual void HandleEvent(EventData* data);
};

