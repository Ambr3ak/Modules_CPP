#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"


#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"


class AMateria{

protected :
                std::string _type;

public:
        AMateria(std::string const & type);
        AMateria (const AMateria & src);
        virtual ~AMateria(void);
        AMateria & operator=(AMateria const & value);

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        
        virtual void use(ICharacter& target);
};

#endif
