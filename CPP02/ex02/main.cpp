#include <iostream>
#include "Fixed.hpp"

std::string testBool(bool result)
{
    if (result == 1)
        return ("true");
    return ("false");
}

int main( void ) {

    Fixed a;
    Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed const c(Fixed (5.05f) / Fixed(2));

    std::cout << "Tests du sujet" << std::endl;
    std::cout << "OUTPUT   : " << a << std::endl;
    std::cout << "EXPECTED : 0" << std::endl;
    std::cout << "OUTPUT   : " << ++a << std::endl;
    std::cout << "EXPECTED : 0.00390625" << std::endl;
    std::cout << "OUTPUT   : " << a << std::endl;
    std::cout << "EXPECTED : 0.00390625" << std::endl;
    std::cout << "OUTPUT   : " << a++ << std::endl;
    std::cout << "EXPECTED : 0.00390625" << std::endl;
    std::cout << "OUTPUT   : " << a << std::endl;
    std::cout << "EXPECTED : 0.0078125" << std::endl;
    std::cout << "OUTPUT   : " << b << std::endl;
    std::cout << "EXPECTED : 10.1016" << std::endl;
    std::cout << "OUTPUT   : " << Fixed::max( a, b ) << std::endl;
    std::cout << "EXPECTED : 10.1016" << std::endl;
    
    std::cout << "Test comparaison" << std::endl;
    std::cout << " a = " << a << "  b = " << b << std::endl;
    std::cout << " a < b = " << testBool(a < b) << std::endl;
    std::cout << " a > b = " << testBool(a > b) << std::endl;
    std::cout << " a >= b = " << testBool(a >= b) << std::endl;
    std::cout << " a <= b = " << testBool(a <= b) << std::endl;
    std::cout << " a == b = " << testBool(a == b) << std::endl;
    std::cout << " a != b = " << testBool(a != b) << std::endl;

    std::cout << "Tests arithmetiques" << std::endl;
    std::cout << " a = " << a << "  b = " << b << std::endl;
	std::cout << "  a + b = " << a + b << std::endl;
	std::cout << "  a + a = " << a + a << std::endl;
	std::cout << "  a - b = " << a - b << std::endl;
	std::cout << "  a * b = " << a * b << std::endl;
	std::cout << "  a / b = " << a / b << std::endl;

    std::cout << "Tests incrementation" << std::endl;
    std::cout << "  a = " << a << std::endl;
    std::cout << "  ++a = " << ++a << std::endl;
    std::cout << "  a = " << a << std::endl;
    std::cout << "  a++  = " << a++ << std::endl;
    std::cout << "  a = " << a << std::endl;

    std::cout << " a.op--(100) = " << a.operator--(100) << std::endl;
	std::cout << " a = " << a << std::endl;
	std::cout << " a.op++(100) = " << a.operator++(100) << std::endl;
	std::cout << " a = " << a << std::endl;

    std::cout << "Tests decrementation" << std::endl;
    std::cout << "  b = " << b << std::endl;
    std::cout << "  --b = " << --b << std::endl;
    std::cout << "  b = " << b << std::endl;
    std::cout << "  b--  = " << b-- << std::endl;
    std::cout << "  b = " << b << std::endl;

    std::cout << "Tests MIN/MAX" << std::endl;
    std::cout << " a = " << a << "  b = " << b << std::endl;
	std::cout << "  max(a,b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "  min(a,b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "a = " << a << "  c(const) = " << c << std::endl;
	std::cout << "  max(a,c) = " << Fixed::max(a, c) << std::endl;
	std::cout << "  min(a,c) = " << Fixed::min(a, c) << std::endl;
    return 0;

}