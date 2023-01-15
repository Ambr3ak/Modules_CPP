#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal"){
    std::cout << COLOR_GREEN << "[WRONGANIMAL] Constructor called." << COLOR_END << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type){

}

WrongAnimal::WrongAnimal(const WrongAnimal & src){
    std::cout << COLOR_YELLOW << "[WRONGANIMAL] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

WrongAnimal::~WrongAnimal(void){
    std::cout << COLOR_RED << "[WRONGANIMAL] Destructor called" << COLOR_END << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & value){

    std::cout << COLOR_YELLOW << "[WRONGANIMAL] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        this->type =  value.type;
    }
    return *this;
}

std::string WrongAnimal::getType(void) const{
    return this->type;
}

void WrongAnimal::makeSound(void) const{
    std::cout << "****WrongAnimal noise****" << std::endl;
}