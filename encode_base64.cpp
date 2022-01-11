#include "encode_base64.h"


std::string encode_base64::char_to_binary_num()
{
	std::cout << "\n enter some message to encode: ";
	std::string str = "";
	std::string nums = "";
	getline(std::cin >> std::ws, str);
	for (const auto& ch : str)
	{
		uint16_t temp = static_cast<uint16_t>(ch);
		//std::cout << temp << std::endl;
		std::string num = "";
		while (true)
		{
			if (temp == 1)
			{
				num.append("1");
				for (size_t i = 0; i <= 8 - num.size(); ++i)
					num.append("0");

				std::reverse(num.begin(), num.end());
				nums.append(num);
				break;
			}
			if (temp % 2 == 0)
				num.append("0");
			else
				num.append("1");
			temp /= 2;
		}
	}
	return nums;
}


std::vector<std::string> encode_base64::new_numbers(const std::string& str)
{
	std::vector<std::string> nums;
	std::string num = "";
	uint16_t counter = 0;
	for (const auto& ch : str)
	{
		++counter;
		num += ch;
		if (counter == 6)
		{
			nums.push_back(num);
			counter = 0;
			num.clear();
		}
	}
	/*if (counter == 2)
	{
		num.append("0000");
		nums.push_back(num);
		flag1 = true;
	}
	if (counter == 4)
	{
		num.append("00");
		nums.push_back(num);
		flag2 = true;
	}*/
	nums.push_back(num);
	return nums;
}

std::string encode_base64::num_to_char64(std::vector<std::string>& nums)
{
	bool flag1 = false;
	bool flag2 = false;
	std::string str = "";
	for (auto& num : nums)
	{
		int8_t count = 0;
		auto it = std::find_if(base64_table.begin(), base64_table.end(),
			[&num, &count, &str, &flag1, &flag2](const std::pair<char, std::string>& item)
			{
				if (num.size() == 2)
				{
					num.append("0000");
					flag1 = true;
				}
				if (num.size() == 4)
				{
					num.append("00");
					flag2 = true;
				}
				if (item.second == num)
				{
					str += item.first;
					++count;
				}
				return item.second == num;
			});
		if (count == 0)
		{
			std::ostringstream out;
			out << " [ " << num << " ] is undefined, check for mistakes. " << std::endl;
			throw std::invalid_argument(out.str());
		}
	}
	if (flag1)
		str.append("==");
	if (flag2)
		str.append("=");
	std::cout << " encoded message: ";
	return str;
}

void encode_base64::encoding()
{
	auto vec_str = new_numbers(char_to_binary_num());
	std::cout << num_to_char64(vec_str);
	std::cout << std::endl;
}