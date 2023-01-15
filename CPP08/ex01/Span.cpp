#include "Span.hpp"

Span::Span(void) : _size(0), _index(0), _array(){
    std::cout << COLOR_GREEN << "[Span empty] Constructor called." << COLOR_END << std::endl;
}

Span::Span(unsigned int N) : _size(N), _index(0), _array(){
    std::cout << COLOR_GREEN << "[Span] Constructor called." << COLOR_END << std::endl;
}

Span::Span(const Span & src) : _array(src._array){
    std::cout << COLOR_YELLOW << "[Span] Copy constructor called" << COLOR_END << std::endl;
    *this = src;
}

Span::~Span(void){
    std::cout << COLOR_RED << "[Span empty] Destructor called" << COLOR_END << std::endl;
}

Span & Span::operator=(Span const & value) {

    std::cout << COLOR_YELLOW << "[Span] Copy assignement operator called" << COLOR_END << std::endl;
    if (&value != this)
    {
        _size = value._size;
        _index = value._index;
    }
    return *this;
}

void Span::addNumber(int toAdd){

    if (_index == _size)
        throw ExceptionArrayFull();
    else
    {
        _array.insert(toAdd);
        _index++;
    }
}

int Span::longestSpan(void){
    if (_index != 1)
        return (*(--_array.end()) - *(_array.begin()));
    throw ExceptionCantFindSpan();
}


int Span::shortestSpan(void){
    if (_index != 1)
    {
        std::multiset<int>::iterator it;
        std::multiset<int>::iterator it2;
        int shortest;
        int shortestTmp = longestSpan();

        for (it = _array.begin(); it != --_array.end(); it++)
        {
            it2 = it;
            it2++;
            shortest = std::max(*it, *it2) - std::min(*it, *it2);
            if (shortest <= shortestTmp)
               shortestTmp = shortest;
        }
        return (shortestTmp);
    }
    throw ExceptionCantFindSpan();
}

std::multiset<int> & Span::getArray(void){
    return _array;
}