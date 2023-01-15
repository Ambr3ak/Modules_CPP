#include "A.hpp"

A::A() : Base("A"){
    std::cout << COLOR_GREEN << "[A] Constructor called." << COLOR_END << std::endl;
}

A::A(std::string type) : Base(type){
    std::cout << COLOR_GREEN << "[A] Param Constructor called." << COLOR_END << std::endl;
}

A::A(const A & src){
    std::cout << COLOR_YELLOW << "[A] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

A::~A(void){
    std::cout << COLOR_RED << "[A] Destructor called" << COLOR_END << std::endl;
}

A & A::operator=(A const & value) {

    std::cout << COLOR_YELLOW << "[A] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        //some copy
    }
    return *this;
}