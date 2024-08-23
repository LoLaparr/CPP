#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, float> _exchange;

public:
	BitcoinExchange();
	BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _exchange(other._exchange) {}
	BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void BitcoinExchange::loadDatabase(const std::string &filename);
	void BitcoinExchange::processInputFile(const std::string &inputFilename);
};

void BitcoinExchange::loadDatabase(const std::string &filename) {

	std::ifstream	file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: File couldn't open the file " << filename << std::endl;
		return 1;
	}
	std::string	line;
	while(std::getline(file, line)) {
		std::string	date;
		float rate;
		std::stringstream	ss(line);

		if (std::getline(ss, date, ',') && ss >> rate) {
			_exchange[date] = rate;
		}
		else
			std::cerr << "Bad line in " << filename << std::endl;
	}
	file.close();

}

void BitcoinExchange::processInputFile(const std::string &inputFilename) {
	
}





































BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_exchange = other._exchange;
	}
	return *this;
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}
