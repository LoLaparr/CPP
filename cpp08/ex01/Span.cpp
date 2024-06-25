/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolaparr <lolaparr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:20:10 by lolaparr          #+#    #+#             */
/*   Updated: 2024/06/25 19:39:30 by lolaparr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0) {

}

Span::Span(unsigned int size) : _size(size) {

}

Span::Span(const Span &other) {
	if (this != &other) {
		_size = other._size;
		_vec = other.vec;
	}
}

Span::~Span() {

}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_size = other._size;
		_vec = other.vec;
	}
	return (*this);
}

void	Span::addNumber(int number) {
	if (vec.size() >= _size) {
		throw Span::tooManyStoredInt();
	}
	vec.push_back(number);
}

int	Span::shortestSpan() {
	if (vec.size() <= 1)
		throw tooFewStoredInt();

	std::vector<int> tmp = _vec;

	std::sort(tmp.begin(), tmp.end());

	int	shortest = tmp[tmp.size() - 1] - tmp[0];

	for (size_t i = 0; i < tmp.size() - 1; i++) {
		if (tmp[i + 1] - tmp[i] < shortest)
			shortest = tmp[i + 1] - tmp[i];
	}

	return (shortest);
}

int	Span::longestSpan() {
	if (_vec.size() <= 1)
		throw tooFewStoredInt();

	std::vector<int> tmp = _vec;

	std::sort(tmp.begin(), tmp.end());

	return (tmp[tmp.size() - 1] - tmp[0]);
}
