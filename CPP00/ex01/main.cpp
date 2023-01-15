#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    std::string buf;
    PhoneBook page_contact;

    std::cout << "Enter a command (ADD, SEARCH, EXIT):" << std::endl;
    while (buf != "EXIT" || std::cin.eof() == false)
    {
        std::cout << "> ";
        std::getline(std::cin, buf);
        if (buf == "ADD")
           page_contact.set_contact();
        else if (buf == "SEARCH")
            page_contact.get_contact();
        if (buf == "EXIT" || std::cin.eof() == true)
        {
            std::cout << "Bye" << std::endl;
            break;
        }
        else
            std::cout << "Please ADD, SEARCH or EXIT" << std::endl;
    }
    return (0);
}