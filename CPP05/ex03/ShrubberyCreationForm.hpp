#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"


class ShrubberyCreationForm : public AForm{

public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm (const ShrubberyCreationForm & src);
        virtual ~ShrubberyCreationForm(void);
        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & value);

        virtual void execute(Bureaucrat const & executor);
        std::string getTargetName(void) const;
private:
       std::string _target;
};

#endif
