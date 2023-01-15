#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubby", 147, 137), _target(target){
    std::cout << COLOR_GREEN << "[ShrubberyCreationForm] Constructor called." << COLOR_END << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src) : AForm(src){
    std::cout << COLOR_YELLOW << "[ShrubberyCreationForm] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
    std::cout << COLOR_RED << "[ShrubberyCreationForm] Destructor called" << COLOR_END << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & value) {

    std::cout << COLOR_YELLOW << "[ShrubberyCreationForm] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        this->_target = value._target;
    }
    return *this;
}

std::string ShrubberyCreationForm::getTargetName(void)const {
    return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor){
    if (executor.getGrade() <= getGradeExec() && getIsSigned())
    {
        std::ofstream ofs(getTargetName().append("_shrubbery").c_str());
        ofs << "       _-_       \n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\\n" << std::endl;ofs << "       _-_       \n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\\n" << std::endl;ofs << "       _-_       \n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\\n" << std::endl;ofs << "       _-_       \n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\\\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\\\n" << std::endl;
    }
    else
        throw GradeTooLowException();
}