#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{   
    std::cout << COLOR_PINK << "SHRUBBERY CREATION FORM" << COLOR_END << std::endl;
    AForm *shrub = new ShrubberyCreationForm("Garden");
    Bureaucrat *bob = new Bureaucrat("Bob", 17);

    std::cout << "Name form is " << shrub->getName() << std::endl;
    std::cout << "Name of Bureaucrat is " << bob->getName() << std::endl;
    try{
        bob->signForm(*shrub);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    bob->executeForm(*shrub);

    std::cout << COLOR_PINK << "ROBOTOMY REQUEST FORM" << COLOR_END << std::endl;
    AForm *robot = new RobotomyRequestForm("Human");
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
    
    AForm *seriousForm = new PresidentialPardonForm("Human");
    Bureaucrat *president = new Bureaucrat("Norminet", 1);

    std::cout << "Name form is " << seriousForm->getName() << std::endl;
    std::cout << "Name of Bureaucrat is " << president->getName() << std::endl;

    try{
        president->signForm(*seriousForm);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    president->executeForm(*seriousForm);
    try{
        president->signForm(*seriousForm);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    delete bob;
    delete shrub;
    delete rob;
    delete robot;
    delete president;
    delete seriousForm;
    return 0;
}