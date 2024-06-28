#include "Span.hpp"
#include <exception>
#include <iostream>
#include <vector>

void	addNumberS(Span &sp) {
	for (size_t i = 0; i < 500; i++) {
		int it = rand() % 1000;
		sp.addNumber(it);
	}
}

int main() {
	Span sp(500);
	try {
		addNumberS(sp);
	}
	catch (std::exception e) {
		std::cout << "List is full" << std::endl;
	}
	try
	{
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
