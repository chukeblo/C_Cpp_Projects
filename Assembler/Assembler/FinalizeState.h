#pragma once

#include "StateBase.h"

class FinalizeState : public StateBase
{
public:
    virtual void HandleEvent(EventData* data);
};

