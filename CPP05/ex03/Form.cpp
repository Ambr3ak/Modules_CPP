#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

AForm::AForm(std::string const name, int const gradeSigned, int const gradeExec) : _name(name), _isSigned(false), _gradeSigned(gradeSigned) , _gradeExec(gradeExec){
    std::cout << COLOR_GREEN << "[AForm] Constructor called." << COLOR_END << std::endl;
    if (_gradeSigned > 150 || _gradeExec > 150)
        throw GradeTooHighException();
    else if (_gradeSigned <= 0 || _gradeExec <= 0)
        throw GradeTooLowException();
}

AForm::AForm(const AForm & src): _name(src._name), _gradeSigned(src._gradeSigned) , _gradeExec(src._gradeExec){
    std::cout << COLOR_YELLOW << "[AForm] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

AForm::~AForm(void){
    std::cout << COLOR_RED <<"[AForm] Destructor called" << COLOR_END << std::endl;
}

AForm & AForm::operator=(AForm const & value){

    std::cout << COLOR_YELLOW << "[AForm] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        this->_isSigned = value._isSigned;
    }
    return *this;
}

std::string AForm::getName(void) const{
    return _name;
}

int AForm::getGradeSigned(void) const{
    return _gradeSigned;
}

int AForm::getGradeExec(void) const{
    return _gradeExec;
}

bool AForm::getIsSigned(void) const{
    return _isSigned;
}

void AForm::beSigned(Bureaucrat & signator){
    if (signator.getGrade() <= _gradeSigned && _isSigned == false)
        this->_isSigned = true;
    else
        throw GradeTooLowException();
    return ;
}

std::ostream & operator<<(std::ostream & o, AForm const & rhs)
{
	o << "AForm : " << std::endl;
    o << std::setw(20) << "Name : " << rhs.getName() << std::endl;
    o << std::setw(20) << "Is signed : " << rhs.getIsSigned() << std::endl;
    o << std::setw(20) << "Grade required : " << rhs.getGradeSigned() << std::endl;
    o << std::setw(20) << "Grade to execute : " << rhs.getGradeExec() << std::endl;

	return o;
}

void AForm::execute(Bureaucrat const & executor){
    if (executor.getGrade() == _gradeExec && _gradeSigned)
    {
        std::cout << "random use" << std::endl;
    }
    else
        throw GradeTooLowException();
}