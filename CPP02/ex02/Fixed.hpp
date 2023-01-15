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

        bool operator==(Fixed const & value2);
        bool operator>(Fixed const & value2);
        bool operator>=(Fixed const & value2);
        bool operator<(Fixed const & value2);
        bool operator<=(Fixed const & value2);   
        bool operator!=(Fixed const & value2);

        Fixed operator+(Fixed const & value) const;
        Fixed operator-(Fixed const & value) const;
        Fixed operator*(Fixed const & value) const;
        Fixed operator/(Fixed const & value) const;
        Fixed & operator++(void);
        Fixed & operator--(void);

        Fixed operator++(int n);
        Fixed operator--(int n);
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;

        static const Fixed & min(Fixed const & a, Fixed const & b);
        static Fixed & min(Fixed & a, Fixed & b);
        static const Fixed & max(Fixed const & a, Fixed const & b);
        static Fixed &max(Fixed & a, Fixed & b);

};

std::ostream & operator<<(std::ostream & o, Fixed const & value);

#endif