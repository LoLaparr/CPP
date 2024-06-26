/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:08:56 by lolaparr          #+#    #+#             */
/*   Updated: 2024/06/28 14:53:04 by louislaparr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <vector>

class Span
{
private:
	unsigned int		_size;
	std::vector<int>	_vec;
public:
	Span();
	Span(unsigned int _size);
	Span(const Span &other);
	~Span();

	Span	&operator=(const Span &other);

	void	addNumber(int number);
	int		shortestSpan();
	int		longestSpan();

	class tooManyStoredInt : public std::exception
	{
		public:
			virtual const char* what() const throw() {
					return ("The maximum capacity of the Span is reached");
			};
	};
	class tooFewStoredInt : public std::exception
	{
		public:
			virtual const char* what() const throw() {
				return ("Not enough numbers to calculate distance");
			};
	};
};

