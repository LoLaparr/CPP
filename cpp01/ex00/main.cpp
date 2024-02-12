#include "Zombie.hpp"

int	main()
{
	Zombie	*caca = newZombie("Pierre");

	caca->announce();
	randomChump("Paul");

	delete caca;
	return (0);
}
