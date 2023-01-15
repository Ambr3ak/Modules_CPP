#include "Contact.hpp"
#include <iomanip>

Contact::Contact(void)
{
    
}

Contact::~Contact(void)
{
}

bool Contact::SetInformationsOldest()
{
    this->_first_name = "";
    this->_last_name = "";
    this->_nickname = "";
    this->_phone_number = "";
    this->_darkest_secret = "";
    std::cout << "Please provide :" << std::endl;
    while (this->_first_name.compare("") == 0)
    {
        std::cout << std::setw(18) << "First name : ";
        std::getline(std::cin, this->_first_name);
        if (this->_first_name.compare("") != 0)
            break;
        std::cout << "\033[31mPlease add informations\033[0m." << std::endl;
    }
    while (this->_last_name.compare("") == 0)
    {
        std::cout << std::setw(18) << "Last name : ";
        std::getline(std::cin, this->_last_name);
        if (this->_last_name.compare("") != 0)
            break;
        std::cout << "\033[31mPlease add informations\033[0m." << std::endl;
    }
    while (this->_nickname.compare("") == 0)
    {
        std::cout << std::setw(18) << "Nickname : ";
        std::getline(std::cin, this->_nickname);
        if (this->_nickname.compare("") != 0)
            break;
        std::cout << "\033[31mPlease add informations\033[0m." << std::endl;
    }
    while (this->_phone_number.compare("") == 0)
    {
        std::cout << std::setw(18) << "Phone Number : ";
        std::getline(std::cin, this->_phone_number);
        if (this->_phone_number.compare("") != 0)
            break;
        std::cout << "\033[31mPlease add informations\033[0m." << std::endl;
    } 
    while (this->_darkest_secret.compare("") == 0)
    {
        std::cout << std::setw(18) << "Darkest Secret : ";
        std::getline(std::cin, this->_darkest_secret);
        if (this->_darkest_secret.compare("") != 0)
            break;
        std::cout << "\033[31mPlease add informations\033[0m." << std::endl;
    }
    return (1);
}

bool Contact::set_informations()
{
    std::cout << "Please provide :" << std::endl;

    while (this->_first_name.compare("") == 0 && std::cin.eof() == false)
    {
        std::cout << std::setw(18) << "First name : ";
        std::getline(std::cin, this->_first_name);
        if (this->_first_name.compare("") != 0)
            break;
        std::cout << "\033[31mPlease add informations\033[0m." << std::endl;
    }
    while (this->_last_name.compare("") == 0 && std::cin.eof() == false)
    {
        std::cout << std::setw(18) << "Last name : ";
        std::getline(std::cin, this->_last_name);
        if (this->_last_name.compare("") != 0)
            break;
        std::cout << "\033[31mPlease add informations\033[0m." << std::endl;
    }
    while (this->_nickname.compare("") == 0 && std::cin.eof() == false)
    {
        std::cout << std::setw(18) << "Nickname : ";
        std::getline(std::cin, this->_nickname);
        if (this->_nickname.compare("") != 0)
            break;
        std::cout << "\033[31mPlease add informations\033[0m." << std::endl;
    }
    while (this->_phone_number.compare("") == 0 && std::cin.eof() == false)
    {
        std::cout << std::setw(18) << "Phone Number : ";
        std::getline(std::cin, this->_phone_number);
        if (this->_phone_number.compare("") != 0)
            break;
        std::cout << "\033[31mPlease add informations\033[0m." << std::endl;
    } 
    while (this->_darkest_secret.compare("") == 0 && std::cin.eof() == false)
    {
        std::cout << std::setw(18) << "Darkest Secret : ";
        std::getline(std::cin, this->_darkest_secret);
        if (this->_darkest_secret.compare("") != 0)
            break;
        std::cout << "\033[31mPlease add informations\033[0m." << std::endl;
    }   
    return (1);
}

void Contact::get_informations(void) const
{
    if (this->_first_name.length() > 10)
        std::cout << this->_first_name.substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << this->_first_name << "|";

    if (this->_last_name.length() > 10)
        std::cout << this->_last_name.substr(0, 9) << ".|";
    else
        std::cout << std::setw(10) << this->_last_name << "|";

    if (this->_nickname.length() > 10)
        std::cout << this->_nickname.substr(0, 9) << ".|" << std::endl;
    else
        std::cout  << std::setw(10) << this->_nickname << "|" << std::endl;
}

void Contact::print_contact(void) const
{
    std::cout << std::setw(17) << "First name : " << this->_first_name << std::endl;
    std::cout << std::setw(17) << "Last name : " << this->_last_name << std::endl;
    std::cout << std::setw(17) << "Nickname : " << this->_nickname << std::endl;
    std::cout << std::setw(17) << "Phone Number : " << this->_phone_number << std::endl;
    std::cout << std::setw(17) << "Darkest Secret : " << this->_darkest_secret << std::endl;
}