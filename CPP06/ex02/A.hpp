#ifndef A_HPP
#define A_HPP

#include <iostream>
#include "Base.hpp"

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

class Base;

class A : public Base{

public:
        A();
        A(std::string type);
        A (const A & src);
        virtual ~A(void);
        A & operator=(A const & value);

};

#endif
