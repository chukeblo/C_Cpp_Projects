#pragma once

enum class EventType
{
	Empty,
	EnteredIdleState,
	HasFileToAssemble,
	NoFileLeftToAssemble,
	EnteredInitializeState,
	SourceFileNameEnrolled,
	UserInputCompleted,
	BothFilesConfirmedAvailable,
	FinishedReading,
	FinishedWriting,
	ShowedAssembleResult,
	FinalizeCompleted,
	StateChangeRequested,
	ErrorOccurred
};