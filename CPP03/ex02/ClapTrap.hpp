#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

class ClapTrap{

public:
        ClapTrap(std::string name);
        ClapTrap (const ClapTrap & src);
        ~ClapTrap(void);
        ClapTrap & operator=(ClapTrap const & value);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        int getEnergyPoints(void) const;
        int getHitPoints(void) const;
        int getDamagePoints(void) const;
        std::string getName(void) const;
        
        void setEnergyPoints(int const new_points);
        void setHitPoints(int const new_points);
        void setDamagePoints(int const new_points);
private:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
};

#endif
