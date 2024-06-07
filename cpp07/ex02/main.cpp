#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int	main(void)
{
	Array<int> numbers(12);
	Array<char> charArray(11);
	Array<double> doubleTest(69);
	Array<int> intTest;
	int *a = new int();

	std::cout << "Printing allocated char : " << std::endl;
	std::cout << *a << std::endl;
    delete	a;

	std::cout << std::endl;
	std::cout << "Numbers array:" << std::endl;

	for (int i = 0; i < 12; ++i) {
		std::cout << numbers[i] << " ";
	}

	std::cout << std::endl;
	std::cout << "Size of the array: " << numbers.size() << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 11; ++i) {
		charArray[i] = 'A' + i;
	}

	std::cout << "Characters array:" << std::endl;

	for (int i = 0; i < 11; ++i){
		std::cout << charArray[i] << " ";
	}

	std::cout << std::endl;
	std::cout << "Size of the array: " << charArray.size() << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << numbers[1223] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
	try
	{
		std::cout << intTest[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "FATAL ERROR : " << e.what() << std::endl;
	}

	for (int i = 0; i < 69; i++)
	{
		doubleTest[i] = static_cast<double>(i);
	}

	for (int i = 0; i < 70; i++) {
		try
		{
			std::cout << doubleTest[i] << " ";
		}
		catch (std::exception &e)
		{
			std::cout << std::endl;
			std::cout << "FATAL ERROR : " << e.what() << std::endl;
		}
	}

	return (0);
}
