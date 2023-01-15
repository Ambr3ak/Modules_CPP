#include "Harl.hpp"
#include <cstdlib>

Harl::Harl(void)
{

}

Harl::~Harl(void)
{

}

void Harl::_debug(void)
{
     std::cout << "DEBUG - " << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::_info(void)
{
    std::cout << "INFO - " << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_error(void)
{
    std::cout << "ERROR - "  << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::_warning(void)
{
     std::cout << "WARNING - "  << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

typedef void(Harl::*fPtr)();

void Harl::complain(std::string level)
{
    std::string complains[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
    };
    int i = 0;
    int j = 5;
    while (i < 4)
    {
        if (level == complains[i])
        {
            j = i;
            break;
        }
        i++;
    }
    switch (j)
    {
    case 0:
        _debug();
        break;
    case 1:
        _info();
        break;
    case 2:
        _warning();
        break;
    case 3:
        _error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}
