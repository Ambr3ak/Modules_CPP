#ifndef Cure_HPP
#define Cure_HPP

#include <iostream>
#include "AMateria.hpp"

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_END "\033[0m"

class Cure : public AMateria{

public:
        Cure(void);
        Cure (const Cure & src);
        ~Cure(void);
        Cure & operator=(Cure const & value);
        virtual Cure * clone(void) const;
        void use(ICharacter& target);
private:
       
};

#endif
