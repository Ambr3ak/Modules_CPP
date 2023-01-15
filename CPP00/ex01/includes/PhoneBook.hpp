#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.hpp"

class PhoneBook
{

private:
        Contact _repertoire[8];
        int     _index;
        int     _oldest;
public:
        PhoneBook(void);
        ~PhoneBook(void);

        void set_contact(void);
        void get_contact(void) const;
};

#endif
