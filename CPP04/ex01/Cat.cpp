#include "Cat.hpp"

Cat::Cat(): Animal("Cat"), _brain(new Brain()){
    std::cout << COLOR_GREEN << "[CAT] Constructor called." << COLOR_END << std::endl;
}

Cat::Cat(const Cat & src): Animal(src), _brain(new Brain(*src._brain)){
    std::cout <<  COLOR_YELLOW << "[CAT] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

Cat::~Cat(void){
    std::cout << COLOR_RED << "[CAT] Destructor called" << COLOR_END << std::endl;
    delete _brain;
}

Cat & Cat::operator=(Cat const & value){

    std::cout <<  COLOR_YELLOW << "[CAT] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        this->type =  value.type;
        if (this->_brain != NULL)
            delete this->_brain;
        this->_brain = new Brain(*(value._brain));
    }
    return *this;
}

void Cat::makeSound(void) const{
    std::cout << "Miaaaooouuuuuu" << std::endl;
}

Brain * Cat::getBrain(void)
{
    return this->_brain;
}