#ifndef B_HPP
#define B_HPP

#include <iostream>
#include "Base.hpp"

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

class B : public Base{

public:
        B();
        B(std::string type);
        B (const B & src);
        virtual ~B(void);
        B & operator=(B const & value);

};

#endif