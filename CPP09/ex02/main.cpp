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

            for (size_t i = 0; i < sort.vectorContainer.size(); i++)
			        std::cout << sort.vectorContainer[i] << " ";
            std::cout << std::endl;
            return 0;
        }
    std::cout << "Bad arguments" << std::endl;
    return 0;
}