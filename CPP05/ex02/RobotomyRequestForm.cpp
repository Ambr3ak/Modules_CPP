#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobbotyForm", 72, 45), _target(target){
    std::cout << COLOR_GREEN << "[RobotomyRequestForm] Constructor called." << COLOR_END << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src) : AForm(src){
    std::cout << COLOR_YELLOW << "[RobotomyRequestForm] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void){
    std::cout << COLOR_RED << "[RobotomyRequestForm] Destructor called" << COLOR_END << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & value) {

    std::cout << COLOR_YELLOW << "[RobotomyRequestForm] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        this->_target = value._target;
    }
    return *this;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor){
    if (executor.getGrade() <= getGradeExec() && getIsSigned())
    {
        std::cout << "BZBZBZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZbzbzbzbzbzbzb\n";
        std::cout << _target << " has been robotomised." << std::endl;
    }
    else
        throw GradeTooLowException();
}