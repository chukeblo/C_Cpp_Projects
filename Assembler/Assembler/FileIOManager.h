#pragma once

#include "IOManagerBase.h"

class FileIOManager : public IOManagerBase
{
public:
	FileIOManager(){}
	~FileIOManager(){}
	virtual void HandleEvent(EventData* data);
};

