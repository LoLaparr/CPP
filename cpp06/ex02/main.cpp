#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

Base	*generate()
{
	int	i;


	i = rand() % 3;
	if (i == 0)
	{
		std::cout << "Generated A" << std::endl;
		return (new A());
	}
	else if (i == 1)
	{
		std::cout << "Generated B" << std::endl;
		return (new B());
	}

	std::cout << "Generated C" << std::endl;
	return (new C());

}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "Identified pointer A" << std::endl;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "Identified pointer B" << std::endl;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "Identified pointer C" << std::endl;
	}
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Identified reference A" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Identified reference B" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Identified reference C" << std::endl;
	}
	catch (std::exception &e)
	{
	}
}

int	main(void)
{
	Base	*ptr;

	for (int i = 0; i < 4; i++)
	{
		ptr = generate();
		identify(ptr);
		std::cout << std::endl;
		identify(*ptr);
		std::cout << std::endl;
		std::cout << "-------------" << std::endl;
	}
}
