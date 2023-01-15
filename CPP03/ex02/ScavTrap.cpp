#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    std::cout << COLOR_GREEN << name << " ScavTrap is ready to fight." << COLOR_END << std::endl;
    std::cout << COLOR_START << "HP : " << getHitPoints() << " EP : " << getEnergyPoints() <<  " AD : " << getDamagePoints() << COLOR_END << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & src) : ClapTrap(src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

ScavTrap::~ScavTrap(void){
    std::cout << COLOR_RED << "ScavTrap destructor called" << COLOR_END << std::endl;
}

void ScavTrap::attack(const std::string & target)
{

    if (getEnergyPoints() <= 0 || getHitPoints() <= 0)
        std::cout << getName() << " ScavTrap can't attack. It is dead." << std::endl;
    else
    {
        setEnergyPoints(getEnergyPoints() - 1);
        std::cout << getName() << " ScavTrap attacks " << target << ". EP (-1)" << std::endl;
        std::cout << COLOR_START << "HP : " << getHitPoints() << " EP : " << getEnergyPoints() <<  " AD : " << getDamagePoints() << COLOR_END << std::endl;
    }
}

void ScavTrap::guardGate(void){
    std::cout << getName() << " : Actived Mode Gate Keep" << std::endl;
}