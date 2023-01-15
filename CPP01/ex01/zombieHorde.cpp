#include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name )
{
    Zombie* horde = new Zombie[N];
    int i = 0;
    
    if (N < 1)
    {
        std::cout << "A horde can not be less than 1 zombie." << std::endl;
        return (NULL);
    }
    std::cout << "Be carefull, a horde of Zombies is coming..." << std::endl;
    while (i < N)
    {
        horde[i].setName(name);
        horde[i].announce();
        i++;
    }
    return (horde);
}