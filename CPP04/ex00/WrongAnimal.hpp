#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"


class WrongAnimal{

protected:
        std::string type;

public:
        WrongAnimal(void);
        WrongAnimal(std::string type);
        WrongAnimal (const WrongAnimal & src);
        virtual ~WrongAnimal(void);
        WrongAnimal & operator=(WrongAnimal const & value);

        std::string getType() const;
        void makeSound(void) const;

};


#endif
