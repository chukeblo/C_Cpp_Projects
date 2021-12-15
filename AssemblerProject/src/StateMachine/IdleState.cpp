#include "include/IdleState.h"

#include "../IOManager/include/IOManagerBase.h"

void IdleState::Initialize()
{
	EventHandler::GetInstance()->Enqueue(new EventData(EventType::EnteredIdleState));
}

void IdleState::HandleEvent(EventData* data)
{
	switch (data->GetEventType())
	{
	case EventType::EnteredIdleState:
		IOManagerBase::GetInstance(IOType::Console)->HandleEvent(data);
		break;
	case EventType::HasFileToAssemble:
		EventHandler::GetInstance()->Enqueue(new EventData(EventType::StateChangeRequested,
			(void*)StateBase::GetInstance(StateType::Initialize)));
		break;
	case EventType::NoFileLeftToAssemble:
		EventHandler::GetInstance()->Enqueue(new EventData(EventType::StateChangeRequested,
			(void*)StateBase::GetInstance(StateType::Finalize)));
		break;
	default:
		StateBase::HandleEvent(data);
		break;
	}
}
