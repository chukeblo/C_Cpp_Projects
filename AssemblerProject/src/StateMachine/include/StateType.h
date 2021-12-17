#pragma once

enum class StateType
{
	Idle,
	Initialize,
	Reading,
	Assembling,
	Writing,
	ShowingResult,
	Finalize
};