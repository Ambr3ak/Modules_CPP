#include "RPN.hpp"

int main(int ac, char **av){
    
    if (ac == 2){
            RPN calcul;

            try{
                calcul.executeCalcul(av[1]);
            }
             catch  (std::exception & e){
                std::cout << e.what();
            }
            return 0;
        }
    std::cout << "Bad arguments" << std::endl;
    return 0;
}