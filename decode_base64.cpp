#include "decode_base64.h"



std::string decode_base64::char64_to_num()
{
	std::cout << "\n enter some message to decode: ";
	std::string str = "";
	std::string num = "";
	getline(std::cin >> std::ws, str);
	for (const auto& ch : str)
	{
		int8_t count = 0;
		auto it = std::find_if(base64_table.begin(), base64_table.end(),
			[&ch, &count, &num](const std::pair<char, std::string>& item)
			{
				if (item.first == ch)
				{
					num.append(item.second);
					++count;
				}
				if (ch == '=')
					++count;
				return item.first == ch;
			});
		if (count == 0)
		{
			std::ostringstream out;
			out << " [ " << ch << " ] is undefined, check for mistakes. " << std::endl;
			throw std::invalid_argument(out.str());
		}
	}
	return num;
}

std::vector<std::string> decode_base64::new_numbers(const std::string& str)
{
	std::vector<std::string> nums;
	std::string num = "";
	uint8_t counter = 0;
	for (const auto& ch : str)
	{
		++counter;
		num += ch;
		if (counter == 8)
		{
			nums.push_back(num);
			counter = 0;
			num.clear();
		}
	}
	return nums;
}

std::string decode_base64::binary_num_to_char(const std::vector<std::string>& nums)
{
	std::string decoded = "";
	for (const auto& num : nums)
	{
		uint16_t converted = 0;
		for (size_t i = 0; i < num.size(); ++i)
		{
			converted += (num[i] - '0') * static_cast<uint16_t>(std::pow(2, num.size() - (i + 1)));
		}
		decoded += static_cast<char>(converted);
	}
	std::cout << " decoded message: ";
	return decoded;
}

void decode_base64::decoding()
{
	std::cout << binary_num_to_char(new_numbers(char64_to_num()));
	std::cout << std::endl;
}