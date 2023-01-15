#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name;
    this->_isArmed = 0;
    std::cout << _name << " joined the crew." << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << _name << " died." << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
    std::cout << _name << " took " << this->_weapon->getType() << "." << std::endl;
    this->_isArmed = 1;
}

void HumanB::attack(void)
{
    if (isArmed == 1)
        std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << _name << " can't fight without a weapon." << std::endl;
}