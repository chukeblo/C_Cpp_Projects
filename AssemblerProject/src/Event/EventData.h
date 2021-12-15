#pragma once

#include "EventType.h"

class EventData
{
private:
	EventType event_type_;
	void* result_data_;
public:
	EventData(EventType type);
	EventData(EventType type, void* data);
	EventType GetEventType();
	void* GetResultData();
};

