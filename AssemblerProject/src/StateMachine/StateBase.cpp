#include "include/StateBase.h"

#include "include/AssemblingState.h"
#include "include/FinalizeState.h"
#include "include/IdleState.h"
#include "include/InitializeState.h"
#include "include/ReadingState.h"
#include "include/ShowingResultState.h"
#include "include/WritingState.h"

void StateBase::HandleEvent(EventData* data)
{
	switch (data->GetEventType()) {
	case EventType::ErrorOccurred:
		EventHandler::GetInstance()->Enqueue(
			new EventData(data));
		break;
	default:
		break;
	}
}

StateBase* StateBase::GetInstance(StateType type)
{
	switch (type) {
	case StateType::Idle:
		return new IdleState();
	case StateType::Initialize:
		return new InitializeState();
	case StateType::Reading:
		return new ReadingState();
	case StateType::Assembling:
		return new AssemblingState();
	case StateType::Writing:
		return new WritingState();
	case StateType::ShowingResult:
		return new ShowingResultState();
	case StateType::Finalize:
		return new FinalizeState();
	default:
		return nullptr;
	}
}

