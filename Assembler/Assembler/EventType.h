#pragma once
enum class EventType {
	Unknown,
	EnteredIdleState,
	HasFileToAssemble,
	NoFileLeftToAssemble,
	EnteredInitializeState,
	UserInputCompleted,
	FinishedReading,
	FinishedWriting,
	ShowedAssembleResult,
	FinalizeCompleted,
	StateChangeRequested,
	ErrorOccurred
};