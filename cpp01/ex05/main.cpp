#include "Harl.hpp"

int main ( void )
{
	std::string input;
	Harl	player;

	std::cout << "-> ";
	while (getline(std::cin, input))
	{
		if (input == "EXIT")
			break;
		else
			player.complain( input );
		std::cout << "-> ";
	}

	return (0);
}
