/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:08:56 by lolaparr          #+#    #+#             */
/*   Updated: 2024/06/25 17:36:02 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Span
{
private:
	unsigned int _size;
	std::vector<int> _vec;
public:
	Span();
	Span(unsigned int _size);
	Span(const Span &other)
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

