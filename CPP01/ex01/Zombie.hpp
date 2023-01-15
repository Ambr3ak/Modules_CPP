#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie{

private:
        std::string _name;

public:
        Zombie(void)
        {
        }
        ~Zombie(void)
        {
            std::cout << _name << " has been killed." << std::endl;
        }
        void announce(void)
        {
            std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
        }
        void setName(std::string name)
        {
            this->_name = name;
        }
};

Zombie*    zombieHorde( int N, std::string name );

#endif