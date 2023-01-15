#include "Dog.hpp"

Dog::Dog(): Animal("Dog"), _brain(new Brain()){
    std::cout << COLOR_GREEN << "[DOG] Constructor called." << COLOR_END << std::endl;
}

Dog::Dog(const Dog & src) : Animal(src), _brain(NULL){
    std::cout << COLOR_YELLOW << "[DOG] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

Dog::~Dog(void){
    std::cout << COLOR_RED << "[DOG] Destructor called" << COLOR_END << std::endl;
    delete _brain;
}

Dog & Dog::operator=(Dog const & value){

    std::cout << COLOR_YELLOW << "[DOG] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        this->type =  value.type;
        if (this->_brain != NULL)
            delete this->_brain;
        this->_brain = new Brain(*(value._brain));
    }
    return *this;
}

void Dog::makeSound(void) const{
    std::cout << "Ouaf ouaf ouaf" << std::endl;
}

Brain * Dog::getBrain(void)
{
    return _brain;
}