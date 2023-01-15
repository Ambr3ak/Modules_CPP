#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
    this->_name = name;
    std::cout << this->_name << " joined the crew with " << _weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
    std::cout << _name << " died." << std::endl;
}

void HumanA::attack(void)
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}