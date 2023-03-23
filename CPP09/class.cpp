#include "Span.hpp"

Span::Span(void){
    std::cout << COLOR_GREEN << "[Span] Constructor called." << COLOR_END << std::endl;
}

Span::Span(const Span & src){
    std::cout << COLOR_YELLOW << "[Span] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

Span::~Span(void){
    std::cout << COLOR_RED << "[Span] Destructor called" << COLOR_END << std::endl;
}

Span & Span::operator=(Span const & value) {

    std::cout << COLOR_YELLOW << "[Span] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        //some copy
    }
    return *this;
}
