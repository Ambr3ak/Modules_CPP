#include "Character.hpp"

Character::Character(void) : _name("anonymous"), _inventorySize(4), _items(new AMateria*[4]()){
    std::cout << COLOR_GREEN << "[CHARACTER] " << _name << " Constructor called." << COLOR_END << std::endl;
}

Character::Character(std::string name) : _name(name), _inventorySize(4), _items(new AMateria*[4]()) {
    std::cout << COLOR_GREEN << "[CHARACTER] " << _name << " Constructor called." << COLOR_END << std::endl;

}

Character::Character(const Character & src){
    this->_items = new AMateria*[4]();
    std::cout << COLOR_YELLOW << "[CHARACTER] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

Character::~Character(void){
    std::cout << COLOR_RED << "[CHARACTER] Destructor called" << COLOR_END << std::endl;
    for (int i = 0; i < _inventorySize ; i++)
    {
        if (_items[i])
        {
            delete _items[i];
            _items[i] = NULL;
        }
    }
    delete[] _items;
}

void Character::deleteItems(AMateria ** items)
{
    for (int i = 0; i < 4 ;i++)
    {
        if (items[i] != NULL)
            delete items[i];
    }
    delete[] items;
}

Character & Character::operator=(Character const & value){

    std::cout << COLOR_YELLOW << "[CHARACTER] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        AMateria **itemsNew = new AMateria*[4]();
       _name = value._name;
       _inventorySize = value._inventorySize;
        if (this->_items)
            deleteItems(this->_items);
        for (int i = 0; i < 4; i++)
        {
            if (value._items[i])
                itemsNew[i] = value._items[i]->clone();
            else
                itemsNew[i] = NULL;
        }
        this->_items = itemsNew;
    }
    return *this;
}

std::string const & Character::getName() const{
    return (this->_name);
}

void Character::equip(AMateria* m){
    for (int i = 0; i < _inventorySize; i++)
    {
        if (_items[i] == NULL)
        {
            std::cout << _name << " got a new Materia ! Of type " << m->getType() << "." << std::endl;
            _items[i] = m;
            return ;
        }
    }
    std::cout << "Inventory is full..." << std::endl;
}

void Character::unequip(int idx){
    
    if (idx < _inventorySize)
    {
        std::cout << "Materia " << _items[idx]->getType() << " left on the ground." << std::endl;
        //delete _items [idx];
        _items[idx] = NULL;
    }
    if (idx >= _inventorySize)
        std::cout << "No materia found." << std::endl;
}

void Character::use(int idx, ICharacter& target){
    if (idx < _inventorySize)
    {   
        if (_items[idx] != NULL)
        {
            _items[idx]->use(target);
            return ;
        }
    }
    std::cout << "No materia found to use." << std::endl;
}

void Character::listInventoryItems(void){
    for (int i = 0; i < _inventorySize; i++)
    {
        if (_items[i])
            std::cout << _items[i]->getType() << std::endl;
    }
}

AMateria * Character::getItems(int index)
{
    return this->_items[index];
}






