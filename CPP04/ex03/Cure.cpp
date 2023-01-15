#include "Cure.hpp"

Cure::Cure(void): AMateria("cure") {
    std::cout << COLOR_GREEN << "[CURE] Constructor called." << COLOR_END << std::endl;
}

Cure::Cure(const Cure & src) : AMateria(src){
    std::cout << COLOR_YELLOW << "[CURE] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

Cure::~Cure(void){
    std::cout << COLOR_RED <<"[CURE] Destructor called" << COLOR_END << std::endl;
}

Cure & Cure::operator=(Cure const & value){

    std::cout << COLOR_YELLOW << "[CURE] Copy assignement operator called"<< COLOR_END << std::endl;
    if (&value != this)
    {
       //some copy
    }
    return *this;
}

void Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure* Cure::clone(void) const{
    return (new Cure(*this));
}