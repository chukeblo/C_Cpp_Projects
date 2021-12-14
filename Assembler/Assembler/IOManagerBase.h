#pragma once

#include "EventData.h"
#include "EventHandler.h"
#include "IOType.h"

class IOManagerBase
{
protected:
	static IOManagerBase* console_io_manager_;
	static IOManagerBase* file_io_manager_;
	virtual ~IOManagerBase(){}
public:
	static IOManagerBase* GetInstance(IOType type);
	static void DestroyInstance(IOType type);
	virtual void HandleEvent(EventData* data) = 0;
};

