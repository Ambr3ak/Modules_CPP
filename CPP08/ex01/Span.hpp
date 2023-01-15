#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
#include <vector>

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

class Span{

public:
        Span();
        Span(unsigned int N);
        Span (const Span & src);
        ~Span(void);
        Span & operator=(Span const & value);



		class ExceptionArrayFull : public std::exception
		{
		public:
				virtual const char* what() const throw()
				{
					return "Array is full\n";
				}
		};	
		class ExceptionCantFindSpan : public std::exception
		{
		public:
				virtual const char* what() const throw()
				{
					return "Can't find span\n";
				}
		};	
        void addNumber(int toAdd);
		std::multiset<int> & getArray(void);
		int longestSpan(void);
		int shortestSpan(void);
		template<typename T>
		void addNumberFromT(typename T::iterator begin,typename T::iterator end);

private:
        unsigned int _size;
		unsigned int _index;
		std::multiset<int> _array;
};


template<typename T>
void Span::addNumberFromT(typename T::iterator begin,typename T::iterator end){

	typename T::iterator it = begin;
	std::vector<int> temp(begin, end);
	if (temp.size() > (_size - _index))
		throw ExceptionArrayFull();
	while (it != end)
	{
    	_array.insert(*it);
		it++;
	}
}
#endif
