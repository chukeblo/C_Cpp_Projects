#include "include/IOManagerBase.h"

#include "include/ConsoleIOManager.h"
#include "include/FileIOManager.h"
#include "../Logger/include/Logger.h"

IOManagerBase *IOManagerBase::console_io_manager_ = nullptr;
IOManagerBase *IOManagerBase::file_io_manager_ = nullptr;
std::string *IOManagerBase::source_file_name_ = nullptr;
std::string *IOManagerBase::binary_file_name_ = nullptr;

void IOManagerBase::ClearFileNameData()
{
    if (source_file_name_)
    {
        delete source_file_name_;
    }
    if (binary_file_name_)
    {
        delete binary_file_name_;
    }
}

IOManagerBase *IOManagerBase::GetInstance(IOType type)
{
    switch (type)
    {
    case IOType::Console:
        if (console_io_manager_ == nullptr)
        {
            console_io_manager_ = new ConsoleIOManager();
            Logger::LogDebug(ComponentName::IOManagerBase, MethodName::GetInstance,
                             "ConsoleIOManager instance is created");
        }
        return console_io_manager_;
    case IOType::File:
        if (file_io_manager_ == nullptr)
        {
            file_io_manager_ = new FileIOManager();
            Logger::LogDebug(ComponentName::IOManagerBase, MethodName::GetInstance,
                             "FileIOManager instance is created");
        }
        return file_io_manager_;
    default:
        return nullptr;
    }
}

void IOManagerBase::DestroyInstance(IOType type)
{
    switch (type)
    {
    case IOType::Console:
        if (console_io_manager_)
        {
            delete console_io_manager_;
            console_io_manager_ = nullptr;
        }
        break;
    case IOType::File:
        if (file_io_manager_)
        {
            delete file_io_manager_;
            file_io_manager_ = nullptr;
        }
        break;
    default:
        break;
    }

    if (!console_io_manager_ && !file_io_manager_)
    {
        ClearFileNameData();
    }
}
