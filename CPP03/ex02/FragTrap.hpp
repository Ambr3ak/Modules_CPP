#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_END "\033[0m"

class FragTrap : public ClapTrap{

public:
        FragTrap(std::string name);
        FragTrap (const FragTrap & src);
        ~FragTrap(void);
        void highFivesGuys(void);
private:
       
};

#endif
