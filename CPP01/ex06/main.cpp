#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl automate;

    if (ac != 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    else
        automate.complain(av[1]);
    return (0);
}