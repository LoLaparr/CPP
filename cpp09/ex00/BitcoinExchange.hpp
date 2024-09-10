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
	BitcoinExchange &operator=(const BitcoinExchange &other);
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other): _exchange(other._exchange) {}
	~BitcoinExchange();

	void	loadDatabase(const std::string &filename);
	void	processInputFile(const std::string &inputFilename);
	float	getExchangeRate(const std::string &date) const;

	void	isValidInput(const std::map<std::string, float>& _exchange);
	bool	isValidValue(float value);
	bool	isValidDate(const std::string &date);

	std::map<std::string, float> getMap() const;
};
