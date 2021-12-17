#include "ResultData.h"

ResultData::ResultData(ResultCode code, std::string message) : result_code_(code), result_message_(message)
{
}

ResultCode ResultData::GetResultCode()
{
    return result_code_;
}

std::string ResultData::GetResultMessage()
{
    return result_message_;
}