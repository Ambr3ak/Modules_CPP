#include "PhoneBook.hpp"
#include <iomanip>
#include <cstdlib>
 

PhoneBook::PhoneBook(void): _index(-1), _oldest(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::set_contact(void)
{
    Contact informations;
    std::string in;

    if (this->_index == -1)
        this->_index = 0;
    if (this->_index <= 7)
    {
        this->_repertoire[this->_index].set_informations();
        if (std::cin.eof())
            return ;
        this->_index++;
    }
    else
    {
        std::cout << "\033[33mYour phone book is full.\033[0m" << std::endl;
        this->_repertoire[this->_oldest].SetInformationsOldest();
        this->_oldest++;
    }
    std::cout << "\033[34mContact successfully added !\033[0m" << std::endl;
    return ;
}

void PhoneBook::get_contact(void) const
{
    int i = 0;
    std::string index;

    if (this->_index == -1)
    {
        std::cout << "\033[31mPlease add contact before searching.\033[0m" << std::endl;
        return ;
    }
    std::cout << "Here is your contact" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "____________________________________________" << std::endl;
    while (i < this->_index)
    {
        std::cout <<  "|" << std::setw(10) << i << "|";
        this->_repertoire[i].get_informations();
        i++;
    }
    std::cout << "Enter the index of the contact you want to see." << std::endl;
    while (std::getline(std::cin, index))
    {
        if (index.size() != 1)
            std::cout << "\033[31mEnter a valid index.\033[0m" << std::endl;
        else if (index.compare("0") < 0 || index.compare("8") > 0)
            std::cout << "\033[31mEnter a valid index.\033[0m" << std::endl;
        else if (std::atoi(index.c_str()) > this->_index - 1 || std::atoi(index.c_str()) < 0)
            std::cout << "\033[31mEnter a valid index.\033[0m" << std::endl;
        else
        {
            this->_repertoire[std::atoi(index.c_str())].print_contact();
            break;
        }
    }
}