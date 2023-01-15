#include "B.hpp"

B::B() : Base("B"){
    std::cout << COLOR_GREEN << "[B] Constructor called." << COLOR_END << std::endl;
}

B::B(std::string type) : Base(type){
    std::cout << COLOR_GREEN << "[B] Param Constructor called." << COLOR_END << std::endl;
}

B::B(const B & src){
    std::cout << COLOR_YELLOW << "[B] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

B::~B(void){
    std::cout << COLOR_RED << "[B] Destructor called" << COLOR_END << std::endl;
}

B & B::operator=(B const & value) {

    std::cout << COLOR_YELLOW << "[B] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        //some copy
    }
    return *this;
}