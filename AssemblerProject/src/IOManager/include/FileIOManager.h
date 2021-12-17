#pragma once

#include <fstream>
#include "IOManagerBase.h"

class FileIOManager : public IOManagerBase
{
public:
	virtual void HandleEvent(EventData *data);

private:
	void CheckFilesAvailable();
};
