#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string const name, int const gradeSigned, int const gradeExec) : _name(name), _isSigned(false), _gradeSigned(gradeSigned) , _gradeExec(gradeExec){
    std::cout << COLOR_GREEN << "[Form] Constructor called." << COLOR_END << std::endl;
    if (_gradeSigned > 150 || _gradeExec > 150)
        throw GradeTooHighException();
    else if (_gradeSigned <= 0 || _gradeExec <= 0)
        throw GradeTooLowException();
}

Form::Form(const Form & src): _name(src._name), _gradeSigned(src._gradeSigned) , _gradeExec(src._gradeExec){
    std::cout << COLOR_YELLOW <<  "[Form] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

Form::~Form(void){
    std::cout << COLOR_RED <<"[Form] Destructor called" << COLOR_END << std::endl;
}

Form & Form::operator=(Form const & value){

    std::cout << COLOR_YELLOW << "[Form] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
       this->_isSigned = value._isSigned;
    }
    return *this;
}

std::string Form::getName(void) const{
    return _name;
}

int Form::getGradeSigned(void) const{
    return _gradeSigned;
}

int Form::getGradeExec(void) const{
    return _gradeExec;
}

bool Form::getIsSigned(void) const{
    return _isSigned;
}

void Form::beSigned(Bureaucrat & signator){
    if (signator.getGrade() <= _gradeSigned && _isSigned == false)
        this->_isSigned = true;
    else
        throw GradeTooLowException();
    return ;
}

std::ostream & operator<<(std::ostream & o, Form const & rhs)
{
	o << "Form : " << std::endl;
    o << std::setw(20) << "Name : " << rhs.getName() << std::endl;
    o << std::setw(20) << "Is signed : " << rhs.getIsSigned() << std::endl;
    o << std::setw(20) << "Grade required : " << rhs.getGradeSigned() << std::endl;
    o << std::setw(20) << "Grade to execute : " << rhs.getGradeExec() << std::endl;

	return o;
}