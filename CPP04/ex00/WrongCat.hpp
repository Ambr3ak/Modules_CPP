#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_END "\033[0m"

class WrongCat : public WrongAnimal{

protected:
            

public:
        WrongCat();
        WrongCat (const WrongCat & src);
        virtual ~WrongCat(void);
        WrongCat & operator=(WrongCat const & value);

        std::string getType() const;
        void makeSound(void) const;

};

#endif
