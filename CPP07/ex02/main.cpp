#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750


int main(){
    { 
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what();
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what();
        }
        std::cout << "Try deep copy" << std::endl;
        try
        {
            std::cout << "Before tmp = " << tmp[45] << std::endl;
            std::cout << "Before test = " << test[45] << std::endl;
            tmp[45] = 7;
            std::cout << "After tmp = " << tmp[45] << std::endl;
            std::cout << "After test = " << test[45] << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what();
        }
        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;
    }
    {   
        Array<int> tab(10);
        
        std::cout << "-----Test copy constructor & copy assignement------" << std::endl;
        Array<int> copyTab(tab);
        std::cout << "Adress of tab = " << tab.getTab() << std::endl;
        std::cout << "Adress of copyTab = " << copyTab.getTab() << std::endl;

        std::cout << "-----Test size function-----" << std::endl;
        std::cout << "Size of tab = " << tab.size() << std::endl;
        std::cout << "Size of copyTab = " << copyTab.size() << std::endl;

        std::cout << "Try empty array" << std::endl;
        Array<int> empty;

    }    
    return 0;
}