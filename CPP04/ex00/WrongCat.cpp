#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
    std::cout << COLOR_GREEN << "[WRONGCAT] Constructor called." << COLOR_END << std::endl;
}

WrongCat::WrongCat(const WrongCat & src) : WrongAnimal(src){
    std::cout << COLOR_YELLOW << "[WRONGCAT] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

WrongCat::~WrongCat(void){
    std::cout << COLOR_RED << "[WRONGCAT] Destructor called" << COLOR_END << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & value){

    std::cout << COLOR_YELLOW << "[WRONGCAT] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        this->type =  value.type;
    }
    return *this;
}