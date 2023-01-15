#include "ClapTrap.hpp"

int main()
{
    {
        ClapTrap	clapTrap1("Clappy");
        ClapTrap	clapTrap2("Robby");

        ClapTrap    copyClappy = clapTrap1;
        clapTrap1.attack(clapTrap2.getName());
        clapTrap2.attack(clapTrap1.getName());
        clapTrap1.takeDamage(10);
        clapTrap1.attack(clapTrap2.getName());
        clapTrap2.takeDamage(5);   
        clapTrap1.beRepaired(10);
        clapTrap2.beRepaired(10); 
        clapTrap2.takeDamage(50);
        clapTrap2.attack(clapTrap1.getName());  

    }
    {
        ClapTrap clapTrap1("Clappy");
        clapTrap1.attack("zombie");
        clapTrap1.attack("zombie");
        clapTrap1.attack("zombie");
        clapTrap1.attack("zombie");
        clapTrap1.attack("zombie");
        clapTrap1.beRepaired(1);
        clapTrap1.beRepaired(1);
        clapTrap1.beRepaired(1);
        clapTrap1.beRepaired(1);
        clapTrap1.beRepaired(1);
        clapTrap1.attack("zombie");
    }
}