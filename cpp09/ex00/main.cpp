#include <iostream>
#include <string>
#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <input.txt>" << std::endl;
		return 1;
	}

	std::string inputFile = argv[1];

	BitcoinExchange exchange;
try
{
	exchange.loadDatabase("input.csv");
}
catch(const std::exception& e)
{
	std::cerr << e.what() << std::endl;
	return 1;
}

try
{
	exchange.isValidInput(exchange.getMap());
}
catch(const std::exception& e)
{
	std::cerr << e.what() << std::endl;
	return 1;
}

try
{
	exchange.processInputFile(inputFile);
}
catch(const std::exception& e)
{
	std::cerr << e.what() << std::endl;
	return 1;
}

	return 0;
}

/*

espaces
char in line
les char dans les date
les try/catch
le main
les return dans les try/catch du main

*/
