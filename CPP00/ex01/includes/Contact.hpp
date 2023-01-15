#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

# include <string>
# include <iostream>

class Contact
{
    private:
            std::string _first_name;
            std::string _last_name;
            std::string _nickname;
            std::string _phone_number;
            std::string _darkest_secret;

    public:

            Contact(void);
            ~Contact(void);

            bool set_informations(void);
            bool SetInformationsOldest(void);
            void get_informations(void) const; 
            void print_contact(void) const;
};

#endif