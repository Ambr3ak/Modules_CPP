#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << COLOR_GREEN << this->_name << " ClapTrap is ready to fight." << COLOR_END << std::endl;
    std::cout << COLOR_START << "HP : " << this->_hitPoints << " EP : " << this->_energyPoints <<  " AD : " << this->_attackDamage << COLOR_END << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & src){
    std::cout << COLOR_YELLOW << "Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap(void){
    std::cout << COLOR_RED << this->_name << " is destroyed." << COLOR_END << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & value){

    std::cout << COLOR_YELLOW << "Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        this->_name = value.getName();
        this->_hitPoints = value.getHitPoints();
        this->_energyPoints = value.getEnergyPoints();
        this->_attackDamage = value.getDamagePoints();
    }
    return *this;
}

//Hits Points

int ClapTrap::getHitPoints(void) const{
    std::cout << "getHitPoints member function called" << std::endl;
    return this->_hitPoints;
}

void ClapTrap::setHitPoints(int const new_points){

    this->_hitPoints = new_points;
}

//Energy Points

int ClapTrap::getEnergyPoints(void) const{
    std::cout << "getEnergyPoints member function called" << std::endl;
    return this->_energyPoints;
}

void ClapTrap::setEnergyPoints(int const new_points){

    this->_energyPoints = new_points;
}

//Attack damage

int ClapTrap::getDamagePoints(void) const{
    std::cout << "getDamagePoints member function called" << std::endl;
    return this->_attackDamage;
}

void ClapTrap::setDamagePoints(int const new_points){

    this->_attackDamage = new_points;
}

//Name

std::string ClapTrap::getName(void) const{
    return this->_name;
}

void ClapTrap::attack(const std::string & target)
{
    if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
        std::cout << this->_name << " ClapTrap can't attack. It is dead." << std::endl;
    else
    {
        this->_energyPoints--;
        std::cout << this->_name << " ClapTrap attacks " << target << ". EP (-1)" << std::endl;
        std::cout << COLOR_START << "HP : " << this->_hitPoints << " EP : " << this->_energyPoints <<  " AD : " << this->_attackDamage << COLOR_END << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << this->_name << " lost " << amount << " damages." << std::endl;
    if (amount >= this->_hitPoints)
    {
        std::cout << this->_name << " is dead. Bye..." << std::endl;
        this->_hitPoints = 0;
    }
    else
        this->_hitPoints -= amount;
    std::cout << COLOR_START << "HP : " << this->_hitPoints << " EP : " << this->_energyPoints <<  " AD : " << this->_attackDamage << COLOR_END << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << this->_name << " is repairing +" << amount << " hitpoints." << ". EP (-1)" << std::endl;
    this->_energyPoints--;
    this->_hitPoints += amount;
    std::cout << COLOR_START << "HP : " << this->_hitPoints << " EP : " << this->_energyPoints <<  " AD : " << this->_attackDamage << COLOR_END << std::endl;
}