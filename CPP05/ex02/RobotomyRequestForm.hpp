#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"


class RobotomyRequestForm : public AForm{

public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm (const RobotomyRequestForm & src);
        virtual ~RobotomyRequestForm(void);
        RobotomyRequestForm & operator=(RobotomyRequestForm const & value);

        virtual void execute(Bureaucrat const & executor);

private:
       std::string _target;
};

#endif
