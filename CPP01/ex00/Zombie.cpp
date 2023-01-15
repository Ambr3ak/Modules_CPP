#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << _name << " is about to destroy your house." << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << _name << " has been killed." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}