#pragma once

enum class ResultCode {
	Unknown,
	Success,
	InvalidArgumentNum,
	SourceFileOpenFailed,
	SourceFileCloseFailed,
	BinaryFileOpenFailed,
	BinaryFileCloseFailed
};