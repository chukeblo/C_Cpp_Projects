#include "include/InitializeState.h"

#include "../IOManager/include/IOManagerBase.h"
#include "../Logger/include/Logger.h"

void InitializeState::Initialize()
{
	EventHandler::GetInstance()->Enqueue(new EventData(EventType::EnteredInitializeState));
}

void InitializeState::HandleEvent(EventData *data)
{
	Logger::LogDebug(ComponentName::InitializeState, MethodName::HandleEvent,
					 "EventType = " + std::to_string((int)(data->GetEventType())));

	switch (data->GetEventType())
	{
	case EventType::EnteredInitializeState:
	case EventType::SourceFileNameEnrolled:
		IOManagerBase::GetInstance(IOType::Console)->HandleEvent(data);
		break;
	case EventType::UserInputCompleted:
		IOManagerBase::GetInstance(IOType::File)->HandleEvent(data);
		break;
	case EventType::BothFilesConfirmedAvailable:
		EventHandler::GetInstance()->Enqueue(
			new EventData(EventType::StateChangeRequested,
						  (void *)StateBase::GetInstance(StateType::Reading)));
	default:
		StateBase::HandleEvent(data);
		break;
	}
}
