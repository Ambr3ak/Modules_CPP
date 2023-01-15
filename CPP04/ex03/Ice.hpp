#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_END "\033[0m"

class Ice : public AMateria{

public:
        Ice(void);
        Ice (const Ice & src);
        virtual ~Ice(void);
        Ice & operator=(Ice const & value);

        virtual Ice * clone(void) const;
        virtual void use(ICharacter& target);
       
};

#endif
