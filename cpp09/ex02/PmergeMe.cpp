#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <list>
#include <vector>

#define MICROSECOND 100000

unsigned int	strToInt(const std::string &str);

PmergeMe::PmergeMe(){};

PmergeMe::~PmergeMe(){};

static void	printVec(std::vector<unsigned int> &vec)
{
	std::vector<unsigned int>::const_iterator itr;
	for (itr = vec.begin(); itr != vec.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

static std::vector<unsigned int> merge_All_Vec(std::vector<unsigned int> &left,
		std::vector<unsigned int> &right)
{
	std::vector<unsigned int> ret;
	while (!left.empty() && !right.empty()) {
		if (left.front() <= right.front()) {
			ret.push_back(left.front());
			left.erase(left.begin());
		}
		else {
			ret.push_back(right.front());
			right.erase(right.begin());
		}
	}
	while (!left.empty()) {
		ret.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty()) {
		ret.push_back(right.front());
		right.erase(right.begin());
	}
	return (ret);
}

static std::vector<unsigned int> merge_Insert_For_Vec(std::vector<unsigned int> &vec)
{
	int	med;

	if (vec.size() <= 1) {
		return (vec);
	}
	med = vec.size() / 2;
	std::vector<unsigned int> left(vec.begin(), vec.begin() + med);
	std::vector<unsigned int> right(vec.begin() + med, vec.end());
	left = merge_Insert_For_Vec(left);
	right = merge_Insert_For_Vec(right);
	return (merge_All_Vec(left, right));
}

void PmergeMe::Vec_Ford_Johnson(int argc, char **argv)
{
	double	time_taken;

	std::vector<unsigned int> ret;
	for (int i = 1; i < argc; i += 1) {
		ret.push_back(strToInt(argv[i]));
	}
	std::cout << "Before: ";
	printVec(ret);
	std::clock_t start = std::clock();
	ret = merge_Insert_For_Vec(ret);
	time_taken = static_cast<double>(std::clock() - start)
		/ static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;
	std::cout << "After: ";
	printVec(ret);
	std::cout << "Time to process a range of " << argc - 1
				<< " elements "
				<< "with std::vector<unsigned int> : "
				<< time_taken << " µs";
}

static std::list<unsigned int> merge_All_List(std::list<unsigned int> &left,
		std::list<unsigned int> &right)
{
	std::list<unsigned int> ret;
	while (!left.empty() && !right.empty()) {
		if (left.front() <= right.front()) {
			ret.push_back(left.front());
			left.erase(left.begin());
		}
		else {
			ret.push_back(right.front());
			right.erase(right.begin());
		}
	}
	while (!left.empty()) {
		ret.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty()) {
		ret.push_back(right.front());
		right.erase(right.begin());
	}
	return (ret);
}

static std::list<unsigned int> mergeInsertList(std::list<unsigned int> &lst)
{
	int	med;

	if (lst.size() <= 1){
		return (lst);
	}
	med = lst.size() / 2;
	std::list<unsigned int> left;
	std::list<unsigned int> right;
	for (int i = 0; i < med; i++) {
		left.push_back(lst.front());
		lst.pop_front();
	}
	right = lst;
	left = mergeInsertList(left);
	right = mergeInsertList(right);
	return (merge_All_List(left, right));
}

void PmergeMe::List_Ford_Johnson(int argc, char **argv)
{
	double	time_taken;

	std::list<unsigned int> ret;
	for (int i = 1; i < argc; i += 1)
		ret.push_back(strToInt(argv[i]));
	std::clock_t start = std::clock();
	ret = mergeInsertList(ret);
	time_taken = static_cast<double>(std::clock() - start)
		/ static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;
	std::cout << "Time to process a range of " << argc - 1
				<< " elements "
				<< "with std::list<unsigned int> : "
				<< time_taken << " µs" << std::endl;
}

const char *PmergeMe::InvalidElementException::what() const throw()
{
	return ("PmergeMe exception: invalid element");
}
