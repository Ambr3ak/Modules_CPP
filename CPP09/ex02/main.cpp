#include "PmergeMe.hpp"

int main(int ac, char **av){
    
    if (ac > 2){
            PmergeMe sort;

            try{
                sort.initContainers(av);
            }
             catch  (std::exception & e){
                std::cout << e.what();
            }
            return 0;
        }
    std::cout << "Please add 2 or more positive interger." << std::endl;
    return 0;
}