#ifndef Cat_HPP
#define Cat_HPP

#include <iostream>
#include "Animal.hpp"

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_END "\033[0m"

class Cat : public Animal {

public:
        Cat();
        Cat (const Cat & src);
        virtual ~Cat(void);
        Cat & operator=(Cat const & value);

        virtual void makeSound(void) const;
};

#endif
