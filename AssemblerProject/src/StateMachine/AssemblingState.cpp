#include "include/AssemblingState.h"

void AssemblingState::HandleEvent(EventData *data)
{
	switch (data->GetEventType())
	{
	default:
		StateBase::HandleEvent(data);
		break;
	}
}
