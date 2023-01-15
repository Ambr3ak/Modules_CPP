#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <exception>


#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"


class Base{

public:
        Base();
        Base(std::string type);
        virtual ~Base(void);

        Base * generate(void);
        void identify(Base* p);
        void identify(Base& p);
private:
       std::string _type;
};

#endif
