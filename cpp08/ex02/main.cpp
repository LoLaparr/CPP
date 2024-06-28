#include "MutantStack.hpp"
#include <list>

int main () {
{
	MutantStack<int> myStack;
	myStack.push(5);
	myStack.push(17);
	std::cout << "Top: " << myStack.top() << std::endl;
	myStack.pop();
	std::cout << "Size: " << myStack.size() << std::endl;
	myStack.push(3);
	myStack.push(5);
	myStack.push(737);
	myStack.push(0);
	MutantStack<int>::iterator it = myStack.begin();
	MutantStack<int>::iterator ite = myStack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(myStack);
}

{
	std::cout << "---------" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Top: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "Size: " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}

}
