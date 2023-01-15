#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

class Animal{

public:
        Animal(void);
        Animal (std::string type);
        Animal (const Animal & src);
        virtual ~Animal(void);
        Animal & operator=(Animal const & value);

        std::string getType() const;
        virtual void makeSound(void) const;

protected:
        std::string type;
};

#endif
