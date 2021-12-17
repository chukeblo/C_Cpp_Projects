#pragma once

#include <string>
#include "ResultCode.h"

class ResultData
{
private:
    ResultCode result_code_;
    std::string result_message_;

public:
    ResultData(ResultCode code, std::string message);
    ResultCode GetResultCode();
    std::string GetResultMessage();
};