#include <iostream>
#include <cstdlib>
#include <string>
#include "convert.hpp"


int main(int ac, char *av[]){

    Convert castConvert;
    if (ac == 2 && (castConvert.isValidInput(av[1]) || castConvert.isExceptions(av[1])))
        return (0);
    std::cout << "Bad arguments." << std::endl;
    return (0);
}