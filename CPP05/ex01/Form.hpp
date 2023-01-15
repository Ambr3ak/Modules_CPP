#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <iomanip>

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_END "\033[0m"

class Bureaucrat;

class Form{

public:
        Form(std::string const name, int const gradeSigned, int const gradeExec);
        Form (const Form & src);
        ~Form(void);
        Form & operator=(Form const & value);

        class GradeTooHighException: public std::exception
        {
        public:
                virtual const char* what() const throw()
                {
                    return "Grade is too high.";
                }
        };
        class GradeTooLowException: public std::exception
        {
        public:
                virtual const char* what() const throw()
                {
                    return "Grade is too low.";
                }
        };

        std::string getName(void) const;
        int getGradeSigned(void) const;
        int getGradeExec(void) const;
        bool getIsSigned(void) const;

        void beSigned(Bureaucrat & signator);
private:
        std::string const _name;
        bool _isSigned;
        int const _gradeSigned;
        int const _gradeExec;

};

std::ostream & operator<<(std::ostream & o, Form const & rhs);


#endif
