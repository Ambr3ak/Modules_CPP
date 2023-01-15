#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("stranger"), _grade(150){
    std::cout << COLOR_GREEN << "[Bureaucrat] Constructor called." << COLOR_END << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade) {
    std::cout << COLOR_GREEN << "[Bureaucrat] Constructor called." << COLOR_END << std::endl;
    std::cout << "[" << _name << "] grade : " << _grade << std::endl;
    if (_grade > 150)
        throw GradeTooHighException();
    else if (_grade <= 0)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat & src){
    std::cout << COLOR_YELLOW << "[Bureaucrat] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

Bureaucrat::~Bureaucrat(void){
    std::cout << COLOR_RED << "[Bureaucrat] Destructor called" << COLOR_END << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & value) {

    std::cout << COLOR_YELLOW << "[Bureaucrat] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        this->_grade = value.getGrade();
    }
    return *this;
}

Bureaucrat Bureaucrat::operator++(int n)
{
    Bureaucrat temp(*this);
    
    if (n)
        this->_grade += n;
    else
        this->_grade++;
    return (temp);
}

Bureaucrat Bureaucrat::operator--(int n)
{
    Bureaucrat temp(*this);

    if (n)
        this->_grade -= n;
    else
        this->_grade--;
    return (temp);
}

std::string Bureaucrat::getName(void) const{
    return _name;
}

int Bureaucrat::getGrade(void) const{
    return _grade;
}

void Bureaucrat::upgradeStatus(int n){
    if (n)
        this->_grade -= n;
    else
        this->_grade--;
    std::cout << "[" << _name << "] New grade : " << _grade << std::endl;
    if (_grade > 150)
        throw GradeTooHighException();
    else if (_grade <= 0)
        throw GradeTooLowException();
}

void Bureaucrat::downgradeStatus(int n){
   if (n)
        this->_grade += n;
    else
        this->_grade++;
    std::cout << "[" << _name << "] New grade : " << _grade << std::endl;
    if (_grade > 150)
        throw GradeTooHighException();
    else if (_grade <= 0)
        throw GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return o;
}