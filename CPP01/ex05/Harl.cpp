#include "Harl.hpp"
#include <cstdlib>

Harl::Harl(void)
{

}

Harl::~Harl(void)
{

}

void Harl::debug(void)
{
     std::cout << "DEBUG - " << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "INFO - " << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::error(void)
{
    std::cout << "ERROR - "  << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::warning(void)
{
     std::cout << "WARNING - "  << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

typedef void(Harl::*fPtr)();

int Harl::getLevel(std::string level)
{
    const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;

    while (i < 4)
    {
        if (levels[i] == level)
            return (i);
        i++;
    }
    return (-1);
}

void Harl::complain(std::string level)
{
    fPtr f[4] = {
        &Harl::debug, 
        &Harl::info, 
        &Harl::warning, 
        &Harl::error,
        };

    int j = 0;
    int i = getLevel(level);
    if (i != -1)
        while (j <= i)
        {
            (this->*f[j])();
            j++;
        }
}
