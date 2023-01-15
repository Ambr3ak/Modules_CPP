#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    {
        ClapTrap	clapTrap1("Clappy");
        ClapTrap	clapTrap2("Trappy");
        ScavTrap    ScavTrap1("Scavy");

        clapTrap1.attack(clapTrap2.getName());
        clapTrap1.takeDamage(10);
        clapTrap1.beRepaired(10);

        ScavTrap1.attack("random");
        ScavTrap1.takeDamage(10);
        ScavTrap1.beRepaired(10);
        ScavTrap1.guardGate();
    }
}