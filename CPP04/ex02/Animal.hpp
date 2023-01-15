#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

class AAnimal{

public:
        AAnimal(void);
        AAnimal (std::string type);
        AAnimal (const AAnimal & src);
        virtual ~AAnimal(void) = 0;
        AAnimal & operator=(AAnimal const & value);

        std::string getType() const;
        virtual void makeSound(void) const;
        virtual Brain * getBrain() = 0;

protected:
        std::string type;
};

#endif
