#include "include/FileIOManager.h"
#include "../Logger/include/Logger.h"
#include "../ResultData.h"
#include "../ResultMessageConstants.h"
#include "../StateMachine/include/StateBase.h"

void FileIOManager::HandleEvent(EventData *data)
{
    switch (data->GetEventType())
    {
    case EventType::UserInputCompleted:
        CheckFilesAvailable();
        break;
    default:
        break;
    }
}

void FileIOManager::CheckFilesAvailable()
{
    // check if source file is available
    std::ifstream source_file_info(*source_file_name_);
    if (!source_file_info)
    {
        Logger::LogError(ComponentName::FileIOManager, MethodName::CheckFilesAvailable,
                         "source file cannot be opened");
        EventHandler::GetInstance()->Enqueue(
            new EventData(EventType::StateChangeRequested,
                          (void *)StateBase::GetInstance(StateType::ShowingResult)));
        EventHandler::GetInstance()->Enqueue(
            new EventData(EventType::ErrorOccurred,
                          (void *)new ResultData(ResultCode::SourceFileOpenFailed, ResultMessage::SourceFileOpenFailed)));
        return;
    }

    // check if binary file is available
    std::ofstream binary_file_info(*binary_file_name_);
    if (!binary_file_info)
    {
        Logger::LogError(ComponentName::FileIOManager, MethodName::CheckFilesAvailable,
                         "binary file cannot be opened");
        EventHandler::GetInstance()->Enqueue(
            new EventData(EventType::StateChangeRequested,
                          (void *)StateBase::GetInstance(StateType::ShowingResult)));
        EventHandler::GetInstance()->Enqueue(
            new EventData(EventType::ErrorOccurred,
                          (void *)new ResultData(ResultCode::BinaryFileOpenFailed, ResultMessage::BinaryFileOpenFailed)));
        return;
    }

    EventHandler::GetInstance()->Enqueue(new EventData(EventType::BothFilesConfirmedAvailable));
}