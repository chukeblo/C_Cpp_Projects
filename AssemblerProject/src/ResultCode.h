#pragma once

enum class ResultCode
{
	Unknown,
	Success,
	ExceededMaxRetryCounts,
	SourceFileOpenFailed,
	SourceFileCloseFailed,
	BinaryFileOpenFailed,
	BinaryFileCloseFailed
};