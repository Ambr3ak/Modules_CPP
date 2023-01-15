#include "Dog.hpp"

Dog::Dog(): Animal("Dog"){
    std::cout << COLOR_GREEN << "[DOG] Constructor called." << COLOR_END << std::endl;
}

Dog::Dog(const Dog & src) : Animal(src){
    std::cout << COLOR_YELLOW << "[DOG] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

Dog::~Dog(void){
    std::cout << COLOR_RED << "[DOG] Destructor called" << COLOR_END << std::endl;
}

Dog & Dog::operator=(Dog const & value){

    std::cout << COLOR_YELLOW << "[DOG] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        this->type =  value.type;
    }
    return *this;
}

void Dog::makeSound(void) const{
    std::cout << "Ouaf ouaf ouaf" << std::endl;
}