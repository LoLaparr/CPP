#include <iostream>
#include <string>


int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}

	int	i = 1;
	while (i < ac)
	{
		std::string str = av[i];
		for (int j = 0; j < str.size(); j++)
			std::cout << (char)std::toupper(str[j]);
		++i;
	}
	std::cout << std::endl;
	return (0);
}
