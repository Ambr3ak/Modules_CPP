#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): _fixedValue(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & src){
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const int IntegerValue){
    std::cout << "Int constructor called" << std::endl;
    this->_fixedValue = IntegerValue << this->_bitValue; //transformer en virgule fixe on decale a gauche
}

Fixed::Fixed(const float FloatValue){
    std::cout << "Float constructor called" << std::endl;
    this->_fixedValue = roundf(FloatValue * (1 << this->_bitValue)); //algo pour transformer float en fixed
}

Fixed::~Fixed(void){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
    return this->_fixedValue;
}

void Fixed::setRawBits(int const raw){

    this->_fixedValue = raw;
}

float Fixed::toFloat( void ) const{

    return((float)this->_fixedValue / (float)(1 << this->_bitValue));
}

int Fixed::toInt( void ) const{

    return (this->_fixedValue >> this->_bitValue);
}

Fixed & Fixed::operator=(Fixed const & value){

    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &value)
        this->_fixedValue = value.getRawBits();

    return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & value)
{
	o << value.toFloat();
	return o;
}
