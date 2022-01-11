#pragma once
#include "base64_table.h"
#include <exception>
#include <sstream>

class encode_base64
{
private:
	std::string char_to_binary_num();
	std::vector<std::string> new_numbers(const std::string&);
	std::string num_to_char64(std::vector<std::string>&);

public:
	void encoding();
};