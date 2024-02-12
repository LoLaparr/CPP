#include "Zombie.hpp"

int	main()
{
	int	N = 6;
	Zombie	*Horde = zombieHorde(N, "jacques");

	for (int i = 0; i < N; i++)
	{
		Horde[i].announce();
	}

	delete	Horde;

	return (0);
}
