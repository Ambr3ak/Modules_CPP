#ifndef C_HPP
#define C_HPP

#include <iostream>
#include "Base.hpp"

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

class C : public Base{

public:
        C();
        C(std::string type);
        C (const C & src);
        virtual ~C(void);
        C & operator=(C const & value);

};

#endif