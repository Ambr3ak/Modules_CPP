#include "PmergeMe.hpp"
#include <sstream>
#include <ctime>

static size_t stringtoint(std::string c){
    std::istringstream is(c);
    int i;

    is >> i;
    return i;
}


PmergeMe::PmergeMe(void){
    std::cout << COLOR_GREEN << "[PmergeMe] Constructor called." << COLOR_END << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe & src){
    std::cout << COLOR_YELLOW << "[PmergeMe] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

PmergeMe::~PmergeMe(void){
    std::cout << COLOR_RED << "[PmergeMe] Destructor called" << COLOR_END << std::endl;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & value) {

    std::cout << COLOR_YELLOW << "[PmergeMe] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        //some copy
    }
    return *this;
}

static void isNum(char *num){
    int i = 0;
    if (num[0] == '-')
        throw PmergeMe::NotPositivNum();
    while (num[i]){
        if (!isdigit(num[i]))
        {
            std::cout << num[i] << std::endl;
            throw PmergeMe::NotANum();
        }
        i++;
    }
}

void PmergeMe::printVector(clock_t start, clock_t end){
    if (start != 0 && end != 0)
    {
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        std::cout << "Time to process a range of " << numberToSort << " elements with std::vector<unsigned int> : " << std::fixed << time_taken << std::setprecision(6) << " sec" << std::endl;
        return;
    }
    return;
    
}

void PmergeMe::printDeq(clock_t start, clock_t end){
    if (start != 0 && end != 0)
    {
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        std::cout << "Time to process a range of " << numberToSort << " elements with std::dequeu<unsigned int> : "  << std::fixed << time_taken << std::setprecision(6) << " sec" << std::endl ;
        return;
    }
    return;
    
}

void PmergeMe::printWidth(){
    if (numberToSort > 5){
        for (size_t i = 0; i < 5; i++)
            std::cout << vectorContainer[i] << " ";
        std::cout << "[...]";
    }
    else
        for (size_t i = 0; i < vectorContainer.size(); i++)
            std::cout << vectorContainer[i] << " ";
    std::cout << std::endl;
}

#include <iostream>
#include <vector>


void PmergeMe::initContainers(char **av){
    int i = 1;
    int number;

    while (av[i]){
        isNum(av[i]);
        number = stringtoint(av[i]);
        vectorContainer.push_back(number);
        DeqContainer.push_back(number);
        i++;
    }
    this->numberToSort = i - 1;
    std::cout << "Before: ";
    printWidth();
    clock_t start = clock();
    vectorContainer = mergeInsertSort(vectorContainer);
    clock_t end = clock();
    clock_t startL = clock();
    DeqContainer = mergeInsertSort(DeqContainer);
    clock_t endL = clock();
    std::cout << "After: ";
    printWidth();

    printVector(start, end);
    printDeq(startL, endL);
}