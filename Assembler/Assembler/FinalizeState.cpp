#include "FinalizeState.h"

void FinalizeState::HandleEvent(EventData* data)
{
	switch (data->GetEventType())
	{
	default:
		StateBase::HandleEvent(data);
		break;
	}
}
