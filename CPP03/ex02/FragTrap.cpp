#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    std::cout << COLOR_GREEN << name << " FragTrap is ready to fight." << COLOR_END << std::endl;
    std::cout << COLOR_START << "HP : " << getHitPoints() << " EP : " << getEnergyPoints() <<  " AD : " << getDamagePoints() << COLOR_END << std::endl;
}

FragTrap::FragTrap(const FragTrap & src) : ClapTrap(src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

FragTrap::~FragTrap(void){
    std::cout << COLOR_RED << "FragTrap destructor called" << COLOR_END << std::endl;
}

void FragTrap::highFivesGuys(void){
    std::cout << "High Fives Guys ?" << std::endl;
}