#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie ZombieHeap = Zombie(name);
    ZombieHeap.announce();
    return ;
}