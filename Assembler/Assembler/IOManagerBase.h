#pragma once

#include <string>
#include "EventData.h"
#include "EventHandler.h"
#include "IOType.h"

class IOManagerBase
{
protected:
	static IOManagerBase* console_io_manager_;
	static IOManagerBase* file_io_manager_;
	static std::string* source_file_name_;
	static std::string* binary_file_name_;
	virtual ~IOManagerBase(){}
	static void ClearFileNameData();
public:
	static IOManagerBase* GetInstance(IOType type);
	static void DestroyInstance(IOType type);
	virtual void HandleEvent(EventData* data) = 0;
};

