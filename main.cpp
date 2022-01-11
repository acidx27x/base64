#include "base64_table.h"
#include "decode_base64.h"
#include "encode_base64.h"
#include <iostream>
#include <exception>



int main()
{
	encode_base64* e_b64 = new encode_base64();
	decode_base64* d_b64 = new decode_base64();

	while (true)
	{
		try {
			//std::cout << "\x1B[2J\x1B[H";
			std::cout << "\n +---------------------------+\n";
			std::cout << " |print base64 table     ...1|\n";
			std::cout << " |encode message         ...2|\n";
			std::cout << " |decode message         ...3|\n";
			std::cout << " |exit                   ...4|\n";
			std::cout << " +---------------------------+\n";
			int16_t fun = 0;
			std::cout << "\n enter the number: ";
			std::cin >> fun;
			switch (fun)
			{
			case 1:
				print_table();
				std::cout << std::endl << "........................................................................." << std::endl;
				break;
			case 2:
				e_b64->encoding();
				std::cout << std::endl << "........................................................................." << std::endl;
				break;
			case 3:
				d_b64->decoding();
				std::cout << std::endl << "........................................................................." << std::endl;
				break;
			case 4:
				delete e_b64;
				delete d_b64;
				return 1;
			default:
				std::cout << "\n wrong number, try again";
				std::cout << std::endl << "........................................................................." << std::endl;
				break;
			}
		}
		catch (std::exception& exp)
		{
			std::cout << exp.what() << std::endl << "........................................................................." << std::endl;
		}
		
	}
	
	return 0;
}