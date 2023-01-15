#include "Cat.hpp"

Cat::Cat(): Animal("Cat"){
    std::cout << COLOR_GREEN << "[CAT] Constructor called." << COLOR_END << std::endl;
}

Cat::Cat(const Cat & src): Animal(src){
    std::cout << COLOR_YELLOW << "[CAT] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

Cat::~Cat(void){
    std::cout << COLOR_RED << "[CAT] Destructor called" << COLOR_END << std::endl;
}

Cat & Cat::operator=(Cat const & value){

    std::cout << COLOR_YELLOW << "[CAT] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        this->type =  value.type;
    }
    return *this;
}

void Cat::makeSound(void) const{
    std::cout << "Miaaaooouuuuuu" << std::endl;
}