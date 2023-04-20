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
    void printList(clock_t start, clock_t end);
	void printWidth();

	template < typename T >
	void startMerge(T & container){
    std::vector<std::pair<unsigned int, unsigned int> > contPair;
    T largest;
    T smallest;

    if (container.size() % 2 != 0)
    {
        straggler = *(container.end() - 1);
        container.erase(container.end() - 1);
    }

    for (typename T::iterator it = container.begin(); it != container.end(); it+=2){
        typename T::iterator tmpIt = it;
        contPair.push_back(std::make_pair((*it), *(++tmpIt)));
    }

    for (size_t i = 0; i < contPair.size(); i++){
        if (contPair[i].first > contPair[i].second){
            std::swap(contPair[i].first, contPair[i].second);
        }
        smallest.push_back(contPair[i].second);
        largest.push_back(contPair[i].first);
    }

    std::sort(smallest.begin(), smallest.end());

    for (typename T::iterator it = largest.begin(); it != largest.end(); ++it){
        smallest.insert(std::lower_bound(smallest.begin(), smallest.end(), *it), *it);
    }
    for (size_t i = 0; i < smallest.size(); i++){
        container[i] = smallest[i];
    }
    if (straggler != -1)
        container.insert(std::lower_bound(container.begin(), container.end(), straggler), straggler);
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
       
	std::deque<unsigned int> listContainer;
    std::vector<unsigned int> vectorContainer;

	int numberToSort;
	int straggler;


};

#endif
