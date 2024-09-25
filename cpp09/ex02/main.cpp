#include "PmergeMe.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

unsigned int	strToInt(const std::string &str)
{
	unsigned int	num;

	std::stringstream ss(str);
	ss >> num;
	return (num);
}

int	main(int argc, char *argv[])
{
	PmergeMe	pmm;

	if (argc == 1)
		return (EXIT_FAILURE);
	try
	{
		for (int i = 1; i < argc; i += 1)
			if (std::string(argv[i]).find_first_not_of("0123456789 ") != std::string::npos)
				throw PmergeMe::InvalidElementException();
		std::vector<unsigned int> temp;
		for (int i = 1; i < argc; i += 1)
			temp.push_back(strToInt(argv[i]));
		std::vector<unsigned int>::iterator itr;
		std::vector<unsigned int>::iterator itr2;
		for (itr = temp.begin(); itr != temp.end(); itr++) {
			for (itr2 = itr + 1; itr2 != temp.end(); itr2++)
				if (*itr2 == *itr)
					throw PmergeMe::InvalidElementException();
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	pmm.Vec_Ford_Johnson(argc, argv);
	std::cout << std::endl;
	pmm.List_Ford_Johnson(argc, argv);
	return (EXIT_SUCCESS);
}
