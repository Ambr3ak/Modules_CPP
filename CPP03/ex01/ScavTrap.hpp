#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <iostream>

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_END "\033[0m"

class ScavTrap: public ClapTrap{

public:
        ScavTrap(std::string name);
        ScavTrap (const ScavTrap & src);
        ~ScavTrap(void);
        void attack(const std::string & target);
        void guardGate(void);
};

#endif