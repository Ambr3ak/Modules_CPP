#include "Weapon.hpp"

Weapon::Weapon(const std::string &weapon)
{
    this->setType(weapon);
}

Weapon::~Weapon(void)
{
    std::cout << this->getType() << " broke." << std::endl;
}

std::string const & Weapon::getType() const
{
    return this->_type;
}

void Weapon::setType(const std::string newType)
{
    _type = newType;
}