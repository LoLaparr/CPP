/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:03:33 by lolaparr          #+#    #+#             */
/*   Updated: 2024/06/04 15:03:34 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

enum Literals { CHAR, INT, FLOAT, DOUBLE, LITERAL, INVALID };

class ScalarConverter
{
private:

	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	~ScalarConverter();

	ScalarConverter &operator=(const ScalarConverter &other);

	Literals identify(std::string input);

	void fromChar(std::string input);
	void fromInt(std::string input);
	void fromFloat(std::string input);
	void fromDouble(std::string input);
	void fromLiteral(std::string input);

public:
	void static convert(std::string input);

};
