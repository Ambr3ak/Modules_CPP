#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie* ZombieStack = new Zombie(name);

    return (ZombieStack);
}