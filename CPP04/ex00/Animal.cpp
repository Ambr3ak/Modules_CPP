#include "Animal.hpp"

Animal::Animal() : type("Animal"){
    std::cout << COLOR_GREEN << "[ANIMAL] Constructor called." << COLOR_END << std::endl;
}

Animal::Animal(std::string type) : type(type){

}

Animal::Animal(const Animal & src){
    std::cout << COLOR_YELLOW << "[ANIMAL] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

Animal::~Animal(void){
    std::cout << COLOR_RED << "[ANIMAL] Destructor called" << COLOR_END << std::endl;
}

Animal & Animal::operator=(Animal const & value){

    std::cout << COLOR_YELLOW << "[ANIMAL] Copy assignement operator called" << COLOR_END <<std::endl;
    if (&value != this)
    {
        this->type = value.type;
    }
    return *this;
}

std::string Animal::getType(void) const{
    return this->type;
}

void Animal::makeSound(void) const{
    std::cout << "****Animal noise****" << std::endl;
}