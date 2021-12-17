#pragma once

#include "../../ResultData.h"
#include "StateBase.h"

class ShowingResultState : public StateBase
{
public:
	virtual void HandleEvent(EventData *data) override;

private:
	void DisplayResult(ResultData *result);
};
