#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type){
    std::cout << COLOR_GREEN << "[AMATERIA] " << "Constructor called." << COLOR_END << std::endl;
}

AMateria::AMateria(const AMateria & src){
    std::cout << COLOR_YELLOW << "[AMATERIA] " << "Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

AMateria::~AMateria(void){
    std::cout << COLOR_RED << "[AMATERIA] " << "Destructor called" << COLOR_END << std::endl;
}

AMateria & AMateria::operator=(AMateria const & value){

    std::cout << COLOR_YELLOW << "[AMATERIA] " << "Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        this->_type = value._type;
    }
    return *this;
}


std::string const & AMateria::getType() const{
    return _type;
}

void AMateria::use(ICharacter& target){
    std::cout << target.getName() << " random use of Materia." << std::endl;
}