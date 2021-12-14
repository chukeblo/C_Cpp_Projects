#include "StateBase.h"

#include "AssemblingState.h"
#include "FinalizeState.h"
#include "IdleState.h"
#include "InitializeState.h"
#include "ReadingState.h"
#include "ShowingResultState.h"
#include "WritingState.h"

void StateBase::HandleEvent(EventData* data)
{
	switch (data->GetEventType()) {
	case EventType::ErrorOccurred:
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

