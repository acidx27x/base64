#pragma once
#include "base64_table.h"
#include <sstream>
#include <exception>

class decode_base64
{
private:
	std::string char64_to_num();
	std::vector<std::string> new_numbers(const std::string&);
	std::string binary_num_to_char(const std::vector<std::string>&);

public:
	void decoding();
};