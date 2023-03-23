#include "BitcoinExchange.hpp"

int creatingRandomFile(){
     std::ofstream output_file("input.txt");

    if (!output_file.is_open()) {
        std::cerr << "Failed to open output file." << std::endl;
        return 1;
    }

    std::srand(std::time(0));

    for (int i = 0; i < 100; ++i) {
        int year = std::rand() % 24 + 2000; // Random year between 2000 and 2023
        int month = std::rand() % 12 + 1; // Random month between 1 and 12
        int day = std::rand() % 31 + 1; // Random day between 1 and 31
        int value = std::rand() % 1001; // Random value between 0 and 1000

        char buffer[11];
        std::snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", year, month, day);

        output_file << buffer << " | " << value << std::endl;
    }
    output_file << "2011-01-03 | 3\n2011-01-03 | 2\n2011-01-03 | 1\n2011-01-03 | 1.2\n2011-01-09 | 1\n2012-01-11 | -1\n2001-42-42\n2012-01-11 | 1\n2012-01-11 | 2147483648\n";
    output_file.close();

    return 0;
}

int main(int ac, char **av){
    
    if (ac == 2 && (creatingRandomFile() == 0)){
        BitcoinExchange btc(av[1]);
        std::ifstream ifs(btc.getFileName().c_str());

        if (ifs.is_open())
        {
            try{
                btc.addData();
                btc.checkFile();
            }
            catch  (std::exception & e){
                std::cout << e.what();
            }
            return 0;
        }
    }
    std::cout << "Bad arguments" << std::endl;
    return 0;
}