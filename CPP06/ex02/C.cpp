#include "C.hpp"

C::C() : Base("C"){
    std::cout << COLOR_GREEN << "[C] Constructor called." << COLOR_END << std::endl;
}

C::C(std::string type) : Base(type){
    std::cout << COLOR_GREEN << "[C] Param Constructor called." << COLOR_END << std::endl;
}

C::C(const C & src){
    std::cout << COLOR_YELLOW << "[C] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

C::~C(void){
    std::cout << COLOR_RED << "[C] Destructor called" << COLOR_END << std::endl;
}

C & C::operator=(C const & value) {

    std::cout << COLOR_YELLOW << "[C] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        //some copy
    }
    return *this;
}