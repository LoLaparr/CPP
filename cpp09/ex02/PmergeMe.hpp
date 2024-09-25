#pragma once

#include <exception>

class PmergeMe
{
  private:
	PmergeMe(PmergeMe const &old);
	PmergeMe &operator=(PmergeMe const &old);

  public:
	PmergeMe();
	~PmergeMe(void);

	void Vec_Ford_Johnson(int argc, char **argv);
	void List_Ford_Johnson(int argc, char **argv);

	class InvalidElementException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};
