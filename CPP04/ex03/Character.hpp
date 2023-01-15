#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter
{
public:
    Character(void);
    Character(std::string name);
    Character (const Character & src);
    virtual ~Character();

    Character & operator=(Character const & value);
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);\

    void listInventoryItems(void);
    AMateria *getItems(int index);
    void deleteItems(AMateria ** items);

private :
    std::string _name;
    int _inventorySize;
    AMateria **_items;
    
}; 

#endif