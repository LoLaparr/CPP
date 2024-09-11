#include "BitcoinExchange.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>


float	BitcoinExchange::getExchangeRate(const std::string &date) const {

try {
	std::map<std::string, float>::const_iterator it = _exchange.find(date);
	if (it != _exchange.end())
		return it->second;

	std::map<std::string, float>::const_iterator lowerBound = _exchange.lower_bound(date);
	if (lowerBound != _exchange.begin()) {
		--lowerBound;
		return lowerBound->second;
	}
}
catch(const std::exception& e) {
	throw std::invalid_argument("Error: No previous date available for");
}
	return 1.0f;
}

void BitcoinExchange::loadDatabase(const std::string &filename) {

	std::ifstream	file(filename.c_str());
	if (!file.is_open()) {
		throw std::invalid_argument("Error: File couldn't open the file");
	}
	std::string	line;
	getline(file, line);
	while(std::getline(file, line)) {
		std::stringstream	ss(line);
		std::string	date;
		float rate;

		if (std::getline(ss, date, ',') && ss >> rate) {
			_exchange[date] = rate;
		}
		else
			throw std::invalid_argument("Error: Bad line in the file.csv");
	}
	file.close();
}

void BitcoinExchange::processInputFile(const std::string &inputFilename) {
	std::ifstream	inputFile(inputFilename.c_str());

	if(!inputFile.is_open()) {
		throw std::invalid_argument("Error: File couldn't open the file");
	}

	std::string	line;
	getline(inputFile, line);
	while(std::getline(inputFile, line)) {
		std::stringstream	ss(line);
		std::string	date;
		float	value;

		if (std::getline(ss, date, '|') && ss >> value) {

			float	rate = getExchangeRate(date);
			float	bitcoinValue = rate * value;

			std::cout << date << " => " << value << " = " << bitcoinValue << std::endl;
		}
		else
			throw std::invalid_argument("Error: Bad line in the file.txt");
	}
	inputFile.close();
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_exchange = other._exchange;
	}
	return *this;
}

bool BitcoinExchange::isValidDate(const std::string &date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return false; // Le format doit être "YYYY-MM-DD"
	}

	int year, month, day;
	char dash1, dash2;

	std::istringstream dateStream(date);

	// Extraction des parties de la date
	if (!(dateStream >> year >> dash1 >> month >> dash2 >> day) ||
		dash1 != '-' || dash2 != '-') {
			return false;
	}

	// Vérification de la validité de l'année, du mois et du jour
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
		return false;
	}

	// Vérification du nombre de jours en fonction du mois
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		return false;
	}

	// Vérification pour février (année bissextile ou non)
	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (month == 2) {
		if (isLeapYear && day > 29) {
			return false;
		} else if (!isLeapYear && day > 28) {
			return false;
		}
	}

	return true;
}

bool BitcoinExchange::isValidValue(float value) {
	return value >= 0.0f && value <= 1000.0f;
}

void	BitcoinExchange::isValidInput(const std::map<std::string, float>& _exchange) {

	std::map<std::string, float>::const_iterator itEnd = _exchange.end();
	--itEnd;

	for (std::map<std::string, float>::const_iterator it = _exchange.begin(); it != itEnd; ++it) {


		std::map<std::string, float>::const_iterator ite = _exchange.find(it->first);

		if (ite == _exchange.end()) {
			throw std::invalid_argument("La date  n'existe pas dans la base de données.");
		}

	// Vérification de la validité de la date
		if (!isValidDate(ite->first)) {
		throw std::invalid_argument("Date invalide");
		}

	std::cout << ite->second << std::endl;

	// Vérification de la validité de la valeur associée
		if (!isValidValue(ite->second)) {
			throw std::invalid_argument("Valeur invalide pour la date");
		}

	}

}

std::map<std::string, float> BitcoinExchange::getMap() const {
	return this->_exchange;
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}
