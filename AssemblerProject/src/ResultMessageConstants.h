#pragma once

#include <string>

namespace ResultMessage
{
    const std::string Success = "Assemble Succeeded";
    const std::string ExceededMaxRetryCounts = "Exceeded Maximum Retry Counts for User Input";
    const std::string SourceFileOpenFailed = "Given Source File Could not be Opened";
    const std::string SourceFileCloseFailed = "Failed to Close Source File";
    const std::string BinaryFileOpenFailed = "Given Binary File Could not be Opened";
    const std::string BinaryFileCloseFailed = "Failed to Close Binary File";
}
