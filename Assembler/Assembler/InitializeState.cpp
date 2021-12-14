#include "InitializeState.h"

#include "IOManagerBase.h"

void InitializeState::Initialize()
{
	EventHandler::GetInstance()->Enqueue(new EventData(EventType::EnteredInitializeState));
}

void InitializeState::HandleEvent(EventData* data)
{
	switch (data->GetEventType())
	{
	case EventType::EnteredInitializeState:
		IOManagerBase::GetInstance(IOType::Console)->HandleEvent(data);
		break;
	default:
		StateBase::HandleEvent(data);
		break;
	}
}
