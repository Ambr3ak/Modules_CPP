#include "Zombie.hpp"

int main()
{
    Zombie* horde;
    int zombieNb = 10;

    horde = zombieHorde(zombieNb, "Soldier");
    if (horde == NULL)
        return (0);
    delete [] horde;
    std::cout << "The horde of " << zombieNb << " has been destroyed." << std::endl;
	return (0);
}