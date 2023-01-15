#include "Bureaucrat.hpp"

int main()
{
//BASIC TEST GRADE OK
    try {
        Bureaucrat bob = Bureaucrat("Bob", 10);
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl; 
    }
//TEST2 GRADE NEGATIVE
    try {
        Bureaucrat bob = Bureaucrat("Bobby", -1999);
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl; 
    }
//TEST3 INCREMENTENTE
    try {
        Bureaucrat bob = Bureaucrat("Bouby", 3);
        bob.upgradeStatus(1);
        bob.upgradeStatus(1);
        bob.upgradeStatus(1);
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl; 
    }
//TEST4 DOWNGRADE
   try {
        Bureaucrat bob = Bureaucrat("Bouby", 145);
        bob.downgradeStatus(1);
        bob.downgradeStatus(1);
        bob.downgradeStatus(1);
        bob.downgradeStatus(1);
        bob.downgradeStatus(1);
        bob.downgradeStatus(1);
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl; 
    }

    return 0;
}