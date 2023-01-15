#ifndef  FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private :
        int _fixedValue;
        static int const _bitValue = 8;

public :
        Fixed(void);
        Fixed(int const IntegerValue);
        Fixed(float const FloatValue);
        Fixed (const Fixed & src);
        ~Fixed(void);
        Fixed & operator=(Fixed const & value);
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & value);

#endif