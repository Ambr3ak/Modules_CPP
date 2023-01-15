#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    {
        ClapTrap	clapTrap1("Clappy");
        ScavTrap    ScavTrap1("Scavy");
        FragTrap    FragTrap1("Fraggy");


        clapTrap1.attack("random");
        clapTrap1.takeDamage(10);
        clapTrap1.beRepaired(10);

        ScavTrap1.attack("random");
        ScavTrap1.takeDamage(10);
        ScavTrap1.beRepaired(10);
        ScavTrap1.guardGate();

        FragTrap1.attack("random");
        FragTrap1.takeDamage(10);
        FragTrap1.beRepaired(10);
        FragTrap1.highFivesGuys();
    }
}