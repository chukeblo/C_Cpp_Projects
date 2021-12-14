#include "WritingState.h"

void WritingState::HandleEvent(EventData* data)
{
	switch (data->GetEventType())
	{
	default:
		StateBase::HandleEvent(data);
		break;
	}
}
