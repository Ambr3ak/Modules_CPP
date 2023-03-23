#ifndef CLASS_NAME_HPP
#define CLASS_NAME_HPP

#include <iostream>

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

class CLASS_NAME{

public:
        CLASS_NAME();
        CLASS_NAME (const CLASS_NAME & src);
        ~CLASS_NAME(void);
        CLASS_NAME & operator=(CLASS_NAME const & value);
private:
       
};

#endif
