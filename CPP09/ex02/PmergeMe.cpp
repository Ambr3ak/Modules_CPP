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
        std::cout << "Time to process a range of " << numberToSort << " elements with std::vector<int> : " << std::fixed << time_taken << setprecision(5);
        return;
    }
    return;
    
}

void PmergeMe::printList(clock_t start, clock_t end){
    if (start != 0 && end != 0)
    {
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        std::cout << "Time to process a range of " << numberToSort << " elements with std::list<int> : " << time_taken << std::endl;
        return;
    }
    return;
    
}

void PmergeMe::initContainers(char **av){
    int i = 1;
    int number;

    while (av[i]){
        isNum(av[i]);
        number = stringtoint(av[i]);
        vectorContainer.push_back(number);
        listContainer.push_back(number);
        i++;
    }
    this->numberToSort = i - 1;
    std::cout << "Before: ";
    for (size_t i = 0; i < vectorContainer.size(); i++)
        std::cout << vectorContainer[i] << " ";
    std::cout << std::endl;
    clock_t start = clock();
    mergeSort(vectorContainer, 0, numberToSort - 1);
    clock_t end = clock();
    clock_t startL = clock();
    mergeSort(vectorContainer, 0, numberToSort - 1);
    clock_t endL = clock();
    std::cout << "After: ";
    for (size_t i = 0; i < vectorContainer.size(); i++)
        std::cout << vectorContainer[i] << " ";
    std::cout << std::endl;
    printVector(start, end);
    printList(startL, endL);
}