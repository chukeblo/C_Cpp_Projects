#include "include/EventData.h"

EventData::EventData(EventData *data)
	: event_type_(data->GetEventType()),
	  result_data_(data->GetResultData())
{
}

EventData::EventData(EventType type)
	: event_type_(type), result_data_(nullptr)
{
}

EventData::EventData(EventType type, void *data)
	: event_type_(type), result_data_(data)
{
}

EventType EventData::GetEventType()
{
	return event_type_;
}

void *EventData::GetResultData()
{
	return result_data_;
}
