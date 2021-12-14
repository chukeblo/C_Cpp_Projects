#include "EventHandler.h"

#include <iostream>

EventHandler* EventHandler::GetInstance()
{
	static EventHandler* instance = nullptr;
	if (!instance) {
		instance = new EventHandler();
	}
	return instance;
}

void EventHandler::Enqueue(EventData* event_data)
{
	std::cout << "EventHandler::Enqueue() EventType=" << (int)(event_data->GetEventType()) << std::endl;
	event_queue_.push(event_data);
}

EventData* EventHandler::Dequeue()
{
	if (event_queue_.empty()) {
		return new EventData(EventType::Unknown);
	}
	EventData* data = event_queue_.front();
	printf("EventHandler::Dequeue() EventType=%d\n", data->GetEventType());
	event_queue_.pop();
	return data;
}
