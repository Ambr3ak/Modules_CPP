#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_END "\033[0m"

class MateriaSource : public IMateriaSource{

public:
        MateriaSource();
        MateriaSource (const MateriaSource & src);
        virtual ~MateriaSource(void);
        MateriaSource & operator=(MateriaSource const & value);

        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);

private:
        int _index;
        AMateria *_copyMateria[4];
};

#endif
