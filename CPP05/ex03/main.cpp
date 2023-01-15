#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{   
    std::cout << COLOR_PINK << "SHRUBBERY CREATION FORM" << COLOR_END << std::endl;
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    Bureaucrat *bob = new Bureaucrat("Bob", 17);

    std::cout << "Name form is " << rrf->getName() << std::endl;
    std::cout << "Name of Bureaucrat is " << bob->getName() << std::endl;
    try{
        bob->signForm(*rrf);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << rrf->getName() << std::endl;
    bob->executeForm(*rrf);

    std::cout << COLOR_PINK << "ROBOTOMY REQUEST FORM" << COLOR_END << std::endl;
    Intern someRandomIntern2;
    AForm* robot;
    robot = someRandomIntern2.makeForm("robotomy request", "Bender");
    Bureaucrat *rob = new Bureaucrat("Rob", 100);

    std::cout << "Name form is " << robot->getName() << std::endl;
    std::cout << "Name of Bureaucrat is " << rob->getName() << std::endl;
    try{
        rob->signForm(*robot);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << robot->getName() << std::endl;
    rob->executeForm(*robot);

    try{
        bob->signForm(*robot);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    bob->executeForm(*robot);


    std::cout << COLOR_PINK << "PRESIDENTIAL PARDON FORM" << COLOR_END << std::endl;
    Intern someRandomIntern3;
    AForm* pardon;
    pardon = someRandomIntern3.makeForm("presidential pardon", "Human");
    Bureaucrat *president = new Bureaucrat("Norminet", 1);
    std::cout << "Name form is " << pardon->getName() << std::endl;
    std::cout << "Name of Bureaucrat is " << president->getName() << std::endl;

    try{
        president->signForm(*pardon);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    president->executeForm(*pardon);
    try{
        president->signForm(*pardon);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << COLOR_PINK << "INVALID FORM" << COLOR_END << std::endl;

    Intern someRandomIntern4;
    AForm* nonValid;
    nonValid = someRandomIntern4.makeForm("shrubberyCreation", "Human");

    delete rrf;
    delete robot;
    delete pardon;
    delete bob;
    delete rob;
    delete president;
  
    return 0;
}