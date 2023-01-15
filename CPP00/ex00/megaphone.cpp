#include <iostream>
#include <cstring>

int main(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while (i < ac)
        {
            j = 0;
            std::string str = av[i];
           for (std::string::iterator it = str.begin(); it != str.end(); it++)
           {
                std::cout << (char)std::toupper(str[j]);
                j++;
           }
            i++;
        }
    }
    std::cout << std::endl;
    return (0);
}