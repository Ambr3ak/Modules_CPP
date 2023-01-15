#include "Ice.hpp"

Ice::Ice(void): AMateria("ice") {
    std::cout << COLOR_GREEN << "[ICE] " << "Constructor called." << COLOR_END << std::endl;
}

Ice::Ice(const Ice & src): AMateria(src){
    std::cout << COLOR_YELLOW << "[ICE] " << "Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

Ice::~Ice(void){
    std::cout << COLOR_RED << "[ICE] " << "Destructor called" << COLOR_END << std::endl;
}

Ice & Ice::operator=(Ice const & value){

    std::cout <<COLOR_YELLOW << "[ICE] " << "Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
       //some copy
    }
    return *this;
}

Ice* Ice::clone(void) const{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}