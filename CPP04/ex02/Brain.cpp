#include "Brain.hpp"

Brain::Brain() : index(0){
    std::cout << COLOR_GREEN << "[BRAIN] Constructor called." << COLOR_END << std::endl;
}

Brain::Brain(const Brain & src){
    std::cout << COLOR_YELLOW << "[BRAIN] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

Brain::~Brain(void){
    std::cout << COLOR_RED << "[BRAIN] Destructor called" << COLOR_END << std::endl;
}

Brain & Brain::operator=(Brain const & value){

    std::cout << COLOR_YELLOW << "[BRAIN] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
       for (int i = 0; i < 100; i++)
            this->_ideas[i] = value._ideas[i];
        this->index = value.index;
    }
    return *this;
}

void Brain::setIdea(std::string idea)
{
    _ideas[index] = idea;
    index++;
}

void Brain::getIdeas(void)
{
    for (int i = 0; i < index; i++)
    {
        std::cout << _ideas[i] << std::endl;
    }

    return ;
}
