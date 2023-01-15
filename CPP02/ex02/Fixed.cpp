#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): _fixedValue(0){
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & src){
    //std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const int IntegerValue){
    //std::cout << "Int constructor called" << std::endl;
    this->_fixedValue = IntegerValue << this->_bitValue; //transformer en virgule fixe on decale a gauche
}

Fixed::Fixed(const float FloatValue){
    //std::cout << "Float constructor called" << std::endl;
    this->_fixedValue = roundf(FloatValue * (1 << this->_bitValue)); //algo pour transformer float en fixed
}

Fixed::~Fixed(void){
    //std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
    return this->_fixedValue;
}

void Fixed::setRawBits(int const raw){

    this->_fixedValue = raw;
}

float Fixed::toFloat( void ) const{

    return((float)this->_fixedValue / (float)(1 << this->_bitValue)); //fixed to float
}

int Fixed::toInt( void ) const{

    return (this->_fixedValue >> this->_bitValue); //fixed to int
}

Fixed & Fixed::operator=(Fixed const & value){

    //std::cout << "Copy assignement operator called" << std::endl;
    if (this != &value)
        this->_fixedValue = value.getRawBits();

    return *this;
}


//Operateurs de comparaison

bool  Fixed::operator==(Fixed const & value2)
{
    if (this->_fixedValue == value2._fixedValue)
            return (true);
    return (false);
};

bool  Fixed::operator>(Fixed const & value2)
{
    if (this->_fixedValue > value2._fixedValue)
            return (true);
    return (false);
};

bool  Fixed::operator>=(Fixed const & value2)
{
    if (this->_fixedValue >= value2._fixedValue)
            return (true);
    return (false);
};

bool  Fixed::operator<(Fixed const & value2)
{
    if (this->_fixedValue < value2._fixedValue)
            return (true);
    return (false);
};

bool  Fixed::operator<=(Fixed const & value2)
{
    if (this->_fixedValue <= value2._fixedValue)
            return (true);
    return (false);
};

bool  Fixed::operator!=(Fixed const & value2)
{
    if (this->_fixedValue != value2._fixedValue)
            return (true);
    return (false);
};

//Operateurs arithmetiques

Fixed Fixed::operator+(Fixed const & value) const
{

    return (Fixed(this->toFloat() + value.toFloat()));
};

Fixed Fixed::operator-(Fixed const & value) const
{
    return (Fixed(this->toFloat() - value.toFloat()));
};

Fixed Fixed::operator*(Fixed const & value) const
{
    return (Fixed(this->toFloat() * value.toFloat()));
}

Fixed Fixed::operator/(Fixed const & value) const
{
    return (Fixed(this->toFloat() / value.toFloat()));
};


//Operateur d'incrementation

Fixed & Fixed::operator++(void)
{
    ++(this->_fixedValue);
    return (*this);
}

Fixed & Fixed::operator--(void)
{
    --(this->_fixedValue);
    return (*this);
}

Fixed Fixed::operator++(int n)
{
    Fixed temp(*this);
    
    if (n)
        this->_fixedValue += n;
    else
        this->_fixedValue++;
    return (temp);
}

Fixed Fixed::operator--(int n)
{
    Fixed temp(*this);

    if (n)
        this->_fixedValue -= n;
    else
        this->_fixedValue--;
    return (temp);
}


 const Fixed & Fixed::min(Fixed const & a, Fixed const & b)
{
    if (a._fixedValue < b._fixedValue)
        return (a);
    else if (a._fixedValue > b._fixedValue)
        return (b);
    return (a);
}

 Fixed & Fixed::min(Fixed & a, Fixed & b)
{
    if (a._fixedValue < b._fixedValue)
        return (a);
    else if (a._fixedValue > b._fixedValue)
        return (b);
    return (a);
}

 const Fixed & Fixed::max(Fixed const & a, Fixed const & b)
{
    if (a._fixedValue > b._fixedValue)
        return (a);
    else if (a._fixedValue < b._fixedValue)
        return (b);
    return (a);
}

 Fixed & Fixed::max(Fixed & a, Fixed & b)
{
    if (a._fixedValue > b._fixedValue)
        return (a);
    else if (a._fixedValue < b._fixedValue)
        return (b);
    return (a);
}


//ostream
std::ostream & operator<<(std::ostream & o, Fixed const & value)
{
	o << value.toFloat();
	return o;
}

