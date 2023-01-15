#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

class Dog : public Animal {

public:
        Dog();
        Dog (const Dog & src);
        virtual ~Dog(void);
        Dog & operator=(Dog const & value);

        virtual void makeSound(void) const;
        virtual Brain * getBrain(void);
private:
        Brain *_brain;
};

#endif
