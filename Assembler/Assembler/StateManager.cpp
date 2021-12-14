#include "StateManager.h"

#include <iostream>
#include "Logger.h"

static const int StateNameStartIndex = 6;

void StateManager::Initialize()
{
	current_state_ = StateBase::GetInstance(StateType::Idle);
	current_state_->Initialize();
}

void StateManager::HandleEvent(EventData* data)
{
	if (!current_state_) {
		Logger::LogError(ComponentName::StateManager, MethodName::HandleEvent,
			"current state is null!");
		return;
	}
	if (data->GetEventType() == EventType::StateChangeRequested) {
		ChangeState((StateBase*)data->GetResultData());
	}
	current_state_->HandleEvent(data);
	
}

std::string StateManager::ExtractStateName(const char* original_typename)
{
	return std::string(original_typename).substr(StateNameStartIndex);
}

void StateManager::ChangeState(StateBase* next_state)
{
	std::string current_state_name = ExtractStateName(typeid(*current_state_).name());
	std::string next_state_name = ExtractStateName(typeid(*next_state).name());
	Logger::LogInfo(ComponentName::StateManager, MethodName::ChangeState,
		"from " + current_state_name + " to " + next_state_name);

	current_state_->Finalize();
	delete current_state_;
	current_state_ = nullptr;
	current_state_ = next_state;
	current_state_->Initialize();
}
