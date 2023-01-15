#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

template<typename T>
class Array{

public:
        Array() :_content(NULL),  _index(0) {
			std::cout << COLOR_GREEN << "[Array] Constructor called." << COLOR_END << std::endl;
        };
        Array(unsigned int n): _content(new T[n]), _index(n){
			std::cout << COLOR_GREEN << "[Array] Constructor param called." << COLOR_END << std::endl;
			for (unsigned int i = 0; i < n; i++)
				_content[i] = 0;
		};
        Array (const Array & src){
			std::cout << COLOR_YELLOW << "[Array] Copy constructor called" << COLOR_END << std::endl;
    		*this = src;
        };
        ~Array(void){
			std::cout << COLOR_RED << "[Array] Destructor called" << COLOR_END << std::endl;
			delete [] _content;
        };
        Array & operator=(Array const & value){
			std::cout << COLOR_YELLOW << "[Array] Copy assignement operator called" << COLOR_END << std::endl;
			if (&value != this)
			{
				_index = value._index;
				_content = new T[value._index];
				for (unsigned int i = 0; i < value._index; i++)
				{
					if (value._content[i])
						_content[i] = value._content[i];
					else
						_content[i] = 0;
				}
			}
			return *this;
        };

		class ExceptionSize : public std::exception
        {
        public:
                virtual const char* what() const throw()
                {
                        return "Array index out of bound\n";
                }
        };

		int & operator[](unsigned int index)
		{
			if (index >= size() || index < 0) {
				throw ExceptionSize();
			}
			return _content[index];
		}

		T * getTab(void){
			return (_content);
		}

		unsigned int size(void){
			return _index;
		}
private:
        T * _content;
		unsigned int _index;
};

#endif
