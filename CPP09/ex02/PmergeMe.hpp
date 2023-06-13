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


	template < typename T >
	T  jacobsthalSequence(int n) {
		T  seq;
		seq.push_back(1);
		seq.push_back(1);

		for (int i = 2; i < n; i++) {
			seq.push_back(seq[i - 1] + 2 * seq[i - 2]);
		}

		return seq;
	}

	template < typename T >
	void binaryInsert(T & arr, unsigned int val) {
		int left = 0, right = arr.size();

		while (left < right) {
			int mid = left + (right - left) / 2;

			if (arr[mid] < val) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		
		arr.insert(arr.begin() + left, val);
	}

	template < typename T >
	T mergeInsertSort(T arr) {
    int n = arr.size();
    
    if (n <= 1) {
        return arr;
    }

    T sortedArr;
    sortedArr.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        binaryInsert(sortedArr, arr[i]);
    }

    return sortedArr;
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
