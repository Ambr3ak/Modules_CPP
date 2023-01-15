#ifndef  FIXED_HPP
#define FIXED_HPP

class Fixed
{
private :
        int _fixedValue;
        static int const _bitValue = 8;

public :
        Fixed(void);
        Fixed (const Fixed & src);
        ~Fixed(void);
        Fixed & operator=(Fixed const & value);
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
};


#endif