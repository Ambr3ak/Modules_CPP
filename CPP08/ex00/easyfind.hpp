#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <list>
#include <deque>

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

class ExceptionNotFound : public std::exception
{
public:
		virtual const char* what() const throw()
		{
				return "Value not found\n";
		}
};

template<typename T>
typename T::iterator easyfind(T & array, int toFind)
{        
	typename T::iterator it;
	it = std::find(array.begin(), array.end(), toFind);
	if (it != array.end())
		return it;
	else
		throw ExceptionNotFound();
} 

#endif
