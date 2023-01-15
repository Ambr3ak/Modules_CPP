#include "Intern.hpp"

Intern::Intern(void){
    std::cout << COLOR_GREEN << "[Intern] Constructor called." << COLOR_END << std::endl;
}

Intern::Intern(const Intern & src){
    std::cout << COLOR_YELLOW << "[Intern] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

Intern::~Intern(void){
    std::cout << COLOR_RED << "[Intern] Destructor called" << COLOR_END << std::endl;
}

Intern & Intern::operator=(Intern const & value) {

    std::cout << COLOR_YELLOW << "[Intern] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        //some copy
    }
    return *this;
}

int Intern::getLevel(std::string level)
{
    const std::string levels[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i = 0;
    int j = 0;
    std::string form;

    for (std::string::iterator it = level.begin(); it != level.end(); it++)
    {
        form += std::tolower(level[j]);
        j++;
    }
    while (i < 3)
    {
        if (levels[i] == form)
            return (i);
        i++;
    }
    throw NoValideFormName();
}

AForm * Intern::newShrubberyForm(std::string target){
    return (new ShrubberyCreationForm(target));
}

AForm * Intern::newRobotomyForm(std::string target){
    return (new RobotomyRequestForm(target));
}

AForm * Intern::newPresidentialForm(std::string target){
    return (new PresidentialPardonForm(target));
}

typedef AForm *(Intern::*fPtr)(std::string target);

AForm * Intern::makeForm(std::string nameForm, std::string targetNameForm){
    fPtr f[3] = {
        &Intern::newShrubberyForm, 
        &Intern::newRobotomyForm, 
        &Intern::newPresidentialForm, 
        };

    try
    {
        int i = getLevel(nameForm);
        std::cout << "Intern creates " << nameForm << std::endl;
        return ((this->*f[i])(targetNameForm));
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return (NULL);
}
