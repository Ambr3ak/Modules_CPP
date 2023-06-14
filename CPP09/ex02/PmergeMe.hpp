#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <bits/stdc++.h>

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

class PmergeMe{

public:
	PmergeMe();
	PmergeMe (const PmergeMe & src);
	~PmergeMe(void);
	PmergeMe & operator=(PmergeMe const & value);

	void initContainers(char **av);
    void printVector(clock_t start, clock_t end);
    void printDeq(clock_t start, clock_t end);
	void printWidth();

template<typename T>
void insertionSort(T& cont, size_t left, size_t right)
{
    for (size_t i = left; i < right; i++)
    {
        typename T::value_type currentElement = cont[i + 1];
        size_t j = i + 1;
        while (j > left && cont[j - 1] > currentElement)
        {
            cont[j] = cont[j - 1];
            j--;
        }
        cont[j] = currentElement;
    }
}

template<typename T>
void merge(T& cont, size_t left, size_t mid, size_t right)
{
    size_t i = left;              // index for the first part
    size_t j = mid + 1;           // index for the second part
    size_t k = 0;                 // index for the temporary container
    
    T mergedSegment(right - left + 1); // Temporary container to store the merged elements
    
    // Merge the two parts
    while (i <= mid && j <= right)
    {
        if (cont[i] <= cont[j])
        {
            mergedSegment[k++] = cont[i++];
        }
        else
        {
            mergedSegment[k++] = cont[j++];
        }
    }
    while (i <= mid)
        mergedSegment[k++] = cont[i++];
    while (j <= right)
        mergedSegment[k++] = cont[j++];

    for (i = left, k = 0; i <= right;)
        cont[i++] = mergedSegment[k++];
}

template<typename T>
void recursiveContainer(T& cont, size_t leftRange, size_t rightRange) {
    size_t halfTotalSize = cont.size() / 2;
    if (rightRange - leftRange <= halfTotalSize){
        insertionSort(cont, leftRange, rightRange);
    }
    else {
        size_t midIndex = (leftRange + rightRange) / 2;
        recursiveContainer(cont, leftRange, midIndex);
        recursiveContainer(cont, midIndex + 1, rightRange);
        merge(cont, leftRange, midIndex, rightRange);
    }
}

	
class NotANum : public std::exception
	{
	public:
		

		virtual const char* what() const throw()
		{
			return "Not a Num\n";
		}
	};
class NotPositivNum : public std::exception
	{
	public:
		

		virtual const char* what() const throw()
		{
			return "Add only positiv num\n";
		}
	};
private:
       
	std::deque<unsigned int> DeqContainer;
    std::vector<unsigned int> vectorContainer;

	int numberToSort;
};

#endif
