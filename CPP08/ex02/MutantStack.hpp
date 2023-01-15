#ifndef MUTANTSTACK_HPP 
#define MUTANTSTACK_HPP

#define COLOR_START "\033[1;100m"
#define COLOR_RED "\033[31m" 
#define COLOR_GREEN "\033[32m" 
#define COLOR_YELLOW "\033[33m"
#define COLOR_END "\033[0m"

#include <stack>
#include <iostream>
#include <list>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T>{

public:
        MutantStack(){
			std::cout << COLOR_GREEN << "[MutantStack] Constructor called." << COLOR_END << std::endl;
        };
        MutantStack (const MutantStack & src){
			std::cout << COLOR_YELLOW << "[MutantStack] Copy constructor called" << COLOR_END << std::endl;
    		*this = src;
        };
        ~MutantStack(void){
			std::cout << COLOR_RED << "[MutantStack] Destructor called" << COLOR_END << std::endl;

        };
        MutantStack & operator=(MutantStack const & value){
			std::cout << COLOR_YELLOW << "[MutantStack] Copy assignement operator called" << COLOR_END << std::endl;
            (void) value;
			return *this;
        };

        typedef typename MutantStack<T>::container_type::iterator iterator;
        typedef typename MutantStack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename MutantStack<T>::container_type::const_iterator const_iterator;
        typedef typename MutantStack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin(){
            return (this->c.begin());
        }
        iterator end(){
            return (this->c.end());
        }
        reverse_iterator rbegin(){
            return (this->c.rbegin());
        }
        reverse_iterator rend(){
            return (this->c.rend());
        }
        const_iterator cbegin(){
            return (this->c.cbegin());
        }
        const_iterator cend(){
            return (this->c.cend());
        }
        const_reverse_iterator crbegin(){
            return (this->c.crbegin());
        }
        const_reverse_iterator crend(){
            return (this->c.crend());
        }

};

#endif
