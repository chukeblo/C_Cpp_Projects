#pragma once

#include <queue>
#include "EventData.h"

class EventHandler
{
private:
	std::queue<EventData*> event_queue_;
public:
	static EventHandler* GetInstance();
	void Enqueue(EventData* event_data);
	EventData* Dequeue();
};

