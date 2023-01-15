#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresForm", 25, 5), _target(target){
    std::cout << COLOR_GREEN << "[PresidentialPardonForm] Constructor called." << COLOR_END << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src) : AForm(src){
    std::cout << COLOR_YELLOW << "[PresidentialPardonForm] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void){
    std::cout << COLOR_RED << "[PresidentialPardonForm] Destructor called" << COLOR_END << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & value) {

    std::cout << COLOR_YELLOW << "[PresidentialPardonForm] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        this->_target = value._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor){
    if (executor.getGrade() <= getGradeExec() && getIsSigned())
    {
        std::cout << _target << " has been forgiven by  Zaphod Beeblebrox." << std::endl;
    }
    else
        throw GradeTooLowException();
}
