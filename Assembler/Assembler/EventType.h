#pragma once
enum class EventType {
	Empty,
	EnteredIdleState,
	HasFileToAssemble,
	NoFileLeftToAssemble,
	EnteredInitializeState,
	SourceFileNameEnrolled,
	UserInputCompleted,
	FinishedReading,
	FinishedWriting,
	ShowedAssembleResult,
	FinalizeCompleted,
	StateChangeRequested,
	ErrorOccurred
};