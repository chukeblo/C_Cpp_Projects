#pragma once

class AddressInfo
{
private:
	unsigned char code_;
	bool is_written_address_;
public:
	bool TrySetCode(unsigned char code);
};

