#include <iostream>
#include <fstream>
#include <cstring>


int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Please launch the program as ./filestream <filename> <str1> <str2>." << std::endl;
        return (0);
    }
    std::ifstream ifs(av[1]);
    std::string line;
    std::string file = av[1];
    std::string str1 = av[2];
    std::string str2 = av[3];
    std::size_t find;

    if (!ifs.is_open())
    {
        std::cout << "Please add an existed file." << std::endl;
        return (0);
    }
    std::ofstream ofs(file.append(".replace").c_str());
    if (!ofs.is_open())
    {
        std::cout << "Bad outfile." << std::endl;
        return (0);
    }

    while (std::getline(ifs, line))
    {
        find = line.find(str1);
        while (1)
        {
            if (find == std::string::npos)
                break;
            line.erase(find, str1.size());
            line.insert(find, str2);
            find = line.find(str1, find + str2.size());
        }
        ofs << line;
        if (ifs.peek() != EOF)
            ofs << std::endl;
    }
    return 0;
}