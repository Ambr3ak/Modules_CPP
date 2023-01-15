#ifndef Cat_HPP
#define Cat_HPP

#include <iostream>
#include "AAnimal.hpp"

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

class Cat : public AAnimal {

public:
        Cat();
        Cat (const Cat & src);
        virtual ~Cat(void);
        Cat & operator=(Cat const & value);

        virtual void makeSound(void) const;
        virtual Brain * getBrain(void);
private:
        Brain *_brain;
};

#endif
