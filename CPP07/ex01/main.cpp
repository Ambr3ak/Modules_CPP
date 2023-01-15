#include "iter.hpp"

template<typename T>
void Print(T & word)
{
    std::cout << word << std::endl;
}

int main()
{
    std::cout << "----------- STRING ARRAY ----------" << std::endl;
    std::string array[4] = {"hello", "ca va ?", "oui", "merci"};
    iter(array, 4, Print);

    std::cout << "------------ INT ARRAY ------------" << std::endl;
    int tab[10] = {1, 2 ,3 ,4 ,5, -8766, 34, 0 , 234 , 4523525};
    iter(tab, 10, Print);

    std::cout << "----------- FLOAT ARRAY -----------" << std::endl;
    float fTab[10] = {0.00001f, 13467645.2f ,3.0004f ,78.4f ,-5.435345f, -8766.435f, 34.02f, 0.0f , 234.098765f , 4523525.023432f};
    iter(fTab, 10, Print);
    return 0;
}