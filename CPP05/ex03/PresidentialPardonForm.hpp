#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"


class PresidentialPardonForm : public AForm{

public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm (const PresidentialPardonForm & src);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm & operator=(PresidentialPardonForm const & value);
        virtual void execute(Bureaucrat const & executor);

private:
        std::string _target;
       
};

#endif
