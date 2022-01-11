#pragma once
#include <vector>
#include <string>
#include <iostream>

static std::vector<std::pair<char, std::string>> base64_table = {	{'A', "000000"},	{'Q', "010000"},	{'g', "100000"},	{'w', "110000"},
																	{'B', "000001"},	{'R', "010001"},	{'h', "100001"},	{'x', "110001"},
																	{'C', "000010"},	{'S', "010010"},	{'i', "100010"},	{'y', "110010"},
																	{'D', "000011"},	{'T', "010011"},	{'j', "100011"},	{'z', "110011"},
																	{'E', "000100"},	{'U', "010100"},	{'k', "100100"},	{'0', "110100"},
																	{'F', "000101"},	{'V', "010101"},	{'l', "100101"},	{'1', "110101"},
																	{'G', "000110"},	{'W', "010110"},	{'m', "100110"},	{'2', "110110"},
																	{'H', "000111"},	{'X', "010111"},	{'n', "100111"},	{'3', "110111"},
																	{'I', "001000"},	{'Y', "011000"},	{'o', "101000"},	{'4', "111000"},
																	{'J', "001001"},	{'Z', "011001"},	{'p', "101001"},	{'5', "111001"},
																	{'K', "001010"},	{'a', "011010"},	{'q', "101010"},	{'6', "111010"},
																	{'L', "001011"},	{'b', "011011"},	{'r', "101011"},	{'7', "111011"},
																	{'M', "001100"},	{'c', "011100"},	{'s', "101100"},	{'8', "111100"},
																	{'N', "001101"},	{'d', "011101"},	{'t', "101101"},	{'9', "111101"},
																	{'O', "001110"},	{'e', "011110"},	{'u', "101110"},	{'+', "111110"},
																	{'P', "001111"},	{'f', "011111"},	{'v', "101111"},	{'/', "111111"}	};


inline void print_table()
{
	uint8_t counter = 0;
	std::cout << "\n base64 table \n";
	std::cout << " +-------------+-------------+-------------+-------------+\n" << " | ";
	for (const auto& item : base64_table)
	{
		++counter;
		std::cout << " " << item.first << " ~ " << item.second << " | ";
		if (counter % 4 == 0)
		{
			std::cout << std::endl;
			if (counter != 64)
				std::cout << " | ";
		}
	}
	std::cout << " +-------------+-------------+-------------+-------------+" << std::endl;
}