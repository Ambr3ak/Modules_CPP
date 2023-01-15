#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal"){
    std::cout << COLOR_GREEN << "[AANIMAL] Constructor called." << COLOR_END << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type){
    std::cout << COLOR_GREEN << "[AANIMAL] param Constructor called." << COLOR_END << std::endl;

}

AAnimal::AAnimal(const AAnimal & src){
    std::cout << COLOR_YELLOW << "[AANIMAL] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

AAnimal::~AAnimal(void){
    std::cout << COLOR_RED << "[AANIMAL] Destructor called" << COLOR_END << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & value){

    std::cout << COLOR_YELLOW << "Animal Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        this->type = value.type;
    }
    return *this;
}

std::string AAnimal::getType(void) const{
    return this->type;
}

void AAnimal::makeSound(void) const{
    std::cout << "****Animal noise****" << std::endl;
}
