#include "IOManagerBase.h"

#include "ConsoleIOManager.h"
#include "FileIOManager.h"

IOManagerBase* IOManagerBase::console_io_manager_ = nullptr;
IOManagerBase* IOManagerBase::file_io_manager_ = nullptr;

IOManagerBase* IOManagerBase::GetInstance(IOType type)
{
    switch (type) {
    case IOType::Console:
        if (console_io_manager_ == nullptr) {
            console_io_manager_ = new ConsoleIOManager();
        }
        return console_io_manager_;
    case IOType::File:
        if (file_io_manager_ == nullptr) {
            file_io_manager_ = new FileIOManager();
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
        if (console_io_manager_ != nullptr) {
            delete console_io_manager_;
            console_io_manager_ = nullptr;
        }
        break;
    case IOType::File:
        if (file_io_manager_ != nullptr) {
            delete file_io_manager_;
            file_io_manager_ = nullptr;
         }
        break;
    default:
        break;
    }
}
