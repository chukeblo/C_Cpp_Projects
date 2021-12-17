#include "include/ShowingResultState.h"

void ShowingResultState::HandleEvent(EventData *data)
{
	switch (data->GetEventType())
	{
	case EventType::ErrorOccurred:
		DisplayResult((ResultData *)data->GetResultData());
		break;
	default:
		StateBase::HandleEvent(data);
		break;
	}
}

void ShowingResultState::DisplayResult(ResultData *result)
{
}