#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

class Intern{

public:
        Intern();
        Intern (const Intern & src);
        ~Intern(void);
        Intern & operator=(Intern const & value);

        class NoValideFormName: public std::exception
        {
        public:
                virtual const char* what() const throw()
                {
                    return "Intern cannot create a form : not a valid form Name\nPlease try : Shrubbery Creation, Robotomy Request or Presidential Pardon";
                }
        };
        AForm * makeForm(std::string nameForm, std::string targetNameForm);
        int getLevel(std::string level);
        AForm * newShrubberyForm(std::string target);
        AForm * newRobotomyForm(std::string target);
        AForm * newPresidentialForm(std::string target);
private:
       
};

#endif

