#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
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
    void printList(clock_t start, clock_t end);
	template < typename T >
	void mergeSort(T & cont, int left, int right){
		int mid;
		if (left < right){
			mid = left + (right - left) / 2;
			mergeSort(cont, left, mid);
			mergeSort(cont, mid + 1, right);
			
		    merge(cont, left, mid, right);
		}
	}
    std::vector<int> vectorContainer;
	template <typename T>
	void merge(T & cont, int left, int mid, int right){
		int i = left;
        int j = mid + 1;
        int k = left;

        std::vector<int> tmp(cont);
        while ((i <= mid) && (j <= right))
        {
            if (cont[i] < cont[j])
                tmp[k++] = cont[i++];
            else
                tmp[k++] = cont[j++];
        }
        for (; j <= right; j++, k++)
            tmp[k] = cont[j];

        for (; i <= mid; i++, k++)
            tmp[k] = cont[i];

        for (i = left; i <= right; i++)
            cont[i] = tmp[i];
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
       
	std::list<int> listContainer;

	int numberToSort;


};

#endif
