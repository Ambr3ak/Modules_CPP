#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void): _fixedValue(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & src){
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed(void){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedValue;
}

void Fixed::setRawBits(int const raw){

    this->_fixedValue = raw;
}

Fixed & Fixed::operator=(Fixed const & value){

    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &value)
        this->_fixedValue = value.getRawBits();

    return *this;
}

