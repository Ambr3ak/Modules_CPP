#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"


class Bureaucrat{

public:
        Bureaucrat(void);   
        Bureaucrat(std::string const name, int grade);
        Bureaucrat (const Bureaucrat & src);
        ~Bureaucrat(void);
        Bureaucrat & operator=(Bureaucrat const & value);
        Bureaucrat operator++(int n);
        Bureaucrat operator--(int n);

        std::string getName(void) const;
        int getGrade(void) const;

        void downgradeStatus(int n);
        void upgradeStatus(int n);

        class GradeTooHighException: public std::exception
        {
        public:
                virtual const char* what() const throw()
                {
                        return "Grade is over 150.";
                }
        };
        class GradeTooLowException: public std::exception
        {
        public:
                virtual const char* what() const throw()
                {
                        return "Grade is under 1.";
                }
        };
                
private:
       std::string const _name;
        int _grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
