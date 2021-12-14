#include "AddressInfo.h"

bool AddressInfo::TrySetCode(unsigned char code) {
	if (is_written_address_) {
		return false;
	}
	code_ = code;
	is_written_address_ = true;
	return true;
}