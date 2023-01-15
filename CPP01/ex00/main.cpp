#include "Zombie.hpp"

int main()
{
    Zombie* ZombieStack = newZombie("ZombieStack");
    randomChump("ZombieHeap");

	delete ZombieStack;
	return (0);
}