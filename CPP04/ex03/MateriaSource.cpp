#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _index(0){
    std::cout << COLOR_GREEN << "[MATERIA SOURCE] Constructor called." << COLOR_END << std::endl;
    for (int i = 0; i < 4; i++)
        _copyMateria[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource & src){
    std::cout << COLOR_YELLOW << "[MATERIA SOURCE] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

MateriaSource::~MateriaSource(void){
    std::cout << COLOR_RED << "[MATERIA SOURCE] Destructor called" << COLOR_END << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_copyMateria[i])
            delete _copyMateria[i];
    }
}

MateriaSource & MateriaSource::operator=(MateriaSource const & value){

    std::cout << COLOR_YELLOW << "[MATERIA SOURCE] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
       this->_index = value._index;
       for (int i = 0; i < 4; i++)
       {
             if (_copyMateria[i])
                delete _copyMateria[i];
            if (value._copyMateria[i])
                _copyMateria[i] = value._copyMateria[i]->clone();
            else
                _copyMateria[i] = NULL;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* src){

    for(int i = 0; i < 4; i++)
    {
        if (_copyMateria[i] == NULL)
        {
            _copyMateria[i] = src;
            return ;
        }
    }
    std::cout << "Inventory is full..." << std::endl;
    delete src;
}

AMateria* MateriaSource::createMateria(std::string const & type){

    for (int i = 0; i <= 4; i++)
    {
        if (_copyMateria[i]->getType() == type)
        {
            return (_copyMateria[i]->clone());
        }
    }
    std::cout << "Cannot create Materia Source. Inventory full." << std::endl;
    return (0);
}