/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:08:32 by lolaparr          #+#    #+#             */
/*   Updated: 2024/06/05 19:29:10 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits.h>
#include <cstdio>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	*this = other;
	return;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return (*this);
}

Literals ScalarConverter::identify(std::string input) {
	unsigned long i = 0;
	if (input.length() == 1 && !isdigit(input[0]))
		return (CHAR);
	if (input == "nan" || input == "nanf" || input == "+inf" ||
		input == "+inff" || input == "-inf" || input == "-inff")
		return (LITERAL);
	if (input[i] == '+' || input[i] == '-')
		i++;
	if ((input[0] == '-' && (input.size() > 12)) || input.size() > 11)
		return (INVALID);
	while (isdigit(input[i]))
		i++;
	if (i >= 1) {
		if (input[i] == '.') {
			i++;
		while (isdigit(input[i]))
			i++;
		if (input[i] == '\0')
			return (DOUBLE);
	}
	if (input[i] == 'f' && i == input.length() - 1)
		return (FLOAT);
	if (input[i] == '\0')
		return (INT);
	}
	return (INVALID);
}

void ScalarConverter::fromChar(std::string input) {
	std::cout << "char: '" << input[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
}

void ScalarConverter::fromInt(std::string input) {
	long long int theInt = std::atoll(input.c_str());

	if (theInt < INT_MIN || theInt > INT_MAX)
		return;
	if (theInt > 32 && theInt < 126)
	std::cout << "char: '" << static_cast<char>(theInt) << "'" << std::endl;
	else
		std::cout << "char: Not displayable" << std::endl;
	std::cout << "int: " << theInt << std::endl;
	std::cout << "float: " << static_cast<float>(theInt) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(theInt) << ".0" << std::endl;
}

void ScalarConverter::fromFloat(std::string input) {
	float theFloat;
	std::istringstream(input) >> theFloat;
	int theInt = static_cast<int>(theFloat);

	if (std::isprint(theInt))
		std::cout << "char: '" << static_cast<char>(theInt) << "'" << std::endl;
	else
		std::cout << "char: Not displayable" << std::endl;
	std::cout << "int: " << theInt << std::endl;
	if (theInt == theFloat) {
		std::cout << "float: " << theFloat << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(theFloat) << ".0"
			<< std::endl;
	}
	else {
	std::cout << "float: " << theFloat << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(theFloat) << std::endl;
	}
}

void ScalarConverter::fromDouble(std::string input) {
	double theDouble;
	std::istringstream(input) >> theDouble;
	int theInt = static_cast<int>(theDouble);

	if (std::isprint(theInt))
		std::cout << "char: '" << static_cast<char>(theInt) << "'" << std::endl;
	else
		std::cout << "char: Not displayable" << std::endl;
	std::cout << "int: " << theInt << std::endl;
	if (theInt == theDouble) {
		std::cout << "float: " << static_cast<float>(theDouble) << ".0f"
			<< std::endl;
		std::cout << "double: " << theDouble << ".0" << std::endl;
	}
	else {
		std::cout << "float: " << static_cast<float>(theDouble) << "f" << std::endl;
		std::cout << "double: " << theDouble << std::endl;
  }
}

void ScalarConverter::fromLiteral(std::string input) {
	std::cout << "char: impossible" << std::endl;
	if (input == "nan" || input == "nanf") {
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (input == "+inf" || input == "+inff") {
		std::cout << "int: +inf" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (input == "-inf" || input == "-inff") {
	std::cout << "int: -inf" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(std::string input) {
	ScalarConverter convert;

	switch (convert.identify(input)) {
	case CHAR:
		convert.fromChar(input);
		break;
	case INT:
		convert.fromInt(input);
		break;
	case FLOAT:
		convert.fromFloat(input);
		break;
	case DOUBLE:
		convert.fromDouble(input);
		break;
	case LITERAL:
		convert.fromLiteral(input);
		break;
	default:
		std::cout << "Not a valid literal" << std::endl;
		break;
	}
}
