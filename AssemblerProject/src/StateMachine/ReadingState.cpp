#include "include/ReadingState.h"

void ReadingState::HandleEvent(EventData* data)
{
	switch (data->GetEventType())
	{
	default:
		StateBase::HandleEvent(data);
		break;
	}
}
