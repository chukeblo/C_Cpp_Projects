#include "include/EventHandler.h"

#include <iostream>
#include "../Logger/include/Logger.h"

EventHandler *EventHandler::GetInstance()
{
	static EventHandler *instance = nullptr;
	if (!instance)
	{
		instance = new EventHandler();
	}
	return instance;
}

void EventHandler::Enqueue(EventData *event_data)
{
	Logger::LogDebug(ComponentName::EventHandler, MethodName::Enqueue,
					 "EventType = " + std::to_string((int)(event_data->GetEventType())));
	event_queue_.push(event_data);
}

EventData *EventHandler::Dequeue()
{
	if (event_queue_.empty())
	{
		return new EventData(EventType::Empty);
	}
	EventData *data = event_queue_.front();
	Logger::LogDebug(ComponentName::EventHandler, MethodName::Dequeue,
					 "EventType = " + std::to_string((int)(data->GetEventType())));
	event_queue_.pop();
	return data;
}
